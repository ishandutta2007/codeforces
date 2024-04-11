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

template<typename Item, typename Sum, typename Lazy> struct SplayTree {
	struct Node { int par, ch[2]; Item item; Sum sum; Lazy lazy; Node(Item item, Sum sum, Lazy lazy) :par(-1), item(item), sum(sum), lazy(lazy) { ch[0] = ch[1] = -1; } };
	vector<Node> nodes;

	void reset() { nodes.clear(); }
	void apply(int x, Lazy lazy) { nodes[x].item += lazy; nodes[x].sum += lazy; nodes[x].lazy += lazy; }
	void push(int x) { REP(z, 2) if (nodes[x].ch[z] != -1) apply(nodes[x].ch[z], nodes[x].lazy); nodes[x].lazy = Lazy(); }
	void update(int x) { nodes[x].sum = Sum(); if (nodes[x].ch[0] != -1) nodes[x].sum += nodes[nodes[x].ch[0]].sum; nodes[x].sum += Sum(nodes[x].item); if (nodes[x].ch[1] != -1) nodes[x].sum += nodes[nodes[x].ch[1]].sum; }
	void connect(int x, int p, int z) { if (x != -1) nodes[x].par = p; if (p != -1) nodes[p].ch[z] = x; }
	int disconnect(int p, int z) { int x = nodes[p].ch[z]; nodes[p].ch[z] = -1; if (x != -1) nodes[x].par = -1; return x; }
	void rotate(int x) {
		int p = nodes[x].par, g = nodes[p].par, z = nodes[p].ch[0] == x ? 0 : 1, y = nodes[x].ch[1 - z]; push(p), push(x);
		connect(y, p, z), connect(p, x, 1 - z), connect(x, g, g == -1 ? -1 : nodes[g].ch[0] == p ? 0 : 1); update(p);
	}
	void splay(int x, int y = -1) { if (nodes[x].par == y) return; while (nodes[x].par != y) { int p = nodes[x].par, g = nodes[p].par; if (g != y) rotate((nodes[p].ch[0] == x) == (nodes[g].ch[0] == p) ? p : x); rotate(x); } update(x); }
	int first(int x) { if (x == -1) return x; splay(x); while (nodes[x].ch[0] != -1) x = nodes[x].ch[0]; splay(x); return x; }
	int last(int x) { if (x == -1) return x; splay(x); while (nodes[x].ch[1] != -1) x = nodes[x].ch[1]; splay(x); return x; }

	int add(Item item) { nodes.PB(Node(item, Sum(item), Lazy())); return SZ(nodes) - 1; };
	int join(int l, int r) { if (l == -1) return r;	l = last(l); push(l); connect(r, l, 1); update(l); return l; }
	void split(int x, int v, int& l, int& r) {
		if (x == -1) { l = r = -1; return; } else splay(x);
		l = r = -1;
		while (x != -1) { push(x); if (nodes[x].item.l() < v) l = x, x = nodes[x].ch[1]; else r = x, x = nodes[x].ch[0]; }
		if (l != -1) splay(l); if (r != -1) splay(r, l);
		if (l == -1) return;
		assert(nodes[l].par == -1 && nodes[l].ch[1] == r && (r == -1 || nodes[r].ch[0] == -1));
		push(l); disconnect(l, 1); update(l);
		if (nodes[l].item.r() < v) return;
		Item splitted = nodes[l].item.split(v);
		if (nodes[l].ch[0] != -1 && nodes[nodes[l].ch[0]].item.r() == nodes[l].item.r()) l = disconnect(l, 0);
		if (r == -1 || splitted.l() != nodes[r].item.l()) r = join(add(splitted), r);
		update(l);
	}
	void gather(int x, vector<Item>& ret) { push(x); if (nodes[x].ch[0] != -1) gather(nodes[x].ch[0], ret); ret.PB(nodes[x].item); if (nodes[x].ch[1] != -1) gather(nodes[x].ch[1], ret); }
	vector<Item> all(int x) { vector<Item> ret; if (x != -1) splay(x), gather(x, ret); return ret; }
};

const int MAXRECT = 200000;
const int INF = 1000000000;
struct Rect { int lt, rt, lx, rx; };

int nrect, sx;
Rect rect[MAXRECT];

struct Line {
	int ly, ry, lcost, slope;
	Line() {}
	Line(int ly, int ry, int lcost, int slope) :ly(ly), ry(ry), lcost(lcost), slope(ly == ry ? 0 : slope) {}
	int rcost() { return lcost + slope * (ry - ly); }
	int len() { return ry - ly; }
	void setly(int nly) { lcost += (nly - ly) * slope; ly = nly; if (ly == ry) slope = 0; }
	void setry(int nry) { ry = nry; if (ly == ry) slope = 0; }
	int l() { return ly; }
	int r() { return ry; }
	Line split(int y) {
		assert(ly < y && y <= ry);
		auto ret = Line(y, ry, lcost + (y - ly) * slope, slope);
		setry(y - 1);
		return ret;
	}
};
struct SumLine { SumLine() {} SumLine(Line line) {} };
SumLine& operator+=(SumLine& a, const SumLine& b) { return a; }
struct LazyLine {};
Line& operator+=(Line& a, const LazyLine& b) { return a; }
SumLine& operator+=(SumLine& a, const LazyLine& b) { return a; }
LazyLine& operator+=(LazyLine& a, const LazyLine& b) { return a; }

SplayTree<Line, SumLine, LazyLine> linetree;

void printfunc(int lineroot,int tline) {
	if (lineroot == -1) {
		printf(" BLOCKED");
	} else {
		auto alllines = linetree.all(lineroot);
		for (auto line : alllines) printf(" (%d,%d)..(%d,%d)", line.ly == -INF ? -INF : line.ly + tline, line.ly == -INF ? INF : line.lcost, line.ry == +INF ? +INF : line.ry + tline, line.ry == +INF ? INF : line.rcost());
	}
	puts("");
}

int t;

int rtrimfunc(int node, int nry) {
	while(true) {
		node = linetree.last(node);
		if (linetree.nodes[node].item.ry <= nry) break;
		if (linetree.nodes[node].item.ly < nry || linetree.nodes[node].item.ly == nry && linetree.nodes[node].ch[0] == -1) {
			linetree.nodes[node].item.setry(nry);
			break;
		}
		node = linetree.disconnect(node, 0);
		assert(node != -1);
	}
	return node;
}
int lgrowfunc(int node, int nly) {
	node = linetree.first(node);
	assert(nly <= linetree.nodes[node].item.ly);
	if (nly == linetree.nodes[node].item.ly) return node;
	if (linetree.nodes[node].item.slope == -1 || linetree.nodes[node].item.ly == linetree.nodes[node].item.ry) {
		linetree.nodes[node].item.slope = -1;
		linetree.nodes[node].item.setly(nly);
		linetree.update(node);
	} else {
		Line line(nly, linetree.nodes[node].item.ly, linetree.nodes[node].item.lcost + linetree.nodes[node].item.ly - nly, -1);
		node = linetree.join(linetree.add(line), node);
	}
	return node;
}
int rgrowfunc(int node, int nry) {
	node = linetree.last(node);
	assert(nry >= linetree.nodes[node].item.ry);
	if (nry == linetree.nodes[node].item.ry) return node;
	if (linetree.nodes[node].item.slope == +1 || linetree.nodes[node].item.ly == linetree.nodes[node].item.ry) {
		linetree.nodes[node].item.slope = +1;
		linetree.nodes[node].item.setry(nry);
		linetree.update(node);
	} else {
		Line line(linetree.nodes[node].item.ry, nry, linetree.nodes[node].item.rcost(), +1);
		node = linetree.join(node, linetree.add(line));
	}
	return node;
}
int shiftfunc(int node, int dt) {
	if (dt == 0) return node;
	node = linetree.first(node);
	int ply = linetree.nodes[node].item.ly;
	if (ply != -INF) node = lgrowfunc(node, ply - dt);
	node = linetree.last(node);
	int pry = linetree.nodes[node].item.ry;
	if (pry != +INF) node = rtrimfunc(node, pry - dt);
	return node;
}
int mergefunc(int l, int r) {
	//printf("merging\n");
	//printfunc(l, t);
	//printfunc(r, t);
	l = linetree.last(l);
	r = linetree.first(r);
	while (l != -1 && r != -1 && linetree.nodes[l].item.rcost() > linetree.nodes[r].item.lcost) {
		assert(linetree.nodes[l].item.ry == linetree.nodes[r].item.ly);
		if (linetree.nodes[l].item.slope == -1 || linetree.nodes[l].item.ly == linetree.nodes[l].item.ry) {
			r = lgrowfunc(r, linetree.nodes[l].item.ly);
			l = linetree.disconnect(l, 0);
		} else {
			assert(linetree.nodes[l].item.slope == 1);
			if (linetree.nodes[r].item.lcost + linetree.nodes[l].item.len() <= linetree.nodes[l].item.lcost) {
				r = lgrowfunc(r, linetree.nodes[l].item.ly);
				l = linetree.disconnect(l, 0);
			} else {
				int y = linetree.nodes[r].item.lcost - linetree.nodes[l].item.lcost + linetree.nodes[l].item.ly + linetree.nodes[l].item.ry; assert(y % 2 == 0); y /= 2;
				assert(y > linetree.nodes[l].item.ly && y < linetree.nodes[l].item.ry);
				r = lgrowfunc(r, y);
				linetree.nodes[l].item.setry(y);
			}
		}
		l = linetree.last(l);
		r = linetree.first(r);
	}
	while (l != -1 && r != -1 && linetree.nodes[l].item.rcost() < linetree.nodes[r].item.lcost) {
		assert(linetree.nodes[l].item.ry == linetree.nodes[r].item.ly);
		if (linetree.nodes[r].item.slope == +1 || linetree.nodes[r].item.ly == linetree.nodes[r].item.ry) {
			l = rgrowfunc(l, linetree.nodes[r].item.ry);
			r = linetree.disconnect(r, 1);
		} else {
			assert(linetree.nodes[r].item.slope == -1);
			if (linetree.nodes[l].item.rcost() + linetree.nodes[r].item.len() <= linetree.nodes[r].item.rcost()) {
				l = rgrowfunc(l, linetree.nodes[r].item.ry);
				r = linetree.disconnect(r, 1);
			} else {
				int y = linetree.nodes[r].item.rcost() - linetree.nodes[l].item.rcost() + linetree.nodes[r].item.ly + linetree.nodes[r].item.ry; assert(y % 2 == 0); y /= 2;
				assert(y > linetree.nodes[r].item.ly && y < linetree.nodes[r].item.ry);
				l = rgrowfunc(l, y);
				linetree.nodes[r].item.setly(y);
			}
		}
		l = linetree.last(l);
		r = linetree.first(r);
	}
	int ret = linetree.join(l, r);
	//printf("-> "); printfunc(ret, t);
	return ret;
}

struct Region {
	int lx, rx, blockcnt, lineroot, tline;
	Region(int lx, int rx, int blockcnt, int lineroot, int tline) :lx(lx), rx(rx), blockcnt(blockcnt), lineroot(lineroot), tline(tline) {};
	int l() { return lx; }
	int r() { return rx; }
	void norm() { if (lineroot != -1) { lineroot = shiftfunc(lineroot, t - tline); tline = t; } }
	Region split(int x) {
		assert(lx < x && x <= rx); 
		norm();
		auto ret = Region(x, rx, blockcnt, -1, tline);
		rx = x - 1;
		if (lineroot != -1) linetree.split(lineroot, x - t, lineroot, ret.lineroot);
		return ret;
	};
};
struct SumRegion {
	int mnblockcnt;
	SumRegion() { mnblockcnt = INT_MAX; }
	SumRegion(Region region) { mnblockcnt = region.lineroot == -1 ? INT_MAX : region.blockcnt; }
};
SumRegion& operator+=(SumRegion& a, const SumRegion& b) { a.mnblockcnt = min(a.mnblockcnt, b.mnblockcnt); return a; }
struct LazyRegion {
	int lazyblockcnt;
	LazyRegion() { lazyblockcnt = 0; }
	LazyRegion(int lazyblockcnt) :lazyblockcnt(lazyblockcnt) {}
};
Region& operator+=(Region& a, const LazyRegion& b) { a.blockcnt += b.lazyblockcnt; return a; }
SumRegion& operator+=(SumRegion& a, const LazyRegion& b) { if (a.mnblockcnt != INT_MAX) a.mnblockcnt += b.lazyblockcnt; return a; }
LazyRegion& operator+=(LazyRegion& a, const LazyRegion& b) { a.lazyblockcnt += b.lazyblockcnt; return a; }


SplayTree<Region, SumRegion, LazyRegion> regiontree;

void print(int regionroot) {
	auto allregions = regiontree.all(regionroot);
	for (auto region : allregions) {
		//region.norm();
		printf("[%d..%d] = %d:", region.lx, region.rx, region.blockcnt); if (region.lineroot!=-1 && region.tline != t) printf(" (delay %d)", t - region.tline);
		printfunc(region.lineroot, region.tline);
	}
}

int killzeroes(int node) {
	regiontree.splay(node);
	while (regiontree.nodes[node].sum.mnblockcnt == 0) {
		//printf("killing\n"); print(node);
		while (regiontree.nodes[node].item.blockcnt != 0 || regiontree.nodes[node].item.lineroot == -1) {
			//printf("node=%d\n", node);
			if (regiontree.nodes[node].ch[0] != -1 && regiontree.nodes[regiontree.nodes[node].ch[0]].sum.mnblockcnt == 0) {
				node = regiontree.nodes[node].ch[0];
			} else {
				node = regiontree.nodes[node].ch[1];
			}
			assert(node != -1 && regiontree.nodes[node].sum.mnblockcnt == 0);
		}
		//printf("found node=%d\n", node);
		assert(regiontree.nodes[node].item.lineroot != -1);
		regiontree.splay(node);
		regiontree.nodes[node].item.lineroot = -1;
		regiontree.update(node);
	}
	return node;
}

int rgrow(int node, int x) {
	int l, r; regiontree.split(node, x + 1, l, r);
	l = regiontree.last(l);
	r = regiontree.first(r);
	//printf("growing\n");
	//printf("l\n"); print(l);
	//printf("r\n"); print(r);
	if (l == -1 || regiontree.nodes[l].item.lineroot == -1) return regiontree.join(l, r);
	while (r != -1 && regiontree.nodes[r].item.lineroot == -1 && regiontree.nodes[r].item.blockcnt == 0) {
		//printf("step\n");
		assert(regiontree.nodes[l].item.rx + 1 == regiontree.nodes[r].item.lx);
		regiontree.nodes[l].item.rx = regiontree.nodes[r].item.rx;
		r = regiontree.disconnect(r, 1);
		r = regiontree.first(r);
	}
	if (r != -1 && regiontree.nodes[r].item.lineroot != -1) {
		assert(regiontree.nodes[l].item.rx + 1 == regiontree.nodes[r].item.lx);
		regiontree.nodes[l].item.rx = regiontree.nodes[r].item.lx;
		regiontree.nodes[l].item.norm();
		regiontree.nodes[l].item.lineroot = rgrowfunc(regiontree.nodes[l].item.lineroot, regiontree.nodes[l].item.rx - t);
		regiontree.nodes[r].item.norm();
		regiontree.nodes[l].item.lineroot = mergefunc(regiontree.nodes[l].item.lineroot, regiontree.nodes[r].item.lineroot);
		regiontree.nodes[l].item.rx = regiontree.nodes[r].item.rx;
		r = regiontree.disconnect(r, 1);
	} else {
		regiontree.nodes[l].item.norm();
		regiontree.nodes[l].item.lineroot = rgrowfunc(regiontree.nodes[l].item.lineroot, regiontree.nodes[l].item.rx - t);
	}
	int ret = regiontree.join(l, r);
	//printf("after rgrow\n"); print(ret);
	return ret;
}

int lgrow(int node, int x) {
	//printf("lgrow %d\n", x);
	int l, r; regiontree.split(node, x, l, r);
	l = regiontree.last(l);
	r = regiontree.first(r);
	if (r == -1 || regiontree.nodes[r].item.lineroot == -1) return regiontree.join(l, r);
	while (l != -1 && regiontree.nodes[l].item.lineroot == -1 && regiontree.nodes[l].item.blockcnt == 0) {
		assert(regiontree.nodes[l].item.rx + 1 == regiontree.nodes[r].item.lx);
		regiontree.nodes[r].item.lx = regiontree.nodes[l].item.lx;
		l = regiontree.disconnect(l, 0);
		l = regiontree.last(l);
	}
	if (l != -1 && regiontree.nodes[l].item.lineroot != -1) {
		assert(regiontree.nodes[l].item.rx + 1 == regiontree.nodes[r].item.lx);
		regiontree.nodes[l].item.rx = regiontree.nodes[r].item.lx;
		regiontree.nodes[l].item.norm();
		regiontree.nodes[l].item.lineroot = rgrowfunc(regiontree.nodes[l].item.lineroot, regiontree.nodes[l].item.rx - t);
		regiontree.nodes[r].item.norm();
		regiontree.nodes[l].item.lineroot = mergefunc(regiontree.nodes[l].item.lineroot, regiontree.nodes[r].item.lineroot);
		regiontree.nodes[l].item.rx = regiontree.nodes[r].item.rx;
		r = regiontree.disconnect(r, 1);
	} else {
		regiontree.nodes[r].item.norm();
		regiontree.nodes[r].item.lineroot = lgrowfunc(regiontree.nodes[r].item.lineroot, regiontree.nodes[r].item.lx - t);
	}
	return regiontree.join(l, r);
}

int solve() {
	//REP(i, nrect) printf("t=%d..%d y=%d..%d to %d..%d\n", rect[i].lt, rect[i].rt, rect[i].lx - rect[i].lt, rect[i].rx - rect[i].lt, rect[i].lx - rect[i].rt, rect[i].rx - rect[i].rt);

	linetree.reset();
	regiontree.reset();
	int linedn = linetree.add(Line(-INF, sx, abs(-INF - sx), -1));
	int lineup = linetree.add(Line(sx, +INF, 0, +1));
	int lineroot = linetree.join(linedn, lineup);
	int regionroot = regiontree.add(Region(-INF, +INF, 0, lineroot, 0));

	vector<pair<int, int>> e;
	REP(i, nrect) e.PB(MP(2 * rect[i].lt + 1, i)), e.PB(MP(2 * rect[i].rt + 0, i));
	sort(e.begin(), e.end());
	//printf("INITIAL\n"); print(regionroot);
	REPSZ(i, e) {
		t = e[i].first >> 1; int kind = e[i].first & 1, idx = e[i].second;
		if (kind == 0) { // release rect
			int l, m, r;
			regiontree.split(regionroot, rect[idx].lx + 1, l, m);
			regiontree.split(m, rect[idx].rx, m, r);
			regiontree.apply(m, LazyRegion(-1));
			regionroot = regiontree.join(regiontree.join(l, m), r);
			regionroot = rgrow(regionroot, rect[idx].lx);
			regionroot = lgrow(regionroot, rect[idx].rx);
		}
		if (kind == 1) { // block rect
			int l, m, r;
			regiontree.split(regionroot, rect[idx].lx + 1, l, m);
			//printf("L\n"); print(l);
			//printf("M\n"); print(m);
			regiontree.split(m, rect[idx].rx, m, r);
			//printf("M\n"); print(m);
			//printf("R\n"); print(r);
			m = killzeroes(m);
			//printf("M\n"); print(m);
			regiontree.apply(m, LazyRegion(1));
			regionroot = regiontree.join(regiontree.join(l, m), r);
		}
		//printf("after %s rect %d (t=%d)\n", kind == 0 ? "releasing" : "blocking", idx + 1, t); print(regionroot);
		//if (i == 0) exit(0);
	}
	//printf("FINAL (t=%d)\n",t); print(regionroot);

	auto finalregions = regiontree.all(regionroot);
	assert(SZ(finalregions) == 1);
	auto finalregion = finalregions[0];
	finalregion.norm();
	assert(finalregion.lineroot != -1);
	auto finalfunc = linetree.all(finalregion.lineroot);
	int ret = INT_MAX;
	for (auto func : finalfunc) ret = min(ret, min(func.lcost, func.rcost()));
	return ret;
}

void run() {
	scanf("%d", &nrect);
	scanf("%d", &sx);
	REP(i, nrect) scanf("%d%d%d%d", &rect[i].lt, &rect[i].rt, &rect[i].lx, &rect[i].rx), --rect[i].lt, ++rect[i].rt, --rect[i].lx, ++rect[i].rx;
	printf("%d\n", solve());
}

void stress() {
	int mxrect = 100, mxdim = 100;
	REP(rep, 10000) {
		nrect = rnd() % mxrect + 1;
		int tdim = rnd() % mxdim + 1;
		int xdim = rnd() % mxdim + 1;
		sx = rnd() % (xdim + 1);
		REP(i, nrect) {
			rect[i].lt = rnd() % tdim; rect[i].rt = rnd() % tdim; if (rect[i].lt > rect[i].rt) swap(rect[i].lt, rect[i].rt); rect[i].rt += 2;
			rect[i].lx = rnd() % xdim; rect[i].rx = rnd() % xdim; if (rect[i].lx > rect[i].rx) swap(rect[i].lx, rect[i].rx); rect[i].rx += 2;
		}
		//printf("%d\n%d\n", nrect, sx); REP(i, nrect) printf("%d %d %d %d\n", rect[i].lt + 1, rect[i].rt - 1, rect[i].lx + 1, rect[i].rx - 1);
		solve();
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}