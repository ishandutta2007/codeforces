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

const int MAXN = 200000;
const int MOD = 998244353;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret * x % MOD; if ((n >>= 1) == 0) return ret; x = (ll)x * x % MOD; } }

int n; ll npairs;

int inv[2 * MAXN + 1];
int fac[2 * MAXN + 1];
int ifac[2 * MAXN + 1];

int choose(int n, int k) { if (k<0 || k>n) return 0; return (ll)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD; }

int solve() {
	if (npairs >= n) return 0;
	inv[1] = 1; FORE(i, 2, 2 * n) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, 2 * n) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, 2 * n) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	int nzero = npairs;
	int npos = n - nzero;
	int ret = 0;
	REP(i, npos) {
		int cur = pw(npos - i, n);
		cur = (ll)cur * choose(npos, i) % MOD;
		if (i % 2 == 0) inc(ret, cur); else inc(ret, MOD - cur);
	}
	ret = (ll)ret * choose(n, npos) % MOD;
	if (nzero != 0) ret = (ll)ret * 2 % MOD;
	return ret;
}

void run() {
	scanf("%d%lld", &n, &npairs);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}