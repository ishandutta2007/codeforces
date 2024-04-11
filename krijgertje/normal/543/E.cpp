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

const bool DEBUG=false;
const int MAXN=DEBUG?400:200000;
const int BLOCKSZ=DEBUG?20:500;
const int MAXBLOCKS=(MAXN+BLOCKSZ-1)/BLOCKSZ;
const int MAXBSTATES=2*BLOCKSZ+1;
const int STEPSZ=DEBUG?20:500;
const int MAXSTEPS=MAXN/STEPSZ+1;
const int MAXSEG=1<<19;
bool writedebug=false;

int sval[MAXSEG],smin[MAXSEG],scnt;
void seginit(int x,int l,int r) {
	sval[x]=smin[x]=0;
	if(l==r) return;
	int m=l+(r-l)/2;
	seginit(2*x+1,l,m);
	seginit(2*x+2,m+1,r);
}
void seginit(int _scnt) { scnt=_scnt; seginit(0,0,scnt-1); }
void segadd(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) { ++sval[x]; ++smin[x]; return; }
	int m=l+(r-l)/2;
	if(L<=m) segadd(2*x+1,l,m,L,R);
	if(m+1<=R) segadd(2*x+2,m+1,r,L,R);
	smin[x]=sval[x]+min(smin[2*x+1],smin[2*x+2]);
}
void segadd(int L,int R) { segadd(0,0,scnt-1,L,R); }
int segmn(int x,int l,int r,int L,int R) {
	if(L<=l&&r<=R) return smin[x];
	int m=l+(r-l)/2;
	if(R<=m) return sval[x]+segmn(2*x+1,l,m,L,R);
	if(L>=m+1) return sval[x]+segmn(2*x+2,m+1,r,L,R);
	return sval[x]+min(segmn(2*x+1,l,m,L,R),segmn(2*x+2,m+1,r,L,R));
}
int segmn(int L,int R) { return segmn(0,0,scnt-1,L,R); }


int n,nlisten;
typedef struct X { int val,idx; } X;
bool operator<(const X &a,const X &b) { return a.val<b.val; }
X x[MAXN];

int av[MAXN+1],al[MAXN],ar[MAXN],na;
int bcv[MAXBLOCKS][MAXBSTATES],bcl[MAXBLOCKS][MAXBSTATES-1],bcr[MAXBLOCKS][MAXBSTATES-1],bcmn[MAXBLOCKS][MAXBSTATES],nbc[MAXBLOCKS]; // local
int bd[MAXBLOCKS][MAXSTEPS]; // global


int findai(int x) { // finds last ai | av[ai]<x
	int l=0,r=na;
	while(l+1<r) {
		int m=l+(r-l)/2;
		if(av[m]<x) l=m; else r=m;
	}
	return l;
}

int findbi(int i,int x) { // finds last bi | bcv[i][bi]<x
	int l=0,r=nbc[i];
	while(l+1<r) {
		int m=l+(r-l)/2;
		if(bcv[i][m]<x) l=m; else r=m;
	}
	return l;
}

void init() {
	sort(x,x+n);
	int nblocks=(n+BLOCKSZ-1)/BLOCKSZ;
	seginit(nblocks*BLOCKSZ);
	na=0,av[na++]=-1; REP(i,MAXBLOCKS) nbc[i]=0,bcmn[i][nbc[i]]=0,bcv[i][nbc[i]++]=-1;
	REP(i,n) {
		int l=max(0,x[i].idx-nlisten+1),r=x[i].idx; 
		int bl=l/BLOCKSZ,br=r/BLOCKSZ;
		al[na-1]=bl,ar[na-1]=br,av[na++]=x[i].val;
		if(l>bl*BLOCKSZ||r<bl*BLOCKSZ+BLOCKSZ-1) {
			int cl=l-bl*BLOCKSZ,cr=bl==br?r-br*BLOCKSZ:BLOCKSZ-1;
			segadd(bl*BLOCKSZ+cl,bl*BLOCKSZ+cr);
			bcl[bl][nbc[bl]-1]=cl,bcr[bl][nbc[bl]-1]=cr,bcmn[bl][nbc[bl]]=segmn(bl*BLOCKSZ,bl*BLOCKSZ+BLOCKSZ-1),bcv[bl][nbc[bl]++]=x[i].val;
		}
		if(bl!=br&&r<br*BLOCKSZ+BLOCKSZ-1) {
			int cl=0,cr=r-br*BLOCKSZ;
			segadd(br*BLOCKSZ+cl,br*BLOCKSZ+cr);
			bcl[br][nbc[br]-1]=cl,bcr[br][nbc[br]-1]=cr,bcmn[br][nbc[br]]=segmn(br*BLOCKSZ,br*BLOCKSZ+BLOCKSZ-1),bcv[br][nbc[br]++]=x[i].val;
		}
	}

	//if(writedebug) REP(i,na-1) printf("%d %d -> %d\n",al[i],ar[i],av[i+1]);
	//if(writedebug) REP(i,nblocks) { printf("%d:",i); REP(j,nbc[i]-1) printf(" [%d,%d,%d,%d]",bcl[i][j],bcr[i][j],bcmn[i][j+1],bcv[i][j+1]); puts(""); }

	seginit(nblocks);
	REP(j,nblocks) bd[j][0]=0;
	REP(i,n) {
		int l=max(0,x[i].idx-nlisten+1),r=x[i].idx; 
		int cl=l/BLOCKSZ,cr=r/BLOCKSZ;
		if(l>cl*BLOCKSZ) ++cl;
		if(r<cr*BLOCKSZ+BLOCKSZ-1) --cr;
		if(cl<=cr) segadd(cl,cr);
		if((i+1)%STEPSZ==0) REP(j,nblocks) bd[j][(i+1)/STEPSZ]=segmn(j,j);
	}
	//if(writedebug) REP(i,nblocks) { printf("%d:",i); REPE(j,n/STEPSZ) printf(" %d",bd[i][j]); puts(""); }
}

int curglob[MAXBLOCKS+1];
int curloc[BLOCKSZ+1];
int calc(int l,int r,int q) {
	int bl=l/BLOCKSZ,br=r/BLOCKSZ;

	FORE(i,bl,br) curglob[i]=0;
	int ai=findai(q),astep=ai/STEPSZ;
	//if(writedebug) printf("ai=%d,astep=%d\n",ai,astep);
	FOR(i,astep*STEPSZ,ai) {
		int l=max(0,x[i].idx-nlisten+1),r=x[i].idx;
		int cl=l/BLOCKSZ,cr=r/BLOCKSZ;
		if(l>cl*BLOCKSZ) ++cl;
		if(r<cr*BLOCKSZ+BLOCKSZ-1) --cr;
		if(cl<bl) cl=bl;
		if(cl<=cr) curglob[cl]++,curglob[cr+1]--;
	}
	FORE(i,bl+1,br) curglob[i]+=curglob[i-1];
	FORE(i,bl,br) curglob[i]+=bd[i][astep];
	//if(writedebug) { printf("curglob:"); REP(i,4) printf(" %d",curglob[i]); puts(""); }

	int ret=INT_MAX;
	FORE(i,bl+1,br-1) {
		int bi=findbi(i,q);
		int cur=curglob[i]+bcmn[i][bi];
		//if(writedebug) printf("block %d: %d+%d=%d\n",i,curglob[i],bcmn[i][bi],cur);
		if(cur<ret) ret=cur;
	}
	{
		int bi=findbi(bl,q),cl=l-bl*BLOCKSZ,cr=bl==br?r-br*BLOCKSZ:BLOCKSZ-1;
		FORE(i,cl,cr) curloc[i]=0;
		REP(i,bi) { int dl=max(bcl[bl][i],cl),dr=bcr[bl][i]; if(dl<=dr) ++curloc[dl],--curloc[dr+1]; }
		FORE(i,cl+1,cr) curloc[i]+=curloc[i-1];
		int mnloc=curloc[cl]; FORE(i,cl+1,cr) if(curloc[i]<mnloc) mnloc=curloc[i];
		int cur=curglob[bl]+mnloc;
		//if(writedebug) printf("first %d: %d+%d=%d (bi=%d,%d)\n",bl,curglob[bl],segmn(l-bl*BLOCKSZ,bl==br?r-br*BLOCKSZ:BLOCKSZ-1),cur,bi,bcv[bl][bi]);
		if(cur<ret) ret=cur;
	}
	if(bl!=br) {
		int bi=findbi(br,q),cl=0,cr=r-br*BLOCKSZ;
		FORE(i,cl,cr) curloc[i]=0;
		REP(i,bi) { int dl=max(bcl[br][i],cl),dr=bcr[br][i]; if(dl<=dr) ++curloc[dl],--curloc[dr+1]; }
		FORE(i,cl+1,cr) curloc[i]+=curloc[i-1];
		int mnloc=curloc[cl]; FORE(i,cl+1,cr) if(curloc[i]<mnloc) mnloc=curloc[i];
		int cur=curglob[br]+mnloc;
		//if(writedebug) printf("last %d: %d+%d=%d (bi=%d)\n",br,curglob[br],segmn(0,r-br*BLOCKSZ),cur,bi);
		if(cur<ret) ret=cur;
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&nlisten);
	REP(i,n) scanf("%d",&x[i].val);
	REP(i,n) x[i].idx=i;
	init();

	int nq; scanf("%d",&nq); int pret=0;
	REP(qi,nq) {
		int l,r,x; scanf("%d%d%d",&l,&r,&x); --l,--r; int q=x^pret;
		int ret=calc(l,r,q); printf("%d\n",ret); pret=ret;
	}
}

int calcbf(int l,int r,int q) {
	int ret=INT_MAX;
	FORE(i,l,r) {
		int cur=0;
		REP(j,n) if(x[j].val<q&&x[j].idx>=i&&x[j].idx<=i+nlisten-1) ++cur;
		if(cur<ret) ret=cur;
	}
	return ret;
}
int myrand() { return rand()*(1<<15)+rand(); }
void test() {
	bool err=false;
	for(int testnr=0;!err;++testnr) {
		writedebug=testnr==0;
		n=MAXN,nlisten=rand()%n+1;
		REP(i,n) x[i].idx=i,x[i].val=myrand()%10;
		init();
		REP(i,n) {
			int l=myrand()%(n-nlisten+1),r=myrand()%(n-nlisten+1),q=myrand()%10; if(l>r) swap(l,r);
			int have=calc(l,r,q),want=calcbf(l,r,q);
			if(have!=want) {
				if(!err) { puts(""); REP(j,n) printf("x[%d]=%d\n",x[j].idx,x[j].val); err=true; }
				printf("%d %d %d -> have=%d vs want=%d\n",l,r,q,have,want);	
			}
		}
		printf(".");
	}

}

int main() {
	if(DEBUG) test(); else run();
	return 0;
}