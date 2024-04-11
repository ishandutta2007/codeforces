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

int h, w;
vector<vector<int>> g;
vector<int> ans; int ansleft; // R=0, B=1

vector<vector<pair<int, int>>> byside;
vector<int> side; // L=0, R=1
vector<int> l, r;

bool solve() {
	int firstred = 0; REP(x, h) if (g[x][0] > g[firstred][0]) firstred = x;
	int firstblue = 0; REP(x, h) if (g[x][0] < g[firstblue][0]) firstblue = x;
	if (g[firstred][0] <= g[firstblue][0]) return false;

	ans = vector<int>(h, -1);
	ans[firstred] = 0, ans[firstblue] = 1;
	side = vector<int>(w);
	side[0] = 0;
	REP(y, w) {
		int r = g[firstred][y], b = g[firstblue][y];
		if (r == b) return false;
		side[y] = r > b ? 0 : 1;
	}
	if (side[w - 1] != 1) return false;
	FOR(i, 1, w) if (side[i - 1] > side[i]) return false;
	
	byside = vector<vector<pair<int, int>>>(2, vector<pair<int, int>>());
	REP(x, h) REP(y, w) byside[side[y]].PB(MP(g[x][y], x));
	REP(z, 2) sort(byside[z].begin(), byside[z].end());

	l = vector<int>(2, -1), r = vector<int>(2); REP(z, 2) r[z] = SZ(byside[z]);
	queue<int> q;
	auto updatel = [&](int y, int v) {
		int z = side[y];
		if (r[z] != SZ(byside[z]) && v >= byside[z][r[z]].first) return false;
		while (l[z] + 1 < SZ(byside[z]) && byside[z][l[z] + 1].first <= v) {
			++l[z];
			int x = byside[z][l[z]].second;
			if (ans[x] == -1) {
				ans[x] = z == 0 ? 1 : 0;
				q.push(x);
			}
		}
		return true;
	};
	auto updater = [&](int y, int v) {
		int z = side[y];
		if (l[z] != -1 && v <= byside[z][l[z]].first) return false;
		while (r[z] - 1 >= 0 && byside[z][r[z] - 1].first >= v) {
			--r[z];
			int x = byside[z][r[z]].second;
			if (ans[x] == -1) {
				ans[x] = z == 0 ? 0 : 1;
				q.push(x);
			}
		}
		return true;
	};
	REP(y, w) if (!updatel(y, side[y] == 0 ? g[firstblue][y] : g[firstred][y])) return false;
	REP(y, w) if (!updater(y, side[y] == 1 ? g[firstblue][y] : g[firstred][y])) return false;
	REP(z, 2) assert(l[z] >= 0 && r[z] < SZ(byside[z]) && l[z] < r[z]);

	while (!q.empty()) {
		int x = q.front(); q.pop();
		REP(y, w) {
			int z = side[y];
			if (side[y] == ans[x]) {
				//printf("(%d,%d) -> updater (%d..%d) with %d\n", x, y, byside[z][l[z]].first, byside[z][r[z]].first, g[x][y]);
				if (!updater(y, g[x][y])) return false;
			} else {
				//printf("(%d,%d) -> updatel (%d..%d) with %d\n", x, y, byside[z][l[z]].first, byside[z][r[z]].first, g[x][y]);
				if (!updatel(y, g[x][y])) return false;
			}
		}
	}

	REP(x, h) if (ans[x] == -1) ans[x] = 0;
	ansleft = 0; REP(y, w) if (side[y] == 0) ++ansleft;
	return true;
}

void run() {
	scanf("%d%d", &h, &w);
	g = vector<vector<int>>(h, vector<int>(w));
	REP(x, h) REP(y, w) scanf("%d", &g[x][y]);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REPSZ(i, ans) printf("%c", "?RB"[ans[i] + 1]); printf(" %d\n", ansleft);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}