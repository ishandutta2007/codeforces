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

const int MAXN = 200000;

int n;
int a[2][MAXN];

bool can(int t,int side) {
	if (t < 2 * n - 1) return false;
	int now = t - (2 * n - 1);
	int x = 0, y = 0;
	if (side == 1) {
		if (a[1 - x][y] > now) return false;
		x = 1 - x, ++now;
		if (a[x][y + 1] > now) return false;
		++y, ++now;
	}
	while (y + 2 < n && a[1 - x][y] <= now && a[1 - x][y + 1] <= now + 1 && a[x][y + 1] <= now + 2 && a[x][y + 2] <= now + 3) {
		y += 2, now += 4;
	}
	int ty = y;
	while (y + 1 < n) {
		if (a[x][y + 1] > now) return false;
		++y, ++now;
	}
	if (a[1 - x][y] > now) return false;
	x = 1 - x, ++now;
	while (y - 1 >= ty) {
		if (a[x][y - 1] > now) return false;
		--y, ++now;
	}
	//printf("\tok(%d,%d) ty=%d\n", t, side, ty);
	return true;
}

int solve() {
	int mx = 0; REP(x, 2) REP(y, n) mx = max(mx, a[x][y]);
	int lo = -1, hi = mx + 2 * n - 1;
	while (lo + 1 < hi) {
		int mi = lo + (hi - lo) / 2;
		if (can(mi, 0) || can(mi, 1)) hi = mi; else lo = mi;
	}
	return hi;
}

void run() {
	scanf("%d", &n);
	REP(x, 2) REP(y, n) scanf("%d", &a[x][y]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}