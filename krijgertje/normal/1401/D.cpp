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
const int MAXP = 60000;
const int MOD = 1000000007;

int n;
vector<int> adj[MAXN];
int np;
int p[MAXP];

int par[MAXN], sz[MAXN];
ll w[MAXN - 1]; int nw;



void dfsinit(int at) {
	sz[at] = 1;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		par[to] = at; dfsinit(to); sz[at] += sz[to];
	}
}

int solve() {
	par[0] = -1; dfsinit(0);
	nw = 0; REP(i, n) if (par[i] != -1) w[nw++] = (ll)sz[i] * (n - sz[i]);
	sort(w, w + nw); reverse(w, w + nw);
	sort(p, p + np);
	while (np > nw) p[np - 2] = (ll)p[np - 2] * p[np - 1] % MOD, --np;
	reverse(p, p + np);
	//printf("w:"); REP(i, nw) printf(" %lld", w[i]); puts("");
	//printf("p:"); REP(i, np) printf(" %d", p[i]); puts("");
	int ret = 0;
	REP(i, np) ret = (ret + (ll)p[i] * (w[i] % MOD)) % MOD;
	FOR(i, np, nw) ret = (ret + (w[i] % MOD)) % MOD;
	return ret;
}


void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	scanf("%d", &np);
	REP(i, np) scanf("%d", &p[i]);
	printf("%d\n", solve());
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}