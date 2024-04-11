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

const int MOD = 998244353;
const int ALPH = 26;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int& a, int b) { inc(a, MOD - b); }

int n;
int have[ALPH];

int solve() {
	int ways[3]; ways[0] = ALPH - 2, ways[1] = 1, ways[2] = 1;
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(3, 0)));
	inc(dp[0][0][0], 1);
	REP(at, n) {
		vector<vector<vector<int>>> ndp(n + 1, vector<vector<int>>(n + 1, vector<int>(3, 0)));
		bool needdiff = at != 0 && at != n / 2;
		REPE(i, n) REPE(j, n) REP(k, 3) {
			int cur = dp[i][j][k];
			if (cur == 0) continue;
			REP(kk, 3) {
				int ii = i + (kk == 1 ? 1 : 0);
				int jj = j + (kk == 2 ? 1 : 0);
				int mlt = ways[kk] - (needdiff && kk == k ? 1 : 0);
				inc(ndp[ii][jj][kk], (ll)cur * mlt % MOD);
			}
		}
		swap(dp, ndp);
	}
	vector<vector<int>> sum(n + 1, vector<int>(n + 1, 0));
	REPE(i, n) REPE(j, n) REP(k, 3) inc(sum[i][j], dp[i][j][k]);
	REPE(i, n) for (int j = n - 1; j >= 0; --j) inc(sum[i][j], sum[i][j + 1]);
	REPE(j, n) for (int i = n - 1; i >= 0; --i) inc(sum[i][j], sum[i + 1][j]);
	//REPE(i, n) { printf("sum%d:", i); REPE(j, n) printf(" %d", sum[i][j]); puts(""); }

	int ret = sum[0][0];
	REP(i, ALPH) if (have[i] < n) dec(ret, sum[have[i] + 1][0]);
	REP(i, ALPH) FOR(j, i + 1, ALPH) if (have[i] < n && have[j] < n) inc(ret, sum[have[i] + 1][have[j] + 1]);
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, ALPH) scanf("%d", &have[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}