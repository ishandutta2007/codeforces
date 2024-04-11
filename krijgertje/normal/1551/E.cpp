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

const int MAXN = 2000;

int n, want;
int a[MAXN];

int bal[MAXN];
int dp[MAXN];

int solve() {
	REP(i, n) bal[i] = i < a[i] ? -1 : i - a[i];
	REP(i, n) {
		if (bal[i] < 0) { dp[i] = 0; continue; }
		dp[i] = 1;
		REP(j, i) if (a[j] < a[i] && bal[j] <= bal[i]) dp[i] = max(dp[i], dp[j] + 1);
	}
	int ret = INT_MAX;
	REP(i, n) if (dp[i] >= want) ret = min(ret, bal[i]);
	return ret == INT_MAX ? -1 : ret;
}

void run() {
	scanf("%d%d", &n, &want);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}