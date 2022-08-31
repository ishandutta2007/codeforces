#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

mt19937_64 mt(48);

struct node {
	LL sz, v, p, lazy;
	LL val, maxval, vsum;
	node *l, *r;
	node(LL _v, LL _val): sz(1), v(_v), l(NULL),r(NULL), p(mt()), lazy(0){
		val = _val;
		maxval = val;
		vsum = v;
	}
};

void push(node* t){
	if(t == NULL) return;
	// unlazy a node, gives correct values of sum, set0, lazy -> 0
	if(t->lazy){
		t->val += t->lazy;
		t->maxval += t->lazy;
		if(t->l != NULL){
			t->l->lazy += t->lazy;
		}
		if(t->r != NULL){
			t->r->lazy += t->lazy;
		}
		t->lazy = 0;
	}
}

LL sz(node* t){
	push(t);
	return (t == NULL ? 0 : t->sz);
}
LL vsum(node* t){
	push(t);
	return (t == NULL ? 0 : t->vsum);
}

LL maxval(node* t){
	push(t);
	return (t == NULL ? -5e17 : t->maxval);
}
void upd(node* t){ // computes fully correct values of sum, sz
	if(t == NULL) return;
	push(t);
	t->sz = 1+sz(t->l)+sz(t->r);
	t->vsum = t->v + vsum(t->l) + vsum(t->r);
	t->maxval = max(t->val, max(maxval(t->l), maxval(t->r)));
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
	push(l);
	push(r);
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
	pt(r->l);
	cout << r->v << " " << r->p << " " << r->sz << " " << r->maxval << endl;
	pt(r->r);
}

node * treap = nullptr;

void add_eel(LL x){
	node *a, *b;
	splitv(treap, a, b, x);
	LL newval = x - 2 * vsum(a);
	if(b != nullptr){
		b->lazy -= 2 * x;
	}
	node *v = new node(x, newval);
	node *c = nullptr;
	merge(c, a, v);
	merge(treap, c, b);
	//pt(treap);
}

void remove_eel(LL x){
	node *a, *b;
	splitv(treap, a, b, x-1);
	node *v;
	split(b, v, b, 1);
	assert(v->v == x);
	delete v;
	if(b != nullptr){
		b->lazy += 2 * x;
	}
	merge(treap, a, b);
}

void find_pos(node * x, int& ans){
	if(x == nullptr) return;
	push(x);
	//cout << "here " << x->v << " " << x->val << " " << x->maxval << endl;
	if(x->maxval > 0){
		if(x->val > 0){
			ans++;
			//cout << "found " << x->v << " " << x->val << " " << x->maxval << endl;
		}
		find_pos(x->l, ans);
		find_pos(x->r, ans);
	}
}

void print_ans(){
	//pt(treap);
	int ans = 0;
	find_pos(treap, ans);
	cout << sz(treap) - ans << '\n';
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int Q;
	cin >> Q;
	for(int q = 0; q < Q; q++){
		string s;
		LL x;
		cin >> s >> x;
		if(s == "+"){
			add_eel(x);
		} else if(s == "-"){
			remove_eel(x);
		}
		print_ans();

	}
}