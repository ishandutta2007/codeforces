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

const int MAXN = 500000;
const int MAXQ = 500000;

int n;
int e[MAXN - 1][3];
int nq;
int qidx[MAXQ], qans[MAXQ];


vector<pair<int, int>> adj[MAXN];


struct SNode {
	int val[2];
	bool lazy;
	SNode() { lazy = false; val[0] = val[1] = INT_MIN; }
};

vector<SNode> sval[2];
int col[2][MAXN];
int dep[2][MAXN];
int par[2][MAXN];
int nid[2];
int lst[2][MAXN];
int lid[2][MAXN];
int rid[2][MAXN];

void dfsinit(int id,int at) {
	dep[id][at] = par[id][at] == -1 ? 0 : dep[id][par[id][at]] + 1;
	lid[id][at] = nid[id]; lst[id][nid[id]] = at; ++nid[id];
	REPSZ(i, adj[at]) {
		int to = adj[at][i].first;
		if (to == par[id][at]) continue;
		par[id][to] = at;
		col[id][to] = col[id][at] ^ adj[at][i].second;
		dfsinit(id, to);
	}
	rid[id][at] = nid[id] - 1;
}

void sapply(vector<SNode>& sval, int x) {
	swap(sval[x].val[0], sval[x].val[1]);
	sval[x].lazy = !sval[x].lazy;
}
void spush(vector<SNode>& sval, int x) {
	if (sval[x].lazy) sapply(sval, 2 * x + 1), sapply(sval, 2 * x + 2), sval[x].lazy = false;
}
void spull(vector<SNode>& sval, int x) {
	REP(i, 2) sval[x].val[i] = max(sval[2 * x + 1].val[i], sval[2 * x + 2].val[i]);
}
void sinit(vector<SNode>& sval, int x, int l, int r, int id) {
	sval[x].lazy = false;
	if (l == r) {
		int at = lst[id][l], c = col[id][at];
		sval[x].val[c] = dep[id][at], sval[x].val[1 - c] = INT_MIN;
	} else {
		int m = l + (r - l) / 2;
		sinit(sval, 2 * x + 1, l, m, id);
		sinit(sval, 2 * x + 2, m + 1, r, id);
		spull(sval, x);
	}
}
void sflip(vector<SNode>& sval, int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		sapply(sval, x);
	} else {
		int m = l + (r - l) / 2; spush(sval, x);
		if (L <= m) sflip(sval, 2 * x + 1, l, m, L, R);
		if (m + 1 <= R) sflip(sval, 2 * x + 2, m + 1, r, L, R);
		spull(sval, x);
	}
}

int farthest(int s) {
	vector<int> d(n, INT_MAX);
	queue<int> q;
	d[s] = 0, q.push(s);
	vector<int> lst;
	while (!q.empty()) {
		int at = q.front(); q.pop();
		lst.PB(at);
		REPSZ(i, adj[at]) {
			int to = adj[at][i].first;
			if (d[to] == INT_MAX) d[to] = d[at] + 1, q.push(to);
		}
	}
	return lst.back();
}

void solve() {
	REP(i, n) adj[i].clear();
	REP(i, n - 1) { int a = e[i][0], b = e[i][1], c = e[i][2]; adj[a].PB(MP(b, c)); adj[b].PB(MP(a, c)); }
	int y = farthest(0);
	int x = farthest(y);

	REP(id, 2) {
		int s = id == 0 ? x : y;
		nid[id] = 0;
		par[id][s] = -1;
		col[id][s] = 0;
		dfsinit(id, s);
		sval[id] = vector<SNode>(4 * n);
		sinit(sval[id], 0, 0, n - 1, id);
	}

	REP(i, nq) {
		int idx = qidx[i];
		int a = e[idx][0], b = e[idx][1];
		qans[i] = 0;
		REP(id, 2) {
			if (dep[id][a] < dep[id][b]) swap(a, b);
			assert(dep[id][a] == dep[id][b] + 1);
			sflip(sval[id], 0, 0, n - 1, lid[id][a], rid[id][a]);
			qans[i] = max(qans[i], sval[id][0].val[0]);
		}
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) scanf("%d%d%d", &e[i][0], &e[i][1], &e[i][2]), --e[i][0], --e[i][1];
	scanf("%d", &nq);
	REP(i, nq) scanf("%d", &qidx[i]), --qidx[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}