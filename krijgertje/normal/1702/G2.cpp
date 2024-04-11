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
const int MAXQ = 100000;
const int MAXLG = 17;

int n;
vector<int> adj[MAXN];
int nq;
vector<int> q[MAXQ];
bool qans[MAXQ];

int par[MAXN], dep[MAXN];
int up[MAXN][MAXLG + 1];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	up[at][0] = par[at] == -1 ? at : par[at]; REP(k, MAXLG) up[at][k + 1] = up[up[at][k]][k];
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
	}
}
int calclca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int k = MAXLG; k >= 0; --k) if (dep[a] - (1 << k) >= dep[b]) a = up[a][k];
	if (a == b) return a;
	for (int k = MAXLG; k >= 0; --k) if (up[a][k] != up[b][k]) a = up[a][k], b = up[b][k];
	return par[a];
}
int calcup(int a, int steps) {
	REPE(k, MAXLG) if (steps & (1 << k)) a = up[a][k];
	return a;
}
bool isdesc(int a, int b) {
	if (dep[a] < dep[b]) return false;
	return calcup(a, dep[a] - dep[b]) == b;
}

void solve() {
	par[0] = -1; dfsinit(0);
	REP(i, nq) {
		int x = q[i][0];
		FORSZ(j, 1, q[i]) {
			x = calclca(x, q[i][j]);
		}
		vector<int> a, b; int aroot = -1, broot = -1; bool ok = true;
		REPSZ(j, q[i]) {
			int at = q[i][j];
			if (at == x) continue;
			int atroot = calcup(at, dep[at] - dep[x] - 1);
			if (aroot == -1) aroot = atroot; else if (atroot != aroot && broot == -1) broot = atroot;
			if (atroot == aroot) a.PB(at); else if (atroot == broot) b.PB(at); else { ok = false; break; }
		}
		sort(a.begin(), a.end(), [&](int u, int v) { return dep[u] < dep[v]; });
		sort(b.begin(), b.end(), [&](int u, int v) { return dep[u] < dep[v]; });
		FORSZ(j, 1, a) if (!isdesc(a[j], a[j - 1])) ok = false;
		FORSZ(j, 1, b) if (!isdesc(b[j], b[j - 1])) ok = false;
		qans[i] = ok;
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	scanf("%d", &nq);
	REP(i, nq) { int cnt; scanf("%d", &cnt); q[i] = vector<int>(cnt); REP(j, cnt) scanf("%d", &q[i][j]), --q[i][j]; }
	solve();
	REP(i, nq) printf("%s\n", qans[i] ? "YES" : "NO");
}

int main() {
	run();
	return 0;
}