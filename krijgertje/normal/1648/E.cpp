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

const int MAXN = 200000;
const int MAXM = 200000;
const int MAXLG = 17;
struct E { int a, b, c, id; };
struct Comp { int subhead, subtail, tmphead, tmptail; bool deleted; Comp() { subhead = subtail = tmphead = tmptail = -1; deleted = false; } };
struct Sub { int prv, nxt, nodehead, nodetail, tmphead, tmptail; bool incomp,deleted; Sub() { prv = nxt = nodehead = nodetail = tmphead = tmptail = -1; incomp = deleted = false; } };
struct Node { int prv, nxt; bool insub; Node() { prv = nxt = -1; insub = false; } };

int n, m;
E e[MAXM];
int ans[MAXM];

struct UF {
	int n; vector<int> par, sz;
	void init(int _n) { n = _n; par = sz = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1; }
	int find(int x) { if (par[x] == x) return x; return par[x] = find(par[x]); }
	void unite(int x, int y) { x = find(x); y = find(y); if (x == y) return; if (sz[x] < sz[y]) swap(x, y); par[y] = x, sz[x] += sz[y]; }
};
UF compuf;

Comp comp[MAXN];
Sub sub[MAXN];
Node node[MAXN];
set<pair<int, int>> eset;
vector<vector<pair<int, int>>> adj;

void addsub(Comp &c, int s, bool totmp) {
	assert(sub[s].prv == -1 && sub[s].nxt == -1 && !sub[s].incomp && !c.deleted && !sub[s].deleted);
	sub[s].prv = (totmp ? c.tmptail : c.subtail);
	sub[s].nxt = -1;
	if (sub[s].prv == -1) (totmp ? c.tmphead : c.subhead) = s; else sub[sub[s].prv].nxt = s;
	(totmp ? c.tmptail : c.subtail) = s;
	sub[s].incomp = true;
}
void addnode(Sub &s, int n, bool totmp) {
	assert(node[n].prv == -1 && node[n].nxt == -1 && !node[n].insub && !s.deleted);
	node[n].prv = (totmp ? s.tmptail : s.nodetail);
	node[n].nxt = -1;
	if (node[n].prv == -1) (totmp ? s.tmphead : s.nodehead) = n; else node[node[n].prv].nxt = n;
	(totmp ? s.tmptail : s.nodetail) = n;
	node[n].insub = true;
}
void removesub(Comp &c, int s) {
	assert(sub[s].incomp && !c.deleted && !sub[s].deleted);
	if (sub[s].prv == -1) { assert(c.subhead == s); c.subhead = sub[s].nxt; } else sub[sub[s].prv].nxt = sub[s].nxt;
	if (sub[s].nxt == -1) { assert(c.subtail == s); c.subtail = sub[s].prv; } else sub[sub[s].nxt].prv = sub[s].prv;
	sub[s].prv = sub[s].nxt = -1, sub[s].incomp = false;
}
void movenodes(Sub &a, Sub &b, bool totmp) {
	assert(!a.deleted && !b.deleted);
	if (a.nodehead == -1) return;
	int n = a.nodehead;
	node[n].prv = (totmp ? b.tmptail : b.nodetail);
	if (node[n].prv == -1) (totmp ? b.tmphead : b.nodehead) = n; else node[node[n].prv].nxt = n;
	(totmp ? b.tmptail : b.nodetail) = a.nodetail;
	a.nodehead = a.nodetail = -1;
}
void movetmpnodes(Sub &a, Sub &b, bool totmp) {
	assert(!a.deleted && !b.deleted);
	if (a.tmphead == -1) return;
	int n = a.tmphead;
	node[n].prv = (totmp ? b.tmptail : b.nodetail);
	if (node[n].prv == -1) (totmp ? b.tmphead : b.nodehead) = n; else node[node[n].prv].nxt = n;
	(totmp ? b.tmptail : b.nodetail) = a.tmptail;
	a.tmphead = a.tmptail = -1;
}
void deletesub(int s) {
	//printf("deleting %d: %d %d %d %d %d %d\n", s, sub[s].deleted ? 1 : 0, sub[s].incomp ? 1 : 0, sub[s].nodehead, sub[s].nodetail, sub[s].tmphead, sub[s].tmptail);
	assert(!sub[s].deleted && !sub[s].incomp && sub[s].nodehead == -1 && sub[s].nodetail == -1 && sub[s].tmphead == -1 && sub[s].tmptail == -1);
	sub[s].deleted = true;
}
void deletecomp(int c) {
	assert(!comp[c].deleted && comp[c].subhead == -1 && comp[c].subtail == -1 && comp[c].tmphead == -1 && comp[c].tmptail == -1);
	comp[c].deleted = true;
}
void persist(Comp &c) {
	assert(!c.deleted);
	if (c.tmphead == -1) return;
	int s = c.tmphead;
	sub[s].prv = c.subtail;
	if (sub[s].prv == -1) c.subhead = s; else sub[sub[s].prv].nxt = s;
	c.subtail = c.tmptail;
	c.tmphead = c.tmptail = -1;
}
void persist(Sub &s) {
	assert(!s.deleted);
	if (s.tmphead == -1) return;
	int n = s.tmphead;
	node[n].prv = s.nodetail;
	if (node[n].prv == -1) s.nodehead = n; else node[node[n].prv].nxt = n;
	s.nodetail = s.tmptail;
	s.tmphead = s.tmptail = -1;
}

int par[MAXN], wpar[MAXN], dep[MAXN];
int up[MAXN][MAXLG + 1];
int wup[MAXN][MAXLG + 1];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	up[at][0] = par[at] == -1 ? at : par[at];
	wup[at][0] = par[at] == -1 ? 0 : wpar[at];
	REP(k, MAXLG) up[at][k + 1] = up[up[at][k]][k], wup[at][k + 1] = max(wup[at][k], wup[up[at][k]][k]);
	for (const auto &z : adj[at]) {
		int to = z.first, w = z.second;
		if (to == par[at]) continue;
		assert(par[to] == -2);
		par[to] = at;
		wpar[to] = w;
		dfsinit(to);
	}
}
int lca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int k = MAXLG; k >= 0; --k) if (dep[a] - (1 << k) >= dep[b]) a = up[a][k];
	if (a == b) return a;
	for (int k = MAXLG; k >= 0; --k) if (up[a][k] != up[b][k]) a = up[a][k], b = up[b][k];
	return par[a];
}
int calc(int a, int nstep) {
	int ret = 0;
	REPE(k, MAXLG) if (nstep & (1 << k)) ret = max(ret, wup[a][k]), a = up[a][k];
	return ret;
}

void solve() {
	sort(e, e + m, [&](const E &p, const E &q) { return p.c < q.c; });
	adj = vector<vector<pair<int, int>>>(n);
	int adjcnt = 0;
	eset.clear();
	REP(i, m) { int a = e[i].a, b = e[i].b; eset.insert(MP(a, b)); eset.insert(MP(b, a)); }
	compuf.init(n);
	REP(i, n) {
		comp[i] = Comp();
		sub[i] = Sub();
		node[i] = Node();
		addsub(comp[i], i, false);
		addnode(sub[i], i, false);
	}
	REP(i, m) {
		int a = compuf.find(e[i].a);
		int b = compuf.find(e[i].b);
		if (a == b) continue;
		//printf("found regular tree edge: %d-%d with cost %d\n", e[i].a + 1, e[i].b + 1, e[i].c);
		compuf.unite(a, b);
		if (compuf.find(b) != b) swap(a, b);
		while(true) {
			int asub = comp[a].subhead;
			if (asub == -1) break;
			removesub(comp[a], asub);
			vector<int> bmerge;
			for (int bsub = comp[b].subhead; bsub != -1; bsub = sub[bsub].nxt) {
				bool merged = false;
				for (int anode = sub[asub].nodehead; anode != -1 && !merged; anode = node[anode].nxt) {
					for (int bnode = sub[bsub].nodehead; bnode != -1 && !merged; bnode = node[bnode].nxt) {
						pair<int, int> key = MP(anode, bnode);
						if (eset.count(key)) continue;
						//printf("\tfound opposite edge %d-%d with cost %d\n", anode + 1, bnode + 1, e[i].c);
						adj[anode].PB(MP(bnode, e[i].c));
						adj[bnode].PB(MP(anode, e[i].c));
						++adjcnt;
						merged = true;
						bmerge.PB(bsub);
					}
				}
			}
			if (SZ(bmerge) == 0) {
				addsub(comp[b], asub, true);
			} else {
				FORSZ(j, 1, bmerge) {
					removesub(comp[b], bmerge[j]);
					movenodes(sub[bmerge[j]], sub[bmerge[0]], false);
					movetmpnodes(sub[bmerge[j]], sub[bmerge[0]], true);
					deletesub(bmerge[j]);
				}
				movenodes(sub[asub], sub[bmerge[0]], true);
				deletesub(asub);
			}
		}
		deletecomp(a);
		persist(comp[b]);
		for (int bsub = comp[b].subhead; bsub != -1; bsub = sub[bsub].nxt) {
			persist(sub[bsub]);
		}
	}
	assert(adjcnt == n - 1);
	REP(i, n) par[i] = -2;
	par[0] = -1; dfsinit(0);
	REP(i, n) assert(par[i] != -2);
	REP(i, m) {
		int a = e[i].a, b = e[i].b, id = e[i].id;
		int c = lca(a, b);
		ans[id] = max(calc(a, dep[a] - dep[c]), calc(b, dep[b] - dep[c]));
	}
}


void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].c), --e[i].a, --e[i].b, e[i].id = i;
	solve();
	REP(i, m) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}