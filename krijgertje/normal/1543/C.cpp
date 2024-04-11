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

const double eps = 1e-9;
const int MAXHALVES = 20;

double pa, pb, pc, step;
map<pair<int, int>, double> mem;

double rec(double ca, double cb, double cc, int ahalves, int bhalves) {
	if (ca < eps && cb < eps) return 1.0;
	if (ca < eps) { double cur = min(cb, step); return 1 + cb * rec(ca, cb - cur, cc + cur, ahalves, bhalves); }
	if (cb < eps) { double cur = min(ca, step); return 1 + ca * rec(ca - cur, cb, cc + cur, ahalves, bhalves); }
	if (mem.count(MP(ahalves, bhalves))) return mem[MP(ahalves, bhalves)];
	double ret = 1;
	{ double cur = min(ca, step); ret += ca * rec(ca - cur, cb + cur / 2, cc + cur / 2, ahalves - 2, bhalves + 1); }
	{ double cur = min(cb, step); ret += cb * rec(ca + cur / 2, cb - cur, cc + cur / 2, ahalves + 2, bhalves - 2); }
	return mem[MP(ahalves, bhalves)] = ret;
}

double solve() {
	mem.clear();
	return rec(pa, pb, pc, 0, 0);
}

void run() {
	scanf("%lf%lf%lf%lf", &pa, &pb, &pc, &step);
	printf("%.15lf\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}