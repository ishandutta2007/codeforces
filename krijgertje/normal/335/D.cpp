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

const int MAXN = 100000;
const int MAXX = 3000;
const int MAXY = 3000;
struct Rect { int lx, ly, hx, hy; };

int n;
Rect rect[MAXN];
vector<int> ans;

int who[MAXX + 1][MAXY + 1];
int area[MAXX + 1][MAXY + 1];
int down[MAXX][MAXY];
int rght[MAXX][MAXY];

bool test(int lx, int ly, int hx, int hy) {
	//printf("testing (%d,%d)-(%d,%d)\n", lx, ly, hx, hy);
	int dx = hx - lx, dy = hy - ly; assert(dx == dy);
	int have = area[hx][hy] - area[lx][hy] - area[hx][ly] + area[lx][ly], want = dx*dy;
	if (have != want) return false;
	if (down[lx][hy - 1] < dx) return false;
	if (rght[hx - 1][ly] < dy) return false;
	ans.clear(); REP(i, n) if (lx <= rect[i].lx&&rect[i].hx <= hx&&ly <= rect[i].ly&&rect[i].hy <= hy) ans.PB(i);
	return true;
}

bool solve() {
	REPE(x, MAXX) REPE(y, MAXY) who[x][y] = -1;
	REP(i, n) FOR(x, rect[i].lx, rect[i].hx) FOR(y, rect[i].ly, rect[i].hy) who[x][y] = i;
	REPE(x, MAXX) REPE(y, MAXY) area[x][y] = (x - 1 >= 0 ? area[x - 1][y] : 0) + (y - 1 >= 0 ? area[x][y - 1] : 0) - (x - 1 >= 0 && y - 1 >= 0 ? area[x - 1][y - 1] : 0) + (x - 1 >= 0 && y - 1 >= 0 && who[x - 1][y - 1] != -1 ? 1 : 0);
	REP(x, MAXX) for (int y = MAXY - 1; y >= 0; --y) rght[x][y] = who[x][y] != -1 && who[x + 1][y] != who[x][y] ? 1 + (y + 1 < MAXY ? rght[x][y + 1] : 0) : 0;
	REP(y, MAXY) for (int x = MAXX - 1; x >= 0; --x) down[x][y] = who[x][y] != -1 && who[x][y + 1] != who[x][y] ? 1 + (x + 1 < MAXX ? down[x + 1][y] : 0) : 0;
	REP(i, n) {
		int lx = rect[i].lx, ly = rect[i].ly, hx = rect[i].hx, hy = rect[i].hy;
		while (true) {
			int dx = hx - lx, dy = hy - ly;
			if (dx == dy && test(lx, ly, hx, hy)) return true;
			int nhx = hx, nhy = hy;
			if (dx <= dy) { int id = who[hx][ly]; if (id == -1) break; if (rect[id].ly != ly) break; assert(rect[id].lx == hx); nhx = rect[id].hx; }
			if (dy <= dx) { int id = who[lx][hy]; if (id == -1) break; if (rect[id].lx != lx) break; assert(rect[id].ly == hy); nhy = rect[id].hy; }
			hx = nhx, hy = nhy;
		}
	}
	return false;
}


void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d%d%d", &rect[i].lx, &rect[i].ly, &rect[i].hx, &rect[i].hy);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES %d\n", SZ(ans));
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}