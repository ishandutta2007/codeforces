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

const int MAXBIT = 50;
const int MAXQ = 50000;
struct Block { ll l, r; int t; Block() {} Block(ll l, ll r, int t) :l(l), r(r), t(t) {} };
struct Node { ll l, r; int t; Node() {} Node(ll l, ll r, int t) :l(l), r(r), t(t) {} };

int nbit, nq;
char qkind[MAXQ][5 + 1]; ll qa[MAXQ], qb[MAXQ];
bool qans[MAXQ];

vector<Node> nodes;
vector<vector<int>> adj;
int makenode(ll l, ll r, int t) { int ret = SZ(nodes); nodes.PB(Node(l, r, t)); adj.PB(vector<int>()); return ret; }

vector<int> buildgraph(ll l, ll r, const vector<Block>& blocks) {
	//printf("rec(%lld,%lld,SZ=%d)\n", l, r, SZ(blocks)); for (const Block& b : blocks) printf("\t%lld..%lld = %d\n", b.l, b.r, b.t);
	if (SZ(blocks) == 0) return { makenode(l,r,-1) };
	if (SZ(blocks) == 1 && blocks[0].l <= l && r <= blocks[0].r) return { makenode(l,r,blocks[0].t) };
	assert(r - l >= 2);
	ll m = l + (r - l) / 2;
	vector<Block> lblocks, rblocks;
	for (const Block& b : blocks) { if (b.l < m) lblocks.PB(b); if (b.r > m) rblocks.PB(b); }
	vector<int> lnodes = buildgraph(l, m, lblocks);
	vector<int> rnodes = buildgraph(m, r, rblocks);
	int li = 0, ri = 0;
	while (li < SZ(lnodes) && ri < SZ(rnodes)) {
		int lidx = lnodes[li], ridx = rnodes[ri];
		adj[lidx].PB(ridx), adj[ridx].PB(lidx);
		//printf("edge [%lld..%lld] - [%lld..%lld]\n", nodes[lidx].l, nodes[lidx].r - 1, nodes[ridx].l, nodes[ridx].r - 1);
		ll nxt = min(nodes[lidx].r - l, nodes[ridx].r - m);
		if (nodes[lidx].r - l == nxt) ++li;
		if (nodes[ridx].r - m == nxt) ++ri;
	}

	vector<int> ret; for (int x : lnodes) ret.PB(x); for (int x : rnodes) ret.PB(x); return ret;
}

struct UF {
	int n; vector<int> par, sz;
	void init(int _n) { n = _n; par = sz = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1; }
	int find(int x) { if (par[x] == x) return x; return par[x] = find(par[x]); }
	void unite(int x, int y) { x = find(x), y = find(y); if (x == y) return; if (sz[x] < sz[y]) swap(x, y); par[y] = x, sz[x] += sz[y]; }
};

int search(ll x) {
	//printf("searching %lld\n", x);
	int lo = -1, hi = SZ(nodes);
	while (lo + 1 < hi) {
		int mi = lo + (hi - lo) / 2;
		if (x >= nodes[mi].l) lo = mi; else hi = mi;
	}
	int ret = lo >= 0 && x < nodes[lo].r ? lo : -1;
	//printf("->%d\n", ret);
	return ret;
}

void solve() {
	vector<Block> blocks;
	REP(i, nq) if (strcmp(qkind[i], "block") == 0) blocks.PB(Block(qa[i], qb[i] + 1, i));
	nodes.clear();
	adj.clear();
	buildgraph(0, 1LL << nbit, blocks);
	//REPSZ(i, nodes) printf("%d: [%lld..%lld] = %d\n", i, nodes[i].l, nodes[i].r, nodes[i].t);
	UF uf;
	uf.init(SZ(nodes));
	//printf("here\n");
	vector<vector<int>> who(nq);
	REPSZ(at, nodes) {
		if (nodes[at].t != -1) { who[nodes[at].t].PB(at); continue; }
		for (int to : adj[at]) if (nodes[to].t == -1) uf.unite(at, to);
	}
	//printf("here\n");
	for (int i = nq - 1; i >= 0; --i) {
		//printf("i=%d\n", i);
		if (strcmp(qkind[i], "block") == 0) {
			//printf("block\n");
			for (int at : who[i]) {
				for (int to : adj[at]) {
					if (nodes[to].t == -1 || nodes[to].t >= i) uf.unite(at, to);
				}
			}
		}
		if (strcmp(qkind[i], "ask") == 0) {
			int a = search(qa[i]), b = search(qb[i]);
			assert(a != -1 && (nodes[a].t == -1 || nodes[a].t > i));
			assert(b != -1 && (nodes[b].t == -1 || nodes[b].t > i));
			qans[i] = uf.find(a) == uf.find(b);
		}
	}
}

void run() {
	scanf("%d%d", &nbit, &nq);
	REP(i, nq) scanf("%s%lld%lld", &qkind[i], &qa[i], &qb[i]);
	solve();
	REP(i, nq) if (strcmp(qkind[i], "ask") == 0) printf("%d\n", qans[i] ? 1 : 0);
}

int main() {
	run();
	return 0;
}