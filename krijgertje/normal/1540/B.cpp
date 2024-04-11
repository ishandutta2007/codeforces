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
const int MOD = 1000000007;
const int INV2 = (MOD + 1) / 2;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret * x % MOD; if ((n >>= 1) == 0) return ret; x = (ll)x * x % MOD; } }

int n;
vector<int> adj[MAXN];

int dp[MAXN + 1][MAXN + 1];

int par[MAXN], sz[MAXN];

vector<int> path;

void dfsinit(int at) {
	sz[at] = 1;
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
		sz[at] += sz[to];
	}
}

int dfscalc(int at) {
	int ret = 0;
	path.PB(at);
	if (at > path[0]) {
		REPSZ(i, path) {
			int cnt = sz[path[i]];
			if (i + 1 < SZ(path)) cnt -= sz[path[i + 1]];
			int cur = (ll)cnt * dp[i][SZ(path) - i - 1] % MOD;
			//printf("%d--%d--%d = %d (%d*%d)\n", path[0] + 1, path[i] + 1, at + 1, cur, cnt, dp[i][SZ(path) - i - 1]);
			inc(ret, cur);
		}
	}
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		int sub = dfscalc(to);
		inc(ret, sub);
	}
	path.pop_back();
	return ret;
}

int solve() {
	REPE(i, n) REPE(j, n) {
		if (i == 0 && j == 0) continue;
		if (i == 0) { dp[i][j] = 0; continue; }
		if (j == 0) { dp[i][j] = 1; continue; }
		dp[i][j] = (ll)(dp[i - 1][j] + dp[i][j - 1]) * INV2 % MOD;
	}
	int ret = 0;
	REP(i, n) {
		par[i] = -1; dfsinit(i);
		path.clear();
		int cur = dfscalc(i);
		inc(ret, cur);
	}
	ret = (ll)ret * pw(n, MOD - 2) % MOD;
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}