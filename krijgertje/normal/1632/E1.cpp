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

const int MAXN = 300000;
const int MAXLG = 18;

int n;
vector<int> adj[MAXN];
int ans[MAXN + 1];

int par[MAXN], dep[MAXN];
int up[MAXN][MAXLG + 1];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	up[at][0] = par[at] == -1 ? at : par[at];
	REP(k, MAXLG) up[at][k + 1] = up[up[at][k]][k];
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
	}
}

int calclca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int k = MAXLG; k >= 0; --k) if (dep[a] - (1 << k) >= dep[b]) a = up[a][k];
	if (a == b) return a;
	for (int k = MAXLG; k >= 0; --k) if (up[a][k] != up[b][k]) a = up[a][k], b = up[b][k];
	return par[a];
}

int calcdist(int a, int b) {
	int c = calclca(a, b);
	return dep[a] + dep[b] - 2 * dep[c];
}

void solve() {
	par[0] = -1;
	dfsinit(0);
	int mxdep = 0;
	REP(i, n) mxdep = max(mxdep, dep[i]);
	vector<vector<int>> bydep(mxdep + 1);
	REP(i, n) bydep[dep[i]].PB(i);
	int u = -1, v = -1, uvdist = -1;
	int anspos = n;
	for (int d = mxdep - 1; d >= 0; --d) {
		for (int at : bydep[d + 1]) {
			if (u == -1 && v == -1) {
				u = v = at, uvdist = 0;
			} else {
				int udist = calcdist(u, at);
				int vdist = calcdist(v, at);
				if (udist < vdist) swap(udist, vdist), swap(u, v);
				if (udist > uvdist) {
					v = at, uvdist = udist;
				}
			}
		}
		// x + ceil(uvdist/2) <= d -> x <= d - ceil(uvdist/2)
		int lim = max(0, d - (uvdist + 1) / 2);
		while (anspos > lim) ans[anspos--] = d + 1;
	}
	while (anspos > 0) ans[anspos--] = 0;
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	solve();
	FORE(i, 1, n) { if (i != 1) printf(" "); printf("%d", ans[i]); } puts("");
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}