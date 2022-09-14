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
const int MAXS=4*MAXN;

int n,nq;
int sval[MAXN];

ll sum[MAXS][10],nsum[10];
int lazy[MAXS][10],nlazy[10];

void sapply(int x,int old,int nw) { REP(i,10) if(lazy[x][i]==old) lazy[x][i]=nw; sum[x][nw]+=sum[x][old]; sum[x][old]=0; }
void sapply2(int x,int old,int nw) { REP(i,10) if(lazy[x][i]==old) nlazy[i]=nw; nsum[nw]+=sum[x][old]; nsum[old]-=sum[x][old]; }
void spush(int x) {
	FORE(dx,1,2) {
		REP(i,10) nlazy[i]=lazy[2*x+dx][i],nsum[i]=sum[2*x+dx][i];
		REP(i,10) if(lazy[x][i]!=i) sapply2(2*x+dx,i,lazy[x][i]);
		REP(i,10) lazy[2*x+dx][i]=nlazy[i],sum[2*x+dx][i]=nsum[i];
	}
	REP(i,10) lazy[x][i]=i;
}
void scalc(int x) { REP(i,10) sum[x][i]=sum[2*x+1][i]+sum[2*x+2][i]; }

void sinit(int x,int l,int r) {
	REP(i,10) lazy[x][i]=i;
	if(l==r) {
		REP(i,10) sum[x][i]=0; for(int v=sval[l],mlt=1;v!=0;v/=10,mlt*=10) sum[x][v%10]+=mlt;
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m); sinit(2*x+2,m+1,r);
		scalc(x);
//		printf("%d..%d:",l,r); REP(i,10) printf(" %lld",sum[x][i]); puts("");
	}
}
void smod(int x,int l,int r,int L,int R,int X,int Y) {
	if(L<=l&&r<=R) {
		sapply(x,X,Y);
	} else {
		spush(x);
		int m=l+(r-l)/2;
		if(L<=m) smod(2*x+1,l,m,L,R,X,Y);
		if(m+1<=R) smod(2*x+2,m+1,r,L,R,X,Y);
		scalc(x);
	}
	//printf("%d..%d:",l,r); REP(i,10) printf(" %lld",sum[x][i]); puts("");
}
ll sget(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		//printf("%d..%d:",l,r); REP(i,10) printf(" %lld",sum[x][i]); puts("");
		ll ret=0; REP(i,10) ret+=i*sum[x][i]; return ret;
	} else {
		spush(x);
		int m=l+(r-l)/2;
		ll ret=0;
		if(L<=m) ret+=sget(2*x+1,l,m,L,R);
		if(m+1<=R) ret+=sget(2*x+2,m+1,r,L,R);
		return ret;
	}
}

void run() {
	scanf("%d%d",&n,&nq); REP(i,n) scanf("%d",&sval[i]);
	sinit(0,0,n-1);
	REP(i,nq) {
		int tp; scanf("%d",&tp);
		if(tp==1) { int l,r,x,y; scanf("%d%d%d%d",&l,&r,&x,&y); --l,--r; if(x!=y) smod(0,0,n-1,l,r,x,y); }
		if(tp==2) { int l,r; scanf("%d%d",&l,&r); --l,--r; ll ret=sget(0,0,n-1,l,r); printf("%lld\n",ret); }
	}
}

int main() {
	run();
	return 0;
}