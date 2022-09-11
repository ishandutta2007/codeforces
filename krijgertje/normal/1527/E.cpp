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

const int MAXN = 35000;
const int MAXS = 4 * MAXN;

int n, npart;
int a[MAXN];

int last[MAXN];
int match[MAXN];

ll rsum[MAXN];
ll dp[MAXN];

ll sval[MAXS];
ll slazy[MAXS];
void sapply(int x, ll by) {
	sval[x] += by;
	slazy[x] += by;
}
void spush(int x) {
	if (slazy[x] != 0) sapply(2 * x + 1, slazy[x]), sapply(2 * x + 2, slazy[x]), slazy[x] = 0;
}
void sinit(int x, int l, int r) {
	slazy[x] = 0;
	if (l == r) {
		sval[x] = dp[l];
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		sval[x] = min(sval[2 * x + 1], sval[2 * x + 2]);
	}
}
void smod(int x, int l, int r, int L, int R, int BY) {
	if (L <= l && r <= R) {
		sapply(x, BY);
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (L <= m) smod(2 * x + 1, l, m, L, R, BY);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, BY);
		sval[x] = min(sval[2 * x + 1], sval[2 * x + 2]);
	}
}
ll sget(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return sval[x];
	} else {
		int m = l + (r - l) / 2; spush(x); ll ret = LLONG_MAX;
		if (L <= m) ret = min(ret, sget(2 * x + 1, l, m, L, R));
		if (m + 1 <= R) ret = min(ret, sget(2 * x + 2, m + 1, r, L, R));
		return ret;
	}
}

ll solve() {
	REP(i, n) last[i] = -1;
	REP(i, n) {
		int x = a[i];
		match[i] = last[x];
		last[x] = i;
	}

	REP(i, n) {
		rsum[i] = i == 0 ? 0 : rsum[i - 1];
		if (match[i] != -1) rsum[i] += i - match[i];
	}
	REP(i, n) dp[i] = rsum[i];
	//printf("dp:"); REP(i, n) printf(" %lld", dp[i]); puts("");
	REP(k, npart - 1) {
		sinit(0, 0, n - 1);
		REP(i, n) {
			if (match[i] != -1) smod(0, 0, n - 1, match[i], n - 1, -(i - match[i]));
			dp[i] = rsum[i] + min(0LL, sget(0, 0, n - 1, 0, i));
		}
		//printf("dp:"); REP(i, n) printf(" %lld", dp[i]); puts("");
	}
	return dp[n - 1];
}

void run() {
	scanf("%d%d", &n, &npart);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}