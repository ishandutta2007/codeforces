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

const int MAXN = 200000;
const int MAXM = 200000;

int n, m, want;
int e[MAXM][2];
int ans[MAXM];

bool alive[MAXN]; int nalive;
bool removed[MAXM];
int deg[MAXN];
vector<pair<int, int>> adj[MAXN];
int q[MAXN], qhead, qtail;

void processqueue() {
	while (qtail < qhead) {
		int at = q[qtail++];
		alive[at] = false, --nalive;
		REPSZ(i, adj[at]) {
			int to = adj[at][i].first, id = adj[at][i].second; if (removed[id]) continue;
			removed[id] = true;
			if (--deg[at] == want - 1) q[qhead++] = at;
			if (--deg[to] == want - 1) q[qhead++] = to;
		}
		assert(deg[at] == 0);
	}
}

void solve() {
	REP(i, n) adj[i].clear(), alive[i] = true; nalive = n;
	REP(i, m) { int a = e[i][0], b = e[i][1]; adj[a].PB(MP(b, i)); adj[b].PB(MP(a, i)); removed[i] = false; }
	REP(i, n) deg[i] = SZ(adj[i]);
	qhead = qtail = 0;
	REP(i, n) if (deg[i] < want) { q[qhead++] = i; }
	processqueue();
	for (int i = m - 1; i >= 0; --i) {
		ans[i] = nalive;
		int a = e[i][0], b = e[i][1];
		if (removed[i]) continue;
		removed[i] = true;
		if (--deg[a] == want - 1) q[qhead++] = a;
		if (--deg[b] == want - 1) q[qhead++] = b;
		processqueue();
	}
}

void run() {
	scanf("%d%d%d", &n, &m, &want);
	REP(i, m) REP(j, 2) scanf("%d", &e[i][j]), --e[i][j];
	solve();
	REP(i, m) printf("%d\n", ans[i]);
}

int main() {
	run();
	return 0;
}