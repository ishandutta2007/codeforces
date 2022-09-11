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

const int MAXN = 250;
const int MAXLIM = 250;
const int MOD = 998244353;

int n, lim;

int dp[MAXLIM + 1][MAXN + 1];
int ndp[MAXLIM + 1][MAXN + 1];
int pw[MAXLIM + 1];

int inv[MAXN + 1];
int fac[MAXN + 1];
int ifac[MAXN + 1];

int solve() {
	inv[1] = 1; FORE(i, 2, n) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, n) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, n) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	if (n == 1) return 1;
	REPE(v, lim) REPE(cnt, n) dp[v][cnt] = 0;
	FORE(v, 1, lim) dp[v][1] = 1;
	REPE(v, lim) pw[v] = v;
	REP(i, n - 2) {
		REPE(v, lim) REPE(cnt, n) ndp[v][cnt] = 0;
		REPE(v, lim) REPE(cnt, n) if (dp[v][cnt] > 0) {
			ndp[v][cnt + 1] = (ndp[v][cnt + 1] + dp[v][cnt]) % MOD;
		}
		REPE(cnt, n) {
			int sum = 0;
			FORE(w, 1, lim) {
				sum = (sum + dp[w - 1][cnt]) % MOD;
				ndp[w][1] = (ndp[w][1] + (ll)sum * ifac[cnt]) % MOD;
			}
		}
		REPE(v, lim) REPE(cnt, n) dp[v][cnt] = (ll)ndp[v][cnt] * pw[lim - v + 1] % MOD;
		REPE(v, lim) pw[v] = (ll)pw[v] * v % MOD;
	}
	int ret = 0;
	REPE(v, lim) REPE(cnt, n) if (dp[v][cnt] > 0) ret = (ret + (ll)dp[v][cnt] * ifac[cnt]) % MOD;
	return (ll)ret * fac[n - 1] % MOD;
}

void run() {
	scanf("%d%d", &n, &lim);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}