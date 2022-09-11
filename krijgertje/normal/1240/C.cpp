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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 500000;

int n, lim;
vector<pair<int,int>> adj[MAXN];

ll dploose[MAXN];
ll dptight[MAXN];

void dfs(int at, int par) {
	REPSZ(i, adj[at]) {
		int to = adj[at][i].first; if (to == par) continue;
		dfs(to, at);
	}
	ll sum = 0;
	vector<ll> opt;
	REPSZ(i, adj[at]) {
		int to = adj[at][i].first; if (to == par) continue;
		sum += dptight[to];
		ll cur = adj[at][i].second + dploose[to] - dptight[to];
		if (cur > 0) opt.PB(cur);
	}
	sort(opt.begin(), opt.end());
	reverse(opt.begin(), opt.end());
	dploose[at] = dptight[at] = sum;
	REPSZ(i, opt) {
		if (i < lim) dptight[at] += opt[i];
		if (i < lim - 1) dploose[at] += opt[i];
	}
}

ll solve() {
	dfs(0, -1);
	return dptight[0];
}

void run() {
	scanf("%d%d", &n, &lim);
	REP(i, n - 1) { int a, b, c; scanf("%d%d%d", &a, &b, &c); --a, --b; adj[a].PB(MP(b, c)); adj[b].PB(MP(a, c)); }
	printf("%lld\n", solve());
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}