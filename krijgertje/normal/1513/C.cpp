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

const int MAXOP = 200000;
const int MOD = 1000000007;

int f[MAXOP + 1][10];

void precalc() {
	REP(k, 10) f[0][k] = 1;
	FORE(i, 1, MAXOP) REP(k, 10) f[i][k] = k != 9 ? f[i - 1][k + 1] : (f[i - 1][1] + f[i - 1][0]) % MOD;
}

int n, nop;

int solve() {
	int x = n;
	int ret = 0;
	while (x > 0) {
		int d = x % 10; x /= 10;
		ret = (ret + f[nop][d]) % MOD;
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &nop);
	printf("%d\n", solve());
}

int main() {
	precalc();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}