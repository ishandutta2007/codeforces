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

const int MAXN = 100000;

int n;
vector<int> adj[MAXN];
vector<vector<int>> ans;

int par[MAXN];
vector<int> rem[MAXN];

void dfsinit(int at) {
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
		if (SZ(rem[at]) < 2 && SZ(rem[to]) < 2) {
			rem[at].PB(to), rem[to].PB(at);
		} else {
			ans.PB({ at,to });
		}
	}
}

void solve() {
	ans.clear();
	REP(i, n) rem[i].clear();
	par[0] = -1;
	dfsinit(0);
	
	vector<vector<int>> paths;
	vector<bool> done(n, false);
	REP(i, n) if (!done[i] && SZ(rem[i]) <= 1) {
		int at = i;
		vector<int> path;
		while (!done[at]) {
			done[at] = true;
			path.PB(at);
			int to = -1;
			for (int x : rem[at]) if (!done[x]) { assert(to == -1); to = x; }
			if (to == -1) break;
			at = to;
		}
		paths.PB(path);
	}
	assert(SZ(ans) == SZ(paths) - 1);
	REPSZ(i, ans) ans[i].PB(paths[i].back()), ans[i].PB(paths[i + 1][0]);
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%d %d %d %d\n", ans[i][0] + 1, ans[i][1] + 1, ans[i][2] + 1, ans[i][3] + 1);
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}