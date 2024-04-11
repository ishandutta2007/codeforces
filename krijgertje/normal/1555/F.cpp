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
const int MAXQ = 500000;
const int MAXLG = 18;

int n, nq;
int qa[MAXQ], qb[MAXQ], qc[MAXQ];
bool qans[MAXQ];

struct UF {
	int n; vector<int> par, sz, w;
	void init(int _n) { n = _n; par = sz = w = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1, w[i] = 0; }
	int getroot(int x) { if (par[x] == x) return x; if (par[par[x]] == par[x]) return par[x]; int ret = getroot(par[x]); w[x] ^= w[par[x]]; par[x] = ret; /*printf("%d->(%d,%d)\n", x + 1, par[x] + 1, w[x]);*/ return ret; }
	int getw(int x) { getroot(x); return w[x]; }
	bool unite(int x, int y, int z) {
		int xx = getroot(x), yy = getroot(y);
		//printf("x=%d y=%d xx=%d yy=%d wx=%d wy=%d z=%d\n", x + 1, y + 1, xx + 1, yy + 1, getw(x), getw(y), z);
		if (xx == yy) return getw(x) ^ getw(y) ^ z == 1;
		if (sz[xx] < sz[yy]) swap(xx, yy), swap(x, y);
		par[yy] = xx, sz[xx] += sz[yy], w[yy] = w[x] ^ w[y] ^ z; // , printf("w[%d]=%d\n", yy + 1, w[yy]);
		return true;
	}
};
UF uf;

int qstate[MAXQ]; // 0=dead, 1=tree, 2=optional
vector<int> adj[MAXN];
int par[MAXN], dep[MAXN];
bool paredgeoncyc[MAXN];

int up[MAXN][MAXLG + 1];
bool anyedgeoncyc[MAXN][MAXLG + 1];
vector<int> used[MAXN][MAXLG];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	up[at][0] = par[at] == -1 ? at : par[at]; REP(k, MAXLG) up[at][k + 1] = up[up[at][k]][k];
	REPE(k, MAXLG) anyedgeoncyc[at][k] = false;
	REP(k, MAXLG) used[at][k] = vector<int>();
	REP(k, MAXLG) used[at][k].PB(at), used[up[at][k]][k].PB(at);
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
	}
}

int getlca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int k = MAXLG; k >= 0; --k) if (dep[a] - (1 << k) >= dep[b]) a = up[a][k];
	if (a == b) return a;
	for (int k = MAXLG; k >= 0; --k) if (up[a][k] != up[b][k]) a = up[a][k], b = up[b][k];
	return par[a];
}

void solve() {
	uf.init(n);
	REP(i, nq) {
		int a = qa[i], b = qb[i], c = qc[i];
		bool samecomp = uf.getroot(a) == uf.getroot(b);
		qstate[i] = uf.unite(a, b, c) ? samecomp ? 2 : 1 : 0;
		qans[i] = false;
	}
	//printf("qstate: "); REP(i, nq) printf("%d", qstate[i]); puts("");
	REP(i, n) adj[i].clear();
	REP(i, nq) if (qstate[i] == 1)  {
		int a = qa[i], b = qb[i];
		adj[a].PB(b), adj[b].PB(a);
		qans[i] = true;
	}
	REP(i, n) par[i] = -2;
	REP(i, n) if (par[i] == -2) { par[i] = -1; dfsinit(i); }
	REP(i, n) paredgeoncyc[i] = false;
	REP(i, nq) if (qstate[i] == 2) {
		qans[i] = true;
		int a = qa[i], b = qb[i];
		if (dep[a] < dep[b]) continue;
		for (int k = MAXLG; k >= 0; --k) if (dep[a] - (1 << k) >= dep[b]) {

		}
	}
	//printf("par:"); REP(i, n) printf(" %d", par[i] + 1); puts("");
	REP(i, nq) if (qstate[i] == 2) {
		//printf("i=%d\n", i);
		qans[i] = false;
		bool ok = true;
		int a = qa[i], b = qb[i], c = getlca(a, b);
		for (int k = MAXLG; k >= 0; --k) if (dep[a] - (1 << k) >= dep[c]) { /*printf("%d,%d\n", a + 1, k);*/ if (anyedgeoncyc[a][k]) ok = false; a = up[a][k]; }
		for (int k = MAXLG; k >= 0; --k) if (dep[b] - (1 << k) >= dep[c]) { /*printf("%d,%d\n", b + 1, k);*/ if (anyedgeoncyc[b][k]) ok = false; b = up[b][k]; }
		if (!ok) continue;
		//printf("ok\n");
		qans[i] = true;
		a = qa[i], b = qb[i];
		queue<pair<int, int>> q;
		while (dep[a] > dep[c]) { anyedgeoncyc[a][0] = true; q.push(MP(a, 0)); a = par[a]; }
		while (dep[b] > dep[c]) { anyedgeoncyc[b][0] = true; q.push(MP(b, 0)); b = par[b]; }
		while (!q.empty()) {
			int at = q.front().first, k = q.front().second; q.pop();
			//if (k <= 2) printf("processing (%d,%d)\n", at + 1, k);
			if (k == MAXLG) continue;
			for (int to : used[at][k]) {
				if (anyedgeoncyc[to][k + 1]) continue;
				anyedgeoncyc[to][k + 1] = true, q.push(MP(to, k + 1));
			}
		}
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, nq) scanf("%d%d%d", &qa[i], &qb[i], &qc[i]), --qa[i], --qb[i];
	solve();
	REP(i, nq) printf("%s\n", qans[i] ? "YES" : "NO");
}

bool qansstupid[MAXQ];

void solvestupid() {
	vector<vector<pair<int, int>>> adj(n);
	REP(i, nq) {
		int a = qa[i], b = qb[i], c = qc[i];
		//printf("n=%d a=%d b=%d c=%d\n", n, a, b, c);
		adj[a].PB(MP(b, c)); adj[b].PB(MP(a, c));
		bool ok = true;
		REP(j, n) {
			vector<bool> onstack(n, false);
			auto dfs = [&](auto self, int at, int par, int sum) -> bool {
				onstack[at] = true;
				for (auto z : adj[at]) {
					int to = z.first;
					if (to == par) continue;
					if (to == j && (sum ^ z.second) == 0) return true;
					if (!onstack[to] && self(self, to, at, sum ^ z.second)) return true;
				}
				onstack[at] = false;
				return false;
			};
			if (dfs(dfs, j, -1, 0)) { ok = false; break; }
		}
		qansstupid[i] = ok;
		if (!ok) adj[a].pop_back(), adj[b].pop_back();
	}
}

void stress() {
	int mxn = 10, mxq = 40;
	//int mxn = 5, mxq = 10;
	REP(rep, 10000) {
		n = rnd() % (mxn - 1) + 2, nq = rnd() % min(n * (n - 1) / 2, mxq) + 1;
		set<pair<int, int>> seen;
		REP(i, nq) while (true) { qa[i] = rnd() % n, qb[i] = rnd() % n; if (qa[i] == qb[i] || seen.count(MP(qa[i], qb[i]))) continue; seen.insert(MP(qa[i], qb[i])), seen.insert(MP(qb[i], qa[i])); qc[i] = rnd() % 2; break; }
		solve();
		solvestupid();
		bool ok = true;
		REP(i, nq) if (qans[i] != qansstupid[i]) ok = false;
		if (ok) { printf("."); continue; }
		printf("err\n");
		printf("have: "); REP(i, nq) printf("%c", qans[i] ? 'v' : '.'); puts("");
		printf("want: "); REP(i, nq) printf("%c", qansstupid[i] ? 'v' : '.'); puts("");
		printf("%d %d\n", n, nq);
		REP(i, nq) printf("%d %d %d\n", qa[i] + 1, qb[i] + 1, qc[i]);
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}