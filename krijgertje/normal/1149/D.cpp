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

const int MAXN=70;
const int MAXLARGE=MAXN/4;

int n,m,lcost,hcost;
vector<pair<int,int>> adj[MAXN];
int ans[MAXN];

int comp[MAXN],ncomp;
int compsize[MAXN];
int q[MAXN],qhead,qtail;
int largeidx[MAXN],nlarge;

priority_queue<pair<int,pair<int,int>>> pq;
int dist[MAXN][1<<MAXLARGE];

void solve() {
	ncomp=0; REP(i,n) comp[i]=-1;
	REP(i,n) if(comp[i]==-1) {
		qhead=qtail=0; q[qhead++]=i; comp[i]=ncomp++;
		while(qtail<qhead) { int at=q[qtail++]; REPSZ(j,adj[at]) if(adj[at][j].second==lcost) { int to=adj[at][j].first; if(comp[to]==-1) comp[to]=comp[at],q[qhead++]=to; } }
	}
	REP(i,ncomp) compsize[i]=0; REP(i,n) ++compsize[comp[i]];
	nlarge=0; REP(i,ncomp) if(compsize[i]>=4) largeidx[i]=nlarge++; else largeidx[i]=-1;

	pq=priority_queue<pair<int,pair<int,int>>>();
	REP(i,n) REP(mask,1<<nlarge) dist[i][mask]=INT_MAX;
	int smask=largeidx[comp[0]]==-1?0:(1<<largeidx[comp[0]]);
	dist[0][smask]=0; pq.push(MP(-dist[0][smask],MP(0,smask)));
	while(!pq.empty()) {
		int cost=-pq.top().first,at=pq.top().second.first,mask=pq.top().second.second; pq.pop();
		if(cost!=dist[at][mask]) continue;
		REPSZ(i,adj[at]) {
			int to=adj[at][i].first,ecost=adj[at][i].second,ncost=cost+ecost,nmask=mask;
			if(ecost==hcost&&comp[to]==comp[at]) continue;
			if(ecost==hcost&&largeidx[comp[to]]!=-1&&(mask&(1<<largeidx[comp[to]]))!=0) continue;
			if(largeidx[comp[to]]!=-1) nmask|=1<<largeidx[comp[to]];
			//printf("at (%d,%x) to (%d,%x): %d vs %d\n",at+1,mask,to+1,nmask,ncost,dist[to][nmask]);
			if(ncost<dist[to][nmask]) dist[to][nmask]=ncost,pq.push(MP(-ncost,MP(to,nmask)));
		}
	}
	REP(i,n) ans[i]=INT_MAX; REP(i,n) REP(mask,1<<nlarge) ans[i]=min(ans[i],dist[i][mask]);
}



void run() {
	scanf("%d%d%d%d",&n,&m,&lcost,&hcost);
	REP(i,m) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; assert(c==lcost||c==hcost); adj[a].PB(MP(b,c)); adj[b].PB(MP(a,c)); }
	solve();
	REP(i,n) { if(i!=0) printf(" "); printf("%d",ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}