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

const int MAXN = 500000;
const int MAXMOD = 100;

int n, nparts, MOD;
int a[MAXN];

int sum[MAXN + 1];

// maximum #parts when reaching this position with cost at most ret
// -> we can reach position before with value at most sum[i] with cost ret and k-1 parts OR we can reach any position before with cost ret-1 and k-1 parts
int dp[2][MAXN + 1];

int bit[MAXMOD + 1];
void bclear() { REPE(i, MOD) bit[i] = -1; }
void bset(int idx, int val) { ++idx; while (idx <= MOD) { bit[idx] = max(bit[idx], val); idx += idx&-idx; } }
int bget(int idx) { ++idx; int ret = -1; while (idx > 0) { ret = max(ret, bit[idx]); idx -= idx&-idx; } return ret; }

void run() {
	scanf("%d%d%d", &n, &nparts, &MOD);
	REP(i, n) scanf("%d", &a[i]);

	sum[0] = 0; REP(i, n) sum[i + 1] = (sum[i] + a[i]) % MOD;
	//printf("sum:"); REPE(i, n) printf(" %d", sum[i]); puts("");

	int at = 0, ret;
	for (ret = 0; true; ++ret) {
		at = 1 - at;
		memset(dp[at], -1, sizeof(dp[at]));
		int mxcheaper = -1;
		bclear();
		REPE(i, n) {
			if (i == 0) dp[at][i] = max(dp[at][i], 0);
			if (ret != 0) dp[at][i] = max(dp[at][i], dp[1 - at][i]);
			if (mxcheaper != -1) dp[at][i] = max(dp[at][i], mxcheaper + 1);
			int mxsame = bget(sum[i]);
			//printf("\t%d: %d\n", i, mxsame);
			if (mxsame != -1) dp[at][i] = max(dp[at][i], mxsame + 1);
			bset(sum[i], dp[at][i]);
			mxcheaper = max(mxcheaper, dp[1 - at][i]);
		}
		//printf("%3d:", ret); REPE(i, n) printf(" %d", dp[at][i]); puts("");
		if (dp[at][n] >= nparts) break;
	}
	printf("%d\n", sum[n] + ret*MOD);
}

int main() {
	run();
	return 0;
}