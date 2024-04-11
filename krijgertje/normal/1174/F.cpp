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
vector<int> adj[MAXN];

int par[MAXN];
int dep[MAXN];
int sz[MAXN];
int heavy[MAXN];

void dfsinit(int at) {
	dep[at]=par[at]==-1?0:dep[par[at]]+1;
	sz[at]=1;
	heavy[at]=-1;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par[at]) continue;
		par[to]=at; dfsinit(to);
		sz[at]+=sz[to]; if(heavy[at]==-1||sz[to]>sz[heavy[at]]) heavy[at]=to;
	}
}

int askdist(int u) {
	printf("d %d\n",u+1); fflush(stdout); int ret; scanf("%d",&ret); if(ret==-1) exit(0); return ret;
}
int asknext(int u) {
	printf("s %d\n",u+1); fflush(stdout); int ret; scanf("%d",&ret); if(ret==-1) exit(0); return ret-1;
}

int solve() {
	par[0]=-1; dfsinit(0);
	int root=0;
	int depx=askdist(root);
	int at=root;
	while(dep[at]!=depx) {
		int to=asknext(at);
		if(to!=heavy[at]) { at=to; continue; }
		int leaf=at; while(heavy[leaf]!=-1) leaf=heavy[leaf];
		int dist=askdist(leaf);
		assert((depx+dep[leaf]-dist)%2==0);
		int depnxt=(depx+dep[leaf]-dist)/2;
		assert(depnxt>dep[at]&&depnxt<=dep[leaf]);
		while(dep[at]!=depnxt) at=heavy[at];
	}
	return at;
}

void run() {
	scanf("%d",&n);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	int ans=solve();
	printf("! %d\n",ans+1); fflush(stdout);
}

int main() {
	run();
	return 0;
}