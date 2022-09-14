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
#include <random>
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

const int MAXB=100000;
const int MAXQ=100000;
const int MAXA=2*MAXQ-1;
const int MAXRMQ=MAXA>=MAXB?4*MAXA:4*MAXB;

typedef struct RMQ {
	int n; int *a; char c;
	int val[4*MAXRMQ]; int lazy[4*MAXRMQ];
	void _push(int x) {
		if(lazy[x]!=-1) val[2*x+1]=lazy[2*x+1]=val[2*x+2]=lazy[2*x+2]=lazy[x],lazy[x]=-1;
	}
	void _init(int x,int l,int r) { lazy[x]=-1; if(l==r) { val[x]=a[l]; return; } int m=l+(r-l)/2; _init(2*x+1,l,m); _init(2*x+2,m+1,r); val[x]=min(val[2*x+1],val[2*x+2]); }
	void init(char _c,int _n,int *_a) { c=_c,n=_n,a=_a; _init(0,0,n-1); }
	void _set(int x,int l,int r,int L,int R,int VAL) {
		if(L<=l&&r<=R) { lazy[x]=val[x]=VAL; return; }
		_push(x);
		int m=l+(r-l)/2;
		if(L<=m) _set(2*x+1,l,m,L,R,VAL);
		if(m+1<=R) _set(2*x+2,m+1,r,L,R,VAL);
		val[x]=min(val[2*x+1],val[2*x+2]);
	}
	void set(int L,int R,int VAL) {
		//printf("%c: set(%d,%d,%d)\n",c,L,R,VAL);
		_set(0,0,n-1,L,R,VAL);
	}
	int _get(int x,int l,int r,int L,int R) {
		if(L<=l&&r<=R) return val[x];
		if(lazy[x]!=-1) return lazy[x];
		int m=l+(r-l)/2,ret=INT_MAX;
		if(L<=m) ret=min(ret,_get(2*x+1,l,m,L,R));
		if(m+1<=R) ret=min(ret,_get(2*x+2,m+1,r,L,R));
		return ret;
	}
	int get(int L,int R) { 
		int ret=_get(0,0,n-1,L,R);
		//printf("%c: get(%d,%d)=%d\n",c,L,R,ret);
		return ret;
	}

} RMQ;

int nb,nrep,nq;
int b[MAXB];
int qt[MAXQ],ql[MAXQ],qr[MAXQ],qv[MAXQ];
RMQ qa,qb;

int x[2*MAXQ],nx;
int a[2*MAXQ],na;



void run() {
	scanf("%d%d",&nb,&nrep); REP(i,nb) scanf("%d",&b[i]); scanf("%d",&nq);
	REP(i,nq) {
		scanf("%d",&qt[i]);
		if(qt[i]==1) scanf("%d%d%d",&ql[i],&qr[i],&qv[i]),--ql[i],--qr[i];
		if(qt[i]==2) scanf("%d%d",&ql[i],&qr[i]),--ql[i],--qr[i];
	}
	nx=0; REP(i,nq) x[nx++]=ql[i],x[nx++]=qr[i]+1; sort(x,x+nx); nx=unique(x,x+nx)-x; na=nx-1;
	qb.init('B',nb,b);
	REP(i,na) {
		int l=x[i],r=x[i+1]-1;
		int pl=l/nb,ql=l%nb,pr=r/nb,qr=r%nb;
		if(pl==pr) a[i]=qb.get(ql,qr); else if(pl+1==pr) a[i]=min(qb.get(ql,nb-1),qb.get(0,qr)); else a[i]=qb.get(0,nb-1);
	}
	//REP(i,na) printf("%d: %d..%d = %d\n",i,x[i],x[i+1]-1,a[i]);
	qa.init('A',na,a);
	REP(i,nq) {
		int l=lower_bound(x,x+nx,ql[i])-x;
		int r=lower_bound(x,x+nx,qr[i]+1)-x-1;
		if(qt[i]==1) {
			qa.set(l,r,qv[i]);
		}
		if(qt[i]==2) {
			int ret=qa.get(l,r);
			printf("%d\n",ret);
		}
	}
}

int main() {
	run();
	return 0;
}