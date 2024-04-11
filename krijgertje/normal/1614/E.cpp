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

const int MAXDAY = 200000;

int nday;
int	temp[MAXDAY];
vector<int> qday[MAXDAY];
vector<int> ans;

struct S { int l, r; int mn, mx, lazy; S() { l = r = -1; mn = mx = lazy = 0; } };

vector<S> s;
int makenode(int lo, int hi) { int ret = SZ(s); s.PB(S()); s[ret].mn = lo, s[ret].mx = hi; return ret; }

void sapply(int x, int by) {
	//printf("applying %d to %d\n", by, x);
	s[x].mn += by;
	if (s[x].mx != INT_MAX) s[x].mx += by;
	s[x].lazy += by;
}
void spush(int x) {
	assert(s[x].l != -1 && s[x].r != -1);
	if (s[x].lazy != 0) sapply(s[x].l, s[x].lazy), sapply(s[x].r, s[x].lazy), s[x].lazy = 0;
}
void spull(int x) {
	assert(s[x].l != -1 && s[x].r != -1);
	s[x].mx = s[s[x].r].mx;
	s[x].mn = s[s[x].l].mn;
}
void smod(int x, int l, int r,int L,int R, int BY) {
	//printf("smod %d..%d = %d..%d with %d..%d by %d\n", l, r, s[x].mn, s[x].mx, L, R, BY);
	if (L <= s[x].mn && s[x].mx <= R) {
		sapply(x, BY);
	} else {
		assert(l != r);
		int m = l + (r - l) / 2;
		if (s[x].l == -1) { int id = makenode(l, m); s[x].l = id; }
		if (s[x].r == -1) { int id = makenode(m + 1, r); s[x].r = id; }
		spush(x);
		if (L <= s[s[x].l].mx) smod(s[x].l, l, m, L, R, BY);
		if (s[s[x].r].mn <= R) smod(s[x].r, m + 1, r, L, R, BY);
		spull(x);
	}
	//printf("smod %d..%d -> %d..%d\n", l, r, s[x].mn, s[x].mx);
}
int sget(int x, int l, int r, int IDX) {
	int ret = s[x].lazy;
	//printf("visit (%d,%d) lazy=%d\n", l, r, s[x].lazy);
	if (l == r) {
		ret += IDX;
	} else {
		int m = l + (r - l) / 2;
		if (IDX <= m) ret += s[x].l == -1 ? IDX : sget(s[x].l, l, m, IDX); else ret += s[x].r == -1 ? IDX : sget(s[x].r, m + 1, r, IDX);
	}
	return ret;
}

void solve() {
	s.clear();
	int lo = 0, hi = 1000000001 + 10 * nday;
	int sroot = makenode(0, hi);

	ans.clear();
	int lastans = 0;
	REP(i, nday) {
		int t = temp[i];
		if (lo <= t - 1 && s[sroot].mn <= t - 1) smod(sroot, lo, hi, lo, t - 1, +1);
		if (t + 1 < hi && s[sroot].mx >= t + 1) smod(sroot, lo, hi, t + 1, hi, -1);
		for (int qq : qday[i]) {
			int q = (qq + lastans) % 1000000001;
			int curans = sget(sroot, lo, hi, q);
			ans.PB(curans);
			lastans = curans;
			//exit(0);
		}
	}
}

void run() {
	scanf("%d", &nday);
	REP(i, nday) {
		scanf("%d", &temp[i]);
		int cnt; scanf("%d", &cnt);
		qday[i] = vector<int>(cnt); REP(j, cnt) scanf("%d", &qday[i][j]);
	}
	solve();
	REPSZ(i, ans) printf("%d\n", ans[i]);
}

void stress() {
	REP(rep, 10) {
		nday = MAXDAY;
		REP(i, nday) temp[i] = rnd() % 1000000001;
		solve();
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}