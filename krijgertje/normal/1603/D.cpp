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

const int MAXN = 100000;


int phi[MAXN + 1];
ll f[MAXN + 1];

int flip[MAXN + 1];
vector<ll> sum1[MAXN + 1]; // sum1[i][j] = sum(k=i/(j+1)+1..i: f[i/k]) for 0<=j<=flip[i]
vector<ll> sum2[MAXN + 1]; // sum2[i][j] = sum(k=j..i: f[i/k]) for 1<=j<=flip[i]

vector<vector<ll>> dp;


void precalc() {
	REPE(i, MAXN) phi[i] = i;
	FORE(i, 2, MAXN) if (phi[i] == i) for (int j = i; j <= MAXN; j += i) phi[j] -= phi[j] / i;
	REPE(i, MAXN) f[i] = phi[i] + (i - 1 >= 0 ? f[i - 1] : 0);
	//printf("f:"); FORE(i, 1, n) printf(" %lld", f[i]); puts("");

	FORE(i, 1, MAXN) {
		flip[i] = sqrt(1.0 * i);
		sum1[i] = sum2[i] = vector<ll>(flip[i] + 1);
		FORE(j, 1, flip[i]) sum1[i][j] = sum1[i][j - 1] + (i / j - i / (j + 1)) * f[j];
		sum2[i][flip[i]] = sum1[i][flip[i]]; // sum(k=flip[i]..i: f[i/k]) = sum(k=flip[i]..i: f[i/k]) - sum(k=i/(flip[i]+1)+1..i: f[i/k]) + sum1[i][flip[i]]
		{ int cur = i / (flip[i] + 1) + 1; while (cur > flip[i]) --cur, sum2[i][flip[i]] += f[i / cur]; while (cur < flip[i]) sum2[i][flip[i]] -= f[i / cur], ++cur; }
		for (int j = flip[i] - 1; j >= 1; --j) sum2[i][j] = sum2[i][j + 1] + f[i / j];
	}
	auto cost = [&](int l, int r) { if (l <= flip[r]) return sum2[r][l]; int v = r / l; return sum1[r][v - 1] + (r / v - l + 1) * f[v]; };

	/*auto coststupid = [&](int l, int r) { int ret = 0; FORE(i, l, r) FORE(j, i, r) if (gcd(i, j) >= l) ++ret; return ret; };
	FORE(i, 1, n) FORE(j, i, n) {
		ll have = cost(i, j);
		ll want = coststupid(i, j);
		if (have == want) { printf("."); continue; }
		printf("err: [%d..%d]: have=%lld want=%lld\n", i, j, have, want);
	}*/

	dp = vector<vector<ll>>(1, vector<ll>(MAXN + 1));
	dp[0][0] = 0; FORE(i, 1, MAXN) dp[0][i] = LLONG_MAX;

	for (int i = 0;; ++i) {
		auto rec = [&](auto self, int l, int r, int lopt, int ropt) -> void {
			int m = l + (r - l) / 2;
			dp[i + 1][m] = LLONG_MAX; int mopt = -1;
			FORE(j, lopt, ropt) {
				if (j > m || dp[i][j - 1] == LLONG_MAX) continue;
				ll cur = dp[i][j - 1] + cost(j, m);
				if (cur < dp[i + 1][m]) dp[i + 1][m] = cur, mopt = j;
			}
			//printf("part %d: [%d..%d] using [%d..%d] -> %d = %lld using %d\n", i, l, r, lopt, ropt, m, dp[i+1][m], mopt);
			if (l <= m - 1) self(self, l, m - 1, lopt, mopt);
			if (m + 1 <= r) self(self, m + 1, r, mopt, ropt);
		};
		dp.PB(vector<ll>(MAXN + 1));
		dp[i + 1][0] = 0;
		rec(rec, 1, MAXN, 1, MAXN);
		if (dp[i + 1][MAXN] == MAXN) break;
	}
}

int n, nparts;

ll solve() {
	return dp[min(SZ(dp) - 1, nparts)][n];
}

void run() {
	scanf("%d%d", &n, &nparts);
	printf("%lld\n", solve());
}

ll solvestupid() {
	vector<vector<ll>> dp(n + 1, vector<ll>(nparts + 1, LLONG_MAX));
	auto cost = [&](int l, int r) { int ret = 0; FORE(i, l, r) FORE(j, i, r) if (gcd(i, j) >= l) ++ret; return ret; };
	dp[0][0] = 0;
	REP(i, n) REP(k, nparts) {
		if (dp[i][k] == LLONG_MAX) continue;
		FORE(j, i + 1, n) {
			ll val = dp[i][k] + cost(i + 1, j);
			dp[j][k + 1] = min(dp[j][k + 1], val);
		}
	}
	return dp[n][nparts];
}

void stress() {
	FORE(n, 1, 100) {
		//if (n != 75 && n != 76) continue;
		FORE(nparts, 1, min(n, 10)) {
			//if (nparts != 3) continue;
			::n = n; ::nparts = nparts;
			ll have = solve();
			ll want = solvestupid();
			if (have == want) printf("."); else printf("%d %d: have = %lld want = %lld\n", n, nparts, have, want);
		}
		printf("done %d\n", n);
	}
}

int main() {
	precalc();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}