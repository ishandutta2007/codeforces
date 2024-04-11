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

const int MAXSPOTS=50;
const int MAXH=50;
const int MAXZ=50;

const int MAXGN=2+MAXSPOTS*(MAXH+1)+MAXZ;
const int MAXGM=MAXSPOTS*(MAXH+1)+MAXSPOTS*MAXH+MAXZ*MAXSPOTS+MAXZ;

typedef struct MF {
	int n,m;
	int ghead[MAXGN],gnxt[2*MAXGM],gto[2*MAXGM]; ll gcap[2*MAXGM];
	void init(int _n) { n=_n,m=0; REP(i,n) ghead[i]=-1; }
	void addedge(int a,int b,ll c) { gnxt[2*m+0]=ghead[a],ghead[a]=2*m+0,gto[2*m+0]=b,gcap[2*m+0]=c; gnxt[2*m+1]=ghead[b],ghead[b]=2*m+1,gto[2*m+1]=a,gcap[2*m+1]=0; ++m; /*printf("%d->%d\n",a,b);*/ }
	int d[MAXGN];
	int q[MAXGN],qhead,qtail;
	int cur[MAXGN];
	ll dinic(int s,int t) {
		ll ret=0; int niter=0;
		while(true) {
			REP(i,n) d[i]=INT_MAX; qhead=qtail=0; d[s]=0,q[qhead++]=s;
			while(qtail<qhead&&d[t]==INT_MAX) { int at=q[qtail++];for(int x=ghead[at];x!=-1;x=gnxt[x]) { int to=gto[x]; if(gcap[x]==0||d[to]!=INT_MAX) continue; d[to]=d[at]+1; q[qhead++]=to; } }
			if(d[t]==INT_MAX) return ret;
			REP(i,n) cur[i]=ghead[i];
			ret+=dfs(s,t,LLONG_MAX); ++niter;
		}
	}
	ll dfs(int at,int t,ll rem) {
		ll ret=0; if(at==t) return rem;
		if(d[at]>=d[t]) return 0;
		for(;cur[at]!=-1;cur[at]=gnxt[cur[at]]) {
			int to=gto[cur[at]]; ll cap=gcap[cur[at]]; if(d[to]!=d[at]+1||cap==0) continue;
			ll now=dfs(to,t,min(cap,rem));
			rem-=now; ret+=now; if(gcap[cur[at]]!=LLONG_MAX) gcap[cur[at]]-=now; if(gcap[cur[at]^1]!=LLONG_MAX) gcap[cur[at]^1]+=now; if(rem==0) return ret;
		}
		return ret;
	}
} MF;
MF g;


int nspots,mxheight,nz;
int zl[MAXZ],zr[MAXZ],zh[MAXZ],zcost[MAXZ];

int nid,srcid,snkid;
int optid[MAXSPOTS][MAXH+1];
int zid[MAXZ];


int solve() {
	nid=0; srcid=nid++; snkid=nid++;
	REP(i,nspots) REPE(j,mxheight) optid[i][j]=nid++;
	REP(i,nz) zid[i]=nid++;
	g.init(nid);
	int mxgain=nspots*mxheight*mxheight;
	int INF=mxgain;
	REP(i,nspots) REPE(j,mxheight) g.addedge(srcid,optid[i][j],j==0?0:2*j-1);
	REP(i,nspots) FORE(j,1,mxheight) g.addedge(optid[i][j],optid[i][j-1],INF);
	REP(i,nz) if(zh[i]!=mxheight) FORE(j,zl[i],zr[i]) g.addedge(optid[j][zh[i]+1],zid[i],INF);
	REP(i,nz) g.addedge(zid[i],snkid,zcost[i]);
	ll flow=g.dinic(srcid,snkid);
	//printf("mxgain=%d flow=%lld\n",mxgain,flow);
	return mxgain-flow;
}

void run() {
	scanf("%d%d%d",&nspots,&mxheight,&nz);
	REP(i,nz) scanf("%d%d%d%d",&zl[i],&zr[i],&zh[i],&zcost[i]),--zl[i],--zr[i];
	printf("%d\n",solve());

}

int main() {
	run();
	return 0;
}