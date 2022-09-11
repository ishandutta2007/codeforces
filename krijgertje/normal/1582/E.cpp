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
const int MAXK = 450;

int n;
int a[MAXN];

ll asum[MAXN + 1];
ll dp[MAXN][MAXK + 1];

int solve() {
	reverse(a, a + n);
	asum[0] = 0; REP(i, n) asum[i + 1] = asum[i] + a[i];
	REP(i, n) FORE(k, 1, MAXK) {
		dp[i][k] = i == 0 ? 0 : dp[i - 1][k];
		if (k == 1) dp[i][k] = max(dp[i][k], (ll)a[i]);
		if (k >= 2 && i - k >= 0) {
			ll cur = asum[i + 1] - asum[i - k + 1];
			if (cur < dp[i - k][k - 1]) dp[i][k] = max(dp[i][k], cur);
		}
	}
	int ret = 0;
	REP(i, n) FORE(k, 1, MAXK) if (dp[i][k] != 0) ret = max(ret, k);
	return ret;
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