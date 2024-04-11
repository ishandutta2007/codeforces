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

const int MAXN = 5000;
const int MOD = 998244353;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n;
int a[MAXN];

int dp[MAXN + 1][MAXN]; // dp[i][j] = #ways when i fishes shown so far, the biggest fish being j
int dpsum[MAXN + 1][MAXN+1]; // dpsum[i][j] = sum(k=0..j-1,dp[i][k])

int cnt[MAXN]; // cnt[i] = #small fishes when biggest fish shown is i

int solve() {
	sort(a, a + n);

	REP(i, n) { cnt[i] = i == 0 ? 0 : cnt[i - 1]; while (cnt[i] < i && 2 * a[cnt[i]] <= a[i]) ++cnt[i]; }

	FORE(i, 1, n) {
		dpsum[i][0] = 0;
		REP(j, n) {
			dp[i][j] = 0;
			// the last one was a small one
			if (i >= 2 && i - 1 < cnt[j] + 1) {
				int opt = cnt[j] + 1 - (i - 1);
				dp[i][j] = (dp[i][j] + (ll)opt * dp[i - 1][j]) % MOD;
			}
			// the last one was a big one
			if (i == 1) inc(dp[i][j], 1);
			//if (i >= 2) REP(k, j) if (2 * a[k] <= a[j]) inc(dp[i][j], dp[i - 1][k]);
			if (i >= 2) inc(dp[i][j], dpsum[i - 1][cnt[j]]);
			dpsum[i][j + 1] = dpsum[i][j];
			inc(dpsum[i][j + 1], dp[i][j]);
		}
	}
	int ret = 0;
	REP(j, n) inc(ret, dp[n][j]);
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}