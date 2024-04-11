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

const int MAXH = 200;
const int MAXW = 200;

int h, w;
char g[MAXH][MAXW + 1];

int lid[MAXH][MAXW], nlid;
int rid[MAXH][MAXW], nrid;

vector<vector<int>> adj;

const int MAXGN = 1000000;
const int MAXGM = 1000000;

typedef struct MF {
	int n, m;
	int ghead[MAXGN], gnxt[2 * MAXGM], gto[2 * MAXGM]; ll gcap[2 * MAXGM];
	void init(int _n) { n = _n, m = 0; REP(i, n) ghead[i] = -1; }
	void addedge(int a, int b, ll c) { gnxt[2 * m + 0] = ghead[a], ghead[a] = 2 * m + 0, gto[2 * m + 0] = b, gcap[2 * m + 0] = c; gnxt[2 * m + 1] = ghead[b], ghead[b] = 2 * m + 1, gto[2 * m + 1] = a, gcap[2 * m + 1] = 0; ++m; /*printf("%d->%d\n",a,b);*/ }
	int d[MAXGN];
	int q[MAXGN], qhead, qtail;
	int cur[MAXGN];
	ll dinic(int s, int t) {
		ll ret = 0; int niter = 0;
		while (true) {
			REP(i, n) d[i] = INT_MAX; qhead = qtail = 0; d[s] = 0, q[qhead++] = s;
			while (qtail < qhead && d[t] == INT_MAX) { int at = q[qtail++]; for (int x = ghead[at]; x != -1; x = gnxt[x]) { int to = gto[x]; if (gcap[x] == 0 || d[to] != INT_MAX) continue; d[to] = d[at] + 1; q[qhead++] = to; } }
			if (d[t] == INT_MAX) return ret;
			REP(i, n) cur[i] = ghead[i];
			ret += dfs(s, t, LLONG_MAX); ++niter;
		}
	}
	ll dfs(int at, int t, ll rem) {
		ll ret = 0; if (at == t) return rem;
		if (d[at] >= d[t]) return 0;
		for (; cur[at] != -1; cur[at] = gnxt[cur[at]]) {
			int to = gto[cur[at]]; ll cap = gcap[cur[at]]; if (d[to] != d[at] + 1 || cap == 0) continue;
			ll now = dfs(to, t, min(cap, rem));
			rem -= now; ret += now; if (gcap[cur[at]] != LLONG_MAX) gcap[cur[at]] -= now; if (gcap[cur[at] ^ 1] != LLONG_MAX) gcap[cur[at] ^ 1] += now; if (rem == 0) return ret;
		}
		return ret;
	}
} MF;
MF mf;


int maxmatching() {
	mf.init(2 + nlid + nrid);
	REP(i, nlid) mf.addedge(0, 2 + i, 1);
	REP(i, nrid) mf.addedge(2 + nlid + i, 1, 1);
	REP(i, nlid) REPSZ(j, adj[i]) { int k = adj[i][j]; mf.addedge(2 + i, 2 + nlid + k, 1); }
	return mf.dinic(0, 1);
}

int solve() {
	nlid = nrid = 0;
	REP(x, h) REP(y, w) lid[x][y] = rid[x][y] = -1;
	REP(x, h) REP(y, w) if(g[x][y]=='#') {
		if (x + 1 < h && g[x + 1][y] == '#') lid[x][y] = nlid++;
		if (y + 1 < w && g[x][y + 1] == '#') rid[x][y] = nrid++;
	}
	adj = vector<vector<int>>(nlid);
	REP(x, h) REP(y, w) if (lid[x][y] != -1) {
		if (y - 1 >= 0 && rid[x][y - 1] != -1) adj[lid[x][y]].PB(rid[x][y - 1]);
		if (rid[x][y] != -1) adj[lid[x][y]].PB(rid[x][y]);
		if (x + 1 < h && y - 1 >= 0 && rid[x + 1][y - 1] != -1) adj[lid[x][y]].PB(rid[x + 1][y - 1]);
		if (x + 1 < h && rid[x + 1][y] != -1) adj[lid[x][y]].PB(rid[x + 1][y]);
	}
	int ncell = 0; REP(x, h) REP(y, w) if (g[x][y] == '#') ++ncell;
	int ncover = maxmatching();
	return ncell - (nlid + nrid - ncover);
}

void run() {
	scanf("%d%d", &h, &w);
	REP(x, h) scanf("%s", g[x]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}