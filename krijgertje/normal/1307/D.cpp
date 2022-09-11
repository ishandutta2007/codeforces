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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 200000;

int n, m, nspecial;
bool isspecial[MAXN];
vector<int> adj[MAXN];

int q[MAXN], qhead, qtail;

void bfs(int s, int* d) {
	qhead = qtail = 0; REP(i, n) d[i] = INT_MAX;
	d[s] = 0; q[qhead++] = s;
	while (qtail < qhead) { int at = q[qtail++]; REPSZ(i, adj[at]) { int to = adj[at][i]; if (d[to] == INT_MAX) d[to] = d[at] + 1, q[qhead++] = to; } }
}

int ds[MAXN];
int dt[MAXN];
pair<int, int> p[MAXN]; int np;

int solve() {
	bfs(0, ds);
	bfs(n - 1, dt);
	np = 0; REP(i, n) if (isspecial[i]) p[np++] = MP(ds[i], dt[i]);
	sort(p, p + np);
	bool decreasing = true;
	FOR(i, 1, np) if (p[i].second >= p[i - 1].second) decreasing = false;
	//printf("p:"); REP(i, np) printf(" (%d,%d)", p[i].first, p[i].second); puts("");
	int ret = ds[n - 1];
	if (decreasing) {
		int best = INT_MIN; FOR(i, 1, np) best = max(best, p[i - 1].first + p[i].second + 1); ret = min(ret, best);
	}
	return ret;
}

void run() {
	scanf("%d%d%d", &n, &m, &nspecial);
	REP(i, n) isspecial[i] = false; REP(i, nspecial) { int a; scanf("%d", &a); --a; isspecial[a] = true; }
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}