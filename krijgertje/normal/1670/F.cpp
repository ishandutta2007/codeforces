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

const int MAXN = 1000;
const int MOD = 1000000007;
const int MAXBIT = 60;

int n; ll lo, hi, sum;

int dp[MAXBIT + 1][MAXN + 1];
int choose[MAXN + 1][MAXN + 1];

int calc(ll lim) {
	//printf("calc(%lld)\n", lim);
	assert((lim >> (MAXBIT + 1)) == 0);
	dp[MAXBIT + 1][0] = 1;
	for (int bit = MAXBIT; bit >= 0; --bit) {
		ll clim = lim >> bit;
		int mxsub = (int)min(clim, (ll)n);
		int want = (sum >> bit) & 1;
		REPE(sub, mxsub) {
			dp[bit][sub] = 0;
			int mxtake = min(clim - sub, (ll)n);
			REPE(take, mxtake) {
				if ((take & 1) != want) continue;
				ll nsub = clim / 2 - (clim - sub - take) / 2;
				assert(nsub <= n);
				dp[bit][sub] = (dp[bit][sub] + (ll)choose[n][take] * dp[bit + 1][nsub]) % MOD;
			}
			//printf("dp[%d][%d]=%d mylim=%lld\n", bit, sub, dp[bit][sub], clim - sub);
		}
	}
	return dp[0][0];
}

int solve() {
	REPE(i, n) { choose[i][0] = choose[i][i] = 1; FOR(j, 1, i) choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % MOD; }
	return (calc(hi) + MOD - calc(lo - 1)) % MOD;
}

void run() {
	scanf("%d%lld%lld%lld", &n, &lo, &hi, &sum);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}