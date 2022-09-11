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

int par[MAXN],sz[MAXN];
ll dpdn[MAXN];
ll dpup[MAXN];

void dfsinit(int at) {
	sz[at]=1;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par[at]) continue;
		par[to]=at; dfsinit(to); sz[at]+=sz[to];
	}
}
void dfsdn(int at) {
	dpdn[at]=0;
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par[at]) continue;
		dfsdn(to); dpdn[at]+=sz[to]+dpdn[to];
	}
}
void dfsup(int at) {
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par[at]) continue;
		dpup[to]=(n-sz[to])+dpup[at]+(dpdn[at]-dpdn[to]-sz[to]);
	}
	REPSZ(i,adj[at]) {
		int to=adj[at][i]; if(to==par[at]) continue;
		dfsup(to);
	}
}



ll solve() {
	par[0]=-1; dfsinit(0);
	dfsdn(0);
	dpup[0]=0; dfsup(0);
	//REP(i,n) printf("%d: par=%d dn=%lld up=%lld\n",i+1,par[i]+1,dpdn[i],dpup[i]);
	ll ret=0; REP(i,n) ret=max(ret,n+dpup[i]+dpdn[i]); return ret;
}

void run() {
	scanf("%d",&n);
	REP(i,n-1) { int a,b; scanf("%d%d",&a,&b); --a,--b; adj[a].PB(b); adj[b].PB(a); }
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}