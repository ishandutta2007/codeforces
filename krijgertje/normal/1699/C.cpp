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
const int MOD = 1000000007;

int n;
int a[MAXN];

int pos[MAXN];

int inv[MAXN + 1];
int fac[MAXN + 1];
int ifac[MAXN + 1];
int choose(int n, int k) { if (k<0 || k>n) return 0; return (ll)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD; }

int solve() {
	inv[1] = 1; FORE(i, 2, n) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, n) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, n) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	REP(i, n) pos[a[i]] = i;
	int ret = 1;
	int l = pos[0], r = pos[0], mex = 1;
	while (mex < n) {
		int idx = pos[mex];
		int nl = min(l, idx), nr = max(r, idx);
		int nmex = mex;
		while (nmex < n && nl <= pos[nmex] && pos[nmex] <= nr) ++nmex;
		int cnt = nmex - mex - 1, places = (nr - nl + 1) - (mex + 1);
		ret = (ll)ret * choose(places, cnt) % MOD * fac[cnt] % MOD;
		//printf("%d->%d (%d choose %d)\n", mex, nmex, places, cnt);
		l = nl, r = nr, mex = nmex;
	}
	return ret;
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