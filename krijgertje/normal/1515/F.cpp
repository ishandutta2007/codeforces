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

const int MAXN = 300000;

int n, m, cost;
int starthave[MAXN];
vector<pair<int, int>> adj[MAXN];
vector<int> ans;

int par[MAXN], parid[MAXN];

void dfsinit(int at) {
	for (pair<int, int> e : adj[at]) {
		int to = e.first, id = e.second;
		if (to == par[at]) continue;
		if (par[to] != -2) continue;
		par[to] = at, parid[to] = id;
		dfsinit(to);
	}
}

struct UF {
	int n; vector<int> par, sz;
	void init(int _n) { n = _n; par = sz = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1; }
	int find(int x) { if (par[x] == x) return x; return par[x] = find(par[x]); }
	int unite(int x, int y) { x = find(x), y = find(y); if (x == y) return x; if (sz[x] < sz[y]) swap(x, y); par[y] = x, sz[x] += sz[y]; return x; }
};

set<pair<ll, int>> opt[MAXN];
queue<int> q;
bool inq[MAXN];
UF uf;
int root[MAXN];
int optid[MAXN];
ll curhave[MAXN];

int merge(int a, int b) {
	if (SZ(opt[a]) < SZ(opt[b])) swap(a, b);
	for (auto p : opt[b]) opt[a].insert(p);
	return a;
}


bool solve() {
	REP(i, n) par[i] = -2;
	par[0] = parid[0] = -1;
	dfsinit(0);
	REP(i, n) opt[i].clear();
	q = queue<int>();
	REP(i, n) inq[i] = false;
	uf.init(n);
	REP(i, n) root[i] = i;
	REP(i, n) optid[i] = i;
	REP(i, n) curhave[i] = starthave[i];
	REP(i, n) if (par[i] != -1) {
		int to = root[uf.find(par[i])];
		opt[optid[to]].insert(MP(curhave[i], i));
	}
	auto check = [&](int at) {
		if (SZ(opt[optid[at]]) == 0) return;
		pair<ll, int> best = *opt[optid[at]].rbegin();
		if (curhave[at] + best.first < cost) return;
		if (inq[at]) return;
		q.push(at), inq[at] = true;
	};
	REP(at, n) check(at);
	while (!q.empty()) {
		int at = q.front(); q.pop();
		inq[at] = false;
		if (at != root[uf.find(at)]) continue;
		if (SZ(opt[optid[at]]) == 0) continue;
		pair<ll, int> best = *opt[optid[at]].rbegin();
		if (curhave[at] + best.first < cost) continue;
		int to = best.second;
		//printf("processing %d->%d (%d+%d)\n", at + 1, to + 1, curhave[at], curhave[to]);
		assert(opt[optid[at]].erase(best) == 1);
		assert(curhave[to] == best.first);
		ans.PB(parid[to]);
		root[uf.unite(at, to)] = at;
		if (par[at] != -1) {
			int p = root[uf.find(par[at])];
			assert(opt[optid[p]].erase(MP(curhave[at], at)) == 1);
		}
		curhave[at] += curhave[to];
		curhave[at] -= cost;
		if (par[at] != -1) {
			int p = root[uf.find(par[at])];
			opt[optid[p]].insert(MP(curhave[at], at));
		}
		optid[at] = merge(optid[at], optid[to]);
		check(at);
		if (par[at] != -1) {
			int p = root[uf.find(par[at])];
			check(p);
		}
	}
	return SZ(ans) == n - 1;
}

void run() {
	scanf("%d%d%d", &n, &m, &cost);
	REP(i, n) scanf("%d", &starthave[i]);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(MP(b, i)); adj[b].PB(MP(a, i)); }
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REPSZ(i, ans) printf("%d\n", ans[i] + 1);
}

int main() {
	run();
	return 0;
}