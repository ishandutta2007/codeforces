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

struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };
bool operator<(const P &a, const P &b) { if (a.x != b.x) return a.x < b.x; return a.y < b.y; };
P operator-(const P &a, const P &b) { return P(a.x - b.x, a.y - b.y); }
ll operator^(const P &a, const P &b) { return (ll)a.x * b.y - (ll)a.y * b.x; }

struct DecrementalUpperHull {
	struct HullNode {
		int id;
		HullNode *next, *prev;
	};
	struct SegNode {
		HullNode *head, *tail, *lbridge, *rbridge; int cnttotal;
	};

	int n;
	vector<P> p;
	vector<int> ord, pos;
	vector<HullNode> hullnode;
	vector<SegNode> segnode;

	void init(vector<P> _p) {
		p = _p; n = SZ(p); assert(n >= 1);
		ord = vector<int>(n); REP(i, n) ord[i] = i; sort(ord.begin(), ord.end(), [&](int i, int j) { return p[i] < p[j]; });
		pos = vector<int>(n); REP(i, n) pos[ord[i]] = i;
		hullnode = vector<HullNode>(n); REP(i, n) hullnode[i].id = ord[i];
		segnode = vector<SegNode>(2 * n - 1);
		build(0, 0, n - 1);
	}

	void build(int x, int l, int r) {
		if (l == r) {
			segnode[x].head = segnode[x].tail = &hullnode[l], segnode[x].lbridge = segnode[x].rbridge =  nullptr, segnode[x].cnttotal = 1;
		} else {
			int m = l + (r - l) / 2, y = x + 1, z = x + 2 * (m - l + 1);
			build(y, l, m);
			build(z, m + 1, r);
			segnode[x].cnttotal = segnode[y].cnttotal + segnode[z].cnttotal;
			createhull(x, y, z, segnode[y].head, segnode[z].head);
		}
	}

	pair<HullNode*, HullNode*> findbridge(HullNode *l, HullNode *r, function<HullNode*(HullNode*)> next,function<bool(const P&,const P&,const P&)> convex) {
		while (next(l) || next(r)) {
			if (!next(r) || next(l) && convex(P(0, 0), p[next(l)->id] - p[l->id], p[next(r)->id] - p[r->id])) {
				if (!convex(p[l->id], p[next(l)->id], p[r->id])) break; else l = next(l);
			} else {
				if (convex(p[l->id], p[r->id], p[next(r)->id])) break; else r = next(r);
			}
		}
		return MP(l, r);
	}

	void createhull(int x, int y, int z, HullNode *l, HullNode *r, int dir = +1) {
		if (dir > 0) {
			tie(l, r) = findbridge(l, r, [](HullNode *node) { return node->next; }, [](const P &a, const P &b, const P &c) { return ((b - a) ^ (c - a)) <= 0; });
		} else {
			tie(r, l) = findbridge(r, l, [](HullNode *node) { return node->prev; }, [](const P &a, const P &b, const P &c) { return ((b - a) ^ (c - a)) >= 0; });
		}
		segnode[x].lbridge = l, segnode[x].rbridge = r;
		segnode[x].head = segnode[y].head; segnode[y].head = l->next; (l->next ? l->next->prev : segnode[y].tail) = nullptr; l->next = r;
		segnode[x].tail = segnode[z].tail; segnode[z].tail = r->prev; (r->prev ? r->prev->next : segnode[z].head) = nullptr; r->prev = l;
	}

	void remove(int x, int l, int r, int IDX) {
		assert(l < r);
		--segnode[x].cnttotal;
		int m = l + (r - l) / 2, y = x + 1, z = x + 2 * (m - l + 1), nx = IDX <= m ? y : z;
		if (!segnode[x].lbridge) {
			swap(segnode[nx].head, segnode[x].head);
			swap(segnode[nx].tail, segnode[x].tail);
			if (IDX <= m) remove(nx, l, m, IDX); else remove(nx, m + 1, r, IDX);
			swap(segnode[nx].head, segnode[x].head);
			swap(segnode[nx].tail, segnode[x].tail);
		} else {
			HullNode *L = segnode[x].lbridge, *R = segnode[x].rbridge; assert(L->next == R && R->prev == L);
			L->next = segnode[y].head; (L->next ? L->next->prev : segnode[y].tail) = L; segnode[y].head = segnode[x].head;
			R->prev = segnode[z].tail; (R->prev ? R->prev->next : segnode[z].head) = R; segnode[z].tail = segnode[x].tail;
			if (segnode[nx].cnttotal == 1) {
				assert(segnode[nx].head == segnode[nx].tail && pos[segnode[nx].head->id] == IDX);
				segnode[nx].head = segnode[nx].tail = segnode[x].lbridge = segnode[x].rbridge = nullptr, segnode[nx].cnttotal = 0;
				segnode[x].head = segnode[y ^ z ^ nx].head; segnode[x].tail = segnode[y ^ z ^ nx].tail; segnode[y ^ z ^ nx].head = segnode[y ^ z ^ nx].tail = nullptr;
			} else if (IDX <= m) {
				if (pos[L->id] == IDX) L = L->next;
				remove(y, l, m, IDX);
				if (!L) L = segnode[y].tail;
				createhull(x, y, z, L, R, -1);
			} else {
				if (pos[R->id] == IDX) R = R->prev;
				remove(z, m + 1, r, IDX);
				if (!R) R = segnode[z].head;
				createhull(x, y, z, L, R, +1);
			}
		}
	}

	void remove(int idx) {
		if (segnode[0].head == segnode[0].tail) { segnode[0].head = segnode[0].tail = nullptr; return; }
		remove(0, 0, n - 1, pos[idx]);
	}

	vector<int> get() {
		vector<int> ret;
		for (HullNode *x = segnode[0].head; x != nullptr; x = x->next) ret.PB(x->id);
		return ret;
	}

	int rotateCCW(int x, int l, int r, P O) {
		//printf("rotateCCW(%d,%d,%d,(%d,%d)) <%d>\n", x, l, r, O.x, O.y, ord[l]);
		if (l == r) return ord[l];
		int m = l + (r - l) / 2, y = x + 1, z = x + 2 * (m - l + 1), nx;
		if (!segnode[x].lbridge) {
			nx = segnode[y].cnttotal >= 1 ? y : z;
		} else {
			HullNode *L = segnode[x].lbridge, *R = segnode[x].rbridge;
			nx = O.x < p[L->id].x || ((p[R->id] - p[L->id]) ^ (O - p[L->id])) > 0 ? y : z;
		}
		return nx == y ? rotateCCW(nx, l, m, O) : rotateCCW(nx, m + 1, r, O);
	}

	int rotateCCW(P o) {
		return empty() ? -1 : rotateCCW(0, 0, n - 1, o);
	}

	int swipeLeft(int x, int l, int r, P DIR) {
		if (l == r) return ord[l];
		int m = l + (r - l) / 2, y = x + 1, z = x + 2 * (m - l + 1), nx;
		if (!segnode[x].lbridge) {
			nx = segnode[y].cnttotal >= 1 ? y : z;
		} else {
			HullNode *L = segnode[x].lbridge, *R = segnode[x].rbridge;
			nx = ((p[L->id] - p[R->id]) ^ DIR) > 0 ? y : z;
		}
		return nx == y ? swipeLeft(nx, l, m, DIR) : swipeLeft(nx, m + 1, r, DIR);
	}

	int swipeLeft(P dir) {
		return empty() ? -1 : swipeLeft(0, 0, n - 1, dir);
	}

	bool empty() { return segnode[0].head == nullptr; }
};

struct DecrementalHull {
	DecrementalUpperHull upper, lower;
	void init(vector<P> p) {
		upper.init(p);
		REPSZ(i, p) p[i].x = -p[i].x, p[i].y = -p[i].y;
		lower.init(p);
	}
	void remove(int idx) {
		upper.remove(idx);
		lower.remove(idx);
	}
	vector<int> get() {
		vector<int> a = upper.get();
		vector<int> b = lower.get();
		if (SZ(a) == 0) { assert(SZ(b) == 0); return a; }
		if (SZ(a) == 1) { assert(SZ(b) == 1 && a[0] == b[0]); return a; }
		assert(a.back() == b[0] && b.back() == a[0]); a.insert(a.end(), b.begin() + 1, b.end() - 1); return a;
	}

	int rotateCCW(P o) {
		if (upper.empty()) return -1;
		P l = upper.p[upper.segnode[0].head->id], r = upper.p[upper.segnode[0].tail->id];
		return o.x > r.x || o.x >= l.x && ((r - l) ^ (o - l)) > 0 ? upper.rotateCCW(o) : lower.rotateCCW(P(-o.x, -o.y));
	}

	int swipeLeft(P dir) {
		return upper.empty() ? -1 : dir.x < 0 || dir.x == 0 && dir.y > 0 ? upper.swipeLeft(dir) : lower.swipeLeft(P(-dir.x, -dir.y));
	}
};

int n;
vector<P> p;
int nq;
vector<P> qdir; vector<int> qsteps;
vector<int> qans;


void solve() {
	DecrementalHull hull;
	hull.init(p);
	vector<int> qstart(nq);
	REP(i, nq) qstart[i] = hull.swipeLeft(qdir[i]);
	vector<vector<int>> layers;
	vector<int> nextlayer(n);
	vector<pair<int, int>> pos(n);
	while (true) {
		vector<int> cur = hull.get();
		if (SZ(cur) == 0) break;
		reverse(cur.begin(), cur.end());
		REPSZ(i, cur) pos[cur[i]] = MP(SZ(layers), i);
		layers.PB(cur);
		//printf("cur:"); for (int idx : cur) printf(" %c", 'A' + idx); puts("");
		for (int idx : cur) hull.remove(idx);
		REPSZ(i, cur) nextlayer[cur[i]] = hull.rotateCCW(p[cur[(i + SZ(cur) - 1) % SZ(cur)]]);
	}
	//REP(i, nq) printf("q%d: %c\n", i, 'A' + qstart[i]);
	//REP(i, n) { printf("(%d,%d) at [%d:%d]", p[i].x, p[i].y, pos[i].first, pos[i].second); if (nextlayer[i] != -1) printf(" -> [%d:%d]", pos[nextlayer[i]].first, pos[nextlayer[i]].second); puts(""); }
	REP(i, n) if (nextlayer[i] != -1) assert(pos[nextlayer[i]].first == pos[i].first + 1);

	vector<vector<pair<int, int>>> jump(n); // jump[at][k] = (to,cnt) jump 2^k layers starting from at ends up at to with cnt steps
	REP(i, n) if (nextlayer[i] != -1) jump[i].PB(MP(nextlayer[i], SZ(layers[pos[i].first])));
	for (int k = 1; (1 << k) < SZ(layers); ++k) REP(i, n) if (pos[i].first + (1 << k) < SZ(layers)) {
		//printf("k=%d i=%d\n", k, i);
		assert(k - 1 < SZ(jump[i]));
		assert(jump[i][k - 1].first >= 0 && jump[i][k - 1].first < n);
		assert(k - 1 < SZ(jump[jump[i][k - 1].first]));
		jump[i].PB(MP(jump[jump[i][k - 1].first][k - 1].first, jump[i][k - 1].second + jump[jump[i][k - 1].first][k - 1].second));
	}
	//REP(i, n) { printf("%c: (%d,%d) at [%d:%d] ->", 'A' + i, p[i].x, p[i].y, pos[i].first, pos[i].second); REPSZ(k, jump[i]) printf(" <%c in %d>", 'A' + jump[i][k].first, jump[i][k].second); puts(""); }

	int kmx = 0; while ((2 << kmx) < SZ(layers)) ++kmx;
	qans = vector<int>(nq);
	REP(i, nq) {
		int at = qstart[i], rem = qsteps[i];
		for (int k = kmx; k >= 0; --k) if (k < SZ(jump[at]) && rem >= jump[at][k].second) rem -= jump[at][k].second, at = jump[at][k].first;
		qans[i] = layers[pos[at].first][(pos[at].second + rem) % SZ(layers[pos[at].first])];
	}
}

void run() {
	scanf("%d", &n);
	p = vector<P>(n); REP(i, n) scanf("%d%d", &p[i].x, &p[i].y);
	scanf("%d", &nq);
	qdir = vector<P>(nq); qsteps = vector<int>(nq); REP(i, nq) scanf("%d%d%d", &qdir[i].x, &qdir[i].y, &qsteps[i]), --qsteps[i];
	solve();
	REPSZ(i, qans) printf("%d\n", qans[i] + 1);
}

void stress() {
	std::mt19937 rnd(213123);
	REP(rep, 10000) {
		//int sz = rnd() % 100 + 1; p.clear(); REP(x, sz) REP(y, sz) p.PB(P(x, y)); n = SZ(p); nq = 0;
		n = rnd() % 100 + 1; p = vector<P>(n); set<P> seen; REP(i, n) while (true) { p[i] = P(rnd() % 100, rnd() % 100); if (seen.count(p[i])) continue; seen.insert(p[i]); break; }
		//printf("%d\n", n); REP(i, n) printf("%d %d\n", p[i].x, p[i].y); printf("%d\n", nq); REP(i, nq) printf("%d %d %d\n", qdir[i].x, qdir[i].y, qsteps[i] + 1);
		solve();
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}