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

const int MAXN = 2000000;
const int MOD = 1000000007;

int dp[MAXN + 1];

void precalc() {
	dp[0] = dp[1] = dp[2] = 0, dp[3] = 4;
	FORE(i, 4, MAXN) {
		int a = (dp[i - 1] + (ll)2 * dp[i - 2]) % MOD;
		int b = (4 + dp[i - 2] + (ll)4 * dp[i - 3] + (ll)4 * dp[i - 4]) % MOD;
		//printf("%d: %d vs %d\n", i, a, b);
		//if (i % 3 == 1) assert(a == b);
		//if (i % 3 == 2) assert(a > b);
		//if (i % 3 == 0) assert(b > a);
		//dp[i] = max(a, b);
		dp[i] = i % 3 == 0 ? b : a;
	}
}

void run() {
	int n; scanf("%d", &n);
	printf("%d\n", dp[n]);
}

int main() {
	precalc();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}