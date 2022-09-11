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

const int MAXMOVE = 200;
const int MOD = 1000000007;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n, mxmove;
int ans[MAXMOVE + 1];

int inv[2 * MAXMOVE + 1];
int fac[2 * MAXMOVE + 1];
int ifac[2 * MAXMOVE + 1];

int dp[MAXMOVE + 1][2 * MAXMOVE + 1];

int choose(int n, int k) { assert(k >= 0 && k <= n); assert(k <= 2 * mxmove); int ret = 1; REP(i, k) ret = (ll)ret * (n - i) % MOD * inv[i + 1] % MOD; return ret; }

void solve() {
	inv[1] = 1; FORE(i, 2, 2 * MAXMOVE) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, 2 * MAXMOVE) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, 2 * MAXMOVE) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	memset(dp, 0, sizeof(dp));
	inc(dp[0][0], 1);
	FORE(cyclen, 2, mxmove + 1) {
		for (int i = mxmove; i >= 0; --i) REPE(j, min(n, 2 * i)) if (dp[i][j] != 0) {
			int cur = dp[i][j];
			for (int t = 1; i + t * (cyclen - 1) <= mxmove; ++t) {
				cur = (ll)cur * inv[cyclen] % MOD;
				//if (i + t * cyclen <= n) printf("dp[%d][%d]+=dp[%d][%d]*inv[%d]^%d*inv[%d]\n", i + t * (cyclen - 1), j + t * cyclen, i, j, cyclen, t, t);
				assert(j + t * cyclen <= 2 * (i + t * (cyclen - 1)));
				inc(dp[i + t * (cyclen - 1)][j + t * cyclen], (ll)cur * ifac[t] % MOD);
			}
		}
	}

	REPE(i, mxmove) {
		ans[i] = 0;
		REPE(j, min(n, 2 * i)) if (dp[i][j] != 0) {
			int cur = (ll)dp[i][j] * fac[j] % MOD * choose(n, j) % MOD;
			//printf("i=%d j=%d -> %d\n", i, j, cur);
			inc(ans[i], cur);
		}
		if (i - 2 >= 0) inc(ans[i], ans[i - 2]);
	}
}

void run() {
	scanf("%d%d", &n, &mxmove);
	solve();
	FORE(i, 1, mxmove) { if (i != 1) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}