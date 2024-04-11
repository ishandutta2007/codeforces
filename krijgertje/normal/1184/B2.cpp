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

const int MAXN=100;
const int MAXSHIP=1000;
const int MAXBASE=1000;

const int MAXGN=2+MAXSHIP+MAXBASE;
const int MAXGM=MAXSHIP+MAXBASE+MAXSHIP*MAXBASE;

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

struct Ship { int pos,attack,fuel; };
struct Base { int pos,defense; };

int n,m;
int d[MAXN][MAXN];
int nship,nbase,basecost,dummycost;
Ship ship[MAXSHIP];
Base base[MAXBASE];

int nid,sid,tid,shipid[MAXSHIP],baseid[MAXBASE];

ll solve() {
	nid=0; sid=nid++,tid=nid++; REP(i,nship) shipid[i]=nid++; REP(i,nbase) baseid[i]=nid++;
	g.init(nid);
	REP(i,nship) g.addedge(sid,shipid[i],1);
	REP(i,nship) REP(j,nbase) if(d[ship[i].pos][base[j].pos]<=ship[i].fuel&&ship[i].attack>=base[j].defense) g.addedge(shipid[i],baseid[j],1);
	REP(j,nbase) g.addedge(baseid[j],tid,1);
	int nattacked=g.dinic(sid,tid);
	return min((ll)nattacked*basecost,(ll)nship*dummycost);	
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) REP(j,n) d[i][j]=i==j?0:INT_MAX;
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; d[a][b]=min(d[a][b],1); d[b][a]=min(d[b][a],1); }
	REP(k,n) REP(i,n) REP(j,n) if(d[i][k]!=INT_MAX&&d[k][j]!=INT_MAX) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	scanf("%d%d%d%d",&nship,&nbase,&basecost,&dummycost);
	REP(i,nship) scanf("%d%d%d",&ship[i].pos,&ship[i].attack,&ship[i].fuel),--ship[i].pos;
	REP(i,nbase) scanf("%d%d",&base[i].pos,&base[i].defense),--base[i].pos;
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}