#include<bits/stdc++.h>
using namespace std;
struct node {
	int c;
	unsigned long long p;
	node *l,*r;
	int rev;
	int v;
	node(int c1,unsigned long long p1,int v1) {
		c=c1;
		p=p1;
		rev=0;
		l=NULL;
		r=NULL;
		v=v1;
	}
};
int count(node* t) {
	if(t==NULL) return 0;
	return t->c;
}
void update(node* &t) {
	if(t==NULL) return;
	t->c = count(t->l) + 1 + count(t->r);
}
void push(node* &t) {
	if(t==NULL) return;
	if(t->rev == 1) {
		t->rev = 0;
		swap(t->l,t->r);
		if(t->l != NULL) t->l->rev^=1;
		if(t->r != NULL) t->r->rev^=1;
	}
}
void merge(node* &t,node* tl,node* tr) {
	push(tl);
	push(tr);
	if(tl==NULL) t=tr;
	else {
		if(tr==NULL) t=tl;
		else {
			if(tl->p > tr->p) {
				merge(tl->r,tl->r,tr);
				t=tl;
			}
			else {
				merge(tr->l,tl,tr->l);
				t=tr;
			}
		}
	}
	update(t);
}
void split(node* t,node* &tl,node* &tr,int k,int add=0) {
	push(t);
	if(t==NULL) {
		tl=NULL;
		tr=NULL;
	}
	else {
		int c=count(t->l)+add;
		if(k<=c) {
			split(t->l,tl,t->l,k,add);
			tr=t;
		}
		else {
			split(t->r,t->r,tr,k,add+count(t->l)+1);
			tl=t;
		}
	}
	update(tl);
	update(tr);
}
void insert(node* &rt,node* t) {
	push(rt);
	merge(rt,rt,t);
}
void cyclic(node* &rt,int l,int r) {
	push(rt);
	l--;
	r--;
	node *t1,*t2,*t3,*t4,*t5;
	split(rt,rt,t5,r+1);
	split(rt,rt,t4,r);
	split(rt,rt,t3,l+1);
	split(rt,t1,t2,l);
	merge(rt,t1,t4);
	merge(rt,rt,t2);
	merge(rt,rt,t3);
	merge(rt,rt,t5);
}
void reverse(node* &rt,int l,int r) {
	push(rt);
	l--;
	r--;
	node* t1,*t2,*t3;
	split(rt,rt,t3,r+1);
	split(rt,t1,t2,l);
	t2->rev=t2->rev^1;
	merge(rt,t1,t2);
	merge(rt,rt,t3);
}
int value(node* &rt,int c) {
	push(rt);
	if(rt==NULL) return -1;
	if(c==count(rt->l)) return rt->v;
	else {
		if(c<count(rt->l)) return value(rt->l,c);
		else return value(rt->r,c-count(rt->l)-1);
	}
}
int main()
{
	node* rt=NULL;
	node* tr;
	int n,q,m;
	scanf("%d %d %d",&n,&q,&m);
	int t,l,r;
	int a,b;
	unsigned long long ra=0;
	unsigned long long tp=3421847921830719293;
	for(int i=0;i<n;i++) {
		scanf("%d",&a);
		ra+=tp;
		insert(rt,new node(i,ra,a));
	}
	for(int i=0;i<q;i++) {
		scanf("%d %d %d",&t,&l,&r);
		if(t==1) cyclic(rt,l,r);
		else reverse(rt,l,r);
	}
	for(int i=0;i<m;i++) {
		scanf("%d",&b);
		printf("%d ",value(rt,b-1));
	}
	return 0;
}