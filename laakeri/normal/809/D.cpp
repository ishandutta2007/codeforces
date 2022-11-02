#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long double ld;
typedef long long ll;

typedef struct node* pnode;
struct node {
	pnode l,r;
	int pr,c;
	int v,add;
	node(int v_) {
		l=0;r=0;c=1;pr=rand();
		v=v_;
		add=0;
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
void addv(pnode t, int v){
	if (t) {
		t->v+=v;
		t->add+=v;
	}
}
void push(pnode t) {
	if (t) {
		if (t->add!=0){
			addv(t->l, t->add);
			addv(t->r, t->add);
			t->add=0;
		}
	}
}
// Merges trees l and r into tree t
void merg(pnode& t, pnode l, pnode r) {
	push(l);push(r);
	if (!l) t=r;
	else if(!r) t=l;
	else {
		if (l->pr>r->pr) {
			merg(l->r, l->r, r);t=l;
		}
		else {
			merg(r->l, l, r->l);t=r;
		}
	}
	upd(t);
}
// Splits tree t into trees l and r
// Size of tree l will be k
void split(pnode t, pnode& l, pnode& r, int k) {
	if (!t) {
		l=0;r=0;return;
	}
	else {
		push(t);
		if (cnt(t->l)>=k) {
			split(t->l, l, t->l, k);r=t;
		}
		else {
			split(t->r, t->r, r, k-cnt(t->l)-1);l=t;
		}
	}
	upd(t);
}

int bs(pnode t, int v){
	if (t==0) return 0;
	push(t);
	if (t->v>=v){
		return bs(t->l, v)+1+cnt(t->r);
	}
	else{
		return bs(t->r, v);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pnode tree=0;
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		int l,r;
		cin>>l>>r;
		int c2=bs(tree, r);
		if (c2!=0){
			pnode t1, t2, t3;
			split(tree, t1, t2, cnt(tree)-c2);
			split(t2, t2, t3, 1);
			merg(tree, t1, t3);
		}
		int c1=bs(tree, l);
		if (c1!=0){
			pnode t1, t2, t3;
			split(tree, t1, t2, cnt(tree)-c1);
			int c4=bs(t2, r);
			split(t2, t2, t3, cnt(t2)-c4);
			addv(t2, 1);
			merg(tree, t1, t2);
			merg(tree, tree, t3);
		}
		int c3=bs(tree, l);
		pnode t1, t2;
		split(tree, t1, t2, cnt(tree)-c3);
		pnode nn=new node(l);
		merg(tree, t1, nn);
		merg(tree, tree, t2);
	}
	cout<<cnt(tree)<<endl;
}