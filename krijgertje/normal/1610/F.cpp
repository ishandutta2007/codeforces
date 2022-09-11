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

const int MAXN = 100000;
const int MAXM = 100000;
struct E { int a, b, w; };
struct Path { int a, b, w; vector<int> edges; };

int n, m;
E e[MAXM];
int ans[MAXM]; // 1 -> from a to b, 2 -> from b to a

bool done1[MAXM];
vector<int> adj1[MAXN][2];
int deg1[MAXN][2];
vector<Path> paths;
vector<bool> done2;
vector<int> adj2[MAXN];
int deg2[MAXN];

void makepath1(int at, int k) {
	Path p; p.a = at, p.w = k + 1;
	while (SZ(adj1[at][k]) > 0) {
		int eid = adj1[at][k].back();
		adj1[at][k].pop_back();
		if (done1[eid]) continue;
		int to = e[eid].a ^ e[eid].b ^ at;
		done1[eid] = true;
		--deg1[at][k], --deg1[to][k];
		p.edges.PB(eid);
		at = to;
	}
	assert(SZ(p.edges) != 0);
	p.b = at;
	int pid = SZ(paths);
	paths.PB(p), done2.PB(false);
	adj2[p.a].PB(pid); adj2[p.b].PB(pid); ++deg2[p.a], ++deg2[p.b];
	//printf("path %d %d %d:", p.a + 1, p.b + 1, p.w); for (int eid : p.edges) printf(" [%d %d %d]", e[eid].a + 1, e[eid].b + 1, e[eid].w); puts("");
}

void makepath2(int at) {
	while (SZ(adj2[at]) > 0) {
		int pid = adj2[at].back();
		adj2[at].pop_back();
		if (done2[pid]) continue;
		if (paths[pid].a != at) swap(paths[pid].a, paths[pid].b), reverse(paths[pid].edges.begin(), paths[pid].edges.end());
		int to = paths[pid].b;
		done2[pid] = true;
		--deg2[at], --deg2[to];
		at = to;
	}
}

int solve() {
	REP(i, n) REP(k,2) adj1[i][k].clear();
	REP(i, n) REP(k,2) deg1[i][k] = 0;
	REP(i, m) { int a = e[i].a, b = e[i].b, k = e[i].w - 1; adj1[a][k].PB(i); adj1[b][k].PB(i); ++deg1[a][k], ++deg1[b][k]; }
	REP(i, m) done1[i] = false;

	paths.clear(), done2.clear();
	REP(i, n) adj2[i].clear();
	REP(i, n) deg2[i] = 0;
	REP(i, n) REP(k, 2) if (deg1[i][k] % 2 != 0) makepath1(i, k);
	REP(i, n) REP(k, 2) while (deg1[i][k] > 0) makepath1(i, k);

	REP(i, n) if (deg2[i] % 2 != 0) makepath2(i);
	REP(i, n) while (deg2[i] > 0) makepath2(i);

	REP(i, m) ans[i] = 0;
	for (const auto &p : paths) {
		int at = p.a;
		for (int eid : p.edges) {
			ans[eid] = e[eid].a == at ? 1 : 2;
			at ^= e[eid].a ^ e[eid].b;
		}
		assert(at == p.b);
	}
	vector<int> bal(n, 0);
	REP(i, m) { int a = e[i].a, b = e[i].b, w = e[i].w; if (ans[i] == 2) swap(a, b); bal[a] -= w, bal[b] += w; }
	//printf("bal:"); REP(i, n) printf(" %d", bal[i]); puts("");
	REP(i, n) if (bal[i] % 2 != 0) assert(abs(bal[i]) == 1);
	int ret = 0; REP(i, n) if (abs(bal[i]) == 1) ++ret; return ret;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].w), --e[i].a, --e[i].b;
	printf("%d\n", solve());
	REP(i, m) printf("%d", ans[i]);
}

void stress() {
	int mxn = 100;
	REP(rep, 100000) {
		n = rnd() % mxn; m = rnd() % (min((ll)MAXM, (ll)n * n) + 1);
		//n = rnd() % mxn; m = rnd() % (min((ll)7 * n / 4, (ll)n * n) + 1);
		REP(i, m) { e[i].a = rnd() % n; e[i].b = rnd() % n; e[i].w = rnd() % 2 + 1; }
		//printf("%d %d\n", n, m); REP(i, m) printf("%d %d %d\n", e[i].a + 1, e[i].b + 1, e[i].w);
		solve();
		if (rep % 1000 == 999) printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}