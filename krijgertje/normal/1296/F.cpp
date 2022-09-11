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
typedef long long ll;  
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 5000;
const int MAXQ = 5000;

int n;
vector<pair<int,int>> adj[MAXN];
int nq;
int qa[MAXQ], qb[MAXQ], qc[MAXQ];
int ans[MAXN - 1];

int par[MAXN], parid[MAXN], dep[MAXN];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	REPSZ(i, adj[at]) {
		int to = adj[at][i].first; if (to == par[at]) continue;
		par[to] = at, parid[to] = adj[at][i].second; dfsinit(to);
	}
}

void updpar(int a, int c) {
	int idx = parid[a]; assert(idx != -1);
	//printf("setting %d to %d\n", idx, c);
	ans[idx] = max(ans[idx], c);
}

bool solve() {
	par[0] = -1, parid[0] = -1; dfsinit(0);
	REP(i, n) ans[i] = 1;
	REP(i, nq) {
		int a = qa[i], b = qb[i], c = qc[i];
		if (dep[a] < dep[b]) swap(a, b);
		while (dep[a] != dep[b]) {
			updpar(a, c);
			a = par[a];
		}
		while (a != b) {
			updpar(a, c);
			updpar(b, c);
			a = par[a], b = par[b];
		}
	}
	REP(i, nq) {
		int a = qa[i], b = qb[i], c = qc[i];
		if (dep[a] < dep[b]) swap(a, b);
		int cur = INT_MAX;
		while (dep[a] != dep[b]) {
			cur = min(cur, ans[parid[a]]);
			a = par[a];
		}
		while (a != b) {
			cur = min(cur, ans[parid[a]]);
			cur = min(cur, ans[parid[b]]);
			a = par[a], b = par[b];
		}
		//printf("%d: want %d have %d\n", i, c, cur);
		assert(cur >= c);
		if (cur != c) return false;
	}
	return true;

}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(MP(b, i)); adj[b].PB(MP(a, i)); }
	scanf("%d", &nq);
	REP(i, nq) { scanf("%d%d%d", &qa[i], &qb[i], &qc[i]); --qa[i], --qb[i]; }
	if (!solve()) { printf("-1\n"); return; }
	REP(i, n - 1) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}