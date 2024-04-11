#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;

int n,nq;

int col[1<<18];
ll lazy[1<<18];
ll sum[1<<18];

void init(int x,int l,int r) {
	if(l==r) {
		col[x]=l+1;
		sum[x]=0;
		lazy[x]=0;
	} else {
		int m=l+(r-l)/2;
		init(2*x+1,l,m);
		init(2*x+2,m+1,r);
		col[x]=-1;
		sum[x]=sum[2*x+1]+sum[2*x+2];
		lazy[x]=0;
	}
}

void push(int x,int l,int r) {
	int m=l+(r-l)/2;
	lazy[2*x+1]+=lazy[x]; sum[2*x+1]+=(ll)(m-l+1)*lazy[x];
	lazy[2*x+2]+=lazy[x]; sum[2*x+2]+=(ll)(r-m  )*lazy[x];
	lazy[x]=0;
}

void change(int x,int l,int r,int ll,int rr,int ncol) {
	if(ll<l) ll=l; if(rr>r) rr=r; if(ll>rr) return;
	if(ll==l&&r==rr&&col[x]!=-1) {
		int diff=abs(ncol-col[x]);
		lazy[x]+=diff;
		sum[x]+=(long long)(r-l+1)*diff;
		col[x]=ncol;
	} else {
		assert(l<r);
		push(x,l,r);
		if(col[x]!=-1) col[2*x+1]=col[2*x+2]=col[x];
		int m=l+(r-l)/2;
		change(2*x+1,l,m,ll,rr,ncol);
		change(2*x+2,m+1,r,ll,rr,ncol);
		col[x]=ll==l&&r==rr?ncol:-1;
		sum[x]=sum[2*x+1]+sum[2*x+2];
	}
}

ll get(int x,int l,int r,int ll,int rr) {
	if(ll<l) ll=l; if(rr>r) rr=r; if(ll>rr) return 0;
	if(ll==l&&r==rr) {
		return sum[x];
	} else {
		assert(l<r);
		push(x,l,r);
		int m=l+(r-l)/2;
		long long a=get(2*x+1,l,m,ll,rr);
		long long b=get(2*x+2,m+1,r,ll,rr);
		return a+b;
	}
}

void run() {
	scanf("%d%d",&n,&nq);
	init(0,0,n-1);
	REP(q,nq) {
		int type; scanf("%d",&type);
		if(type==1) {
			int l,r,x; scanf("%d%d%d",&l,&r,&x); --l,--r;
			change(0,0,n-1,l,r,x);
		}
		if(type==2) {
			int l,r; scanf("%d%d",&l,&r); --l,--r;
			ll ret=get(0,0,n-1,l,r);
			cout<<ret<<endl;
		}
	}
}

int main() {
	run();
	return 0;
}