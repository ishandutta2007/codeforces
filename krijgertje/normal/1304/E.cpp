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

const int MAXN = 100000;
const int MAXQ = 100000;
const int MAXLG = 16;

int n;
vector<int> adj[MAXN];
int nq;
int qa[MAXQ], qb[MAXQ], qs[MAXQ], qt[MAXQ], qwant[MAXQ]; bool qans[MAXQ];

int par[MAXN];
int dep[MAXN];
int up[MAXN][MAXLG + 1];

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

int calcdist(int a, int b) {
	int c = lca(a, b);
	return dep[a] + dep[b] - 2 * dep[c];
}

bool query(int i) {
	int a = qa[i], b = qb[i], s = qs[i], t = qt[i], want = qwant[i];
	int dst = calcdist(s, t);
	int dsa = calcdist(s, a);
	int dsb = calcdist(s, b);
	int dat = calcdist(a, t);
	int dbt = calcdist(b, t);
	int dab = calcdist(a, b);
	int opt[5]; opt[0] = dst, opt[1] = dsa + 1 + dbt, opt[2] = dsb + 1 + dat, opt[3] = dsa + 1 + dab + 1 + dbt, opt[4] = dsb + 1 + dab + 1 + dat;
	REP(i, 5) { int have = opt[i]; if (have <= want && have % 2 == want % 2) return true; }
	return false;
}

void solve() {
	par[0] = -1; dfsinit(0);
	REP(i, nq) qans[i] = query(i);
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d%d%d%d", &qa[i], &qb[i], &qs[i], &qt[i], &qwant[i]), --qa[i], --qb[i], --qs[i], --qt[i];
	solve();
	REP(i, nq) printf("%s\n", qans[i] ? "YES" : "NO");
}

int main() {
	run();
	return 0;
}