#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 2000;
const int MAXM = 10000;
const int MAXROWS = MAXN;
const int MAXCOLS = MAXN + 1;
const int MAXWORDS = (MAXCOLS + 63) / 64;

struct BinaryGaussJord {
	int R, C, W;
	ull A[MAXROWS][MAXWORDS];
	void init(int _R, int _C) {
		R = _R, C = _C, W = (C + 63) / 64;
		REP(r, R) REP(w, W) A[r][w] = 0;
	}
	void toggle(int r, int c) { A[r][c / 64] ^= 1LL << (c % 64); }
	bool isset(int r, int c) { return ((A[r][c / 64] >> (c % 64)) & 1) != 0; }
	void solve() {
		int r = 0, c = 0;
		//printf("before\n"); REP(r, R) { REP(c, C) printf("%d", isset(r, c) ? 1 : 0); puts(""); }
		while (r < R && c < C) {
			{ int rr = r; while (rr < R && !isset(rr, c)) ++rr; if (rr >= R) { ++c; continue; } if (rr != r) REP(w, W) swap(A[r][w], A[rr][w]); }
			FOR(rr, r + 1, R) if (isset(rr, c)) REP(w, W) A[rr][w] ^= A[r][w];
			++r, ++c;
		}
		//printf("between\n"); REP(r, R) { REP(c, C) printf("%d", isset(r, c) ? 1 : 0); puts(""); }
		while (--r >= 0) {
			c = 0; while (c < C && !isset(r, c)) ++c; assert(c < C);
			REP(rr, r) if (isset(rr, c)) REP(w, W) A[rr][w] ^= A[r][w];
		}
		//printf("after\n"); REP(r, R) { REP(c, C) printf("%d", isset(r, c) ? 1 : 0); puts(""); }
	}
};

int n, m;
vector<int> adj[MAXN];
int ans[MAXN], nans;

BinaryGaussJord mat;

void solve() {
	bool alleven = true; REP(i, n) if (SZ(adj[i]) % 2 != 0) alleven = false;
	if (alleven) { nans = 1; REP(i, n) ans[i] = 0; return; }

	mat.init(n, n + 1);
	REP(i, n) REPSZ(j, adj[i]) { int k = adj[i][j]; mat.toggle(i, k); }
	REP(i, n) if (SZ(adj[i]) % 2 != 0) mat.toggle(i, i), mat.toggle(i, n);
	mat.solve();

	nans = 2; REP(i, n) ans[i] = 0;
	REP(i, n) { int idx = -1; REP(j, n) if (mat.isset(i, j) && idx == -1) idx = j; if (mat.isset(i, n)) { assert(idx != -1 && ans[idx] == 0); ans[idx] = 1; } }
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	solve();
	printf("%d\n", nans); REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
	REP(i, n) adj[i].clear();
}

int main() {
	int n; scanf("%d", &n); FORE(i, 1, n) run();
	return 0;
}