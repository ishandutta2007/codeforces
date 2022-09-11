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

int n;
vector<vector<int>> adj;

vector<int> sz;
void dfssz(int at, int par) {
	sz[at] = 1;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par) continue;
		dfssz(to, at);
		sz[at] += sz[to];
	}
}
int dfscentroid(int at, int par) {
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par) continue;
		if (sz[to] >= n / 2) return dfscentroid(to, at);
	}
	return at;
}

pair<pair<int, int>, pair<int, int>> solve() {
	sz = vector<int>(n);
	dfssz(0, -1);
	int cent = dfscentroid(0, -1);
	dfssz(cent, -1);
	REPSZ(i, adj[cent]) {
		int to = adj[cent][i];
		if (2 * sz[to] == n) {
			int at = to, prv = cent;
			while (true) {
				int nxt = -1; REPSZ(j, adj[at]) { int tmp = adj[at][j]; if (tmp == prv) continue; nxt = tmp; break; } if (nxt == -1) break;
				prv = at, at = nxt;
			}
			//printf("cent=%d to=%d prv=%d at=%d\n", cent + 1, to + 1, prv + 1, at + 1);
			assert(SZ(adj[at]) == 1 && adj[at][0] == prv);
			return MP(MP(prv, at), MP(cent, at));
		}
	}
	REPSZ(i, adj[cent]) {
		int to = adj[cent][i];
		return MP(MP(cent, to), MP(cent, to));
	}
	assert(false); return MP(MP(-1, -1), MP(-1, -1));
}

void run() {
	scanf("%d", &n);
	adj = vector<vector<int>>(n); REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	auto ans = solve();
	printf("%d %d\n%d %d\n", ans.first.first + 1, ans.first.second + 1, ans.second.first + 1, ans.second.second + 1);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}