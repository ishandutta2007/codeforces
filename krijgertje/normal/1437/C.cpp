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

int n;
int a[MAXN];

void upd(int& a, int b) { a = min(a, b); }

int solve() {
	sort(a, a + n);
	vector<int> opt;
	REP(i, n) FORE(d, -(n - 1), +(n - 1)) { int x = a[i] + d; if (x >= 1) opt.PB(x); }
	sort(opt.begin(), opt.end());
	opt.erase(unique(opt.begin(), opt.end()), opt.end());
	int nopt = SZ(opt);
	vector<vector<int>> dp(n + 1, vector<int>(nopt + 1, INT_MAX));
	dp[0][0] = 0;
	REPE(i, n) REPE(j, nopt) if (dp[i][j] != INT_MAX) {
		if (j < nopt) upd(dp[i][j + 1], dp[i][j]);
		if (i < n && j < nopt) upd(dp[i + 1][j + 1], dp[i][j] + abs(opt[j] - a[i]));
	}
	return dp[n][nopt];
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