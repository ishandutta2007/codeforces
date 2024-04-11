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

const int MAXDIM = 50;

int h, w;
char g[MAXDIM][MAXDIM + 1];
char ans[MAXDIM][MAXDIM + 1];

bool solve() {
	int redmask = 0, whitemask = 0;
	REP(x, h) REP(y, w) {
		if (g[x][y] == 'R') redmask |= 1 << ((x + y) % 2);
		if (g[x][y] == 'W') whitemask |= 1 << ((x + y) % 2);
	}
	if (redmask == 3 || whitemask == 3 || (redmask & whitemask) != 0) return false;
	if (redmask == 0 && whitemask != 0) redmask = 3 ^ whitemask;
	if (whitemask == 0 && redmask != 0) whitemask = 3 ^ redmask;
	if (redmask == 0 && whitemask == 0) redmask = 1, whitemask = 2;
	REP(x, h) REPE(y, w) ans[x][y] = g[x][y];
	REP(x, h) REP(y, w) if (ans[x][y] == '.') {
		if ((x + y) % 2 == 0) ans[x][y] = redmask & 1 ? 'R' : 'W';
		if ((x + y) % 2 == 1) ans[x][y] = redmask & 2 ? 'R' : 'W';
	}
	return true;
}

void run() {
	scanf("%d%d", &h, &w);
	REP(x, h) scanf("%s", g[x]);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(x, h) printf("%s\n", ans[x]);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}