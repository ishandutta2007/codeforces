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

const int MAXN = 400;

int n, MOD;

int inv[MAXN + 1];
int fac[MAXN + 1];
int ifac[MAXN + 1];
int choose[MAXN + 1][MAXN + 1];

int ways[MAXN + 1];
int dp[MAXN + 2][MAXN + 2];

int solve() {
	inv[1] = 1; FORE(i, 2, n) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, n) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, n) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;
	memset(choose, 0, sizeof(choose));
	REPE(i, n) { choose[i][0] = choose[i][i] = 1; FOR(j, 1, i) choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % MOD; }

	memset(ways, 0, sizeof(ways));
	FORE(i, 1, n) {
		REP(j, i) {
			int a = j, b = i - j - 1;
			ways[i] = (ways[i] + choose[a + b][a]) % MOD;
		}
	}

	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	REP(i, n) REPE(j, i) {
		FORE(len, 1, n - i) {
			dp[i + len + 1][j + len] = (dp[i + len + 1][j + len] + (ll)dp[i][j] * ifac[len] % MOD * ways[len]) % MOD;
		}
	}

	int ret = 0;
	FORE(j, 1, n) {
		int cur = (ll)dp[n + 1][j] * fac[j] % MOD;
		ret = (ret + cur) % MOD;
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &MOD);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}