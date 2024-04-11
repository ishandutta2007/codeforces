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

struct P { double x, y; P() {} P(double x, double y) :x(x), y(y) {} };
const double eps = 1e-9;

bool local;
double locx, locy;

double query(const vector<P>& pol) {
	if (!local) {
		printf("? %d\n", SZ(pol)); REPSZ(i, pol) printf("%.15lf %.15lf\n", pol[i].x, pol[i].y); fflush(stdout);
		double ret; scanf("%lf", &ret); return ret;
	} else {
		int num = 0, den = 0;
		std::uniform_real_distribution<double> unif(0, 1);
		REP(rep, 1000000) {
			P p(locx + unif(rnd), locy + unif(rnd));
			int cnt = 0;
			REPSZ(i, pol) {
				P a = pol[i];
				P b = pol[(i + 1) % SZ(pol)];
				if (a.y > b.y) swap(a, b);
				if (a.y == b.y) continue;
				if (a.y >= p.y || b.y <= p.y) continue;
				if (a.x + (p.y - a.y) / (b.y - a.y) * (b.x - a.x) < p.x) ++cnt;
			}
			if (cnt % 2 == 1) ++num;
			++den;
		}
		return 1.0 * num / den;
	}
}

double solve1dim(int h, int w, bool flipped) {
	if (w == 1) return 0;
	vector<P> pol;
	pol.PB(P(w, 0)), pol.PB(P(w - 1, 0));
	REP(y, h) pol.PB(P(0, y + 0.5)), pol.PB(P(w - 1, y + 1));
	pol.PB(P(w, h));
	if (flipped) REPSZ(i, pol) swap(pol[i].x, pol[i].y);
	double res = query(pol);
	double step = 1.0 / (w - 1), half = 0.5 * step;
	if (res < (w - 2) * step + half) return (res - half) / step;
	return w - 1 - sqrt(2 * (w - 1) * (1 - res));
}

int h, w; // x==w, y==h

P solve() {
	double x = solve1dim(h, w, false);
	double y = solve1dim(w, h, true);
	return P(x, y);
}

void run() {
	scanf("%d%d", &w, &h);
	P ans = solve();
	printf("! %.15lf %.15lf\n", ans.x, ans.y); fflush(stdout);
}

void test() {
	local = true; scanf("%d%d%lf%lf", &w, &h, &locx, &locy);
	P ans = solve();
	printf("! %.15lf %.15lf\n", ans.x, ans.y);
}

int main() {
	run();
	//test();
	return 0;
}