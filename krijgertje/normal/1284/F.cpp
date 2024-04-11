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

const int MAXN = 250000;
const int MAXLG = 17;

int n;
vector<int> adj1[MAXN];
vector<int> adj2[MAXN];
vector<pair<pair<int, int>, pair<int, int>>> ans;

int deg2[MAXN];
bool done[MAXN];
queue<int> q2;

int dep1[MAXN];
int par1[MAXN];
int up1[MAXN][MAXLG + 1];

int ufpar[MAXN], ufsz[MAXN];
int uffind(int x) { if (ufpar[x] == x) return x; return ufpar[x] = uffind(ufpar[x]); }
void ufunite(int x, int y) { x = uffind(x); y = uffind(y); if (x == y) return; if (ufsz[x] < ufsz[y]) swap(x, y); ufpar[y] = x, ufsz[x] += ufsz[y]; }

void dfs1(int at) {
	dep1[at] = par1[at] == -1 ? 0 : dep1[par1[at]] + 1;
	up1[at][0] = par1[at] == -1 ? at : par1[at]; REP(k, MAXLG) up1[at][k + 1] = up1[up1[at][k]][k];
	REPSZ(i, adj1[at]) { int to = adj1[at][i]; if (to == par1[at]) continue; par1[to] = at; dfs1(to); }
}
int lca1(int a, int b) {
	//printf("\tcalclca(%d,%d) [%d,%d]\n", a + 1, b + 1, dep1[a], dep1[b]);
	if (dep1[a] < dep1[b]) swap(a, b);
	for (int k = MAXLG; k >= 0; --k) if (dep1[a] - (1 << k) >= dep1[b]) a = up1[a][k];
	if (a == b) return a;
	for (int k = MAXLG; k >= 0; --k) if (up1[a][k] != up1[b][k]) a = up1[a][k], b = up1[b][k];
	return par1[a];
}

pair<int, int> findedgeup(int a, int b) {
	//printf("findup(%d,%d)\n", a + 1, b + 1);
	for (int k = MAXLG; k >= 0; --k) if (dep1[a] - (1 << k) >= dep1[b]) {
		int c = up1[a][k];
		if (uffind(a) != uffind(c)) b = c; else a = c;
	}
	return MP(a, par1[a]);
}

pair<int, int> findedgedown(int a, int b) {
	//printf("finddn(%d,%d)\n", a + 1, b + 1);
	for (int k = MAXLG; k >= 0; --k) if (dep1[b] - (1 << k) >= dep1[a]) {
		int c = up1[b][k];
		if (uffind(a) != uffind(c)) b = c; else a = c;
	}
	return MP(b, par1[b]);
}

pair<int, int> findedgeonpath(int a, int b) {
	assert(uffind(a) != uffind(b));
	int c = lca1(a, b);
	//printf("lca(%d,%d)=%d\n", a + 1, b + 1, c + 1);
	if (uffind(a) != uffind(c)) return findedgeup(a, c); else return findedgedown(c, b);
}

void solve() {
	par1[0] = -1; dfs1(0);
	REP(i, n) ufpar[i] = i, ufsz[i] = 1;
	REP(i, n) deg2[i] = SZ(adj2[i]);
	REP(i, n) done[i] = false;
	q2=queue<int>(); REP(i, n) if (deg2[i] <= 1) q2.push(i);
	ans.clear();
	while (!q2.empty()) {
		int at = q2.front(); q2.pop();
		done[at] = true;
		int to = -1; REPSZ(i, adj2[at]) { int cur = adj2[at][i]; if (done[cur]) continue; assert(to == -1); to = cur; } if (to == -1) break;
		//printf("%d-%d\n", at + 1, to + 1);
		pair<int, int> edge = findedgeonpath(at, to);
		//printf("  -> %d-%d\n", edge.first + 1, edge.second + 1);
		ans.PB(MP(edge, MP(at, to)));
		ufunite(edge.first, edge.second);
		if (--deg2[to] == 1) q2.push(to);
	}
	assert(SZ(ans) == n - 1);
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj1[a].PB(b); adj1[b].PB(a); }
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj2[a].PB(b); adj2[b].PB(a); }
	solve();
	printf("%d\n", SZ(ans)); REPSZ(i, ans) printf("%d %d %d %d\n", ans[i].first.first + 1, ans[i].first.second + 1, ans[i].second.first + 1, ans[i].second.second + 1);
}

int main() {
	run();
	return 0;
}