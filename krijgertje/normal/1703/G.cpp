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
const int MAXKEY = 30;

int n, keycost;
int a[MAXN];

ll dp[MAXN + 1][MAXKEY + 1];

ll solve() {
	REPE(k, MAXKEY) dp[n][k] = 0;
	for (int i = n - 1; i >= 0; --i) {
		REPE(k, MAXKEY) {
			// good
			dp[i][k] = dp[i + 1][k] + (a[i] >> k) - keycost;
			// bad
			dp[i][k] = max(dp[i][k], dp[i + 1][min(k + 1, MAXKEY)] + (a[i] >> (k + 1)));
		}
	}
	return dp[0][0];
}

void run() {
	scanf("%d%d", &n, &keycost);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}