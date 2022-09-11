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

const int MAXN=100000;
const int MAXBIT=60;

int n;
ll a[MAXN];

vector<int> who[MAXBIT+1];
vector<pair<int,int>> edges;

vector<int> alive;
vector<int> adj[MAXN];

int dist[MAXN];
int q[MAXN],qhead,qtail;



int solve() {
	REPE(k,MAXBIT) who[k].clear();
	REP(i,n) REPE(k,MAXBIT) if(a[i]&(1LL<<k)) who[k].PB(i);
	REPE(k,MAXBIT) if(SZ(who[k])>=3) return 3;

	edges.clear(); REPE(k,MAXBIT) if(SZ(who[k])==2) { int a=who[k][0],b=who[k][1]; if(a>b) swap(a,b); edges.PB(MP(a,b)); }
	sort(edges.begin(),edges.end()); edges.erase(unique(edges.begin(),edges.end()),edges.end());

	int ret=INT_MAX;
	REP(i,n) adj[i].clear(),dist[i]=INT_MAX;
	REPSZ(fixed,edges) {
		int s=edges[fixed].first,t=edges[fixed].second;
		alive.clear();
		REPSZ(k,edges) if(k!=fixed) { int a=edges[k].first,b=edges[k].second; adj[a].PB(b); adj[b].PB(a); if(SZ(adj[a])==1) alive.PB(a); if(SZ(adj[b])==1) alive.PB(b); }
		if(SZ(adj[s])==0) alive.PB(s);
		qhead=qtail=0;
		dist[s]=0,q[qhead++]=s;
		while(qtail<qhead) {
			int at=q[qtail++];
			REPSZ(i,adj[at]) {
				int to=adj[at][i]; if(dist[to]!=INT_MAX) continue;
				dist[to]=dist[at]+1,q[qhead++]=to;
			}
		}
		if(dist[t]!=INT_MAX) ret=min(ret,dist[t]+1);
		REPSZ(i,alive) { int at=alive[i]; adj[at].clear(); dist[at]=INT_MAX; }
	}
	return ret==INT_MAX?-1:ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%lld",&a[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}