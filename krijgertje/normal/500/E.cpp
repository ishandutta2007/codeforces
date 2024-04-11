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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int n,nq;
int x[200000];
int h[200000];

int xx[200000];

int par[20][200000];
int cst[20][200000];

const int MAXS=1<<23;
int ns;
int lft[MAXS];
int rgt[MAXS];
int maxval[MAXS];
int create() {
	assert(ns<MAXS);
	lft[ns]=rgt[ns]=-1; maxval[ns]=0; return ns++;
}
int getmax(int z,int l,int r,int L,int R) {
	if(z==-1) return 0;
	if(L<=l&&r<=R) return maxval[z];
	int m=l+(r-l)/2;
	if(R<=m) return getmax(lft[z],l,m,L,R);
	if(m+1<=L) return getmax(rgt[z],m+1,r,L,R);
	return max(getmax(lft[z],l,m,L,R),getmax(rgt[z],m+1,r,L,R));
}
void updatemax(int &z,int l,int r,int IDX,int VAL) {
	if(z==-1) z=create();
	if(IDX<=l&&r<=IDX) {
		maxval[z]=max(maxval[z],VAL);
	} else {
		int m=l+(r-l)/2;
		if(IDX<=m) {
			updatemax(lft[z],l,m,IDX,VAL);
			maxval[z]=max(maxval[z],maxval[lft[z]]);
		} else {
			updatemax(rgt[z],m+1,r,IDX,VAL);
			maxval[z]=max(maxval[z],maxval[rgt[z]]);
		}
	}
}

int getrand() { int ret=rand(); ret=ret*RAND_MAX+rand(); ret=ret*RAND_MAX+rand(); ret=ret*RAND_MAX+rand(); ret=ret*RAND_MAX+rand(); if(ret<0) ret=-ret; return ret; }

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&x[i],&h[i]);
//	n=200000; REP(i,n) x[i]=getrand()%1000000000+1,h[i]=getrand()%1000000000+1; sort(x,x+n);


	ns=0; int root=-1;
	memset(maxval,0,sizeof(maxval));
	for(int i=n-1;i>=0;--i) {
		xx[i]=max(x[i]+h[i],getmax(root,0,INT_MAX,x[i],x[i]+h[i]));
		int l=i,h=n; // (l,h]
		while(l+1<h) {
			int m=l+(h-l)/2;
			if(x[m]>xx[i]) h=m; else l=m;
		}
		updatemax(root,0,INT_MAX,x[i],xx[i]);
		par[0][i]=h<n?h:i;
		cst[0][i]=h<n?x[h]-xx[i]:0;
	}
	//REP(i,n) printf("%d: %d costs %d (%d..%d->%d..%d)\n",i,par[0][i],cst[0][i],x[i],x[i]+h[i],xx[i],x[par[0][i]]);
	REP(i,19) REP(j,n) par[i+1][j]=par[i][par[i][j]],cst[i+1][j]=cst[i][j]+cst[i][par[i][j]];


	scanf("%d",&nq);
	REP(qi,nq) {
		int s,t; scanf("%d%d",&s,&t); --s,--t;
		int ret=0;
		for(int i=19;i>=0;--i) if(par[i][s]<t) { ret+=cst[i][s]; s=par[i][s]; }
		if(x[t]>xx[s]) ret+=x[t]-xx[s];
		printf("%d\n",ret);
	}
	
}

int main() {
	run();
	return 0;
}