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

const int MAXN = 1000000;
const int MOD = 1000000007;
const int INV2 = (MOD + 1) / 2;


int ntot, npos, mxval;

int inv[MAXN + 1];
int fac[MAXN + 1];
int ifac[MAXN + 1];
int invp2[MAXN + 1];
int choose(int n, int k) { if (k<0 || k>n) return 0; return (ll)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD; }

int solve() {
	inv[1] = 1; FORE(i, 2, ntot) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, ntot) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, ntot) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;
	invp2[0] = 1; FORE(i, 1, ntot) invp2[i] = (ll)invp2[i - 1] * INV2 % MOD;

	int nneg = ntot - npos;
	if (nneg == 0) return (ll)npos * mxval % MOD;
	int ret = 0;
	FORE(v, 1, npos) {
		int nleft = nneg - 1, ndown = npos - v;
		int ways = choose(nleft + ndown, nleft);
		int cur = (ll)ways * v % MOD * invp2[nleft + ndown + 1] % MOD;
		ret = (ret + cur) % MOD;
	}
	return (ll)ret * mxval % MOD;
}

void run() {
	scanf("%d%d%d", &ntot, &npos, &mxval);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}