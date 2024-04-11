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

const int MOD = 1000000007;
const int MAXN = 100000;

int n, k;

int inv[MAXN + 1];
int fac[MAXN + 1];
int ifac[MAXN + 1];

void precalc() {
	inv[1] = 1; FORE(i, 2, MAXN) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, MAXN) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, MAXN) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;
}

int choose(int n, int k) { if (k<0 || k>n) return 0; assert(n <= MAXN); return (ll)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD; }
int invchoose(int n, int k) { if (k<0 || k>n) assert(false); assert(n <= MAXN); return (ll)ifac[n] * fac[k] % MOD * fac[n - k] % MOD; }

int solve() {
	int ret = 1;
	FORE(i, 1, n) {
		int rem = n - (i - 1) * (k - 1) - i;
		if (rem < 0) break;
		int slots = i + 1;
		int num = choose(rem + slots - 1, slots - 1);
		int invden = invchoose(n, i);
		ret = (ret + (ll)num * invden) % MOD;
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &k);
	printf("%d\n", solve());
}

int main() {
	precalc();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}