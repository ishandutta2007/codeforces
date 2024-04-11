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

const int MAXN = 100;

int n;
char g[MAXN][MAXN + 1];

int cnt[MAXN][MAXN];
int one[MAXN][MAXN];

int solve() {
	REP(x, n) REP(y, n) cnt[x][y] = one[x][y] = 0;
	REP(x, n) REP(y, n) {
		int xx = x, yy = y;
		int bx = x, by = y;
		REP(k, 4) {
			if (MP(xx, yy) < MP(bx, by)) bx = xx, by = yy;
			int nx = yy, ny = n - xx - 1;
			xx = nx, yy = ny;
		}
		++cnt[bx][by];
		if (g[x][y] == '1') ++one[bx][by];
	}
	int ret = 0;
	REP(x, n) REP(y, n) ret += min(one[x][y], cnt[x][y] - one[x][y]);
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(x, n) scanf("%s", &g[x]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}