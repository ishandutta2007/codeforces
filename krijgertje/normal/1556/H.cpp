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

const int MAXN = 50;
const int MAXSPECIAL = 5;

int n, nspecial;
int deglim[MAXSPECIAL];
int w[MAXN][MAXN];

struct DSU {
	int n; vector<int> par, sz;
	void init(int _n) { n = _n; par = sz = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1; }
	int find(int x) { if (par[x] == x) return x; return par[x] = find(par[x]); }
	bool unite(int x, int y) { x = find(x), y = find(y); if (x == y) return false; if (sz[x] < sz[y]) swap(x, y); sz[x] += sz[y], par[y] = x; return true; }
};

// Partition matroid
struct M1 {
	int ncol; vector<int> collim; vector<vector<int>> items;
	void init(int _ncol, vector<int> _collim) { ncol = _ncol; collim = _collim; items = vector<vector<int>>(ncol); }

	vector<bool> curset;
	vector<int> colcnt;
	vector<int> col;
	void update(const vector<bool>& _curset) {
		curset = _curset;
		col = vector<int>(SZ(curset), -1);
		REP(i, ncol) for (int x : items[i]) col[x] = i;
		colcnt = vector<int>(ncol, 0);
		REPSZ(x, curset) if (curset[x] && col[x] != -1) ++colcnt[col[x]];
		REP(i, ncol) assert(colcnt[i] <= collim[i]);
	}
	bool canadd(int x) { return col[x] == -1 || colcnt[col[x]] < collim[col[x]]; } // assumes !curset[x]
	vector<int> getallrevivedaddoptions(int x) { // assumes curset[x]
		vector<int> ret;
		if (col[x] != -1 && colcnt[col[x]] == collim[col[x]]) for (int y : items[col[x]]) if (!curset[y]) ret.PB(y);
		return ret;
	}
};

// Graphic matroid
struct M2 {
	int n; vector<pair<int, int>> edges;
	void init(int _n) { n = _n; edges = vector<pair<int, int>>(); }

	vector<vector<pair<int,int>>> forest;
	vector<int> par, parid, comp, dep; int ncomp;
	DSU dsu; vector<int> top;
	void dfsinit(int at) {
		for (const auto &z : forest[at]) {
			int to = z.first, id = z.second;
			if (id == parid[at]) continue;
			assert(comp[to] == -1);
			par[to] = at;
			parid[to] = id;
			comp[to] = comp[at];
			dep[to] = dep[at] + 1;
			dfsinit(to);
		}
	}
	void update(const vector<bool>& curset) {
		forest = vector<vector<pair<int,int>>>(n);
		REPSZ(x, curset) if (curset[x]) { int a = edges[x].first, b = edges[x].second; forest[a].PB(MP(b, x)); forest[b].PB(MP(a, x)); }
		ncomp = 0; par = parid = comp = dep = vector<int>(n, -1);
		REP(i, n) if (comp[i] == -1) {
			comp[i] = ncomp++; dep[i] = 0;
			dfsinit(i);
		}
		dsu.init(n); top = vector<int>(n); REP(i, n) top[i] = i;
	}
	bool canadd(int x) { int a = edges[x].first, b = edges[x].second; return comp[a] != comp[b]; } // assumes !curset[x]
	vector<int> getunvisitedremoveoptions(int x) { // assumes !curset[x] && !canadd(x)
		int a = edges[x].first, b = edges[x].second; assert(comp[a] == comp[b]);
		vector<int> ret;
		while (true) {
			a = top[dsu.find(a)], b = top[dsu.find(b)];
			if (a == b) break;
			if (dep[a] < dep[b]) swap(a, b);
			assert(par[a] != -1 && parid[a] != -1);
			ret.PB(parid[a]);
			int b = dsu.find(par[a]);
			dsu.unite(a, b);
			top[dsu.find(a)] = top[b];
		}
		return ret;
	}
	vector<int> getallremoveoptions(int x) { // assumes !curset[x] && !canadd(x)
		int a = edges[x].first, b = edges[x].second; assert(comp[a] == comp[b]);
		vector<int> ret;
		while (true) {
			if (a == b) break;
			if (dep[a] < dep[b]) swap(a, b);
			assert(par[a] != -1 && parid[a] != -1);
			ret.PB(parid[a]);
			a = par[a];
		}
		return ret;
	}
};

struct MatroidIntersection {
	int nitem; vector<int> w; M1 m1; M2 m2;
	void init(int _nitem, vector<int> _w, M1 _m1, M2 _m2) { nitem = _nitem, w = _w, m1 = _m1, m2 = _m2; }

	int solve() { // maximum intersection of m1 and m2 with maximum weight
		if (nitem == 0) return 0;
		int ret = 0;
		vector<bool> curset(nitem, false);
		vector<int> pot(nitem, 0);
		for (int it = 0;; ++it) {
			//printf("it %d: ", it); REP(x, nitem) printf("%c", curset[x] ? 'v' : '.'); puts("");
			m1.update(curset);
			m2.update(curset);
			//REP(at, nitem) if (curset[at]) for (int to : m1.getallrevivedaddoptions(at)) if (!(w[at] + pot[at] - w[to] - pot[to] >= 0)) { printf("nonneg edge: %d->%d = %d\n", at, to, w[at] + pot[at] - w[to] - pot[to]); exit(0); }
			//REP(at, nitem) if (!curset[at] && !m2.canadd(at)) for (int to : m2.getallremoveoptions(at)) assert(pot[at] - pot[to] >= 0);
			int n = nitem + 2, s = nitem, t = nitem + 1;
			vector<pair<int, int>> d(n, MP(INT_MAX, INT_MAX)); // wsum,steps
			vector<int> prv(n, -2);
			priority_queue<pair<pair<int, int>, int>> pq;
			auto relax = [&](int at, int to, pair<int, int> cost) { if (cost >= d[to]) return; d[to] = cost; prv[to] = at; pq.push(MP(MP(-cost.first, -cost.second), -to)); };
			relax(-1, s, MP(0, 0));
			while (!pq.empty()) {
				pair<int, int> cost = MP(-pq.top().first.first, -pq.top().first.second); int at = -pq.top().second; pq.pop();
				if (d[at] != cost) continue;
				//printf("\t%d = (%d,%d)\n", at, cost.first, cost.second);
				if (at == s) { REP(to, nitem) if (!curset[to] && m1.canadd(to)) relax(at, to, MP(cost.first - w[to] - pot[to], cost.second + 1)); continue; }
				if (at == t) continue; // don't break, because we need to update potentials
				if (curset[at]) {
					for (int to : m1.getallrevivedaddoptions(at)) relax(at, to, MP(cost.first + w[at] + pot[at] - w[to] - pot[to], cost.second + 1));
				} else {
					if (m2.canadd(at)) {
						relax(at, t, MP(cost.first + pot[at], cost.second + 1));
						REP(to, nitem) if (curset[to]) relax(at, to, MP(cost.first + pot[at] - pot[to], cost.second + 1));
					}
					else for (int to : m2.getallremoveoptions(at)) relax(at, to, MP(cost.first + pot[at] - pot[to], cost.second + 1));
				}
			}
			//printf("d:"); REP(i, n) printf(" %d:(%d,%d)", prv[i], d[i].first, d[i].second); puts("");

			if (d[t] == MP(INT_MAX, INT_MAX)) break;
			ret -= d[t].first;
			REP(x, nitem) pot[x] += d[x].first;
			for (int x = t; x != -1; x = prv[x]) curset[x] = !curset[x];
			//printf("pot:"); REP(x, nitem) printf(" %d", pot[x]); puts("");
		}
		//printf("-> %d\n", ret);
		return ret;
	}
};

int solve() {
	int ret = INT_MAX;
	vector<pair<int, int>> especial;
	REP(i, nspecial) FOR(j, i + 1, nspecial) especial.PB(MP(i, j));
	map<pair<vector<int>, vector<int>>, int> best;
	REP(mask, 1 << SZ(especial)) {
		vector<int> comp(nspecial, -1);
		vector<int> par(nspecial, -1);
		int ncomp = 0;
		bool cycle = false;
		REP(i, nspecial) if (comp[i] == -1) {
			comp[i] = ncomp++;
			queue<int> q;
			q.push(i);
			while (!q.empty()) {
				int at = q.front(); q.pop();
				REPSZ(j, especial) if (mask & (1 << j)) if (especial[j].first == at || especial[j].second == at) {
					int to = especial[j].first ^ especial[j].second ^ at;
					if (to == par[at]) { assert(comp[to] == comp[at]); continue; }
					if (comp[to] != -1) { assert(comp[to] == comp[at]); cycle = true; continue; }
					par[to] = at; comp[to] = comp[at]; q.push(to);
				}
			}
		}
		if (cycle) continue;
		vector<int> remlim(deglim, deglim + nspecial);
		REPSZ(j, especial) if (mask & (1 << j)) --remlim[especial[j].first], --remlim[especial[j].second];
		bool exceedlimit = false;
		REP(i, nspecial) if (remlim[i] < 0) exceedlimit = true;
		if (exceedlimit) continue;
		int startcost = 0;
		REPSZ(j, especial) if (mask & (1 << j)) startcost += w[especial[j].first][especial[j].second];
		if (nspecial == n) { if (ncomp == 1) ret = min(ret, startcost); continue; }
		vector<bool> comprem(ncomp, false);
		REP(i, nspecial) if (remlim[i] > 0) comprem[comp[i]] = true;
		bool isolatedcomp = false;
		REP(i, ncomp) if (comprem[i] == 0) isolatedcomp = true;
		if (isolatedcomp) continue;
		auto key = MP(comp, remlim);
		auto it = best.find(key);
		if (it == best.end()) best[key] = startcost; else it->second = min(it->second, startcost);
	}
	//printf("%d out of %d\n", SZ(best), 1 << SZ(especial));

	vector<pair<int, int>> optregular;
	vector<pair<int, pair<int, int>>> eregular;
	FOR(i, nspecial, n) FOR(j, i + 1, n) eregular.PB(MP(w[i][j], MP(i, j)));
	sort(eregular.begin(), eregular.end());
	DSU regulardsu;
	regulardsu.init(n - nspecial);
	for (const auto& z : eregular) {
		int a = z.second.first, b = z.second.second;
		if (regulardsu.unite(a - nspecial, b - nspecial)) optregular.PB(MP(a, b));
	}
	//printf("optregular:"); for (const auto& e : optregular) printf(" (%d,%d)=%d", e.first, e.second, w[e.first][e.second]); puts("");

	for (auto it = best.begin(); it != best.end(); ++it) {
		vector<int> comp = it->first.first, remlim = it->first.second; int startcost = it->second;
		//printf("comp:"); REP(i, nspecial) printf(" %d", comp[i]); printf(" remlim:"); REP(i, nspecial) printf(" %d", remlim[i]); puts("");
		int ncomp = 0;
		REP(i, nspecial) ncomp = max(ncomp, comp[i] + 1);
		vector<int> col(nspecial, -1);
		vector<int> collim;
		int ncol = 0;
		REP(i, nspecial) if (remlim[i] > 0) col[i] = ncol++, collim.PB(remlim[i]);
		int nitem = 0;
		vector<int> witem;
		M1 m1;
		m1.init(ncol, collim);
		M2 m2;
		m2.init(ncomp + n - nspecial);
		REP(i, nspecial) if (col[i] != -1) FOR(j, nspecial, n) {
			int curitem = nitem++;
			witem.PB(-w[i][j]);
			m1.items[col[i]].PB(curitem);
			m2.edges.PB(MP(comp[i], ncomp + j - nspecial));
			//printf("\t%d: %d-%d = %d (col=%d,comp=%d)\n", curitem, i, j, w[i][j], col[i], comp[i]);
		}
		for (const auto& e : optregular) {
			int a = e.first, b = e.second;
			int curitem = nitem++;
			witem.PB(-w[a][b]);
			m2.edges.PB(MP(ncomp + a - nspecial, ncomp + b - nspecial));
			//printf("\t%d: %d-%d = %d\n", curitem, a, b, w[a][b]);
		}
		MatroidIntersection solver;
		solver.init(nitem, witem, m1, m2);
		int solvecost = -solver.solve();
		int totalcost = startcost + solvecost;
		ret = min(ret, totalcost);
	}

	return ret;
}

void run() {
	scanf("%d%d", &n, &nspecial);
	REP(i, nspecial) scanf("%d", &deglim[i]);
	REP(i, n) FOR(j, i + 1, n) scanf("%d", &w[i][j]), w[j][i] = w[i][j];
	REP(i, n) w[i][i] = 0;
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}