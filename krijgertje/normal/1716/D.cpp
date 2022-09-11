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

const int MAXN = 200000;
const int MOD = 998244353;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n, k;
int ans[MAXN + 1];

int dp[MAXN + 1];

void solve() {
	REPE(i, n) ans[i] = dp[i] = 0;
	inc(dp[0], 1);
	for (int step = k;; ++step) {
		bool any = false;
		REP(offset, step) {
			int sum = 0;
			for (int at = offset; at <= n; at += step) {
				int cur = dp[at];
				dp[at] = sum;
				inc(ans[at], sum);
				inc(sum, cur);
				if (cur != 0) any = true;
			}
		}
		if (!any) break;
	}
}

void run() {
	scanf("%d%d", &n, &k);
	solve();
	FORE(i, 1, n) { if (i != 1) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}