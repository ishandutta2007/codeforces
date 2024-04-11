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

const int MAXN = 1000;
const int MAXB = 1000;
const int MAXLIM = 1000000;
const int MAXCOST = 12;

int n, lim;
int b[MAXN];
int c[MAXN];

int cost[MAXB + 1];

void precalc() {
	FORE(i, 1, MAXB) cost[i] = INT_MAX;
	cost[1] = 0;
	FORE(i, 1, MAXB) {
		FORE(x, 1, i) {
			int ni = i + i / x;
			if (ni <= MAXB) cost[ni] = min(cost[ni], cost[i] + 1);
		}
	}
	//int mxcost = 1; FORE(i, 1, MAXB) mxcost = max(mxcost, cost[i]); printf("mxcost=%d\n", mxcost);
}



int solve() {
	vector<vector<int>> bycost(MAXCOST + 1);
	REP(i, n) bycost[cost[b[i]]].PB(c[i]);
	int sumcost = 0;
	REP(i, n) sumcost += cost[b[i]];
	//printf("lim=%d\n", lim);
	//REP(i, n) printf("cost %d gain %d\n", cost[b[i]], c[i]);

	int upto = min(lim, sumcost);
	vector<int> dp(upto + 1, INT_MIN);
	int sumfree = 0;
	for (int x : bycost[0]) sumfree += x;
	dp[0] = sumfree;
	FORSZ(c, 1, bycost) {
		for (int x : bycost[c]) {
			for (int i = upto; i >= c; --i) dp[i] = max(dp[i], dp[i - c] + x);
		}
	}
	int ret = 0;
	REPE(i, upto) ret = max(ret, dp[i]);
	return ret;
}

void run() {
	scanf("%d%d", &n, &lim);
	REP(i, n) scanf("%d", &b[i]);
	REP(i, n) scanf("%d", &c[i]);
	printf("%d\n", solve());
}

int main() {
	precalc();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}