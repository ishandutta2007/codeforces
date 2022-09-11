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

const int MAXN = 200000;
const int MAXLG = 17;

int n;
int val[MAXN];
vector<int> adj[MAXN];

int par[MAXN];
int lord[MAXN], rord[MAXN], ord[MAXN], nord;
int up[MAXN][MAXLG + 1];
int dep[MAXN];

int block[MAXN + 1];

void dfsinit(int at) {
	lord[at] = nord, ord[nord] = at, ++nord;
	up[at][0] = par[at] == -1 ? at : par[at]; REP(k, MAXLG) up[at][k + 1] = up[up[at][k]][k];
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	REPSZ(i, adj[at]) {
		int to = adj[at][i];
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
	}
	rord[at] = nord - 1;
}

bool insubtree(int a, int b) {
	return lord[b] <= lord[a] && lord[a] <= rord[b];
}

int calcup(int a, int steps) {
	REPE(k, MAXLG) if (steps & (1 << k)) a = up[a][k];
	return a;
}

int solve() {
	par[0] = -1; nord = 0; dfsinit(0);

	map<int, vector<int>> who;
	REP(i, n) who[val[i]].PB(lord[i]);

	REPE(i, n) block[i] = 0;
	for (auto kvp : who) {
		vector<int> lst = kvp.second;
		sort(lst.begin(), lst.end());
		REPSZ(i, lst) {
			int at = ord[lst[i]];
			bool anyoutside = false, anyinside = false;
			if (!insubtree(ord[lst[0]],at)) anyoutside = true;
			if (!insubtree(ord[lst.back()],at)) anyoutside = true;
			if (i + 1 < SZ(lst) && insubtree(ord[lst[i + 1]], at)) anyinside = true;
			if (anyoutside && anyinside) return 0;
			if (anyoutside) ++block[lord[at]], --block[rord[at] + 1];
			if (anyinside) {
				assert(i == 0);
				int x = ord[lst[1]], y = ord[lst.back()];
				int to = calcup(x, dep[x] - dep[at] - 1);
				if (calcup(y, dep[y] - dep[at] - 1) != to) return 0;
				++block[0], --block[lord[to]], ++block[rord[to] + 1], --block[n];
			}
		}
	}
	REP(i, n) block[i + 1] += block[i];
	int ret = 0;
	REP(i, n) if (block[i] == 0) ++ret;
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &val[i]);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b), adj[b].PB(a); }
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}