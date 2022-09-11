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

const int MAXN = 200000;
struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };
struct PF { double x, y; PF() {} PF(double x, double y) :x(x), y(y) {} };
P operator-(const P& a, const P& b) { return P(a.x - b.x, a.y - b.y); };
PF operator*(const double& a, const P& b) { return PF(a * b.x, a * b.y); };
PF operator+(const P& a, const PF& b) { return PF(a.x + b.x, a.y + b.y); };
PF operator-(const PF& a, const P& b) { return PF(a.x - b.x, a.y - b.y); };
ll operator^(const P& a, const P& b) { return (ll)a.x * b.y - (ll)a.y * b.x; }
int side(const P& a, const P& b, const P& c) { ll res = (b - a) ^ (c - a); return res > 0 ? +1 : res < 0 ? -1 : 0; }
double len(const P& a) { return sqrt(1.0 * a.x * a.x + 1.0 * a.y * a.y); }
double len(const PF& a) { return sqrt(a.x * a.x + a.y * a.y); }

int n, heye;
P p[MAXN];

PF intersect(const P& a, const P& b, const P& c, const P& d) {
	ll num1 = (d - c) ^ (c - a);
	ll num2 = (b - a) ^ (c - a);
	ll den = (d - c) ^ (b - a);
	if (den < 0) num1 = -num1, num2 = -num2, den = -den;
	assert(den != 0);
	return a + (1.0 * num1 / den) * (b - a);
}

double solve() {
	P eye = P(p[n - 1].x, p[n - 1].y + heye);
	P look = p[n - 1];
	double ret = 0;
	for (int i = n - 2; i >= 0; --i) {
		// p[i+1] is always <= eye-look line
		int s = side(eye, look, p[i]);
		if (s > 0) continue;
		if (s == 0 && side(eye, look, p[i + 1]) == 0) {
			ret += len(p[i + 1] - p[i]);
			//printf("entire %d..%d\n", i, i + 1);
		} else {
			PF pos = intersect(p[i], p[i + 1], eye, look);
			//printf("pos=(%lf,%lf)\n", pos.x, pos.y);
			ret += len(pos - p[i]);
		}
		look = p[i];
		//printf("looking at %d\n", i);
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &heye);
	REP(i, n) scanf("%d%d", &p[i].x, &p[i].y);
	printf("%.15lf\n", solve());
}

int main() {
	run();
	return 0;
}