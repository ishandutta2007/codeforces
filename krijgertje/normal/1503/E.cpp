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

const int MAXDIM = 2021;
const int MOD = 998244353;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

int h, w;

int dp[MAXDIM + 1][MAXDIM + 1];
int dplft[MAXDIM][MAXDIM];
int dprgt[MAXDIM][MAXDIM];

int solve() {
	int ret = 0;
	REPE(j, MAXDIM) dp[0][j] = 1;
	FORE(i, 1, MAXDIM) {
		int sum = 0;
		REPE(j, MAXDIM) {
			inc(sum, dp[i - 1][j]);
			dp[i][j] = sum;
		}
	}
	REP(rep, 2) {
		REP(x, h) REP(y, w) {
			dplft[x][y] = (ll)dp[x][y] * dp[h - x - 1][y + 1] % MOD;
			dprgt[x][y] = (ll)dp[x][w - y] * dp[h - x - 1][w - y - 1] % MOD;
		}
		REP(ly, w-1) {
			int sum = 0;
			FOR(lx,1, h) {
				ret = (ret + (ll)dplft[lx][ly] * sum) % MOD;
				if (rep == 0) ret = (ret + (ll)dplft[lx][ly] * dprgt[lx - 1][ly + 1]) % MOD;
				inc(sum, dprgt[lx - 1][ly + 1]);
				/*REP(rx, lx) {
					int ry = ly + 1;
					if (rx == lx - 1 && rep == 1) continue;
					ret = (ret + (ll)dplft[lx][ly] * dprgt[rx][ry]) % MOD;
				}*/
			}
		}
		swap(h, w);
	}
	ret = (ll)ret * 2 % MOD;
	return ret;
}

void run() {
	scanf("%d%d", &h, &w);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}