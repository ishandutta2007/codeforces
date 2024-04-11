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

const int MAXN = 150000;
const int MAXLG = 17;
const int MAXPATH = 150000;
const int MAXSNODES = MAXN * (MAXLG + 2);

int n, npath, need;
vector<int> adj[MAXN];
int path[MAXPATH][2];

int par[MAXN], dep[MAXN], sz[MAXN], heavy[MAXN];
int up[MAXN][MAXLG + 1];
int lid[MAXN], rid[MAXN], nid;

vector<int> bylca[MAXN];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1; sz[at] = 1; heavy[at] = -1;
	up[at][0] = par[at] == -1 ? at : par[at]; REP(k, MAXLG) up[at][k + 1] = up[up[at][k]][k];
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
		sz[at] += sz[to]; if (heavy[at] == -1 || sz[to] > sz[heavy[at]]) heavy[at] = to;
	}
	rid[at] = nid - 1;
}
void dfsid(int at) {
	lid[at] = nid++;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at] || to == heavy[at]) continue;
		dfsid(to);
	}
	if (heavy[at] != -1) dfsid(heavy[at]);
	rid[at] = nid - 1;
}
int calcup(int a, int cnt) { REPE(k, MAXLG) if (cnt & (1 << k)) a = up[a][k]; return a; }
int lca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	a = calcup(a, dep[a] - dep[b]);
	if (a == b) return a;
	for (int k = MAXLG; k >= 0; --k) if (up[a][k] != up[b][k]) a = up[a][k], b = up[b][k];
	return par[a];
}
bool isdesc(int a, int b) { return lid[b] <= lid[a] && rid[a] <= rid[b]; }

ll ans;

int bit[MAXN + 1];
int bget(int idx) { ++idx; int ret = 0; while (idx > 0) { ret += bit[idx]; idx -= idx & -idx; } return ret; }
void bmod(int idx, int by) { ++idx; while (idx <= n) { bit[idx] += by; idx += idx & -idx; } }
int bget(int lidx, int ridx) { return bget(ridx) - bget(lidx - 1); }

void dfs1(int at) {
	REP(i, 2) {
		REPSZ(_, bylca[at]) {
			int id = bylca[at][_];
			int to = path[id][i];
			if (dep[to] - dep[at] < need) continue;
			to = calcup(to, dep[to] - dep[at] - need);
			ans += bget(lid[to], rid[to]);
		}
		REPSZ(_, bylca[at]) {
			int id = bylca[at][_];
			int to = path[id][i];
			bmod(lid[to], +1);
		}
	}
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		dfs1(to);
	}
}

struct SNode { int l, r, sum; };
vector<int> byfst[MAXN];
int sndset[MAXN];
SNode snodes[MAXSNODES]; int nsnodes;
int smake() { assert(nsnodes < MAXSNODES); SNode node; node.l = node.r = -1; node.sum = 0; snodes[nsnodes++] = node; return nsnodes - 1; }
void spull(int x) {
	snodes[x].sum = 0;
	if (snodes[x].l != -1) snodes[x].sum += snodes[snodes[x].l].sum;
	if (snodes[x].r != -1) snodes[x].sum += snodes[snodes[x].r].sum;
}
void smod(int& x, int l, int r, int IDX, int BY) {
	if (x == -1) x = smake();
	if (l == r) {
		snodes[x].sum += BY;
	} else {
		int m = l + (r - l) / 2;
		if (IDX <= m) smod(snodes[x].l, l, m, IDX, BY); else smod(snodes[x].r, m + 1, r, IDX, BY);
		spull(x);
	}
}
int sget(int x, int l, int r, int L, int R) {
	if (x == -1) return 0;
	if (L <= l && r <= R) {
		return snodes[x].sum;
	} else {
		int m = l + (r - l) / 2; int ret = 0;
		if (L <= m) ret += sget(snodes[x].l, l, m, L, R);
		if (m + 1 <= R) ret += sget(snodes[x].r, m + 1, r, L, R);
		return ret;
	}
}
void smerge(int& x, int y) {
	if (y == -1) return; else if (x == -1) { x = y; return; }
	smerge(snodes[x].l, snodes[y].l); smerge(snodes[x].r, snodes[y].r);
	if (snodes[x].l == -1 && snodes[x].r == -1) snodes[x].sum += snodes[y].sum; else spull(x);
}

void calc(int id,int x,int at,int root) {
	int a = path[id][0], b = path[id][1];
	int extra = max(0, need - (dep[at] - dep[root]));
	if (dep[b] - dep[root] >= extra) {
		int to = extra == 0 ? root : calcup(b, dep[b] - dep[root] - extra);
		int cnt = sget(sndset[x], 0, n - 1, lid[to], rid[to]);
		//printf("root=%d at=%d: calc with %d..%d path -> to=%d (id=%d..%d) cnt=%d [x=%d]\n", root + 1, at + 1, a + 1, b + 1, to + 1, lid[to], rid[to], cnt, x);
		ans += cnt;
	}
}
int merge(int x, int y, int at, int root) {
	if (SZ(byfst[x]) < SZ(byfst[y])) swap(x, y);
	REPSZ(_, byfst[y]) {
		int id = byfst[y][_];
		calc(id, x, at, root);
		byfst[x].PB(id);
	}
	//printf("merging %d with %d\n", x, y);
	smerge(sndset[x], sndset[y]);
	byfst[y].clear(); sndset[y] = -1;
	return x;
}

int dfs2(int at, int root) {
	int ret = at;
	REPSZ(_, byfst[at]) {
		int id = byfst[at][_];
		int a = path[id][0], b = path[id][1];
		//printf("root=%d at=%d: adding %d (id=%d) to sndset (path is %d..%d) [x=%d]\n", root + 1, at + 1, b + 1, lid[b], a + 1, b + 1, ret);
		calc(id, ret, at, root);
		smod(sndset[ret], 0, n - 1, lid[b], +1);
	}
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at] || to == heavy[root]) continue;
		int sub = dfs2(to, root);
		ret = merge(ret, sub, at, root);
	}
	return ret;
}


ll solve() {
	par[0] = -1; dfsinit(0);
	nid = 0; dfsid(0);

	REP(i, n) bylca[i].clear();
	REP(i, npath) { int &a = path[i][0], &b = path[i][1]; if (lid[a] > lid[b]) swap(a, b); int c = lca(a, b); bylca[c].PB(i); }

	ans = 0;
	REPE(i, n) bit[i] = 0;
	dfs1(0);
	nsnodes = 0; REP(i, n) byfst[i].clear(), sndset[i] = -1;
	REP(at, n) {
		REPSZ(_, bylca[at]) {
			int id = bylca[at][_];
			int a = path[id][0], b = path[id][0];
			if (heavy[at] != -1) assert(!isdesc(a, heavy[at]));
			byfst[a].PB(id);
		}
		int sub = dfs2(at, at);
		assert(SZ(byfst[sub]) == SZ(bylca[at]));
		nsnodes = 0; byfst[sub].clear(); sndset[sub] = -1;
	}
	return ans;
}

void run() {
	scanf("%d%d%d", &n, &npath, &need);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b), adj[b].PB(a); }
	REP(i, npath) REP(j, 2) scanf("%d", &path[i][j]), --path[i][j];
	printf("%lld\n", solve());
}

ll solvestupid() {
	par[0] = -1; dfsinit(0); ll ret = 0;
	REP(i, npath) FOR(j, i + 1, npath) {
		int ai = path[i][0], bi = path[i][1], ci = lca(ai, bi);
		int aj = path[j][0], bj = path[j][1], cj = lca(aj, bj);
		set<int> have; while (ai != ci) have.insert(ai), ai = par[ai]; while (bi != ci) have.insert(bi), bi = par[bi];
		int cnt = 0; while (aj != cj) cnt += have.count(aj), aj = par[aj]; while (bj != cj) cnt += have.count(bj), bj = par[bj];
		if (cnt >= need) ++ret;
	}
	return ret;
}

void stress() {
	REP(rep, 1000000) {
		n = rnd() % (10 - 1) + 2;
		npath = rnd() % 10 + 1;
		need = rnd() % (n - 1) + 1;
		vector<pair<int, int>> e; vector<int> col(n); REP(i, n) col[i] = i;
		REP(i, n - 1) while (true) { int a = rnd() % n, b = rnd() % n; if (col[a] == col[b]) continue; int ocol = col[b]; REP(j, n) if (col[j] == ocol) col[j] = col[a]; e.PB(MP(a, b)); break; }
		REP(i, n) adj[i].clear(); REPSZ(i, e) { int a = e[i].first, b = e[i].second; adj[a].PB(b), adj[b].PB(a); }
		REP(i, npath) path[i][0] = rnd() % n, path[i][1] = rnd() % n;
		ll want = solvestupid();
		ll have = solve();
		if (have == want) { if (rep % 1000 == 999) printf("."); continue; }
		printf("err have=%lld want=%lld\n", have, want);
		printf("%d %d %d\n", n, npath, need);
		REPSZ(i, e) printf("%d %d\n", e[i].first + 1, e[i].second + 1);
		REP(i, npath) printf("%d %d\n", path[i][0] + 1, path[i][1] + 1);
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}