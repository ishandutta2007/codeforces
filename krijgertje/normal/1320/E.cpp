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
const int MAXQ = 200000;

struct T {
	int n;
	vector<pair<int,int>> adj[MAXN];
	T() { n = 0; }
	void reset() { REP(i, n) adj[i].clear(); n = 0; }
	int addnode() { int ret = n++; adj[ret].clear(); return ret; }
	void addedge(int a, int b, int c) { adj[a].PB(MP(b, c)), adj[b].PB(MP(a, c)); }
	void print(int at = 0, int par = -1) { printf("[%d", at); REPSZ(i, adj[at]) { int to = adj[at][i].first, len = adj[at][i].second; if (to == par) continue; printf(":%d=", len); print(to, at); } printf("]"); }
};
struct LCA {
	int lgn;
	vector<int> dep;
	vector<vector<int>> up;

	void dfsinit(const T &t, int at, int par) {
		dep[at] = par == -1 ? 0 : dep[par] + 1; up[at][0] = par == -1 ? at : par; REP(k, lgn) up[at][k + 1] = up[up[at][k]][k];
		REPSZ(i, t.adj[at]) { int to = t.adj[at][i].first; if (to == par) continue; dfsinit(t, to, at); }
	}

	void init(const T &t) {
		lgn = 0; while ((2 << lgn) <= t.n - 1) ++lgn;
		dep = vector<int>(t.n, -1);
		up = vector<vector<int>>(t.n, vector<int>(lgn + 1, -1));
		dfsinit(t, 0, -1);
	}
	int calc(int a, int b) {
		if (dep[a]<dep[b]) swap(a, b);
		for (int k = lgn; k >= 0; --k) if (dep[a] - (1 << k) >= dep[b]) a = up[a][k];
		for (int k = lgn; k >= 0; --k) if (up[a][k] != up[b][k]) a = up[a][k], b = up[b][k];
		return a == b ? a : up[a][0];
	}
};
struct TreeCompressor {
	vector<int> preidx, rootdist;
	LCA lca;

	void dfsinit(const T &t, int at, int par, int parlen, int &npre) {
		preidx[at] = npre++; rootdist[at] = par == -1 ? 0 : rootdist[par] + parlen;
		REPSZ(i, t.adj[at]) { int to = t.adj[at][i].first; if (to == par) continue; dfsinit(t, to, at, t.adj[at][i].second, npre); }
	}

	void init(const T &t) {
		preidx = rootdist = vector<int>(t.n, -1);
		int npre = 0; dfsinit(t, 0, -1, 0, npre);
		lca.init(t);
	}

	vector<int> build(const vector<int> &special, T &result) {
		vector<pair<int, int>> o; REPSZ(i, special) o.PB(MP(preidx[special[i]], i)); sort(o.begin(), o.end());
		vector<int> ret(SZ(special), -1); result.reset(); vector<pair<int, int>> path;
		int root = 0, rootid = result.addnode(); path.PB(MP(root, rootid));
		REPSZ(i, o) {
			int idx = o[i].second, at = special[idx];
			int x = lca.calc(at, path[SZ(path) - 1].first);
			while (SZ(path) >= 2 && rootdist[x] <= rootdist[path[SZ(path) - 2].first]) { pair<int,int> a = path[SZ(path) - 2], b = path[SZ(path) - 1]; result.addedge(a.second, b.second, rootdist[b.first] - rootdist[a.first]); path.pop_back(); }
			if (rootdist[x] < rootdist[path[SZ(path) - 1].first]) { pair<int, int> b = path[SZ(path) - 1]; int xid = result.addnode(); result.addedge(xid, b.second, rootdist[b.first] - rootdist[x]); path.pop_back(); path.PB(MP(x, xid)); }
			if (rootdist[at] > rootdist[x]) { int atid = result.addnode(); path.PB(MP(at, atid)); }
			ret[idx] = path[SZ(path) - 1].second;
		}
		while (SZ(path) >= 2) { pair<int, int> a = path[SZ(path) - 2], b = path[SZ(path) - 1]; result.addedge(a.second, b.second, rootdist[b.first] - rootdist[a.first]); path.pop_back(); }
		return ret;
	}
};

int n;
T orig;
int nq;
vector<pair<int, int>> viruses[MAXQ];
vector<int> queries[MAXQ];
vector<int> answers[MAXQ];

T compressed;
TreeCompressor compressor;
int scolor[MAXN], sspeed[MAXN];

int t[MAXN][2], via[MAXN][2], col[MAXN][2], dist[MAXN][2], speed[MAXN][2];

void upd(int at, int cvia, int ccol, int cdist, int cspeed) {
	//printf("\tupd(%d,via=%d,col=%d,dist=%d,speed=%d)\n", at, cvia, ccol, cdist, cspeed);
	int ct = (cdist + cspeed - 1) / cspeed;
	if (ct < t[at][0] || ct == t[at][0] && ccol < col[at][0]) t[at][1] = t[at][0], via[at][1] = via[at][0], col[at][1] = col[at][0], dist[at][1] = dist[at][0], speed[at][1] = speed[at][0], t[at][0] = ct, via[at][0] = cvia, col[at][0] = ccol, dist[at][0] = cdist, speed[at][0] = cspeed;
	else if (ct < t[at][1] || ct == t[at][1] && ccol < col[at][1]) t[at][1] = ct, via[at][1] = cvia, col[at][1] = ccol, dist[at][1] = cdist, speed[at][1] = cspeed;
}
void dfsdn(int at, int par) {
	if (scolor[at] != -1) upd(at, at, scolor[at], 0, sspeed[at]);
	REPSZ(i, compressed.adj[at]) {
		int to = compressed.adj[at][i].first, len = compressed.adj[at][i].second; if (to == par) continue;
		dfsdn(to, at);
		if (t[to][0] != INT_MAX) upd(at, to, col[to][0], dist[to][0] + len, speed[to][0]);
	}
}
void dfsup(int at, int par) {
	REPSZ(i, compressed.adj[at]) {
		int to = compressed.adj[at][i].first, len = compressed.adj[at][i].second; if (to == par) continue;
		int idx = via[at][0] != to ? 0 : 1;
		if (t[at][idx] != INT_MAX) upd(to, at, col[at][idx], dist[at][idx] + len, speed[at][idx]);
		dfsup(to, at);
	}
}

void calc() {
	REP(i, compressed.n) REP(j, 2) t[i][j] = dist[i][j] = INT_MAX, via[i][j] = col[i][j] = -1, speed[i][j] = 0;
	dfsdn(0, -1);
	dfsup(0, -1);
}

void solve() {
	compressor.init(orig);
	REP(q, nq) {
		//printf("q%d:", q); REPSZ(i, viruses[q]) printf(" [%d,%d]", viruses[q][i].first + 1, viruses[q][i].second); REPSZ(i, queries[q]) printf(" %d", queries[q][i] + 1); puts("");
		vector<int> special; REPSZ(i, viruses[q]) special.PB(viruses[q][i].first); REPSZ(i, queries[q]) special.PB(queries[q][i]);
		vector<int> mapping = compressor.build(special, compressed);
		//compressed.print(); puts("");
		//printf("mapping:"); REPSZ(i, mapping) printf(" %d", mapping[i]); puts("");
		REP(i, compressed.n) scolor[i] = -1, sspeed[i] = -1;
		REPSZ(i, viruses[q]) { int at = mapping[i]; assert(scolor[at] == -1); scolor[at] = i; sspeed[at] = viruses[q][i].second; }
		calc();
		answers[q].resize(SZ(queries[q])); REPSZ(i, answers[q]) answers[q][i] = col[mapping[SZ(viruses[q]) + i]][0];
	}
}

void run() {
	scanf("%d", &n);
	orig.reset(); REP(i, n) orig.addnode();
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; orig.addedge(a, b, 1); }
	scanf("%d", &nq);
	REP(i, nq) { 
		int nvirus, nquery; scanf("%d%d", &nvirus, &nquery); 
		viruses[i].resize(nvirus); REP(j, nvirus) scanf("%d%d", &viruses[i][j].first, &viruses[i][j].second), --viruses[i][j].first;
		queries[i].resize(nquery); REP(j, nquery) scanf("%d", &queries[i][j]), --queries[i][j];
	}
	solve();
	REP(i, nq) { REPSZ(j, answers[i]) { if (j != 0) printf(" "); printf("%d", answers[i][j] + 1); } puts(""); }
}

int main() {
	run();
	return 0;
}