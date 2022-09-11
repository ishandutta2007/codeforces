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
vector<pair<int, int>> ans;

int mxdeg;


void rec(int at, int par, int t) {
	//printf("rec(%d,%d)\n", at, t);
	ans.PB(MP(at, t));
	bool jumped = false;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par) continue;
		if (t == mxdeg) { assert(!jumped); jumped = true; t -= SZ(adj[at]), ans.PB(MP(at, t)); }
		rec(to, at, t + 1);
		++t;
		//printf("expect: (%d,%d), have: (%d,%d) [mxdeg=%d]\n", at, t, ans.back().first, ans.back().second, mxdeg);
		assert(ans.back() == MP(at, t));
	}
	if (par != -1) {
		if (!jumped) t -= SZ(adj[at]), ans.PB(MP(at, t));
		ans.PB(MP(par, t + 1));
	}
}

void solve() {
	mxdeg = 0; REP(i, n) mxdeg = max(mxdeg, SZ(adj[i]));
	ans.clear();
	rec(0, -1, 0);
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b), adj[b].PB(a); }
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%d %d\n", ans[i].first + 1, ans[i].second);
}

int main() {
	run();
	return 0;
}