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

const int MAXN = 3000;

int n;
int a[MAXN];

int dp[MAXN][MAXN];

int b[MAXN];

int sum[MAXN + 1][MAXN];

void upd(int& a, int b) { a = min(a, b); }
int solve() {
	REP(i, n) b[i] = i + a[i];
	REP(i, n) REP(j, n) dp[i][j] = INT_MAX;
	upd(dp[0][0], 0);
	REPE(i, n) REP(j, n) sum[i][j] = 0;
	REP(i, n) REP(j, n) if (b[i] >= j) ++sum[i + 1][j];
	REP(i, n) REP(j, n) sum[i + 1][j] += sum[i][j];
	//REP(j, n) { printf("sum[*][%d]", j); REPE(i, n) printf(" %d", sum[i][j]); puts(""); }
	REP(i, n) REP(j, n) {
		int cur = dp[i][j];
		if (cur == INT_MAX) continue;
		//printf("dp[%d][%d]=%d\n", i, j, cur);
		if (j + 1 < n) upd(dp[i][j + 1], cur);
		if (j + 1 < n && j + 1 <= b[i]) {
			//int cnt = 0; FORE(k, i + 1, j) if (b[k] >= j + 1) ++cnt;
			int chk = sum[j + 1][j + 1] - sum[i + 1][j + 1];
			//printf("i=%d j=%d cnt=%d chk=%d\n", i, j, cnt, chk);
			//assert(cnt == chk);
			upd(dp[j + 1][b[i]], cur + chk);
		}
	}
	return dp[n - 1][n - 1];
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}