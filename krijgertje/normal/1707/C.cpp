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

const int MAXN = 100000;
const int MAXLG = 16;
const int MAXM = 200000;

int n, m;
int e[MAXM][2];
bool ans[MAXN];

bool intree[MAXM];
vector<int> tree[MAXN];

int par[MAXN], dep[MAXN];
int up[MAXN][MAXLG + 1];
void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	up[at][0] = par[at] == -1 ? at : par[at]; REP(k, MAXLG) up[at][k + 1] = up[up[at][k]][k];
	for (int to : tree[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
	}
}
int calclca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int k = MAXLG; k >= 0; --k) if (dep[a] - (1 << k) >= dep[b]) a = up[a][k];
	if (a == b) return a;
	for (int k = MAXLG; k >= 0; --k) if (up[a][k] != up[b][k]) a = up[a][k], b = up[b][k];
	return par[a];
}
int calcup(int a, int n) {
	REPE(k, MAXLG) if (n & (1 << k)) a = up[a][k];
	return a;
}

struct UF {
	int n; vector<int> par, sz;
	void init(int _n) { n = _n; par = sz = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1; }
	int find(int x) { if (par[x] == x) return x; return par[x] = find(par[x]); }
	bool unite(int x, int y) { x = find(x), y = find(y); if (x == y) return false; if (sz[x] < sz[y]) swap(x, y); par[y] = x, sz[x] += sz[y]; return true; }
};

int dp[MAXN], dpsubtree[MAXN];
void dfsdp(int at) {
	dp[at] += dpsubtree[at];
	for (int to : tree[at]) {
		if (to == par[at]) continue;
		dpsubtree[to] += dpsubtree[at];
		dfsdp(to);
	}
}

void solve() {
	UF uf;
	uf.init(n);
	REP(i, n) tree[i].clear();
	REP(i, m) {
		int a = e[i][0], b = e[i][1];
		intree[i] = uf.unite(a, b);
		if (intree[i]) tree[a].PB(b), tree[b].PB(a);
	}
	int root = 0;
	par[root] = -1; dfsinit(root);
	int cnt = 0;
	REP(i, n) dp[i] = dpsubtree[i] = 0;
	REP(i, m) if (!intree[i]) {
		++cnt;
		int a = e[i][0], b = e[i][1];
		if (dep[a] > dep[b]) swap(a, b);
		int c = calclca(a, b);
		if (c == a) {
			++dpsubtree[root], --dpsubtree[calcup(b, dep[b] - dep[a] - 1)], ++dpsubtree[b];
		} else {
			++dpsubtree[a], ++dpsubtree[b];
		}
	}
	dfsdp(root);
	//printf("dp:"); REP(i, n) printf(" %d", dp[i]); puts("");
	REP(i, n) ans[i] = dp[i] == cnt;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) REP(j, 2) scanf("%d", &e[i][j]), --e[i][j];
	solve();
	REP(i, n) printf("%c", ans[i] ? '1' : '0'); puts("");
}

int main() {
	run();
	return 0;
}