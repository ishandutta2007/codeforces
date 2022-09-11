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

const int MAXN = 200000;
const int MAXVAL = 200000;
const int MOD = 1000000007;
const int MAXFAC = MAXN + MAXVAL;

int n;
int a[MAXN + 1];

int inv[MAXFAC + 1];
int fac[MAXFAC + 1];
int ifac[MAXFAC + 1];

int choose(int n, int k) { if (k<0 || k>n) return 0; return (ll)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD; }

int solve() {
	inv[1] = 1; FORE(i, 2, MAXFAC) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, MAXFAC) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, MAXFAC) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;
	int ret = 0;
	REPE(i, n) ret = (ret + choose(a[i] + i, i + 1)) % MOD;
	return ret;
}

void run() {
	scanf("%d", &n);
	REPE(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}