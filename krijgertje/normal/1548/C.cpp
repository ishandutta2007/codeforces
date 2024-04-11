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
const int MAXQ = 200000;
const int MOD = 1000000007;


int n, nq;
int qx[MAXQ];
int qans[MAXQ];

int inv[3 * MAXN + 1];
int fac[3 * MAXN + 1];
int ifac[3 * MAXN + 1];
int choose(int n, int k) { if (k<0 || k>n) return 0; return (ll)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD; }

int dp[3 * MAXN + 1][3]; // dp[x][k] = sum(i=0..n-1,C[3*i+k][x])

void solve() {
	inv[1] = 1; FORE(i, 2, 3 * n) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, 3 * n) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, 3 * n) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	dp[0][0] = dp[0][1] = dp[0][2] = n;
	FORE(x, 1, 3 * n) {
		dp[x][0] = ((ll)choose(3 * n, x + 1) + (MOD - dp[x - 1][1]) + 2 * (MOD - dp[x - 1][0])) * inv[3] % MOD;
		dp[x][1] = (dp[x - 1][0] + dp[x][0]) % MOD;
		dp[x][2] = (dp[x - 1][1] + dp[x][1]) % MOD;
	}

	REP(i, nq) { int x = qx[i]; qans[i] = (dp[x][0] + choose(3 * n, x)) % MOD; }
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, nq) scanf("%d", &qx[i]);
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}