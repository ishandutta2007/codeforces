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

const int MAXN = 300000;
const int MAXDEP = 18; // for k>=2 ->  (1<<MAXDEP)-1<=MAXN

int n;
vector<int> adj[MAXN];
int par[MAXN];
int top[MAXN], ntop;

void dfsinit(int at) {
	top[ntop++] = at;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		par[to] = at; dfsinit(to);
	}
}

int jmx[MAXN]; // jmx[i] = maximum j for which i is a 1-ary heap of depth j
int kmx[MAXN][MAXDEP + 1]; // kmx[i][j] = maximum k for which i is a k-ary heap of depth j

void dfsjmx(int at) {
	jmx[at] = 1;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		dfsjmx(to);
		jmx[at] = max(jmx[at], jmx[to] + 1);
	}
}

int cur[MAXN], ncur;
void dfskmx(int at) {
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		dfskmx(to);
	}
	kmx[at][1] = n;
	FORE(j, 2, MAXDEP) {
		ncur = 0; REPSZ(i, adj[at]) { int to = adj[at][i]; if (to != par[at]) cur[ncur++] = kmx[to][j - 1]; }
		sort(cur, cur + ncur); reverse(cur, cur + ncur);
		kmx[at][j] = 0; REP(pos, ncur) if (cur[pos] >= pos + 1) kmx[at][j] = pos + 1;
	}
}

int dp[MAXN]; ll dpsum;
vector<pair<int, int> > e[MAXN + 1]; // e[k][idx]=(i,j) -> i is a kk-ary heap of depth j for kk<=k
void upddp(int at, int val) {
	while (at != -1 && val > dp[at]) {
		dpsum += val - dp[at]; dp[at] = val; at = par[at];
	}
}

void run() {
	scanf("%d", &n); REP(i, n-1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }

	par[0] = -1; ntop = 0; dfsinit(0);
	dfsjmx(0);
	dfskmx(0);
	
	ll ans = 0;
	REP(i, n) dp[i] = 0; dpsum = 0;
	REP(i, n) FORE(j, 1, MAXDEP) if (kmx[i][j] >= 2) e[kmx[i][j]].PB(MP(i, j));
	for (int k = n; k >= 2; --k) {
		REPSZ(idx, e[k]) {
			int i = e[k][idx].first, j = e[k][idx].second;
			upddp(i, j);
		}
		ans += dpsum;
	}
	REP(i, n) dp[i] = jmx[i];
	for (int i = n - 1; i >= 0; --i) { int at = top[i]; ans += dp[at]; if (par[at] != -1) dp[par[at]] = max(dp[par[at]], dp[at]); }
	printf("%lld\n", ans);
}

int main() {
	run();
	return 0;
}