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

const int MAXN = 500000;
const int KINDPAIRING = 0;
const int KINDPATH = 1;

int n, m;
vector<int> adj[MAXN];
vector<pair<int, int>> anspairing;
vector<int> anspath;

int par[MAXN], dep[MAXN];

int deg[MAXN];
vector<int> available[MAXN];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		if (par[to] != -2) continue;
		par[to] = at; dfsinit(to);
	}
}

int solve() {
	REP(i, n) par[i] = -2;
	par[0] = -1; dfsinit(0);
	int mxdepnode = 0; FOR(i, 1, n) if (dep[i] > dep[mxdepnode]) mxdepnode = i;
	if (dep[mxdepnode] + 1 >= (n + 1) / 2) {
		anspath.clear();
		for (int x = mxdepnode; x != -1; x = par[x]) anspath.PB(x);
		return KINDPATH;
	}

	REP(i, n) deg[i] = 0;
	REP(i, n) if (par[i] != -1) ++deg[i], ++deg[par[i]];
	REP(i, n) available[i].clear();
	REP(i, n) if (i != 0 && deg[i] <= 1) available[dep[i]].PB(i);

	int a = n - 1, b = n - 1; anspairing.clear();
	while (true) {
		while (a >= 0 && SZ(available[a]) == 0) --a;
		while (b >= 0 && SZ(available[b]) - (b == a ? 1 : 0) == 0) --b;
		if (a < 0 || b < 0) break;
		int x = available[a].back(); available[a].pop_back();
		int y = available[b].back(); available[b].pop_back();
		anspairing.PB(MP(x, y));
		if (par[x] != -1) { --deg[x], --deg[par[x]]; if (par[x] != 0 && deg[par[x]] == 1) available[dep[par[x]]].PB(par[x]); }
		if (par[y] != -1) { --deg[y], --deg[par[y]]; if (par[y] != 0 && deg[par[y]] == 1) available[dep[par[y]]].PB(par[y]); }
	}
	assert(2 * SZ(anspairing) >= (n + 1) / 2);
	return KINDPAIRING;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b), adj[b].PB(a); }
	int anskind = solve();
	if (anskind == KINDPAIRING) {
		printf("PAIRING\n");
		printf("%d\n", SZ(anspairing));
		REPSZ(i, anspairing) printf("%d %d\n", anspairing[i].first + 1, anspairing[i].second + 1);
	} else if (anskind == KINDPATH) {
		printf("PATH\n");
		printf("%d\n", SZ(anspath));
		REPSZ(i, anspath) { if (i != 0) printf(" "); printf("%d", anspath[i] + 1); } puts("");
	} else {
		printf("TODO\n");
	}
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}