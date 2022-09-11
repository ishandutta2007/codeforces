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

const int MAXN=300000;
const int MAXQ=600000;
const int MAXLVL=18;


int n;
ll crosscost[MAXN];
ll treecost[MAXN-1][2];
vector<pair<int,int>> adj[MAXN];
int nq;
int qa[MAXQ],qb[MAXQ]; ll qans[MAXQ];

priority_queue<pair<ll,int>> pq;
ll reducedcost[MAXN];

int sz[MAXN];
bool alive[MAXN];

int cent[MAXN][MAXLVL+1];
ll dp[MAXN][MAXLVL+1][2][2]; // dp[i][lvl][a][b] = shortest path from node i to the centroid of level lvl, starting at side a and ending at side b

void dfsprocess(int at,int par,int parid,int lvl,int c) {
	cent[at][lvl]=c;
	if(parid!=-1) REP(a,2) REP(b,2) dp[at][lvl][a][b]=min(treecost[parid][a]+dp[par][lvl][a][b],reducedcost[at]+treecost[parid][1-a]+dp[par][lvl][1-a][b]);
	REPSZ(i,adj[at]) { int to=adj[at][i].first,id=adj[at][i].second; if(to==par||!alive[to]) continue; dfsprocess(to,at,id,lvl,c); }
}

void process(int c,int lvl) {
	//printf("process(%d,%d)\n",2*c+1,lvl);
	REP(a,2) REP(b,2) dp[c][lvl][a][b]=a==b?0:reducedcost[c];
	dfsprocess(c,-1,-1,lvl,c);
}

void dfssz(int at,int par) {
	sz[at]=1;
	REPSZ(i,adj[at]) { int to=adj[at][i].first; if(to==par||!alive[to]) continue; dfssz(to,at); sz[at]+=sz[to]; }
}
int dfscent(int at,int par,int totsz) {
	REPSZ(i,adj[at]) { int to=adj[at][i].first; if(to==par||!alive[to]) continue; if(2*sz[to]>=totsz) return dfscent(to,at,totsz); }
	return at;
}

int getcentroid(int root) {
	dfssz(root,-1);
	return dfscent(root,-1,sz[root]);
}

void decompose(int at,int lvl) {
	int c=getcentroid(at);
	process(c,lvl);
	alive[c]=false;
	REPSZ(i,adj[c]) { int to=adj[c][i].first; if(!alive[to]) continue; decompose(to,lvl+1); }
}


void solve() {
	pq=priority_queue<pair<ll,int>>();
	REP(i,n) reducedcost[i]=crosscost[i],pq.push(MP(-reducedcost[i],i));
	while(!pq.empty()) {
		ll cost=-pq.top().first; int at=pq.top().second; pq.pop();
		if(reducedcost[at]!=cost) continue;
		REPSZ(i,adj[at]) { int to=adj[at][i].first,id=adj[at][i].second; ll ncost=cost+treecost[id][0]+treecost[id][1]; if(ncost<reducedcost[to]) reducedcost[to]=ncost,pq.push(MP(-reducedcost[to],to)); }
	}
	//printf("reducedcost:"); REP(i,n) printf(" %lld",reducedcost[i]); puts("");

	REP(i,n) alive[i]=true; memset(cent,-1,sizeof(cent));
	decompose(0,0);
	//REP(i,n) { printf("%d:",2*i+1); REPE(lvl,MAXLVL) if(cent[i][lvl]!=-1) printf(" %d=%d",lvl,2*cent[i][lvl]+1); puts(""); }

	REP(i,nq) {
		int a=qa[i]/2,aside=qa[i]%2,b=qb[i]/2,bside=qb[i]%2;
		int lvl=MAXLVL; while(lvl>=0&&(cent[a][lvl]==-1||cent[b][lvl]==-1||cent[a][lvl]!=cent[b][lvl])) --lvl; assert(lvl>=0);
		qans[i]=min(dp[a][lvl][aside][0]+dp[b][lvl][bside][0],dp[a][lvl][aside][1]+dp[b][lvl][bside][1]);
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%lld",&crosscost[i]);
	REP(i,n-1) { int a,b; scanf("%d%d%lld%lld",&a,&b,&treecost[i][0],&treecost[i][1]); --a,--b; adj[a].PB(MP(b,i)); adj[b].PB(MP(a,i)); }
	scanf("%d",&nq);
	REP(i,nq) scanf("%d%d",&qa[i],&qb[i]),--qa[i],--qb[i];
	solve();
	REP(i,nq) printf("%lld\n",qans[i]);
}

int main() {
	run();
	return 0;
}