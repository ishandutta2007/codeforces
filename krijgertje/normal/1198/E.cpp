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

const int MAXRECT=50;
const int MAXDIM=2*MAXRECT+2;
struct Rect { int lx,ly,hx,hy; };

const int MAXGN=2+2*(MAXDIM-1);
const int MAXGM=2*(MAXDIM-1)+(MAXDIM-1)*(MAXDIM-1);

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


int sz,nrect;
Rect rect[MAXRECT];

int allx[MAXDIM],nallx;
int ally[MAXDIM],nally;

int cnt[MAXDIM][MAXDIM];

int nid,sid,tid,rid[MAXDIM-1],cid[MAXDIM-1];

ll solve() {
	nallx=0; allx[nallx++]=0; allx[nallx++]=sz; REP(i,nrect) allx[nallx++]=rect[i].lx,allx[nallx++]=rect[i].hx; sort(allx,allx+nallx); nallx=unique(allx,allx+nallx)-allx; 
	REP(i,nrect) rect[i].lx=lower_bound(allx,allx+nallx,rect[i].lx)-allx,rect[i].hx=lower_bound(allx,allx+nallx,rect[i].hx)-allx;
	nally=0; ally[nally++]=0; ally[nally++]=sz; REP(i,nrect) ally[nally++]=rect[i].ly,ally[nally++]=rect[i].hy; sort(ally,ally+nally); nally=unique(ally,ally+nally)-ally; 
	REP(i,nrect) rect[i].ly=lower_bound(ally,ally+nally,rect[i].ly)-ally,rect[i].hy=lower_bound(ally,ally+nally,rect[i].hy)-ally;
	//REP(i,nrect) printf("rect%d: %d,%d,%d,%d\n",i,rect[i].lx,rect[i].ly,rect[i].hx,rect[i].hy);

	REP(x,nallx) REP(y,nally) cnt[x][y]=0;
	REP(i,nrect) ++cnt[rect[i].hx][rect[i].hy],--cnt[rect[i].lx][rect[i].hy],--cnt[rect[i].hx][rect[i].ly],++cnt[rect[i].lx][rect[i].ly];
	REP(i,nallx) REP(j,nally-1) cnt[i][j+1]+=cnt[i][j];
	REP(i,nallx-1) REP(j,nally) cnt[i+1][j]+=cnt[i][j];
	//printf("x:"); REP(i,nallx) printf(" %d",allx[i]); puts("");
	//printf("y:"); REP(i,nally) printf(" %d",ally[i]); puts("");
	//REP(i,nallx) { REP(j,nally) printf("%d ",cnt[i][j]); puts(""); }

	nid=0; sid=nid++; tid=nid++; REP(i,nallx-1) rid[i]=nid++; REP(j,nally-1) cid[j]=nid++;
	g.init(nid);
	REP(i,nallx-1) g.addedge(sid,rid[i],allx[i+1]-allx[i]);
	REP(i,nallx-1) REP(j,nally-1) if(cnt[i][j]>0) g.addedge(rid[i],cid[j],min(allx[i+1]-allx[i],ally[j+1]-ally[j]));
	REP(j,nally-1) g.addedge(cid[j],tid,ally[j+1]-ally[j]);
	return g.dinic(sid,tid);
}

void run() {
	scanf("%d%d",&sz,&nrect);
	REP(i,nrect) { scanf("%d%d%d%d",&rect[i].lx,&rect[i].ly,&rect[i].hx,&rect[i].hy); --rect[i].lx,--rect[i].ly; }
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}