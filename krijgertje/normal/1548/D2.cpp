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

const int MAXN = 6000;
struct P { int x, y; };

int n;
P p[MAXN];


ll two(ll x) { return x * (x - 1) / 2; }
ll three(ll x) { return x * (x - 1) * (x - 2) / 6; }

ll calcEEE() {
	vector<vector<int>> cnt2(2, vector<int>(2, 0));
	vector<vector<int>> cnt4(4, vector<int>(4, 0));
	REP(i, n) ++cnt2[p[i].x % 2][p[i].y % 2];
	REP(i, n) ++cnt4[p[i].x % 4][p[i].y % 4];
	ll ret = 0;
	REP(i, 4) REP(j, 4) {
		ret += two(cnt4[i][j]) * (cnt2[i % 2][j % 2] - cnt4[i][j]);
		ret += three(cnt4[i][j]);
	}
	return ret;
}

ll calcOOE() {
	ll ret = 0;
	vector<vector<int>> g(n, vector<int>(n));
	REP(i, n) FOR(j, i + 1, n) g[i][j] = g[j][i] = gcd(abs(p[i].x - p[j].x), abs(p[i].y - p[j].y));
	REP(i, n) {
		int x0 = p[i].x % 4, y0 = p[i].y % 4;
		vector<vector<vector<int>>> cnt(4, vector<vector<int>>(4, vector<int>(4, 0)));
		REP(j, n) if (j != i) ++cnt[g[i][j] % 4][p[j].x % 4][p[j].y % 4];
		for (int b1 = 1; b1 <= 3; b1 += 2) REP(x1, 4) REP(y1, 4) for (int b2 = 1; b2 <= 3; b2 += 2) REP(x2, 4) REP(y2, 4) {
			if (b2 < b1 || b2 == b1 && (x2 < x1 || x2 == x1 && (y2 < y1))) continue; // avoid double counting
			if (cnt[b1][x1][y1] == 0 || cnt[b2][x2][y2] == 0) continue;
			int b3 = x1 == x2 && y1 == y2 ? 0 : (x1 % 2) == (x2 % 2) && (y1 % 2) == (y2 % 2) ? 2 : -1; if (b3 == -1) continue;
			int area = (((x1 - x0) * (y2 - y0) - (y1 - y0) * (x2 - x0)) % 4 + 4) % 4;
			if (area % 2 != 0) continue;
			int boundary = (b1 + b2 + b3) % 4;
			if (area != boundary) continue;
			if (b1 == b2 && x1 == x2 && y1 == y2) {
				ret += two(cnt[b1][x1][y1]);
			} else {
				ret += cnt[b1][x1][y1] * cnt[b2][x2][y2];
			}
		}
	}
	return ret;
}

ll solve() {
	return calcEEE() + calcOOE();
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &p[i].x, &p[i].y);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}