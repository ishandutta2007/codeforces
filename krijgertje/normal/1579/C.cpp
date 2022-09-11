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

const int MAXH = 10;
const int MAXW = 19;

int h, w, lim;
char g[MAXH][MAXW + 1];

bool marked[MAXH][MAXW];

bool solve() {
	REP(x, h) REP(y, w) marked[x][y] = false;
	REP(x, h) REP(y, w) if (g[x][y] == '*') {
		int l = 1;
		while (x - l >= 0 && y - l >= 0 && g[x - l][y - l] == '*') ++l;
		int r = 1;
		while (x - r >= 0 && y + r < w && g[x - r][y + r] == '*') ++r;
		int sz = min(l, r) - 1;
		if (sz < lim) continue;
		//printf("(%d,%d)=%d\n", x, y, sz);
		REPE(i, sz) marked[x - i][y - i] = marked[x - i][y + i] = true;
	}
	REP(x, h) REP(y, w) if (g[x][y] == '*' && !marked[x][y]) return false;
	return true;
}

void run() {
	scanf("%d%d%d", &h, &w, &lim);
	REP(x, h) scanf("%s", g[x]);
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}