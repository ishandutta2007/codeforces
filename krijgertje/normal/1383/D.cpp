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

const int MAXH = 250;
const int MAXW = 250;
const int MAXN = MAXH*MAXW;

int h, w;
int g[MAXH][MAXW];
int ans[MAXH][MAXW];

int n;
bool isrowmax[MAXN + 1], iscolmax[MAXN + 1];
queue<pair<int, int>> q;

void solve() {
	n = h*w;
	FORE(i, 1, n) isrowmax[i] = iscolmax[i] = false;
	REP(x, h) { int mx = -1; REP(y, w) mx = max(mx, g[x][y]); isrowmax[mx] = true; }
	REP(y, w) { int mx = -1; REP(x, h) mx = max(mx, g[x][y]); iscolmax[mx] = true; }
	int ansh = 0, answ = 0; q = queue<pair<int, int>>();
	REP(x, h) REP(y, w) ans[x][y] = -1;
	for (int i = n; i >= 1; --i) {
		if (isrowmax[i]) ++ansh;
		if (iscolmax[i]) ++answ;
		int x, y;
		if (!isrowmax[i] && !iscolmax[i]) {
			assert(!q.empty());
			tie(x, y) = q.front(); q.pop();
		} else {
			x = ansh - 1, y = answ - 1;
			if (isrowmax[i]) for (int yy = y - 1; yy >= 0; --yy) q.push(MP(x, yy));
			if (iscolmax[i]) for (int xx = x - 1; xx >= 0; --xx) q.push(MP(xx, y));
		}
		ans[x][y] = i;
	}
	assert(ansh == h&&answ == w);
}

void run() {
	scanf("%d%d", &h, &w);
	REP(x, h) REP(y, w) scanf("%d", &g[x][y]);
	solve();
	REP(x, h) { REP(y, w) { if (y != 0) printf(" "); printf("%d", ans[x][y]); } puts(""); }
}

int main() {
	run();
	return 0;
}