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
vector<string> g;

int solve() {
	vector<vector<int>> cnt(h, vector<int>(w, 0));
	int ret = 0;
	REP(d, w + h - 1) {
		bool need = false;
		for (int x = min(d, h - 1); x >= max(d - w + 1, 0); --x) {
			int y = d - x;
			assert(y >= 0 && y < w);
			if (g[x][y] == '1' && !need) {
				need = true;
				if (x + 1 < h && y + 1 < w) ++cnt[x + 1][y + 1]; else if (x + 2 < h) { assert(y - 1 >= 0); ++cnt[x + 2][y]; }
			}
			if (cnt[x][y] > 0 && need) {
				need = false;
				--cnt[x][y];
			}
			if (cnt[x][y] > 0) {
				if (x + 1 < h && y + 1 < w) cnt[x + 1][y + 1] += cnt[x][y]; else if (x + 2 < h) { assert(y - 1 >= 0); cnt[x + 2][y] += cnt[x][y]; }
				cnt[x][y] = 0;
			}
		}
		if (need) ++ret;
		//printf("after %d: (ret=%d)\n", d, ret);
		//REP(x, h) { REP(y, w) printf("%3d", cnt[x][y]); puts(""); }
	}
	return ret;
}

void run() {
	scanf("%d%d", &h, &w);
	g = vector<string>(h); REP(x, h) cin >> g[x];
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}