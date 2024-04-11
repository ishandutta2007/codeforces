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
std::mt19937_64 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXN = 300000;
const int MAXQ = 300000;
const int MAXLG = 18;

struct SNode {
	int l, r;
	ull sum;
	SNode() { l = r = -1, sum = 0ULL; }
};
vector<SNode> snodes;

int scopy(int x) {
	SNode me = x == -1 ? SNode() : snodes[x];
	snodes.PB(me);
	return SZ(snodes) - 1;
}

int smod(int x, int l, int r, int IDX, ull VAL) {
	int ret = scopy(x);
	snodes[ret].sum ^= VAL;
	if (l != r) {
		int m = l + (r - l) / 2;
		if (IDX <= m) { int sub = smod(snodes[ret].l, l, m, IDX, VAL); snodes[ret].l = sub; }
		else { int sub = smod(snodes[ret].r, m + 1, r, IDX, VAL); snodes[ret].r = sub; }
	}
	return ret;
}

int scalc(int a, int b, int c, int d, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		ull cur = (a == -1 ? 0ULL : snodes[a].sum) ^ (b == -1 ? 0ULL : snodes[b].sum) ^ (c == -1 ? 0ULL : snodes[c].sum) ^ (d == -1 ? 0ULL : snodes[d].sum);
		if (cur != 0ULL) {
			if (l == r) return l;
			int m = l + (r - l) / 2;
			{ int ret = scalc(a == -1 ? -1 : snodes[a].l, b == -1 ? -1 : snodes[b].l, c == -1 ? -1 : snodes[c].l, d == -1 ? -1 : snodes[d].l, l, m, L, R); if (ret != -1) return ret; }
			{ int ret = scalc(a == -1 ? -1 : snodes[a].r, b == -1 ? -1 : snodes[b].r, c == -1 ? -1 : snodes[c].r, d == -1 ? -1 : snodes[d].r, m + 1, r, L, R); if (ret != -1) return ret; }
			assert(false);
		}
	} else {
		int m = l + (r - l) / 2;
		if (L <= m) { int ret = scalc(a == -1 ? -1 : snodes[a].l, b == -1 ? -1 : snodes[b].l, c == -1 ? -1 : snodes[c].l, d == -1 ? -1 : snodes[d].l, l, m, L, R); if (ret != -1) return ret; }
		if (m + 1 <= R) { int ret = scalc(a == -1 ? -1 : snodes[a].r, b == -1 ? -1 : snodes[b].r, c == -1 ? -1 : snodes[c].r, d == -1 ? -1 : snodes[d].r, m + 1, r, L, R); if (ret != -1) return ret; }
	}
	return -1;
}


int n, nq;
int kind[MAXN];
vector<int> adj[MAXN];
int qx[MAXQ], qy[MAXQ], ql[MAXQ], qr[MAXQ], qans[MAXQ];

ull key[MAXN];

int sroot[MAXN];
int par[MAXN], dep[MAXN];
int up[MAXN][MAXLG + 1];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	up[at][0] = par[at] == -1 ? at : par[at]; REP(k, MAXLG) up[at][k + 1] = up[up[at][k]][k];
	sroot[at] = par[at] == -1 ? -1 : sroot[par[at]];
	sroot[at] = smod(sroot[at], 0, n - 1, kind[at], key[kind[at]]);
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




void solve() {
	REP(i, n) key[i] = rnd();
	par[0] = -1; dfsinit(0);

	REP(i, nq) {
		int x = qx[i], y = qy[i], l = ql[i], r = qr[i];
		int z = calclca(x, y);
		qans[i] = scalc(sroot[x], sroot[y], sroot[z], par[z] == -1 ? -1 : sroot[par[z]], 0, n - 1, l, r);
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &kind[i]), --kind[i];
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	REP(i, nq) scanf("%d%d%d%d", &qx[i], &qy[i], &ql[i], &qr[i]), --qx[i], --qy[i], --ql[i], --qr[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i] == -1 ? -1 : qans[i] + 1);
}

int main() {
	run();
	return 0;
}