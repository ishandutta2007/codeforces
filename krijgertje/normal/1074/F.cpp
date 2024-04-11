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
const int MAXS = 4 * MAXN;
const int MAXLG = 17;

int n, nq;
vector<int> adj[MAXN];

int pre[MAXN], lpreidx[MAXN], rpreidx[MAXN], npre;
int dep[MAXN];
int up[MAXN][MAXLG + 1];
int par[MAXN];

set<pair<int, int>> extra;

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	up[at][0] = par[at] == -1 ? at : par[at]; REP(k, MAXLG) up[at][k + 1] = up[up[at][k]][k];
	pre[npre] = at, lpreidx[at] = npre, ++npre;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		par[to] = at; dfsinit(to);
	}
	rpreidx[at] = npre - 1;
}
int goup(int a, int n) {
	for (int k = MAXLG; k >= 0; --k) if (n&(1 << k)) a = up[a][k];
	return a;
}
int lca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int k = MAXLG; k >= 0; --k) if (dep[a] - (1 << k) >= dep[b]) a = up[a][k];
	for (int k = MAXLG; k >= 0; --k) if (up[a][k] != up[b][k]) a = up[a][k], b = up[b][k];
	return a == b ? a : up[a][0];
}

int smn[MAXS], smncnt[MAXS], slazy[MAXS];

void sapply(int x, int by) {
	smn[x] += by, slazy[x] += by;
}
void spush(int x) {
	if (slazy[x] != 0) sapply(2 * x + 1, slazy[x]), sapply(2 * x + 2, slazy[x]), slazy[x] = 0;
}
void spull(int x) {
	smn[x] = min(smn[2 * x + 1], smn[2 * x + 2]); smncnt[x] = (smn[2 * x + 1] == smn[x] ? smncnt[2 * x + 1] : 0) + (smn[2 * x + 2] == smn[x] ? smncnt[2 * x + 2] : 0);
}

void sinit(int x, int l, int r) {
	if (l == r) {
		smn[x] = 0, smncnt[x] = 1;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}

void supd(int x, int l, int r, int L, int R, int BY) {
	if (L <= l&&r <= R) {
		sapply(x, BY);
	} else {
		int m = l + (r - l) / 2;
		spush(x);
		if (L <= m) supd(2 * x + 1, l, m, L, R, BY);
		if (m + 1 <= R) supd(2 * x + 2, m + 1, r, L, R, BY);
		spull(x);
	}
}



void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	
	npre = 0; par[0] = -1; dfsinit(0);
	sinit(0, 0, n - 1);

	REP(i, nq) {
		int a, b; scanf("%d%d", &a, &b); --a, --b; if (a > b) swap(a, b);
		int by; if (!extra.count(MP(a, b))) by = +1, extra.insert(MP(a, b)); else by = -1, extra.erase(MP(a, b));
		if (dep[a] > dep[b]) swap(a, b);
		int c = lca(a, b);
		if (c == a) {
			int d = goup(b, dep[b] - dep[a] - 1);
			//printf("changing subtree %d except subsubtree %d by %d\n", d + 1, b + 1, by);
			supd(0, 0, n - 1, lpreidx[d], rpreidx[d], by);
			supd(0, 0, n - 1, lpreidx[b], rpreidx[b], -by);
		} else {
			//printf("changing all except subtrees %d and %d by %d\n", a + 1, b + 1, by);
			supd(0, 0, n - 1, 0, n - 1, by);
			supd(0, 0, n - 1, lpreidx[a], rpreidx[a], -by);
			supd(0, 0, n - 1, lpreidx[b], rpreidx[b], -by);
		}
		//printf("mn=%d mncnt=%d\n", smn[0], smncnt[0]);
		int ans = smn[0] == 0 ? smncnt[0] : 0;
		printf("%d\n", ans);
	}
}

int main() {
	run();
	return 0;
}