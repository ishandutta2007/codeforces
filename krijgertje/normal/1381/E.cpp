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
const int MAXQ = 100000;
const double eps = 1e-9;
struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };

P operator-(const P &a, const P &b) { return P(a.x - b.x, a.y - b.y); }
ll operator^(const P &a, const P &b) { return (ll)a.x*b.y - (ll)a.y*b.x; }
int side(const P &a, const P &b, const P &c) { ll res = (b - a) ^ (c - a); return res < 0 ? -1 : res>0 ? +1 : 0; }


int n, nq;
P p[MAXN + 1];
int qx[MAXQ]; double qans[MAXQ];

int gmnx, gmxx;

void normalize() {
	int mnyidx = 0; FOR(i, 1, n) if (p[i].y < p[mnyidx].y) mnyidx = i;
	rotate(p, p + mnyidx, p + n);
	if (side(p[0], p[1], p[n - 1]) > 0) reverse(p + 1, p + n);
	p[n] = p[0];
	//printf("p:"); REP(i, n) printf(" (%d,%d)", p[i].x, p[i].y); puts("");
	gmnx = p[0].x; FOR(i, 1, n) gmnx = min(gmnx, p[i].x);
	gmxx = p[0].x; FOR(i, 1, n) gmxx = max(gmxx, p[i].x);
}

double getx(const P &a, const P &b, int y) {
	assert(a.y < b.y && a.y <= y && y <= b.y);
	return a.x + 1.0*(y - a.y) / (b.y - a.y)*(b.x - a.x);
}

struct Part { 
	double lx, hx, a, b, c; 
	Part() {} Part(double lx, double hx, double a, double b, double c) :lx(lx), hx(hx), a(a), b(b), c(c) {} 
	bool isinside(int x) { return x >= lx - eps && x <= hx - eps; }
	double get(int x) { return a*x*x + b*x + c; }
}; // a*x^2+b*x+c
vector<Part> parts;


// int(y=ly..ex+f, ax+by+c)
void buildvarupper(double lx, double hx, double ly, double e, double f, double a, double b, double c) {
	// axy+1/2by^2+cy -> (a*x*(e*x+f)+1/2*b*(e*e*x*x+2*e*f*x+f*f)+c*(e*x+f))-(a*x*ly+1/2*b*ly*ly+c*ly)
	parts.PB(Part(lx, hx, +a*e + 0.5*b*e*e, a*f + b*e*f + c*e - a*ly, 0.5*b*f*f + c*f - 0.5*b*ly*ly - c*ly));

}
// int(y=ex+f..hy, ax+by+c)
void buildvarlower(double lx, double hx, double e, double f, double hy, double a, double b, double c) {
	// axy+1/2by^2+cy -> (a*x*hy+1/2*b*hy*hy+c*hy)-(a*x*(e*x+f)+1/2*b*(e*x+f)*(e*x+f)+c*(e*x+f))
	parts.PB(Part(lx, hx, -a*e - 0.5*b*e*e, a*hy - a*f - b*e*f - c*e, 0.5*b*hy*hy + c*hy - 0.5*b*f*f - c*f));
}
// int(y=ly..hy, ax+by+c)
void buildfixed(double lx, double hx, double ly, double hy, double a, double b, double c) {
	// axy+1/2by^2+cy -> (a*x*hy+1/2*b*hy*hy+c*hy)-(a*x*ly+1/2*b*ly*ly+c*ly)
	parts.PB(Part(lx, hx, 0, a*(hy - ly), 0.5*b*(hy*hy - ly*ly) + c*(hy - ly)));
}

// int(y=ly..min(hy,ex+f), ax+by+c)
void buildbelow(double a, double b, double c, int ly, int hy, double e, double f) {
	assert(fabs(e) > eps && ly < hy);
	if (e > 0) {
		double lx = (ly - f) / e, hx = (hy - f) / e;
		//printf("\t\tfor x in (%lf,%lf) %d..%lfx+%lf for [%lf,%lf,%lf]\n", lx, hx, ly,e, f, a, b, c);
		buildvarupper(lx, hx, ly, e, f, a, b, c);
		//printf("\t\tfor x in (%lf,oo) %d..%d for [%lf,%lf,%lf]\n", hx, ly, hy, a, b, c);
		buildfixed(hx, gmxx, ly, hy, a, b, c);
	} else {
		double hx = (ly - f) / e, lx = (hy - f) / e;
		//printf("\t\tfor x in (-oo,%lf) %d..%d for [%lf,%lf,%lf]\n", lx, ly, hy, a, b, c);
		buildfixed(gmnx, lx, ly, hy, a, b, c);
		//printf("\t\tfor x in (%lf,%lf) %d..%lfx+%lf for [%lf,%lf,%lf]\n", lx, hx, ly, e, f, a, b, c);
		buildvarupper(lx, hx, ly, e, f, a, b, c);
	}
}

// int(y=max(ly,ex+f)..hy, ax+by+c)
void buildabove(double a, double b, double c, int ly, int hy, double e, double f) {
	assert(fabs(e) > eps && ly < hy);
	if (e > 0) {
		double lx = (ly - f) / e, hx = (hy - f) / e;
		//printf("\t\tfor x in (-oo,%lf) %d..%d for [%lf,%lf,%lf]\n", lx, ly, hy, a, b, c);
		buildfixed(gmnx, lx, ly, hy, a, b, c);
		//printf("\t\tfor x in (%lf,%lf) %lfx+%lf..%d for [%lf,%lf,%lf]\n", lx, hx, e, f, hy, a, b, c);
		buildvarlower(lx, hx, e, f, hy, a, b, c);
	} else {
		double hx = (ly - f) / e, lx = (hy - f) / e;
		//printf("\t\tfor x in (%lf,%lf) %lfx+%lf..%d for [%lf,%lf,%lf]\n", lx, hx, e, f, hy, a, b, c);
		buildvarlower(lx, hx, e, f, hy, a, b, c);
		//printf("\t\tfor x in (%lf,oo) %d..%d for [%lf,%lf,%lf]\n", hx, ly, hy, a, b, c);
		buildfixed(hx, gmxx, ly, hy, a, b, c);
	}
}

void buildparts() {
	parts.clear();
	int l = 0, r = n, ly = p[l].y;
	int mxyidx = 0; FOR(i, 1, n) if (p[i].y > p[mxyidx].y) mxyidx = i;
	while (l < mxyidx && r > mxyidx) {
		assert(ly >= p[l].y && ly >= p[r].y);
		int hy = min(p[l + 1].y, p[r - 1].y);
		assert(hy > ly);
		double lx1 = getx(p[l], p[l + 1], ly), lx2 = getx(p[l], p[l + 1], hy), mnlx = min(lx1, lx2), mxlx = max(lx1, lx2);
		double rx1 = getx(p[r], p[r - 1], ly), rx2 = getx(p[r], p[r - 1], hy), mnrx = min(rx1, rx2), mxrx = max(rx1, rx2);

		double a = (lx2 - lx1) / (hy - ly), b = lx1 - a*ly;
		double c = (rx2 - rx1) / (hy - ly), d = rx1 - c*ly;
		//printf("%d..%d: %lf->%lf / %lf->%lf -> %lfy+%lf / %lfy+%lf\n", ly, hy, lx1, lx2, rx1, rx2, a, b, c, d);
		// int(y==ly..hy,max(x-a*y-b,c*y+d-x))

		if (fabs(a + c) > eps) {
			double e = 2 / (a + c), f = -(b + d) / (a + c);
			//printf("\t%lfx+%lf\n", e, f);
			if (a + c > 0) {
				buildbelow(+1, -a, -b, ly, hy, e, f);
				buildabove(-1, +c, +d, ly, hy, e, f);
			} else {
				buildabove(+1, -a, -b, ly, hy, e, f);
				buildbelow(-1, +c, +d, ly, hy, e, f);
			}

		} else {
			double mx = (b + d) / 2;
			if (mx <= gmnx + eps) {
				buildfixed(gmnx, gmxx, ly, hy, -1, +c, +d);
			} else if (mx >= gmxx - eps) {
				buildfixed(gmnx, gmxx, ly, hy, +1, -a, -b);
			} else {
				buildfixed(gmnx, mx, ly, hy, -1, +c, +d);
				buildfixed(mx, gmxx, ly, hy, +1, -a, -b);
			}
			//printf("!!! (mx=%lf gmnx=%d gmxx=%d)\n", mx, gmnx, gmxx);
		}

		if (fabs(mnlx - gmnx) > eps) parts.PB(Part(gmnx, mnlx, 0, hy - ly, -1.0*(hy - ly)*mnlx - 0.5*(hy - ly)*(mxlx - mnlx)));
		// 0.5*(mxlx-x)*(hy-ly)*(mxlx-x)/(mxlx-mnlx) -> 0.5*(hy-ly)/(mxlx-mnlx)*(mxlx*mxlx-2*mxlx*x+x*x)
		if (fabs(mxlx - mnlx) > eps) { double z = 0.5*(hy - ly) / (mxlx - mnlx); parts.PB(Part(mnlx, mxlx, -z, +2 * z*mxlx, -z*mxlx*mxlx)); }
		// 0.5*(x-mnrx)*(hy-ly)*(x-mnrx)/(mxrx-mnrx) -> 0.5*(hy-ly)/(mxrx-mnrx)*(x*x-2*mnrx*x+mnrx*mnrx)
		if (fabs(mxrx - mnrx) > eps) { double z = 0.5*(hy - ly) / (mxrx - mnrx); parts.PB(Part(mnrx, mxrx, -z, +2 * z*mnrx, -z*mnrx*mnrx)); }
		if (fabs(gmxx - mxrx) > eps) parts.PB(Part(mxrx, gmxx, 0, -(hy - ly), 1.0*(hy - ly)*mxrx - 0.5*(hy - ly)*(mxrx - mnrx)));

		ly = hy;
		if (p[l + 1].y == ly) ++l;
		if (p[r - 1].y == ly) --r;
		//break;
	}
	//REPSZ(i, parts) { Part p = parts[i]; printf("%lf..%lf: %lf*x^2+%lf*x+%lf\n", p.lx, p.hx, p.a, p.b, p.c); }
}

struct E { double x, a, b, c; E() {} E(double x, double a, double b, double c) :x(x), a(a), b(b), c(c) {} };
bool operator<(const E &p, const E &q) { return p.x < q.x; }

pair<int, int> o[MAXQ];
vector<E> e;

void solvequeries() {
	REP(i, nq) o[i] = MP(qx[i], i);
	sort(o, o + nq);
	e.clear();
	REPSZ(i, parts) { 
		Part p = parts[i];
		e.PB(E(p.lx - eps, +p.a, +p.b, +p.c));
		e.PB(E(p.hx - eps, -p.a, -p.b, -p.c));
	}
	sort(e.begin(), e.end());
	double a = 0, b = 0, c = 0; int at = 0;
	REP(i, nq) {
		int id = o[i].second; int x = qx[id];
		while (at < SZ(e) && e[at].x < x) { a += e[at].a, b += e[at].b, c += e[at].c; ++at; }
		qans[id] = a*x*x + b*x + c;
	}


	/*REP(i, nq) {
		int x = qx[i];
		double sum = 0; REPSZ(j, parts) if (parts[j].isinside(x)) sum += parts[j].get(x);
		printf("q%d: %lf\n", x, sum);
	}*/

}

void solve() {
	normalize();
	buildparts();
	solvequeries();
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d%d", &p[i].x, &p[i].y);
	REP(i, nq) scanf("%d", &qx[i]);
	solve();
	REP(i, nq) printf("%.15lf\n", qans[i]);
}

int main() {
	run();
	return 0;
}