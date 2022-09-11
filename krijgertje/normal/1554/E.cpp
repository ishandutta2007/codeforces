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
const int MOD = 998244353;

int n;
vector<int> adj[MAXN];
int ans[MAXN + 1];

int par[MAXN], sz[MAXN];
void dfsinit(int at) {
	sz[at] = 1;
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
		sz[at] += sz[to];
	}
}

void solve() {
	par[0] = -1; dfsinit(0);
	FORE(i, 1, n) ans[i] = 0;
	ans[1] = 1; REP(i, n - 1) ans[1] = (ll)ans[1] * 2 % MOD;
	FORE(i, 2, n) if ((n - 1) % i == 0) {
		bool ok = true;
		REP(j, n) if ((sz[j] - 1) % i != 0 && sz[j] % i != 0) ok = false;
		if (ok) ++ans[i];
	}
	for (int i = n; i >= 1; --i) for (int j = i + i; j <= n; j += i) ans[i] -= ans[j];
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	solve();
	FORE(i, 1, n) { if (i != 1) printf(" "); printf("%d", ans[i]); } puts("");
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}