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

const int MAXN = 200000;

int n, mxdist;
int x[MAXN], y[MAXN], t[MAXN];


struct UF {
	int n; vector<int> par, sz;
	void init(int _n) { n = _n; par = sz = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1; }
	int find(int x) { if (par[x] == x) return x; return par[x] = find(par[x]); }
	void unite(int x, int y) { x = find(x), y = find(y); if (x == y) return; if (sz[x] < sz[y]) swap(x, y); par[y] = x, sz[x] += sz[y]; }
};
UF uf;
int tg[MAXN];

int solve() {
	uf.init(n);

	map<int, vector<int>> byx;
	REP(i, n) byx[x[i]].PB(i);
	for (auto it = byx.begin(); it != byx.end(); ++it) {
		vector<int> lst = it->second;
		sort(lst.begin(), lst.end(), [&](int a, int b) { return y[a] < y[b]; });
		FORSZ(i, 1, lst) {
			int a = lst[i - 1], b = lst[i];
			if (y[b] - y[a] <= mxdist) uf.unite(a, b);
		}
	}

	map<int, vector<int>> byy;
	REP(i, n) byy[y[i]].PB(i);
	for (auto it = byy.begin(); it != byy.end(); ++it) {
		vector<int> lst = it->second;
		sort(lst.begin(), lst.end(), [&](int a, int b) { return x[a] < x[b]; });
		FORSZ(i, 1, lst) {
			int a = lst[i - 1], b = lst[i];
			if (x[b] - x[a] <= mxdist) uf.unite(a, b);
		}
	}

	//printf("uf:"); REP(i, n) printf(" %d", uf.find(i)); puts("");
	REP(i, n) tg[i] = INT_MAX;
	REP(i, n) { int g = uf.find(i); tg[g] = min(tg[g], t[i]); }
	vector<int> opt;
	REP(i, n) if (uf.find(i) == i) opt.PB(tg[i]);
	sort(opt.begin(), opt.end());
	//printf("opt:"); REPSZ(i, opt) printf(" %d", opt[i]); puts("");
	int ret = 0;
	while (ret + 1 < SZ(opt) && opt[SZ(opt) - (ret + 1) - 1] > ret) ++ret;
	return ret;
}

void run() {
	scanf("%d%d", &n, &mxdist);
	REP(i, n) scanf("%d%d%d", &x[i], &y[i], &t[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}