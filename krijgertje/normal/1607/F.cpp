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

const int MAXDIM = 2000;
const int MAXN = MAXDIM * MAXDIM;

int h, w;
char g[MAXDIM][MAXDIM + 1];
int ansx, ansy, anssteps;

int n;
int nxt[MAXN];

int state[MAXN];
int res[MAXN];

void solve() {
	n = h * w;
	REP(x, h) REP(y, w) {
		int at = x * w + y;
		int to = at;
		if (g[x][y] == 'U') { if (x == 0) to = -1; else to -= w; }
		if (g[x][y] == 'D') { if (x == h - 1) to = -1; else to += w; }
		if (g[x][y] == 'L') { if (y == 0) to = -1; else --to; }
		if (g[x][y] == 'R') { if (y == w - 1) to = -1; else ++to; }
		nxt[at] = to;
	}

	REP(i, n) state[i] = 0;
	REP(i, n) res[i] = -1;
	REP(i, n) if (state[i] == 0) {
		int at = i, pathsteps = 0;
		while (at != -1 && state[at] == 0) {
			state[at] = 1;
			at = nxt[at];
			++pathsteps;
		}
		if (state[at] == 2) pathsteps += res[at];
		if (at != -1 && state[at] == 1) {
			int cycsteps = 0;
			while (state[at] == 1) {
				state[at] = 2;
				at = nxt[at];
				++cycsteps;
			}
			while (res[at] == -1) {
				res[at] = cycsteps;
				at = nxt[at];
			}
		}
		at = i;
		while (at != -1 && state[at] == 1) {
			state[at] = 2;
			res[at] = pathsteps;
			at = nxt[at];
			--pathsteps;
		}
	}
	//REP(x, h) { REP(y, w) printf("%3d", res[x * w + y]); puts(""); }
	
	anssteps = -1;
	REP(x, h) REP(y, w) {
		int cur = res[x * w + y];
		if (cur > anssteps) anssteps = cur, ansx = x, ansy = y;
	}
}

void run() {
	scanf("%d%d", &h, &w);
	REP(x, h) scanf("%s", g[x]);
	solve();
	printf("%d %d %d\n", ansx + 1, ansy + 1, anssteps);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}