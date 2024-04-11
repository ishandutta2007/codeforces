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

const int MAXN = 100000;

int n;
vector<int> adj[MAXN];

int d[MAXN], prv[MAXN];
int q[MAXN], qhead, qtail;
int farthest(int s) {
	REP(i, n) d[i] = INT_MAX, prv[i] = -2; qhead = qtail = 0;
	d[s] = 0, prv[s] = -1, q[qhead++] = s;
	while (qtail < qhead) { int at = q[qtail++]; REPSZ(i, adj[at]) { int to = adj[at][i]; if (d[to] != INT_MAX) continue; d[to] = d[at] + 1, prv[to] = at, q[qhead++] = to; } }
	return q[qhead - 1];
}

int ans[MAXN];
int cnt[MAXN + 1];
bool onpath[MAXN];
int dfs(int at, int par) {
	int ret = 0; bool any = false;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par) continue; else any = true;
		int cur = dfs(to, at);
		ret = max(ret, cur);
	}
	if (!any) { ++cnt[1]; return 1; }
	--cnt[ret], ++ret, ++cnt[ret]; return ret;
}

void run() {
	scanf("%d", &n); REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }

	int u = farthest(0), v = farthest(u);
	ans[1] = 1, ans[2] = d[v] + 1;
	
	REPE(i, n) cnt[i] = 0;
	REP(i, n) onpath[i] = false;
	for (int x = v; x != -1; x = prv[x]) onpath[x] = true;
	REP(at, n) if (onpath[at]) REPSZ(i, adj[at]) { int to = adj[at][i]; if (onpath[to]) continue; dfs(to, at); }
	int at = 3;
	for (int i = n; i >= 0; --i) REP(j, cnt[i]) ans[at] = ans[at - 1] + i, ++at;
	while (at <= n) ans[at] = ans[at - 1], ++at;

	FORE(i, 1, n) { if (i != 1) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}