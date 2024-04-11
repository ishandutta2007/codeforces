#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct node{
	int lazy, p, s, m, lazys, idx; // s = shirts
	node *l, *r;
	node(){
		p = rand(); lazy = lazys = 0; l = r = NULL;
		s = 0; m = 0;
	}
	node(int a, int b, int i){
		p = rand(); lazy = lazys = 0; l = r = NULL;
		s = a; m = b; idx = i;
	}
};
void push(node *a){
	if(a == NULL) return;
	a->m += a->lazy;
	a->s += a->lazys;
	if(a->l != NULL){
		a->l->lazy += a->lazy;
		a->l->lazys += a->lazys;
	}
	if(a->r != NULL){
		a->r->lazy += a->lazy;
		a->r->lazys += a->lazys;
	}
	a->lazy = a->lazys = 0;
}
//<k >= k;
void split(node *t, node *&l, node *&r, int k){
	push(t);
	if(t == NULL){
		l = r = NULL;
	} else if(t->m >= k){
		split(t->l,l,t->l,k);
		r = t;
	} else {
		split(t->r,t->r,r,k);
		l = t;
	}
}
void merge(node *&t, node *l, node *r){
	push(l); push(r);
	if(l == NULL){
		t = r;
	} else if(r == NULL){
		t = l;
	} else if(l->p >= r->p){
		merge(l->r,l->r,r);
		t = l;
	} else {
		merge(r->l,l,r->l);
		t = r;
	}
}
int ans[210000];
void pt(node * t){
	if(t == NULL) return;
	push(t);
	ans[t->idx] = t->s;
	pt(t->l);
	pt(t->r);
}
int main(){
	int n;
	scanf("%d", &n);
	pair<int,int> s[n];
	int c[n];
	for(int i = 0; i < n; i++){
		scanf("%d%d", &s[i].second, &s[i].first);
		s[i].first *= -1;
	}
	sort(s,s+n);
	for(int i = 0; i < n; i++) c[i] = s[i].second;
	int k;
	scanf("%d", &k);
	int q[k];
	pair<int,int> z[k];
	for(int i = 0; i < k; i++){
		scanf("%d", &q[i]);
		z[i].first = q[i];
		z[i].second = i;
	}
	sort(z,z+k);
	node * treap = NULL;
	for(int i = 0; i < k; i++){
		node * a = new node(0,z[i].first,z[i].second);
		merge(treap,treap,a);
	}
	node *a, *b, *d, *e, *e1, *e2, *e3;
	for(int i = 0; i < n; i++){
		split(treap,a,b,c[i]);
		if(b != NULL){
			b->lazys++;
			b->lazy -= c[i];
		}
		split(b,b,d,c[i]);
		while(b != NULL){
			push(b);
			node * cur = new node(b->s,b->m, b->idx);
			split(a,e1,e2,cur->m);
			merge(e3,e1,cur);
			merge(a,e3,e2);
			merge(b,b->l,b->r);
		}
		merge(treap,a,d);
	}
	pt(treap);
	for(int i = 0; i < k; i++) printf("%d ", ans[i]);
	printf("\n");
}