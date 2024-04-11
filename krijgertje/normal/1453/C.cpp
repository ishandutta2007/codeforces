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
int ans[10];

vector<vector<int>> a;

vector<vector<int>> rotate(const vector<vector<int>>& a) {
	vector<vector<int>> ret(n, vector<int>(n));
	REP(x, n) REP(y, n) ret[y][n - x - 1] = a[x][y];
	return ret;
}

void solvebottom() {
	vector<int> top(10, INT_MAX);
	REP(x, n) {
		vector<int> lft(10, INT_MAX), rgt(10, INT_MIN);
		REP(y, n) { int d = a[x][y]; lft[d] = min(lft[d], y), rgt[d] = max(rgt[d], y); top[d] = min(top[d], x); }
		REP(d, 10) if (lft[d] <= rgt[d] && top[d] != INT_MAX) {
			int opt1 = (rgt[d] - lft[d]) * (x - 0);
			ans[d] = max(ans[d], opt1);
			int opt2 = (n - 1 - lft[d]) * (x - top[d]);
			ans[d] = max(ans[d], opt2);
			int opt3 = (rgt[d] - 0) * (x - top[d]);
			ans[d] = max(ans[d], opt3);
		}
	}
}

void solve() {
	REP(d, 10) ans[d] = 0;
	a = vector<vector<int>>(n, vector<int>(n)); REP(x, n) REP(y, n) a[x][y] = g[x][y] - '0';
	REP(rep, 4) {
		solvebottom();
		a = rotate(a);
	}
}

void run() {
	scanf("%d", &n);
	REP(x, n) scanf("%s", g[x]);
	solve();
	REP(d, 10) { if (d != 0) printf(" "); printf("%d", ans[d]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}