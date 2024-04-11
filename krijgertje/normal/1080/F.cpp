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

const int MAXSET=100000;
const int MAXSEG=300000;
const int MAXQ=100000;
const int MAXLGSET=17;
const int MAXS=4*MAXSET+MAXSEG*(MAXLGSET+1);

struct Seg { int l,r,belongsto; };
bool operator<(const Seg &a,const Seg &b) { return a.l<b.l; }
struct SNode { int c[2],val; };

int nset,nq,nseg;
Seg seg[MAXSEG];

SNode s[MAXS]; int ns;
int sroot[MAXSEG+1];

int smake() { assert(ns<MAXS); int ret=ns++; s[ret].c[0]=s[ret].c[1]=-1,s[ret].val=INT_MAX; return ret; }
int scopy(int x) { assert(ns<MAXS); int ret=ns++; s[ret].c[0]=s[x].c[0],s[ret].c[1]=s[x].c[1],s[ret].val=s[x].val; return ret; }
void spull(int x) { s[x].val=max(s[s[x].c[0]].val,s[s[x].c[1]].val); }

int sinit(int l,int r) {
	int x=smake();
	if(l!=r) {
		int m=l+(r-l)/2;
		s[x].c[0]=sinit(l,m);
		s[x].c[1]=sinit(m+1,r);
		spull(x);
	}
	return x;
}
int supd(int x,int l,int r,int IDX,int VAL) {
	x=scopy(x);
	if(l==r) {
		s[x].val=min(s[x].val,VAL);
	} else {
		int m=l+(r-l)/2;
		if(IDX<=m) s[x].c[0]=supd(s[x].c[0],l,m,IDX,VAL);
		if(m+1<=IDX) s[x].c[1]=supd(s[x].c[1],m+1,r,IDX,VAL);
		spull(x);
	}
	return x;
}
int sget(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) {
		return s[x].val;
	} else {
		int m=l+(r-l)/2,ret=INT_MIN;
		if(L<=m) ret=max(ret,sget(s[x].c[0],l,m,L,R));
		if(m+1<=R) ret=max(ret,sget(s[x].c[1],m+1,r,L,R));
		return ret;
	}
}


void build() {
	//printf("MAXS=%d\n",MAXS);
	sort(seg,seg+nseg);
	//printf("seg:"); REP(i,nseg) printf(" %d=%d..%d",seg[i].belongsto,seg[i].l,seg[i].r); puts("");
	ns=0; sroot[nseg]=sinit(0,nset-1);
	for(int i=nseg-1;i>=0;--i) {
		sroot[i]=supd(sroot[i+1],0,nset-1,seg[i].belongsto,seg[i].r);
	}
	//printf("ns=%d\n",ns);
}

bool query(int a,int b,int l,int r) {
	int lo=-1,hi=nseg; while(lo+1<hi) { int mi=lo+(hi-lo)/2; if(seg[mi].l>=l) hi=mi; else lo=mi; } int at=hi;
	int need=sget(sroot[at],0,nset-1,a,b);
	//printf("q(%d..%d,%d..%d): at=%d need=%d\n",a,b,l,r,at,need);
	return r>=need;
}

void run() {
	scanf("%d%d%d",&nset,&nq,&nseg);
	REP(i,nseg) scanf("%d%d%d",&seg[i].l,&seg[i].r,&seg[i].belongsto),--seg[i].belongsto;

	build();
	REP(i,nq) {
		int a,b,l,r; scanf("%d%d%d%d",&a,&b,&l,&r); --a,--b;
		printf("%s\n",query(a,b,l,r)?"yes":"no"); fflush(stdout);
	}
}

int main() {
	run();
	return 0;
}