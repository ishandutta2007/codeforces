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

const int MAXN = 2000;

int n;
char g[MAXN][MAXN + 1];
char ans[MAXN][MAXN + 1];

int pat[MAXN][MAXN];

int solve() {
	if (n % 2 != 0) return 0;

	auto assign = [&](int x, int y, int val) { assert(val != -1 && pat[x][y] == -1 || pat[x][y] == val); pat[x][y] = val; };
	REP(i, n) REP(j, n) pat[i][j] = -1;
	REP(i, n) assign(i, 0, i / 2 * 2);
	REP(i, n) if (i % 2 == 0) for (int j = 1; i - j >= 0; ++j) assign(i - j, j, pat[i][0] ^ (j & 1));
	REP(i, n) if (i % 2 == 1) for (int j = 1; i + j < n; ++j) assign(i + j, j, pat[i][0] ^ (j & 1));
	REP(j, n) if (j % 2 == 0) assign(0, j + 1, pat[0][j]);
	REP(j, n) if (j % 2 == 1) for (int i = 1; i + j < n; ++i) assign(i, i + j, pat[0][j] ^ (i & 1));
	REP(j, n) if (j % 2 == 0) assign(n - 1, j + 1, pat[n - 1][j]);
	REP(j, n) if (j % 2 == 1) for (int i = 1; i + j < n; ++i) assign(n - 1 - i, i + j, pat[n - 1][j] ^ (i & 1));
	//REP(i, n) { REP(j, n) printf("%c", pat[i][j] == -1 ? '-' : (pat[i][j] % 2 == 0 ? 'A' : 'a') + pat[i][j] / 2); puts(""); }

	vector<int> val(n / 2, -1);
	REP(x, n) REP(y, n) if (g[x][y] != '.') {
		int v = g[x][y] == 'G' ? 0 : 1;
		v ^= pat[x][y] & 1;
		int id = pat[x][y] / 2;
		if (val[id] != -1 && val[id] != v) return 0;
		val[id] = v;
	}
	REP(id, n / 2) if (val[id] == -1) return 2;
	REP(x, n) REP(y, n) ans[x][y] = (val[pat[x][y] / 2] ^ (pat[x][y] & 1)) == 0 ? 'G' : 'S';
	REP(x, n) ans[x][n] = '\0';
	return 1;
}

void run() {
	scanf("%d", &n);
	REP(x, n) scanf("%s", g[x]);
	int ways = solve();
	printf("%s\n", ways == 0 ? "NONE" : ways == 1 ? "UNIQUE" : "MULTIPLE");
	if (ways == 1) REP(x, n) printf("%s\n", ans[x]);
}

int main() {
	run();
	return 0;
}