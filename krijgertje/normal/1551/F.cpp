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
const int MOD = 1000000007;

int n, k;
vector<int> adj[MAXN];

int opt[MAXN][MAXN];
int dp[MAXN + 1];

void dfsopt(int at, int par, int tree,int dep) {
	++opt[tree][dep];
	for (int to : adj[at]) {
		if (to == par) continue;
		dfsopt(to, at, tree, dep + 1);
	}
}

int solve() {
	if (k == 1) return n;
	if (k == 2) return n * (n - 1) / 2;
	int ret = 0;
	REP(root, n) {
		for (int at : adj[root]) {
			REP(dep, n) opt[at][dep] = 0;
			dfsopt(at, root, at, 1);
		}
		FORE(d, 1, n - 1) {
			REPE(i, k) dp[i] = 0;
			dp[0] = 1;
			for (int at : adj[root]) {
				for (int i = k; i >= 1; --i) dp[i] = (dp[i] + (ll)opt[at][d] * dp[i - 1]) % MOD;
			}
			ret = (ret + dp[k]) % MOD;
		}
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &k);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n", solve());
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}