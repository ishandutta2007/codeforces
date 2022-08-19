#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,b) FOR(i,0,b)
#define MP make_pair

//#define DB

#ifndef DB
#undef assert
#define assert(x) 0
#endif

using namespace std;

int read(){
	int i;
	scanf("%d",&i);
	return i;
}

struct Node{
	Node const *l,*r;
	int sz,lz,dep;
} buf[48000000];

using Np=Node const*;
using LR=Node const;

Np newNode(Np l,Np r,int sz,int lz,int dep){
	static int c=0;
	buf[c]=Node{l,r,sz,lz,dep};
	return buf+(c++);
}

Np newCh(Np l,Np r){
	assert(l&&r);
	return newNode(
		l,r,
		l->sz+r->sz,
		0,
		max(l->dep,r->dep)+1
	);
}

Np newLz(Np x,int exlz){
	assert(x);
	return exlz?newNode(x->l,x->r,x->sz,x->lz+exlz,x->dep):x;
}

LR Merge1(Np a,Np b,Np c){
	assert(a&&b&&c);
	if(abs(max(a->dep,b->dep)+1-c->dep)<=1)
		return LR{newCh(a,b),c};
	if(abs(max(b->dep,c->dep)+1-a->dep)<=1)
		return LR{a,newCh(b,c)};
	assert(b->l&&b->r);
	return LR{newCh(a,newLz(b->l,b->lz)),newCh(newLz(b->r,b->lz),c)};
}

LR Merge2(Np a,Np b,int alz,int blz){
	assert(a&&b);
	if(a->dep<b->dep){
		blz+=b->lz;
		assert(b->l&&b->r);
		LR x=Merge2(a,b->l,alz,blz);
		return Merge1(x.l,x.r,newLz(b->r,blz));
	}else if(a->dep>b->dep){
		alz+=a->lz;
		assert(a->l&&a->r);
		LR x=Merge2(a->r,b,alz,blz);
		return Merge1(newLz(a->l,alz),x.l,x.r);
	}else
		return LR{newLz(a,alz),newLz(b,blz)};
}

Np Merge(Np a,Np b){
	if(!a)return b;
	if(!b)return a;
	LR x=Merge2(a,b,0,0);
	return newCh(x.l,x.r);
}

Np SplitLeft(Np x,int s,int lz){
	assert(x);
	if(x->sz==s)
		return newLz(x,lz);
	lz+=x->lz;
	if(s<=x->l->sz)
		return SplitLeft(x->l,s,lz);
	return Merge(newLz(x->l,lz),SplitLeft(x->r,s-x->l->sz,lz));
}

typedef pair<int,int> pii;
pii shirts[200000];

int GetAns(Np x,int v,int lz){
	lz+=x->lz;
	if(x->sz==1)
		return lz;
	if(v<x->l->sz)
		return GetAns(x->l,v,lz);
	return GetAns(x->r,v-x->l->sz,lz);
}

int main(){
	int n=read();
	REP(i,n){
		int c=read(),q=read();
		shirts[i]=MP(-q,c);
	}
	sort(shirts,shirts+n);
	Np root=newNode(NULL,NULL,1,0,1);
	REP(i,30)
		root=Merge(root,root);
	const int s=1<<30;
	for(int i=n-1;i>=0;i--){
		int c=shirts[i].second;
		Np x=SplitLeft(root,c,0);
		Np y=SplitLeft(root,s-c,0);
		y=newLz(y,1);
		root=Merge(x,y);
	}
	int k=read();
	REP(i,k){
		int b=read();
		printf(i<k-1?"%d ":"%d\n",GetAns(root,b,0));
	}
}