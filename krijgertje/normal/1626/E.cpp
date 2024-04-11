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
#include <chrono>
#include <random>
#include <functional>
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
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXN = 300000;

int n;
int col[MAXN];
vector<int> adj[MAXN];
int ans[MAXN];

int par[MAXN];
int cntsubtree[MAXN];
bool marked[MAXN];
int closest[MAXN];
int subtree[MAXN];

int tospecial[MAXN];

void dfsinit(int at) {
	cntsubtree[at] = col[at];
	closest[at] = col[at] == 1 ? at : closest[par[at]];
	subtree[at] = par[at] == -1 || par[par[at]] == -1 ? at : subtree[par[at]];
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
		cntsubtree[at] += cntsubtree[to];
	}
}

void dfsspecial(int at) {
	tospecial[at] = cntsubtree[at] >= 1 ? at : tospecial[par[at]];
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		dfsspecial(to);
	}
}


void solve() {
	int root = -1;
	REP(i, n) if (col[i] == 1) { root = i; break; }
	assert(root != -1);

	par[root] = -1;
	dfsinit(root);
	REP(i, n) marked[i] = col[i] == 1;
	REP(i, n) if (col[i] == 1 && par[i] != -1) marked[par[i]] = true;
	for (int to : adj[root]) if (cntsubtree[to] >= 1) marked[to] = true;
	//printf("cntsubtree:"); REP(i, n) printf(" %d", cntsubtree[i]); puts("");

	bool all = false;
	REP(at, n) if (at != root && col[at] == 1 && cntsubtree[at] >= 2) all = true;
	for (int to : adj[root]) if (cntsubtree[to] >= 1 && cntsubtree[to] != cntsubtree[root] - 1) all = true;
	REP(at, n) for (int to : adj[at]) if (col[at] == 0 && at != root && marked[at] && to != par[at] && cntsubtree[to] >= 1 && cntsubtree[to] != cntsubtree[at]) all = true;
	for (int at : adj[root]) if (marked[at] && col[at] == 0) for (int to : adj[at]) if (to != root && cntsubtree[to] >= 1 && cntsubtree[to] != cntsubtree[at]) all = true;
	if (all) { REP(i, n) ans[i] = 1; return; }

	//REP(at, n) ans[at] = col[at] == 1 || marked[at] || closest[at] != root || !marked[subtree[at]] ? 1 : 0;
	dfsspecial(root);
	REP(at, n) ans[at] = marked[tospecial[at]];
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &col[i]);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}