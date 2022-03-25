#include "BSTSet.h"
#include <iostream>
#include <vector>
using namespace std;

BSTSet::BSTSet()
{
	// TODO
	root = NULL;
}

BSTSet::BSTSet(const std::vector<int>& input)
{
	// TODO, change following code after completing this function
	if(input.empty()){
		root = NULL;
		return;
	}
	root = new TNode(input[0], NULL, NULL);
	for(int i=1; i<input.size();i++){
		add(input[i]);
	}
}

void BSTSet::RecursiveDelete(TNode* &ptr)
{
	if(ptr){
		RecursiveDelete(ptr->left);
		RecursiveDelete(ptr->right);
		delete ptr;
	}
}



BSTSet::~BSTSet()
{
	// TODO
	RecursiveDelete(root);
}

bool BSTSet::isIn(int v, TNode* &ptr)
{
	if(!ptr){return false;}
	else if(v < ptr->element){return isIn(v, ptr->left);}
	else if(v > ptr->element){return isIn(v,ptr->right);}
	else {return true;}
}

bool BSTSet::isIn(int v)
{
	// TODO
	return isIn(v,root);
}


void BSTSet::add(int v)
{
	// TODO
	add(v, root);
}

void BSTSet::add(int v, TNode* &ptr)
{
	if(ptr == NULL){ptr = new TNode(v, NULL, NULL);}
	else if(v < ptr->element){add(v,ptr->left);}
	else if(v > ptr->element){add(v,ptr->right);}
	// if equal to node then exit function and do nothing
	else {return;}

}

TNode* BSTSet::findMax(TNode* &ptr){
	TNode* p = ptr;				// WHY WE NEED THIS????
	if(p==NULL){return NULL;}
	while(p->right!=NULL){
		p = p->right;
	}
	return p;
}

bool BSTSet::remove(int v, TNode* &ptr)
{
	// TODO
	if(!ptr){return false;}
	if(v < ptr->element){return remove(v,ptr->left);}
	else if(v > ptr->element){return remove(v,ptr->right);}
	else if(ptr->left != NULL && ptr->right != NULL){
		ptr->element = findMax(ptr->left)->element;
		return remove(ptr->element, ptr->left);
	}
	else{
		TNode* temp = ptr;
		ptr = (ptr->left)? ptr->left : ptr-> right;
		delete temp;
		return true;
	}
}

bool BSTSet::remove(int v)
{
	// TODO
    return remove(v, root); //change this after completing this function
}

void BSTSet::Union(const BSTSet& s, TNode* ptr)
{
	if(ptr==NULL){return;}
	else if(!isIn(ptr->element)){add(ptr->element);}

	Union(s,ptr->left);
	Union(s,ptr->right);

}

void BSTSet::Union(const BSTSet& s)
{
	// TODO
	Union(s,s.root);
}

void BSTSet::intersection(const BSTSet& s)
{
	// TODO
	BSTSet* temp = new BSTSet();
	intersection(s.root, temp);
	RecursiveDelete(root);
	root = temp->root;
}

void BSTSet::intersection(TNode* ptr, BSTSet* temp)
{
	if(!ptr){return;}

	if(isIn(ptr->element)){temp->add(ptr->element);}
		intersection(ptr->left, temp);
		intersection(ptr->right, temp);
	}

//	if(!ptr){return;}
//
//	else if(!(ptr2->isIn(ptr->element))){
//		remove(ptr->element);
//	}
//	intersection(ptr->left, ptr2);
//	intersection(ptr->right, ptr2);

void BSTSet::difference(const BSTSet& s)
{
	// TODO
	difference(s.root);

}

void BSTSet::difference(TNode* ptr)
{
	if(ptr == NULL){return;}
	else{
		difference(ptr->left);
		remove(ptr->element);
		difference(ptr->right);
	}
}


int BSTSet::size()
{
	// TODO
	int digits = 0;
    return size(digits, root); //change this after completing this function
}

int BSTSet::size(int& tally, TNode* ptr)
{
	if(ptr==NULL){return tally;}
	else{
		tally = size(tally, ptr->left);
		tally = size(tally, ptr->right);
		return ++tally;
	}
}

int BSTSet::height()
{
	// TODO

    return height(root); //change this after completing this function
}

int BSTSet::height(TNode* ptr)
{
	if(!ptr){return -1;}

	int right_height = height(ptr->right);
	int left_height = height(ptr->left);
	return max(right_height, left_height)+1;
}

// create and use class MyStack
void BSTSet::printNonRec()
{
	// TODO

	cout << "-2"; //change this after completing this function
}

// Do not modify following provided methods

void BSTSet::printBSTSet()
{
    if (root == NULL)
        std::cout << "";
    else {
        printBSTSet(root);
    }
}

void BSTSet::printBSTSet(TNode* t)
{
    if (t != NULL) {
        printBSTSet(t->left);
        std::cout << t->element << ",";
        printBSTSet(t->right);
    }
}
