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
const int MOD = 998244353;

int n;
char s[MAXN][3];

int l[MAXN], r[MAXN];

int inv[MAXN + 1];
int fac[MAXN + 1];
int ifac[MAXN + 1];
int choose(int n, int k) { if (k<0 || k>n) return 0; return (ll)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD; }

int calcequal() {
	inv[1] = 1; FORE(i, 2, n) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, n) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, n) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	int lzero = 0, lone = 0;
	REP(i, n) if (l[i] == 0) ++lzero; else if (l[i] == 1) ++lone;
	int rzero = 0, rone = 0;
	REP(i, n) if (r[i] == 0) ++rzero; else if (r[i] == 1) ++rone;
	int ret = 0;
	REPE(zero, n) {
		if (zero < lzero || zero < rzero) continue;
		if (zero > n - lone || zero > n - rone) continue;
		ret = (ret + (ll)choose(n - lzero - lone, zero - lzero) * choose(n - rzero - rone, zero - rzero)) % MOD;
	}
	return ret;
}

int calcsame() {
	int ret = 1;
	REP(i, n) {
		if (l[i] == -1 && r[i] == -1) { ret = (ll)2 * ret % MOD; continue; }
		if (l[i] != -1 && r[i] != -1 && l[i] != r[i]) return 0;
	}
	return ret;
}

int calccol(int col) {
	REP(i, n) if (l[i] == 1 - col || r[i] == 1 - col) return 0;
	return 1;
}

int solve() {
	REP(i, n) l[i] = s[i][0] == 'W' ? 0 : s[i][0] == 'B' ? 1 : -1;
	REP(i, n) r[i] = s[i][1] == 'B' ? 0 : s[i][1] == 'W' ? 1 : -1;
	return ((ll)calcequal() + (MOD - calcsame()) + calccol(0) + calccol(1)) % MOD;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%s", s[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}