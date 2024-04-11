// Treap implementation with pointers
// Expected running time of split and merge is O(log n)
#include <bits/stdc++.h>
using namespace std;

typedef struct node* pnode;
struct node {
	pnode l,r;
	int pr,c;
	char t;
	int rev;
	node(char tt) {
		l=0;
		r=0;
		c=1;
		pr=rand();
		t=tt;
		rev=0;
	}
};

// Returns the size of the subtree t
int cnt(pnode t) {
	if (t) return t->c;
	return 0;
}

// Updates the size of the subtree t
void upd(pnode t) {
	if (t) t->c=cnt(t->l)+cnt(t->r)+1;
}

// Put lazy updates here
void push(pnode t) {
	if (t) {
		if (t->rev){
			t->rev=0;
			swap(t->l, t->r);
			if (t->l) t->l->rev^=1;
			if (t->r) t->r->rev^=1;
		}
	}
}

// Merges trees l and r into tree t
void merg(pnode& t, pnode l, pnode r) {
	push(l);
	push(r);
	if (!l) t=r;
	else if(!r) t=l;
	else {
		if (l->pr>r->pr) {
			merg(l->r, l->r, r);
			t=l;
		}
		else {
			merg(r->l, l, r->l);
			t=r;
		}
	}
	upd(t);
}

// Splits tree t into trees l and r
// Size of tree l will be k
void split(pnode t, pnode& l, pnode& r, int k) {
	if (!t) {
		l=0;
		r=0;
		return;
	}
	else {
		push(t);
		if (cnt(t->l)>=k) {
			split(t->l, l, t->l, k);
			r=t;
		}
		else {
			split(t->r, t->r, r, k-cnt(t->l)-1);
			l=t;
		}
	}
	upd(t);
}

void output(pnode t){
	if (!t) return;
	push(t);
	output(t->l);
	cout<<t->t;
	output(t->r);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	pnode tree=0;
	for (int i=0;i<(int)s.size();i++){
		pnode nn=new node(s[i]);
		merg(tree, tree, nn);
	}
	int q;
	cin>>q;
	for (int qq=0;qq<q;qq++){
		int a;
		cin>>a;
		pnode t1,t2,t3;
		split(tree, t1, t2, a-1);
		split(t2, t2, t3, (int)s.size()-a*2+2);
		if (t2) t2->rev^=1;
		merg(tree, t1, t2);
		merg(tree, tree, t3);
	}
	output(tree);
	cout<<endl;
}