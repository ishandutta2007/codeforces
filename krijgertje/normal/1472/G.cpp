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
vector<int> adj[MAXN];
vector<int> radj[MAXN];
int ans[MAXN];

int d[MAXN];

void solve() {
	vector<int> ord;
	{
		REP(i, n) d[i] = INT_MAX;
		queue<int> q;
		auto relax = [&](int to, int cost) { if (d[to] != INT_MAX) return; d[to] = cost; q.push(to); };
		relax(0, 0);
		while (!q.empty()) {
			int at = q.front(); q.pop();
			ord.PB(at);
			for (int to : adj[at]) relax(to, d[at] + 1);
		}
	}

	{
		REP(i, n) ans[i] = INT_MAX;
		queue<int> q;
		auto relax = [&](int to, int val) { if (ans[to] != INT_MAX) return; ans[to] = val; q.push(to); };
		REP(i, n) {
			int cur = ord[i];
			relax(cur, d[cur]);
			for (int prv : radj[cur]) relax(prv, d[cur]);
			while (!q.empty()) {
				int at = q.front(); q.pop();
				for (int to : radj[at]) if (d[to] == d[at] - 1) relax(to, d[cur]);
			}
		}
	}
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); radj[b].PB(a); }
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
	REP(i, n) adj[i].clear(), radj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase)  run();
	return 0;
}