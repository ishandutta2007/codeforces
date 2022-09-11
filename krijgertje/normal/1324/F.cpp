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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 200000;

int n;
int col[MAXN];
vector<int> adj[MAXN];
int ans[MAXN];

int dpdown[MAXN];
int dpup[MAXN];

void dfsdown(int at, int par) {
	dpdown[at] = col[at] == 1 ? +1 : -1;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par) continue;
		dfsdown(to, at);
		dpdown[at] += max(0, dpdown[to]);
	}
}
void dfsup(int at, int par) {
	ans[at] = col[at] == 1 ? +1 : -1;
	ans[at] += max(0, dpup[at]);
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par) continue;
		dpup[to] = dpdown[at] - max(0, dpdown[to]) + max(0, dpup[at]);
		ans[at] += max(0, dpdown[to]);
		dfsup(to, at);
	}
}



void solve() {
	dfsdown(0, -1);
	dpup[0] = 0; dfsup(0, -1);
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &col[i]);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}


int main() {
	run();
	return 0;
}