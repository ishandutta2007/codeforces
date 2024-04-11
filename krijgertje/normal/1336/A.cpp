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

int n, k;
vector<int> adj[MAXN];

int dep[MAXN], par[MAXN], sz[MAXN];
int opt[MAXN], nopt;

void dfs(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	sz[at] = 1;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		par[to] = at; dfs(to);
		sz[at] += sz[to];
	}
	opt[nopt++] = dep[at] - (sz[at] - 1);
}

ll solve() {
	nopt = 0; par[0] = -1; dfs(0);
	sort(opt, opt + nopt); reverse(opt, opt + nopt);
	ll ret = 0; REP(i, k) ret += opt[i]; return ret;
}

void run() {
	scanf("%d%d", &n, &k);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b), adj[b].PB(a); }
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}