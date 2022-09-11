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

const int MAXN = 200;

int n, mxchange;
char s[MAXN + 1];
char t[2 + 1];

int dp[MAXN + 1][MAXN + 1][MAXN + 1];

void upd(int& a, int b) { a = max(a, b); }
int solve() {
	char a = t[0], b = t[1];
	REPE(i, n) REPE(j, n) REPE(k, n) dp[i][j][k] = INT_MIN;
	dp[0][0][0] = 0;
	REPE(i, n) REPE(j, n) REPE(k, n) if (dp[i][j][k] != INT_MIN) {
		//printf("dp[%d][%d][%d]=%d\n", i, j, k, dp[i][j][k]);
		if (i >= n) break;
		if (s[i] != a && s[i] != b) { // keep non a/b
			upd(dp[i + 1][j][k], dp[i][j][k]);
		}
		{ // change to a
			upd(dp[i + 1][j + (s[i] != a ? 1 : 0)][k + 1], dp[i][j][k] + (a == b ? k : 0));
		}
		if (b != a) { // change to b
			upd(dp[i + 1][j + (s[i] != b ? 1 : 0)][k], dp[i][j][k] + k);
		}
		
	}
	int ret = INT_MIN;
	REPE(j, mxchange) REPE(k, n) if (dp[n][j][k] != INT_MIN) upd(ret, dp[n][j][k]);
	return ret;
}

void run() {
	scanf("%d%d", &n, &mxchange);
	scanf("%s", s); assert(strlen(s) == n);
	scanf("%s", t); assert(strlen(t) == 2);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}