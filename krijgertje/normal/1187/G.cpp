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

typedef struct MCMF {
	int n,m;
	vector<int> ghead,gnxt,gto,gcap; vector<ll> gcost;
 
	vector<ll> d; vector<int> bck; vector<ll> pot; vector<int> flow;
 
	void init(int _n) { n=_n,m=0; ghead=vector<int>(n,-1); gnxt.clear(),gto.clear(),gcap.clear(),gcost.clear(); d=vector<ll>(n); bck=vector<int>(n); pot=vector<ll>(n,0); flow=vector<int>(n); }
	void addedge(int a,int b,int c,ll d) {
		gnxt.PB(ghead[a]); ghead[a]=m; gto.PB(b); gcap.PB(c); gcost.PB(+d); ++m;
		gnxt.PB(ghead[b]); ghead[b]=m; gto.PB(a); gcap.PB(0); gcost.PB(-d); ++m;
		//printf("adding edge %d-%d with cap %d and cost %lld\n",a,b,c,d);
	}
	pair<int,ll> solve(int s,int t) {
		//REP(i,n) { printf("%d:",i); for(int x=ghead[i];x!=-1;x=gnxt[x]) printf(" %d",gto[x]); puts(""); }
 
		REP(i,n) d[i]=LLONG_MAX,bck[i]=-1; d[s]=0,bck[s]=-2;
		while(true) {
			bool change=false;
			REP(at,n) if(d[at]!=LLONG_MAX) for(int x=ghead[at];x!=-1;x=gnxt[x]) if(gcap[x]>0) {
				int to=gto[x]; if(d[at]+gcost[x]>=d[to]) continue;
				d[to]=d[at]+gcost[x]; bck[to]=x^1; change=true;
			}
			if(!change) break;
		}
		if(d[t]==LLONG_MAX) return MP(0,0);
		REP(i,n) pot[i]=d[i];
 
 
		pair<int,ll> ret=MP(0,0LL);
		while(true) {
			REP(i,n) d[i]=LLONG_MAX,bck[i]=-1,flow[i]=0; d[s]=0,bck[s]=-2,flow[s]=INT_MAX;
			priority_queue<pair<ll,int> > q; q.push(MP(-d[s],s));
			while(!q.empty()) {
				ll cost=-q.top().first; int at=q.top().second; q.pop();
				if(cost>d[at]) continue;
				for(int x=ghead[at];x!=-1;x=gnxt[x]) if(gcap[x]>0) {
					int to=gto[x]; ll rcost=gcost[x]-pot[at]+pot[to]; if(d[at]+rcost>=d[to]) continue;
					d[to]=d[at]+rcost; bck[to]=x^1; flow[to]=min(flow[at],gcap[x]); q.push(MP(-d[to],to));
				}
			}
			if(d[t]==LLONG_MAX) break;
			assert(flow[t]>0);
			//printf("%d\n",d[t]-pot[t]);
			ret.first+=flow[t],ret.second+=(d[t]-pot[t])*flow[t];
			REP(i,n) if(d[i]!=LLONG_MAX) pot[i]-=d[i];
 
			for(int at=t;at!=s;at=gto[bck[at]]) {
				//printf("%d ",at);
				gcap[bck[at]]+=flow[t]; gcap[bck[at]^1]-=flow[t];
			}
			//printf("%d ",s);
			//puts("");
		}
		return ret;
	}
} MCMF;

const int MAXN=50;
const int MAXK=50;
const int MAXT=MAXN+MAXK;

int n,m,k,c,d;
int start[MAXN];
vector<int> adj[MAXN];


int nid,sid,tid;
int vid[MAXN][MAXT+1];
MCMF g;


ll solve() {
	nid=0; sid=nid++; tid=nid++; REP(i,n) REPE(j,n+k) vid[i][j]=nid++;
	g.init(nid);
	REP(i,k) g.addedge(sid,vid[start[i]][0],1,0);
	//REP(at,n) REPSZ(i,adj[at]) { int to=adj[at][i]; REP(j,n+k) g.addspecialedge(vid[at][j],vid[to][j+1]); }
	for(int z=k-1;z>=0;--z) REP(at,n) REPSZ(i,adj[at]) { int to=adj[at][i]; REP(j,n+k)  g.addedge(vid[at][j],vid[to][j+1],1,(2*z+1)*d); }
	REP(i,n) REP(j,n+k) g.addedge(vid[i][j],vid[i][j+1],k,0);
	REPE(j,n+k) g.addedge(vid[0][j],tid,k,c*j);
	pair<int,ll> res=g.solve(sid,tid);
	assert(res.first==k); return res.second;
}


void run() {
	scanf("%d%d%d%d%d",&n,&m,&k,&c,&d);
	REP(i,k) scanf("%d",&start[i]),--start[i];
	REP(i,m) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}