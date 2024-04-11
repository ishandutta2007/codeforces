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

const int MAXPICK = 2000;
const int MOD = 998244353;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret * x % MOD; if ((n >>= 1) == 0) return ret; x = (ll)x * x % MOD; } }
int calcinv(int x) { return pw(x, MOD - 2); }

int inv[MAXPICK + 1];
int ways[MAXPICK + 1][MAXPICK + 1]; // ways[i][j] = number of ways to create a sequence of length j consisting of values 1..i, such that each value is used at least once

void precalc() {
	inv[1] = 1; FORE(i, 2, MAXPICK) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	FORE(j, 1, MAXPICK) ways[1][j] = 1;
	FORE(i, 2, MAXPICK) {
		ways[i][1] = 0;
		FORE(j, 2, MAXPICK) ways[i][j] = ((ll)i * ways[i][j - 1] + (ll)i * ways[i - 1][j - 1]) % MOD;
	}
}

int nbag, nball, npick;

int solve() {
	int odd = (nball + 1) / 2, evn = nball / 2;
	int ret = 0;
	int mlt = 1 * 1 * pw(nball, nbag);
	int invnball = calcinv(nball);
	FORE(nuse, 1, npick) {
		if (nuse > nbag) continue;
		// choose(nbag,nuse)*(odd^nuse)*(nball^(nbag-nuse))*ways[nuse][npick]
		mlt = (ll)mlt * (nbag - nuse + 1) % MOD * inv[nuse] % MOD * odd % MOD * invnball % MOD;
		ret = (ret + (ll)mlt * ways[nuse][npick]) % MOD;
	}
	return ret;
}

void run() {
	scanf("%d%d%d", &nbag, &nball, &npick);
	printf("%d\n", solve());
}

int main() {
	precalc();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}