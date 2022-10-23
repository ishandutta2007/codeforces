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
const int MAXQ = 10;

int n;
int par[MAXN];
int nq;
int q[MAXQ];
int qans[MAXQ];

vector<int> ch[MAXN];
vector<int> adj[MAXN];
int dep[MAXN];
int dist[MAXN];
vector<int> res[MAXN];
int curx, curans;

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	for (int to : ch[at]) dfsinit(to);
}

int dfscalc(int at) {
	int id = at;
	for (int to : ch[at]) {
		int subid = dfscalc(to);
		if (SZ(res[subid]) > SZ(res[id])) swap(id, subid);
		REPSZ(i, res[subid]) {
			while (true) {
				int jmn = max(0, curans + 1 - i - curx);
				if (jmn >= SZ(res[id]) || res[id][jmn] + res[subid][i] - 2 * dep[at] <= curans) break;
				++curans;
			}
		}
		REPSZ(i, res[subid]) res[id][i] = max(res[id][i], res[subid][i]);
	}
	while (true) {
		int jmn = max(0, curans + 1 - dist[at] - curx);
		if (jmn >= SZ(res[id]) || res[id][jmn] + dep[at] - 2 * dep[at] <= curans) break;
		++curans;
	}
	if (dist[at] < SZ(res[id])) {
		res[id][dist[at]] = max(res[id][dist[at]], dep[at]);
	} else {
		assert(dist[at] == SZ(res[id]));
		res[id].PB(dep[at]);
	}
	return id;
}

void solve() {
	REP(i, n) ch[i].clear();
	REP(i, n) adj[i].clear();
	REP(i, n) if (par[i] != -1) ch[par[i]].PB(i), adj[i].PB(par[i]), adj[par[i]].PB(i);
	dfsinit(0);
	REP(i, n) dist[i] = INT_MAX;
	queue<int> q;
	REP(i, n) if (SZ(adj[i]) <= 1) dist[i] = 0, q.push(i);
	while (!q.empty()) {
		int at = q.front(); q.pop();
		for (int to : adj[at]) if (dist[to] == INT_MAX) dist[to] = dist[at] + 1, q.push(to);
	}
	REP(i, nq) {
		REP(j, n) res[j] = vector<int>();
		curx = ::q[i], curans = -1;
		dfscalc(0);
		qans[i] = curans;
	}
}

void run() {
	scanf("%d", &n);
	par[0] = -1; FOR(i, 1, n) scanf("%d", &par[i]), --par[i];
	scanf("%d", &nq);
	REP(i, nq) scanf("%d", &q[i]);
	solve();
	REP(i, nq) { if (i != 0) printf(" "); printf("%d", qans[i]); } puts("");
}

int main() {
	run();
	return 0;
}