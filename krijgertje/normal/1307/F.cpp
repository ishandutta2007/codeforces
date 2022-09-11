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
const int MAXLG = 17;
const int MAXQ = 200000;

int n, lim, nspecial;
vector<int> adj[MAXN];
bool isspecial[MAXN];
int nq;
int qa[MAXQ], qb[MAXQ]; bool qans[MAXQ];

int par[MAXN];
int dep[MAXN];
int up[MAXN][MAXLG + 1];
int dist1[MAXN], dist1via[MAXN], dist2[MAXN];
bool canpar[MAXN];
int comp[MAXN], ncomp;
int comptop[MAXN];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	up[at][0] = par[at] == -1 ? at : par[at]; REP(k, MAXLG) up[at][k + 1] = up[up[at][k]][k];
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		par[to] = at; dfsinit(to);
	}
}

int lca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int k = MAXLG; k >= 0; --k) if (dep[a] - (1 << k) >= dep[b]) a = up[a][k];
	if (a == b) return a;
	for (int k = MAXLG; k >= 0; --k) if (up[a][k] != up[b][k]) a = up[a][k], b = up[b][k];
	return par[a];
}

void upddist(int at, int d, int via) {
	if (d != INT_MAX) ++d;
	if (d < dist1[at]) { if (dist1via[at] != via) dist2[at] = dist1[at]; dist1[at] = d, dist1via[at] = via; } else if (via != dist1via[at] && d < dist2[at]) dist2[at] = d;
}

void dfsdown(int at) {
	dist1[at] = dist2[at] = INT_MAX, dist1via[at] = -1;
	if (isspecial[at]) dist1[at] = 0, dist1via[at] = at;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		dfsdown(to);
		upddist(at, dist1[to], to);
	}
}
void dfsup(int at) {
	canpar[at] = par[at] != -1 && dist1[at] + 1 + dist1[par[at]] <= lim;
	if (!canpar[at]) { comp[at] = ncomp++; comptop[comp[at]] = -1; } else comp[at] = comp[par[at]];
	if (isspecial[at] && (comptop[comp[at]] == -1 || dep[at] < dep[comptop[comp[at]]])) comptop[comp[at]] = at;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		upddist(to, dist1via[at] != to ? dist1[at] : dist2[at], at);
		dfsup(to);
	}
}

pair<int, int> stck[MAXN]; int nstck;
int top[MAXN];

void dfstop(int at, int stckpos) {
	while (stckpos < nstck && stck[stckpos].second < dep[at]) ++stckpos;
	top[at] = stckpos < nstck ? stck[stckpos].first : at;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		int d = dist1via[at] != to ? dist1[at] : dist2[at];
		int deplim = lim + 2 * dep[at] - (dep[at] + d);
		if (nstck == 0 || deplim > stck[nstck - 1].second) stck[nstck++] = MP(at, deplim);
		dfstop(to, stckpos);
		if (nstck > 0 && stck[nstck - 1].first == at) --nstck;
	}
}

bool calc(int a, int b) {
	int c = lca(a, b);
	if (dep[a] + dep[b] - 2 * dep[c] <= lim) return true;
	if (comp[a] == comp[b]) return true;
	if (dep[top[a]] <= dep[c] && dep[top[b]] <= dep[c]) return true;
	if (dep[top[a]] <= dep[c]) swap(a, b);
	a = top[a];
	if (dep[top[b]] > dep[c]) { b = top[b]; return comp[a] == comp[b]; }
	if (comptop[comp[a]] == -1) return false;
	a = comptop[comp[a]];
	return dep[a] + dep[b] - 2 * dep[c] <= lim;
}

void solve() {
	par[0] = -1; dfsinit(0);
	dfsdown(0);
	ncomp = 0; dfsup(0);
	nstck = 0; dfstop(0, 0);
	//REP(i, n) printf("%d: dep=%d comp=%d top=%d comptop=%d (dist1=%d dist1via=%d dist2=%d)\n", i + 1, dep[i], comp[i], top[i] + 1, comptop[comp[i]] + 1, dist1[i], dist1via[i] + 1, dist2[i]);
	
	REP(i, nq) {
		int a = qa[i], b = qb[i];
		qans[i] = calc(a, b);
	}
}

void run() {
	scanf("%d%d%d", &n, &lim, &nspecial);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	REP(i, n) isspecial[i] = false; REP(i, nspecial) { int a; scanf("%d", &a); --a; isspecial[a] = true; }
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d", &qa[i], &qb[i]), --qa[i], --qb[i];
	solve();
	REP(i, nq) printf("%s\n", qans[i] ? "YES" : "NO");
}

int main() {
	run();
	return 0;
}