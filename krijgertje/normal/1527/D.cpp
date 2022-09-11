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
ll ans[MAXN + 1];

int par[MAXN], sz[MAXN];
void dfsinit(int at) {
	sz[at] = 1;
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
		sz[at] += sz[to];
	}
}


void solve() {
	par[0] = -1;
	dfsinit(0);

	deque<int> path;
	vector<bool> onpath(n, false);
	path.push_back(0), onpath[0] = true;
	FOR(i, 1, n) if (!onpath[i]) {
		vector<int> cur;
		int at = i;
		while (!onpath[at]) {
			cur.PB(at);
			at = par[at];
		}
		if (at == path.back()) {
			reverse(cur.begin(), cur.end());
			for (int x : cur) path.push_back(x), onpath[x] = true;
		} else if (at == path.front()) {
			reverse(cur.begin(), cur.end());
			for (int x : cur) path.push_front(x), onpath[x] = true;
		} else {
			break;
		}
	}
	vector<int> pathidx(n, -1);
	REPSZ(i, path) pathidx[path[i]] = i;
	int l = pathidx[0], r = pathidx[0];
	REPE(i, n) ans[i] = 0;
	FOR(i, 1, n) {
		if (pathidx[i] == -1) break;
		l = min(l, pathidx[i]);
		r = max(r, pathidx[i]);
		int lsz = sz[path[l]] - (par[path[l + 1]] == path[l] ? sz[path[l + 1]] : 0);
		int rsz = sz[path[r]] - (par[path[r - 1]] == path[r] ? sz[path[r - 1]] : 0);
		ans[i + 1] += (ll)lsz * rsz;
	}
	ans[1] += (ll)n * (n - 1) / 2;
	for (int to : adj[0]) ans[1] -= (ll)sz[to] * (sz[to] - 1) / 2;
	ans[0] += (ll)n * (n - 1) / 2;
	ll sum = 0;
	for (int i = n; i >= 0; --i) {
		ans[i] -= sum;
		sum += ans[i];
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); adj[a].PB(b); adj[b].PB(a); }
	solve();
	REPE(i, n) { if (i != 0) printf(" "); printf("%lld", ans[i]); } puts("");
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}