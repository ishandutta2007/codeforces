#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 300000;
const int MAXQ = 300000;

struct P { int x, y; };
bool operator<(const P &a, const P &b) { if (a.x != b.x) return a.x < b.x; return a.y < b.y; }

struct Seg { int x, ly, hy, lidx; };

struct D { int cent, off, dst; D() {} D(int cent, int off, int dst) :cent(cent), off(off), dst(dst) {} };

int n;
P p[MAXN];
int nq;
int qkind[MAXQ], qx[MAXQ], qy[MAXQ];
map<pair<int, int>, int>  mp;

int nseg;
Seg seg[MAXN];
int p2seg[MAXN];
vector<int> adj[MAXN];
bool alive[MAXN];
int sz[MAXN];

void calcseg() {
	sort(p, p + n);
	mp.clear(); REP(i, n) mp[MP(p[i].x, p[i].y)] = i;
	nseg = 0;
	for (int l = 0, r = l; l<n; l = r) {
		while (r < n&&p[l].x == p[r].x && (l == r || p[r].y == p[r - 1].y + 1)) ++r;
		FOR(i, l, r) p2seg[i] = nseg; seg[nseg].x = p[l].x, seg[nseg].ly = p[l].y, seg[nseg].hy = p[r - 1].y, seg[nseg].lidx = l, ++nseg;
	}
	int at = 0;
	REP(i, nseg) {
		while (at < nseg&&seg[at].x < seg[i].x - 1) ++at;
		while (at < nseg&&seg[at].x == seg[i].x - 1 && seg[at].hy < seg[i].ly) ++at;
		while (at < n&&seg[at].x == seg[i].x - 1 && seg[at].ly <= seg[i].hy) { adj[i].PB(at); adj[at].PB(i); ++at; } if (at > 0) --at;
	}
	//REP(i, nseg) { printf("%d: (%d,%d..%d):", i, seg[i].x, seg[i].ly, seg[i].hy); REPSZ(j, adj[i]) printf(" %d", adj[i][j]); puts(""); }
}

void dfssz(int at,int par) {
	sz[at] = 1;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (!alive[to] || to == par) continue;
		dfssz(to, at); sz[at] += sz[to];
	}
}

int centroid(int rt) {
	dfssz(rt,-1);
	int at = rt;
	while (true) {
		bool found = false;
		REPSZ(i, adj[at]) {
			int to = adj[at][i]; if (!alive[to] || sz[to] > sz[at]) continue;
			if (2 * sz[to] > sz[rt]) { at = to; found = true; break; }
		}
		if (!found) return at;
	}
}

vector<D> d[MAXN];

void calcdst(int at, int par, int cent, int lvl) {
	//REP(i, lvl) printf("  "); printf("%d:", at); REPE(j, seg[at].hy - seg[at].ly) { int idx = seg[at].lidx + j; printf(" (%d,%d,%d)", d[idx][lvl].cent, d[idx][lvl].off, d[idx][lvl].dst); } puts("");
	int lidx = seg[at].lidx, ridx = lidx + seg[at].hy - seg[at].ly;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (!alive[to] || to == par) continue;
		REPE(j, seg[to].hy - seg[to].ly) {
			int idx = seg[to].lidx + j, y = seg[to].ly + j;
			int off, dst;
			if (y < seg[at].ly) off = d[lidx][lvl].off, dst = d[lidx][lvl].dst + 1 + seg[at].ly - y;
			else if (y > seg[at].hy) off = d[ridx][lvl].off, dst = d[ridx][lvl].dst + 1 + y - seg[at].hy;
			else off = d[lidx + y - seg[at].ly][lvl].off, dst = d[lidx + y - seg[at].ly][lvl].dst + 1;
			d[idx].PB(D(cent, off, dst));
		}
		calcdst(to, at, cent, lvl);
	}
}

void decompose(int lvl,int at) {
	at = centroid(at);
	//REP(i, lvl) printf("  "); printf("centroid=%d\n", at);

	REPE(j, seg[at].hy - seg[at].ly) d[seg[at].lidx + j].PB(D(at, j, 0));
	calcdst(at, -1, at, lvl);

	alive[at] = false;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (!alive[to]) continue;
		decompose(lvl + 1, to);
	}
}

struct ST {
	int n; vector<int> a, b; // a: val+pos, b = val-pos
	void init(int _n) { n = _n; a = vector<int>(4 * n, INT_MAX), b = vector<int>(4 * n, INT_MAX); }
	void amod(int x, int l, int r, int L, int R, int VAL) {
		if (L <= l&&r <= R) {
			a[x] = min(a[x], VAL);
		} else {
			int m = l + (r - l) / 2;
			if (L <= m) amod(2 * x + 1, l, m, L, R, VAL);
			if (m + 1 <= R) amod(2 * x + 2, m + 1, r, L, R, VAL);
		}
	}
	void bmod(int x, int l, int r, int L, int R, int VAL) {
		if (L <= l&&r <= R) {
			b[x] = min(b[x], VAL);
		} else {
			int m = l + (r - l) / 2;
			if (L <= m) bmod(2 * x + 1, l, m, L, R, VAL);
			if (m + 1 <= R) bmod(2 * x + 2, m + 1, r, L, R, VAL);
		}
	}
	int get(int x, int l, int r, int POS) {
		int ret = INT_MAX;
		if (a[x] != INT_MAX) ret = min(ret, a[x] - POS);
		if (b[x] != INT_MAX) ret = min(ret, b[x] + POS);
		if (l < r) {
			int m = l + (r - l) / 2;
			if (POS <= m) ret = min(ret, get(2 * x + 1, l, m, POS));
			if (m + 1 <= POS) ret = min(ret, get(2 * x + 2, m + 1, r, POS));
		}
		return ret;
	}

	void mod(int pos, int val) { amod(0, 0, n - 1, 0, pos, val + pos); bmod(0, 0, n - 1, pos, n - 1, val - pos); }
	int get(int pos) { return get(0, 0, n - 1, pos); }
};

ST st[MAXN];


void solve() {
	calcseg();
	
	REP(i, nseg) alive[i] = true;
	decompose(0, 0);
	REP(i, nseg) st[i].init(seg[i].hy - seg[i].ly + 1);
	
	REP(i, nq) {
		int idx = mp[MP(qx[i], qy[i])];
		//printf("q%d: idx=%d\n", i, idx);
		if (qkind[i] == 1) {
			REPSZ(lvl, d[idx]) {
				D cd = d[idx][lvl];
				st[cd.cent].mod(cd.off, cd.dst);
			}
		}
		if (qkind[i] == 2) {
			int ans = INT_MAX;
			REPSZ(lvl, d[idx]) {
				D cd = d[idx][lvl];
				int cur = st[cd.cent].get(cd.off); if (cur != INT_MAX) cur += cd.dst;
				ans = min(ans, cur);
			}
			printf("%d\n", ans == INT_MAX ? -1 : ans);
		}
	}
}

void run() {
	scanf("%d", &n); REP(i, n) scanf("%d%d", &p[i].x, &p[i].y);
	scanf("%d", &nq); REP(i, nq) scanf("%d%d%d", &qkind[i], &qx[i], &qy[i]);
	solve();
}

int main() {
	run();
	return 0;
}