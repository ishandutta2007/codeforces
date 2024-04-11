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

const int MAXN = 500000;
const int MAXBIT = 18;
const int MAXLINE = 500000;

int n, nline;
vector<int> adj[MAXN];
int lineend[MAXLINE][2];

int par[MAXN], dep[MAXN];
int up[MAXN][MAXBIT + 1];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	up[at][0] = par[at] == -1 ? at : par[at]; REP(k, MAXBIT) up[at][k + 1] = up[up[at][k]][k];
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		par[to] = at; dfsinit(to);
	}
}
int calcup(int a, int steps) {
	for (int k = MAXBIT; k >= 0; --k) if (steps&(1 << k)) a = up[a][k];
	return a;
}
int calclca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	a = calcup(a, dep[a] - dep[b]);
	if (a == b) return a;
	for (int k = MAXBIT; k >= 0; --k) if (up[a][k] != up[b][k]) a = up[a][k], b = up[b][k];
	return par[a];
}

int ufpar[MAXN], ufsz[MAXN], ufdiff[MAXN];

int uffind(int a) { if (ufpar[a] == a) return a; uffind(ufpar[a]); ufdiff[a] ^= ufdiff[ufpar[a]]; return ufpar[a] = ufpar[ufpar[a]]; }
bool ufunite(int a, int b, int diff) { uffind(a), uffind(b); diff ^= ufdiff[a], a = ufpar[a], diff ^= ufdiff[b], b = ufpar[b]; if (a == b) return diff == 0; if (ufsz[a] < ufsz[b]) swap(a, b); ufsz[a] += ufsz[b], ufpar[b] = a, ufdiff[b] ^= diff; return true; }

int unitedep[MAXN];
bool anyedge[MAXN];

void dfsunite(int at) {
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		dfsunite(to);
		unitedep[at] = min(unitedep[at], unitedep[to]);
	}
}

int dp[MAXN];
int seenby[MAXN], mxzero[MAXN], mxone[MAXN];
int seenlst[MAXN], nseenlst;

bool dfscalc(int at, int lim) {
	if (par[at] == -1) REP(i, n) seenby[i] = -1;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		if (!dfscalc(to, lim)) return false;
	}
	nseenlst = 0;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		uffind(to);
		int id = ufpar[to];
		if (seenby[id] != at) seenlst[nseenlst++] = id, seenby[id] = at, mxzero[id] = mxone[id] = 0;
		if (ufdiff[to] == 0 && anyedge[to]) mxzero[id] = max(mxzero[id], dp[to]);
		if (ufdiff[to] == 1 && anyedge[to]) mxone[id] = max(mxone[id], dp[to]);
	}
	uffind(at); int me = ufpar[at];
	int lo = 1, loupto = lim, hi = lim, hidownto = 1;
	REP(i, nseenlst) {
		int id = seenlst[i];
		//printf("\tat=%d comp=%d mxzero=%d mxone=%d [me=%d mediff=%d]\n", at + 1, it->first, mxzero, mxone, me, ufdiff[at]);
		int a = mxzero[id], b = mxone[id];
		if (id == me) {
			if (ufdiff[at] == 1) swap(a, b);
			lo = max(lo, a + 1); hi = min(hi, lim - b);
		} else {
			// [mxzero+1..lim-mxone] or [mxone+1..lim-mxzero]
			if (a > b) swap(a, b); // [a+1..lim-b] or [b+1..lim-a]
			lo = max(lo, a + 1), hi = min(hi, lim - a);
			if (lim - b < b + 1) loupto = min(loupto, lim - b), hidownto = max(hidownto, b + 1);
		}
	}
	loupto = min(loupto, hi);
	hidownto = max(hidownto, lo);
	bool ret;
	if (lo <= loupto) { dp[at] = lo; ret = true; }
	else if (hidownto <= hi) { dp[at] = hidownto; ret = true; }
	else ret = false;
	//printf("lim=%d at=%d: %s (%d) [%d..%d and %d..%d]\n", lim, at + 1, ret ? "OK" : "ERR", dp[at], lo, loupto, hidownto, hi);
	return ret;
}

int ans;
int cost[MAXN];
bool rev[MAXN];
bool swapped[MAXN];

void reconstruct(int at) {
	if (par[at] == -1) REP(i, n) seenby[i] = -1;
	cost[at] = !rev[at] ? dp[at] : ans - dp[at] + 1;
	nseenlst = 0;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		uffind(to);
		int id = ufpar[to];
		if (seenby[id] != at) seenlst[nseenlst++] = id, seenby[id] = at, mxzero[id] = mxone[id] = 0;
		if (ufdiff[to] == 0 && anyedge[to]) mxzero[id] = max(mxzero[id], dp[to]);
		if (ufdiff[to] == 1 && anyedge[to]) mxone[id] = max(mxone[id], dp[to]);
	}
	uffind(at); int me = ufpar[at];
	REP(i, nseenlst) {
		int id = seenlst[i];
		//printf("\tat=%d comp=%d mxzero=%d mxone=%d [me=%d mediff=%d]\n", at + 1, it->first, mxzero, mxone, me, ufdiff[at]);
		int a = mxzero[id], b = mxone[id]; swapped[id] = false;
		if (id == me && ufdiff[at] == 1) swap(a, b), swapped[id] = !swapped[id];
		if ((dp[at] <= a || dp[at] > ans - b) && id != me) swap(a, b), swapped[id] = !swapped[id];
		assert(dp[at] > a && dp[at] <= ans - b);
	}
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		rev[to] = rev[at] ^ swapped[ufpar[to]] ^ (ufdiff[to] == 1);
	}
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		reconstruct(to);
	}
}

bool solve() {
	par[0] = -1; dfsinit(0);
	REP(i, n) ufpar[i] = i, ufsz[i] = 1, ufdiff[i] = 0, unitedep[i] = dep[i], anyedge[i] = false;
	REP(i, nline) {
		int a = lineend[i][0], b = lineend[i][1]; if (dep[a] > dep[b]) swap(a, b);
		int c = calclca(a, b);
		if (c == a) {
			unitedep[b] = min(unitedep[b], dep[c]);
		} else {
			int aa = calcup(a, dep[a] - dep[c] - 1);
			int bb = calcup(b, dep[b] - dep[c] - 1);
			if (!ufunite(aa, bb, 1)) return false;
			unitedep[a] = min(unitedep[a], dep[c]);
			unitedep[b] = min(unitedep[b], dep[c]);
		}
	}
	dfsunite(0);
	REP(i, n) if (unitedep[i] < dep[i]) anyedge[i] = true;
	REP(i, n) if (unitedep[i] < dep[i] - 1) if (!ufunite(i, par[i], 0)) return false;
	//REP(i, n) if (par[i] != -1) { uffind(i); printf("%d-%d: %d,%d\n", i + 1, par[i] + 1, ufpar[i], ufdiff[i]); }

	int lo = 1, hi = n;
	while (lo + 1 < hi) {
		int mi = lo + (hi - lo) / 2;
		if (!dfscalc(0, mi)) lo = mi; else hi = mi;
	}
	ans = hi;
	//puts("");
	assert(dfscalc(0, ans));
	rev[0] = false; reconstruct(0);
	return true;
}

void run() {
	scanf("%d%d", &n, &nline);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	REP(i, n) sort(adj[i].begin(), adj[i].end());
	REP(i, nline) REP(j, 2) scanf("%d", &lineend[i][j]), --lineend[i][j];
	if (!solve()) { printf("-1\n"); return; }
	printf("%d\n", ans);
	REP(i, n) { if (i != 0) printf(" "); printf("%d", cost[i]); } puts("");
}

void stress() {
	REP(rep, 100000) {
		n = rand() % 10 + 2; REP(i, n) adj[i].clear();
		vector<int> col(n); REP(i, n) col[i] = i;
		REP(i, n - 1) while (true) { int a = rand() % n, b = rand() % n; if (col[a] == col[b]) continue; int ocol = col[b]; REP(j, n) if (col[j] == ocol) col[j] = col[a]; adj[a].PB(b), adj[b].PB(a); break; }
		REP(i, n) sort(adj[i].begin(), adj[i].end());
		nline = rand() % 10 + 1; REP(i, nline) while (true) { int a = rand() % n, b = rand() % n; if (a == b) continue; lineend[i][0] = a, lineend[i][1] = b; break; }
		//if (rep != 1) continue;
		//printf("%d %d\n", n, nline);
		//REP(at, n) REPSZ(i, adj[at]) { int to = adj[at][i]; if (at < to) printf("%d %d\n", at + 1, to + 1); }
		//REP(i, nline) printf("%d %d\n", lineend[i][0] + 1, lineend[i][1] + 1);
		solve();
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}