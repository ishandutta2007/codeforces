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

struct Seg {
	vector<int> val;
	vector<int> lazy;
	void init(int n) {
		//printf("init(%d)\n", n);
		val = lazy = vector<int>(4 * n, 0);
	}
	void mod(int x, int l, int r, int L, int R, int BY) {
		//printf("mod %d=%d..%d on %d..%d with %d\n", x, l, r, L, R, BY);
		if (L <= l && r <= R) {
			val[x] += BY, lazy[x] += BY;
		} else {
			int m = l + (r - l) / 2;
			if (L <= m) mod(2 * x + 1, l, m, L, R, BY);
			if (m + 1 <= R) mod(2 * x + 2, m + 1, r, L, R, BY);
			val[x] = lazy[x] + max(val[2 * x + 1], val[2 * x + 2]);
		}
	}
};

const int MAXN = 50000;
const int MAXABSDIM = 100000000;
struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };

int n, window, need;
P p[MAXN];

double calcupperbound() {
	// suppose we divide the area into k parts with 'window > k * (need-1)'. Then at least one of the parts has at least 'need' points
	int kmx = (window - 1) / (need - 1);
	// divide area into s*s grid witch s*s<=kmx (so there is at least one cell with at least 'need' points)
	int s = (int)sqrt(1.0 * kmx);
	assert(s >= 1 && s * s <= kmx);
	double side = 2.0 * MAXABSDIM / s;
	// put a circle in center of grid cell
	return side / sqrt(2);
}

double gridside;
map<pair<int, int>, vector<int>> grid;

pair<int, int> getcell(const P &p) {
	int x = floor((p.x + MAXABSDIM) / gridside);
	int y = floor((p.y + MAXABSDIM) / gridside);
	return MP(x, y);
}

void buildgrid(double side) {
	grid.clear(), gridside = max(side, 1.0);
	REP(i, n) grid[getcell(p[i])].PB(i);
}

// Tests whether there is a point on the circle centered at 'center' with radius 'r' for which there are at least 'need' points within distance 'r'.
// Assumes the grid is build for '2*r' (or bigger)
bool can(int center, double r) {
	pair<int, int> cell = getcell(p[center]);
	vector<pair<int,pair<double,double>>> opt;
	double period = 2 * acos(-1);
	FORE(dx, -1, +1) FORE(dy, -1, +1) {
		auto it = grid.find(MP(cell.first + dx, cell.second + dy));
		if (it == grid.end()) continue;
		const vector<int> &lst = it->second;
		for (auto lit = lower_bound(lst.begin(), lst.end(), center - window + 1); lit != lst.end() && *lit <= center + window - 1; ++lit) {
			if (*lit == center) continue;
			const P &a = p[center];
			const P &b = p[*lit];
			double d = sqrt(1.0 * (a.x - b.x) * (a.x - b.x) + 1.0 * (a.y - b.y) * (a.y - b.y));
			if (d > 2 * r) continue;
			double alpha = atan2(b.y - a.y, b.x - a.x);
			double beta = acos(0.5 * d / r);
			if (alpha < 0) alpha += period;
			double u = alpha - beta, v = alpha + beta;
			opt.PB(MP(*lit, MP(u, v)));
		}
	}
	sort(opt.begin(), opt.end());
	if (SZ(opt) == 0) return false;
	vector<pair<int, int>> init;
	vector<pair<double, pair<pair<int, int>, int>>> e;
	int j = 0;
	REPSZ(i, opt) {
		double u = opt[i].second.first, v = opt[i].second.second;
		while (opt[j].first <= opt[i].first - window) ++j;
		if (u < 0) init.PB(MP(j, i)), e.PB(MP(u + period, MP(MP(j, i), +1))); else e.PB(MP(u, MP(MP(j, i), +1)));
		if (v < period) e.PB(MP(v, MP(MP(j, i), -1))); else init.PB(MP(j, i)), e.PB(MP(v - period, MP(MP(j, i), -1)));
	}
	sort(e.begin(), e.end());
	Seg seg;
	seg.init(SZ(opt));
	for (const auto z : init) seg.mod(0, 0, SZ(opt) - 1, z.first, z.second, +1);
	FORSZ(i, -1, e) {
		if (i != -1) seg.mod(0, 0, SZ(opt) - 1, e[i].second.first.first, e[i].second.first.second, e[i].second.second);
		if (seg.val[0] >= need - 1) {
			//printf("found point on circle with center (%d,%d) and radius %lf\n", p[center].x, p[center].y, r);
			//REPSZ(j, opt) printf("\t%d: %lf..%lf\n", opt[j].first, opt[j].second.first, opt[j].second.second);
			return true;
		}
	}
	return false;
}

double solve() {
	double r = calcupperbound();
	buildgrid(2 * r);
	REP(i, n) {
		if (can(i, r)) {
			double lo = 0, hi = r;
			REP(rep, 100) {
				double mi = lo + (hi - lo) / 2;
				if (can(i, mi)) hi = mi; else lo = mi;
			}
			r = hi;
			buildgrid(2 * r);
		}
	}
	return r;
}

void run() {
	scanf("%d%d%d", &n, &window, &need);
	REP(i, n) scanf("%d%d", &p[i].x, &p[i].y);
	printf("%.15lf\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}