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

const int MAXN = 500000;
const int MAXQ = 500000;
const int MAXS = 4 * MAXN;

int n, nq;
int gain[3][MAXN];
int ql[MAXQ], qr[MAXQ], qcost[MAXQ];

ll a[MAXN + 1], b[MAXN + 1], c[MAXN + 1];
ll x[MAXN], y[MAXN];

struct Seg1 {
	ll v[MAXS];
	void init(int x, int l, int r) {
		if (l == r) {
			v[x] = ::x[l];
		} else {
			int m = l + (r - l) / 2;
			init(2 * x + 1, l, m);
			init(2 * x + 2, m + 1, r);
			v[x] = max(v[2 * x + 1], v[2 * x + 2]);
		}
	}
	ll get(int x, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			return v[x];
		} else {
			int m = l + (r - l) / 2; ll ret = LLONG_MIN;
			if (L <= m) ret = max(ret, get(2 * x + 1, l, m, L, R));
			if (m + 1 <= R) ret = max(ret, get(2 * x + 2, m + 1, r, L, R));
			return ret;
		}
	}
	void mod(int x, int l, int r, int IDX, ll VAL) {
		if (l == r) {
			v[x] = max(v[x], VAL);
		} else {
			int m = l + (r - l) / 2;
			if (IDX <= m) mod(2 * x + 1, l, m, IDX, VAL); else mod(2 * x + 2, m + 1, r, IDX, VAL);
			v[x] = max(v[2 * x + 1], v[2 * x + 2]);
		}
	}

};
Seg1 seg1;

struct Seg2 {
	struct S {
		ll v, vl, vr;
	};
	S s[MAXS];
	S make(ll x, ll y) { S ret; ret.v = x + y; ret.vl = x; ret.vr = y; return ret; }
	S merge(const S &a, const S &b) { S ret; ret.v = max(max(a.v, b.v), a.vl + b.vr); ret.vl = max(a.vl, b.vl); ret.vr = max(a.vr, b.vr); return ret; }
	void init(int x, int l, int r) {
		if (l == r) {
			s[x] = make(::x[l], ::y[l]);
		} else {
			int m = l + (r - l) / 2;
			init(2 * x + 1, l, m);
			init(2 * x + 2, m + 1, r);
			s[x] = merge(s[2 * x + 1], s[2 * x + 2]);
		}
		//if (r <= 30) printf("init(%d,%d..%d) = %lld %lld %lld\n", x, l, r, s[x].v, s[x].vl, s[x].vr);
	}
	S get(int x, int l, int r, int L, int R) {
		S ret;
		if (L <= l && r <= R) {
			ret = s[x];
		} else {
			int m = l + (r - l) / 2;
			if (L <= m && m + 1 <= R) ret = merge(get(2 * x + 1, l, m, L, R), get(2 * x + 2, m + 1, r, L, R));
			else if (L <= m) ret = get(2 * x + 1, l, m, L, R);
			else if (m + 1 <= R) ret = get(2 * x + 2, m + 1, r, L, R);
			else assert(false);
		}
		//printf("get(%d,%d..%d,%d..%d) = %lld %lld %lld\n", x, l, r, L, R, ret.v, ret.vl, ret.vr);
		return ret;
	}
};
Seg2 seg2;

vector<int> who[MAXN];

ll solve() {
	a[0] = 0; REP(i, n) a[i + 1] = a[i] + gain[0][i];
	b[0] = 0; REP(i, n) b[i + 1] = b[i] + gain[1][i];
	c[0] = 0; REP(i, n) c[i + 1] = c[i] + gain[2][i];
	REP(i, n) x[i] = a[i + 1] - b[i];
	REP(j, n) y[j] = b[j + 1] - c[j];
	//ll chk = LLONG_MIN; REP(id, nq) FORE(i, ql[id], qr[id]) FORE(j, i, qr[id]) { ll cur = x[i] + y[j] + c[n] - qcost[id]; if (cur > chk) { chk = cur; printf("%d: %d->%d=%lld (%lld)\n", id, i, j, cur, cur + qcost[id] - c[n]); } }
	//printf("here=%lld\n", x[28] + y[28]);
	seg1.init(0, 0, n - 1);
	REP(i, n) who[i].clear();
	REP(i, nq) who[ql[i]].PB(i);
	REP(i, n) {
		x[i] = max(x[i], seg1.get(0, 0, n - 1, i, i));
		for (int id : who[i]) {
			ll v = seg1.get(0, 0, n - 1, ql[id], qr[id]) - qcost[id];
			if (qr[id] + 1 < n) seg1.mod(0, 0, n - 1, qr[id] + 1, v);
		}
	}
	seg2.init(0, 0, n - 1);
	//printf("here=%lld\n", x[28] + y[28]);
	ll ret = LLONG_MIN;
	REP(id, nq) {
		ll cur = seg2.get(0, 0, n - 1, ql[id], qr[id]).v - qcost[id] + c[n];
		ret = max(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, 3) REP(j, n) scanf("%d", &gain[i][j]);
	REP(i, nq) scanf("%d%d%d", &ql[i], &qr[i], &qcost[i]), --ql[i], --qr[i];
	printf("%lld\n", solve());
}

ll solvestupid() {
	ll ret = LLONG_MIN;
	FOR(mask, 1, 1 << nq) {
		vector<vector<bool>> ok(3, vector<bool>(n, false));
		REP(j, n) ok[0][j] = ok[2][j] = true;
		ll totalcost = 0;
		REP(i, nq) if (mask & (1 << i)) { totalcost += qcost[i]; FORE(j, ql[i], qr[i]) ok[1][j] = true; }
		vector<vector<ll>> dp(3, vector<ll>(n, LLONG_MIN));
		dp[0][0] = 0;
		REP(i, 3) REP(j, n) if (ok[i][j] && dp[i][j] != LLONG_MIN) {
			dp[i][j] += gain[i][j];
			if (i + 1 < 3 && ok[i + 1][j]) dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			if (j + 1 < n && ok[i][j + 1]) dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
		}
		ret = max(ret, dp[2][n - 1] - totalcost);
	}
	return ret;
}

void stress() {
	std::mt19937 rnd(1235);
	int mxn = MAXN/10000, mxq = 1, lo = -1000000000, hi = +1000000000;
	REP(rep, 3) {
		n = rnd() % mxn + 1;
		nq = rnd() % mxq + 1;
		REP(i, 3) REP(j, n) gain[i][j] = lo + rnd() % (hi - lo + 1);
		REP(i, nq) { ql[i] = rnd() % n, qr[i] = rnd() % n, qcost[i] = rnd() % hi + 1; if (ql[i] > qr[i]) swap(ql[i], qr[i]); }
		ll have = solve();
		ll want = solvestupid();
		if (have == want) { /*if (rep % 1000 == 999)*/ printf("."); continue; }
		printf("have=%lld want=%lld\n", have, want);
	}
}

int main() {
	run();
	//stress();
	return 0;
}