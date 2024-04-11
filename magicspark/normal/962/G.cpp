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

const int MAXN=15000;
struct P { int x,y; P() {} P(int x,int y):x(x),y(y) {} };

int wlx,wly,whx,why;
int n;
P p[MAXN];

int whor,wver;
int inter[2*MAXN],ninter; // points in order encountered by the polygon
int all[2*MAXN],nall;
int nxt[2*MAXN];

bool been[2*MAXN];

void addinter(const P &a,const P &b) {
	if(a.x==b.x) {
		int x=a.x;
		if(x<wlx||x>whx) return;
		int ly=min(a.y,b.y),hy=max(a.y,b.y);
		int u=ly<=wly&&wly<=hy?whor+wver+x-wlx:-1;
		int v=ly<=why&&why<=hy?whx-x:-1;
		if(a.y>b.y) swap(u,v);
		if(u!=-1) inter[ninter++]=u;
		if(v!=-1) inter[ninter++]=v;
	} else if(a.y==b.y) {
		int y=a.y;
		if(y<wly||y>why) return;
		int lx=min(a.x,b.x),hx=max(a.x,b.x);
		int u=lx<=wlx&&wlx<=hx?whor+why-y:-1;
		int v=lx<=whx&&whx<=hx?whor+wver+whor+y-wly:-1;
		if(a.x>b.x) swap(u,v);
		if(u!=-1) inter[ninter++]=u;
		if(v!=-1) inter[ninter++]=v;
	}
}
bool insidepolygon(const P &a) {
	int cnt=0;
	REP(i,n) {
		int j=(i+1)%n;
		if(p[i].x!=p[j].x||p[i].x>=a.x) continue;
		int ly=min(p[i].y,p[j].y),hy=max(p[i].y,p[j].y);
		if(ly<a.y&&a.y<hy) ++cnt;
	}
	return cnt%2==1;
}
bool outsidewindow(const P &a) {
	return a.x<wlx||a.x>whx||a.y<wly||a.y>why;
}


int solve() {
	swap(wly,why); wlx*=3,wly*=3,whx*=3,why*=3; ++wlx,++wly,--whx,--why; REP(i,n) p[i].x*=3,p[i].y*=3;
	whor=whx-wlx,wver=why-wly;

	//printf("w: (%d,%d) (%d,%d)\n",wlx,wly,whx,why);
	//REP(i,n) printf("(%d,%d): %s\n",p[i].x,p[i].y,outsidewindow(p[i])?"outside":"inside");
	//for(int y=50;y>=-10;--y) if(y%3!=0) { FORE(x,-10,+50) if(x%3!=0) printf("%c",insidepolygon(P(x,y))?'*':'.'); puts(""); }

	int outidx=0; while(outidx<n&&!outsidewindow(p[outidx])) ++outidx;
	if(outidx>=n) return 1; // polygon completely inside window

	ninter=0;
	REP(i,n) { int a=(outidx+i)%n,b=(outidx+i+1)%n; addinter(p[a],p[b]); }
	//printf("inter:"); REP(i,ninter) printf(" %d",inter[i]); puts("");
	assert(ninter%2==0);
	if(ninter==0) return insidepolygon(P(wlx,wly))?1:0; // either window completely inside polygon or completely disjoint

	nall=0; REP(i,ninter) all[nall++]=inter[i]; sort(all,all+nall); nall=unique(all,all+nall)-all; assert(nall==ninter);
	REP(i,ninter) inter[i]=lower_bound(all,all+nall,inter[i])-all;
	REP(i,ninter) nxt[inter[i]]=inter[(i+1)%n];

	int ret=0;
	REP(i,ninter) been[i]=false;
	for(int i=0;i<ninter;i++) if(!been[inter[i]]) {
		++ret;
		int at=inter[i];
		while(!been[at]) { been[at]=true; at=nxt[at]; been[at]=true; at=(at+1)%ninter; }
	}
	return ret;
}

void run() {
	scanf("%d%d%d%d",&wlx,&wly,&whx,&why); scanf("%d",&n); REP(i,n) scanf("%d%d",&p[i].x,&p[i].y);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}