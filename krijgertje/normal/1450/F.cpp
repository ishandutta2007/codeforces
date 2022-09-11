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

const int MAXN = 100000;

int n;
int a[MAXN];

bool breakafter[MAXN];

int solve() {
	vector<pair<int, int>> pairs;
	vector<int> cycs;

	REP(i, n) breakafter[i] = i + 1 >= n || a[i + 1] == a[i];
	for (int l = 0, r = l; l < n; l = r) {
		while (!breakafter[r]) ++r;
		int u = a[l], v = a[r];
		if (u == v) cycs.PB(u); else pairs.PB(MP(u, v));
		++r;
	}

	sort(cycs.begin(), cycs.end());
	int mxcyc = 0, mxcycval = -1;
	for (int l = 0, r = l; l < SZ(cycs); l = r) {
		while (r < SZ(cycs) && cycs[r] == cycs[l]) ++r;
		int cnt = r - l, val = cycs[l];
		if (cnt > mxcyc) mxcyc = cnt, mxcycval = val;
	}

	int oth = 0;
	REPSZ(i, pairs) if (pairs[i].first != mxcycval && pairs[i].second != mxcycval) ++oth;
	REPSZ(i, cycs) if (cycs[i] != mxcycval) ++oth;
	int ret = SZ(pairs) + SZ(cycs) - 1;
	//printf("mxcyc=%d mxcycval=%d oth=%d ret=%d\n", mxcyc, mxcycval, oth, ret);
	if (oth >= mxcyc - 1) return ret;

	int need = mxcyc - 1 - oth;
	int have = 0;
	REP(i, n - 1) if (!breakafter[i] && a[i] != mxcycval && a[i + 1] != mxcycval) ++have;
	if (have < need) return -1;

	//printf("need=%d have=%d\n", need, have);
	return ret + need;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int solvestupid() {
	vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
	auto upd = [&](int& a, int b) { a = min(a, b); };
	REP(i, n) upd(dp[1 << i][i], 0);
	REP(mask, 1 << n) REP(at, n) if (dp[mask][at] != INT_MAX) {
		REP(to, n) {
			if (mask & (1 << to)) continue;
			if (a[to] == a[at]) continue;
			upd(dp[mask | (1 << to)][to], dp[mask][at] + (abs(at - to) >= 2 ? 1 : 0));
		}
	}
	int ret = INT_MAX; REP(i, n) upd(ret, dp[(1 << n) - 1][i]); return ret == INT_MAX ? -1 : ret;
}

void stress() {
	REP(rep, 100000) {
		n = rnd() % 10 + 1;
		REP(i, n) a[i] = rnd() % n + 1;
		int have = solve();
		int want = solvestupid();
		if (have == want) { printf("."); continue; }
		printf("err have=%d want=%d\n", have, want);
		printf("%d\n", n); REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i]); } puts("");
		break;
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}