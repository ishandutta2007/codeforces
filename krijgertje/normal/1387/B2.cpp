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
int ans[MAXN];

int sz[MAXN];

void dfssz(int at, int par) {
	sz[at] = 1;
	REPSZ(i, adj[at]) { int to = adj[at][i]; if (to == par) continue; dfssz(to, at); sz[at] += sz[to]; }
}
int dfscentroid(int at, int par, int rootsz) {
	REPSZ(i, adj[at]) { int to = adj[at][i]; if (to == par) continue; if (2 * sz[to] > rootsz) return dfscentroid(to, at, rootsz); }
	return at;
}

int centroid(int at) {
	dfssz(at, -1);
	return dfscentroid(at, -1, sz[at]);
}

int lst[MAXN], nlst;

void dfslst(int at, int par) {
	lst[nlst++] = at;
	REPSZ(i, adj[at]) { int to = adj[at][i]; if (to == par) continue; dfslst(to, at); }
}
ll dfscalc(int at, int par) {
	ll ret = 0; sz[at] = 1;
	REPSZ(i, adj[at]) { int to = adj[at][i]; if (to == par) continue; ret += dfscalc(to, at); ret += min(sz[to], n - sz[to]); sz[at] += sz[to]; }
	return ret;
}

ll solve() {
	int c = centroid(0);
	nlst = 0; dfslst(c, -1);
	REP(i, n) ans[lst[i]] = lst[(i + n / 2) % n];
	return 2 * dfscalc(c, -1);
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%lld\n", solve());
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}