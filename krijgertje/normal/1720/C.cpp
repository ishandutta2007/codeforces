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

const int MAXDIM = 500;

int h, w;
char g[MAXDIM][MAXDIM + 1];

int solve() {
	int cnt = 0;
	REP(x, h) REP(y, w) if (g[x][y] == '1') ++cnt;
	if (cnt == h * w) return cnt - 2;
	REP(x, h) REP(y, w - 1) if (g[x][y] == '0' && g[x][y + 1] == '0') return cnt;
	REP(x, h - 1) REP(y, w) if (g[x][y] == '0' && g[x + 1][y] == '0') return cnt;
	REP(x, h - 1) REP(y, w - 1) if (g[x][y] == '0' && g[x + 1][y + 1] == '0' || g[x + 1][y] == '0' && g[x][y + 1] == '0') return cnt;
	return cnt - 1;
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