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

struct V {
	int lazy;
	set<int> vals;
	V() { lazy = 0; vals.clear(); vals.insert(0); }
	int size() { return SZ(vals); }
	bool have(int x) { return vals.count(x ^ lazy) != 0; }
	vector<int> get() { vector<int> ret; for (int v : vals) ret.PB(v ^ lazy); return ret; }
	void insert(int x) { vals.insert(x ^ lazy); }
};

const int MAXN = 200000;

int n;
int val[MAXN];
vector<int> adj[MAXN];

V vals[MAXN];
bool change[MAXN];

int dfs(int at, int par) {
	change[at] = false;
	int ret = at;
	vals[ret] = V();
	for (int to : adj[at]) {
		if (to == par) continue;
		int sub = dfs(to, at);
		if (sub == -1 || ret == -1) continue;
		if (SZ(vals[sub]) > SZ(vals[ret])) swap(sub, ret);
		for (int v : vals[sub].get()) {
			if (vals[ret].have(v ^ val[at])) {
				change[at] = true;
				ret = -1;
				break;
			}
		}
		if (ret == -1) continue;
		for (int v : vals[sub].get()) {
			vals[ret].insert(v);
		}
	}
	if (ret != -1) vals[ret].lazy ^= val[at];
	//printf("%d:", at + 1); if (ret == -1) printf(" X"); else for (int v : vals[ret].get()) printf(" %d", v); puts("");
	return ret;
}

int solve() {
	dfs(0, -1);
	int ret = 0; REP(i, n) if (change[i]) ++ret; return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &val[i]);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}