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
const int MAXM = 200000;
const int MAXBIT = 29;

struct UF {
	int n; vector<int> par, sz;
	void init(int _n) { n = _n; par = sz = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1; }
	int find(int x) { if (par[x] == x) return x; return par[x] = find(par[x]); }
	bool unite(int x, int y) { x = find(x), y = find(y); if (x == y) return false; if (sz[x] > sz[y]) swap(x, y); par[y] = x, sz[x] += sz[y]; return true; }
};


int n, m;
int a[MAXM], b[MAXM], c[MAXM];

UF uf;

bool can(int forbidden) {
	uf.init(n);
	int ncomp = n;
	REP(i, m) {
		if ((c[i] & forbidden) != 0) continue;
		if (uf.unite(a[i], b[i])) --ncomp;
	}
	return ncomp == 1;
}

int solve() {
	int ret = 0;
	int forbidden = 0;
	for (int bit = MAXBIT; bit >= 0; --bit) {
		if (can(forbidden | (1 << bit))) {
			forbidden |= 1 << bit;
		} else {
			ret |= 1 << bit;
		}
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) scanf("%d%d%d", &a[i], &b[i], &c[i]), --a[i], --b[i];
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}