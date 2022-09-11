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

const int MAXN = 14;
const int MOD = 1000000007;
int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret * x % MOD; if ((n >>= 1) == 0) return ret; x = (ll)x * x % MOD; } }
int calcinv(int x) { return pw(x, MOD - 2); }
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int& a, int b) { inc(a, MOD - b); }

int n;
int a[MAXN];

int pwin[MAXN][MAXN];
int ponecomp[1 << MAXN];
int bc[1 << MAXN];

int solve() {
	REP(i, n) REP(j, n) if (i != j) pwin[i][j] = (ll)a[i] * calcinv(a[i] + a[j]) % MOD;
	bc[0] = 0; FOR(mask, 1, 1 << n) bc[mask] = bc[mask >> 1] + (mask & 1);

	FOR(mask, 1, 1 << n) {
		ponecomp[mask] = 1;
		int oth = (1 << n) - mask - 1;
		for (int submask = (oth + 1) & mask; submask < mask; submask = (submask + oth + 1) & mask) {
			int cur = ponecomp[submask];
			REP(i, n) if (submask & (1 << i)) REP(j, n) if ((mask & (1 << j)) != 0 && (submask & (1 << j)) == 0) cur = (ll)cur * pwin[i][j] % MOD;
			dec(ponecomp[mask], cur);
		}
		//printf("%x: %d\n", mask, ponecomp[mask]);
	}

	int ret = 0;
	FOR(mask, 1, 1 << n) {
		int cur = ponecomp[mask];
		REP(i, n) if (mask & (1 << i)) REP(j, n) if ((mask & (1 << j)) == 0) cur = (ll)cur * pwin[i][j] % MOD;
		ret = (ret + (ll)cur * bc[mask]) % MOD;
	}
	return ret;
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