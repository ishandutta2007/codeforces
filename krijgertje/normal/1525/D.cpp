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

const int MAXN = 5000;

int n;
int a[MAXN];

int b[MAXN], nb;
int c[MAXN], nc;

int dp[MAXN + 1][MAXN + 1];

int solve() {
	nb = nc = 0;
	REP(i, n) if (a[i] == 1) b[nb++] = i; else c[nc++] = i;
	assert(nb <= nc);

	auto relax = [&](int& val, int by) { val = min(val, by); };
	REPE(i, nb) REPE(j, nc) dp[i][j] = INT_MAX;
	relax(dp[0][0], 0);
	REPE(i, nb) REPE(j, nc) {
		int cur = dp[i][j];
		if (cur == INT_MAX) continue;
		if (j < nc) relax(dp[i][j + 1], cur);
		if (i < nb && j < nc) relax(dp[i + 1][j + 1], cur + abs(b[i] - c[j]));
	}
	return dp[nb][nc];
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}