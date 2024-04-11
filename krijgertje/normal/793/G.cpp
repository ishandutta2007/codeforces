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
#include <random>
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

const int MAXN=10000;
const int MAXBLOCKS=10000;
const int MAXRECT=4*MAXBLOCKS;
const int MAXGN=2+4*MAXN+MAXRECT;
const int MAXGM=6*MAXN+2*2*14*MAXRECT;
typedef struct R { int lx,ly,hx,hy; } R;

int n,h,w;
R b[MAXBLOCKS]; int nb;
bool blocked[MAXN][MAXN];
R r[MAXRECT]; int nr;

typedef struct MF {
	int n,m;
	int ghead[MAXGN],gnxt[2*MAXGM],gto[2*MAXGM],gcap[2*MAXGM];
	void init(int _n) { n=_n,m=0; REP(i,n) ghead[i]=-1; }
	void addedge(int a,int b,int c) { gnxt[2*m+0]=ghead[a],ghead[a]=2*m+0,gto[2*m+0]=b,gcap[2*m+0]=c; gnxt[2*m+1]=ghead[b],ghead[b]=2*m+1,gto[2*m+1]=a,gcap[2*m+1]=0; ++m; /*printf("%d->%d\n",a,b);*/ }
	int d[MAXGN];
	int q[MAXGN],qhead,qtail;
	int cur[MAXGN];
	int dinic(int s,int t) {
		int ret=0; int niter=0;
		while(true) {
			REP(i,n) d[i]=INT_MAX; qhead=qtail=0; d[s]=0,q[qhead++]=s;
			while(qtail<qhead&&d[t]==INT_MAX) { int at=q[qtail++];for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x]; if(gcap[x]==0||d[to]!=INT_MAX) continue; d[to]=d[at]+1; q[qhead++]=to; } }
			if(d[t]==INT_MAX) { /*printf("niter=%d\n",niter);*/ return ret; }
			REP(i,n) cur[i]=ghead[i];
			ret+=dfs(s,t,INT_MAX); ++niter;
		}
	}
	int dfs(int at,int t,int rem) {
		int ret=0; if(at==t) return rem;
		if(d[at]>=d[t]) return 0;
		for(;cur[at]!=-1;cur[at]=gnxt[cur[at]]) {
			int to=gto[cur[at]],cap=gcap[cur[at]]; if(d[to]!=d[at]+1||cap==0) continue;
			int now=dfs(to,t,min(cap,rem));
			rem-=now; ret+=now; gcap[cur[at]]-=now; gcap[cur[at]^1]+=now; if(rem==0) return ret;
		}
		return ret;
	}
	void print() { REP(i,m) if(gcap[2*i+0]==0) printf("used %d->%d\n",gto[2*i+1],gto[2*i+0]); }
} MF;
MF g;

int solve() {
	memset(blocked,false,sizeof(blocked)); h=w=n;
	REP(i,nb) FORE(x,b[i].lx,b[i].hx) FORE(y,b[i].ly,b[i].hy) blocked[x][y]=true;

	nr=0;
	REP(lx,h) REP(ly,w) if(!blocked[lx][ly]) {
		int hy=ly; while(hy+1<w&&!blocked[lx][hy+1]) ++hy;
		int hx=lx; while(hx+1<h) { bool ok=true; FORE(y,ly,hy) if(blocked[hx+1][y]) { ok=false; break; } if(!ok) break; else ++hx; }
		r[nr].lx=lx,r[nr].ly=ly,r[nr].hx=hx,r[nr].hy=hy,++nr;
		FORE(x,lx,hx) FORE(y,ly,hy) blocked[x][y]=true;
	}
	//printf("nr=%d\n",nr);
	//REP(i,nr) printf("(%d..%d)/(%d..%d)\n",r[i].lx,r[i].hx,r[i].ly,r[i].hy);


	g.init(2+4*n+nr);
	//printf("g.n=%d\n",g.n);
	REP(i,n) g.addedge(0,2+n+i,1);
	FOR(i,1,n) g.addedge(2+2*i,2+i,n),g.addedge(2+2*i+1,2+i,n);
	REP(i,n) g.addedge(2+3*n+i,1,1);
	FOR(i,1,n) g.addedge(2+2*n+i,2+2*n+2*i,n),g.addedge(2+2*n+i,2+2*n+2*i+1,n);
	//printf("g.m=%d\n",g.m);
	REP(i,nr) {
		{
			int lidx=n+r[i].lx,ridx=n+r[i].hx+1;
			for(;lidx<ridx;lidx>>=1,ridx>>=1) {
				if(lidx&1) g.addedge(2+lidx,2+4*n+i,n),++lidx;
				if(ridx&1) --ridx,g.addedge(2+ridx,2+4*n+i,n);
			}
		}
		{
			int lidx=n+r[i].ly,ridx=n+r[i].hy+1;
			for(;lidx<ridx;lidx>>=1,ridx>>=1) {
				if(lidx&1) g.addedge(2+4*n+i,2+2*n+lidx,n),++lidx;
				if(ridx&1) --ridx,g.addedge(2+4*n+i,2+2*n+ridx,n);
			}
		}
	}
	//printf("g.m=%d\n",g.m);

	int ret=g.dinic(0,1);
	return ret;
}

void run() {
	scanf("%d",&n);
	scanf("%d",&nb); REP(i,nb) { int lx,ly,hx,hy; scanf("%d%d%d%d",&b[i].lx,&b[i].ly,&b[i].hx,&b[i].hy); --b[i].lx,--b[i].ly,--b[i].hx,--b[i].hy;  }
	printf("%d\n",solve());
}

void stress() {
	n=MAXN; nb=MAXBLOCKS-1; REP(i,nb) { b[i].lx=i,b[i].hx=i,b[i].ly=(rand()*1000+rand())%n,b[i].hy=n-1; }
	//printf("%d\n%d\n",n,nb); REP(i,nb) printf("%d %d %d %d\n",b[i].lx+1,b[i].ly+1,b[i].hx+1,b[i].hy+1); return;
	clock_t begin = clock();
	printf("%d\n",solve());
	clock_t end = clock(); printf("%.9lf\n",(double)(end-begin)/CLOCKS_PER_SEC);
}

int main() {
	//stress();
	run();
	return 0;
}