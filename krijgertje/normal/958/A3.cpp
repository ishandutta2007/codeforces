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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }


default_random_engine re;

const int MAXN = 50000;
const int MAXNN = (3 * MAXN + 1) / 2;
const double MPI = acos(-1.0);
struct P { double x, y; int idx; P() {} P(double x, double y) :x(x), y(y) {} };
bool operator<(const P &a, const P &b) { if (fabs(a.x - b.x) > 1e-9) return a.x < b.x; if (fabs(a.y - b.y) > 1e-9) return a.y < b.y; return a.idx < b.idx; }
P operator-(const P &a, const P &b) { return P(a.x - b.x, a.y - b.y); }
P operator+(const P &a, const P &b) { return P(a.x + b.x, a.y + b.y); }
double operator^(const P &a, const P &b) { return a.x*b.y - a.y*b.x; }
double side(const P &a, const P &b, const P &c) { return (b - a) ^ (c - a); }
double len(const P &a) { return sqrt(a.x*a.x + a.y*a.y); }

int n;
int na, nb;

P a[MAXNN], b[MAXNN];

P ha[MAXNN + 1]; int nha;
P hb[MAXNN + 1]; int nhb;

P p[MAXNN];

void calchull(P *_p, int np, P *h, int &nh) {
	REP(i, np) p[i] = _p[i];
	sort(p, p + np); nh = 0;
	REP(i, np) { while (nh >= 2 && side(h[nh - 2], h[nh - 1], p[i]) <= 0) --nh; h[nh++] = p[i]; }
	int was = nh; for (int i = np - 2; i >= 0; --i) { while (nh > was && side(h[nh - 2], h[nh - 1], p[i]) <= 0) --nh; h[nh++] = p[i]; }
	--nh;
}

P rot(const P &p, double ang) {
	double angcos = cos(ang), angsin = sin(ang);
	P ret(p.x*angcos - p.y*angsin, p.x*angsin + p.y*angcos); ret.idx = p.idx; return ret;
}

P c[MAXNN];
P d[MAXNN];
pair<double, int> oa[MAXNN];
pair<double, int> ob[MAXNN];
bool used[MAXNN];
const int MAGIC = 100;

pair<double, pair<int, int> > ret[MAXNN]; int nret;


bool solve(const P &a1, const P &b1, const P &a2, const P &b2) {
	P da = a2 - a1, db = b2 - b1;
	double anga = atan2(da.y, da.x), angb = atan2(db.y, db.x), ang = angb - anga;
	P c1 = rot(a1, ang), c2 = rot(a2, ang);
	P t = b1 - c1;
	REP(i, na) c[i] = rot(a[i], ang) + t, c[i].idx = a[i].idx;
	//printf("c:"); REP(i, na) printf(" (%.2lf,%.2lf)", c[i].x, c[i].y); puts("");
	//printf("b:"); REP(i, nb) printf(" (%.2lf,%.2lf)", b[i].x, b[i].y); puts("");

	uniform_real_distribution<double> aunif(0, 2 * acos(-1.0));
	double rang = aunif(re);
	REP(i, na) c[i] = rot(c[i], rang);
	REP(i, nb) d[i] = rot(b[i], rang);

	REP(i, na) oa[i] = MP(c[i].x + c[i].y, c[i].idx); sort(oa, oa + na);
	REP(i, nb) ob[i] = MP(d[i].x + d[i].y, d[i].idx); sort(ob, ob + nb);

	//REP(i, max(na, nb)) printf("%lf %lf\n", i < na ? oa[i].first : -1, i < nb ? ob[i].first : -1);

	int at = 0; nret = 0;
	REP(i, nb) used[i] = false;
	REP(i, na) {
		while (at<nb&&oa[i].first>ob[at].first) ++at;
		//printf("%lf %lf -> %lf\n", oa[i].first, at < nb ? ob[at].first : -1, at < nb ? len(c[oa[i].second] - d[ob[at].second]) : -1);
		int best = -1; double bestval = 1e200;
		REP(j, MAGIC) {
			if (at + j < nb && !used[ob[at + j].second]) {
				double curval = len(c[oa[i].second] - d[ob[at + j].second]);
				if (curval < bestval) bestval = curval, best = ob[at + j].second;
			}
			if (at - j >= 0 && !used[ob[at - j].second]) {
				double curval = len(c[oa[i].second] - d[ob[at - j].second]);
				if (curval < bestval) bestval = curval, best = ob[at - j].second;
			}
		}
		if (bestval < 0.1) {
			//printf("%d with %d\n", oa[i].second, best);
			ret[nret++] = MP(bestval, MP(oa[i].second, best));
			used[best] = true;
		}
		//printf("at=%d\n", at);
	}
	//printf("nret=%d\n", nret);
	if (nret < n) return false;
	sort(ret, ret + nret);
	REP(i, n) printf("%d %d\n", ret[i].second.first + 1, ret[i].second.second + 1);
	return true;
}

void run() {
	scanf("%d", &n);
	scanf("%d", &na); REP(i, na) scanf("%lf%lf", &a[i].x, &a[i].y), a[i].idx = i;
	scanf("%d", &nb); REP(i, nb) scanf("%lf%lf", &b[i].x, &b[i].y), b[i].idx = i;

	calchull(a, na, ha, nha);
	calchull(b, nb, hb, nhb);

	REP(a1, nha) FOR(a2, a1 + 1, nha) REP(b1, nhb) FOR(b2, b1 + 1, nhb) {
		double da = len(ha[a1] - ha[a2]), db = len(hb[b1] - hb[b2]);
		if (fabs(da) < 0.1 || fabs(db) < 0.1 || fabs(da - db) > 0.02) continue;
		//printf("%lf\n", fabs(da - db));
		if (solve(ha[a1], hb[b2], ha[a2], hb[b1])) return;
		if (solve(ha[a1], hb[b1], ha[a2], hb[b2])) return;
	}
	printf("not found\n");
}

int main() {
	run();
	return 0;
}