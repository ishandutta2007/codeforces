#include <cstdio>
#include <iostream>
#include <algorithm>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define N 100005
int n,v,x[N],t[N];
struct node{
	int p,q;
}a[N];
bool operator<(node a,node b){
	return a.p==b.p?a.q<b.q:a.p<b.p;
}
struct LIS{
	int top,v[N];
	void clear(){
		top=0;
	}
	void push(int x){
		int p=std::lower_bound(v+1,v+top+1,x+1)-v;
		v[p]=x;
		if(p>top) top++;
	}
}_;
int main(){
	scanf("%d",&n);
	rpt(i,1,n) scanf("%d%d",&x[i],&t[i]);
	scanf("%d",&v);
	rpt(i,1,n) a[i].p=-x[i]+t[i]*v,a[i].q=x[i]+t[i]*v;
	std::sort(a+1,a+n+1);
	_.clear();
	rpt(i,1,n) if(a[i].p>=0&&a[i].q>=0) _.push(a[i].q);
	printf("%d ",_.top);
	_.clear();
	rpt(i,1,n) _.push(a[i].q);
	printf("%d",_.top);
}