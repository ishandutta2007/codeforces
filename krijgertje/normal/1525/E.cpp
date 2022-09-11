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

const int MAXCITY = 20;
const int MAXPOINT = 50000;
const int MOD = 998244353;
int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret * x % MOD; if ((n >>= 1) == 0) return ret; x = (ll)x * x % MOD; } };
int calcinv(int x) { return pw(x, MOD - 2); }

int ncity, npoint;
int d[MAXCITY][MAXPOINT];

int opt[MAXCITY];

int solve() {
	int ret = 0;
	int fac = 1;
	FORE(j, 1, ncity) fac = (ll)fac * j % MOD;
	REP(i, npoint) {
		REP(j, ncity) opt[j] = d[j][i] - 1;
		sort(opt, opt + ncity);
		int ways = 1;
		REP(j, ncity) ways = (ll)ways * (opt[j] - j) % MOD;
		ret = (ret + (ll)fac + MOD - ways) % MOD;
		//printf("%d: %d\n", i, ways);
	}
	ret = (ll)ret * calcinv(fac) % MOD;
	return ret;
}

void run() {
	scanf("%d%d", &ncity, &npoint);
	REP(i, ncity) REP(j, npoint) scanf("%d", &d[i][j]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}