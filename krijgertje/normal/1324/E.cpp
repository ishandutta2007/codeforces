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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 2000;

int n, mod, lgood, rgood;
int a[MAXN];

int b[MAXN];

int dp[MAXN + 1][MAXN + 1];
void upd(int& a, int b) { a = max(a, b); }

int solve() {
	REP(i, n) b[i] = ((i == 0 ? 0 : b[i - 1]) + a[i]) % mod;
	//printf("b:"); REP(i, n) printf(" %d", b[i]); puts("");

	REPE(i, n) REPE(j, n) dp[i][j] = INT_MIN;
	dp[0][0] = 0;
	REP(i, n) REPE(j, i) if (dp[i][j] != INT_MIN) REP(k, 2) {
		int cur = ((b[i] - (j + k)) % mod + mod) % mod;
		int nval = dp[i][j] + (lgood <= cur && cur <= rgood ? 1 : 0);
		upd(dp[i + 1][j + k], nval);
	}
	int ret = INT_MIN; REPE(j, n) upd(ret, dp[n][j]); return ret;
}

void run() {
	scanf("%d%d%d%d", &n, &mod, &lgood, &rgood);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}


int main() {
	run();
	return 0;
}