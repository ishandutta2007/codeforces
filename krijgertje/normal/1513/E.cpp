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

const int MAXN = 100000;
const int MOD = 1000000007;

int n;
int a[MAXN];

int inv[MAXN + 1];
int fac[MAXN + 1];
int ifac[MAXN + 1];
int choose(int n, int k) { return (ll)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD; }

int solve() {
	inv[1] = 1; FORE(i, 2, n) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, n) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, n) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	ll sum = 0;
	REP(i, n) sum += a[i];
	if (sum % n != 0) return 0;
	int target = sum / n;
	int nx = 0, ny = 0, nz = 0;
	REP(i, n) if (a[i] < target) ++nx; else if (a[i] > target) ++ny; else ++nz;

	sort(a, a + n);
	int mlt = 1;
	for (int l = 0, r = l; l < n; l = r) {
		while (r < n && a[r] == a[l]) ++r;
		int cnt = r - l;
		if (a[l] != target) mlt = (ll)mlt * ifac[cnt] % MOD;
	}

	int ret;
	if (nx <= 1 || ny <= 1) {
		ret = (ll)fac[n] * ifac[nz] % MOD;
	} else {
		ret = (ll)2 * fac[nx] % MOD * fac[ny] % MOD * choose(n, nz) % MOD;
	}
	return (ll)ret * mlt % MOD;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}