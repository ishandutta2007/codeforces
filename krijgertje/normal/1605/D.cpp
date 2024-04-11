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

const int MAXN = 200000;

int n;
vector<int> adj[MAXN];
int ans[MAXN];

int par[MAXN], dep[MAXN];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
	}
}

void solve() {
	par[0] = -1; dfsinit(0);
	int neven = 0, nodd = 0; REP(i, n) if (dep[i] % 2 == 0) ++neven; else ++nodd;
	int target = min(neven, nodd);
	vector<int> targetlst, otherlst;
	for (int bit = 0; (1 << bit) <= n; ++bit) {
		int lo = (1 << bit), hi = min(n, (2 << bit) - 1);
		int cnt = (hi - lo + 1);
		if (cnt == (1 << bit) && (target & (1 << bit)) != 0) {
			FORE(i, lo, hi) targetlst.PB(i);
		} else {
			FORE(i, lo, hi) otherlst.PB(i);
		}
	}
	//printf("n=%d target=%d neven=%d nodd=%d SZ(targetlst)=%d\n", n, target, neven, nodd, SZ(targetlst));
	assert(SZ(targetlst) == target);
	vector<int> evenlst = targetlst, oddlst = otherlst;
	if (nodd < neven) swap(evenlst, oddlst);
	//printf("SZ(evenlst)=%d SZ(oddlst)=%d\n", SZ(evenlst), SZ(oddlst));
	REP(i, n) if (dep[i] % 2 == 0) { assert(SZ(evenlst) > 0); ans[i] = evenlst.back(); evenlst.pop_back(); } else { assert(SZ(oddlst) > 0); ans[i] = oddlst.back(); oddlst.pop_back(); }
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
	REP(i, n) adj[i].clear();
}

void stress() {
	int mxn = 100;
	REP(rep, 100000) {
		n = rnd() % mxn + 1;
		vector<pair<int, int>> edges;
		vector<int> col(n); REP(i, n) col[i] = i;
		REP(i, n - 1) while (true) { int a = rnd() % n, b = rnd() % n; if (col[a] == col[b]) continue; int x = col[b]; REP(i, n) if (col[i] == x) col[i] = col[a]; edges.PB(MP(a, b)); break; }
		REP(i, n) adj[i].clear();
		for (auto e : edges) { int a = e.first, b = e.second; adj[a].PB(b); adj[b].PB(a); }
		solve();
		bool ok = true;
		for (auto e : edges) { int a = e.first, b = e.second; int u = ans[a], v = ans[b]; if ((u ^ v) <= min(u, v)) ok = false; }
		if (ok) { if (rep % 1000 == 999) printf("."); continue; }
		printf("err rep=%d\n", rep);
		printf("have:"); REP(i, n) printf(" %d", ans[i]); puts("");
		printf("%d\n", n); for (auto e : edges) { int a = e.first, b = e.second; printf("%d %d\n", a + 1, b + 1); }
		mxn = n - 1;
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}