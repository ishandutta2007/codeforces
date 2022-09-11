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

int n, m;
int s[MAXN], t[MAXN];
vector<int> adj[MAXN];

bool done[MAXN];
int par[MAXN];
int dep[MAXN];

bool bipartite;
ll bal;


void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	bal += (dep[at] % 2 == 0 ? +1 : -1) * (s[at] - t[at]);
	for (int to : adj[at]) {
		if (done[to]) {
			if (dep[at] % 2 == dep[to] % 2) bipartite = false;
			continue;
		}
		done[to] = true, par[to] = at;
		dfsinit(to);
	}
}

bool solve() {
	REP(i, n) done[i] = false;
	REP(i, n) if (!done[i]) {
		bipartite = true, bal = 0;
		done[i] = true, par[i] = -1;
		dfsinit(i);
		if (bal % 2 != 0) return false;
		if (bipartite && bal != 0) return false;
	}
	return true;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, n) scanf("%d", &s[i]);
	REP(i, n) scanf("%d", &t[i]);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%s\n", solve() ? "YES" : "NO");
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}