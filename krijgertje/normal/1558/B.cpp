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

const int MAXN = 4000000;

int n, mod;

int dp[MAXN + 2];

void inc(int& a, int b) { if ((a += b) >= mod) a -= mod; }
void dec(int& a, int b) { inc(a, mod - b); }

int solve() {
	FORE(i, 1, n + 1) dp[i] = 0;
	inc(dp[1], 1);
	dec(dp[2], 1);
	FORE(i, 1, n) {
		//printf("dp[%d]=%d\n", i, dp[i]);
		inc(dp[i + 1], dp[i]);
		//printf("\t+ %d..%d\n", i + 1, n);
		inc(dp[i + 1], dp[i]);
		dec(dp[n + 1], dp[i]);
		for (int k = 2; k * i <= n; ++k) {
			//printf("\t*%d %d..%d\n", k, k * i, min(n + 1, k * (i + 1)) - 1);
			inc(dp[k * i], dp[i]);
			dec(dp[min(n + 1, k * (i + 1))], dp[i]);
		}
	}
	return dp[n];
}

void run() {
	scanf("%d%d", &n, &mod);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}