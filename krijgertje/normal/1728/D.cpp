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

const int MAXN = 2000;

char s[MAXN + 1]; int n;

int dp[MAXN][MAXN];

int compare(char a, char b) { return a < b ? +1 : a > b ? -1 : 0; }
int solve() {
	for (int len = 2; len <= n; len += 2) {
		REPE(l, n - len) {
			int r = l + len - 1;
			// l l+1
			int a = len >= 4 && dp[l + 2][r] != 0 ? dp[l + 2][r] : compare(s[l], s[l + 1]);
			// l r
			int b = len >= 4 && dp[l + 1][r - 1] != 0 ? dp[l + 1][r - 1] : compare(s[l], s[r]);
			// r l
			int c = len >= 4 && dp[l + 1][r - 1] != 0 ? dp[l + 1][r - 1] : compare(s[r], s[l]);
			// r r-1
			int d = len >= 4 && dp[l][r - 2] != 0 ? dp[l][r - 2] : compare(s[r], s[r - 1]);
			dp[l][r] = max(min(a, b), min(c, d));
		}
	}
	return dp[0][n - 1];
}

void run() {
	scanf("%s", s); n = strlen(s);
	int res = solve();
	printf("%s\n", res > 0 ? "Alice" : res < 0 ? "Bob" : "Draw");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}