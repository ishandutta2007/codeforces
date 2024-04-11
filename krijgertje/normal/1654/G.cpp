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

int n;
int isbase[MAXN];
vector<int> adj[MAXN];
int ans[MAXN];

int d[MAXN];
bool isspecial[MAXN];
vector<int> special;
int nspecial;
vector<int> need[MAXN];
vector<int> byd[MAXN];
bool done[MAXN];

void dfsup(int at, int par) {
	done[at] = true;
	for (int to : adj[at]) {
		if (to == par || d[to] != d[at]) continue;
		dfsup(to, at);
		REP(k, nspecial) if (need[to][k] != INT_MAX) need[at][k] = min(need[at][k], need[to][k] + 1);
	}
}
void dfsdown(int at, int par) {
	for (int to : adj[at]) {
		if (to == par || d[to] != d[at]) continue;
		REP(k, nspecial) if (need[at][k] != INT_MAX) need[to][k] = min(need[to][k], need[at][k] + 1);
		dfsdown(to, at);
	}
}

void solve() {
	{
		REP(i, n) d[i] = INT_MAX;
		queue<int> q;
		REP(i, n) if (isbase[i] == 1) d[i] = 0, q.push(i);
		while (!q.empty()) {
			int at = q.front(); q.pop();
			for (int to : adj[at]) {
				if (d[at] + 1 < d[to]) d[to] = d[at] + 1, q.push(to);
			}
		}
	}
	REP(i, n) isspecial[i] = false;
	REP(at, n) for (int to : adj[at]) if (d[at] == d[to]) isspecial[d[at]] = true;
	special.clear();
	REP(i, n) if (isspecial[i]) special.PB(i);
	nspecial = SZ(special);
	REP(at, n) need[at] = vector<int>(nspecial, INT_MAX);
	REP(i, n) byd[d[i]].PB(i);
	REP(at, n) done[at] = false;
	REP(i, n) {
		for (int at : byd[i]) {
			for (int to : adj[at]) {
				if (d[to] == d[at] - 1) {
					REP(k, nspecial) if (need[to][k] != INT_MAX) need[at][k] = min(need[at][k], max(0, need[to][k] - 1));
				}
				if (d[to] == d[at]) {
					REP(k, nspecial) if (special[k] == d[at]) need[at][k] = 0;
				}
			}
		}
		for (int at : byd[i]) {
			if (done[at]) continue;
			dfsup(at, -1);
			dfsdown(at, -1);
		}
	}
	REP(at, n) {
		ans[at] = d[at];
		REP(k, nspecial) if (need[at][k] == 0) ans[at] = max(ans[at], 2 * d[at] - special[k]);
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &isbase[i]);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}