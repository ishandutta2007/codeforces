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

const int MAXN = 100;

int n, nmxforgood, ngood, MOD;

int C[MAXN + 1][MAXN + 1];
int dp[MAXN + 1][MAXN + 1][MAXN + 1]; // dp[i][j][k] = number of permutations of length i, such that there are k integers in it that have j different maximums

int solve() {
	REPE(i, n) { C[i][0] = C[i][i] = 1; FOR(j, 1, i) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD; }
	REPE(i, n) REPE(j, nmxforgood) REPE(k, ngood) dp[i][j][k] = 0;
	REPE(j, nmxforgood) dp[0][j][0] = 1;
	FORE(i, 1, n) {
		dp[i][0][0] = (ll)i * dp[i - 1][0][0] % MOD;
		FORE(j, 1, nmxforgood) REPE(k, max(0, i - (j - 1))) {
			int ck = k - (j == 1 ? 1 : 0);
			if (ck < 0) continue;
			REP(pos, i) {
				int li = pos, ri = i - pos - 1;
				int llim = max(0, li - (j - 2)), rlim = max(0, ri - (j - 2));
				// 0<=lk<=llim, rk=ck-lk, 0<=rk<=rlim -> lk<=ck ck-rlim<=lk
				FORE(lk, max(0, ck - rlim), min(llim, ck)) {
					int rk = ck - lk;
					//if (i == 3 && j == 1 && k == 1) printf("here pos=%d lk=%d rk=%d -> %d*%d\n", pos, lk, rk, dp[li][j - 1][lk], dp[ri][j - 1][rk]);
					dp[i][j][k] = (dp[i][j][k] + (ll)dp[li][j - 1][lk] * dp[ri][j - 1][rk] % MOD * C[li + ri][li]) % MOD;
				}
			}
			//if (dp[i][j][k] != 0) printf("dp[%d][%d][%d]=%d\n", i, j, k, dp[i][j][k]);
		}
	}
	return dp[n][nmxforgood][ngood];
}

void run() {
	scanf("%d%d%d%d", &n, &nmxforgood, &ngood, &MOD);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}