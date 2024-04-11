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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 9;

int n;
int g[MAXN][MAXN];

vector<vector<string>> ans;

int reach[MAXN];
pair<int, int> o[MAXN];

int layer[MAXN];
vector<int> layernodes[MAXN]; int nlayer;
vector<int> layeradj[MAXN];
int top[MAXN], topidx[MAXN], ntop;

void dfstop(int at) {
	REPSZ(i, layeradj[at]) {
		int to = layeradj[at][i];
		if (topidx[to] != -1) continue;
		dfstop(to);
	}
	topidx[at] = ntop, top[ntop] = at, ++ntop;
}

void solve() {
	REP(i, n) { reach[i] = 1 << i; REP(j, n) if (g[i][j] == 1) reach[i] |= 1 << j; }
	REP(k, n) REP(i, n) REP(j, n) if ((reach[i] & (1 << k)) != 0 && (reach[k] & (1 << j)) != 0) reach[i] |= 1 << j;
	//printf("reach:"); REP(i, n) printf(" %d", reach[i]); puts("");

	REP(i, n) o[i] = MP(reach[i], i); sort(o, o + n);
	nlayer = 0;
	for (int l = 0, r = l; l < n; l = r) {
		while (r < n && o[l].first == o[r].first) ++r;
		int clayer = nlayer++; layernodes[clayer].clear(); FOR(i, l, r) layernodes[clayer].PB(o[i].second), layer[o[i].second] = clayer;
	}
	REP(i, nlayer) {
		layeradj[i].clear();
		REPSZ(j, layernodes[i]) { int at = layernodes[i][j]; REP(to, n) if (g[at][to] == 1 && layer[to] != layer[at]) layeradj[i].PB(layer[to]); }
		sort(layeradj[i].begin(), layeradj[i].end()); layeradj[i].erase(unique(layeradj[i].begin(), layeradj[i].end()), layeradj[i].end());
	}
	//REP(i, nlayer) { printf("layernodes%d:", i); REPSZ(j, layernodes[i]) printf(" %d", layernodes[i][j] + 1); puts(""); }
	//REP(i, nlayer) { printf("layeradj%d:", i); REPSZ(j, layeradj[i]) printf(" %d", layeradj[i][j]); puts(""); }
	ntop = 0; REP(i, nlayer) topidx[i] = -1; REP(i, nlayer) if (topidx[i] == -1) dfstop(i);
	//printf("top:"); REP(i, ntop) printf(" %d", top[i]); puts(" (bottom first)");
	
	vector<pair<int, int>> e; REP(i, nlayer) REPSZ(j, layeradj[i]) e.PB(MP(topidx[i], topidx[layeradj[i][j]]));
	int nz = 2 * nlayer - 1, ny = 3, nx = max(n, 2 * SZ(e) - 1);
	//printf("nx=%d ny=%d nz=%d\n", nx, ny, nz);
	ans = vector<vector<string>>(nz, vector<string>(ny, string(nx , '#')));
	for (int z = 1; z < nz; z += 2) REPSZ(i, e) if (e[i].second != (z + 1) / 2) ans[z][0][2 * i] = '.';
	for (int z = 0; z < nz; z += 2) { REP(x, nx) ans[z][2][x] = '.'; REPSZ(i, e) ans[z][0][2 * i] = '.'; REPSZ(i, e) if (e[i].first == z / 2 || e[i].second == z / 2) ans[z][1][2 * i] = '.'; }
	REP(i, nlayer) REPSZ(j, layernodes[i]) ans[topidx[i] * 2][2][j] = '1' + layernodes[i][j];
}

void run() {
	scanf("%d", &n);
	REP(i, n) REP(j, n) scanf("%d", &g[i][j]);
	solve();
	printf("%d %d %d\n", SZ(ans[0][0]), SZ(ans[0]), SZ(ans));
	for (int z = SZ(ans) - 1; z >= 0; --z) {
		if (z != SZ(ans) - 1) puts("");
		REPSZ(y, ans[z]) printf("%s\n", ans[z][y].c_str());
	}
}

int main() {
	run();
	return 0;
}