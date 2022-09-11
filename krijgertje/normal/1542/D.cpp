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

const int MAXN = 500;
const int MOD = 998244353;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n;
char kind[MAXN]; int val[MAXN];

int solve() {
	int ret = 0;
	REP(i, n) if (kind[i] == '+') {
		vector<int> dp(1, 1);
		REP(j, n) {
			if (j == i) continue;
			if (kind[j] == '+' && (val[j] > val[i] || val[j] == val[i] && j > i)) { REPSZ(k, dp) inc(dp[k], dp[k]); continue; }
			vector<int> ndp = dp;
			if (kind[j] == '+') ndp.PB(0);
			REPSZ(k, dp) {
				if (kind[j] == '+') inc(ndp[k + 1], dp[k]);
				if (kind[j] == '-' && k > 0) inc(ndp[k - 1], dp[k]);
				if (kind[j] == '-' && k == 0 && j < i) inc(ndp[k], dp[k]);
			}
			dp = ndp;
		}
		int ways = 0;
		REPSZ(k, dp) inc(ways, dp[k]);
		//printf("%d: ways=%d\n", i, ways);
		ret = (ret + (ll)ways * val[i]) % MOD;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) { scanf(" %c", &kind[i]); if (kind[i] == '+') scanf("%d", &val[i]); }
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}