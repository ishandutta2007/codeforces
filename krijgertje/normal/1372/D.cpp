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

int n;
int val[MAXN];

void upd(ll& a, ll b) { a = max(a, b); }
ll dp[MAXN][2][2][2]; // dp[i][a][b][c] = after considering items [0..i], having taking the first iff a==1 and the last iff b==1 and taken two consecutive iff c==1

ll solve() {
	if (n == 1) return val[0];
	REP(i, n) REP(a, 2) REP(b, 2) REP(c, 2) dp[i][a][b][c] = LLONG_MIN;
	dp[0][0][0][0] = 0;
	dp[0][1][1][0] = val[0];
	FOR(i, 1, n) REP(a, 2) REP(b, 2) REP(c, 2) {
		ll cur = dp[i - 1][a][b][c]; if (cur == LLONG_MIN) continue;
		if (b == 1) upd(dp[i][a][0][c], cur + 0);
		if (b == 0) upd(dp[i][a][1][c], cur + val[i]);
		if (b == 1 && c == 0) upd(dp[i][a][1][1], cur + val[i]);
	}
	ll ret = LLONG_MIN;
	REP(a, 2) REP(b, 2) REP(c, 2) {
		ll cur = dp[n - 1][a][b][c]; if (cur == LLONG_MIN) continue;
		if (a == 0 && b == 0) continue;
		if (a == 1 && b == 1 && c == 1) continue;
		if (!(a == 1 && b == 1) && c == 0) continue;
		upd(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &val[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}