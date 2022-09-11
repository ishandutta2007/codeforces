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

int h, w;
vector<vector<int>> g;
vector<int> ans;

bool solve(int xx, int ya, int yb,const vector<int> &ndiff) {
	vector<pair<int, int>> one;
	vector<pair<int, int>> two;
	REP(x, h) if (x != xx) {
		int cur = ndiff[x];
		if (g[x][ya] != g[xx][ya]) --cur;
		if (g[x][yb] != g[xx][yb]) --cur;
		if (cur > 2) return false;
		if (cur == 0) continue;
		if (cur == 1) one.PB(MP(g[x][ya], g[x][yb]));
		if (cur == 2) two.PB(MP(g[x][ya], g[x][yb]));
	}
	if (SZ(two) >= 1) {
		int va = two[0].first, vb = two[0].second;
		for (auto p : one) if (p.first != va && p.second != vb) return false;
		for (auto p : two) if (p.first != va || p.second != vb) return false;
		ans = g[xx]; ans[ya] = va, ans[yb] = vb; return true;
	}
	if (SZ(one) == 0) {
		ans = g[xx]; return true;
	} else {
		int va = one[0].first, vb = one[0].second;
		FORSZ(i, 1, one) {
			if (one[i].first == va && one[i].second == vb) continue;
			if (one[i].first == va) { vb = -1; break; }
			if (one[i].second == vb) { va = -1; break; }
			int wa = one[i].first, wb = one[i].second;
			bool ab = true, ba = true;
			FORSZ(j, i + 1, one) {
				if (one[j].first != va && one[j].second != wb) ab = false;
				if (one[j].first != wa && one[j].second != vb) ba = false;
			}
			if (ab) { ans = g[xx]; ans[ya] = va, ans[yb] = wb; return true; }
			if (ba) { ans = g[xx]; ans[ya] = wa, ans[yb] = vb; return true; }
			return false;
		}
		REPSZ(i, one) {
			if (one[i].first == va || one[i].second == vb) continue;
			if (va == -1) va = one[i].first;
			if (vb == -1) vb = one[i].second;
			if (one[i].first == va || one[i].second == vb) continue;
			return false;
		}
		ans = g[xx]; if (va != -1) ans[ya] = va; if (vb != -1) ans[yb] = vb; return true;
	}
}

bool solve(int xx, int ya) {
	vector<int> ndiff(h, 0);
	REP(x, h) REP(y, w) if (g[x][y] != g[xx][y]) ++ndiff[x];
	REP(yb, w) if (yb != ya) if (solve(xx, ya, yb, ndiff)) return true;
	return false;
}

bool solve() {
	if (w == 1) {
		ans = g[0];
		return true;
	}
	REP(x, h - 1) REP(y, w) if (g[x][y] != g[x + 1][y]) {
		if (solve(x, y)) return true;
		if (solve(x + 1, y)) return true;
		return false;
	}
	ans = g[0];
	return true;
}

void run() {
	scanf("%d%d", &h, &w);
	g = vector<vector<int>>(h, vector<int>(w));
	REP(x, h) REP(y, w) scanf("%d", &g[x][y]);
	if (!solve()) { printf("No\n"); return; }
	printf("Yes\n");
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}