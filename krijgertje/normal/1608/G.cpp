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

namespace SuffixArray {
	void build(int *s, int *sa, int *mem, int n, int alph) { // length of mem >= 2n, alph <= n
		if (n == 0) return;
		if (n == alph) { REP(i, n) sa[s[i]] = i; return; }
		int n0 = (n + 2) / 3, n1 = (n + 1) / 3, n2 = n / 3, n12 = n1 + n2, na = n12, nb = na - (n % 3 != 1 ? 1 : 0), nc = nb - (n % 3 != 2 ? 1 : 0);
		int *s12 = mem, *sa0 = mem + n12, *cnt = mem + n;
		int *a = sa, *b = s12, *c = sa, *sa12 = sa + n0, *pos = cnt;

		{ // build a of positions mod3 = 1 and mod3 = 2 (length = 2/3n)
			REP(i, alph) cnt[i] = 0;
			for (int i = 1; i + 2 < n; i += 3) ++cnt[s[i + 2]];
			for (int i = 2; i + 2 < n; i += 3) ++cnt[s[i + 2]];
			for (int i = alph - 1; i >= 1; --i) cnt[i] = cnt[i - 1]; cnt[0] = 0; FOR(i, 1, alph) cnt[i] += cnt[i - 1];
			if (n % 3 != 0 && n >= 4) c[cnt[s[n - 1]]++] = n - 3;
			for (int i = 1; i + 2 < n - 1; i += 3) c[cnt[s[i + 2]]++] = i;
			for (int i = 2; i + 2 < n - 1; i += 3) c[cnt[s[i + 2]]++] = i;
			REP(i, alph) cnt[i] = 0;
			for (int i = 1; i + 1 < n; i += 3) ++cnt[s[i + 1]];
			for (int i = 2; i + 1 < n; i += 3) ++cnt[s[i + 1]];
			for (int i = alph - 1; i >= 1; --i) cnt[i] = cnt[i - 1]; cnt[0] = 0; FOR(i, 1, alph) cnt[i] += cnt[i - 1];
			if (n % 3 != 2) b[cnt[s[n - 1]]++] = n - 2;
			REP(i, nc) b[cnt[s[c[i] + 1]]++] = c[i];
			REP(i, alph) cnt[i] = 0;
			for (int i = 1; i < n; i += 3) ++cnt[s[i]];
			for (int i = 2; i < n; i += 3) ++cnt[s[i]];
			for (int i = alph - 1; i >= 1; --i) cnt[i] = cnt[i - 1]; cnt[0] = 0; FOR(i, 1, alph) cnt[i] += cnt[i - 1];
			if (n % 3 != 1) a[cnt[s[n - 1]]++] = n - 1;
			REP(i, nb) a[cnt[s[b[i]]]++] = b[i];
		}

		{ // build s12 with a, and calculate sa12 recursively
			REP(i, n) pos[i] = -1;
			REP(i, n1) pos[3 * i + 1] = i;
			REP(i, n2) pos[3 * i + 2] = n1 + i;
			int nalph = 0, last = -1;
			auto same = [&](int i, int j) { if (i == j) return true; if (i + 3 >= n || j + 3 >= n) return false; return s[i] == s[j] && s[i + 1] == s[j + 1] && s[i + 2] == s[j + 2]; };
			REP(i, n12) if (last == -1 || !same(a[i], last)) { last = a[i]; s12[pos[a[i]]] = nalph++; } else { s12[pos[a[i]]] = s12[pos[last]]; }
			assert(2 * n - n12 >= 2 * n12);
			build(s12, sa12, mem + n12, n12, nalph);
		}

		{ // build sa0 with stable sort
			REP(i, alph) cnt[i] = 0;
			for (int i = 0; i < n; i += 3) ++cnt[s[i]];
			for (int i = alph - 1; i >= 1; --i) cnt[i] = cnt[i - 1]; cnt[0] = 0; FOR(i, 1, alph) cnt[i] += cnt[i - 1];
			if (n % 3 == 1) sa0[cnt[s[n - 1]]++] = n - 1;
			REP(i, n12) if (sa12[i] < n1) sa0[cnt[s[3 * sa12[i]]]++] = 3 * sa12[i];
		}
		REP(i, n12) if (sa12[i] < n1) sa12[i] = 3 * sa12[i] + 1; else sa12[i] = 3 * (sa12[i] - n1) + 2;
		{ // build sa with merge of sa0 and sa12
			REP(i, n) pos[i] = -1;
			REP(i, n12) pos[sa12[i]] = i;
			auto less = [&](int i, int j) {
				while (true) {
					if (j >= n) return false; else if (i >= n) return true;
					if (pos[i] != -1 && pos[j] != -1) return pos[i] < pos[j];
					if (s[i] != s[j]) return s[i] < s[j];
					++i, ++j;
				}
			};
			int i = 0, j = 0;
			while (i < n0 || j < n12) if (j == n12 || i != n0 && less(sa0[i], sa12[j])) sa[i + j] = sa0[i], ++i; else sa[i + j] = sa12[j], ++j;
		}
	}

	vector<int> build(const vector<int> &a, int alph) {
		int n = SZ(a);
		vector<int> in(n);
		vector<int> mem(2 * n);
		vector<int> out(n);
		vector<bool> have(alph, false);
		REP(i, n) have[a[i]] = true;
		vector<int> mp(alph, -1);
		int nalph = 0;
		REP(i, alph) if (have[i]) mp[i] = nalph++;
		REP(i, n) in[i] = mp[a[i]];
		build(in.data(), out.data(), mem.data(), n, nalph);
		return out;
	}

	vector<int> build(const string &s) {
		int n = SZ(s);
		vector<int> a(n);
		REP(i, n) a[i] = (int)s[i];
		return build(a, 256);
	}

	template<class T> vector<int> build(const vector<T> &a) {
		int n = SZ(a);
		vector<int> ord(n);
		REP(i, n) ord[i] = i;
		sort(ord.begin(), ord.end(), [&](int i, int j) { return a[i] < a[j]; });
		vector<int> in(n, -1);
		vector<int> mem(2 * n);
		vector<int> out(n);
		int alph = 0;
		REP(i, n) in[ord[i]] = i != 0 && a[ord[i - 1]] == a[ord[i]] ? alph - 1 : alph++;
		build(in.data(), out.data(), mem.data(), n, alph);
		return out;
	}
};

struct LCP {
	int n;
	vector<int> lcp;
	vector<int> lg;
	vector<vector<int>> rmq;

	void kasai(const string &s, const vector<int> &sa) {
		n = SZ(s), lcp = vector<int>(n - 1);
		int k = 0; vector<int> pos(n); REP(i, n) pos[sa[i]] = i;
		REP(i, n) {
			if (pos[i] == n - 1) { k = 0; continue; }
			int j = sa[pos[i] + 1];
			while (i + k < n && j + k < n && s[i + k] == s[j + k]) ++k;
			lcp[pos[i]] = k;
			if (k > 0) --k;
		}
	}

	void build(const string &s, const vector<int> &sa) {
		kasai(s, sa);
		lg = vector<int>(n + 1); REPE(i, n) if (i == 0) lg[i] = -1; else if (i == 1) lg[i] = 0; else { lg[i] = lg[i - 1]; while ((2 << lg[i]) <= i) ++lg[i]; }
		rmq = vector<vector<int>>(n, vector<int>(lg[n] + 1, -1));
		REP(i, n - 1) rmq[i][0] = lcp[i];
		REP(k, lg[n]) REP(i, n - 1) if (i + (2 << k) <= n - 1) rmq[i][k + 1] = min(rmq[i][k], rmq[i + (1 << k)][k]);
	}

	int query(int a, int b) {
		if (a == b) return INT_MAX;
		if (a > b) swap(a, b);
		int k = lg[b - a];
		return min(rmq[a][k], rmq[b - (1 << k)][k]);
	}
};

struct BIT {
	int n; vector<int> val;
	void init(int _n) { n = _n; val = vector<int>(n, 0); }
	void add(int idx, int delta) { while (idx < n) { val[idx] += delta; idx |= idx + 1; } }
	int get(int idx) { int ret = 0; while (idx >= 0) { ret += val[idx]; idx = (idx & (idx + 1)) - 1; } return ret; }
	int get(int lidx, int ridx) { return get(ridx) - get(lidx - 1); }
};

const int MAXN = 100000;
const int MAXP = 100000;
const int MAXQ = 100000;
const int MAXLG = 16;

int n, np, nq;
vector<pair<int, char>> adj[MAXN];
string p[MAXP];
int qa[MAXQ], qb[MAXQ], ql[MAXQ], qr[MAXQ];
int qans[MAXQ];

int par[MAXN], sz[MAXN], heavy[MAXN], dep[MAXN]; char parc[MAXN]; int up[MAXN][MAXLG + 1];
int hroot[MAXN];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	sz[at] = 1;
	heavy[at] = -1;
	up[at][0] = par[at] == -1 ? at : par[at]; REP(k, MAXLG) up[at][k + 1] = up[up[at][k]][k];
	REPSZ(i, adj[at]) {
		int to = adj[at][i].first; char c = adj[at][i].second;
		if (to == par[at]) continue;
		par[to] = at;
		parc[to] = c;
		dfsinit(to);
		sz[at] += sz[to];
		if (heavy[at] == -1 || sz[to] > sz[heavy[at]]) heavy[at] = to;
	}
}

int lca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int k = MAXLG; k >= 0; --k) if (dep[a] - (1 << k) >= dep[b]) a = up[a][k];
	if (a == b) return a;
	for (int k = MAXLG; k >= 0; --k) if (up[a][k] != up[b][k]) a = up[a][k], b = up[b][k];
	return par[a];
}

int calcup(int a, int steps) {
	for (int k = MAXLG; k >= 0; --k) if (steps & (1 << k)) a = up[a][k];
	return a;
}

vector<pair<int, int>> decompose(int a, int b) {
	int c = lca(a, b);
	vector<pair<int, int>> up;
	while (a != c) {
		if (hroot[a] != hroot[c]) {
			up.PB(MP(a, hroot[a]));
			a = par[hroot[a]];
		} else {
			up.PB(MP(a, calcup(a, dep[a] - dep[c] - 1)));
			a = c;
		}
	}
	vector<pair<int, int>> dn;
	while (b != c) {
		if (hroot[b] != hroot[c]) {
			dn.PB(MP(b, hroot[b]));
			b = par[hroot[b]];
		} else {
			dn.PB(MP(b, calcup(b, dep[b] - dep[c] - 1)));
			b = c;
		}
	}
	reverse(dn.begin(), dn.end());
	REPSZ(i, dn) swap(dn[i].first, dn[i].second);
	vector<pair<int, int>> ret;
	ret.insert(ret.end(), up.begin(), up.end());
	ret.insert(ret.end(), dn.begin(), dn.end());
	return ret;
}

int pidx[MAXP];
int upidx[MAXN], dnidx[MAXN];

struct E { int id, l, r, by; E() {} E(int id, int l, int r, int by) :id(id), l(l), r(r), by(by) {} };

void solve() {
	par[0] = -1; parc[0] = '-'; dfsinit(0);
	REP(i, n) if (par[i] == -1 || heavy[par[i]] != i) for (int at = i; at != -1; at = heavy[at]) hroot[at] = i;
	
	string s;
	REP(i, np) {
		pidx[i] = SZ(s);
		s += p[i] + "#";
	}
	REP(i, n) if (hroot[i] == i) {
		string path; 
		for (int at = i; at != -1; at = heavy[at]) path += parc[at];
		for (int at = i; at != -1; at = heavy[at]) dnidx[at] = SZ(s) + (dep[at] - dep[i]), upidx[at] = SZ(s) + 2 * SZ(path) - (dep[at] - dep[i]);
		s += path + "#";
		reverse(path.begin(), path.end()); 
		s += path + "#"; 
	}
	vector<int> sa = SuffixArray::build(s);
	LCP lcp;
	lcp.build(s, sa);
	vector<int> pos(SZ(s), -1);
	REPSZ(i, sa) pos[sa[i]] = i;
	//printf("%s\n", s.c_str());
	//REPSZ(i, sa) { printf("%2d: ", i); FORSZ(j, sa[i], s) if (s[j] == '#') break; else printf("%c", s[j]); if (i != SZ(sa) - 1) printf(" %d", lcp.lcp[i]); puts(""); }

	vector<vector<E>> e(np + 1);
	REP(i, nq) {
		int a = qa[i], b = qb[i];
		vector<pair<int, int>> parts = decompose(a, b);
		//printf("%d->%d:", a + 1, b + 1); for (auto z : parts) printf(" %d..%d", z.first + 1, z.second + 1); puts("");

		auto cmp = [&](int idx) {
			REPSZ(i, parts) {
				int x = parts[i].first, y = parts[i].second;
				int len, partidx;
				if (dep[x] <= dep[y]) len = dep[y] - dep[x] + 1, partidx = dnidx[x]; else len = dep[x] - dep[y] + 1, partidx = upidx[x];
				int common = min(len, lcp.query(pos[idx], pos[partidx]));
				//printf("\tcomparing %d and %s[%d] -> %d and %d -> %d (len=%d)\n", idx, dep[x] <= dep[y] ? "dnidx" : "upidx", x + 1, pos[idx], pos[partidx], common, len);
				if (common < len) return s[idx + common] < s[partidx + common] ? -1 : +1;
				idx += common;
			}
			return 0;
		};
		int l, r;
		{
			int lo = -1, hi = SZ(sa);
			while (lo + 1 < hi) {
				int mi = lo + (hi - lo) / 2;
				if (cmp(sa[mi]) >= 0) hi = mi; else lo = mi;
			}
			l = hi;
		}
		{
			int lo = -1, hi = SZ(sa);
			while (lo + 1 < hi) {
				int mi = lo + (hi - lo) / 2;
				if (cmp(sa[mi]) > 0) hi = mi; else lo = mi;
			}
			r = hi - 1;
		}
		//printf("\t[%d..%d]\n", l, r);
		qans[i] = 0;
		if (l <= r) {
			e[ql[i]].PB(E(i, l, r, -1));
			e[qr[i] + 1].PB(E(i, l, r, +1));
		}
	}

	BIT bit;
	bit.init(SZ(sa));
	REPE(i, np) {
		for (auto ee : e[i]) {
			int cur = bit.get(ee.l, ee.r);
			qans[ee.id] += ee.by * cur;
		}
		if (i == np) break;
		REPSZ(j, p[i]) bit.add(pos[pidx[i] + j], +1);
	}
}


void run() {
	scanf("%d%d%d", &n, &np, &nq);
	REP(i, n - 1) { int a, b; char c; scanf("%d%d %c", &a, &b, &c); --a, --b; adj[a].PB(MP(b, c)); adj[b].PB(MP(a, c)); }
	REP(i, np) cin >> p[i];
	REP(i, nq) scanf("%d%d%d%d", &qa[i], &qb[i], &ql[i], &qr[i]), --qa[i], --qb[i], --ql[i], --qr[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int qansstupid[MAXQ];

void solvestupid() {
	REP(i, nq) {
		int a = qa[i], b = qb[i];
		vector<int> prv(n, -2); vector<char> cprv(n, '?'); queue<int> q;
		auto relax = [&](int to, int from, char c) { if (prv[to] != -2) return; prv[to] = from; cprv[to] = c; q.push(to); };
		relax(a, -1, '-');
		while (!q.empty()) { int at = q.front(); q.pop(); REPSZ(i, adj[at]) { int to = adj[at][i].first; relax(to, at, adj[at][i].second); } }
		assert(prv[b] != -2);
		string path;
		for (int at = b; at != a; at = prv[at]) path += cprv[at];
		reverse(path.begin(), path.end());
		qansstupid[i] = 0;
		FORE(j, ql[i], qr[i]) { string s = p[j]; REPE(k, SZ(s) - SZ(path)) if (s.substr(k, SZ(path)) == path) ++qansstupid[i]; }
	}
}

void stress() {
	int mxn = 10, mxp = 3, mxq = 10, mxalph = 4, mxplen = 8;
	REP(rep, 100000) {
		n = rnd() % (mxn - 2 + 1) + 2, np = rnd() % mxp + 1, nq = rnd() % mxq + 1; int alph = rnd() % mxalph + 1;
		REP(i, n) adj[i].clear();
		vector<int> col(n); REP(i, n) col[i] = i; vector<pair<int, int>> e;
		REP(i, n - 1) while (true) { int a = rnd() % n, b = rnd() % n; if (col[a] == col[b]) continue; int ocol = col[b]; REP(j, n) if (col[j] == ocol) col[j] = col[a]; e.PB(MP(a, b)); break; }
		vector<char> ec(n - 1); REP(i, n - 1) { int a = e[i].first, b = e[i].second; ec[i] = 'a' + rnd() % alph; adj[a].PB(MP(b, ec[i])); adj[b].PB(MP(a, ec[i])); }
		REP(i, np) { int len = rnd() % mxplen + 1; p[i] = string(len, '?'); REP(j, len) p[i][j] = 'a' + rnd() % alph; }
		REP(i, nq) while (true) { qa[i] = rnd() % n, qb[i] = rnd() % n; if (qa[i] == qb[i]) continue; ql[i] = rnd() % np; qr[i] = rnd() % np; if (ql[i] > qr[i]) swap(ql[i], qr[i]); break; }
		solve();
		solvestupid();
		bool ok = true; REP(i, nq) if (qans[i] != qansstupid[i]) ok = false;
		if (ok) { if (rep % 1000 == 999) printf("."); continue; }
		printf("err\n");
		printf("have:"); REP(i, nq) printf(" %d", qans[i]); puts("");
		printf("want:"); REP(i, nq) printf(" %d", qansstupid[i]); puts("");
		printf("%d %d %d\n", n, np, nq);
		REP(i, n - 1) printf("%d %d %c\n", e[i].first + 1, e[i].second + 1, ec[i]);
		REP(i, np) printf("%s\n", p[i].c_str());
		REP(i, nq) printf("%d %d %d %d\n", qa[i] + 1, qb[i] + 1, ql[i] + 1, qr[i] + 1);
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}