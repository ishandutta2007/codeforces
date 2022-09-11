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

const int MAXN = 200000;
const int MAXQ = 200000;
const int MAXLG = 17;

int n, nq;
vector<int> adj[MAXN];
int qkind[MAXQ], qx[MAXQ], qy[MAXQ], qdist[MAXQ]; bool qans[MAXQ];

int par[MAXN], dep[MAXN];
int sz[MAXN], heavy[MAXN];
int up[MAXN][MAXLG + 1];
int lorder[MAXN], rorder[MAXN], norder;
int hroot[MAXN], hidx[MAXN], nh;

int lcacnt[MAXN]; // number of times a node is a lca of an active path
multiset<int> lightdesc[MAXN]; // depths of lca's of active paths in subtrees of light childs
multiset<pair<int,int>> subtree[MAXN]; // only for roots of heavy paths, the depths of lca's in its subtree (depth,node)
set<pair<int, int>> lightsubtrees[MAXN]; // for each light subtree the depth of the deepest lca in that subtree (depth,subtree)

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	sz[at] = 1;
	heavy[at] = -1;
	up[at][0] = par[at] == -1 ? at : par[at]; REP(k, MAXLG) up[at][k + 1] = up[up[at][k]][k];
	lorder[at] = norder++;
	REPSZ(i, adj[at]) {
		int to = adj[at][i];
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
		sz[at] += sz[to];
		if (heavy[at] == -1 || sz[to] > sz[heavy[at]]) heavy[at] = to;
	}
	rorder[at] = norder - 1;
}

int calclca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int k = MAXLG; k >= 0; --k) if (dep[a] - (1 << k) >= dep[b]) a = up[a][k];
	if (a == b) return a;
	for (int k = MAXLG; k >= 0; --k) if (up[a][k] != up[b][k]) a = up[a][k], b = up[b][k];
	assert(a != b && par[a] == par[b]);
	return par[a];
}

int calcup(int a, int n) {
	REPE(k, MAXLG) if (n&(1 << k)) a = up[a][k];
	return a;
}

struct BIT {
	int n;
	vector<int> val;
	void init(int _n) { n = _n; val = vector<int>(n + 1, 0); }
	void mod(int idx, int by) { ++idx; while (idx <= n) { val[idx] += by; idx += idx&-idx; } }
	int get(int idx) { ++idx; int ret = 0; while (idx > 0) { ret += val[idx]; idx -= idx&-idx; } return ret; }
	int get(int l, int r) { return get(r) - get(l - 1); }
};

struct SegTree {
	int n;
	vector<int> val;

	void init(int _n) { n = _n; val = vector<int>(4 * n, INT_MIN); }
	void set(int x, int l, int r, int IDX, int VAL) {
		if (l == r) {
			val[x] = VAL;
		} else {
			int m = l + (r - l) / 2;
			if (IDX <= m) set(2 * x + 1, l, m, IDX, VAL); else set(2 * x + 2, m + 1, r, IDX, VAL);
			val[x] = max(val[2 * x + 1], val[2 * x + 2]);
		}
	}
	void set(int idx, int val) { set(0, 0, n - 1, idx, val); }
	int get(int x, int l, int r, int L, int R) {
		if (L <= l&&r <= R) {
			return val[x];
		} else {
			int m = l + (r - l) / 2, ret = INT_MIN;
			if (L <= m) ret = max(ret, get(2 * x + 1, l, m, L, R));
			if (m + 1 <= R) ret = max(ret, get(2 * x + 2, m + 1, r, L, R));
			return ret;
		}
	}
	int get(int l, int r) { return get(0, 0, n - 1, l, r); }
};

BIT orderbit;
SegTree ordersegtree;
SegTree lightdescsegtree;

template<class T,class U> void toggle(T &s, U val,int by) {
	if (by == +1) s.insert(val); else { auto it = s.find(val); assert(it != s.end()); s.erase(it); }
}

void lcachange(int lca, int by) {
	lcacnt[lca] += by;
	ordersegtree.set(lorder[lca], lcacnt[lca] == 0 ? INT_MIN : dep[lca]);
	int at = lca;
	while (true) {
		at = hroot[at];
		if (SZ(subtree[at]) != 0 && par[at] != -1) toggle(lightsubtrees[par[at]], MP(prev(subtree[at].end())->first, at), -1);
		toggle(subtree[at], MP(dep[lca], lca), by);
		if (SZ(subtree[at]) != 0 && par[at] != -1) toggle(lightsubtrees[par[at]], MP(prev(subtree[at].end())->first, at), +1);
		at = par[at];
		if (at == -1) break;
		toggle(lightdesc[at], dep[lca], by);
		int val = SZ(lightdesc[at]) == 0 ? INT_MIN : *prev(lightdesc[at].end()) - 2 * dep[at];
		lightdescsegtree.set(hidx[at], val);
	}
}


// return maximum distance of x to any lca that is in a sibling subtree of the path from x to y (y being an ancestor of x)
int getfarthest(int x, int y) {
	int ret = INT_MIN;
	int at = x;
	{
		int cur = ordersegtree.get(lorder[at], rorder[at]);
		//printf("desc of x: %d\n", cur == INT_MIN ? INT_MIN : cur + dep[x] - 2 * dep[x]);
		if (cur != INT_MIN) ret = max(ret, cur + dep[x] - 2 * dep[x]);
	}
	while (hroot[at] != hroot[y]) {
		if (at != hroot[at]) {
			int cur = lightdescsegtree.get(hidx[hroot[at]], hidx[par[at]]);
			//printf("light descendant of %d..%d: %d\n", hroot[at] + 1, par[at] + 1, cur == INT_MIN ? INT_MIN : cur + dep[x]);
			if (cur != INT_MIN) ret = max(ret, cur + dep[x]);
		}
		at = hroot[at];
		assert(par[at] != -1);
		auto it = lightsubtrees[par[at]].end();
		while (it != lightsubtrees[par[at]].begin()) {
			--it;
			if (it->second == at) continue;
			//printf("light descendant of %d: %d\n", at + 1, it->first + dep[x] - 2 * dep[par[at]]);
			ret = max(ret, it->first + dep[x] - 2 * dep[par[at]]);
			break;
		}
		at = par[at];
		if (heavy[at] != -1) {
			int cur = ordersegtree.get(lorder[heavy[at]], rorder[heavy[at]]);
			//printf("heavy descendant of %d: %d\n", at + 1, cur == INT_MIN ? INT_MIN : cur + dep[x] - 2 * dep[at]);
			if (cur != INT_MIN) ret = max(ret, cur + dep[x] - 2 * dep[at]);
		}
	}
	if (at != y) {
		int cur = lightdescsegtree.get(hidx[y], hidx[par[at]]);
		//printf("light descendant of %d..%d: %d\n", y + 1, par[at] + 1, cur == INT_MIN ? INT_MIN : cur + dep[x]);
		if (cur != INT_MIN) ret = max(ret, cur + dep[x]);
	}
	return ret;
}

bool calc(int dist) {
	//printf("calc(%d)\n", dist);
	assert(SZ(subtree[0]) != 0);
	int deeplca = prev(subtree[0].end())->second;
	//printf("deeplca=%d (dep=%d)\n", deeplca + 1, dep[deeplca]);
	if (dep[deeplca] <= dist) return true;
	int common = calcup(deeplca, dist);
	int top;
	if (dep[common] <= dist) {
		top = 0;
	} else {
		top = calcup(common, dist);
	}
	//printf("top=%d -> %d..%d n=%d\n", top, lorder[top], rorder[top], n);
	int have = orderbit.get(lorder[top], rorder[top]);
	int want = SZ(subtree[0]);
	//printf("common=%d top=%d have=%d want=%d\n", common + 1, top + 1, have, want);
	if (have != want) return false;
	int mx = getfarthest(common, top);
	//printf("mx=%d\n", mx);
	return mx <= dist;
}

void solve() {
	par[0] = -1;
	norder = 0;
	dfsinit(0);
	nh = 0;
	REP(at, n) if (par[at] == -1 || at != heavy[par[at]]) for (int x = at; x != -1; x = heavy[x]) hroot[x] = at, hidx[x] = nh++;

	orderbit.init(norder);
	ordersegtree.init(norder);
	lightdescsegtree.init(nh);
	REP(at, n) lcacnt[at] = 0, lightdesc[at].clear(), subtree[at].clear(), lightsubtrees[at].clear();

	REP(i, nq) {
		//printf("processing q%d\n", i);
		if (qkind[i] != 3) {
			int by = qkind[i] == 1 ? +1 : -1;
			int a = qx[i], b = qy[i];
			int c = calclca(a, b);
			orderbit.mod(lorder[a], +by);
			orderbit.mod(lorder[b], +by);
			orderbit.mod(lorder[c], -by);
			lcachange(c, by);
		} else {
			qans[i] = calc(qdist[i]);
		}
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	REP(i, nq) { scanf("%d", &qkind[i]); if (qkind[i] != 3) scanf("%d%d", &qx[i], &qy[i]), --qx[i], --qy[i]; else scanf("%d", &qdist[i]); }
	solve();
	REP(i, nq) if (qkind[i] == 3) printf("%s\n", qans[i] ? "Yes" : "No");
}

bool qansstupid[MAXQ];

bool findstupidpath(int at, int par, int dst, vector<int> &path) {
	path.PB(at);
	if (at == dst) return true;
	REPSZ(i, adj[at]) {
		int to = adj[at][i];
		if (to == par) continue;
		if (findstupidpath(to, at, dst, path)) return true;
	}
	path.pop_back();
	return false;
}

void solvestupid() {
	multiset<pair<int, int>> paths;
	REP(i, nq) {
		if (qkind[i] != 3) {
			int by = qkind[i] == 1 ? +1 : -1, a = qx[i], b = qy[i];
			if (a > b) swap(a, b);
			toggle(paths, MP(a, b), by);
		} else {
			vector<int> cnt(n, 0);
			for (auto it = paths.begin(); it != paths.end(); ++it) {
				vector<int> path;
				assert(findstupidpath(it->first, -1, it->second, path));
				vector<int> dist(n, -1);
				queue<int> q;
				REPSZ(j, path) dist[path[j]] = 0, q.push(path[j]);
				while (!q.empty()) {
					int at = q.front(); q.pop();
					++cnt[at];
					if (dist[at] >= qdist[i]) continue;
					REPSZ(j, adj[at]) {
						int to = adj[at][j];
						if (dist[to] != -1) continue;
						dist[to] = dist[at] + 1, q.push(to);
					}
				}
			}
			qansstupid[i] = false;
			REP(j, n) if (cnt[j] == SZ(paths)) qansstupid[i] = true;
		}
	}
}

void stress() {
	REP(rep, 1000000) {
		n = rnd() % 10 + 1;
		vector<int> col(n); REP(i, n) col[i] = i;
		REP(i, n) adj[i].clear();
		vector<pair<int, int>> edges;
		REP(i, n - 1) while (true) { int a = rnd() % n, b = rnd() % n; if (col[a] == col[b]) continue; int ocol = col[b]; REP(j, n) if (col[j] == ocol) col[j] = col[a]; adj[a].PB(b), adj[b].PB(a); edges.PB(MP(a, b)); break; }
		nq = rnd() % 10 + 1;
		vector<pair<int, int>> exist;
		REP(i, nq) while (true) {
			qkind[i] = rnd() % 3 + 1;
			if (qkind[i] == 1) { int a = rnd() % n, b = rnd() % n; qx[i] = a, qy[i] = b; exist.PB(MP(a, b)); }
			if (qkind[i] == 2) { if (SZ(exist) == 0) continue; int idx = rnd() % SZ(exist); int a = exist[idx].first, b = exist[idx].second; qx[i] = a, qy[i] = b; exist.erase(exist.begin() + idx); }
			if (qkind[i] == 3) { if (SZ(exist) == 0) continue; qdist[i] = rnd() % n; }
			break;
		}
		solve();
		solvestupid();
		bool ok = true; REP(i, nq) if (qkind[i] == 3 && qans[i] != qansstupid[i]) ok = false;
		if (ok) { if(rep%1000==999) printf("."); continue; }
		printf("err\n");
		printf("have:"); REP(i, nq) if (qkind[i] == 3) printf(" %s", qans[i] ? "Yes" : "No"); puts("");
		printf("want:"); REP(i, nq) if (qkind[i] == 3) printf(" %s", qansstupid[i] ? "Yes" : "No"); puts("");
		printf("%d %d\n", n, nq);
		REPSZ(i, edges) printf("%d %d\n", edges[i].first + 1, edges[i].second + 1);
		REP(i, nq) { printf("%d", qkind[i]); if (qkind[i] != 3) printf(" %d %d\n", qx[i] + 1, qy[i] + 1); else printf(" %d\n", qdist[i]); }
	}
}

int main() {
	//stress();
	run();
	return 0;
}