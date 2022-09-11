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

const int MAXH = 500;
const int MAXW = 500;
const int DX[] = { 0,-1,0,+1 }, DY[] = { -1,0,+1,0 };

int h, w;
char g[MAXH][MAXW + 1];
char ans[MAXH][MAXW + 1];

bool line[MAXH];

void solve() {
	REP(x, h) REPE(y, w) ans[x][y] = g[x][y];
	int offset = h % 3 == 0 ? 1 : 0;
	for (int x = offset; x < h; x += 3) {
		REP(y, w) ans[x][y] = 'X';
		if (x + 2 < h) {
			bool done = false;
			REP(y, w) if (g[x + 1][y] == 'X' || g[x + 2][y] == 'X') { ans[x + 1][y] = ans[x + 2][y] = 'X'; done = true; break; }
			if (!done) ans[x + 1][0] = ans[x + 2][0] = 'X';
		}
	}
}

void run() {
	scanf("%d%d", &h, &w);
	REP(x, h) scanf("%s", g[x]);
	solve();
	REP(x, h) printf("%s\n", ans[x]);

}


int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}