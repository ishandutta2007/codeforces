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

vector<int> fib;

int sz[MAXN];

void dfssz(int at, int par) {
	sz[at] = 1;
	for (int to : adj[at]) {
		if (to == par) continue;
		dfssz(to, at);
		sz[at] += sz[to];
	}
}
int dfscentroid(int at, int par, int rootsz) {
	for (int to : adj[at]) {
		if (to == par) continue;
		if (2 * sz[to] > rootsz) return dfscentroid(to, at, rootsz);
	}
	return at;
}
int centroid(int at) {
	dfssz(at, -1);
	return dfscentroid(at, -1, sz[at]);
}

int par[MAXN];
vector<int> lst;
void dfsinit(int at) {
	lst.PB(at);
	sz[at] = 1;
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
		sz[at] += sz[to];
	}
}

void removeedge(int a, int b) {
	//printf("removing %d-%d\n", a + 1, b + 1);
	bool bfound = false; REPSZ(i, adj[a]) if (adj[a][i] == b) { bfound = true; swap(adj[a][i], adj[a].back()); adj[a].pop_back(); break; } assert(bfound);
	bool afound = false; REPSZ(i, adj[b]) if (adj[b][i] == a) { afound = true; swap(adj[b][i], adj[b].back()); adj[b].pop_back(); break; } assert(afound);
}

bool decompose(int at, int idx) {
	//printf("decompose(%d,%d)\n", at + 1, fib[idx]);
	int cent = centroid(at);
	lst.clear(); par[cent] = -1; dfsinit(cent);
	assert(sz[cent] == fib[idx]);
	if (fib[idx] == 1) return true;
	int small = -1;
	for (int x : lst) if (sz[x] == fib[idx - 2]) { small = x; break; }
	if (small == -1) return false;
	removeedge(small, par[small]);
	return decompose(cent, idx - 1) && decompose(small, idx - 2);
}

bool solve() {
	if (n == 1) return true;
	fib.clear();
	fib.PB(1);
	fib.PB(1);
	while (fib.back() < n) fib.PB(fib[SZ(fib) - 2] + fib[SZ(fib) - 1]);
	//printf("fib:"); REPSZ(i, fib) printf(" %d", fib[i]); puts("");

	if (fib.back() != n) return false;
	return decompose(0, SZ(fib) - 1);
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	run();
	return 0;
}