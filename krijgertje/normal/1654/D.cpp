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
const int MOD = 998244353;
struct E { int to, num, den; E() {} E(int to, int num, int den) :to(to), num(num), den(den) {} };

int n;
vector<E> adj[MAXN];

int inv[MAXN + 1];
int pmn[MAXN + 1];

int par[MAXN], val[MAXN];
int tmp[MAXN + 1], need[MAXN + 1];

void dfsinit(int at) {
	for (const auto &e : adj[at]) {
		int to = e.to;
		if (to == par[at]) continue;
		par[to] = at;
		val[to] = (ll)val[at] * e.num % MOD * inv[e.den] % MOD;
		for (int x = e.num; x != 1; x /= pmn[x]) --tmp[pmn[x]];
		for (int x = e.den; x != 1; x /= pmn[x]) { ++tmp[pmn[x]]; need[pmn[x]] = max(need[pmn[x]], tmp[pmn[x]]); }
		dfsinit(to);
		for (int x = e.num; x != 1; x /= pmn[x]) ++tmp[pmn[x]];
		for (int x = e.den; x != 1; x /= pmn[x]) --tmp[pmn[x]];
	}
}

int solve() {
	inv[1] = 1; FORE(i, 2, n) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	REPE(i, n) pmn[i] = -1; for (int i = 2; i <= n; ++i) if (pmn[i] == -1) for (int j = i; j <= n; j += i) if (pmn[j] == -1) pmn[j] = i;

	REPE(i, n) tmp[i] = 0, need[i] = 0;
	par[0] = -1; val[0] = 1; dfsinit(0);
	int mlt = 1;
	REPE(i, n) REP(j, need[i]) mlt = (ll)mlt * i % MOD;
	int sum = 0;
	REP(i, n) sum = (sum + val[i]) % MOD;
	return (ll)sum * mlt % MOD;
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b, x, y; scanf("%d%d%d%d", &a, &b, &x, &y); --a, --b; int g = gcd(x, y); x /= g, y /= g; adj[a].PB(E(b, y, x)); adj[b].PB(E(a, x, y)); }
	printf("%d\n", solve());
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}