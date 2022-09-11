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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=200000;
const int MAXWANTIDX=400;
struct E { int to,cost; E() {} E(int to,int cost):to(to),cost(cost) {} };
bool operator<(const E &a,const E &b) { return a.cost<b.cost; }

int n,m,wantidx;
vector<E> adj[MAXN];

pair<int,int> path[MAXWANTIDX]; ll pathlen[MAXWANTIDX]; int npath; int pathpos[MAXWANTIDX][2]; int nodepos[MAXN];
map<pair<int,int>,int> mp;
priority_queue<pair<ll,int>> pq;

void addnodenext(int at) { if(nodepos[at]<SZ(adj[at])) pq.push(MP(-(ll)adj[at][nodepos[at]].cost,at)); }
void addpathnext(int idx,int side) { int a=path[idx].first,b=path[idx].second; if(side==1) swap(a,b); if(pathpos[idx][side]<SZ(adj[b])) pq.push(MP(-(pathlen[idx]+adj[b][pathpos[idx][side]].cost),n+2*idx+side)); }

ll solve() {
	npath=0; mp.clear(); pq=priority_queue<pair<ll,int>>();
	REP(at,n) { nodepos[at]=0; sort(adj[at].begin(),adj[at].end()); addnodenext(at); }
	while(npath<wantidx&&!pq.empty()) {
		ll len=-pq.top().first; int id=pq.top().second; pq.pop();
		if(id<n) {
			int at=id; pair<int,int> cur=MP(id,adj[at][nodepos[at]++].to); addnodenext(at);
			if(cur.first>cur.second) swap(cur.first,cur.second); if(cur.first==cur.second||mp.count(cur)!=0) continue;
			int toidx=npath++; path[toidx]=cur; pathlen[toidx]=len; mp[cur]=toidx; REP(side,2) { pathpos[toidx][side]=0; addpathnext(toidx,side); }
		} else {
			int idx=(id-n)/2,side=(id-n)%2; int a=path[idx].first,b=path[idx].second; if(side==1) swap(a,b); pair<int,int> cur=MP(a,adj[b][pathpos[idx][side]++].to); addpathnext(idx,side);
			if(cur.first>cur.second) swap(cur.first,cur.second); if(cur.first==cur.second||mp.count(cur)!=0) continue;
			int toidx=npath++; path[toidx]=cur; pathlen[toidx]=len; mp[cur]=toidx; REP(side,2) { pathpos[toidx][side]=0; addpathnext(toidx,side); }
		}
	}
	//REP(i,npath) printf("%d to %d = %lld\n",path[i].first+1,path[i].second+1,pathlen[i]);
	assert(npath>=wantidx); return pathlen[wantidx-1];
}

void run() {
	scanf("%d%d%d",&n,&m,&wantidx);
	REP(i,m) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; adj[a].PB(E(b,c)); adj[b].PB(E(a,c)); }
	printf("%lld\n",solve());

}

int main() {
	run();
	return 0;
}