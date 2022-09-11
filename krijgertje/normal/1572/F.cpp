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

struct BIT {
	int n; vector<pair<int, ll>> val;
	void init(int _n) { n = _n; val = vector<pair<int, ll>>(n + 1, MP(0, 0LL)); }
	ll getprefix(int idx) { int a = 0; ll b = 0; int x = idx; ++idx; while (idx > 0) { a += val[idx].first, b += val[idx].second; idx -= idx & -idx; } return (ll)a * x + b; }
	void modsuffix(int idx, int a, ll b) { ++idx; while (idx <= n) { val[idx].first += a, val[idx].second += b; idx += idx & -idx; } }
	void modrange(int l, int r, int by) { /*printf("modrange %d..%d by %d\n", l, r, by);*/ modsuffix(l, by, -(ll)(l - 1) * by); modsuffix(r, -by, (ll)r * by); }
	ll getrange(int l, int r) { return getprefix(r) - getprefix(l - 1); }
};

// A*idx+B
// [L..) A+=by, B-=(L-1)*by
// [R..) A-=by, B+=R*by

const int MAXCITY = 200000;
const int MAXQ = 200000;
const int MAXS = 4 * MAXCITY;
struct S { int mx, mxcnt, mx2; };

int ncity, nq;
int qkind[MAXQ], qcity[MAXQ], qlim[MAXQ], ql[MAXQ], qr[MAXQ];
ll qans[MAXQ];

BIT bit;
S s[MAXS];

void spull(int x) {
	S& a = s[x]; const S& b = s[2 * x + 1], & c = s[2 * x + 2];
	a.mx = max(b.mx, c.mx);
	a.mxcnt = (b.mx == a.mx ? b.mxcnt : 0) + (c.mx == a.mx ? c.mxcnt : 0);
	a.mx2 = max(b.mx == a.mx ? b.mx2 : b.mx, c.mx == a.mx ? c.mx2 : c.mx);
}
void spush(int x) {
	const S& a = s[x]; S& b = s[2 * x + 1], & c = s[2 * x + 2];
	b.mx = min(b.mx, a.mx);
	c.mx = min(c.mx, a.mx);
}
void sinit(int x, int l, int r) {
	if (l == r) {
		S& a = s[x]; a.mx = l, a.mxcnt = 1, a.mx2 = INT_MIN;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void smin(int x, int l, int r, int L, int R, int BY) {
	if (s[x].mx <= BY) return;
	if (L <= l && r <= R && s[x].mx2 < BY) {
		bit.modrange(BY + 1, s[x].mx, -s[x].mxcnt);
		s[x].mx = BY;
		return;
	}
	assert(l != r);
	int m = l + (r - l) / 2;
	spush(x);
	if (L <= m) smin(2 * x + 1, l, m, L, R, BY);
	if (m + 1 <= R) smin(2 * x + 2, m + 1, r, L, R, BY);
	spull(x);
}
void sset(int x, int l, int r, int IDX, int VAL) {
	if (l == r) {
		if (VAL > s[x].mx) bit.modrange(s[x].mx + 1, VAL, +1);
		if (VAL < s[x].mx) bit.modrange(VAL + 1, s[x].mx, -1);
		s[x].mx = VAL;
	} else {
		int m = l + (r - l) / 2;
		spush(x);
		if (IDX <= m) sset(2 * x + 1, l, m, IDX, VAL); else sset(2 * x + 2, m + 1, r, IDX, VAL);
		spull(x);
	}
}


void solve() {
	bit.init(ncity);
	bit.modrange(0, ncity - 1, 1);
	sinit(0, 0, ncity - 1);
	REP(i, nq) {
		//printf("q%d\n", i);
		if (qkind[i] == 1) {
			int idx = qcity[i], lim = qlim[i];
			if (idx != 0) smin(0, 0, ncity - 1, 0, idx - 1, idx - 1);
			sset(0, 0, ncity - 1, idx, lim);
		}
		if (qkind[i] == 2) {
			qans[i] = bit.getrange(ql[i], qr[i]);
		}
	}
}

void run() {
	scanf("%d%d", &ncity, &nq);
	REP(i, nq) { scanf("%d", &qkind[i]); if (qkind[i] == 1) scanf("%d%d", &qcity[i], &qlim[i]), --qcity[i], --qlim[i]; if (qkind[i] == 2) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i]; }
	solve();
	REP(i, nq) if (qkind[i] == 2) printf("%lld\n", qans[i]);
}

int main() {
	//int ncase; scanf("%d", &ncase); FORE(i, 1, ncase)
	run();
	return 0;
}