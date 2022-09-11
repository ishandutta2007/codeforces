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
const int MOD = 1000000007;
const int INV2 = (MOD + 1) / 2;

int dp[MAXN + 1][MAXN + 1];

void precalc() {
	REPE(a, MAXN) REPE(b, MAXN) {
		if (a == 0) { dp[a][b] = 0; continue; }
		if (b == 0) { dp[a][b] = a; continue; }
		dp[a][b] = (ll)INV2 * (dp[a - 1][b] + dp[a][b - 1]) % MOD;
	}
}

int ntot, npos, mxval;

int solve() {
	int ret = dp[npos][ntot - npos];
	ret = (ll)ret * mxval % MOD;
	return ret;
}

void run() {
	scanf("%d%d%d", &ntot, &npos, &mxval);
	printf("%d\n", solve());
}

int main() {
	precalc();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}