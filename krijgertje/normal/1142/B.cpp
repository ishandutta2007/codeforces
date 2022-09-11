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

const int MAXP=200000;
const int MAXA=200000;
const int MAXQ=200000;
const int MAXS=4*MAXA;

int np,na,nq;
int p[MAXP];
int a[MAXA];
int ql[MAXQ],qr[MAXQ]; bool qans[MAXQ];

int last[MAXP];
int nxt[MAXA];
int pos[MAXP];
vector<int> prv[MAXA];
int need[MAXA];

int stck[MAXA],nstck;
void dfsneed(int at) { stck[nstck++]=at; if(nstck>=np) need[at]=stck[nstck-np]; REPSZ(i,prv[at]) dfsneed(prv[at][i]); --nstck; }

int sval[MAXS];
void sinit(int x,int l,int r) {
	if(l==r) {
		sval[x]=need[l];
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		sval[x]=min(sval[2*x+1],sval[2*x+2]);
	}
}
int sget(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		return sval[x];
	} else {
		int m=l+(r-l)/2,ret=INT_MAX;
		if(L<=m) ret=min(ret,sget(2*x+1,l,m,L,R));
		if(m+1<=R) ret=min(ret,sget(2*x+2,m+1,r,L,R));
		return ret;
	}
}

void solve() {
	REP(i,np) last[i]=-1;
	REP(i,np) pos[p[i]]=i;
	for(int i=na-1;i>=0;--i) {
		int idx=pos[a[i]];
		int want=p[(idx+1)%np];
		nxt[i]=last[want];
		last[a[i]]=i;
	}
	REP(i,na) prv[i].clear(); REP(i,na) if(nxt[i]!=-1) prv[nxt[i]].PB(i);
	REP(i,na) need[i]=na;
	REP(i,na) if(nxt[i]==-1) { nstck=0; dfsneed(i); }
	//printf("nxt:"); REP(i,na) printf(" %d",nxt[i]); puts("");
	//printf("need:"); REP(i,na) printf(" %d",need[i]); puts("");

	sinit(0,0,na-1);
	REP(i,nq) {
		int l=ql[i],r=qr[i];
		qans[i]=sget(0,0,na-1,l,r)<=r;
	}
}

void run() {
	scanf("%d%d%d",&np,&na,&nq);
	REP(i,np) scanf("%d",&p[i]),--p[i];
	REP(i,na) scanf("%d",&a[i]),--a[i];
	REP(i,nq) scanf("%d%d",&ql[i],&qr[i]),--ql[i],--qr[i];
	solve();
	REP(i,nq) printf("%d",qans[i]?1:0); puts("");
}

int main() {
	run();
	return 0;
}