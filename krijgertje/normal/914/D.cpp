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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=500000;
const int MAXS=4*MAXN;

int n;
int a[MAXN];

int sval[MAXS];

void sinit(int x,int l,int r) {
	if(l==r) {
		sval[x]=a[l];
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m);
		sinit(2*x+2,m+1,r);
		sval[x]=gcd(sval[2*x+1],sval[2*x+2]);
	}
}

void sset(int x,int l,int r,int IDX,int VAL) {
	if(l==r) {
		sval[x]=VAL;
	} else {
		int m=l+(r-l)/2;
		if(IDX<=m) sset(2*x+1,l,m,IDX,VAL);
		if(m+1<=IDX) sset(2*x+2,m+1,r,IDX,VAL);
		sval[x]=gcd(sval[2*x+1],sval[2*x+2]);
	}
}

int sget(int x,int l,int r,int L,int VAL) {
	if(L<=l&&sval[x]%VAL==0) return r+1;
	if(l==r) return l;
	int m=l+(r-l)/2;
	if(L<=m) { int ret=sget(2*x+1,l,m,L,VAL); if(ret!=m+1) return ret; }
	return sget(2*x+2,m+1,r,L,VAL);
}

bool solve(int l,int r,int val) {
	int a=sget(0,0,n-1,l,val);
	if(a>=r) return true;
	int b=sget(0,0,n-1,a+1,val);
	return b>r;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	sinit(0,0,n-1);
	int nq; scanf("%d",&nq);
	REP(i,nq) {
		int kind; scanf("%d",&kind);
		if(kind==1) {
			int l,r,val; scanf("%d%d%d",&l,&r,&val); --l,--r;
			printf("%s\n",solve(l,r,val)?"YES":"NO");
		}
		if(kind==2) {
			int idx,val; scanf("%d%d",&idx,&val); --idx;
			a[idx]=val; sset(0,0,n-1,idx,val);
		}
	}

}

int main() {
	run();
	return 0;
}