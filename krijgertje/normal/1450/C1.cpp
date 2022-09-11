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

const int MAXN = 300;

int n;
char g[MAXN][MAXN + 1];
char ans[MAXN][MAXN + 1];


int xcnt[3], ocnt[3];

void solve() {
	REP(i, 3) xcnt[i] = ocnt[i] = 0;
	REP(x, n) REP(y, n) if (g[x][y] == 'X') ++xcnt[(x + y) % 3]; else if (g[x][y] == 'O') ++ocnt[(x + y) % 3];
	int killx = -1; REP(i, 3) if (killx == -1 || xcnt[i] < xcnt[killx]) killx = i;
	int killo = -1; REP(i, 3) if (i != killx && (killo == -1 || ocnt[i] < ocnt[killo])) killo = i;

	REP(x, n) REPE(y, n) ans[x][y] = g[x][y];
	REP(x, n) REP(y, n) {
		if ((x + y) % 3 == killx && g[x][y] == 'X') ans[x][y] = 'O';
		if ((x + y) % 3 == killo && g[x][y] == 'O') ans[x][y] = 'X';
	}
}

void run() {
	scanf("%d", &n);
	REP(x, n) scanf("%s", g[x]);
	solve();
	REP(x, n) printf("%s\n", ans[x]);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}