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

const int MAXN = 5000;

int n;
int a[MAXN];

int dp[MAXN]; // dp[i] = max possible length of equal elements for a[0..i] given that a[i] cannot be deleted

int pref[MAXN][MAXN + 1];

int solve() {
	REP(v, n) { pref[v][0] = 0; REP(i, n) pref[v][i + 1] = pref[v][i] + (a[i] == v ? 1 : 0); }
	REP(i, n) dp[i] = INT_MIN;
	auto relax = [&](int& a, int b) { a = max(a, b); };
	int ret = INT_MIN;
	REPE(l, n) {
		int leader = 0, delta = 0;
		FORE(r, l, n) {
			int len = r - l, cnt = pref[leader][r] - pref[leader][l];
			if (len % 2 == 0 && cnt <= len / 2) {
				if (r == n) {
					if (l == 0) relax(ret, 0); else relax(ret, dp[l - 1]);
				} else {
					if (l == 0) relax(dp[r], 1); else if (a[r] == a[l - 1]) relax(dp[r], dp[l - 1] + 1);
				}
			}
			if (r == n) break; else if (a[r] == leader) ++delta; else if (delta >= 1) --delta; else leader = a[r], ++delta;
		}
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}