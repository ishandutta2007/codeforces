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

const int MAXN=200000;

int n;
vector<pair<int,int>> adj[MAXN];

int par[MAXN],parval[MAXN];
int waysdown[MAXN]; // assuming first edge is from parent, number of reachable nodes
int waysup[MAXN]; // assuming first edge is to parent, number of reachable nodes

void dfsinit(int at) {
	REPSZ(i,adj[at]) { int to=adj[at][i].first,toval=adj[at][i].second; if(to==par[at]) continue; par[to]=at,parval[to]=toval; dfsinit(to); }
}

void dfsdown(int at) {
	waysdown[at]=parval[at]==-1?-1:1;
	REPSZ(i,adj[at]) {
		int to=adj[at][i].first,toval=adj[at][i].second; if(to==par[at]) continue;
		dfsdown(to);
		if(parval[at]==0||parval[at]==1&&toval==1) waysdown[at]+=waysdown[to];
	}
}
void dfsup(int at) {
	int sumzero=0,sumone=0;
	if(parval[at]==0) sumzero+=waysup[at]; else if(parval[at]==1) sumone+=waysup[at];
	REPSZ(i,adj[at]) {
		int to=adj[at][i].first,toval=adj[at][i].second; if(to==par[at]) continue;
		if(toval==0) sumzero+=waysdown[to]; else if(toval==1) sumone+=waysdown[to];
	}
	REPSZ(i,adj[at]) {
		int to=adj[at][i].first,toval=adj[at][i].second; if(to==par[at]) continue;
		if(toval==0) waysup[to]=1+sumzero+sumone-waysdown[to]; else if(toval==1) waysup[to]=1+sumone-waysdown[to]; else waysup[to]=-1;
		dfsup(to);
	}
}

ll solve() {
	par[0]=-1,parval[0]=-1; dfsinit(0);
	dfsdown(0);
	waysup[0]=-1; dfsup(0);
	//REP(i,n) printf("%d: par=%d parval=%d waysdown=%d waysup=%d\n",i+1,par[i]+1,parval[i],waysdown[i],waysup[i]);
	ll ret=0; REP(i,n) if(par[i]!=-1) ret+=waysup[i]+waysdown[i]; return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n-1) { int a,b,c; scanf("%d%d%d",&a,&b,&c); --a,--b; adj[a].PB(MP(b,c)); adj[b].PB(MP(a,c)); }
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}