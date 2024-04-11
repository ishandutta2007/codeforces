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

struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };

P operator+(const P& a, const P& b) { return P(a.x + b.x, a.y + b.y); }
P operator-(const P& a, const P& b) { return P(a.x - b.x, a.y - b.y); }
P flip(const P& a) { return P(a.y, a.x); }

P lca(const P &a, const P &b) {
	//printf("\tlca(%d,%d) (%d,%d)\n", a.x, a.y, b.x, b.y);
	if (a.y > a.x) return flip(lca(flip(a), flip(b)));
	if (b.y > b.x) return P(0, 0);
	if (a.x == 0 || b.x == 0) return P(0, 0);
	int abit = 0; while ((2LL << abit) <= a.x) ++abit;
	int bbit = 0; while ((2LL << bbit) <= b.x) ++bbit;
	if (abit != bbit) return abit < bbit ? lca(a, P((2 << abit) - 1, 0)) : lca(P((2 << bbit) - 1, 0), b);
	P shift(1 << abit, 0);
	return lca(a - shift, b - shift) + shift;
}
bool operator<(const P& a, const P& b) {
	//printf("comparing(%d,%d)\n", a.x, a.y, b.x, b.y);
	if (a.x == b.x && a.y == b.y) return false;
	if (a.x == 0 && a.y == 0) return true;
	if (b.x == 0 && b.y == 0) return false;
	if ((a.y > a.x) != (b.y > b.x)) return a.y < a.x;
	if (a.y > a.x) return flip(a) < flip(b);
	int abit = 0; while ((2LL << abit) <= a.x) ++abit;
	int bbit = 0; while ((2LL << bbit) <= b.x) ++bbit;
	if (abit > bbit) return b.y > 0;
	if (bbit > abit) return a.y == 0;
	P shift(1 << abit, 0);
	return a - shift < b - shift;
}
int dep(const P& a) { return a.x + a.y; }

const int MAXPATH = 100000;

int npath;
P path[MAXPATH][2];

vector<P> special;

map<pair<int, int>, int> mp;
vector<P> lst;
vector<int> par;
vector<vector<int>> ch;
vector<int> marknode;
vector<int> markparentpath;

int makenode(const P& p) { int ret = SZ(lst); mp[MP(p.x, p.y)] = ret; lst.PB(p); par.PB(-1); return ret; }

void dfsmark(int at) {
	REPSZ(i, ch[at]) {
		int to = ch[at][i];
		dfsmark(to);
		markparentpath[at] += markparentpath[to];
	}
	marknode[at] += markparentpath[at];
}

set<int> flips;
void toggleflip(int x) {
	if (flips.count(x)) flips.erase(x); else flips.insert(x);
}
void togglesegment(int l, int r) {
	//printf("togglesegment(%d..%d)\n", l, r);
	toggleflip(l);
	toggleflip(r + 1);
}

int solve() {
	special.clear();
	REP(i, npath) REP(j, 2) special.PB(path[i][j]);
	sort(special.begin(), special.end());

	mp.clear();
	lst.clear();
	par.clear();

	int root = makenode(P(0, 0));
	vector<int> stck;
	stck.PB(root);
	REPSZ(i, special) {
		P at = special[i];
		//printf("processing(%d,%d)\n", at.x, at.y);
		P x = lca(at, lst[stck.back()]);
		while (SZ(stck) >= 2) {
			int a = stck[SZ(stck) - 1];
			int b = stck[SZ(stck) - 2];
			if (dep(x) > dep(lst[b])) break;
			par[a] = b; stck.pop_back();
		}
		{
			int a = stck[SZ(stck) - 1];
			if (dep(x) < dep(lst[a])) {
				int xid = makenode(x);
				par[a] = xid;
				stck.pop_back();
				stck.PB(xid);
			}
		}
		if (dep(at) > dep(x)) {
			int atid = makenode(at);
			stck.PB(atid);
		}
	}
	while (SZ(stck) >= 2) {
		int a = stck[SZ(stck) - 1];
		int b = stck[SZ(stck) - 2];
		par[a] = b;
		stck.pop_back();
	}
	ch = vector<vector<int>>(SZ(lst));
	REPSZ(i, par) if (par[i] != -1) ch[par[i]].PB(i);
	
	marknode = vector<int>(SZ(lst), 0);
	markparentpath = vector<int>(SZ(lst), 0);
	REP(i, npath) {
		pair<int, int> akey = MP(path[i][0].x, path[i][0].y);
		assert(mp.count(akey));
		pair<int, int> bkey = MP(path[i][1].x, path[i][1].y);
		assert(mp.count(bkey));
		P c = lca(path[i][0], path[i][1]);
		pair<int, int> ckey = MP(c.x, c.y);
		assert(mp.count(bkey));
		int aid = mp[akey], bid = mp[bkey], cid = mp[ckey];
		++marknode[aid], ++marknode[bid], ++marknode[cid];
		++markparentpath[aid], ++markparentpath[bid], markparentpath[cid] -= 2;
	}
	dfsmark(root);
	//REPSZ(i, lst) printf("%d: (%d,%d) par=%d dep=%d mark=%d markparentpath=%d\n", i, lst[i].x, lst[i].y, par[i], dep(lst[i]), marknode[i], markparentpath[i]);

	flips.clear();
	REPSZ(i, lst) {
		if (marknode[i]) { int x = dep(lst[i]); togglesegment(x, x); }
		if (markparentpath[i]) { assert(par[i] != -1); int x = dep(lst[i]), y = dep(lst[par[i]]); if (y + 1 <= x - 1) togglesegment(y + 1, x - 1); }
	}

	vector<pair<int, int>> segments;
	int start = 0, bal = 0;
	for (const int& x : flips) {
		if (bal == 0) {
			start = x;
			bal = 1;
		} else {
			segments.PB(MP(start, x - 1));
			bal = 0;
		}
	}
	//printf("segments:"); REPSZ(i, segments) printf(" %d..%d", segments[i].first, segments[i].second); puts("");
	if (SZ(segments) == 0) return 0;
	return 2 * SZ(segments) - (segments[0].first == 0 ? 1 : 0);
}

void run() {
	scanf("%d", &npath);
	REP(i, npath) REP(j, 2) scanf("%d%d", &path[i][j].x, &path[i][j].y);
	printf("%d\n", solve());

}

void stresslca() {
	int dim = 300;
	vector<vector<int>> id(dim, vector<int>(dim, -1));
	vector<P> lst;
	int nid = 0;
	REP(x, dim) REP(y, dim) if ((x & y) == 0) id[x][y] = nid++, lst.PB(P(x, y));
	vector<int> par(nid, -2), dep(nid, -1);
	queue<pair<int, int>> q;
	par[0] = -1, dep[0] = 0, q.push(MP(0, 0));
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second, at = id[x][y]; q.pop();
		FORE(dx, -1, +1) FORE(dy, -1, +1) if (dx * dx + dy * dy == 1) {
			int nx = x + dx, ny = y + dy;
			if (nx < 0 || nx >= dim || ny < 0 || ny >= dim) continue;
			if (id[nx][ny] == -1) continue;
			int to = id[nx][ny];
			if (par[to] == -2) par[to] = at, dep[to] = dep[at] + 1, q.push(MP(nx, ny));
		}
	}
	REP(i, nid) assert(par[i] != -2);
	REPSZ(i, lst) REPSZ(j, lst) {
		P have = lca(lst[i], lst[j]);
		int a = i, b = j;
		while (a != b) {
			if (dep[a] < dep[b]) swap(a, b);
			a = par[a];
		}
		P want = lst[a];
		//printf("(%d,%d) (%d,%d) -> have=(%d,%d) want=(%d,%d)\n", lst[i].x, lst[i].y, lst[j].x, lst[j].y, have.x, have.y, want.x, want.y);
		assert(have.x == want.x && have.y == want.y);
	}
}
void stressord() {
	int dim = 300;
	vector<vector<int>> id(dim, vector<int>(dim, -1));
	vector<P> lst;
	int nid = 0;
	REP(x, dim) REP(y, dim) if ((x & y) == 0) id[x][y] = nid++, lst.PB(P(x, y));
	vector<int> par(nid, -2), ord(nid, -1);
	int nord = 0;
	auto dfs = [&](auto self,int at) {
		if (false) return;
		ord[at] = nord++;
		int x = lst[at].x, y = lst[at].y;
		REP(rep, 2) {
			FORE(dy, -1, +1) FORE(dx, -1, +1) if (dx * dx + dy * dy == 1) {
				int nx = x + dx, ny = y + dy;
				if (nx < 0 || nx >= dim || ny < 0 || ny >= dim) continue;
				if (id[nx][ny] == -1) continue;
				if (rep == 0 && (par[at] == -1 || nx - x != x - lst[par[at]].x || ny - y != y - lst[par[at]].y)) continue;
				int to = id[nx][ny];
				if (par[to] == -2) par[to] = at, self(self, to);
			}
		}
	};
	par[0] = -1; dfs(dfs, 0);
	assert(nord == nid);
	int nerr = 0;
	REPSZ(i, lst) REPSZ(j, lst) {
		bool have = lst[i] < lst[j];
		bool want = ord[i] < ord[j];
		if (have == want) continue;
		printf("err have=%s want=%s %d vs %d = (%d,%d) vs (%d,%d)\n", have ? "true" : "false", want ? "true" : "false", ord[i], ord[j], lst[i].x, lst[i].y, lst[j].x, lst[j].y);
		++nerr;
	}
	printf("nerr=%d\n", nerr);
	//puts("");  REP(i, dim) { printf("ord%2d:", i); REP(j, dim) if (id[i][j] == -1) printf(" XXX"); else printf(" %3d", ord[id[i][j]]); puts(""); }
}

void stress() {
	int dim = 1000;
	vector<vector<int>> id(dim, vector<int>(dim, -1));
	vector<P> lst;
	int nid = 0;
	REP(x, dim) REP(y, dim) if ((x & y) == 0) id[x][y] = nid++, lst.PB(P(x, y));
	vector<int> par(nid, -2), ord(nid, -1), dep(nid, -1);
	int nord = 0;
	auto dfs = [&](auto self, int at) {
		if (false) return;
		dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
		ord[at] = nord++;
		int x = lst[at].x, y = lst[at].y;
		REP(rep, 2) {
			FORE(dy, -1, +1) FORE(dx, -1, +1) if (dx * dx + dy * dy == 1) {
				int nx = x + dx, ny = y + dy;
				if (nx < 0 || nx >= dim || ny < 0 || ny >= dim) continue;
				if (id[nx][ny] == -1) continue;
				if (rep == 0 && (par[at] == -1 || nx - x != x - lst[par[at]].x || ny - y != y - lst[par[at]].y)) continue;
				int to = id[nx][ny];
				if (par[to] == -2) par[to] = at, self(self, to);
			}
		}
	};
	par[0] = -1; dfs(dfs, 0);
	assert(nord == nid);

	std::mt19937 rnd(2131);
	REP(rep, 1000000) {
		npath = rnd() % 50 + 1;
		REP(i, npath) REP(j, 2) path[i][j] = lst[rnd() % nid];
		int have = solve();
		vector<int> cnt(0);
		vector<bool> been(nid, false);
		REP(i, npath) {
			int a = id[path[i][0].x][path[i][0].y];
			int b = id[path[i][1].x][path[i][1].y];
			while (true) {
				if (dep[a] < dep[b]) swap(a, b);
				while (dep[a] >= SZ(cnt)) cnt.PB(0);
				if (!been[a]) been[a] = true, ++cnt[dep[a]];
				if (a == b) break;
				a = par[a];
			}
		}
		REPSZ(i, cnt) cnt[i] %= 2;
		int want = 0;
		if (cnt[0] == 1) ++want;
		FORSZ(i, 1, cnt) if (cnt[i - 1] == 0 && cnt[i] == 1) want += 2;
		if (have == want) { if (rep % 1000 == 999) printf("."); continue; }
		printf("err have=%d want=%d\n", have, want);
		printf("%d\n", npath); REP(i, npath) printf("%d %d %d %d\n", path[i][0].x, path[i][0].y, path[i][1].x, path[i][1].y);
	}

}

int main() {
	run();
	//stresslca();
	//stressord();
	//stress();
	return 0;
}