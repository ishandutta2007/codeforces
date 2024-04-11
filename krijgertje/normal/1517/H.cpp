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

const int MAXN = 100000;

struct Frac {
	ll num, den;
	Frac() :num(0), den(1) {}
	Frac(ll _num) :num(_num), den(1) {}
	Frac(ll _num, ll _den) { num = _num, den = _den; if (den < 0) num = -num, den = -den; ll g = gcd(abs(num), den); num /= g, den /= g; }
	void print() const { printf("%lld", num); if (den != 1) printf("/%lld", den); }
};
Frac operator+(const Frac& a, const Frac& b) { ll g = gcd(a.den, b.den); return Frac(a.num * (b.den / g) + b.num * (a.den / g), a.den * (b.den / g)); }
Frac operator-(const Frac& a, const Frac& b) { ll g = gcd(a.den, b.den); return Frac(a.num * (b.den / g) - b.num * (a.den / g), a.den * (b.den / g)); }
Frac operator*(const Frac& a, const Frac& b) { ll g1 = gcd(abs(a.num), b.den); ll g2 = gcd(abs(b.num), a.den); return Frac((a.num / g1) * (b.num / g2), (a.den / g2) * (b.den / g1)); }
Frac operator/(const Frac& a, const Frac& b) { return Frac(a.num * b.den, a.den * b.num); }
bool operator<(const Frac& a, const Frac& b) { return a.num * b.den < b.num * a.den; }
bool operator>(const Frac& a, const Frac& b) { return a.num * b.den > b.num * a.den; }
bool operator!=(const Frac& a, const Frac& b) { return a.num != b.num || a.den != b.den; }

struct P { Frac x, y; P() {} P(Frac x, Frac y) :x(x), y(y) {} void print() const { printf("("); x.print(); printf(","); y.print(); printf(")"); } };
P operator+(const P& a, const P& b) { return P(a.x + b.x, a.y + b.y); }
P operator*(const Frac& a, const P& b) { return P(a * b.x, a * b.y); }
P operator-(const P& a, const P& b) { return P(a.x - b.x, a.y - b.y); }
bool operator!=(const P& a, const P& b) { return a.x != b.x || a.y != b.y; }

P calcx(const P& a, const P& b, int x) { return a + (x - a.x) * (1 / (b.x - a.x) * (b - a)); }
P calcy(const P& a, const P& b, int y) { return a + (y - a.y) * (1 / (b.y - a.y) * (b - a)); }


struct Hull {
	int t; ll dx,dy;
	deque<P> q; // (x,y) -> (x+t*y+dx,y+dy)
	Hull() { t = 0; dx = dy = 0; }

	P tocurrent(const P& a) {
		//if (debug) { printf("tocurrent "); a.print(); printf(" t=%d dx=%lld dy=%lld\n", t, dx.val, dy.val); }
		ll xwhole = a.x.num / a.x.den, ywhole = a.y.num / a.y.den;
		Frac xfrac = a.x - xwhole, yfrac = a.y - ywhole;
		return P((xwhole + t * ywhole + dx) + (xfrac + t * yfrac), a.y + dy);
	}
	P tostored(const P& a) { 
		//printf("tostored a="); a.print(); printf(" t=%d dx=%lld dy=%lld\n", t, dx.val, dy.val); 
		ll xwhole = a.x.num / a.x.den, ywhole = a.y.num / a.y.den;
		Frac xfrac = a.x - xwhole, yfrac = a.y - ywhole;
		//printf("here\n");
		//printf("-> "); (xfrac).print(); puts("");
		//printf("-> "); (t * yfrac).print(); puts("");
		//printf("-> "); (xwhole + t * dy + dx - t * ywhole).print(); puts("");
		//printf("-> "); (xfrac - t * yfrac).print(); puts("");
		P ret = P((xfrac - t * yfrac) + (xwhole + t * dy - dx - t * ywhole), a.y - dy);
		//P ret = P(a.x - t * (a.y - dy) + dx, a.y - dy);
		//printf("done\n");
		return ret;
	}

	void removefirst() { assert(!q.empty()); q.pop_front(); }
	void removelast() { assert(!q.empty()); q.pop_back(); }
	P first() { assert(!q.empty()); return tocurrent(q.front()); }
	P last() { assert(!q.empty()); return tocurrent(q.back()); }
	Frac ymax() { return last().y; }
	Frac ymin() { return first().y; }
	Frac xmax() { return last().x; }
	Frac xmin() { return first().x; }

	void prepend(const P& p) { if (q.empty() || first() != p) q.push_front(tostored(p)); }
	void append(const P& p) { if (q.empty() || last() != p) q.push_back(tostored(p)); }

	void cutbelow(int y) {
		P p = first();
		while (p.y < y) {
			removefirst();
			P q = first();
			if (q.y > y) { prepend(calcy(p, q, y)); break; }
			p = q;
		}
	}
	void cutabove(int y) {
		P p = last();
		while (p.y > y) {
			removelast();
			P q = last();
			if (q.y < y) { append(calcy(q, p, y)); break; }
			p = q;
		}
	}
	void cutleft(int x) {
		P p = first();
		while (p.x < x) {
			removefirst();
			P q = first();
			if (q.x > x) { prepend(calcx(p, q, x)); break; }
			p = q;
		}
	}
	void cutright(int x) {
		P p = last();
		while (p.x > x) {
			removelast();
			P q = last();
			if (q.x < x) { append(calcx(q, p, x)); break; }
			p = q;
		}
	}
	void transform() {
		//REPSZ(i, q) q[i].x = q[i].x + q[i].y;
		++t, dx += dy;
	}
	void translate(int z) {
		//REPSZ(i, q) q[i].x = q[i].x + z, q[i].y = q[i].y + z;
		dx += z, dy += z;
	}

	void print(char* s) {
		printf("%s:", s); REPSZ(i, q) { printf(" "); tocurrent(q[i]).print(); } puts("");
	}
};



int n;
int xlo[MAXN], xhi[MAXN];
int ylo[MAXN], yhi[MAXN];
int zlo[MAXN], zhi[MAXN];

bool solve() {
	Hull lo;
	Hull hi;


	auto empty = [&]() {
		return lo.q.empty() || hi.q.empty();
	};
	auto clear = [&]() {
		lo.q.clear();
		hi.q.clear();
	};
	auto cutbelow = [&](int y) {
		if (empty()) return;
		if (lo.ymax() < y) return clear();
		lo.cutbelow(y);
		hi.cutbelow(y);
		lo.prepend(hi.first());
	};
	auto cutabove = [&](int y) {
		if (empty()) return;
		if (lo.ymin() > y) return clear();
		lo.cutabove(y);
		hi.cutabove(y);
		hi.append(lo.last());
	};
	auto cutleft = [&](int x) {
		if (empty()) return;
		if (lo.xmax() < x) return clear();
		lo.cutleft(x);
		hi.cutleft(x);
		hi.prepend(lo.first());
	};
	auto cutright = [&](int x) {
		if (empty()) return;
		if (lo.xmin() > x) return clear();
		lo.cutright(x);
		hi.cutright(x);
		lo.append(hi.last());
	};
	auto transform = [&]() {
		if (empty()) return;
		lo.transform();
		hi.transform();
	};
	auto translate = [&](int lz,int hz) {
		if (empty()) return;
		lo.translate(lz);
		hi.translate(hz);
		lo.append(hi.last());
		hi.prepend(lo.first());
	};

	P llo(xlo[1], xlo[1] - xhi[0]);
	P rlo(xhi[1], xhi[1] - xhi[0]);
	P lhi(xlo[1], xlo[1] - xlo[0]);
	P rhi(xhi[1], xhi[1] - xlo[0]);
	lo.append(llo);
	lo.append(rlo);
	lo.append(rhi);
	hi.append(llo);
	hi.append(lhi);
	hi.append(rhi);
	cutbelow(ylo[1]);
	cutabove(yhi[1]);
	//lo.print("loinit");
	//hi.print("hiinit");

	FOR(i, 2, n) {
		transform();
		translate(zlo[i], zhi[i]);
		cutleft(xlo[i]);
		cutright(xhi[i]);
		cutbelow(ylo[i]);
		cutabove(yhi[i]);
	}
	//lo.print("lofinal");
	//hi.print("hifinal");

	return !empty();
}

void run(int casenr) {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &xlo[i], &xhi[i]);
	FOR(i, 1, n) scanf("%d%d", &ylo[i], &yhi[i]);
	FOR(i, 2, n) scanf("%d%d", &zlo[i], &zhi[i]);
	if (false) {
		printf("n=%d\n", n);
		REP(i, n) { if (i - 2 >= 0 && xlo[i] == xlo[i - 2] && xhi[i] == xhi[i - 2]) continue; printf("x[%d]=(%d,%d)\n", i, xlo[i], xhi[i]); }
		FOR(i, 1, n) { if (i - 2 >= 1 && ylo[i] == ylo[i - 2] && yhi[i] == yhi[i - 2]) continue; printf("y[%d]=(%d,%d)\n", i, ylo[i], yhi[i]); }
		FOR(i, 2, n) { if (i - 2 >= 2 && zlo[i] == zlo[i - 2] && zhi[i] == zhi[i - 2]) continue; printf("z[%d]=(%d,%d)\n", i, zlo[i], zhi[i]); }
		exit(0);
	}
	printf("%s\n", solve() ? "YES" : "NO");
}

void stress() {
	const int MINLIM = -1e8, MAXLIM = +1e8;
	auto genval = [&]() { return rnd() % (MAXLIM/4 - MINLIM/4 + 1) + MINLIM/4; };
	auto genatmost = [&](int x) { x = min(x, MAXLIM); assert(x >= MINLIM); return rnd() % (x - MINLIM + 1) + MINLIM; };
	auto genatleast = [&](int x) { x = max(x, MINLIM); assert(x <= MAXLIM); return rnd() % (MAXLIM - x + 1) + x; };

	REP(rep, 1) {
		n = MAXN;
		vector<ll> ans(n); REP(i, n) ans[i] = genval();

		/*REP(i, n) { xlo[i] = genatmost(ans[i]); xhi[i] = genatleast(ans[i]); }
		FOR(i, 1, n) { ylo[i] = genatmost(ans[i] - ans[i - 1]); xhi[i] = genatleast(ans[i] - ans[i - 1]); }
		FOR(i, 2, n) { zlo[i] = genatmost((ans[i] - ans[i - 1]) - (ans[i - 1] - ans[i - 2])); zlo[i] = genatleast((ans[i] - ans[i - 1]) - (ans[i - 1] - ans[i - 2])); }*/

		/*xlo[0] = xhi[0] = -2; xlo[1] = -1, xhi[1] = +1; xlo[2] = -100000000, xhi[2] = 1, xlo[3] = -100000000, xhi[3] = 100000000;
		FOR(i, 4, n) xlo[i] = xlo[i - 2], xhi[i] = xhi[i - 2];
		xlo[99997] = -6624322, xhi[99997] = 74252438; xlo[99998] = -45047987, xhi[99998] = -16354480; xlo[99999] = -66279757, xhi[99999] = 89508424;
		ylo[1] = -1, yhi[1] = 1; ylo[2] = -100000000, yhi[2] = 100000000; ylo[3] = -100000000, yhi[3] = 100000000;
		FOR(i, 4, n) ylo[i] = ylo[i - 2], yhi[i] = yhi[i - 2];
		ylo[99997] = 13567486, yhi[99997] = 78355001; ylo[99998] = -95239272, yhi[99998] = -48276155; ylo[99999] = -15106488, yhi[99999] = 69428756;
		zlo[2] = zhi[2] = 0, zlo[3] = -1, zhi[3] = 0;
		FOR(i, 4, n) zlo[i] = zlo[i - 2], zhi[i] = zhi[i - 2];
		zlo[99997] = -50245815, zhi[99997] = -45106835; zlo[99998] = -6754906, zhi[99998] = 48421868; zlo[99999] = -54971252, zhi[99999] = 98626604;*/

		/*n = 4000;
		xlo[0] = xhi[0] = -2; xlo[1] = -1, xhi[1] = +1; xlo[2] = -100000000, xhi[2] = 1, xlo[3] = -100000000, xhi[3] = 100000000;
		FOR(i, 4, n) xlo[i] = xlo[i - 2], xhi[i] = xhi[i - 2];
		xlo[3997] = -62270349, xhi[3997] = 15883721; xlo[3998] = -48068918, xhi[3998] = -16258758; xlo[3999] = -69746109, xhi[3999] = -65395351;
		ylo[1] = -1, yhi[1] = 1; ylo[2] = -100000000, yhi[2] = 100000000; ylo[3] = -100000000, yhi[3] = 100000000;
		FOR(i, 4, n) ylo[i] = ylo[i - 2], yhi[i] = yhi[i - 2];
		ylo[3997] = -79334513, yhi[3997] = 10380870; ylo[3998] = -26468846, yhi[3998] = 84698777; ylo[3999] = -57380010, yhi[3999] = 66012270;
		zlo[2] = zhi[2] = 0, zlo[3] = -1, zhi[3] = 0;
		FOR(i, 4, n) zlo[i] = zlo[i - 2], zhi[i] = zhi[i - 2];
		zlo[3997] = -53649231, zhi[3997] = 745637; zlo[3998] = 58667819, zhi[3998] = 71673867; zlo[3999] = -74231555, zhi[3999] = 2290961;*/

		/*n = 10000;
		xlo[0] = -1, xhi[0] = +1; xlo[1] = -1, xhi[1] = +1; xlo[2] = -100000000, xhi[2] = 100000000, xlo[3] = -100000000, xhi[3] = 100000000;
		FOR(i, 4, n) xlo[i] = xlo[i - 2], xhi[i] = xhi[i - 2];
		xlo[n - 3] = 11583918, xhi[n - 3] = 57879847; xlo[n - 2] = 7176753, xhi[n - 2] = 96167903; xlo[n - 1] = -32585366, xhi[n - 1] = 29546461;
		ylo[1] = -1, yhi[1] = 1; ylo[2] = -100000000, yhi[2] = 100000000; ylo[3] = -100000000, yhi[3] = 100000000;
		FOR(i, 4, n) ylo[i] = ylo[i - 2], yhi[i] = yhi[i - 2];
		ylo[n - 3] = -82947042, yhi[n - 3] = 95114671; ylo[n - 2] = -647194, yhi[n - 2] = 38703929; ylo[n - 1] = -34600276, yhi[n - 1] = 45399526;
		zlo[2] = 0, zhi[2] = 100000000, zlo[3] = 0, zhi[3] = 100000000;
		FOR(i, 4, n) zlo[i] = zlo[i - 2], zhi[i] = zhi[i - 2];
		zlo[n - 3] = -11692017, zhi[n - 3] = 34662843; zlo[n - 2] = 76018704, zhi[n - 2] = 91087514; zlo[n - 1] = -84750792, zhi[n - 1] = 14509972;*/

		bool res = solve();
		printf("%s\n", res ? "YES" : "NO");
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run(i);
	//stress();
	return 0;
}