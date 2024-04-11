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

const int MAXDIM = 400;

int h, w;
char g[MAXDIM][MAXDIM + 1];

int up[MAXDIM + 1][MAXDIM];

int a[MAXDIM];
int b[MAXDIM];

int solve() {
	REP(y, w) { up[0][y] = 0; REP(x, h) up[x + 1][y] = up[x][y] + (g[x][y] == '1' ? 1 : 0); }

	int ret = INT_MAX;
	REP(lx, h) FOR(hx, lx + 4, h) {
		REP(y, w) {
			a[y] = (hx - lx + 1 - 2) - (up[hx][y] - up[lx + 1][y]);
			b[y] = (up[hx][y] - up[lx + 1][y]) + (g[lx][y] != '1' ? 1 : 0) + (g[hx][y] != '1' ? 1 : 0);
		}
		int best = INT_MAX;
		FOR(y, 3, w) {
			best = min(best, a[y - 3] + b[y - 2]);
			best += b[y - 1];
			ret = min(ret, a[y] + best);
		}
	}
	return ret;
}

void run() {
	scanf("%d%d", &h, &w);
	REP(x, h) scanf("%s", g[x]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}