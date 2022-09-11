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

int wroom, hroom;
int lx, ly, hx, hy;
int wtable, htable;

double solve() {
	if (htable > hroom, wtable > wroom) return -1;
	vector<pair<int, int>> opt;
	opt.PB(MP(0, 0));
	opt.PB(MP(0, wroom - wtable));
	opt.PB(MP(hroom-htable, 0));
	opt.PB(MP(hroom - htable, wroom - wtable));
	int ret = INT_MAX;
	for (auto o : opt) {
		int x = o.first, y = o.second;
		int cur = INT_MAX;
		if (hx <= x) cur = min(cur, 0); else if (hx - lx <= x) cur = min(cur, hx - x);
		if (hy <= y) cur = min(cur, 0); else if (hy - ly <= y) cur = min(cur, hy - y);
		if (lx >= x + htable) cur = min(cur, 0); else if (hx - lx <= hroom - x - htable) cur = min(cur, x + htable - lx);
		if (ly >= y + wtable) cur = min(cur, 0); else if (hy - ly <= wroom - y - wtable) cur = min(cur, y + wtable - ly);
		//printf("(%d,%d)->%d\n", x, y, cur);
		ret = min(ret, cur);
	}
	return ret == INT_MAX ? -1 : ret;
}

void run() {
	scanf("%d%d", &hroom, &wroom);
	scanf("%d%d%d%d", &lx, &ly, &hx, &hy);
	scanf("%d%d", &htable, &wtable);
	double ans = solve();
	if (ans < -0.5) printf("-1\n"); else printf("%.15lf\n", ans);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}