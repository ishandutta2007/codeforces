#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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

const int MAXN=200000;
const int MAXS=4*MAXN;
const int MAXDIM=5;
const int MAXQ=200000;
struct Res { int val[1<<MAXDIM]; };


int n,ndim;
int pinit[MAXN][MAXDIM];
int nq;
int qkind[MAXQ],qidx[MAXQ],qdim[MAXQ][MAXDIM],ql[MAXQ],qr[MAXQ],qans[MAXQ];


int p[MAXN][MAXDIM];
Res sval[MAXS];

Res smake(int idx) {
	Res ret;
	REP(mask,1<<ndim) {
		int cur=0; REP(i,ndim) if(mask&(1<<i)) cur+=p[idx][i]; else cur-=p[idx][i];
		ret.val[mask]=cur;
	}
	return ret;
}
Res smerge(const Res &a,const Res &b) {
	Res ret; REP(mask,1<<ndim) ret.val[mask]=max(a.val[mask],b.val[mask]); return ret;
}
void sinit(int x,int l,int r) {
	if(l==r) {
		sval[x]=smake(l);
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		sval[x]=smerge(sval[2*x+1],sval[2*x+2]);
	}
}
void supdate(int x,int l,int r,int IDX) {
	if(l==r) {
		sval[x]=smake(l);
	} else {
		int m=l+(r-l)/2;
		if(IDX<=m) supdate(2*x+1,l,m,IDX); else supdate(2*x+2,m+1,r,IDX);
		sval[x]=smerge(sval[2*x+1],sval[2*x+2]);
	}
}
Res sget(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		return sval[x];
	} else {
		int m=l+(r-l)/2;
		if(m+1>R) return sget(2*x+1,l,m,L,R);
		if(L>m) return sget(2*x+2,m+1,r,L,R);
		return smerge(sget(2*x+1,l,m,L,R),sget(2*x+2,m+1,r,L,R));
	}
}

void solve() {
	REP(i,n) REP(j,ndim) p[i][j]=pinit[i][j];
	sinit(0,0,n-1);
	REP(i,nq) {
		if(qkind[i]==1) { REP(j,ndim) p[qidx[i]][j]=qdim[i][j]; supdate(0,0,n-1,qidx[i]); }
		if(qkind[i]==2) { Res cur=sget(0,0,n-1,ql[i],qr[i]); qans[i]=0; REP(j,1<<ndim) qans[i]=max(qans[i],cur.val[j]+cur.val[(1<<ndim)-1-j]); }
	}
}

void run() {
	scanf("%d%d",&n,&ndim);
	REP(i,n) REP(j,ndim) scanf("%d",&pinit[i][j]);
	scanf("%d",&nq);
	REP(i,nq) {
		scanf("%d",&qkind[i]);
		if(qkind[i]==1) { scanf("%d",&qidx[i]),--qidx[i]; REP(j,ndim) scanf("%d",&qdim[i][j]); }
		if(qkind[i]==2) { scanf("%d%d",&ql[i],&qr[i]),--ql[i],--qr[i]; }
	}
	solve();
	REP(i,nq) if(qkind[i]==2) printf("%d\n",qans[i]);
}

int main() {
	run();
	return 0;
}