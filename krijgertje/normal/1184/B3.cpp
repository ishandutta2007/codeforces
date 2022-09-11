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
const int MAXSHIP=100000;
const int MAXBASE=100000;
const int MAXDEP=1000;

const int MAXGN=2+MAXSHIP;
const int MAXGM=MAXSHIP+MAXDEP;

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

struct Ship { int pos,attack,fuel,cost; };
struct Base { int pos,defense,gold; };
bool operator<(const Base &a,const Base &b) { if(a.gold!=b.gold) return a.gold>b.gold; return a.defense<b.defense; }

int n,m;
int d[MAXN][MAXN];
int nship,nbase,ndep;
Ship ship[MAXSHIP];
Base base[MAXBASE];
vector<int> dep[MAXSHIP];

vector<Base> opt[MAXN];
ll best[MAXSHIP];
vector<int> rdep[MAXSHIP];
bool alive[MAXSHIP];
int q[MAXSHIP],qhead,qtail;

int nid,sid,tid,shipid[MAXSHIP];


ll solve() {
	REP(i,nbase) opt[base[i].pos].PB(base[i]);
	REP(i,n) sort(opt[i].begin(),opt[i].end());
	REP(i,n) { int nsz=0; REPSZ(j,opt[i]) if(nsz==0||opt[i][j].defense<opt[i][nsz-1].defense) opt[i][nsz++]=opt[i][j]; opt[i].resize(nsz); }
	//REP(i,n) { printf("%d:",i+1); REPSZ(j,opt[i]) printf(" %d=%d",opt[i][j].defense,opt[i][j].gold); puts(""); }

	REP(i,nship) best[i]=LLONG_MIN;
	REP(i,nship) REP(j,n) if(d[ship[i].pos][j]<=ship[i].fuel&&SZ(opt[j])>0&&ship[i].attack>=opt[j].back().defense) {
		int l=-1,r=SZ(opt[j])-1;
		while(l+1<r) { int m=l+(r-l)/2; if(ship[i].attack>=opt[j][m].defense) r=m; else l=m; }
		best[i]=max(best[i],(ll)opt[j][r].gold-ship[i].cost);
	}
	//printf("best:"); REP(i,nship) printf(" %lld",best[i]); puts("");

	REP(i,nship) REPSZ(j,dep[i]) { int k=dep[i][j]; rdep[k].PB(i); }
	qhead=qtail=0; REP(i,nship) { alive[i]=best[i]!=LLONG_MIN; if(!alive[i]) q[qhead++]=i; }
	while(qtail<qhead) { int at=q[qtail++]; REPSZ(i,rdep[at]) { int to=rdep[at][i]; if(alive[to]) alive[to]=false,q[qhead++]=to; } }
	//printf("alive:"); REP(i,nship) printf(" %d",alive[i]?1:0); puts("");

	nid=0,sid=nid++,tid=nid++; REP(i,nship) if(!alive[i]) shipid[i]=-1; else shipid[i]=nid++;
	g.init(nid);
	ll sum=0;
	REP(i,nship) if(alive[i]) { if(best[i]>0) sum+=best[i],g.addedge(sid,shipid[i],best[i]); if(best[i]<0) g.addedge(shipid[i],tid,-best[i]); }
	REP(i,nship) REPSZ(j,dep[i]) { int k=dep[i][j]; if(!alive[i]) continue; assert(alive[k]); g.addedge(shipid[i],shipid[k],LLONG_MAX); }
	ll flow=g.dinic(sid,tid);
	return sum-flow;
}

void run() {
	scanf("%d%d",&n,&m);
	REP(i,n) REP(j,n) d[i][j]=i==j?0:INT_MAX;
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; d[a][b]=min(d[a][b],1); d[b][a]=min(d[b][a],1); }
	REP(k,n) REP(i,n) REP(j,n) if(d[i][k]!=INT_MAX&&d[k][j]!=INT_MAX) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	scanf("%d%d%d",&nship,&nbase,&ndep);
	REP(i,nship) scanf("%d%d%d%d",&ship[i].pos,&ship[i].attack,&ship[i].fuel,&ship[i].cost),--ship[i].pos;
	REP(i,nbase) scanf("%d%d%d",&base[i].pos,&base[i].defense,&base[i].gold),--base[i].pos;
	REP(i,ndep) { int a,b; scanf("%d%d",&a,&b); --a,--b; dep[a].PB(b); }
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}