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

const int MAXN = 200;

int n, MOD;

int inv[MAXN + 1];
int fac[MAXN + 1];
int ifac[MAXN + 1];

int solve() {
	inv[1] = 1; FORE(i, 2, MAXN) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, MAXN) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, MAXN) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	int lo = INT_MAX;
	FORE(a0, 1, n) FORE(k, 1, min(n, a0)) {
		int fixed = 0;
		FOR(i, k, n) fixed += max(a0 + 1, i + 2) - a0;
		if (fixed > a0) continue;
		lo = min(lo, a0);
		//printf("\tb:"); REP(i, n) if (i < k) printf(" ="); else printf(" %d", max(a0 + 1, i + 2)); printf(" [%d]\n", a0);
	}
	int mxlast = n + 1 - lo;
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(mxlast + 1, -1)));

	auto rec = [&](auto self, int rem, int sumlim, int last) {
		if (sumlim < 0) return 0;
		if (rem == 0) return fac[n];
		if (last < 0) return 0;
		int &ret = dp[rem][sumlim][last];
		if (ret == -1) {
			ret = 0;
			int mxzero = max(0, rem - last);
			REPE(nzero, mxzero) {
				ret = (ret + (ll)ifac[nzero] * self(self, rem - nzero, sumlim - (rem - nzero), last - 1)) % MOD;
			}
		}
		return ret;
	};

	int ret = 1;
	FORE(a0, 1, n) FORE(k, 1, min(n, a0)) {
		int fixed = 0;
		FOR(i, k, n) fixed += max(a0 + 1, i + 2) - a0;
		if (fixed > a0) continue;
		int cur = (ll)rec(rec, n - fixed, a0 - (n - fixed), n + 1 - a0 - 1) * ifac[fixed] % MOD;
		ret = (ret + cur) % MOD;
		//printf("\tb:"); REP(i, n) if (i < k) printf(" ="); else printf(" %d", max(a0 + 1, i + 2)); printf(" [%d] -> %d\n", a0, cur);
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &MOD);
	printf("%d\n", solve());
}

void research() {
	const int MOD = 1000000007;
	inv[1] = 1; FORE(i, 2, MAXN) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, MAXN) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, MAXN) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	FORE(n, 1, 200) {
		/*{
			int want = 0;
			REP(mask, 1 << (2 * n)) {
				int cnt = 0; REP(i, 2 * n) if (mask >> i & 1) ++cnt; if (cnt != n) continue;
				vector<int> a;
				int cur = 1;
				REP(i, 2 * n) if (mask >> i & 1) ++cur; else a.PB(cur);
				assert(SZ(a) == n && cur <= n + 1);
				bool ok = true;
				int sum = 0;
				REP(i, n) { sum += a[i]; if (a[0] * a[i] < sum) ok = false; }
				if (!ok) continue;
				int pref = 0; while (pref < n && a[pref] == a[0]) ++pref;
				//printf("\ta:"); REP(i, n) printf(" %d", a[i]); puts("");
				//printf("\tb:"); REP(i, n) if (i < pref) printf(" ="); else printf(" %d", max(a[0] + 1, i + 2)); puts("");
				int ways = fac[n]; for (int l = 0, r = l; l < n; l = r) { while (r < n && a[r] == a[l]) ++r; ways = (ll)ways * ifac[r - l] % MOD; } want += ways;
			}
			printf("%d: want=%d\n", n, want);
		}*/
		{
			int ways = 0;
			int lo = INT_MAX;
			FORE(a0, 1, n) FORE(k, 1, min(n, a0)) {
				int fixed = 0;
				FOR(i, k, n) fixed += max(a0 + 1, i + 2) - a0;
				if (fixed > a0) continue;
				++ways;
				lo = min(lo, a0);
				//printf("\tb:"); REP(i, n) if (i < k) printf(" ="); else printf(" %d", max(a0 + 1, i + 2)); printf(" [%d]\n", a0);
			}
			int mxlast = n + 1 - lo;
			printf("%d: ways=%d lo=%d\n", n, ways, lo);
			vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(mxlast + 1, -1)));

			auto rec = [&](auto self, int rem, int sumlim, int last) {
				if (sumlim < 0) return 0;
				if (rem == 0) return fac[n];
				if (last < 0) return 0;
				int &ret = dp[rem][sumlim][last];
				if (ret == -1) {
					ret = 0;
					int mxzero = max(0, rem - last);
					REPE(nzero, mxzero) {
						ret = (ret + (ll)ifac[nzero] * self(self, rem - nzero, sumlim - (rem - nzero), last - 1)) % MOD;
					}
				}
				return ret;
			};

			int have = 1;
			FORE(a0, 1, n) FORE(k, 1, min(n, a0)) {
				int fixed = 0;
				FOR(i, k, n) fixed += max(a0 + 1, i + 2) - a0;
				if (fixed > a0) continue;
				int cur = (ll)rec(rec, n - fixed, a0 - (n - fixed), n + 1 - a0 - 1) * ifac[fixed] % MOD;
				have = (have + cur) % MOD;
				//printf("\tb:"); REP(i, n) if (i < k) printf(" ="); else printf(" %d", max(a0 + 1, i + 2)); printf(" [%d] -> %d\n", a0, cur);
			}
			printf("have=%d\n", have);
		}
	}
}

int main() {
	run();
	//research();
	return 0;
}