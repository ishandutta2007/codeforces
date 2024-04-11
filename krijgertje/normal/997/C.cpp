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

const int MAXN = 1000000;
const int MOD = 998244353;
int pw(int x, int n, int mod) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret*x%mod; if ((n >>= 1) == 0) return ret; x = (ll)x*x%mod; } }

int n;
int inv[MAXN + 1];
int fac[MAXN + 1];
int ifac[MAXN + 1];

int C(int n, int k) { if (k<0 || k>n) return 0; return (ll)fac[n] * ifac[k] % MOD*ifac[n - k] % MOD; }


void run() {
	inv[1] = 1; FORE(i, 2, MAXN) inv[i] = (ll)(MOD - MOD / i)*inv[MOD%i] % MOD;
	fac[0] = 1; FORE(i, 1, MAXN) fac[i] = (ll)fac[i - 1] * i%MOD;
	ifac[0] = 1; FORE(i, 1, MAXN) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	scanf("%d", &n);

	int ret = 0;
	REPE(ncols, n) {
		int cur;
		if (ncols == 0) {
			cur = pw((pw(3, n, MOD) + MOD - 3) % MOD, n, MOD);
		} else {
			cur = ((ll)3 * pw((pw(3, n - ncols, MOD) + MOD - 1), n, MOD) + (ll)(pw(3, ncols, MOD) + MOD - 3)*pw(pw(3, n - ncols, MOD), n, MOD)) % MOD;
		}
		cur = (ll)cur * C(n, ncols) % MOD;
		//printf("%d: %d\n", ncols, cur);
		if (ncols % 2 == 0) ret = (ret + cur) % MOD; else ret = (ret + MOD - cur) % MOD;
	}
	ret = (pw(pw(3, n, MOD), n, MOD) + MOD - ret) % MOD;
	printf("%d\n", ret);
}

int main() {
	run();
	return 0;
}