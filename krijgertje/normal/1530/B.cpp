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

const int MAXDIM = 20;

int h, w;
char ans[MAXDIM][MAXDIM + 1];

void solve() {
	REP(x, h) REP(y, w) ans[x][y] = '0';
	REP(x, h) ans[x][w] = '\0';
	ans[0][0] = ans[0][w - 1] = ans[h - 1][0] = ans[h - 1][w - 1] = '1';
	REP(x, h) REP(y, w) {
		int cnt = 0; bool onborder = false;
		FORE(dx, -1, +1) FORE(dy, -1, +1) {
			int nx = x + dx, ny = y + dy;
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) { onborder = true; continue; }
			if (ans[nx][ny] == '1') ++cnt;
		}
		if (cnt == 0 && onborder) ans[x][y] = '1';
	}
}

void run() {
	scanf("%d%d", &h, &w);
	solve();
	REP(x, h) printf("%s\n", ans[x]);
	puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}