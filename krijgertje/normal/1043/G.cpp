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

struct ZAlgo {
	string s; int n; vector<int> z;
	void init(int _n) { n = _n; s = string(n, '?'); z = vector<int>(n, -1); }
	void calc() {
		int l = 0, r = 0;
		FOR(i, 1, n) {
			if (i < r) { int k = i - l; if (z[k] < r - i) { z[i] = z[k]; continue; } else l = i; } else l = r = i;
			while (r < n && s[r] == s[r - l]) ++r; z[i] = r - l;
		}
	}
};

struct RepeatRun { int l, r, len; RepeatRun(int l, int r, int len) :l(l), r(r), len(len) {} };
//bool operator<(const RepeatRun &a, const RepeatRun &b) { if (a.len != b.len) return a.len < b.len; return a.l < b.l; }
struct RepeatFinder {
	char *s; int n;
	ZAlgo ba, abrev;

	vector<RepeatRun> runs;

	void rec(int l, int r) {
		if (l == r) return;
		int m = l + (r - l) / 2;
		rec(l, m);
		rec(m + 1, r);
		ba.n = 0; FORE(i, m + 1, r) ba.s[ba.n++] = s[i]; ba.s[ba.n++] = '#'; FORE(i, l, m) ba.s[ba.n++] = s[i];
		abrev.n = 0; for (int i = m; i >= l; --i) abrev.s[abrev.n++] = s[i]; abrev.s[abrev.n++] = '#'; for (int i = r; i >= m + 1; --i) abrev.s[abrev.n++] = s[i];
		ba.calc(); abrev.calc();
		FORE(i, l, m) {
			int k = m - i + 1, k1 = abrev.z[k], k2 = ba.z[r - m + 1 + i - l];
			if (k1 + k2 >= k && k2 >= 1) runs.PB(RepeatRun(i - min(k - 1, k1), i - (k - k2), k));
		}
		FORE(i, m + 2, r) {
			int k = i - m, k1 = ba.z[k], k2 = abrev.z[m - l + 1 + 1 + r - i];
			if (k1 + k2 >= k && k2 >= 1 && k1 >= 1) runs.PB(RepeatRun(m + 1 - min(k - 1, k2), m + 1 - max(k - k1, 1), k));
		}
	}
	void init(char *_s) { s = _s; n = strlen(s); ba.init(n + 1); abrev.init(n + 1); }
	void calcruns() { runs.clear(); rec(0, n - 1); }
	vector<int> calcminstart() {
		vector<vector<int>> e(n + 1); REPSZ(i, runs) e[runs[i].l].PB(runs[i].len), e[runs[i].r + 1].PB(-runs[i].len);
		multiset<int> have;	vector<int> ret(n);
		REP(i, n) { REPSZ(j, e[i]) { int x = e[i][j]; if (x > 0) have.insert(x); else have.erase(have.find(-x)); } ret[i] = SZ(have) == 0 ? 0 : *have.begin(); }
		return ret;
	}
	vector<int> calcminend() {
		vector<vector<int>> e(n + 1); REPSZ(i, runs) e[runs[i].l + 2 * runs[i].len - 1].PB(runs[i].len), e[runs[i].r + 2 * runs[i].len].PB(-runs[i].len);
		multiset<int> have;	vector<int> ret(n);
		REP(i, n) { REPSZ(j, e[i]) { int x = e[i][j]; if (x > 0) have.insert(x); else have.erase(have.find(-x)); } ret[i] = SZ(have) == 0 ? 0 : *have.begin(); }
		return ret;
	}
};

struct RMQ {
	int *a; int n;
	void init(int* _a, int _n) { a = _a; n = _n; }

	vector<int> lg; vector<vector<int>> rmq;
	void calc() {
		lg = vector<int>(n + 1); lg[1] = 0; FORE(i, 1, n) { lg[i] = lg[i - 1]; while ((2 << lg[i]) <= i) ++lg[i]; }
		rmq = vector<vector<int>>(n, vector<int>(lg[n] + 1));
		REP(i, n) rmq[i][0] = a[i]; REP(k, lg[n]) REP(i, n) if (i + (1 << k) < n) rmq[i][k + 1] = min(rmq[i][k], rmq[i + (1 << k)][k]); else rmq[i][k + 1] = rmq[i][k];
	}
	int query(int l, int r) { int k = lg[r - l + 1]; return min(rmq[l][k], rmq[r - (1 << k) + 1][k]); }
};


struct SuffixArray {
	char *s; int n;
	void init(char *_s, bool cyclic) { s = _s; n = strlen(s) + (cyclic ? 0 : 1); }

	vector<int> sa, id, cnt, sa2, oid; int nid;
	void calcsuffixarray() {
		sa = id = sa2 = oid = vector<int>(n); nid = 256; cnt = vector<int>(max(n, nid), 0);	REP(i, n) oid[i] = (int)s[i];
		REP(i, n) ++cnt[oid[i]]; FOR(i, 1, nid) cnt[i] += cnt[i - 1]; REP(i, n) sa[--cnt[oid[i]]] = i;
		nid = 0; REP(i, n) if (i == 0 || oid[sa[i]] != oid[sa[i - 1]]) id[sa[i]] = nid++; else id[sa[i]] = id[sa[i - 1]];
		for (int step = 0; (1 << step) < n; ++step) {
			REP(i, n) { oid[i] = id[i], sa2[i] = sa[i] - (1 << step); if (sa2[i] < 0) sa2[i] += n; }
			REP(i, nid) cnt[i] = 0;
			REP(i, n) ++cnt[oid[sa2[i]]]; FOR(i, 1, nid) cnt[i] += cnt[i - 1]; for (int i = n - 1; i >= 0; --i) sa[--cnt[oid[sa2[i]]]] = sa2[i];
			nid = 0; REP(i, n) if (i == 0 || oid[sa[i]] != oid[sa[i - 1]] || oid[(sa[i] + (1 << step)) % n] != oid[(sa[i - 1] + (1 << step)) % n]) id[sa[i]] = nid++; else id[sa[i]] = id[sa[i - 1]];
		}
	}

	vector<int> pos, lcp;
	void calcadjacentlcp() {
		pos = vector<int>(n); REP(i, n) pos[sa[i]] = i;
		lcp = vector<int>(n - 1); int k = 0; REP(i, n) if (pos[i] != n - 1) { while (i + k < n && sa[pos[i] + 1] + k < n && s[i + k] == s[sa[pos[i] + 1] + k]) ++k; lcp[pos[i]] = k; k = max(0, k - 1); }
	}

	RMQ rmq;
	void preparegenerallcp() { rmq.init(lcp.data(), n - 1); rmq.calc();	}
	int querylcp(int l, int r) { l = pos[l], r = pos[r]; if (l > r) swap(l, r); if (l == r) return n - l; return rmq.query(l, r - 1); }
};

struct Seg2D {
	int *a; int n, lg;
	vector<vector<int>> vals;

	void init(int dep, int l, int r) {
		if (l == r) {
			vals[dep][l] = a[l];
		} else {
			int m = l + (r - l) / 2;
			init(dep + 1, l, m);
			init(dep + 1, m + 1, r);
			merge(vals[dep + 1].begin() + l, vals[dep + 1].begin() + m + 1, vals[dep + 1].begin() + m + 1, vals[dep + 1].begin() + r + 1, vals[dep].begin() + l);
		}
	}
	bool find(int dep, int l, int r, int L, int R, int LVAL, int RVAL) {
		if (L <= l && r <= R) {
			int off = lower_bound(vals[dep].begin() + l, vals[dep].begin() + r + 1, LVAL) - vals[dep].begin();
			return off <= r&&vals[dep][off] <= RVAL;
		} else {
			int m = l + (r - l) / 2;
			if (L <= m && find(dep + 1, l, m, L, R, LVAL, RVAL)) return true;
			if (m + 1 <= R && find(dep + 1, m + 1, r, L, R, LVAL, RVAL)) return true;
			return false;
		}
	}
	void init(int *_a, int _n) {
		a = _a, n = _n, lg = 0; while ((1 << lg) < n) ++lg;
		vals = vector<vector<int>>(lg + 1, vector<int>(n));
		init(0, 0, n - 1);
	}
};




const int MAXLEN = 200000;
const int MAXQ = 200000;
const int ALPH = 26;

int slen;
char s[MAXLEN + 1];
int nq;
int ql[MAXQ], qr[MAXQ], qans[MAXQ];

int charsum[MAXLEN + 1][ALPH];
RepeatFinder repeatfinder;
int firstrepeatends[MAXLEN];
int lastrepeatstarts[MAXLEN];
SuffixArray suffixarray;
int pmn[MAXLEN + 1];
RMQ nextrepeatends;

void precalc() {
	REP(k, ALPH) charsum[0][k] = 0;
	REP(i, slen) REP(k, ALPH) charsum[i + 1][k] = charsum[i][k] + (s[i] == 'a' + k ? 1 : 0);
	repeatfinder.init(s);
	repeatfinder.calcruns();
	//REPSZ(i, repeatfinder.runs) { auto run = repeatfinder.runs[i]; printf("[%d..%d] len %d\n", run.l, run.r, run.len); }
	vector<int> minstart = repeatfinder.calcminstart(), minend = repeatfinder.calcminend();
	REP(i, slen) firstrepeatends[i] = minstart[i] == 0 ? slen : i + 2 * minstart[i] - 1;
	REP(i, slen) lastrepeatstarts[i] = minend[i] == 0 ? -1 : i - 2 * minend[i] + 1;
	nextrepeatends.init(firstrepeatends, slen); nextrepeatends.calc();
	//REP(i, slen) FOR(j, i, slen) { int have = nextrepeatends.query(i, j), want = firstrepeatends[i]; FORE(k, i + 1, j) want = min(want, firstrepeatends[k]); if (have != want) printf("%d..%d: have=%d want=%d\n", i, j, have, want); }
	suffixarray.init(s, false);
	suffixarray.calcsuffixarray();
	suffixarray.calcadjacentlcp();
	suffixarray.preparegenerallcp();
	//REPE(i, slen) printf("%2d: %s (%d)\n", i, s + suffixarray.sa[i], i < slen ? suffixarray.lcp[i] : -1);
	//REPE(i, slen) FORE(j, i + 1, slen) { int have = suffixarray.querylcp(i, j), want = 0; while (j + want <= slen&&s[i + want] == s[j + want]) ++want; if (have != want) printf("%d %d -> have=%d want=%d\n", i, j, have, want); }
	memset(pmn, -1, sizeof(pmn)); FORE(i, 2, MAXLEN) if (pmn[i] == -1) for (int j = i; j <= MAXLEN; j += i) if (pmn[j] == -1) pmn[j] = i;
}

Seg2D seg;
bool qborder[MAXQ];

void precalcborders() {
	vector<vector<int>> e(slen + 1); REP(i, slen) e[suffixarray.lcp[i]].PB(i);
	vector<int> id(slen + 1); vector<set<int>> lst(slen + 1); REPE(i, slen) { id[i] = i; lst[i].insert(i); }
	vector<vector<int>> bylen(slen + 1); REP(i, nq) qborder[i] = false, bylen[qr[i] - ql[i] + 1].PB(i);
	vector<set<pair<int, int>>> q(slen + 1);

	for (int lcplen = slen; lcplen >= 1; --lcplen) {
		REPSZ(i, e[lcplen]) {
			int idx = e[lcplen][i], aid = id[suffixarray.sa[idx]], bid = id[suffixarray.sa[idx + 1]];
			if (SZ(lst[aid]) < SZ(lst[bid])) swap(aid, bid);
			for (auto it = lst[bid].begin(); it != lst[bid].end(); ++it) {
				int at = *it; // at+lcplen-1 >= q[aid][?]
				while (true) {
					auto qit = q[aid].lower_bound(MP(at, 0));
					if (qit == q[aid].end() || at + lcplen - 1 < qit->first) break;
					qborder[qit->second] = true; q[aid].erase(qit);
				}
			}
			for (auto qit = q[bid].begin(); qit != q[bid].end(); ++qit) {
				int to = qit->first; // lst[aid][?] >= to-lcplen+1
				auto it = lst[aid].lower_bound(to - lcplen + 1);
				if (it != lst[aid].end() && *it <= to) qborder[qit->second] = true; else q[aid].insert(MP(to, qit->second));
			}
			for (auto it = lst[bid].begin(); it != lst[bid].end(); ++it) {
				int at = *it;
				id[at] = aid, lst[aid].insert(at);
			}
		}
		REPSZ(i, bylen[lcplen]) { int qid = bylen[lcplen][i], aid = id[ql[qid]]; q[aid].insert(MP(qr[qid], qid)); }
	}

	// Try to find border at position idx such that lcp(ql[i],idx)>=qlen
	seg.init(suffixarray.sa.data(), slen + 1);
	REP(i, nq) if (!qborder[i]) {
		int qlen = qr[i] - ql[i] + 1, pos = suffixarray.pos[ql[i]], lpos, rpos;
		{ int lo = -1, hi = pos; while (lo + 1 < hi) { int mi = lo + (hi - lo) / 2; if (suffixarray.querylcp(suffixarray.sa[mi], ql[i]) >= qlen) hi = mi; else lo = mi; } lpos = hi; }
		{ int lo = pos, hi = slen + 1; while (lo + 1 < hi) { int mi = lo + (hi - lo) / 2; if (suffixarray.querylcp(suffixarray.sa[mi], ql[i]) >= qlen) lo = mi; else hi = mi; } rpos = lo; }
		if (seg.find(0, 0, slen, lpos, rpos, ql[i] + 1, qr[i])) qborder[i] = true;
	}
}

int countchar(int l, int r, char c) {
	return charsum[r + 1][c - 'a'] - charsum[l][c - 'a'];
}
bool impossible(int l, int r) {
	for (char c = 'a'; c <= 'z'; ++c) if (countchar(l, r, c) >= 2) return false;
	return true;
}
bool periodic(int l, int r) {
	int len = r - l + 1, x = len;
	while (x != 1) { int p = pmn[x], repcnt = p, replen = len / repcnt; if (suffixarray.querylcp(l, l + replen) >= len - replen) return true;  while (x % p == 0) x /= p; }
	return false;
}
bool startswithrepeat(int l, int r) {
	return firstrepeatends[l] <= r;
}
bool endswithrepeat(int l, int r) {
	return lastrepeatstarts[r] >= l;
}
bool hasborder(int l, int r, int qid) {
	return qborder[qid];
}
bool containschar(int l, int r, char c) {
	return countchar(l, r, c) >= 1;
}
bool containsrepeat(int l, int r) {
	return nextrepeatends.query(l, r) <= r;
}
int calc(int l, int r, int qid) {
	if (impossible(l, r)) return -1;
	if (periodic(l, r)) return 1;
	if (startswithrepeat(l, r) || endswithrepeat(l, r) || hasborder(l, r, qid)) return 2;
	if (containschar(l + 1, r, s[l]) || containschar(l, r - 1, s[r]) || containsrepeat(l, r)) return 3;
	return 4;
}

void solve() {
	precalc();
	precalcborders();
	REP(i, nq) qans[i] = calc(ql[i], qr[i], i);
}

void run() {
	scanf("%d", &slen);
	scanf("%s", s);
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}