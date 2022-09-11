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

const int MAXN = 2000;
const int MAXLIM = 50;
const int MOD = 998244353;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int &a, int b) { inc(a, MOD - b); }

int n, lim;
int want[MAXN];

int dp[2 * MAXLIM + 1][MAXN + 1]; // dp[mexdiff][big]
int ndp[2 * MAXLIM + 1][MAXN + 1];
int tmp[2 * MAXLIM + 1];

int inv[MAXN + 1];
int fac[MAXN + 1];
int ifac[MAXN + 1];
int choose(int n, int k) { if (k<0 || k>n) return 0; return (ll)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD; }

int solve() {
	inv[1] = 1; FORE(i, 2, n) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, n) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, n) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	FORE(mexdiff, -lim, +lim) REPE(big, n) dp[lim + mexdiff][big] = 0;
	inc(dp[lim + 0][0], 1);
	REP(i, n) {
		FORE(mexdiff, -lim, +lim) REPE(big, n) ndp[lim + mexdiff][big] = 0;
		FORE(mexdiff, -lim, +lim) REPE(big, n) {
			int cur = dp[lim + mexdiff][big];
			if (cur == 0) continue;
			int mex = (i == 0 ? 0 : want[i - 1]) + mexdiff;
			int nmexdiff = mex - want[i];
			if (abs(nmexdiff) > lim) continue;
			inc(ndp[lim + nmexdiff][big], (ll)cur * (mex + big) % MOD);
			inc(ndp[lim + nmexdiff][big + 1], cur);
		}
		FORE(sum, -lim, +lim + n) {
			FORE(nmexdiff, -lim, +lim) tmp[lim + nmexdiff] = 0;
			FORE(mexdiff, -lim, +lim) {
				int big = sum - mexdiff;
				if (big < 0 || big > n) continue;
				int cur = dp[lim + mexdiff][big];
				if (cur == 0) continue;
				int mex = (i == 0 ? 0 : want[i - 1]) + mexdiff;
				// delta >= 0, delta <= big, mex + delta + 1 - want[i] >= -lim, mex + delta + 1 - want[i] <= +lim
				int ldelta = max(0, -lim - mex + want[i] - 1), rdelta = min(big, +lim - mex + want[i] - 1);
				if (ldelta > rdelta) continue;
				int lnmexdiff = mex + ldelta + 1 - want[i], rnmexdiff = mex + rdelta + 1 - want[i];
				assert(lnmexdiff >= -lim && rnmexdiff <= +lim);
				cur = (ll)cur * fac[big] % MOD;
				//printf("i=%d mex=%d big=%d -> delta = %d..%d -> nmexdiff = %d..%d\n", i, mex, big, ldelta, rdelta, lnmexdiff, rnmexdiff);
				inc(tmp[lim + lnmexdiff], cur);
				if (rnmexdiff != +lim) dec(tmp[lim + rnmexdiff + 1], cur);
			}
			//printf("tmp:"); FORE(nmexdiff, -lim, +lim) printf(" %d", tmp[lim + nmexdiff]); puts("");
			FORE(nmexdiff, -lim, +lim) {
				if (nmexdiff != -lim) inc(tmp[lim + nmexdiff], tmp[lim + nmexdiff - 1]);
				int cur = tmp[lim + nmexdiff];
				if (cur == 0) continue;
				int nmex = want[i] + nmexdiff;
				int nbig = sum + 1 - nmexdiff + (i == 0 ? 0 : want[i - 1]) - want[i];
				//printf("-> nmex=%d nbig=%d (%d)\n", nmex, nbig, cur);
				assert(nbig >= 0 && nbig <= n);
				cur = (ll)cur * ifac[nbig] % MOD;
				inc(ndp[lim + nmexdiff][nbig], cur);
			}
		}

		FORE(mexdiff, -lim, +lim) REPE(big, n) dp[lim + mexdiff][big] = ndp[lim + mexdiff][big];
	}
	int ret = 0;
	FORE(mexdiff, -lim, +lim) REPE(big, n) {
		int cur = dp[lim + mexdiff][big];
		if (cur == 0) continue;
		int mex = want[n - 1] + mexdiff;
		inc(ret, (ll)cur * choose(n - mex, big) % MOD * fac[big] % MOD);
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &lim);
	REP(i, n) scanf("%d", &want[i]);
	printf("%d\n", solve());
}

void stress() {
	n = MAXN, lim = MAXLIM;
	REP(i, n) want[i] = MAXLIM;
	printf("%d\n", solve());
}

int main() {
	run();
	//stress();
	return 0;
}