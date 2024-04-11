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
const pair<int, int> IMPOSSIBLE = MP(-2, -2);

int n;
vector<int> adj[MAXN];
vector<pair<int, int>> ans;

int par[MAXN];
void dfsinit(int at) {
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
	}
}

pair<int, int> dfscalc(int at) {
	vector<int> singles;
	vector<pair<int, int>> pairs;
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		pair<int, int> res = dfscalc(to);
		if (res == IMPOSSIBLE) return IMPOSSIBLE;
		if (res.second != -1) pairs.PB(res); else if (res.first != -1) singles.PB(res.first);
	}
	int col = SZ(adj[at]) % 2;
	while (true) {
		if (col == 0) {
			if (SZ(pairs) == 0) {
				if (SZ(singles) == 0) return MP(-1, -1);
				if (SZ(singles) == 1) return MP(at, singles[0]);
				return IMPOSSIBLE;
			}
			pair<int, int> cur = pairs.back(); pairs.pop_back();
			ans.PB(MP(at, cur.first));
			ans.PB(cur);
		} else {
			if (SZ(singles) == 0) {
				if (SZ(pairs) == 0) return MP(at, -1);
				return IMPOSSIBLE;
			}
			int cur = singles.back(); singles.pop_back();
			ans.PB(MP(at, cur));
		}
		col = 1 - col;
	}
}

bool solve() {
	ans.clear();
	par[0] = -1; dfsinit(0);
	return dfscalc(0) == MP(-1, -1);
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	if (!solve()) {
		printf("NO\n");
	} else {
		printf("YES\n");
		REPSZ(i, ans) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
	}
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}