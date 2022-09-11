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

const int MOD = 998244353;
const int MAXN = 1000000;
int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret * x % MOD; if ((n >>= 1) == 0) return ret; x = (ll)x * x % MOD; } }
int calcinv(int x) { return pw(x, MOD - 2); }

int inv[MAXN + 1];
int fac[MAXN + 1];
int ifac[MAXN + 1];
int choose(int n, int k) { if (k<0 || k>n) return 0; return (ll)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD; }

// number of ways to arrange x ones and y zeroes so that there are exactly k groups of each (cyclic) and the first character is a zero
int calcfirstfixed(int x, int y, int k) {
	if (x < k || y < k) return 0;
	if (k == 1) return y;

	// sum(i=1..y-k+1: i*choose(x-k+k-1,k-1)*choose(y-k-i+1+k-2,k-2))
	// =(y-k+1)*sum(i=1..y-k+1: choose(x-k+k-1,k-1)*choose(y-k-i+1+k-2,k-2))-sum(i=1..y-k+1: (y-k-i+1)*choose(x-k+k-1,k-1)*choose(y-k-i+1+k-2,k-2))
	// =(y-k+1)*sum(i=1..y-k+1: choose(x-k+k-1,k-1)*choose(y-k-i+1+k-2,k-2))-sum(i=1..y-k: (k-1)*choose(x-k+k-1,k-1)*choose(y-k-i+1+k-2,k-1))
	// =(y-k+1)*choose(x-k+k-1,k-1)*sum(i=0..y-k: choose(i+k-2,k-2))-(k-1)*choose(x-k+k-1,k-1)*sum(i=0..y-k-1: choose(i+k-1,k-1))
	// =(y-k+1)*choose(x-k+k-1,k-1)*choose(y-k+k-2+1,y-k)-(k-1)*choose(x-k+k-1,k-1)*choose(y-k-1+k-1+1,y-k-1)

	//int chk = 0; FORE(i, 1, y - k + 1) chk = (chk + (ll)i * choose(x - k + k - 1, k - 1) % MOD * choose(y - k - i + 1 + k - 2, k - 2)) % MOD; return chk;
	//int chk = 0; FORE(i, 1, y - k + 1) chk = (chk + (ll)(y - k + 1) * choose(x - k + k - 1, k - 1) % MOD * choose(y - k - i + 1 + k - 2, k - 2)) % MOD; FORE(i, 1, y - k + 1) chk = (chk + MOD - (ll)(y - k - i + 1) * choose(x - k + k - 1, k - 1) % MOD * choose(y - k - i + 1 + k - 2, k - 2) % MOD) % MOD; return chk;
	//int chk = 0; FORE(i, 1, y - k + 1) chk = (chk + (ll)(y - k + 1) * choose(x - k + k - 1, k - 1) % MOD * choose(y - k - i + 1 + k - 2, k - 2)) % MOD; FORE(i, 1, y - k) chk = (chk + MOD - (ll)(k - 1) * choose(x - k + k - 1, k - 1) % MOD * choose(y - k - i + 1 + k - 2, k - 1) % MOD) % MOD; return chk;
	//int chk = 0; REPE(i, y - k) chk = (chk + (ll)(y - k + 1) * choose(x - k + k - 1, k - 1) % MOD * choose(i + k - 2, k - 2)) % MOD; REPE(i, y - k - 1) chk = (chk + MOD - (ll)(k - 1) * choose(x - k + k - 1, k - 1) % MOD * choose(i + k - 1, k - 1) % MOD) % MOD; return chk;
	int a = (ll)(y - k + 1) * choose(x - k + k - 1, k - 1) % MOD * choose(y - k + k - 2 + 1, y - k) % MOD;
	int b = (ll)(k - 1) * choose(x - k + k - 1, k - 1) % MOD * choose(y - k - 1 + k - 1 + 1, y - k - 1) % MOD;
	return (a + MOD - b) % MOD;
}

// number of ways to arrange x ones and y zeroes so that there are exactly k groups of each (cyclic)
int calc(int x, int y, int k) {
	return (calcfirstfixed(x, y, k) + calcfirstfixed(y, x, k)) % MOD;
}

pair<int, int> calc(const vector<int> &sz) {
	int sum = 0; for (int x : sz) sum += x;
	int totways = fac[sum]; for (int x : sz) totways = (ll)totways * ifac[x] % MOD;
	//printf("totways=%d\n", totways);

	int ret = 0;
	for (int x : sz) {
		int othways = (ll)totways * ifac[sum] % MOD * fac[sum - x] % MOD * fac[x] % MOD;
		//printf("\tx=%d othways=%d\n", x, othways);
		FORE(k, 1, x) ret = (ret + (ll)k * calc(x, sum - x, k) % MOD * othways) % MOD;
	}

	return MP(ret, totways);
}

int n;
int a[MAXN];

int cnt[MAXN];

int solve() {
	REP(i, n) cnt[i] = 0;
	REP(i, n) ++cnt[a[i]];
	vector<int> sz;
	REP(i, n) if (cnt[i] > 0) sz.PB(cnt[i]);
	//printf("sz:"); REPSZ(i, sz) printf(" %d", sz[i]); puts("");
	if (SZ(sz) == 1) return 1;

	int g = 0;
	for (int x : sz) g = gcd(g, x);
	assert(g >= 1);
	//printf("g=%d\n", g);

	vector<int> w(g + 1, 0);
	vector<int> wsum(g + 1, 0);
	FORE(i, 1, g) if (g % i == 0) {
		w[i] = i - wsum[i];
		for (int j = i; j <= g; j += i) if (g % j == 0) wsum[j] += w[i];
	}
	int num = 0;
	int den = 0;
	FORE(i, 1, g) if (w[i] != 0) {
		vector<int> nsz = sz;
		REPSZ(j, nsz) nsz[j] /= i;
		pair<int, int> cur = calc(nsz);
		num = (num + (ll)w[i] * i % MOD * cur.first) % MOD;
		den = (den + (ll)w[i] * cur.second) % MOD;
	}
	return (ll)num * calcinv(den) % MOD;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	printf("%d\n", solve());
}

int main() {
	inv[1] = 1; FORE(i, 2, MAXN) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, MAXN) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, MAXN) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}