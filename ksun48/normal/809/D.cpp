#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct node{
	LL sz, v, sum, set0, p, lazy;
	node *l, *r;
	node(LL v): sz(1), v(v), sum(v), set0(0),l(NULL),r(NULL), p(rand()), lazy(0) {}
};

void push(node* t){
	if(t == NULL) return;
	// unlazy a node, gives correct values of sum, set0, lazy -> 0
	if(t->lazy){
		t->sum += (t->lazy)*(t->sz);
		if(t->l != NULL){
			t->l->lazy += t->lazy;
		}
		if(t->r != NULL){
			t->r->lazy += t->lazy;
		}
		t->v += t->lazy;
		t->lazy = 0;
	}
}

LL sz(node* t){
	push(t);
	return (t == NULL ? 0 : t->sz);
}
LL sum(node* t){
	push(t);
	return (t == NULL ? 0 : t->sum);
}
void upd(node* t){ // computes fully correct values of sum, sz
	if(t == NULL) return;
	push(t); push(t->l); push(t->r);
	t->sz = 1+sz(t->l)+sz(t->r);
	t->sum = t->v + sum(t->l) + sum(t->r);	
}
void split(node *t, node *&l, node *&r, LL k){ // splits into [0,k-1] and [k,?]
	push(t);
	if(t == NULL){
		l = NULL;
		r = NULL;
	} else if(sz(t->l) < k){
		split(t->r,t->r,r,k-sz(t->l)-1);
		l = t;
	} else {
		split(t->l,l,t->l,k);
		r=t;
	}
	upd(t);
}
void splitv(node *t, node *&l, node *&r, LL v){ // splits into <= v and > v
	push(t);
	if(t == NULL){
		l = NULL;
		r = NULL;
	} else if(t->v <= v){
		splitv(t->r,t->r,r,v);
		l = t;
	} else {
		splitv(t->l,l,t->l,v);
		r=t;
	}
	upd(t);
}
void merge(node *&t, node *l, node *r){
	push(t);
	if(l == NULL){
		t = r;
	} else if(r == NULL){
		t = l;
	} else if(l->p < r->p){
		merge(l->r, l->r,r);
		t = l;	
	} else {
		merge(r->l,l,r->l);
		t=r;
	}
	upd(t);
}

void pt(node *r){
	if(r == NULL) return;
	cout << r->v << " " << r->p << " " << r->sz << endl;
	pt(r->l);
	pt(r->r);
}

int main(){
	node * treap = NULL;
	node * f = new node(0);
	merge(treap,treap,f);
	int n;
	cin >> n;
	int l[n];
	int r[n];
	for(int i = 0; i < n; i++){
		scanf("%d%d", &l[i], &r[i]);
	}
	node * a;
	node * b;
	node * c;
	node * d;
	for(int i = 0; i < n; i++){
		splitv(treap,a,b,l[i]-1);
		splitv(b,b,c,r[i]-1);
		if(b != NULL) b->lazy++;
		push(b);
		split(c,d,c,1);
		node * ne = new node(l[i]);
		merge(a,a,ne);
		merge(a,a,b);
		merge(treap,a,c);
	}
	cout << sz(treap) - 1 << endl;
}