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

const int MAXH = 200000;
const int MAXW = 200000;
const int MAXQ = 200000;

int h, w, nq;
int qx[MAXQ], qy[MAXQ]; bool qans[MAXQ];


int a[MAXW], b[MAXW];

bool can(int cnt) {
	REP(y, w) a[y] = b[y] = 0;
	REP(i, cnt) {
		int x = qx[i], y = qy[i];
		if (x % 2 == 1 && y % 2 == 1) {
			x /= 2, y /= 2;
			a[y] = max(a[y], x + 1);
		} else {
			assert(x % 2 == 0 && y % 2 == 0);
			x /= 2, y /= 2;
			b[y] = max(b[y], h - x);
		}
	}
	for (int y = w - 2; y >= 0; --y) a[y] = max(a[y], a[y + 1]);
	for (int y = 2; y < w; ++y) b[y] = max(b[y], b[y - 1]);
	REP(y, w) if (a[y] + b[y] > h) return false;
	return true;
}

void solve() {
	int lo = 0, hi = nq + 1;
	while (lo + 1 < hi) {
		int mi = lo + (hi - lo) / 2;
		if (can(mi)) lo = mi; else hi = mi;
	}
	int res = lo;
	REP(i, nq) if (i + 1 <= res) qans[i] = true; else qans[i] = false;
}

void run() {
	scanf("%d%d%d", &h, &w, &nq);
	REP(i, nq) scanf("%d%d", &qx[i], &qy[i]), --qx[i], --qy[i];
	solve();
	REP(i, nq) printf("%s\n", qans[i] ? "YES" : "NO");
}

int main() {
	run();
	return 0;
}