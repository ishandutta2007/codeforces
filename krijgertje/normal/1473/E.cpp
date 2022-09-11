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
vector<pair<int, int>> adj[MAXN];
ll ans[MAXN];

ll d[MAXN][2][2];
priority_queue<pair<ll, pair<int, pair<int, int>>>> pq;

void relax(int at, int x, int y, ll cost) { if (cost >= d[at][x][y]) return; d[at][x][y] = cost; pq.push(MP(-cost, MP(at, MP(x, y)))); }

void solve() {
	REP(i, n) REP(x, 2) REP(y, 2) d[i][x][y] = LLONG_MAX;
	pq = priority_queue<pair<ll, pair<int, pair<int, int>>>>();
	relax(0, 0, 0, 0LL);
	while (!pq.empty()) {
		ll cost = -pq.top().first; int at = pq.top().second.first; int x = pq.top().second.second.first, y = pq.top().second.second.second; pq.pop();
		if (cost != d[at][x][y]) continue;
		REPSZ(i, adj[at]) {
			int to = adj[at][i].first, w = adj[at][i].second;
			relax(to, x, y, cost + w);
			if (x == 0) relax(to, 1, y, cost + 2 * w);
			if (y == 0) relax(to, x, 1, cost);
			if (x == 0 && y == 0) relax(to, 1, 1, cost + w);
		}
	}
	REP(i, n) ans[i] = d[i][1][1];
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b, c; scanf("%d%d%d", &a, &b, &c); --a, --b; adj[a].PB(MP(b, c)); adj[b].PB(MP(a, c)); }
	solve();
	FOR(i, 1, n) { if (i != 1) printf(" "); printf("%lld", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}