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

const int MAXN = 1000;

int n;
int a[MAXN][MAXN];
int ans[MAXN][MAXN];

struct UF {
	int n; vector<int> par, sz, val;
	void init(int _n) { n = _n; par = sz = val = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1, val[i] = 0; }
	pair<int, int> find(int x) { if (par[x] != x) { pair<int, int> res = find(par[x]); par[x] = res.first; val[x] ^= res.second; } return MP(par[x], val[x]); }
	bool unite(int x, int y, int z) {
		pair<int, int> xx = find(x);
		pair<int, int> yy = find(y);
		x = xx.first, y = yy.first, z ^= xx.second ^ yy.second;
		if (x == y) return z == 0;
		if (sz[x] < sz[y]) swap(x, y);
		par[y] = x, sz[x] += sz[y], val[y] = z; return true;
	}
};

void solve() {
	UF uf;
	uf.init(n);
	REP(i, n) REP(j, n) ans[i][j] = a[i][j];
	REP(i, n) FOR(j, i + 1, n) {
		int v = a[i][j], w = a[j][i];
		if (v == w) continue;
		if (v < w) {
			if (!uf.unite(i, j, 0)) swap(ans[i][j], ans[j][i]);
		} else {
			if (uf.unite(i, j, 1)) swap(ans[i][j], ans[j][i]);
		}
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) REP(j,n) scanf("%d", &a[i][j]);
	solve();
	REP(i, n) { REP(j, n) { if (j != 0) printf(" "); printf("%d", ans[i][j]); } puts(""); }
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}