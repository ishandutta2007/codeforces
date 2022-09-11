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

const int MAXDIM = 500;
const int MAXSTEP = 20;

int h, w, nstep;
int costrt[MAXDIM][MAXDIM - 1];
int costdn[MAXDIM - 1][MAXDIM];
int ans[MAXDIM][MAXDIM];

int dp[MAXDIM][MAXDIM][MAXSTEP / 2 + 1];

void solve() {
	if (nstep % 2 != 0) { REP(x, h) REP(y, w) ans[x][y] = -1; return; }
	REP(x, h) REP(y, w) dp[x][y][0] = 0;
	FORE(k, 1, nstep / 2) REP(x, h) REP(y, w) {
		dp[x][y][k] = INT_MAX;
		if (x - 1 >= 0) dp[x][y][k] = min(dp[x][y][k], dp[x - 1][y][k - 1] + costdn[x - 1][y]);
		if (x + 1 < h) dp[x][y][k] = min(dp[x][y][k], dp[x + 1][y][k - 1] + costdn[x][y]);
		if (y - 1 >= 0) dp[x][y][k] = min(dp[x][y][k], dp[x][y - 1][k - 1] + costrt[x][y - 1]);
		if (y + 1 < w) dp[x][y][k] = min(dp[x][y][k], dp[x][y + 1][k - 1] + costrt[x][y]);
	}
	REP(x, h) REP(y, w) ans[x][y] = 2 * dp[x][y][nstep / 2];
}

void run() {
	scanf("%d%d%d", &h, &w, &nstep);
	REP(x, h) REP(y, w - 1) scanf("%d", &costrt[x][y]);
	REP(x, h - 1) REP(y, w) scanf("%d", &costdn[x][y]);
	solve();
	REP(x, h) { REP(y, w) { if (y != 0) printf(" "); printf("%d", ans[x][y]); } puts(""); }
}

int main() {
	run();
	return 0;
}