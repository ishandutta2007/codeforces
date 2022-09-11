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

const int MOD = 998244353;
const int PRIMROOT = 3;
int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret*x%MOD; if ((n >>= 1) == 0) return ret; x = (ll)x*x%MOD; } }

struct NTT {
	void _init(int n, int &nlog, int &g, vector<int> &w) {
		assert((MOD - 1) % n == 0);
		g = pw(PRIMROOT, (MOD - 1) / n); nlog = 0; while ((1 << nlog) < n) ++nlog; if ((1 << nlog) != n) nlog = -1;
		w = vector<int>(n); w[0] = 1; FOR(i, 1, n) w[i] = (ll)w[i - 1] * g%MOD;
	}
	int fftn, fftnlog; int fftg; vector<int> fftw;
	void initfft(int n) { fftn = n, _init(fftn, fftnlog, fftg, fftw); assert(fftnlog != -1); }
	void fft(int *a, int n, bool inv) {
		if (n != fftn) initfft(n);
		for (int i = 1, j = n >> 1, k, l = j; i < n; j ^= k, ++i) { if (i < j) swap(a[i], a[j]); for (k = l; k&j; j ^= k, k >>= 1); }
		int *l, *r, *w;
		if (inv) reverse(fftw.begin() + 1, fftw.end());
		for (int hlen = 1, step = n >> 1; hlen < n; hlen <<= 1, step >>= 1) {
			for (int i = 0; i < n; i += (hlen << 1)) {
				l = a + i, r = l + hlen, w = fftw.data();
				REP(off, hlen) {
					int v = (ll)(*r)*(*w) % MOD;
					*r = (*l) - v; if (*r<0) *r += MOD;
					*l = (*l) + v; if (*l >= MOD) *l -= MOD;
					++l, ++r, w += step;
				}
			}
		}
		if (inv) reverse(fftw.begin() + 1, fftw.end());
		if (inv) { int mlt = pw(n, MOD - 2); REP(i, n) a[i] = (ll)a[i] * mlt%MOD; }
	}
	void mult(const int *a, int na, const int *b, int nb, int *c, int nc) {
		int sz = 1; while (sz<na + nb - 1) sz *= 2;
		vector<int> A(sz, 0), B(sz, 0);
		REP(i, na) A[i] = a[i]; REP(i, nb) B[i] = b[i];
		fft(A.data(), sz, false); fft(B.data(), sz, false); REP(i, sz) A[i] = (ll)A[i] * B[i] % MOD; fft(A.data(), sz, true);
		REP(i, nc) c[i] = i<sz ? A[i] : 0;
	}
};

NTT ntt;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
vector<int> add(const vector<int> &a, const vector<int> &b) { vector<int> c(max(SZ(a), SZ(b)), 0); REPSZ(i, c) { if (i < SZ(a)) inc(c[i], a[i]); if (i < SZ(b)) inc(c[i], b[i]); } return c; }
vector<int> mult(const vector<int> &a, const vector<int> &b) { vector<int> c(SZ(a) + SZ(b) - 1, 0); ntt.mult(a.data(), SZ(a), b.data(), SZ(b), c.data(), SZ(c)); return c; }

struct LHeapNode { ll val; int c[2], dst; LHeapNode() { c[0] = c[1] = -1, dst = 0; } };
struct LHeap {
	int n;
	vector<LHeapNode> nodes;
	void init(int _n) { n = _n; nodes = vector<LHeapNode>(n); }
	void update(int x) { if (nodes[x].c[0] == -1 || nodes[x].c[1] != -1 && nodes[nodes[x].c[0]].dst < nodes[nodes[x].c[1]].dst) swap(nodes[x].c[0], nodes[x].c[1]); nodes[x].dst = nodes[x].c[1] == -1 ? 0 : nodes[nodes[x].c[1]].dst + 1; }
	int merge(int x, int y) { if (x == -1) return y; else if (y == -1) return x; if (nodes[x].val > nodes[y].val) swap(x, y); nodes[x].c[1] = merge(nodes[x].c[1], y); update(x); return x; }
	int removemin(int x) { return merge(nodes[x].c[0], nodes[x].c[1]); }
};
struct HuTucker {
	int n;
	vector<int> x;
	vector<int> d;
	void init(vector<int> _x) { n = SZ(_x), x = _x; }

	LHeap globheap; int globroot; vector<int> globmp;
	LHeap locheap; int atloc; vector<int> locmp; vector<bool> localive; vector<int> locroot, loclft, locrgt;
	vector<pair<int, int>> par;
	void calc() {
		globheap.init(n - 1); globroot = -1; globmp = vector<int>(n - 1, -1);
		locheap.init(3 * n - 1); atloc = 2 * n; locmp = vector<int>(3 * n - 1, -1); localive = vector<bool>(3 * n - 1, false); locroot = vector<int>(2 * n, -1); loclft = locrgt = vector<int>(3 * n - 1, -1);
		par = vector<pair<int, int>>();
		REP(i, n) locheap.nodes[2 * i + 0].val = locheap.nodes[2 * i + 1].val = (ll)x[i] * n + i;
		REP(i, n - 1) { int l = 2 * i + 1, r = 2 * (i + 1) + 0, x = locheap.merge(l, r); localive[l] = localive[r] = true; updateloc(x, l, r, i); }
		while (globroot != -1) {
			int g = globroot, x = globmp[g]; ll sum = globheap.nodes[g].val;
			globroot = globheap.removemin(globroot);
			if (x == -1) continue;
			int xl, xr; clearloc(x, xl, xr);
			int a = x; x = locheap.removemin(x);
			int b = x; x = locheap.removemin(x);
			process(a, x, xl, xr);
			process(b, x, xl, xr);
			int y = atloc++; localive[y] = true; locheap.nodes[y].val = sum; x = locheap.merge(x, y);
			updateloc(x, xl, xr, g);
			par.PB(MP(a < 2 * n ? a / 2 : a - n, y - n)); par.PB(MP(b < 2 * n ? b / 2 : b - n, y - n));
		}
		vector<int> dep(2 * n - 1, 0); for (int i = SZ(par) - 1; i >= 0; --i) dep[par[i].first] = dep[par[i].second] + 1;
		d = vector<int>(n); REP(i, n) d[i] = dep[i];
	}
	void updateloc(int x, int l, int r, int g) {
		while (x != -1 && !localive[x]) x = locheap.removemin(x);
		if (x == -1) return;
		REP(i, 2) while (true) { int y = locheap.nodes[x].c[i]; if (y == -1 || localive[y]) break; locheap.nodes[x].c[i] = locheap.removemin(y); } locheap.update(x);
		loclft[x] = l, locrgt[x] = r; if (l != -1) locroot[l] = x; if (r != -1) locroot[r] = x;
		int y = locheap.nodes[x].c[0], z = locheap.nodes[x].c[1]; if (y == -1 && z == -1) return;
		ll v1 = locheap.nodes[x].val, v2 = locheap.nodes[y != -1 && (z == -1 || locheap.nodes[y].val < locheap.nodes[z].val) ? y : z].val, sum = (v1 / n + v2 / n)*n + min(v1%n, v2%n);
		globmp[g] = x, locmp[x] = g; globheap.nodes[g].val = sum; globheap.nodes[g].c[0] = globheap.nodes[g].c[1] = -1; globheap.nodes[g].dst = 0; globroot = globheap.merge(globroot, g);
	}
	void clearloc(int x, int &l, int &r) {
		int g = locmp[x]; if (g != -1) globmp[g] = -1; locmp[x] = -1;
		l = loclft[x], r = locrgt[x]; loclft[x] = locrgt[x] = -1; if (l != -1) locroot[l] = -1; if (r != -1) locroot[r] = -1;
	}
	void process(int a, int &x, int &xl, int &xr) {
		localive[a] = false;
		if (a >= 2 * n) return;
		assert(a == xl || a == xr);
		if (a == 1) { xl = -1; return; } if (a == 2 * n - 2) { xr = -1; return; }
		int b = a ^ 1, y = locroot[b]; assert(y != -1 && locmp[y] != -1);
		localive[b] = false;
		int yl, yr; clearloc(y, yl, yr);
		x = locheap.merge(x, y);
		if (a == xl) { assert(yr == b); xl = yl; }
		if (a == xr) { assert(yl == b); xr = yr; }
	}
};
HuTucker ht;

const int MAXN = 100000;


int n; ll want;
vector<int> adj[MAXN];

int par[MAXN];
int sz[MAXN];
int dep[MAXN];
int heavy[MAXN];

vector<int> ways[MAXN]; // ways[x][y] = # ways to select a subtree rooted at x with exactly y nodes (only calculated for roots of heavy paths) [optionally use root]
vector<int> waysnonheavy[MAXN]; // waysnonheavy[x][y] = # ways to select a subtree rooted at x with exactly y nodes in which the heavy child is not used [always use root]

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1, sz[at] = 1, heavy[at] = -1;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		par[to] = at; dfsinit(to); sz[at] += sz[to]; if (heavy[at] == -1 || sz[to] > sz[heavy[at]]) heavy[at] = to;
	}
}

int path[MAXN], npath;
pair<vector<int>, vector<int>> rec(int l, int r) { // (sum of nonempty prefixes, product of all)
	if (l == r) {
		int at = path[l];
		return MP(waysnonheavy[at], waysnonheavy[at]);
	} else {
		int lsum = 0, cl = l - 1, rsum = 0, cr = r + 1; while (cr - cl > 1) if (lsum <= rsum) lsum += SZ(waysnonheavy[path[++cl]]); else rsum += SZ(waysnonheavy[path[--cr]]);
		auto res1 = rec(l, cl);
		auto res2 = rec(cr, r);
		return MP(add(res1.first, mult(res1.second, res2.first)), mult(res1.second, res2.second));
	}
}

int lst[MAXN], nlst;
vector<int> tmp[2 * MAXN]; int ntmp;
priority_queue<pair<int, int>> pq;
void calcways(int at);
void calcwaysnonheavy(int at) {
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at] || to == heavy[at]) continue;
		calcways(to);
	}
	nlst = 0;  REPSZ(i, adj[at]) { int to = adj[at][i]; if (to == par[at] || to == heavy[at]) continue; lst[nlst++] = to; }
	ntmp = nlst; pq = priority_queue<pair<int, int>>(); REP(i, nlst) tmp[i] = ways[lst[i]], pq.push(MP(-SZ(tmp[i]), i));
	while (SZ(pq) >= 2) {
		int a = pq.top().second; pq.pop(); int b = pq.top().second; pq.pop(); int c = ntmp++;
		tmp[ntmp] = mult(tmp[a], tmp[b]), pq.push(MP(-SZ(tmp[c]), c));
	}
	waysnonheavy[at] = SZ(pq) == 1 ? tmp[pq.top().second] : vector<int>(1, 1);
	waysnonheavy[at].insert(waysnonheavy[at].begin(), 0);
	REP(i, ntmp) tmp[i].clear();
}

void calcways(int at) {
	for (int x = at; x != -1; x = heavy[x]) calcwaysnonheavy(x);
	npath = 0; for (int x = at; x != -1; x = heavy[x]) path[npath++] = x;
	//ways[at] = rec(0, npath - 1).first; inc(ways[at][0], 1);

	vector<int> x(npath); REP(i, npath) x[i] = SZ(waysnonheavy[i]);
	ht.init(x); ht.calc(); vector<int> d = ht.d;
	vector<pair<int, pair<vector<int>, vector<int>>>> stck;
	REP(i,npath) {
		auto cur = MP(d[i], MP(waysnonheavy[path[i]], waysnonheavy[path[i]]));
		while (SZ(stck) > 0 && stck.back().first == cur.first) { cur = MP(cur.first - 1, MP(add(stck.back().second.first, mult(stck.back().second.second, cur.second.first)), mult(stck.back().second.second, cur.second.second))); stck.pop_back(); }
		stck.PB(cur);
	}
	assert(SZ(stck) == 1 && stck[0].first == 0); ways[at] = stck[0].second.first; inc(ways[at][0], 1);
}

int inv[MAXN + 1];

void run() {
	scanf("%d%lld", &n, &want);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }

	par[0] = -1; dfsinit(0);

	calcways(0);
	//printf("ways:"); REPSZ(i, ways[0]) printf(" %d", ways[0][i]); puts("");

	int ret = 0, mlt = 1;
	//FORSZ(i, 1, ways[0]) ret += ways[0][i] * C(want + i - 1, i - 1);
	inv[1] = 1; FORSZ(i, 2, ways[0]) inv[i] = (ll)(MOD - MOD / i)*inv[MOD%i] % MOD;
	FORSZ(i, 1, ways[0]) {
		//printf("%d: mlt=%d\n", i, mlt);
		ret = (ret + (ll)ways[0][i] * mlt) % MOD;
		mlt = (ll)mlt*(want%MOD + i) % MOD * inv[i] % MOD;
	}
	printf("%d\n", ret);
}

int main() {
	run();
	return 0;
}