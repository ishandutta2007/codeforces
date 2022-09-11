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
const int MAXQ = 300000;

int n, m;
vector<int> adj[MAXN];
int nq;
int qa[MAXQ], qb[MAXQ];
vector<int> qpath[MAXQ];

vector<pair<int, int>> qadj[MAXN];

int par[MAXN], dep[MAXN];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		if (par[to] != -2) continue;
		par[to] = at;
		dfsinit(to);
	}
}

int solve() {
	REP(i, n) qadj[i].clear();
	REP(i, nq) { int a = qa[i], b = qb[i]; qadj[a].PB(MP(b, i)); qadj[b].PB(MP(a, i)); }
	int nodd = 0;
	REP(i, n) if (SZ(qadj[i]) % 2 != 0) ++nodd;
	assert(nodd % 2 == 0);
	if (nodd == 0) {
		REP(i, n) par[i] = -2;
		par[0] = -1;
		dfsinit(0);
		REP(i, n) assert(par[i] != -2);
		REP(i, nq) {
			int a = qa[i], b = qb[i];
			vector<int> apath; vector<int> bpath;
			while (a != b) {
				if (dep[a] > dep[b]) apath.PB(a), a = par[a]; else bpath.PB(b), b = par[b];
			}
			reverse(bpath.begin(), bpath.end());
			qpath[i].clear();
			for (int x : apath) qpath[i].PB(x);
			qpath[i].PB(a);
			for (int x : bpath) qpath[i].PB(x);
		}
	}
	return nodd / 2;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d", &qa[i], &qb[i]), --qa[i], --qb[i];
	int ans = solve();
	if (ans == 0) {
		printf("YES\n");
		REP(i, nq) { printf("%d\n", SZ(qpath[i])); REPSZ(j, qpath[i]) { if (j != 0) printf(" "); printf("%d", qpath[i][j] + 1); } puts(""); }
	} else {
		printf("NO\n");
		printf("%d\n", ans);
	}
}

int main() {
	run();
	return 0;
}