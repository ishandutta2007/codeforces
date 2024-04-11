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

const int MAXN=100000;
const int MAXD=MAXN-1;
const int MAXS=4*MAXD;

int n;
int a[MAXN];

int nd;
ll d[MAXN-1];
ll dsum;

ll sval[MAXS];
int sidx[MAXS];

void spull(int x,int l,int m,int r) {
	sval[x]=min(sval[2*x+1],sval[2*x+2]);
	ll a=d[m],b=d[m+1];
	if(a>=0&&b<=0) sval[x]=0;
	if(a<0&&b<=0) sval[x]=min(sval[x],-a);
	if(a>=0&&b>0) sval[x]=min(sval[x],+b);
	if(sval[x]==0) sidx[x]=-1; else { sidx[x]=sidx[2*x+1]; if(sidx[2*x+2]!=-1) { assert(sidx[x]==-1); sidx[x]=sidx[2*x+2]; } if(a<0&&b>0) { assert(sidx[x]==-1); sidx[x]=m; } } 
}

void sinit(int x,int l,int r) {
	if(l==r) {
		sval[x]=LLONG_MAX,sidx[x]=-1;
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m);
		sinit(2*x+2,m+1,r);
		spull(x,l,m,r);
	}
	//printf("sinit(%d,%d..%d)=%lld\n",x,l,r,sval[x]);
}

void smod(int x,int l,int r,int IDX) {
	if(l==r) {
	} else {
		int m=l+(r-l)/2;
		if(IDX<=m) smod(2*x+1,l,m,IDX);
		if(m+1<=IDX) smod(2*x+2,m+1,r,IDX);
		spull(x,l,m,r);
	}
	//printf("smod(%d,%d..%d)=%lld\n",x,l,r,sval[x]);
}

ll sget(int x,int l,int r,int L,int R,int VAL) {
	ll ret=LLONG_MIN;
	if(L<=l&&r<=R) {
		ret=sval[x]==LLONG_MAX?LLONG_MIN:(ll)2*VAL-2*min((ll)VAL,sval[x]);
		if(sidx[x]!=-1) ret=max(ret,abs(d[sidx[x]]+VAL)+abs(d[sidx[x]+1]-VAL)-abs(d[sidx[x]])-abs(d[sidx[x]+1]));
	} else {
		int m=l+(r-l)/2;
		if(L<=m) ret=max(ret,sget(2*x+1,l,m,L,R,VAL));
		if(m+1<=R) ret=max(ret,sget(2*x+2,m+1,r,L,R,VAL));
		if(L<=m&&m+1<=R) ret=max(ret,abs(d[m]+VAL)+abs(d[m+1]-VAL)-abs(d[m])-abs(d[m+1]));
	}
	//printf("sget(%d,%d..%d,%d..%d,%d)=%lld\n",x,l,r,L,R,VAL,ret);
	return ret;
}



void dmod(int idx,int by) {
	dsum-=abs(d[idx]); d[idx]+=by; dsum+=abs(d[idx]);
	smod(0,0,nd-1,idx);
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);

	nd=n-1;
	REP(i,nd) d[i]=a[i+1]-a[i];
	dsum=0; REP(i,nd) dsum+=abs(d[i]);
	sinit(0,0,nd-1);

	int nq; scanf("%d",&nq);
	REP(i,nq) {
		int kind,l,r,x; scanf("%d%d%d%d",&kind,&l,&r,&x); --l,--r;
		if(kind==1) {
			ll best=LLONG_MIN;
			if(l==0) { best=max(best,abs(d[0]-x)-abs(d[0])); ++l; }
			if(r==n-1) { best=max(best,abs(d[nd-1]+x)-abs(d[nd-1])); --r; }
			if(l==r) { best=max(best,abs(d[l-1]+x)+abs(d[l]-x)-abs(d[l-1])-abs(d[l])); }
			if(l<r) { best=max(best,sget(0,0,nd-1,l-1,r,x)); }
			printf("%lld\n",dsum+best);
		}
		if(kind==2) {
			if(l!=0) dmod(l-1,+x);
			if(r!=n-1) dmod(r,-x);
		}
	}
}

int main() {
	run();
	return 0;
}