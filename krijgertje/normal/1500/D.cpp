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

const int MAXN = 1500;
const int MAXLIM = 10;

int n, lim;
int a[MAXN][MAXN];
int ans[MAXN + 1];

vector<pair<int, int>> dp[MAXN][MAXN]; // dp[i][j] = ordered list of colors that appear in square with top-left at (i,j) (each item of the first (sz,col))
int mx[MAXN][MAXN]; // mx[i][j] = maximum size

bool seen[MAXN * MAXN];

void solve() {
	REP(i, n * n) seen[i] = false;
	for (int i = n - 1; i >= 0; --i) for (int j = n - 1; j >= 0; --j) {
		vector<pair<int, int>> cur;
		cur.PB(MP(1, a[i][j]));
		if (i + 1 < n) for (auto p : dp[i + 1][j]) cur.PB(MP(p.first + 1, p.second));
		if (j + 1 < n) for (auto p : dp[i][j + 1]) cur.PB(MP(p.first + 1, p.second));
		if (i + 1 < n && j + 1 < n) for (auto p : dp[i + 1][j + 1]) cur.PB(MP(p.first + 1, p.second));
		sort(cur.begin(), cur.end());
		//printf("[%d,%d] cur:", i, j); for (auto p : cur) printf(" (%d,%d)", p.first, p.second + 1); puts("");
		int ncur = 0;
		mx[i][j] = min(n - i, n - j);
		if (i + 1 < n) mx[i][j] = min(mx[i][j], mx[i + 1][j] + 1);
		if (j + 1 < n) mx[i][j] = min(mx[i][j], mx[i][j + 1] + 1);
		if (i + 1 < n && j + 1 < n) mx[i][j] = min(mx[i][j], mx[i + 1][j + 1] + 1);
		REPSZ(k, cur) if (cur[k].first <= mx[i][j] && !seen[cur[k].second]) seen[cur[k].second] = true, cur[ncur++] = cur[k];
		REPSZ(k, cur) seen[cur[k].second] = false;
		cur.resize(ncur);
		while (SZ(cur) > lim) {
			int x = cur.back().first;
			mx[i][j] = x - 1;
			while (SZ(cur) > 0 && cur.back().first == x) cur.pop_back();
		}
		dp[i][j] = cur;
	}
	//REP(i, n) REP(j, n) { printf("dp[%d][%d]:", i, j); for (auto p : dp[i][j]) printf(" (%d,%d)", p.first, p.second + 1); puts(""); }
	//REP(i, n) { printf("mx%d:", i); REP(j, n) printf(" %d", mx[i][j]); puts(""); }
	FORE(i, 1, n) ans[i] = 0;
	REP(i, n) REP(j, n) ++ans[mx[i][j]];
	for (int i = n; i > 1; --i) ans[i - 1] += ans[i];
}

void run() {
	scanf("%d%d", &n, &lim);
	REP(i, n) REP(j, n) scanf("%d", &a[i][j]), --a[i][j];
	solve();
	FORE(i, 1, n) printf("%d\n", ans[i]);
}

int ansstupid[MAXN + 1];

void solvestupid() {
	FORE(i, 1, n) ansstupid[i] = 0;
	REP(i, n) REP(j, n) FORE(sz, 1, min(n - i, n - j)) {
		set<int> have;
		REP(ii, sz) REP(jj, sz) have.insert(a[i + ii][j + jj]);
		if (SZ(have) <= lim) ++ansstupid[sz];
	}
}

void stress() {
	int mxn = 10;
	REP(rep, 10000) {
		n = rnd() % mxn + 1;
		lim = rnd() % 10 + 1;
		int mxval = rnd() % (n * n) + 1;
		REP(i, n) REP(j, n) a[i][j] = rnd() % mxval;
		solve();
		solvestupid();
		bool ok = true; FORE(i, 1, n) if (ans[i] != ansstupid[i]) ok = false;
		if (ok) { printf("."); continue; }
		printf("err\n");
		printf("have:"); FORE(i, 1, n) printf(" %d", ans[i]); puts("");
		printf("want:"); FORE(i, 1, n) printf(" %d", ansstupid[i]); puts("");
		printf("%d %d\n", n, lim);
		REP(i, n) { REP(j, n) { if (j != 0) printf(" "); printf("%d", a[i][j] + 1); } puts(""); }

		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}