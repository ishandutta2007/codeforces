#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 200000;

int n;
vector<int> adj[MAXN];

int sz[MAXN], dep[MAXN];

ll dfs(int at, int par) {
	dep[at] = par == -1 ? 0 : dep[par] + 1; sz[at] = 1; ll ret = 0;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par) continue;
		ret += dfs(to, at);
		ret += (ll)(n - sz[to])*sz[to];
		sz[at] += sz[to];
	}
	return ret;
}

ll solve() {
	ll sumdst = dfs(0, -1);
	int nred = 0, nblack = 0; REP(i, n) if (dep[i] % 2 == 0) ++nred; else ++nblack;
	ll ret = sumdst + (ll)nred*nblack; assert(ret % 2 == 0); ret /= 2; return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}