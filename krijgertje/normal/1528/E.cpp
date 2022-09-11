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

const int MAXN = 1000000;
const int MOD = 998244353;
const int INV2 = (MOD + 1) / 2;
const int INV6 = (MOD + 1) / 6;

int n;


int dp[MAXN + 1]; // dp[i] = number of downward trees of length i with root at most deg 2
int dpsum[MAXN + 1]; // dpsum[i] = number of downward trees of length at most i with root at most deg 2

int chooserep(int n, int k) {
	int ret = 1;
	REP(i, k) ret = (ll)ret * (n - 1 + k - i) % MOD;
	if (k == 2) ret = (ll)ret * INV2 % MOD; else if (k == 3) ret = (ll)ret * INV6 % MOD; else assert(false);
	return ret;
}

int solve() {
	if (n == 1) return 5;
	dp[0] = 1;
	dpsum[0] = 1;
	dp[1] = 2;
	dpsum[1] = 3;
	FORE(i, 2, n) {
		dp[i] = (chooserep(dpsum[i - 1] + 1, 2) + MOD - chooserep(dpsum[i - 2] + 1, 2)) % MOD;
		dpsum[i] = (dpsum[i - 1] + dp[i]) % MOD;
	}
	//REPE(i, min(20, n)) printf("dp[%d]=%d dpsum[%d]=%d\n", i, dp[i], i, dpsum[i]);

	int ret = 0;
	int onlytree = (chooserep(dpsum[n - 1] + 1, 3) + MOD - chooserep(dpsum[n - 2] + 1, 3)) % MOD;
	//printf("onlytree=%d\n", onlytree);
	ret = (ret + (ll)2 * onlytree + MOD - 1) % MOD;
	FORE(before, 1, n - 2) {
		int after = n - before - 1;
		int a = (dp[before] + MOD - dp[before - 1]) % MOD;
		int b = (dp[after] + MOD - 1) % MOD;
		//if (before <= 20) printf("(%d,1,%d) -> %d*%d\n", before, after, a, b);
		ret = (ret + (ll)a * b) % MOD;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}