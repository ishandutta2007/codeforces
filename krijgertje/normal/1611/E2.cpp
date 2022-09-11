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
const int MAXFRIEND = 200000;

int n, nfriend;
int friendstartpos[MAXFRIEND];
vector<int> adj[MAXN];

int par[MAXN];
int dep[MAXN];
int reach[MAXN];
bool startswithfriend[MAXN];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	reach[at] = startswithfriend[at] ? 0 : INT_MAX;
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
		if (reach[to] != INT_MAX) reach[at] = min(reach[at], reach[to] + 1);
	}
}

int dfscalc(int at) {
	if (reach[at] <= dep[at]) return 1;
	bool leaf = true;
	int ret = 0;
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		leaf = false;
		int sub = dfscalc(to);
		if (sub == -1) return -1;
		ret += sub;
	}
	if (leaf) return -1;
	return ret;
}

int solve() {
	REP(i, n) startswithfriend[i] = false;
	REP(i, nfriend) startswithfriend[friendstartpos[i]] = true;
	par[0] = -1;
	dfsinit(0);
	return dfscalc(0);
}

void run() {
	scanf("%d%d", &n, &nfriend);
	REP(i, nfriend) scanf("%d", &friendstartpos[i]), --friendstartpos[i];
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n", solve());
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}