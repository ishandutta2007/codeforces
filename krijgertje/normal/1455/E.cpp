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

struct P { int x, y; };

P p[4];

ll solve() {
	vector<int> perm(4); REP(i, 4) perm[i] = i;
	ll ret = LLONG_MAX;
	do {
		vector<int> x(4); REP(i, 4) x[i] = p[perm[i]].x;
		swap(x[1], x[3]);
		sort(x.begin(), x.begin() + 2);
		sort(x.begin() + 2, x.end());
		int lx = max(0, x[2] - x[1]);
		int rx = max(0, x[3] - x[0]);
		vector<int> y(4); REP(i, 4) y[i] = p[perm[i]].y;
		sort(y.begin(), y.begin() + 2);
		sort(y.begin() + 2, y.end());
		int ly = max(0, y[2] - y[1]);
		int ry = max(0, y[3] - y[0]);
		int lz = max(lx, ly), rz = min(rx, ry);
		int sz;
		if (rx < ly) sz = rx; else if (ry < lx) sz = ry; else { assert(lz <= rz); sz = lz; }
		x[2] -= sz, x[3] -= sz, y[2] -= sz, y[3] -= sz;
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		ll cur = (ll)x[3] - x[0] + x[2] - x[1] + y[3] - y[0] + y[2] - y[1];
		//REP(i, 4) printf("(%d,%d) ", p[perm[i]].x, p[perm[i]].y); printf("%d..%d %d..%d (%d..%d) -> %d: %lld\n", lx, rx, ly, ry, lz, rz, sz, cur);
		ret = min(ret, cur);
	} while (next_permutation(perm.begin(), perm.end()));
	return ret;
}

void run() {
	REP(i, 4) scanf("%d%d", &p[i].x, &p[i].y);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}