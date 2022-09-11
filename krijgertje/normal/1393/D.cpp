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

const int MAXH = 2000;
const int MAXW = 2000;

int h, w;
char g[MAXH][MAXW + 1];

int dp[MAXH][MAXW];

ll solve() {
	REP(x, h) REP(y, w) {
		dp[x][y] = 0;
		if (x - 1 >= 0 && y - 1 >= 0 && y + 1 < w && g[x - 1][y - 1] == g[x][y] && g[x - 1][y] == g[x][y] && g[x - 1][y + 1] == g[x][y]) {
			int lim = min(dp[x - 1][y], min(dp[x - 1][y - 1], dp[x - 1][y + 1])) + 1;
			if (x - 2 * lim >= 0 && g[x - 2 * lim][y] == g[x][y]) dp[x][y] = lim; else dp[x][y] = lim - 1;
		}
	}
	//REP(x, h) { printf("dp%d:", x); REP(y, w) printf(" %d", dp[x][y]); puts(""); }
	ll ret = 0; REP(x, h) REP(y, w) ret += dp[x][y] + 1; return ret;
}

void run() {
	scanf("%d%d", &h, &w);
	REP(x, h) scanf("%s", g[x]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}