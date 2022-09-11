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

int n;
vector<int> adj[MAXN];
int val[MAXN];

int par[MAXN], dep[MAXN];
vector<int> bydep[MAXN];

ll f[MAXN];
ll dp[MAXN];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
	}
}

ll solve() {
	par[0] = -1; dfsinit(0);
	int mxdep = 0; REP(i, n) mxdep = max(mxdep, dep[i]);
	REPE(d, mxdep) bydep[d].clear();
	REP(i, n) bydep[dep[i]].PB(i);

	for (int d = mxdep; d >= 0; --d) {
		ll posmx = LLONG_MIN, negmx = LLONG_MIN;
		int mx = INT_MIN, mn = INT_MAX;
		for (int at : bydep[d]) {
			f[at] = 0;
			for (int to : adj[at]) {
				if (to == par[at]) continue;
				f[at] = max(f[at], dp[to]);
			}
			posmx = max(posmx, +val[at] + f[at]);
			negmx = max(negmx, -val[at] + f[at]);
			mx = max(mx, val[at]);
			mn = min(mn, val[at]);
		}
		for (int at : bydep[d]) {
			dp[at] = max(max(mx - val[at], val[at] - mn) + f[at], max(posmx - val[at], negmx + val[at]));
		}
	}
	return dp[0];
}

void run() {
	scanf("%d", &n);
	REP(i, n) adj[i].clear();
	FOR(a, 1, n) { int b; scanf("%d", &b); --b; adj[a].PB(b), adj[b].PB(a); }
	FOR(i, 1, n) scanf("%d", &val[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}