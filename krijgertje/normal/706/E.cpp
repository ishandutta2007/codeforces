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

const int MAXH=1000;
const int MAXW=1000;
const int MAXV=(MAXH+2)*(MAXW+2);

int h,w,nq;

int v[MAXV];
int root,rgt[MAXV],dwn[MAXV];



void run() {
	scanf("%d%d%d",&h,&w,&nq);
	root=0;
	REP(x,h+2) REP(y,w+2) rgt[x*(w+2)+y]=y+1<w+2?x*(w+2)+(y+1):-1;
	REP(x,h+2) REP(y,w+2) dwn[x*(w+2)+y]=x+1<h+2?(x+1)*(w+2)+y:-1;
	memset(v,-1,sizeof(v)); FORE(x,1,h) FORE(y,1,w) scanf("%d",&v[x*(w+2)+y]);
	
	//{ REP(x,h+2) { int at=root; REP(xx,x) at=dwn[at]; REP(y,w+2) { if(y!=0) printf(" "); printf("%2d",at); at=rgt[at]; } puts(""); } }
	REP(qi,nq) {
		int ax,ay,bx,by,xx,yy; scanf("%d%d%d%d%d%d",&ax,&ay,&bx,&by,&xx,&yy);
		int ap=root; REP(x,ax-1) ap=dwn[ap]; REP(y,ay-1) ap=rgt[ap]; int ar=rgt[ap]; ap=dwn[ap];
		int aq=ap; REP(y,yy) aq=rgt[aq]; int as=ar; REP(x,xx) as=dwn[as];
		int bp=root; REP(x,bx-1) bp=dwn[bp]; REP(y,by-1) bp=rgt[bp]; int br=rgt[bp]; bp=dwn[bp];
		int bq=bp; REP(y,yy) bq=rgt[bq]; int bs=br; REP(x,xx) bs=dwn[bs];
		//printf("\t%d %d %d %d | %d %d %d %d\n",v[ap],v[aq],v[ar],v[as],v[bp],v[bq],v[br],v[bs]);
		//printf("\t%d %d %d %d | %d %d %d %d\n",ap,aq,ar,as,bp,bq,br,bs);
		REP(x,xx) { swap(rgt[ap],rgt[bp]); ap=dwn[ap],bp=dwn[bp]; }
		REP(x,xx) { swap(rgt[aq],rgt[bq]); aq=dwn[aq],bq=dwn[bq]; }
		REP(y,yy) { swap(dwn[ar],dwn[br]); ar=rgt[ar],br=rgt[br]; }
		REP(y,yy) { swap(dwn[as],dwn[bs]); as=rgt[as],bs=rgt[bs]; }
	}
	{ REP(x,h) { int at=rgt[dwn[root]]; REP(xx,x) at=dwn[at]; REP(y,w) { if(y!=0) printf(" "); printf("%d",v[at]); at=rgt[at]; } puts(""); } }
}

int main() {
	run();
	return 0;
}