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

int n;
int a[MAXN];

int inv[MAXN + 1];
int fac[MAXN + 1];
int ifac[MAXN + 1];
int choose(int n, int k) { if (k<0 || k>n) return 0; return (ll)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD; }

int solve() {
	FORE(i, 1, n) inv[i] = i == 1 ? 1 : (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	FORE(i, 0, n) fac[i] = i == 0 ? 1 : (ll)fac[i - 1] * i % MOD;
	FORE(i, 0, n) ifac[i] = i == 0 ? 1 : (ll)ifac[i - 1] * inv[i] % MOD;

	sort(a, a + n);
	reverse(a, a + n);
	if (a[0] == a[1]) return fac[n];
	if (a[0] >= a[1] + 2) return 0;
	int x = 0; REP(i, n) if (a[i] == a[1]) ++x;
	return (fac[n] + MOD - (ll)fac[x] * choose(n, x + 1) % MOD * fac[n - x - 1] % MOD) % MOD;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}