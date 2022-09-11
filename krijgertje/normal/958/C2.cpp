#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 20000;
const int MAXPARTS = 50;
const int MAXMOD = 100;

int n, MOD, nparts;
int a[MAXN];

int dp[2][MAXPARTS][MAXMOD]; // dp[at][j][k] is maximum sum for j finished parts and a suffix with sum k

void upd(int &a, int b) { a = max(a, b); }
void run() {
	scanf("%d%d%d", &n, &nparts, &MOD);
	REP(i, n) scanf("%d", &a[i]);

	int at = 0; memset(dp[at], -1, sizeof(dp[at])); dp[at][0][0] = 0;
	REP(i, n) {
		memset(dp[1 - at], -1, sizeof(dp[1 - at]));
		REP(j, nparts) REP(k, MOD) if (dp[at][j][k] != -1) {
			//printf("%d: %d %d = %d\n", i, j, k, dp[at][j][k]);
			int nk = (k + a[i]) % MOD;
			upd(dp[1 - at][j][nk], dp[at][j][k]);
			if (j + 1 < nparts) upd(dp[1 - at][j + 1][0], dp[at][j][k] + nk);
		}
		at = 1 - at;
	}
	int ret = 0; REP(k, MOD) if (dp[at][nparts - 1][k] != -1) upd(ret, dp[at][nparts - 1][k] + k);
	printf("%d\n", ret);
}

int main() {
	run();
	return 0;
}