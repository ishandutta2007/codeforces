#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 3000;
const int MOD = 1000000007;

int n, mxsal;
int par[MAXN];

int inv[MAXN + 1];
int dp[MAXN][MAXN + 2];

void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
void mlt(int &a, int b) { a = (ll)a*b%MOD; }

int solve() {
	REP(i, n) FORE(j, 1, n + 1) dp[i][j] = 1;
	for (int i = n - 1; i >= 0; --i) {
		FORE(j, 2, n + 1) inc(dp[i][j], dp[i][j - 1]);
		if (par[i] != -1) FORE(j, 1, n + 1) mlt(dp[par[i]][j], dp[i][j]);
	}
	//FORE(j, 1, n + 1) printf("ways with mxsal=%d: %d\n", j, dp[0][j]);

	if (mxsal <= n + 1) return dp[0][mxsal];
	
	// sum(prod((x-xj)/(xi-xj))*yi)
	inv[1] = 1; FORE(i, 2, n) inv[i] = (ll)(MOD - MOD / i)*inv[MOD%i] % MOD;
	int ret = 0;
	FORE(i, 1, n + 1) {
		int cur = 1;
		FORE(j, 1, n + 1) if (i != j) {
			mlt(cur, mxsal - j);
			mlt(cur, i > j ? inv[i - j] : MOD - inv[j - i]);
		}
		ret = (ret + (ll)cur*dp[0][i]) % MOD;
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &mxsal);
	par[0] = -1; FOR(i, 1, n) scanf("%d", &par[i]), --par[i];
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}