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

int n, nmarked;
int s, t;
int marked[MAXN];
vector<int> adj[MAXN];

int par[MAXN];
void dfsinit(int at) {
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
	}
}

bool onpath[MAXN];
bool ismarked[MAXN];
int dfscalc(int at) {
	int ret = 0;
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		ret += dfscalc(to);
	}
	if (ismarked[at] || ret > 0) ret += 2;
	return ret;
}

int solve() {
	par[s] = -1;
	dfsinit(s);
	vector<int> path;
	for (int x = t; x != -1; x = par[x]) path.PB(x);
	reverse(path.begin(), path.end());
	int ret = SZ(path) - 1;
	REP(i, n) onpath[i] = false;
	for (int x : path) onpath[x] = true;
	REP(i, n) ismarked[i] = false;
	REP(i, nmarked) ismarked[marked[i]] = true;
	for (int x : path) {
		for (int to : adj[x]) {
			if (onpath[to]) continue;
			par[to] = x;
			ret += dfscalc(to);
		}
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &nmarked);
	scanf("%d%d", &s, &t), --s, --t;
	REP(i, nmarked) scanf("%d", &marked[i]), --marked[i];
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n", solve());
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}