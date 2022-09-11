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

const int MAXN = 100;

int n;
int cap[MAXN], init[MAXN];
double ans[MAXN + 1];

// cnt,bsum -> max asum

void relax(int& a, int b) { a = max(a, b); }
void solve() {
	int totinitsum = 0; REP(i, n) totinitsum += init[i];
	vector<vector<int>> dp(n + 1, vector<int>(totinitsum + 1, INT_MIN));
	relax(dp[0][0], 0);
	int cnt = 0, initsum = 0;
	REP(i, n) {
		for (int j = cnt; j >= 0; --j) REPE(k, initsum) {
			if (dp[j][k] == INT_MIN) continue;
			//printf("%d: (%d,%d)->(%d,%d) = %d\n", i, j, k, j + 1, k + init[i], dp[j][k] + cap[i]);
			relax(dp[j + 1][k + init[i]], dp[j][k] + cap[i]);
		}
		++cnt, initsum += init[i];
	}
	FORE(j, 1, cnt) {
		ans[j] = 0;
		REPE(k, initsum) {
			if (dp[j][k] == INT_MIN) continue;
			int curinit = k, curcap = dp[j][k];
			//printf("j=%d k=%d curinit=%d curcap=%d\n", j, k, curinit, curcap);
			double cur = min(0.5 * (totinitsum + curinit), 1.0 * curcap);
			ans[j] = max(ans[j], cur);
		}
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &cap[i], &init[i]);
	solve();
	FORE(i, 1, n) { if (i != 1) printf(" "); printf("%.15lf", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}