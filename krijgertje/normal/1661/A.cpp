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

const int MAXN = 25;

int n;
int a[MAXN];
int b[MAXN];

ll dp[MAXN][2];

ll solve() {
	REP(i, n) REP(j, 2) dp[i][j] = LLONG_MAX;
	dp[0][0] = 0;
	REP(i, n-1) REP(j, 2) {
		int w = a[i], x = b[i];
		if (j == 1) swap(w, x);
		if (dp[i][j] == LLONG_MAX) continue;
		REP(k, 2) {
			int y = a[i + 1], z = b[i + 1];
			if (k == 1) swap(y, z);
			dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + abs(w - y) + abs(x - z));
		}
	}
	return min(dp[n - 1][0], dp[n - 1][1]);
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, n) scanf("%d", &b[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}