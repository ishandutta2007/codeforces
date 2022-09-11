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

const int MAXN = 200000;
const int MAXLIM = 20;
const int MAXVAL = 10000000;

int pmn[MAXVAL + 1];

void precalc() {
	REPE(i, MAXVAL) pmn[i] = -1;
	FORE(i, 2, MAXVAL) if (pmn[i] == -1) for (int j = i; j <= MAXVAL; j += i) if (pmn[j] == -1) pmn[j] = i;
}

int n, lim;
int a[MAXN];

int b[MAXN];
int c[MAXN], nc;
int d[MAXN];

int sum, cnt[MAXN];
int nxt[MAXN][MAXLIM + 1];

int dp[MAXN + 1][MAXLIM + 1];

int solve() {
	REP(i, n) {
		int x = a[i], y = 1;
		while (x != 1) { int p = pmn[x]; int cnt = 0; while (x % p == 0) x /= p, ++cnt; if (cnt % 2 == 1) y *= p; }
		b[i] = y;
	}
	//printf("b:"); REP(i, n) printf(" %d", b[i]); puts("");

	nc = 0; REP(i, n) c[nc++] = b[i]; sort(c, c + nc); nc = unique(c, c + nc) - c;
	REP(i, n) d[i] = lower_bound(c, c + nc, b[i]) - c;
	//printf("d:"); REP(i, n) printf(" %d", d[i]); puts("");

	REPE(k, lim) {
		sum = 0; REP(i, nc) cnt[i] = 0;
		int l = 0, r = 0;
		while (l < n) {
			assert(l <= r);
			while (r < n && sum + (cnt[d[r]] != 0 ? 1 : 0) <= k) sum += cnt[d[r]] != 0 ? 1 : 0, ++cnt[d[r]], ++r;
			nxt[l][k] = r;
			assert(l < r);
			sum -= cnt[d[l]] != 1 ? 1 : 0, --cnt[d[l]], ++l;
		}
	}

	REPE(i, n) REPE(k, lim) dp[i][k] = INT_MAX;
	dp[0][0] = 0;
	REPE(i, n) REPE(k, lim) {
		if (dp[i][k] == INT_MAX) continue;
		if (k + 1 <= lim) dp[i][k + 1] = min(dp[i][k + 1], dp[i][k]);
		if (i != n) REPE(kk, lim - k) { int ni = nxt[i][kk], nk = k + kk; dp[ni][nk] = min(dp[ni][nk], dp[i][k] + 1); }
	}
	return dp[n][lim];
}

void run() {
	scanf("%d%d", &n, &lim);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}


int main() {
	precalc();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}