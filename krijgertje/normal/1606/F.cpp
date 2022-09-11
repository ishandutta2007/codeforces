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
const int MAXQ = 200000;

int n;
vector<int> adj[MAXN];
int nq;
int qv[MAXQ], qprice[MAXQ];
int qans[MAXQ];

int lim;
vector<int> f[MAXN]; // f[i][k] = max value for subtree of i when removing costs k
vector<int> g[MAXN]; // g[i][j] = max value for subtree of i when removing exactly j elements


vector<int> merge(const vector<int> &a, const vector<int> &b) {
	assert(SZ(a) >= 1 && SZ(b) >= 1);
	vector<int> ret(min(lim + 1, SZ(a) - 1 + SZ(b) - 1 + 1 + 1), INT_MIN);
	REPSZ(i, a) if (i < SZ(ret)) ret[i] = max(ret[i], a[i] + 1);
	REPSZ(i, a) REPSZ(j, b) if (i + j + 1 < SZ(ret)) ret[i + j + 1] = max(ret[i + j + 1], a[i] + b[j]);
	REPSZ(i, ret) assert(ret[i] != INT_MIN);
	return ret;
}

void dfsf(int at, int par) {
	f[at] = vector<int>(lim + 1, 0);
	for (int to : adj[at]) {
		if (to == par) continue;
		dfsf(to, at);
		REPE(k, lim) f[at][k] += max(1, f[to][k] - k);
	}
}

void dfsg(int at, int par) {
	g[at] = vector<int>(1, 0);
	for (int to : adj[at]) {
		if (to == par) continue;
		dfsg(to, at);
		g[at] = merge(g[at], g[to]);
	}
	//printf("g[%d]: ", at + 1); REPSZ(i, g[at]) printf(" %d", g[at][i]); puts("");
}

void solve() {
	lim = sqrt(1.0 * n);
	dfsf(0, -1);
	REP(i, nq) {
		int x = qv[i], k = qprice[i];
		if (k <= lim) {
			qans[i] = f[x][k];
		}
	}
	REP(i, n) f[i] = vector<int>();
	dfsg(0, -1);
	REP(i, nq) {
		int x = qv[i], k = qprice[i];
		if (k > lim) {
			qans[i] = g[x][0];
			FORSZ(j, 1, g[x]) qans[i] = max(qans[i], g[x][j] - j * k);
		}
	}
	REP(i, n) g[i] = vector<int>();
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d", &qv[i], &qprice[i]), --qv[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}