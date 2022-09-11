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

const int MAXDIFF = 22;
const int MAXPERIOD = 2 * MAXDIFF;

int n, x, y;

int period;
int w[MAXPERIOD];

int dp[1 << MAXDIFF];
int ndp[1 << MAXDIFF];

int solve() {
	period = x + y;
	REP(i, period) w[i] = i >= n ? 0 : (n - i + period - 1) / period;
	//printf("w:"); REP(i, period) printf(" %d", w[i]); puts("");

	int mxdiff = max(x, y);
	REP(mask, 1 << mxdiff) dp[mask] = INT_MIN;
	dp[0] = 0;
	REP(i, period) {
		REP(mask, 1 << mxdiff) ndp[mask] = INT_MIN;
		REP(mask, 1 << mxdiff) {
			if (dp[mask] == INT_MIN) continue;
			REP(bit, 2) {
				if (bit == 1 && (((mask >> (x - 1)) & 1) != 0 || ((mask >> (y - 1)) & 1) != 0)) continue;
				int nmask = ((mask << 1) | bit) & ((1 << mxdiff) - 1);
				ndp[nmask] = max(ndp[nmask], dp[mask] + bit * w[i]);
			}
		}
		REP(mask, 1 << mxdiff) dp[mask] = ndp[mask];
	}
	int ret = INT_MIN;
	REP(mask, 1 << mxdiff) ret = max(ret, dp[mask]);
	return ret;
}

void run() {
	scanf("%d%d%d", &n, &x, &y);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}