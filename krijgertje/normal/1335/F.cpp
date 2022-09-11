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

const int MAXN = 1000000;

int h, w, n;
char col[MAXN + 1];
char dir[MAXN + 1];

int nxt[MAXN];
int state[MAXN];
int cycid[MAXN], cycoffset[MAXN];
vector<int> cyc[MAXN]; int ncyc;

pair<int, int> solve() {
	//printf("%s\n", col);
	//printf("%s\n", dir);
	REP(i, n) {
		if (dir[i] == 'U') { assert(i >= w); nxt[i] = i - w; }
		else if (dir[i] == 'D') { assert(i + w < n); nxt[i] = i + w; }
		else if (dir[i] == 'L') { assert(i % w - 1 >= 0); nxt[i] = i - 1; }
		else if (dir[i] == 'R') { assert(i % w + 1 < w); nxt[i] = i + 1; }
		else assert(false);
	}

	ncyc = 0;
	REP(i, n) state[i] = 0;
	REP(i, n) if (state[i] == 0) {
		int at = i, stepstocyc = 0;
		while (state[at] == 0) { state[at] = 1; at = nxt[at]; ++stepstocyc; }
		if (state[at] == 1) {
			int id = ncyc++;
			while (state[at] == 1) { state[at] = 2; cycid[at] = id, cycoffset[at] = SZ(cyc[id]); cyc[id].PB(col[at] == '0' ? 1 : 0); at = nxt[at]; }
			stepstocyc -= SZ(cyc[id]);
		}
		int id = cycid[at], mod = SZ(cyc[id]), cur = (cycoffset[at] + mod - stepstocyc % mod) % mod;
		at = i;
		while (state[at] == 1) { state[at] = 2; cycid[at] = id, cycoffset[at] = cur; if (col[at] == '0') cyc[id][cur] = 1; cur = cur == SZ(cyc[id]) - 1 ? 0 : cur + 1; at = nxt[at]; }
	}
	pair<int, int> ret = MP(0, 0);
	REP(i, ncyc) REPSZ(j, cyc[i]) ++ret.first, ret.second += cyc[i][j];
	REP(i, ncyc) cyc[i].clear();
	return ret;
}

void run() {
	scanf("%d%d", &h, &w); n = h * w;
	REP(x, h) scanf("%s", col + x * w);
	REP(x, h) scanf("%s", dir + x * w);
	pair<int, int> ans = solve();
	printf("%d %d\n", ans.first, ans.second);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}