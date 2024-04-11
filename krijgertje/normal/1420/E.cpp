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

const int MAXN = 80;

int n;
int a[MAXN];
int ans[MAXN * (MAXN - 1) / 2 + 1];

void solve() {
	// #zeroes, #ones, cost -> min pairs
	vector<int> zeroes;
	vector<int> ones;
	REP(i, n) if (a[i] == 0) zeroes.PB(i); else ones.PB(i);
	int nzeroes = SZ(zeroes), nones = SZ(ones);
	int mxcost = nones * (n - 1) - nones * (nones - 1) / 2;
	vector<vector<vector<int>>> dp(nzeroes + 1, vector<vector<int>>(nones + 1, vector<int>(mxcost + 1, INT_MAX)));
	auto upd = [&](int& a, int b) { a = min(a, b); };
	upd(dp[0][0][0], 0);
	REPE(zero, nzeroes) REPE(one, nones) REPE(cost, mxcost) if (dp[zero][one][cost] != INT_MAX) {
		if (one + 1 <= nones) REPE(dzero, nzeroes - zero) {
			upd(dp[zero + dzero][one + 1][cost + abs(zero + one + dzero - ones[one])], dp[zero][one][cost] + dzero * (dzero - 1) / 2);
		}
		if (one == nones && zero < nzeroes) {
			int dzero = nzeroes - zero;
			upd(dp[zero + dzero][one][cost], dp[zero][one][cost] + dzero * (dzero - 1) / 2);
		}
		//printf("dp[%d][%d][%d]=%d\n", zero, one, cost, dp[zero][one][cost]);
	}
	int nans = n * (n - 1) / 2 + 1;
	REP(i, nans) ans[i] = INT_MAX;
	REPE(cost, mxcost) upd(ans[cost], dp[nzeroes][nones][cost]);
	FOR(i, 1, nans) upd(ans[i], ans[i - 1]);
	REP(i, nans) assert(ans[i] != INT_MAX);
	REP(i, nans) ans[i] = nzeroes * (nzeroes - 1) / 2 - ans[i];
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	REPE(i, n * (n - 1) / 2) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}