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

const int MAXLEN = 1000000;

int h, w;
char s[MAXLEN + 1]; int slen;

pair<int, int> solve() {
	int lx = 0, x = 0, hx = 0;
	int ly = 0, y = 0, hy = 0;
	REP(i, slen) {
		int dx = s[i] == 'U' ? -1 : s[i] == 'D' ? +1 : 0;
		int dy = s[i] == 'L' ? -1 : s[i] == 'R' ? +1 : 0;
		x += dx, y += dy;
		if (max(hx, x) - min(lx, x) + 1 > h || max(hy, y) - min(ly, y) + 1 > w) {
			x -= dx, y -= dy;
			//printf("stopping after valid %d moves\n", i);
			break;
		}
		lx = min(lx, x);
		hx = max(hx, x);
		ly = min(ly, y);
		hy = max(hy, y);
		//printf("[%d..%d..%d] [%d..%d..%d]\n", lx, x, hx, ly, y, hy);
	}
	return MP(0 - lx, 0 - ly);
}

void run() {
	scanf("%d%d", &h, &w);
	scanf("%s", s); slen = strlen(s);
	pair<int, int> ans = solve();
	printf("%d %d\n", ans.first + 1, ans.second + 1);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}