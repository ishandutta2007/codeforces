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

const int MAXN = 300000;
const int NBIT = 30;

int n, need;
int val[MAXN];
vector<int> ans;

int ord[MAXN];

void rec(int bit, int la, int ra, int lb, int rb) {
	//printf("rec(%d,%d..%d,%d..%d)\n", bit, la, ra, lb, rb);
	if (ra == la || rb == lb) {
		if (la < ra) ans.PB(ord[la]);
		if (lb < rb) ans.PB(ord[lb]);
		return;
	}
	if (bit == -1) {
		ans.PB(ord[la]);
		ans.PB(ord[lb]);
		return;
	}
	int ma = la;
	while (ma < ra && (val[ord[ma]] & (1 << bit)) == 0) ++ma;
	int mb = lb;
	while (mb < rb && (val[ord[mb]] & (1 << bit)) == 0) ++mb;
	if ((need & (1 << bit)) == 0) {
		if (la < ma && mb < rb) {
			ans.PB(ord[la]);
			ans.PB(ord[mb]);
		} else if (ma < ra && lb < mb) {
			ans.PB(ord[ma]);
			ans.PB(ord[lb]);
		} else {
			if (la == ma) {
				assert(ma < ra && lb == mb && mb < rb);
				rec(bit - 1, ma, ra, mb, rb);
			} else {
				assert(mb == rb && lb < mb && ma == ra && la < ma);
				rec(bit - 1, la, ma, lb, mb);
			}
		}
	} else {
		int oldcnt = SZ(ans);
		rec(bit - 1, la, ma, mb, rb);
		if (SZ(ans) - oldcnt == 2) return;
		while (SZ(ans) > oldcnt) ans.pop_back();
		rec(bit - 1, ma, ra, lb, mb);
		if (SZ(ans) - oldcnt == 2) return;
		while (SZ(ans) > oldcnt) ans.pop_back();
		ans.PB(ord[la]);
	}
}

void rec(int bit, int l, int r) {
	//printf("rec(%d,%d..%d)\n", bit, l, r);
	if (r == l) return;
	if (bit == -1) { FOR(i, l, r) ans.PB(ord[i]); return; }
	int m = l;
	while (m < r && (val[ord[m]] & (1 << bit)) == 0) ++m;
	if ((need & (1 << bit)) == 0) {
		rec(bit - 1, l, m);
		rec(bit - 1, m, r);
	} else {
		rec(bit - 1, l, m, m, r);
	}
}

bool solve() {
	ans.clear();
	REP(i, n) ord[i] = i;
	sort(ord, ord + n, [&](int i, int j) { return val[i] < val[j]; });
	rec(NBIT - 1, 0, n);
	return SZ(ans) >= 2;
}


void run() {
	scanf("%d%d", &n, &need);
	REP(i, n) scanf("%d", &val[i]);
	if (!solve()) { printf("-1\n"); return; }
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int solvestupid() {
	int ret = -1;
	REP(mask, 1 << n) {
		bool ok = true;
		REP(i, n) if (mask & (1 << i)) FOR(j, i + 1, n) if (mask & (1 << j)) {
			if ((val[i] ^ val[j]) < need) ok = false;
		}
		if (!ok) continue;
		int cnt = 0;
		REP(i, n) if (mask & (1 << i)) ++cnt;
		if (cnt >= 2) ret = max(ret, cnt);
	}
	return ret;
}

void stress() {
	std::mt19937 rnd(12131);
	int mxn = 3;
	int nbit = 3;
	REP(rep, 10000) {
		n = rnd() % mxn + 1;
		need = rnd() % (1 << nbit);
		REP(i, n) val[i] = rnd() % (1 << nbit);
		if (rep != 82) continue;
		int have = solve() ? SZ(ans) : -1;
		int want = solvestupid();
		if (have == want) { printf("."); continue; }
		printf("err rep=%d\n", rep);
		printf("have=%d want=%d\n", have, want);
		printf("%d %d\n", n, need); REP(i, n) { if (i != 0) printf(" "); printf("%d", val[i]); } puts("");
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}