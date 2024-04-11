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

int n, nday;
int a[MAXN];

int calc(int x) {
	if (n == 1) return nday - 1;
	else if (n == 2) {
		int v = a[1 - x];
		int ret = 0;
		if (v != 0) ret = max(ret, (v - 1) / 2);
		if (v != nday - 1) ret = max(ret, min(v, nday - 1 - v - 1));
		return ret;
	} else {
		int mn = INT_MAX, mx = INT_MIN, last = -1;
		REP(i, n) {
			if (i == x) continue;
			int cur = a[i] - (i == 0 ? -1 : i - 1 != x ? a[i - 1] : i - 1 == 0 ? -1 : a[i - 2]) - 1;
			mn = min(mn, cur);
			mx = max(mx, cur);
			last = a[i];
		}
		int ret = 0;
		//printf("\t%d: mn=%d mx=%d last=%d\n", x, mn, mx, last);
		if (mx >= 1) ret = max(ret, min(mn, (mx - 1) / 2));
		//printf("\t%d\n", ret);
		if (last != nday - 1) ret = max(ret, min(mn, nday - 1 - last - 1));
		//printf("\t%d\n", ret);
		return ret;
	}
}

int solve() {
	int idx = 0, dist = a[0];
	FOR(i, 1, n) {
		int cur = a[i] - a[i - 1] - 1;
		if(cur < dist) dist = cur, idx = i;
	}
	int ret = dist;
	ret = max(ret, calc(idx));
	if (idx - 1 >= 0) ret = max(ret, calc(idx - 1));
	return ret;
}

void run() {
	scanf("%d%d", &n, &nday);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}