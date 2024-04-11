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

const int MAXN = 400;
const int MOD = 998244353;

int n, m;
vector<int> adj[MAXN];
int ans[MAXN][MAXN];

int d[MAXN][MAXN];


int calc(int a, int b) {
	int cnt = 0;
	int ret = 1;
	REP(i, n) {
		if (d[a][i] + d[b][i] == d[a][b]) { ++cnt; continue; }
		int cur = 0;
		for (int j : adj[i]) if (d[a][i] == d[a][j] + 1 && d[b][i] == d[b][j] + 1) ++cur;
		//printf("calc(%d,%d) %d -> %d\n", a + 1, b + 1, i + 1, cur);
		ret = (ll)ret * cur % MOD;
	}
	if (cnt != d[a][b] + 1) return 0;
	return ret;
}

void solve() {
	REP(i, n) REP(j, n) d[i][j] = i == j ? 0 : INT_MAX;
	REP(at, n) for (int to : adj[at]) d[at][to] = min(d[at][to], 1);
	REP(k, n) REP(i, n) REP(j, n) if (d[i][k] != INT_MAX && d[k][j] != INT_MAX) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	//REP(i, n) { REP(j, n) { if (j != 0) printf(" "); printf("%d", d[i][j]); } puts(""); }

	REP(i, n) REPE(j, i) ans[i][j] = ans[j][i] = calc(i, j);
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b), adj[b].PB(a); }
	solve();
	REP(i, n) { REP(j, n) { if (j != 0) printf(" "); printf("%d", ans[i][j]); } puts(""); }
}

int main() {
	run();
	return 0;
}