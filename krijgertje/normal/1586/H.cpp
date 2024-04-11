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
const int MAXLG = 17;
const int MAXQ = 200000;
struct E { int a, b, cap, cost; };

int n, nq;
int val[MAXN];
E e[MAXN - 1];
int qsz[MAXQ], qstart[MAXQ];
pair<int, int> qans[MAXQ];

int compval[MAXN];
int compdist[MAXN];
int company[MAXN];

int par[MAXN], parcost[MAXN], dep[MAXN];
int up[MAXN][MAXLG + 1];
int upcost[MAXN][MAXLG + 1];

vector<int> adj[MAXN];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	up[at][0] = par[at] == -1 ? at : par[at];
	REP(k, MAXLG) up[at][k + 1] = up[up[at][k]][k];
	upcost[at][0] = parcost[at];
	REP(k, MAXLG) upcost[at][k + 1] = max(upcost[at][k], upcost[up[at][k]][k]);
	for (int eid : adj[at]) {
		int to = e[eid].a ^ e[eid].b ^ at;
		if (to == par[at]) continue;
		par[to] = at;
		parcost[to] = e[eid].cost;
		dfsinit(to);
	}
}

int lca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int k = MAXLG; k >= 0; --k) if (dep[a] - (1 << k) >= dep[b]) a = up[a][k];
	if (a == b) return a;
	for (int k = MAXLG; k >= 0; --k) if (up[a][k] != up[b][k]) a = up[a][k], b = up[b][k];
	return par[a];
}

int calcupcost(int at, int steps) {
	int ret = 0;
	REPE(k, MAXLG) if (steps & (1 << k)) {
		ret = max(ret, upcost[at][k]);
		at = up[at][k];
	}
	return ret;
}

int calcdist(int a, int b) {
	int c = lca(a, b);
	return max(calcupcost(a, dep[a] - dep[c]), calcupcost(b, dep[b] - dep[c]));
}

struct UF {
	int n; vector<int> par, sz;
	void init(int _n) { n = _n; par = sz = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1; }
	int find(int x) { if (par[x] == x) return x; return par[x] = find(par[x]); }
	void unite(int x, int y) { x = find(x); y = find(y); if (x == y) return; if (sz[x] < sz[y]) swap(x, y); par[y] = x, sz[x] += sz[y]; }
};
UF uf;

void solve() {
	REP(i, n) adj[i].clear();
	REP(i, n - 1) { int a = e[i].a, b = e[i].b; adj[a].PB(i); adj[b].PB(i); }
	par[0] = -1; parcost[0] = 0; dfsinit(0);
	sort(e, e + n - 1, [](const E& p, const E& q) { return p.cap > q.cap; });
	vector<int> qord(nq); REP(i, nq) qord[i] = i; sort(qord.begin(), qord.end(), [&](int i, int j) { return qsz[i] > qsz[j]; });
	int eidx = 0;
	uf.init(n);
	REP(i, n) compval[i] = val[i], compdist[i] = 0, company[i] = i;
	for (int qid : qord) {
		while (eidx < n - 1 && e[eidx].cap >= qsz[qid]) {
			int a = uf.find(e[eidx].a), b = uf.find(e[eidx].b);
			if (a != b) {
				int ncompval = max(compval[a], compval[b]);
				int nany = -1;
				int ndist = 0;
				if (compval[a] == ncompval) { ndist = max(ndist, compdist[a]); if (nany == -1) nany = company[a]; }
				if (compval[b] == ncompval) { ndist = max(ndist, compdist[b]); if (nany == -1) nany = company[b]; }
				if (compval[a] == ncompval && compval[b] == ncompval) ndist = max(ndist, calcdist(company[a], company[b]));
				uf.unite(a, b);
				int c = uf.find(a);
				compval[c] = ncompval, compdist[c] = ndist, company[c] = nany;
			}
			++eidx;
		}
		int a = qstart[qid], b = uf.find(a);
		qans[qid].first = compval[b];
		qans[qid].second = max(compdist[b], calcdist(a, company[b]));
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &val[i]);
	REP(i, n - 1) scanf("%d%d%d%d", &e[i].a, &e[i].b, &e[i].cap, &e[i].cost), --e[i].a, --e[i].b;
	REP(i, nq) scanf("%d%d", &qsz[i], &qstart[i]), --qstart[i];
	solve();
	REP(i, nq) printf("%d %d\n", qans[i].first, qans[i].second);
}

int main() {
	run();
	return 0;
}