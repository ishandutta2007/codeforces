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

const int MAXN = 50000;

int n;
int a[MAXN];
int want;

ll b[MAXN + 1];

int dp[MAXN + 1][3];

int solve() {
	b[0] = 0;
	REP(i, n) b[i + 1] = b[i] + a[i] - want;
	//printf("b:"); REPE(i, n) printf(" %lld", b[i]); puts("");

	REPE(i, n) REP(j, 3) dp[i][j] = INT_MIN;
	auto relax = [&](int &a, int b) { a = max(a, b); };
	dp[0][0] = 0;
	REP(i, n) REP(j, 3) {
		int cur = dp[i][j];
		if (cur == INT_MIN) continue;
		relax(dp[i + 1][0], cur);
		int nj = min(j + 1, 2);
		bool ok = true;
		FORE(k, 1, j) if (b[i + 1] < b[i - k]) ok = false;
		if (ok) relax(dp[i + 1][nj], cur + 1);
	}
	int ret = INT_MIN;
	REP(j, 3) relax(ret, dp[n][j]);
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	scanf("%d", &want);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}