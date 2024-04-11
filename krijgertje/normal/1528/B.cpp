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

int n;

int pmn[MAXN + 1];
int dv[MAXN + 1];

int dp[MAXN + 1];

int solve() {
	REPE(i, n) pmn[i] = -1;
	FORE(i, 2, n) if (pmn[i] == -1) for (int j = i; j <= n; j += i) if (pmn[j] == -1) pmn[j] = i;
	dv[1] = 1;
	FORE(i, 2, n) {
		int p = pmn[i];
		int j = i, cnt = 0;
		while (pmn[j] == p) j /= p, ++cnt;
		dv[i] = dv[j] * (cnt + 1);
	}
	//REPE(i, n) printf("%d: %d\n", i, dv[i]);

	dp[0] = 1;
	int sum = 1;
	FORE(i, 1, n) {
		dp[i] = (sum + dv[i] - 1) % MOD;
		sum = (sum + dp[i]) % MOD;
	}
	return dp[n];
}

void run() {
	scanf("%d", &n);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}