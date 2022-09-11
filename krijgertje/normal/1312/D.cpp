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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 200000;
const int MAXVAL = 200000;
const int MOD = 998244353;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n, mxval;

int inv[MAXVAL + 1];
int fac[MAXVAL + 1];
int ifac[MAXVAL + 1];

int choose(int n, int k) { if (k < 0 || k > n) return 0; return (ll)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD; }

int solve() {
	inv[1] = 1; FORE(i, 2, mxval) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, mxval) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, mxval) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	if (n == 2) return 0;
	int ret = 0;
	FORE(vmx, 2, mxval) {
		int cur = choose(vmx - 1, n - 2);
		inc(ret, cur);
	}
	ret = (ll)ret * (n - 2) % MOD;
	REP(i, n - 3) ret = (ll)ret * 2 % MOD;
	return ret;
}

void run() {
	scanf("%d%d", &n, &mxval);
	printf("%d\n", solve());
}


int main() {
	run();
	return 0;
}