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

const int MAXN = 1000000;

int h, w, n;
vector<string> g;
vector<string> ans;

vector<int> adj[MAXN];

void solve() {
	ans = g;
	n = h * w;
	REP(i, n) adj[i].clear();
	REP(x, h) REP(y, w) FORE(dx, -1, +1) FORE(dy, -1, +1) if (dx * dx + dy * dy == 1) {
		int nx = x + dx, ny = y + dy;
		if (nx < 0 || nx >= h || ny < 0 || ny >= w || g[nx][ny] == '#') continue;
		adj[x * w + y].PB(nx * w + ny);
	}
	vector<bool> ok(n, false);
	vector<int> cntwrong(n);
	REP(i, n) cntwrong[i] = SZ(adj[i]);
	vector<int> cntright(n, 0);
	queue<int> q;
	REP(x, h) REP(y, w) if (g[x][y] == 'L') { int id = x * w + y; ok[id] = true; q.push(id); }
	while (!q.empty()) {
		int at = q.front(); q.pop();
		for (int to : adj[at]) {
			--cntwrong[to];
			++cntright[to];
			if (!ok[to] && (cntright[to] == 1 && cntwrong[to] <= 1 || cntright[to] >= 1 && cntwrong[to] == 1)) { ok[to] = true; q.push(to); }
		}
	}
	REP(x, h) REP(y, w) if (ans[x][y] == '.' && ok[x * w + y]) ans[x][y] = '+';
}

void run() {
	scanf("%d%d", &h, &w); 
	g = vector<string>(h); REP(x, h) cin >> g[x];
	solve();
	REPSZ(x, ans) printf("%s\n", ans[x].c_str());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}