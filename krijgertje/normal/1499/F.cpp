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

const int MAXN = 5000;
const int MOD = 998244353;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n, lim;
vector<int> adj[MAXN];

int par[MAXN];
void dfsinit(int at) {
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
	}
}

int dp[MAXN][MAXN];
int atpref[MAXN];
int topref[MAXN];
void dfscalc(int at) {
	REPE(i, lim) dp[at][i] = 0;
	inc(dp[at][0], 1);
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		dfscalc(to);
		/*
		int sum = 0; REPE(j, lim) inc(sum, dp[to][j]);
		for (int i = lim; i >= 0; --i) {
			int ways = dp[at][i];
			dp[at][i] = (ll)ways * sum % MOD;
			REP(j, lim) if (i + j + 1 <= lim) inc(dp[at][max(i, j + 1)], (ll)ways * dp[to][j] % MOD);
		}*/
		REPE(i, lim) { atpref[i] = dp[at][i]; if (i - 1 >= 0) inc(atpref[i], atpref[i - 1]); }
		REPE(i, lim) { topref[i] = dp[to][i]; if (i - 1 >= 0) inc(topref[i], topref[i - 1]); }
		REPE(i, lim) {
			int ways = 0;
			// cut
			ways = (ways + (ll)topref[lim] * dp[at][i]) % MOD;
			// no cut and longest root-path stayed same: i+j+1<=lim -> j<=lim-i-1
			if (i - 1 >= 0 && lim - i - 1 >= 0) ways = (ways + (ll)topref[min(i - 1, lim - i - 1)] * dp[at][i]) % MOD;
			// no cut and longest root-path increased: j+(i-1)+1<=lim -> j<=lim-i
			if (i - 1 >= 0 && lim - i >= 0) ways = (ways + (ll)atpref[min(i - 1, lim - i)] * dp[to][i - 1]) % MOD;
			dp[at][i] = ways;
		}
		//printf("\t%d->%d:", at + 1, to + 1); REPE(i, lim) printf(" %d", dp[at][i]); puts("");
	}
	//printf("%d:", at + 1); REPE(i, lim) printf(" %d", dp[at][i]); puts("");
}

int solve() {
	par[0] = -1; dfsinit(0);
	dfscalc(0);
	int ret = 0; REPE(i, lim) inc(ret, dp[0][i]); return ret;
}

void run() {
	scanf("%d%d", &n, &lim);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n", solve());
}


int main() {
	run();
	return 0;
}