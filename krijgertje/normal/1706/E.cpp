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
const int MAXLGN = 16; // 1<<MAXLGN <= MAXN-1
const int MAXM = 200000;
const int MAXQ = 200000;
const int MAXNODE = 2 * MAXN - 1;
const int MAXLGNODE = 17; // 1<<MAXLGNODE <= MAXNODE

int n, m, nq;
int e[MAXM][2];
int ql[MAXQ], qr[MAXQ];
int qans[MAXQ];

int nnode;
int par[MAXNODE];
int val[MAXNODE];
int dep[MAXNODE];
int up[MAXNODE][MAXLGNODE + 1];
vector<vector<int>> ch;
int top[MAXN];

struct UF {
	int n; vector<int> par, sz;
	void init(int _n) { n = _n; par = sz = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1; }
	int find(int x) { if (par[x] == x) return x; return par[x] = find(par[x]); }
	bool unite(int x, int y) { x = find(x), y = find(y); if (x == y) return false; if (sz[x] < sz[y]) swap(x, y); par[y] = x, sz[x] += sz[y]; return true; }
};
UF uf;

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	up[at][0] = par[at] == -1 ? at : par[at]; REP(k, MAXLGNODE) up[at][k + 1] = up[up[at][k]][k];
	for (int to : ch[at]) dfsinit(to);
}

int lca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int k = MAXLGNODE; k >= 0; --k) if (dep[a] - (1 << k) >= dep[b]) a = up[a][k];
	if (a == b) return a;
	for (int k = MAXLGNODE; k >= 0; --k) if (up[a][k] != up[b][k]) a = up[a][k], b = up[b][k];
	return par[a];
}

int adjlca[MAXN - 1];
int jumplca[MAXN - 1][MAXLGN + 1];

void solve() {
	nnode = n;
	REP(i, nnode) par[i] = -1, val[i] = 0;
	REP(i, n) top[i] = i;
	uf.init(n);
	REP(i, m) {
		int a = e[i][0], b = e[i][1];
		int u = top[uf.find(a)], v = top[uf.find(b)];
		//printf("%d and %d: %d + %d\n", a, b, u, v);
		assert(par[u] == -1 && par[v] == -1);
		if (uf.unite(a, b)) {
			int c = uf.find(a);
			int w = nnode++;
			//printf("%d and %d: %d + %d -> %d [%d]\n", a, b, u, v, w, c);
			par[u] = par[v] = w, par[w] = -1, val[w] = i + 1;
			top[c] = w;
		}
	}
	assert(nnode == 2 * n - 1);
	ch = vector<vector<int>>(nnode);
	REP(i, nnode) if (par[i] != -1) ch[par[i]].PB(i);
	int root = -1; REP(i, nnode) if (par[i] == -1) { assert(root == -1); root = i; } assert(root != -1);
	dfsinit(root);
	REP(i, n - 1) adjlca[i] = lca(i, i + 1);
	REP(i, n - 1) jumplca[i][0] = adjlca[i];
	auto topmost = [&](int a, int b) { return dep[a] <= dep[b] ? a : b; };
	REP(k, MAXLGN) for (int i = 0; i + (2 << k) < n; ++i) jumplca[i][k + 1] = topmost(jumplca[i][k], jumplca[i + (1 << k)][k]);
	REP(i, nq) {
		int l = ql[i], r = qr[i];
		if (l == r) { qans[i] = 0; continue; }
		int sz = r - l;
		int k = 0; while ((2 << k) <= sz) ++k;
		int lca = topmost(jumplca[l][k], jumplca[r - (1 << k)][k]);
		qans[i] = val[lca];
	}
}

void run() {
	scanf("%d%d%d", &n, &m, &nq);
	REP(i, m) REP(j, 2) scanf("%d", &e[i][j]), --e[i][j];
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	REP(i, nq) { if (i != 0) printf(" "); printf("%d", qans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}