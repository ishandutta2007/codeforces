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

const int MAXSEG = 2000;
struct Seg { int lx, rx, y; };
struct Frac { ll num, den; Frac(ll _num, ll _den) :num(_num), den(_den) { assert(den != 0); if (den < 0) num = -num, den = -den; if (den != 1) { ll g = gcd(abs(num), den); num /= g, den /= g; } } };
bool operator<(const Frac& a, const Frac& b) { return a.num * b.den < b.num * a.den; }

int nseg;
Seg seg[MAXSEG];

vector<pair<double, Seg>> mx;
vector<pair<double, Seg>> mn;
vector<pair<Frac, int>> e;

double calc(double lo, double hi, Seg l, Seg r) {
	// (r.rx+r.y*a)-(l.lx+l.y*a) -> p+q*a
	int p = r.rx - l.lx, q = r.y - l.y;
	double ret;
	if (q < 0) ret = p + hi * q; else if (q > 0) ret = p + lo * q; else ret = p;
	//printf("-> %lf (%d+%d*a)\n", ret, p, q);
	return ret;
}

double solve() {
	sort(seg, seg + nseg, [](const Seg& a, const Seg& b) { if (a.y != b.y) return a.y < b.y; return a.lx < b.lx; });
	mx.clear();
	REP(i, nseg) {
		Seg cur = seg[i];
		while (true) {
			if (SZ(mx) == 0) { mx.PB(MP(-1e200, cur)); break; }
			Seg lst = mx[SZ(mx) - 1].second;
			assert(cur.y >= lst.y);
			if (cur.y == lst.y) { assert(cur.rx > lst.rx); mx.pop_back(); continue; }
			double a = 1.0 * (lst.rx - cur.rx) / (cur.y - lst.y);
			if (a <= mx[SZ(mx) - 1].first) { mx.pop_back(); continue; }
			mx.PB(MP(a, cur));
			break;
		}
	}
	//printf("mx:"); REPSZ(i, mx) { if (i != 0) printf(" %.2lf ", mx[i].first); printf("(x=%d,y=%d)", mx[i].second.rx, mx[i].second.y); } puts("");

	sort(seg, seg + nseg, [](const Seg& a, const Seg& b) { if (a.y != b.y) return a.y > b.y; return a.lx > b.lx; });
	mn.clear();
	REP(i, nseg) {
		Seg cur = seg[i];
		while (true) {
			if (SZ(mn) == 0) { mn.PB(MP(-1e200, cur)); break; }
			Seg lst = mn[SZ(mn) - 1].second;
			assert(cur.y <= lst.y);
			if (cur.y == lst.y) { assert(cur.lx < lst.lx); mn.pop_back(); continue; }
			double a = 1.0 * (cur.lx - lst.lx) / (lst.y - cur.y);
			if (a <= mn[SZ(mn) - 1].first) { mn.pop_back(); continue; }
			mn.PB(MP(a, cur));
			break;
		}
	}
	//printf("mn:"); REPSZ(i, mn) { if (i != 0) printf(" %.2lf ", mn[i].first); printf("(x=%d,y=%d)", mn[i].second.lx, mn[i].second.y); } puts("");

	e.clear();
	REP(i, nseg) REP(j, nseg) if (seg[i].y > seg[j].y) {
		Frac l(seg[j].lx - seg[i].rx, seg[i].y - seg[j].y);
		Frac r(seg[j].rx - seg[i].lx, seg[i].y - seg[j].y);
		//printf("forbidden: %.2lf..%.2lf\n", 1.0 * l.num / l.den, 1.0 * r.num / r.den);
		e.PB(MP(l, +1)); e.PB(MP(r, -1));
	}
	sort(e.begin(), e.end());

	int bal = 0, ate = 0, atmx = 0, atmn = 0; double a = -1e200; double ret = 1e200;
	while (a < 1e200) {
		while (ate < SZ(e) && 1.0 * e[ate].first.num / e[ate].first.den <= a) bal += e[ate++].second;
		while (bal > 0 && ate < SZ(e)) bal += e[ate++].second;
		assert(bal == 0);
		if (ate - 1 >= 0) a = max(a, 1.0 * e[ate - 1].first.num / e[ate - 1].first.den);
		// e[ate-1].first..e[ate].first
		while (atmx + 1 < SZ(mx) && mx[atmx + 1].first <= a) ++atmx;
		while (atmn + 1 < SZ(mn) && mn[atmn + 1].first <= a) ++atmn;
		double na = 1e200;
		if (atmx + 1 < SZ(mx)) na = min(na, mx[atmx + 1].first);
		if (atmn + 1 < SZ(mn)) na = min(na, mn[atmn + 1].first);
		if (ate < SZ(e)) na = min(na, 1.0 * e[ate].first.num / e[ate].first.den);
		//if (a == -1e200) printf("-oo"); else printf("%.2lf", a);
		//printf("..");
		//if (na == 1e200) printf("+oo"); else printf("%.2lf", na);
		//printf(": l=(%d,%d) r=(%d,%d)\n", mn[atmn].second.lx, mn[atmn].second.y, mx[atmx].second.rx, mx[atmx].second.y);
		ret = min(ret, calc(a, na, mn[atmn].second, mx[atmx].second));
		a = na;
	}

	return ret;
}

void run() {
	scanf("%d", &nseg);
	REP(i, nseg) scanf("%d%d%d", &seg[i].lx, &seg[i].rx, &seg[i].y);
	printf("%.15lf\n", solve());

}

int main() {
	run();
	return 0;
}