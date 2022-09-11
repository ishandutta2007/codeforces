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

const int MAXN = 500;
const int MAXREM = MAXN - 1;

int n, len, mxrem;
int x[MAXN];
int v[MAXN];

int dp[MAXN][MAXREM + 1];
int ndp[MAXN][MAXREM + 1];

int solve() {
	auto relax = [&](int &a, int b) { a = min(a, b); };
	REP(i, n) REPE(j, mxrem) dp[i][j] = INT_MAX;
	relax(dp[0][0], 0);
	REP(at, n) {
		int d = (at + 1 == n ? len : x[at + 1]) - x[at];
		REP(i, n) REPE(j, mxrem) ndp[i][j] = INT_MAX;
		REP(i, n) REPE(j, mxrem) {
			int cur = dp[i][j];
			if (cur == INT_MAX) continue;
			int nval = cur + d * v[i];
			if (j + 1 <= mxrem) relax(ndp[i][j + 1], nval);
			if (at + 1 < n) relax(ndp[at + 1][j], nval); else relax(ndp[i][j], nval);
		}
		REP(i, n) REPE(j, mxrem) dp[i][j] = ndp[i][j];
	}
	int ret = INT_MAX;
	REP(i, n) REPE(j, mxrem) relax(ret, dp[i][j]);
	return ret;
}

void run() {
	scanf("%d%d%d", &n, &len, &mxrem);
	REP(i, n) scanf("%d", &x[i]);
	REP(i, n) scanf("%d", &v[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}