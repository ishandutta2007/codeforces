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

const int MAXH = 100;
const int MAXW = 100;

int h, w;
int lft[MAXH][MAXW], rgt[MAXH][MAXW];

int dp[MAXW][MAXW]; // dp[l][r] = consider only segments completely inside [l..r]


int solve() {
	for (int l = w - 1; l >= 0; --l) FOR(r, l, w) {
		dp[l][r] = 0;
		FORE(m, l, r) {
			int cur = 0;
			if (l <= m - 1) cur += dp[l][m - 1];
			if (m + 1 <= r) cur += dp[m + 1][r];
			int cnt = 0;
			REP(i, h) if (lft[i][m] >= l && rgt[i][m] <= r) ++cnt;
			cur += cnt * cnt;
			dp[l][r] = max(dp[l][r], cur);
		}
		//printf("dp[%d][%d]=%d\n", l, r, dp[l][r]);
	}
	return dp[0][w - 1];
}

void run() {
	scanf("%d%d", &h, &w);
	REP(x, h) { int cnt; scanf("%d", &cnt); REP(i, cnt) { int l, r; scanf("%d%d", &l, &r); --l, --r; FORE(y, l, r) lft[x][y] = l, rgt[x][y] = r; } }
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}