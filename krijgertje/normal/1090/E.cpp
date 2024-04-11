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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXH = 8;
const int MAXW = 8;
const int DX[] = { -2,-2,-1,-1,+1,+1,+2,+2 }, DY[] = { -1,+1,-2,+2,-2,+2,-1,+1 };
struct Move { int sx, sy, tx, ty; Move() {} Move(int sx, int sy, int tx, int ty) :sx(sx), sy(sy), tx(tx), ty(ty) {} };

int h = MAXH, w = MAXW;
int nknight;
bool haveknight[MAXH][MAXW];

bool wantknight[MAXH][MAXW];
bool have[MAXH][MAXW];
bool want[MAXH][MAXW];
bool valid[MAXH][MAXW];

pair<int, int> q[MAXH*MAXW]; int qhead, qtail;
int d[MAXH][MAXW];
pair<int, int> nxt[MAXH][MAXW];

vector<Move> ans;


void domove(int sx, int sy, int tx, int ty) {
	int x = sx, y = sy;
	while (x != tx || y != ty) {
		assert(have[x][y]);
		int nx = nxt[x][y].first, ny = nxt[x][y].second;
		ans.PB(Move(x, y, nx, ny)); have[x][y] = false, have[nx][ny] = true, x = nx, y = ny;
	}
}

void moveto(int tx, int ty) {
	qhead = qtail = 0; REP(x, h) REP(y, w) d[x][y] = INT_MAX;
	d[tx][ty] = 0; q[qhead++] = MP(tx, ty);
	while (qtail < qhead) {
		int x = q[qtail].first, y = q[qtail].second; ++qtail;
		if (have[x][y]) { domove(x, y, tx, ty); return; }
		REP(k, 8) {
			int nx = x + DX[k], ny = y + DY[k]; if (nx < 0 || nx >= h || ny < 0 || ny >= w || !valid[nx][ny] || d[nx][ny] != INT_MAX) continue;
			d[nx][ny] = d[x][y] + 1, nxt[nx][ny] = MP(x, y), q[qhead++] = MP(nx, ny);
		}
	}
	printf("chave: (%d,%d)\n",h,w); REP(x, h) { REP(y, w) printf("%c", !valid[x][y] ? '-' : x == tx && y == ty ? 'T' : have[x][y] ? 'x' : '.'); puts(""); }
	assert(false);
}

void solve() {
	//printf("haveknight:\n"); REP(x, h) { REP(y, w) printf("%c", haveknight[x][y] ? 'x' : '.'); puts(""); }
	REP(x, h) REP(y, w) wantknight[x][y] = y*MAXH + x < nknight;
	//printf("wantknight:\n"); REP(x, h) { REP(y, w) printf("%c", wantknight[x][y] ? 'x' : '.'); puts(""); }
	bool flip = 2 * nknight > MAXH*MAXW;
	if (!flip) REP(x, h) REP(y, w) have[x][y] = haveknight[x][y], want[x][y] = wantknight[x][y];
	else REP(x, h) REP(y, w) have[x][y] = !haveknight[h - x - 1][w - y - 1], want[x][y] = !wantknight[h - x - 1][w - y - 1];
	//printf("have:\n"); REP(x, h) { REP(y, w) printf("%c", have[x][y] ? 'x' : '.'); puts(""); }
	//printf("want:\n"); REP(x, h) { REP(y, w) printf("%c", want[x][y] ? 'x' : '.'); puts(""); }

	ans.clear();
	REP(x, h) REP(y, w) valid[x][y] = true;
	REP(y, w) REP(x, h) if (want[x][y]) {
		moveto(x, y);
		assert(have[x][y]);
		valid[x][y] = false;
	}
	//printf("nhave:\n"); REP(x, h) { REP(y, w) printf("%c", have[x][y] ? 'x' : '.'); puts(""); }

	if (flip) {
		REPSZ(i, ans) swap(ans[i].sx, ans[i].tx), swap(ans[i].sy, ans[i].ty);
		REPSZ(i, ans) ans[i].sx = h - ans[i].sx - 1, ans[i].sy = w - ans[i].sy - 1;
		REPSZ(i, ans) ans[i].tx = h - ans[i].tx - 1, ans[i].ty = w - ans[i].ty - 1;
	}
}

void verify() {
	REP(x, h) REP(y, w) have[x][y] = haveknight[x][y];
	REPSZ(i, ans) { 
		int sx = ans[i].sx, sy = ans[i].sy, tx = ans[i].tx, ty = ans[i].ty; 
		assert(sx >= 0 && sx < h&&sy >= 0 && sy < w);
		assert(tx >= 0 && tx < h&&ty >= 0 && ty < w);
		assert(abs(sx - tx)*abs(sx - tx) + abs(sy - ty)*abs(sy - ty) == 5);
		assert(have[sx][sy]); have[sx][sy] = false; assert(!have[tx][ty]); have[tx][ty] = true; 
	}
	REP(x, h) REP(y, w) assert(have[x][y] == wantknight[x][y]);
}

void run() {
	scanf("%d", &nknight);
	REP(x, h) REP(y, w) haveknight[x][y] = false;
	REP(i, nknight) { char x; int y; scanf(" %c%d", &x, &y); haveknight[x - 'a'][y - 1] = true; }
	solve();
	verify();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%c%d-%c%d\n", 'a' + ans[i].sx, ans[i].sy + 1, 'a' + ans[i].tx, ans[i].ty + 1);
}


int main() {
	run();
	return 0;
}