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

const int MAXN = 1000000;
const int MIN1 = 0;
const int PLUS1 = 1;
const int MIN2 = 2;
const int PLUS2 = 3;

int n;
int a[MAXN];
int ans[MAXN];

int dp[MAXN][4];
pair<int, int> prv[MAXN][4];

bool solve() {
	REP(i, n) REP(j, 4) dp[i][j] = INT_MAX, prv[i][j] = MP(-2, -2);
	auto relax = [&](int i, int j, int ni, int nj, int val) { if (val >= dp[ni][nj]) return; dp[ni][nj] = val; prv[ni][nj] = MP(i, j); };
	relax(-1, -1, 0, MIN1, INT_MIN);
	relax(-1, -1, 0, PLUS1, INT_MIN);
	relax(-1, -1, 0, MIN2, -a[0]);
	relax(-1, -1, 0, PLUS2, +a[0]);
	REP(i, n - 1) REP(j, 4) {
		if (prv[i][j] == MP(-2, -2)) continue;
		int mx = j == MIN1 ? -a[i] : j == PLUS1 ? +a[i] : dp[i][j];
		int lim = j == MIN2 ? -a[i] : j == PLUS2 ? +a[i] : dp[i][j];
		for (int sgn = -1; sgn <= +1; sgn += 2) {
			int v = sgn * a[i + 1];
			assert(v != mx && v != lim);
			if (v < lim) continue;
			if (v > mx) relax(i, j, i + 1, sgn == -1 ? MIN1 : PLUS1, lim);
			if (v < mx) relax(i, j, i + 1, sgn == -1 ? MIN2 : PLUS2, mx);
		}
	}
	REP(tj, 4) if (prv[n - 1][tj] != MP(-2, -2)) {
		int i = n - 1, j = tj;
		while (i >= 0) {
			ans[i] = j == MIN1 || j == MIN2 ? -a[i] : +a[i];
			tie(i, j) = prv[i][j];
		}
		return true;
	}
	return false;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}