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

const int MAXN = 2000;

int n, lim;
int a[MAXN][MAXN];
char ans[MAXN][MAXN + 1];

pair<int, int> pos[MAXN * MAXN];

void solve() {
	REP(i, n) REP(j, n) ans[i][j] = '?';
	REP(i, n) ans[i][n] = '\0';
	REP(i, n) REP(j, n) pos[a[i][j]] = MP(i, j);
	int lu = -(n - 1), hu = +(n - 1);
	int lv = 0, hv = 2 * (n - 1);

	auto relax = [&](int u, int v) { if ((u + v) % 2 != 0) return; int x = (v - u) / 2, y = (u + v) / 2; if (x < 0 || x >= n || y < 0 || y >= n) return; if (ans[x][y] != '?') return; ans[x][y] = 'G'; };
	for (int i = n * n - 1; i >= 0; --i) {
		int x = pos[i].first, y = pos[i].second;
		if (ans[x][y] != '?') continue;
		ans[x][y] = 'M';
		int u = y - x, v = x + y;
		assert(lu <= u && u <= hu && lv <= v && v <= hv);
		int nlu = max(lu, u - lim), nhu = min(hu, u + lim);
		int nlv = max(lv, v - lim), nhv = min(hv, v + lim);

		if (lv <= hv) FORE(cu, lu, nlu - 1) FORE(cv, lv, hv) relax(cu, cv);
		if (lv <= hv) FORE(cu, nhu + 1, hu) FORE(cv, lv, hv) relax(cu, cv);
		if (lv <= nlv - 1) FORE(cu, nlu, nhu) FORE(cv, lv, nlv - 1) relax(cu, cv);
		if (nhv + 1 <= hv) FORE(cu, nlu, nhu) FORE(cv, nhv + 1, hv) relax(cu, cv);
		lu = nlu, hu = nhu, lv = nlv, hv = nhv;
	}
}

void run() {
	scanf("%d%d", &n, &lim);
	REP(i, n) REP(j, n) scanf("%d", &a[i][j]), --a[i][j];
	solve();
	REP(i, n) printf("%s\n", ans[i]);
}

int main() {
	run();
	return 0;
}