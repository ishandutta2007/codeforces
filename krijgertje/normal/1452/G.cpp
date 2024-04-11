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

const int MAXN = 200000;

int n;
vector<int> adj[MAXN];
int nbob;
int bob[MAXN];
int ans[MAXN];

int dbob[MAXN];

void calcdbob() {
	queue<int> q;
	REP(i, n) dbob[i] = INT_MAX;
	REP(i, nbob) { int at = bob[i]; dbob[at] = 0; q.push(at); }
	while (!q.empty()) {
		int at = q.front(); q.pop();
		REPSZ(i, adj[at]) { int to = adj[at][i]; if (dbob[to] == INT_MAX) dbob[to] = dbob[at] + 1, q.push(to); }
	}
}

bool alive[MAXN];
int sz[MAXN];

void dfssz(int at, int par) {
	sz[at] = 1;
	REPSZ(i, adj[at]) {
		int to = adj[at][i];
		if (to == par || !alive[to]) continue;
		dfssz(to, at);
		sz[at] += sz[to];
	}
}
int dfscentroid(int at, int par, int rootsz) {
	REPSZ(i, adj[at]) {
		int to = adj[at][i];
		if (to == par || !alive[to]) continue;
		if (2 * sz[to] > rootsz) return dfscentroid(to, at, rootsz);
	}
	return at;
}
int centroid(int at) {
	dfssz(at,-1);
	return dfscentroid(at, -1, sz[at]);
}

int lst[MAXN], nlst;
int par[MAXN], dep[MAXN];
int mxdep;
int best[MAXN + 1];

void dfsinit(int at) {
	lst[nlst++] = at;
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	REPSZ(i, adj[at]) {
		int to = adj[at][i];
		if (to == par[at] || !alive[to]) continue;
		par[to] = at;
		dfsinit(to);
	}
}

void processcentroid(int cent,int lvl) {
	//printf("processing %d at lvl %d\n", cent, lvl);
	nlst = 0; par[cent] = -1; dfsinit(cent);
	mxdep = 0; REP(i, nlst) mxdep = max(mxdep, dep[lst[i]]);
	REPE(d, mxdep) best[d] = INT_MIN;
	REP(i, nlst) {
		int at = lst[i];
		int d = min(mxdep, dbob[at] - dep[at] - 1);
		if (d < 0) continue;
		//printf("\tto %d: mxdep=%d -> %d\n", at, d, dbob[at]);
		best[d] = max(best[d], dbob[at]);
	}
	for (int d = mxdep - 1; d >= 0; --d) best[d] = max(best[d], best[d + 1]);
	REP(i, nlst) {
		int at = lst[i];
		ans[at] = max(ans[at], best[dep[at]]);
	}
}

void decompose(int at,int lvl=0) {
	at = centroid(at);
	processcentroid(at, lvl);
	alive[at] = false;
	REPSZ(i, adj[at]) {
		int to = adj[at][i];
		if (!alive[to]) continue;
		decompose(to, lvl + 1);
	}
}

void solve() {
	calcdbob();
	REP(i, n) ans[i] = 0;
	REP(i, n) alive[i] = true;
	decompose(0);
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b), adj[b].PB(a); }
	scanf("%d", &nbob);
	REP(i, nbob) scanf("%d", &bob[i]), --bob[i];
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}