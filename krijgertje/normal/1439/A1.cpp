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
#include <array>
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

const int MAXH = 100;
const int MAXW = 100;
struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };

int h, w;
char g[MAXH][MAXW + 1];
vector<vector<P>> ans;

void apply(vector<P> op) {
	REPSZ(i, op) { int x = op[i].x, y = op[i].y; g[x][y] ^= 1; }
}

void solve() {
	ans.clear();
	REP(x, h - 1) {
		REP(y, w - 2) {
			vector<P> cur;
			if (g[x][y] == '1') cur.PB(P(x, y));
			if (g[x + 1][y] == '1') cur.PB(P(x + 1, y));
			if (SZ(cur) == 0) continue;
			if (SZ(cur) < 3) cur.PB(P(x, y + 1));
			if (SZ(cur) < 3) cur.PB(P(x + 1, y + 1));
			assert(SZ(cur) == 3);
			ans.PB(cur);
			apply(cur);
		}
		while (true) {
			int cnt = 0;
			REP(dx, 2) REP(dy, 2) { int cx = x + dx, y = w - 2 + dy; if (g[cx][y] == '1') ++cnt; }
			if (cnt == 0) break;
			int ones = cnt <= 2 ? 1 : 3;
			vector<P> cur;
			REP(dx, 2) REP(dy, 2) { int cx = x + dx, y = w - 2 + dy; if (g[cx][y] == '1' && SZ(cur) < ones) cur.PB(P(cx, y)); }
			assert(SZ(cur) == ones);
			REP(dx, 2) REP(dy, 2) { int cx = x + dx, y = w - 2 + dy; if (g[cx][y] == '0' && SZ(cur) < 3) cur.PB(P(cx, y)); }
			assert(SZ(cur) == 3);
			ans.PB(cur);
			apply(cur);
		}
		//printf("after %d:\n", x); REP(x, h) printf("%s\n", g[x]);
	}
	REP(x, h) REP(y, w) assert(g[x][y] == '0');
}

void run() {
	scanf("%d%d", &h, &w);
	REP(x, h) scanf("%s", g[x]);
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { REP(j, 3) { if (j != 0) printf(" "); printf("%d %d", ans[i][j].x + 1, ans[i][j].y + 1); } puts(""); }
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}