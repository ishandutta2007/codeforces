#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXH = 300;
const int MAXW = 300;
struct Move { int x1, y1, x2, y2; Move() {} Move(int x1, int y1, int x2, int y2) :x1(x1), y1(y1), x2(x2), y2(y2) {} };

int h, w;
string a[MAXH][MAXW];
string b[MAXH][MAXW];
string g[MAXH][MAXW];

vector<Move> ans;

int cnt[2][MAXW];

void solveonedir() {
	ans.clear();
	REP(x, 2) REP(y, w) cnt[x][y] = 0;
	REP(x, h) REP(y, w) for (int i = SZ(g[x][y]) - 1; i >= 0; --i) {
		char c = g[x][y][i];
		int nx = c == '0' ? 0 : 1, ny = x != nx ? y : (y + 1) % w;
		ans.PB(Move(x, y, nx, ny));
		++cnt[nx][ny];
	}
	REP(x, 2) FOR(y, 1, w) while (cnt[x][y] > 0) { int nx = x, ny = 0; ans.PB(Move(x, y, nx, ny)); --cnt[x][y], ++cnt[nx][ny]; }
}

void verify() {
	REP(x, h) REP(y, w) g[x][y] = a[x][y];
	REPSZ(i, ans) {
		int sx = ans[i].x1, sy = ans[i].y1, tx = ans[i].x2, ty = ans[i].y2;
		assert(sx != tx || sy != ty); assert(sx >= 0 && sx < h); assert(sy >= 0 && sy < w); assert(tx >= 0 && tx < h); assert(ty >= 0 && ty < w);
		assert(sx == tx || sy == ty);
		assert(SZ(g[sx][sy]) != 0);
		char c = g[sx][sy].back(); g[sx][sy].pop_back(); g[tx][ty] = string(1, c) + g[tx][ty];
		//REP(x, h) { REP(y, w) { if (y != 0) printf(" "); printf("%s", g[x][y].c_str()); } puts(""); } puts("");
	}
	REP(x, h) REP(y, w) assert(g[x][y] == b[x][y]);
	int sumlen = 0; REP(x, h) REP(y, w) sumlen += SZ(a[x][y]); assert(SZ(ans) <= 4 * sumlen);
}

void solve() {
	REP(x, h) REP(y, w) g[x][y] = a[x][y];
	solveonedir();
	vector<Move> ans1 = ans;
	REP(x, h) REP(y, w) { g[x][y] = b[x][y]; reverse(g[x][y].begin(), g[x][y].end()); }
	solveonedir();
	vector<Move> ans2 = ans; REPSZ(i, ans2) { swap(ans2[i].x1, ans2[i].x2); swap(ans2[i].y1, ans2[i].y2); } reverse(ans2.begin(), ans2.end());
	ans.clear(); REPSZ(i, ans1) ans.PB(ans1[i]); REPSZ(i, ans2) ans.PB(ans2[i]);
}

void run() {
	cin >> h >> w;
	REP(x, h) REP(y, w) cin >> a[x][y];
	REP(x, h) REP(y, w) cin >> b[x][y];
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%d %d %d %d\n", ans[i].x1 + 1, ans[i].y1 + 1, ans[i].x2 + 1, ans[i].y2 + 1);
}

void stress() {
	REP(rep, 1000) {
		h = 2 + rand() % 4, w = 2 + rand() % 4; int nzero = rand() % 100, none = rand() % 100;
		REP(x, h) REP(y, w) a[x][y] = b[x][y] = "";
		{ int remzero = nzero, remone = none; while (remzero + remone > 0) { char c = rand() % (remzero + remone) < remzero ? '0' : '1'; int x = rand() % h, y = rand() % w; a[x][y] += c; if (c == '0') --remzero; else --remone; } }
		{ int remzero = nzero, remone = none; while (remzero + remone > 0) { char c = rand() % (remzero + remone) < remzero ? '0' : '1'; int x = rand() % h, y = rand() % w; b[x][y] += c; if (c == '0') --remzero; else --remone; } }
		solve();
		verify();
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}