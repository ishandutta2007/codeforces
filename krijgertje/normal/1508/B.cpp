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

const int MAXN = 100000;
const ll MAXWANT = 1000000000000000000LL;

ll safeadd(ll a, ll b) { if (a >= LLONG_MAX - b) return LLONG_MAX; else return a + b; }
ll safemul(ll a, ll b) { if (b != 0 && a >= LLONG_MAX / b) return LLONG_MAX; else return a * b; }

int n; ll want;
int ans[MAXN];

int nans = 0;
vector<ll> dp;

void construct(int len, ll idx, int offset) {
	//printf("construct(%d,%lld,%d) [%d]\n", len, idx, offset, nans);
	if (len == 0) { assert(idx == 0 && offset == n && nans == n); return; }
	REP(j, len) {
		int sufflen = len - j - 1;
		ll ways = sufflen < SZ(dp) ? dp[sufflen] : LLONG_MAX;
		if (idx >= ways) { idx -= ways; continue; }
		REPE(k, j) ans[nans++] = offset + j - k;
		construct(sufflen, idx, offset + j + 1);
		return;
	}
	assert(false);
}

bool solve() {
	dp = vector<ll>(1, 1);
	while (dp.back() < LLONG_MAX) {
		int i = SZ(dp);
		dp.PB(0LL);
		REP(j, i) dp[i] = safeadd(dp[i], dp[i - j - 1]);
		//printf("dp[%d]=%lld\n", i, dp[i]);
	}
	if (n < SZ(dp) && want >= dp[n]) return false;

	nans = 0;
	construct(n, want, 0);
	return true;
}

void run() {
	scanf("%d%lld", &n, &want); --want;
	if (!solve()) { printf("-1\n"); return; }
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}