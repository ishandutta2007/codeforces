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

struct UF {
	int n; vector<int> par, sz;
	void init(int _n) { n = _n; par = sz = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1; }
	int find(int x) { if (par[x] == x) return x; return par[x] = find(par[x]); }
	bool unite(int x, int y) { x = find(x), y = find(y); if (x == y) return false; if (sz[x] < sz[y]) swap(x, y); par[y] = x, sz[x] += sz[y]; return true; }
};

const int MAXBUILDING = 300000;
const int MAXQ = 300000;
const int MAXNODE = 2 * MAXBUILDING - 1;
const int MAXBIT = 19;
const int MAXS = 4 * MAXBUILDING;
struct E { int a, b, c; };
struct S { int lazy; int mnon, mntot, mxon, mxtot; };

int nbuilding, nq;
E e[MAXBUILDING - 1];
int qkind[MAXQ], ql[MAXQ], qr[MAXQ], qidx[MAXQ];
int qans[MAXQ];

int nnode;
int par[MAXNODE];
int val[MAXNODE];
int up[MAXNODE][MAXBIT + 1];
vector<int> ch[MAXNODE];
int nord;
int lord[MAXNODE], rord[MAXNODE];
int pos[MAXNODE];
int dep[MAXNODE];

S s[MAXS];

void sapply(int x, int val) {
	s[x].lazy = val;
	if (val == 0) s[x].mnon = INT_MAX, s[x].mxon = INT_MIN;
	if (val == 1) s[x].mnon = s[x].mntot, s[x].mxon = s[x].mxtot;
}
void spush(int x) {
	if (s[x].lazy != -1) sapply(2 * x + 1, s[x].lazy), sapply(2 * x + 2, s[x].lazy), s[x].lazy = -1;
}
void spull(int x) {
	s[x].mnon = min(s[2 * x + 1].mnon, s[2 * x + 2].mnon);
	s[x].mntot = min(s[2 * x + 1].mntot, s[2 * x + 2].mntot);
	s[x].mxon = max(s[2 * x + 1].mxon, s[2 * x + 2].mxon);
	s[x].mxtot = max(s[2 * x + 1].mxtot, s[2 * x + 2].mxtot);
}
void sinit(int x, int l, int r) {
	s[x].lazy = -1;
	if (l == r) {
		s[x].mnon = INT_MAX;
		s[x].mxon = INT_MIN;
		s[x].mntot = s[x].mxtot = lord[l];
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void smod(int x, int l, int r, int L, int R, int VAL) {
	if (L <= l && r <= R) {
		sapply(x, VAL);
	} else {
		int m = l + (r - l) / 2;
		spush(x);
		if (L <= m) smod(2 * x + 1, l, m, L, R, VAL);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, VAL);
		spull(x);
	}
}

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	lord[at] = nord, pos[nord] = at, ++nord;
	for (int to : ch[at]) dfsinit(to);
	rord[at] = nord - 1;
}

int lca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int k = MAXBIT; k >= 0; --k) if (dep[a] - (1 << k) >= dep[b]) a = up[a][k];
	if (a == b) return a;
	for (int k = MAXBIT; k >= 0; --k) if (up[a][k] != up[b][k]) a = up[a][k], b = up[b][k];
	return par[a];
}

void solve() {
	nnode = nbuilding;
	REP(i, nnode) par[i] = -1, val[i] = -1;
	sort(e, e + nbuilding - 1, [&](const E &p, const E &q) { return p.c < q.c; });
	UF uf;
	uf.init(nbuilding);
	vector<int> root(nbuilding);
	REP(i, nbuilding) root[i] = i;
	REP(i, nbuilding - 1) {
		int a = e[i].a, b = e[i].b;
		a = uf.find(a);
		b = uf.find(b);
		assert(uf.unite(a, b));
		int c = uf.find(a);
		par[root[a]] = nnode;
		par[root[b]] = nnode;
		root[c] = nnode;
		par[nnode] = -1;
		val[nnode] = e[i].c;
		++nnode;
	}
	REP(i, nnode) if (par[i] != -1) ch[par[i]].PB(i);
	REP(i, nnode) up[i][0] = par[i] == -1 ? i : par[i];
	REP(k, MAXBIT) REP(i, nnode) up[i][k + 1] = up[up[i][k]][k];
	int groot = root[uf.find(0)];
	nord = 0;
	dfsinit(groot);
	//REP(i, nnode) printf("%d: par=%d val=%d\n", i, par[i], val[i]);

	sinit(0, 0, nbuilding - 1);
	REP(i, nq) {
		if (qkind[i] == 1) {
			int l = ql[i], r = qr[i];
			smod(0, 0, nbuilding - 1, l, r, 1);
		}
		if (qkind[i] == 2) {
			int l = ql[i], r = qr[i];
			smod(0, 0, nbuilding - 1, l, r, 0);
		}
		if (qkind[i] == 3) {
			int start = qidx[i];
			if (s[0].mnon == INT_MAX || s[0].mxon == INT_MIN) {
				qans[i] = -1;
			} else {
				int l = pos[min(s[0].mnon, lord[start])];
				int r = pos[max(s[0].mxon, lord[start])];
				qans[i] = val[lca(l, r)];
			}
		}
	}


}

void run() {
	scanf("%d%d", &nbuilding, &nq);
	REP(i, nbuilding - 1) scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].c), --e[i].a, --e[i].b;
	REP(i, nq) { scanf("%d", &qkind[i]); if (qkind[i] == 1 || qkind[i] == 2) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i]; if (qkind[i] == 3) scanf("%d", &qidx[i]), --qidx[i]; }
	solve();
	REP(i, nq) if (qkind[i] == 3) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}