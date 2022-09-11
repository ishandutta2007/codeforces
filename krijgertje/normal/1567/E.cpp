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
const int MAXQ = 200000;
const int MAXS = 4 * MAXN;
struct S { ll inside; int pref, suff; bool all; S() {} S(int x) { inside = 1; pref = 1; suff = x == 0 ? 1 : 0; all = x == 0; } };

int n, nq;
int a[MAXN];
int qkind[MAXQ], qidx[MAXQ], qval[MAXQ], ql[MAXQ], qr[MAXQ];
ll qans[MAXQ];

int cur[MAXN];

S s[MAXS];
S merge(const S& a, const S& b) {
	S ret;
	ret.inside = a.inside + b.inside + (ll)a.suff * b.pref;
	ret.pref = a.pref + (a.all ? b.pref : 0);
	ret.suff = b.suff + (b.all ? a.suff : 0);
	ret.all = a.all && b.all;
	return ret;
}
void spull(int x) {
	s[x] = merge(s[2 * x + 1], s[2 * x + 2]);
}
void sinit(int x, int l, int r) {
	if (l == r) {
		s[x] = S(0);
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void sset(int x, int l, int r, int IDX, int VAL) {
	if (l == r) {
		s[x] = S(VAL);
	} else {
		int m = l + (r - l) / 2;
		if (IDX <= m) sset(2 * x + 1, l, m, IDX, VAL);
		else sset(2 * x + 2, m + 1, r, IDX, VAL);
		spull(x);
	}
}
S sget(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return s[x];
	} else {
		int m = l + (r - l) / 2;
		if (R <= m) return sget(2 * x + 1, l, m, L, R);
		if (L >= m + 1) return sget(2 * x + 2, m + 1, r, L, R);
		return merge(sget(2 * x + 1, l, m, L, R), sget(2 * x + 2, m + 1, r, L, R));
	}
}

void solve() {
	sinit(0, 0, n - 1);
	REP(i, n) cur[i] = a[i];
	REP(i, n - 1) if (cur[i] > cur[i + 1]) sset(0, 0, n - 1, i, 1);
	REP(i, nq) {
		if (qkind[i] == 1) {
			int idx = qidx[i], val = qval[i];
			cur[idx] = val;
			if (idx - 1 >= 0) sset(0, 0, n - 1, idx - 1, cur[idx - 1] > cur[idx] ? 1 : 0);
			if (idx + 1 < n) sset(0, 0, n - 1, idx, cur[idx] > cur[idx + 1] ? 1 : 0);
		}
		if (qkind[i] == 2) {
			qans[i] = sget(0, 0, n - 1, ql[i], qr[i]).inside;
		}
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, nq) { scanf("%d", &qkind[i]); if (qkind[i] == 1) scanf("%d%d", &qidx[i], &qval[i]), --qidx[i]; if (qkind[i] == 2) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i]; }
	solve();
	REP(i, nq) if (qkind[i] == 2) printf("%lld\n", qans[i]);
}

int main() {
	run();
	return 0;
}