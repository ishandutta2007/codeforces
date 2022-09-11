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
const int MAXJUMP=5;
struct Res { int val[MAXJUMP+1]; };

int n,mxjump,nq;
ll a[MAXN];

Res sres[MAXS][2];
bool slazy[MAXS];

Res merge(const Res &a,const Res &b) {
	Res ret;
	REPE(i,mxjump) ret.val[i]=a.val[b.val[i]];
	return ret;
}

void sapply(int x) {
	swap(sres[x][0],sres[x][1]);
	slazy[x]=!slazy[x];
}
void spull(int x) {
	REP(i,2) sres[x][i]=merge(sres[2*x+1][i],sres[2*x+2][i]);
}
void spush(int x) {
	if(slazy[x]) sapply(2*x+1),sapply(2*x+2),slazy[x]=false;
}
void sprint(const Res &res) {
	printf("["); REPE(j,mxjump) { if(j!=0) printf(","); printf("%d",res.val[j]); } printf("]");
}
void sprint(int x) {
	REP(i,2) { sprint(sres[x][i]); } 
}

void sinit(int x,int l,int r) {
	if(l==r) {
		REPE(i,mxjump) sres[x][0].val[i]=i==0?0:i-1;
		REPE(i,mxjump) sres[x][1].val[i]=i==0?mxjump:i-1;
		if(a[l]%2==1) sapply(x);
	} else {
		int m=l+(r-l)/2;
		sinit(2*x+1,l,m);
		sinit(2*x+2,m+1,r);
		spull(x);
	}
	//printf("sinit(%d,%d..%d): ",x,l,r); sprint(x); puts("");
}

void smod(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		sapply(x);
	} else {
		spush(x);
		int m=l+(r-l)/2;
		if(L<=m) smod(2*x+1,l,m,L,R);
		if(m+1<=R) smod(2*x+2,m+1,r,L,R);
		spull(x);
	}
	//printf("smod(%d,%d..%d): ",x,l,r); sprint(x); puts("");
}

Res sget(int x,int l,int r,int L,int R) {
	Res ret;
	if(L<=l&&r<=R) {
		ret=sres[x][0];
	} else {
		spush(x);
		int m=l+(r-l)/2;
		if(m+1>R) ret=sget(2*x+1,l,m,L,R);
		else if(L>m) ret=sget(2*x+2,m+1,r,L,R);
		else ret=merge(sget(2*x+1,l,m,L,R),sget(2*x+2,m+1,r,L,R));
		spull(x);
	}
	//printf("sget(%d..%d): ",max(l,L),min(r,R)); sprint(ret); puts("");
	return ret;
}


void run() {
	scanf("%d%d%d",&n,&mxjump,&nq);
	REP(i,n) scanf("%lld",&a[i]);
	sinit(0,0,n-1);
	REP(i,nq) {
		int kind; scanf("%d",&kind);
		if(kind==1) {
			int l,r; ll by; scanf("%d%d%lld",&l,&r,&by); --l,--r;
			if(by%2==1) smod(0,0,n-1,l,r);
		}
		if(kind==2) {
			int l,r; scanf("%d%d",&l,&r); --l,--r;
			Res res=sget(0,0,n-1,l,r);
			printf("%d\n",res.val[0]!=mxjump?1:2);
		}
	}
}

int main() {
	run();
	return 0;
}