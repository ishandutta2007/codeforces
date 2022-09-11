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

const int MAXN = 300000;
struct Res { int with, without, best; };

int n;
vector<int> adj[MAXN];

Res dfs(int at, int par) {
	int nch = SZ(adj[at]) - (par != -1 ? 1 : 0);
	Res ret; ret.with = 1; ret.without = nch; ret.best = 0;
	int without1 = 0, without2 = 0;
	int any1 = 0, any2 = 0;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par) continue;
		Res sub = dfs(to, at);
		ret.with = max(ret.with, sub.without + 1);
		ret.without = max(ret.without, max(sub.with, sub.without) + nch - 1);
		ret.best = max(ret.best, sub.best);
		int anyc = max(sub.with, sub.without);
		if (anyc > any1) any2 = any1, any1 = anyc; else if (anyc > any2) any2 = anyc;
		int withoutc = sub.without;
		if (withoutc > without1) without2 = without1, without1 = withoutc; else if (withoutc > without2) without2 = withoutc;
	}
	ret.best = max(ret.best, max(ret.with, ret.without));
	if (nch >= 2) ret.best = max(ret.best, max(without1 + without2 + 1, any1 + any2 + SZ(adj[at]) - 2));
	return ret;
}

int solve() {
	return dfs(0, -1).best;
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b), adj[b].PB(a); }
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}