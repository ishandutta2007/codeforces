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

const int MAXN = 5000;
const int MOD = 998244353;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n, want;
char s[MAXN + 1];

int inv[MAXN + 1];
int fac[MAXN + 1];
int ifac[MAXN + 1];
int choose(int n, int k) { if (k<0 || k>n) return 0; return (ll)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD; }

int solve() {
	inv[1] = 1; FORE(i, 2, n) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, n) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, n) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	if (want == 0) return 1;
	int have = 0;
	REP(i, n) if (s[i] == '1') ++have;
	if (want > have) return 1;
	int cnt = 0;
	int ret = 1;
	for (int l = 0, r = 0; l < n; ++l) {
		while (r < n && (cnt < want || s[r] == '0')) cnt += s[r] == '1' ? 1 : 0, ++r;
		assert(l < r);
		int len = r - l, ones = cnt, zeroes = len - ones;
		if (s[l] == '0' && ones > 0) {
			--ones;
			inc(ret, choose(ones + zeroes, ones));
		}
		if (s[l] == '1' && zeroes > 0) {
			--zeroes;
			inc(ret, choose(ones + zeroes, ones));
		}
		if (s[l] == '1') --cnt;
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &want);
	scanf("%s", s);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}