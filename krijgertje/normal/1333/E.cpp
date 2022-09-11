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

const int MAXN = 500;

int n;
int ans[MAXN][MAXN];

bool solve() {
	if (n <= 2) return false;
	int at = 0, x = 0, y = n;
	REP(x, n) REP(y, n) ans[x][y] = -1;
	while (at < n * n - 3 * 3) {
		if (x == 0) {
			--y;
			while (x < y) ans[x][y] = at++, ++x;
			while (y > 0) ans[x][y] = at++, --y;
			ans[x][y] = at++;
		} else if (y == 0) {
			--x;
			while (y < x) ans[x][y] = at++, ++y;
			while (x > 0) ans[x][y] = at++, --x;
			ans[x][y] = at++;
		} else {
			assert(false);
		}
	}
	if (x == 0) {
		ans[0][2] = at++, ans[0][1] = at++, ans[1][1] = at++, ans[1][0] = at++, ans[0][0] = at++, ans[2][1] = at++, ans[2][2] = at++, ans[2][0] = at++, ans[1][2] = at++;
	} else {
		ans[2][0] = at++, ans[1][0] = at++, ans[1][1] = at++, ans[0][1] = at++, ans[0][0] = at++, ans[1][2] = at++, ans[2][2] = at++, ans[0][2] = at++, ans[2][1] = at++;
	}
	return true;
}

void run() {
	scanf("%d", &n);
	if (!solve()) { printf("-1\n"); return; }
	REP(i, n) { REP(j, n) { if (j != 0) printf(" "); printf("%d", ans[i][j] + 1); } puts(""); }
}

int main() {
	run();
	return 0;
}