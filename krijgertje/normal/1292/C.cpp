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

const int MAXN = 3000;
const int MAXM = MAXN - 1;

int n;
int e[MAXM][2];

vector<pair<int,int>> adj[MAXN];
int dep[MAXN], par[MAXN], parid[MAXN], sz[MAXN], lid[MAXN], rid[MAXN], nid;

int nxtedge[MAXN][MAXN];

int lsz[MAXM][MAXM], rsz[MAXM][MAXM];
int lnxt[MAXM][MAXM], rnxt[MAXM][MAXM];
vector<pair<int, int>> bysum[MAXN + 1];
ll dp[MAXM][MAXM];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1; sz[at] = 1; lid[at] = nid++;
	REPSZ(i, adj[at]) {
		int to = adj[at][i].first; if (to == par[at]) continue;
		par[to] = at, parid[to] = adj[at][i].second; dfsinit(to); sz[at] += sz[to];
	}
	rid[at] = nid - 1;
}
void dfsnxt(int root, int at, int par, int parid) {
	nxtedge[at][root] = parid;
	REPSZ(i, adj[at]) {
		int to = adj[at][i].first; if (to == par) continue;
		dfsnxt(root, to, at, adj[at][i].second);
	}
}
bool isancestor(int a, int b) {
	return lid[a] <= lid[b] && rid[b] <= rid[a];
}
void upd(int i, int j, ll b) { if (i < j) swap(i, j);  dp[i][j] = max(dp[i][j], b); }

ll solve() {
	REP(i, n) adj[i].clear(); REP(i, n - 1) { int a = e[i][0], b = e[i][1]; adj[a].PB(MP(b, i)); adj[b].PB(MP(a, i)); }
	par[0] = parid[0] = -1; nid = 0; dfsinit(0);
	REP(i, n) dfsnxt(i, i, -1, -1);

	REP(i, n - 1) {
		int a = e[i][0], b = e[i][1]; if (dep[a] > dep[b]) swap(a, b);
		lsz[i][i] = n - sz[b], rsz[i][i] = sz[b]; lnxt[i][i] = rnxt[i][i] = -1;
	}
	REP(i, n - 1) REP(j, i) {
		int a = e[i][0], b = e[i][1]; if (dep[a] > dep[b]) swap(a, b);
		int c = e[j][0], d = e[j][1]; if (dep[c] > dep[d]) swap(c, d);
		if (isancestor(b, c)) { lsz[i][j] = n - sz[b]; lnxt[i][j] = nxtedge[b][d]; } else { lsz[i][j] = sz[b]; lnxt[i][j] = nxtedge[a][a == d ? c : d]; }
		if (isancestor(d, a)) { rsz[i][j] = n - sz[d]; rnxt[i][j] = nxtedge[d][b]; } else { rsz[i][j] = sz[d]; rnxt[i][j] = nxtedge[c][c == b ? a : b]; }
	}
	REPE(i, n) bysum[i].clear(); REP(i, n - 1) REPE(j, i) { int sum = lsz[i][j] + rsz[i][j]; assert(sum <= n); bysum[sum].PB(MP(i, j)); }
	REP(i, n - 1) REPE(j, i) dp[i][j] = 0;
	REPE(sum, n) REPSZ(_, bysum[sum]) {
		int i, j; tie(i, j) = bysum[sum][_];
		dp[i][j] += lsz[i][j] * rsz[i][j];
		//printf("(%d-%d) / (%d-%d): %lld [%d,%d][%d,%d]\n", e[i][0] + 1, e[i][1] + 1, e[j][0] + 1, e[j][1] + 1, dp[i][j], lsz[i][j], rsz[i][j], lnxt[i][j], rnxt[i][j]);
		if (lnxt[i][j] != -1) upd(lnxt[i][j], j, dp[i][j]);
		if (rnxt[i][j] != -1) upd(i, rnxt[i][j], dp[i][j]);
	}
	ll ret = 0; REP(i, n - 1) ret = max(ret, dp[i][i]); return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) REP(j, 2) scanf("%d", &e[i][j]), --e[i][j];
	printf("%lld\n", solve());
}

void stress() {
	n = MAXN;
	REP(i, n - 1) e[i][0] = i, e[i][1] = i + 1;
	printf("%lld\n", solve());
}

int main() {
	run();
	//stress();
	return 0;
}