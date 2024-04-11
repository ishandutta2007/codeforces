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

const int MAXN = 500;
const int MAXHEALTH = 500;
const int MOD = 998244353;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n, mxhealth;

int dp[MAXN + 1][MAXHEALTH];

int choose[MAXN + 1][MAXN + 1];
int pw[MAXHEALTH + 1][MAXN + 1];

int solve() {
	REPE(i, n) { choose[i][0] = choose[i][i] = 1; FOR(j, 1, i) choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % MOD; }
	FORE(i, 1, mxhealth) { pw[i][0] = 1; FORE(j, 1, n) pw[i][j] = (ll)pw[i][j - 1] * i % MOD; }

	FORE(cnt, 1, n) for (int dmg = mxhealth - 1; dmg >= 0; --dmg) {
		dp[cnt][dmg] = 0;
		if (cnt == 1) continue;
		REPE(kill, cnt) {
			int lo = 1, hi = min(cnt - 1, mxhealth - dmg);
			if (kill < cnt && dmg + cnt - 1 >= mxhealth) continue;
			int ways = (ll)choose[cnt][kill] * pw[hi - lo + 1][kill] % MOD;
			//printf("cnt=%d dmg=%d: kill=%d: %d * %d (%d..%d)\n", cnt, dmg, kill, choose[cnt][kill], pw[hi - lo + 1][kill], lo, hi);
			if (kill < cnt) {
				ways = (ll)ways * dp[cnt - kill][dmg + cnt - 1] % MOD;
				//printf("\t*%d\n", dp[cnt - kill][dmg + cnt - 1]);
			}
			inc(dp[cnt][dmg], ways);
		}
		//printf("-> dp[%d][%d]=%d\n", cnt, dmg, dp[cnt][dmg]);
	}
	return dp[n][0];
}

void run() {
	scanf("%d%d", &n, &mxhealth);
	printf("%d\n", solve());
}

void stress() {
	n = 3;
	for (mxhealth = 1; mxhealth <= 50; ++mxhealth) {
		int have = solve();
		int want = 0;
		FORE(a, 1, mxhealth) FORE(b, 1, mxhealth) FORE(c, 1, mxhealth) {
			int aa = a, bb = b, cc = c;
			while (true) {
				int alive = (aa > 0 ? 1 : 0) + (bb > 0 ? 1 : 0) + (cc > 0 ? 1 : 0);
				if (alive < 2) break;
				int dmg = alive - 1;
				aa = max(0, aa - dmg); bb = max(0, bb - dmg); cc = max(0, cc - dmg);
			}
			if (aa == 0 && bb == 0 && cc == 0) ++want;
			//printf("(%d,%d,%d) -> (%d,%d,%d)\n", a, b, c, aa, bb, cc);
		}
		printf("%d: have=%d want=%d\n", mxhealth, have, want);
	}
}

int main() {
	run();
	//stress();
	return 0;
}