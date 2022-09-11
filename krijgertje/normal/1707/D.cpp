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

const int MAXN = 2000;

int n, MOD;
vector<int> adj[MAXN];
int ans[MAXN];

int dp[MAXN][MAXN]; // dp[i][k] = ways for subtree i, assuming all values are in range 1..k, with k occurring at least once

int prod[MAXN];
int prefprodsum[MAXN][MAXN];
int suffprodsum[MAXN][MAXN];

void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

void dfs(int at, int par) {
	for (int to : adj[at]) {
		if (to == par) continue;
		dfs(to, at);
	}

	vector<int> ch;
	for (int to : adj[at]) {
		if (to == par) continue;
		ch.PB(to);
	}

	FORE(k, 1, n - 1) prod[k] = 1;
	FORE(k, 1, n - 1) prefprodsum[0][k] = 1;
	REPSZ(i, ch) {
		int to = ch[i];
		int sum = 0;
		FORE(k, 1, n - 1) {
			prod[k] = (ll)prod[k] * dp[to][k] % MOD;
			inc(sum, dp[to][k]);
			prefprodsum[i + 1][k] = (ll)prefprodsum[i][k] * sum % MOD;
		}
	}
	FORE(k, 1, n - 1) suffprodsum[SZ(ch)][k] = 1;
	for (int i = SZ(ch) - 1; i >= 0; --i) {
		int to = ch[i];
		int sum = 0;
		FORE(k, 1, n - 1) {
			inc(sum, dp[to][k]);
			suffprodsum[i][k] = (ll)suffprodsum[i + 1][k] * sum % MOD;
		}
	}
	
	FORE(k, 1, n - 1) {
		dp[at][k] = suffprodsum[0][k]; // we are k
	}
	REPSZ(i, ch) {
		int sum = 0;
		FORE(k, 1, n - 1) {
			int to = ch[i]; // to is k
			sum = (sum + (ll)prefprodsum[i][k - 1] * suffprodsum[i + 1][k - 1]) % MOD;
			if (k >= 2 && par != -1) dp[at][k] = (dp[at][k] + (ll)dp[to][k] * sum) % MOD;
		}
	}
	//printf("dp%d:", at + 1); FORE(k, 1, n - 1) printf(" %d", dp[at][k]); puts("");
}

int choose[MAXN + 1][MAXN + 1];

void solve() {
	REPE(i, n) { choose[i][0] = choose[i][i] = 1; FOR(j, 1, i) { choose[i][j] = choose[i - 1][j - 1]; inc(choose[i][j], choose[i - 1][j]); } }
	int root = 0;
	dfs(root, -1);
	FORE(k, 1, n - 1) {
		ans[k] = dp[root][k];
		FORE(i, 1, k - 1) ans[k] = (ans[k] + MOD - (ll)choose[k][i] * ans[i] % MOD) % MOD;
	}
}

void run() {
	scanf("%d%d", &n, &MOD);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	solve();
	FORE(i, 1, n - 1) { if (i != 1) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}