#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#include <assert.h>
#include <bitset>
#include <bits/stdc++.h>
#include <time.h>
#include <chrono>
using namespace std; 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsinged long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define quickcin ios_base::sync_with_stdio(false);
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
const int inf=1039074182;
const ll llinf=1LL*inf*inf;
using namespace std;
int n,m,q;
int a[200005];

struct node
{
	node *l=nullptr,*r=nullptr;
	bool rev=false;
	int sz=1;
	int data;
	int rd=rand(1,1000000000);
	int size()
	{
		return (this==nullptr?0:sz);
	}
	void pushdown()
	{
		if(this==nullptr || !rev) return;
		rev=false;
		swap(l,r);
		if(l) l->rev^=1;
		if(r) r->rev^=1;
	}
	void pushup()
	{
		if(this==nullptr) return;
		sz=l->size()+r->size()+1;
	}
};

int querykth(node *rt,int x)
{
	rt->pushdown();
	if(x<rt->l->size()) return querykth(rt->l,x);
	x-=rt->l->size();
	if(x<1) return rt->data;
	x-=1;
	return querykth(rt->r,x);
}

void print(node *rt)
{
	int sz=rt->size();
	for(int i=0;i<sz;i++)
	{
		cout<<querykth(rt,i)<<' ';
	}
	cout<<endl;
}

pair <node*,node*> split(node* x,int key,int psum=0)
{
	if(x==nullptr) return mp(nullptr,nullptr);
	x->pushdown();
	int curid=psum+x->l->size();
	if(key>=curid)
	{
		pair <node*,node*> o=split(x->r,key,curid+1);
		x->r=o.first;
		x->pushup();
		return mp(x,o.second);
	}
	else
	{
		pair <node*,node*> o=split(x->l,key,psum);
		x->l=o.second;
		x->pushup();
		return mp(o.first,x);
	}
}

node* merge(node* x,node *y)
{
	if(x==nullptr) return y;
	if(y==nullptr) return x;
	x->pushdown();
	y->pushdown();
	if(x->rd>y->rd)
	{
		node *rt=merge(x->r,y);
		x->r=rt;
		x->pushup();
		return x;
	}
	else
	{
		node *rt=merge(x,y->l);
		y->l=rt;
		y->pushup();
		return y;
	}
}

node* build(int a[],int n)
{
	node *rt=nullptr;
	for(int i=0;i<n;i++)
	{
		node *x=new node;
		x->data=a[i];
		rt=merge(rt,x);
	}
	return rt;
}

void reverse(node *&rt,int l,int r) //[]
{
	pair<node*,node*> o1,o2;
	o1=split(rt,l-1);
	o2=split(o1.second,r-l);
	node *a=o1.first,*b=o2.first,*c=o2.second;
	b->rev^=1;
	rt=merge(merge(a,b),c);
}

void CyclicShift(node *&rt,int l,int r,int k)//[]
{
	assert(l<=r);
	k%=(r-l+1);
	pair <node*,node*> o1,o2,o3;
	o2=split(rt,r-k);
	o1=split(o2.first,l-1);
	o3=split(o2.second,r-(r-k+1));
	rt=merge(merge(o1.first,o3.first),merge(o1.second,o3.second));
}

int main()
{
//	freopen("input.txt","r",stdin);
	quickcin;
	cin>>n>>q>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int l,r,op;
	node* rt=build(a,n);
	for(int i=0;i<q;i++)
	{
		cin>>op>>l>>r;
		l--;
		r--;
		if(op==1) CyclicShift(rt,l,r,1);
		if(op==2) reverse(rt,l,r);
	}
	for(int i=0;i<m;i++)
	{
		cin>>l;
		l--;
		cout<<querykth(rt,l)<<' ';
	}
	cout<<endl;
	return 0;
}