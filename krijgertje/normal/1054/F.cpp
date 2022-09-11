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

struct BipartiteGraph {
	int nl, nr;
	vector<vector<int>> ladj;
	void init(int _nl, int _nr) { nl = _nl, nr = _nr; ladj = vector<vector<int>>(nl); }
};

// Hopcroft-Karp: O(sqrt(n)*m)
struct MaximumBipartiteMatching {
	bool solved;
	BipartiteGraph* g;
	vector<bool> been;
	vector<int> dist;
	vector<int> lmatch, rmatch;

	void init(BipartiteGraph* _g) { g = _g; solved = false; }
	bool augment(int at) {
		if (been[at]) return false; else been[at] = true;
		REPSZ(i, g->ladj[at]) {
			int oth = g->ladj[at][i], to = rmatch[oth];
			if (to == -1 || dist[to] == dist[at] + 1 && augment(to)) { lmatch[at] = oth; rmatch[oth] = at; return true; }
		}
		return false;
	}
	int solve() {
		solved = true;
		lmatch = vector<int>(g->nl, -1);
		rmatch = vector<int>(g->nr, -1);
		dist = vector<int>(g->nl, INT_MAX);
		been = vector<bool>(g->nl, false);
		int ret = 0;
		while (true) {
			queue<int> q; int unmatcheddist = INT_MAX;
			REP(i, g->nl) if (lmatch[i] != -1) dist[i] = INT_MAX; else dist[i] = 0, q.push(i);
			while (!q.empty()) { 
				int at = q.front(); q.pop(); if (dist[at] > unmatcheddist) continue;
				REPSZ(i, g->ladj[at]) { int to = rmatch[g->ladj[at][i]]; if (to == -1) unmatcheddist = dist[at]; else if (dist[to] == INT_MAX) dist[to] = dist[at] + 1, q.push(to); }
			}
			if (unmatcheddist == INT_MAX) break;
			REP(i, g->nl) been[i] = false;
			REP(i, g->nl) if (lmatch[i] == -1 && augment(i)) ++ret;
		}
		return ret;
	}
	vector<pair<int, int>> getMatching() {
		if (!solved) solve();
		vector<pair<int, int>> ret; REP(i, g->nl) if (lmatch[i] != -1) ret.PB(MP(i, lmatch[i])); return ret;
	}
	pair<vector<int>, vector<int>> getMinVertexCover() {
		if (!solved) solve();
		vector<int> lcover; REP(i, g->nl) if (dist[i] == INT_MAX) lcover.PB(i);
		vector<int> rcover; REP(i, g->nr) if (rmatch[i] != -1 && dist[rmatch[i]] != INT_MAX) rcover.PB(i);
		return MP(lcover, rcover);
	}
	pair<vector<int>, vector<int>> getMaxIndependentSet() {
		if (!solved) solve();
		vector<int> lset; REP(i, g->nl) if (dist[i] != INT_MAX) lset.PB(i);
		vector<int> rset; REP(i, g->nr) if (rmatch[i] == -1 || dist[rmatch[i]] == INT_MAX) rset.PB(i);
		return MP(lset, rset);
	}
};

struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };
struct XSeg { int x, ly, hy; XSeg() {} XSeg(int x, int ly, int hy) :x(x), ly(ly), hy(hy) {} };
struct YSeg { int y, lx, hx; YSeg() {} YSeg(int y, int lx, int hx) :y(y), lx(lx), hx(hx) {} };

bool intersect(const XSeg &a, const YSeg &b) {
	return a.ly < b.y && b.y < a.hy && b.lx < a.x && a.x < b.hx;
}

struct Points2SegsConvertor {
	vector<int> fst, snd; // segidx->pointidx
	vector<int> prv, nxt; // pointidx->segidx

	vector<pair<int, pair<int, int>>> solve(vector<pair<pair<int, int>, int>> &lst) {
		prv = nxt = vector<int>(SZ(lst), -1); fst.clear(); snd.clear(); vector<pair<int, pair<int, int>>> ret;
		sort(lst.begin(), lst.end());
		REPSZ(i, lst) if (i + 1 < SZ(lst) && lst[i].first.first == lst[i + 1].first.first) {
			nxt[lst[i].second] = prv[lst[i + 1].second] = SZ(ret);
			fst.PB(lst[i].second); snd.PB(lst[i + 1].second);
			ret.PB(MP(lst[i].first.first, MP(lst[i].first.second, lst[i + 1].first.second)));
		}
		return ret;
	}
	vector<XSeg> makeXSegs(vector<P> p) {
		vector<pair<pair<int, int>, int>> byx; REPSZ(i, p) byx.PB(MP(MP(p[i].x, p[i].y), i));
		auto res = solve(byx);
		vector<XSeg> ret; REPSZ(i, res) ret.PB(XSeg(res[i].first, res[i].second.first, res[i].second.second)); return ret;
	}
	vector<YSeg> makeYSegs(vector<P> p) {
		vector<pair<pair<int, int>, int>> byy; REPSZ(i, p) byy.PB(MP(MP(p[i].y, p[i].x), i));
		auto res = solve(byy);
		vector<YSeg> ret; REPSZ(i, res) ret.PB(YSeg(res[i].first, res[i].second.first, res[i].second.second)); return ret;
	}
};


const int MAXN = 1000;

int n;
vector<P> p;

Points2SegsConvertor xconv, yconv;

vector<XSeg> xseg;
vector<YSeg> yseg;
BipartiteGraph bg;
MaximumBipartiteMatching solver;
vector<bool> xused;
vector<bool> yused;
vector<XSeg> xans;
vector<YSeg> yans;

void solve() {
	xseg = xconv.makeXSegs(p);
	yseg = yconv.makeYSegs(p);

	//REP(i, n) printf("%d: (%d,%d) x:[%d,%d->%d] y:[%d,%d->%d]\n", i, p[i].x, p[i].y, xconv.prv[i], xconv.nxt[i], xconv.snd[xconv.nxt[i]], yconv.prv[i], yconv.nxt[i], yconv.snd[yconv.nxt[i]]);
	
	bg.init(SZ(xseg), SZ(yseg));
	REPSZ(i, xseg) REPSZ(j, yseg) if (intersect(xseg[i], yseg[j])) bg.ladj[i].PB(j);
	//printf("nl=%d nr=%d\n", bg.nl, bg.nr);
	//REP(i, bg.nl) { printf("%d:", i); REPSZ(j, bg.ladj[i]) printf(" %d", bg.ladj[i][j]); puts(""); }

	solver.init(&bg);
	pair<vector<int>, vector<int>> res = solver.getMaxIndependentSet();
	xused = vector<bool>(SZ(xseg), false); REPSZ(i, res.first) xused[res.first[i]] = true;
	yused = vector<bool>(SZ(yseg), false); REPSZ(i, res.second) yused[res.second[i]] = true;
	//printf("xused:"); REPSZ(i, xseg) printf(" %d", xused[i] ? 1 : 0); puts("");
	//printf("yused:"); REPSZ(i, yseg) printf(" %d", yused[i] ? 1 : 0); puts("");
	xans.clear(); REP(i, n) if (xconv.prv[i] == -1 || !xused[xconv.prv[i]]) { int j = i; while (xconv.nxt[j] != -1 && xused[xconv.nxt[j]]) j = xconv.snd[xconv.nxt[j]]; xans.PB(XSeg(p[i].x, p[i].y, p[j].y)); }
	yans.clear(); REP(i, n) if (yconv.prv[i] == -1 || !yused[yconv.prv[i]]) { int j = i; while (yconv.nxt[j] != -1 && yused[yconv.nxt[j]]) j = yconv.snd[yconv.nxt[j]]; yans.PB(YSeg(p[i].y, p[i].x, p[j].x)); }
}

void run() {
	scanf("%d", &n);
	p.clear(); REP(i, n) { int x, y; scanf("%d%d", &x, &y); p.PB(P(x, y)); }
	solve();
	printf("%d\n", SZ(yans));
	REPSZ(i, yans) printf("%d %d %d %d\n", yans[i].lx, yans[i].y, yans[i].hx, yans[i].y);
	printf("%d\n", SZ(xans));
	REPSZ(i, xans) printf("%d %d %d %d\n", xans[i].x, xans[i].ly, xans[i].x, xans[i].hy);
}

int main() {
	run();
	return 0;
}