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
const int MAXSTEP = 20;
const int MAXMOD = 2 * MAXSTEP;

int n, step;
vector<int> adj[MAXN];
int val[MAXN];
int ans[MAXN];

int par[MAXN];

int mod;
int subtreesum[MAXN][MAXMOD];

int allsum[MAXN][MAXMOD];

void dfsinit(int at) {
	REP(i, mod) subtreesum[at][i] = 0;
	subtreesum[at][0] ^= val[at];
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
		REP(i, mod) subtreesum[at][(i + 1) % mod] ^= subtreesum[to][i];
	}
}

void dfscalc(int at) {
	int sum = 0; FOR(i, step, mod) sum ^= allsum[at][i]; ans[at] = sum == 0 ? 0 : 1;
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		REP(i, mod) allsum[to][i] = subtreesum[to][i] ^ (allsum[at][(i + mod - 1) % mod] ^ subtreesum[to][(i + mod - 2) % mod]);
		dfscalc(to);
	}
}

void solve() {
	mod = 2 * step;
	par[0] = -1; dfsinit(0);
	REP(i, mod) allsum[0][i] = subtreesum[0][i];
	REP(i, n) ans[i] = -1;
	dfscalc(0);
}

void run() {
	scanf("%d%d", &n, &step);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	REP(i, n) scanf("%d", &val[i]);
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}


int main() {
	//int ncase; scanf("%d", &ncase); FORE(i, 1, ncase)
	run();
	return 0;
}