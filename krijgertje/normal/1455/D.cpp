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

const int MAXN = 500;

int n, x;
int a[MAXN];

int dp1[MAXN + 1][MAXN]; // dp1[pos][xpos] = minimum cost to be at position pos, with pos-1 unmoved, and current value of x initially in xpos
int dp2[MAXN + 1][MAXN + 1]; // dp2[pos][lastpos] = minimum cost to be at position pos, with original pos-1 currently in x, and last placed originally in lastpos (or x if lastpos==n)

int solve() {
	bool ok = true; REP(i, n - 1) if (a[i] > a[i + 1]) ok = false; if (ok) return 0;
		
	auto upd = [&](int& a, int b) { a = min(a, b); };
	REPE(pos, n) REP(xpos, n) dp1[pos][xpos] = INT_MAX;
	REPE(pos, n) REPE(lastpos, n) dp2[pos][lastpos] = INT_MAX;

	REP(i, n) {
		if (x < a[i] && (i == 0 || x >= a[i - 1])) upd(dp2[i + 1][n], 1);
		if (i - 1 >= 0 && a[i] < a[i - 1]) break;
	}
	REP(pos, n) {
		REP(xpos, n) {
			int cur = dp1[pos][xpos];
			if (cur == INT_MAX) continue;
			//printf("dp1[%d][%d]=%d\n", pos, xpos, cur);
			assert(pos >= 1);
			int alast = a[pos - 1], anow = a[pos], cx = a[xpos];
			if (anow >= alast) upd(dp1[pos + 1][xpos], cur);
			if (cx >= alast && cx < anow) upd(dp2[pos + 1][xpos], cur + 1);
		}
		REPE(lastpos, n) {
			int cur = dp2[pos][lastpos];
			if (cur == INT_MAX) continue;
			//printf("dp2[%d][%d]=%d\n", pos, lastpos, cur);
			assert(pos >= 1);
			int alast = lastpos == n ? x : a[lastpos], anow = a[pos], cx = a[pos - 1];
			if (anow >= alast) upd(dp1[pos + 1][pos - 1], cur);
			if (cx >= alast && cx < anow) upd(dp2[pos + 1][pos - 1], cur + 1);
		}
	}
	int ret = INT_MAX;
	REP(xpos, n) upd(ret, dp1[n][xpos]);
	REPE(lastpos, n) upd(ret, dp2[n][lastpos]);
	return ret == INT_MAX ? -1 : ret;
}

void run() {
	scanf("%d%d", &n, &x);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}