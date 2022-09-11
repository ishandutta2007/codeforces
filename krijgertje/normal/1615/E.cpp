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

int n, redlim;
vector<int> adj[MAXN];

int par[MAXN];
bool isleaf[MAXN];
int dep[MAXN];
int deepest[MAXN];

void dfsinit(int at) {
	isleaf[at] = true;
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	deepest[at] = at;
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		isleaf[at] = false;
		dfsinit(to);
		if (dep[deepest[to]] > dep[deepest[at]]) deepest[at] = deepest[to];
	}
}

ll solve() {
	par[0] = -1;
	dfsinit(0);

	int nleaf = 0;
	REP(i, n) if (isleaf[i]) ++nleaf;
	if (redlim >= nleaf) {
		int nopt = n - nleaf, ncan = min(n, redlim) - nleaf;
		ll ret = LLONG_MIN;
		REPE(x, ncan) ret = max(ret, (ll)(nopt - x) * (nleaf + x));
		return ret;
	} else {
		priority_queue<pair<int, int>> pq;
		pq.push(MP(dep[deepest[0]], deepest[0]));
		vector<bool> blocked(n, false);
		int nblocked = 0;
		REP(i, redlim) {
			assert(!pq.empty());
			int at = pq.top().second; pq.pop();
			//printf("at=%d\n", at + 1);
			assert(isleaf[at] && !blocked[at]);
			int prv = -1;
			while (at != -1 && !blocked[at]) {
				blocked[at] = true;
				++nblocked;
				for (int to : adj[at]) {
					if (par[to] != at) continue;
					if (to == prv) continue;
					pq.push(MP(dep[deepest[to]] - dep[to], deepest[to]));
				}
				prv = at, at = par[at];
			}
		}
		int nopt = n - nblocked;
		//printf("B choice: (%d-x)*(%d-x) [0..%d]\n", nblocked - redlim + nopt, redlim, nopt);
		// (nopt-x)*(redlim-x)
		ll ret = LLONG_MAX;
		REPE(x, nopt) ret = min(ret, (ll)(nblocked - redlim + nopt - x) * (redlim - x));
		return ret;
	}
}

void run() {
	scanf("%d%d", &n, &redlim);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}