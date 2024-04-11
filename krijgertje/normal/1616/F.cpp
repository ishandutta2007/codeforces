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

const int MAXN = 64;
const int MAXM = 256;
struct Tri { int edges[3]; };
struct Edge { int a, b, scol; };

int n, m;
Edge e[MAXM];
int ans[MAXM];

int g[MAXN][MAXN];
vector<Tri> tri;

int e2col[MAXM];
int ncol;


int inv[] = { 0,1,2 };
void inc(int &a, int b) { if ((a += b) >= 3) a -= 3; }
void dec(int &a, int b) { if ((a -= b) < 0) a += 3; }

void gaussjord(vector<vector<int>> &A) {
	if (SZ(A) == 0) return;
	int R = SZ(A), C = SZ(A[0]);
	int r = 0, c = 0;
	//REP(r, R) { printf("A[%d]:", r); REP(c, C) printf(" %d", A[r][c]); puts(""); }
	while (r < R && c < C) {
		FOR(rr, r, R) if (A[rr][c] != 0) { FOR(cc, c, C) swap(A[r][cc], A[rr][cc]); break; } if (A[r][c] == 0) { ++c; continue; }
		{ int mlt = inv[A[r][c]]; FOR(cc, c, C) A[r][cc] = A[r][cc] * mlt % 3; }
		FOR(rr, r + 1, R) if (A[rr][c] != 0) { int t = A[rr][c]; FOR(cc, c, C) A[rr][cc] = (A[rr][cc] + (3 - t)*A[r][cc]) % 3; }
		++r, ++c;
	}
	while (--r) {
		c = 0; while (A[r][c] == 0) ++c;
		REP(rr, r) if (A[rr][c] != 0) { int t = A[rr][c]; FOR(cc, c, C) A[rr][cc] = (A[rr][cc] + (3 - t)*A[r][cc]) % 3; }
	}
	//REP(r, R) { printf("A[%d]:", r); REP(c, C) printf(" %d", A[r][c]); puts(""); }
}

bool solve() {
	REP(i, n) REP(j, n) g[i][j] = -1;
	REP(i, m) { int a = e[i].a, b = e[i].b; g[a][b] = g[b][a] = i; }
	tri.clear();
	REP(a, n) FOR(b, a + 1, n) FOR(c, b + 1, n) if (g[a][b] != -1 && g[b][c] != -1 && g[c][a] != -1) {
		int x = g[a][b], y = g[b][c], z = g[c][a];
		Tri t; t.edges[0] = x, t.edges[1] = y, t.edges[2] = z;
		tri.PB(t);
	}

	ncol = 0;
	REP(i, m) e2col[i] = -1;
	REP(i, m) ans[i] = e[i].scol;
	REP(i, m) if (ans[i] == -1) e2col[i] = ncol++;

	vector<vector<int>> A(SZ(tri), vector<int>(ncol + 1, 0));
	REPSZ(i, tri) {
		int x = tri[i].edges[0], y = tri[i].edges[1], z = tri[i].edges[2];
		if (ans[x] == -1) inc(A[i][e2col[x]], 1); else dec(A[i][ncol], ans[x]);
		if (ans[y] == -1) inc(A[i][e2col[y]], 1); else dec(A[i][ncol], ans[y]);
		if (ans[z] == -1) inc(A[i][e2col[z]], 1); else dec(A[i][ncol], ans[z]);
	}
	gaussjord(A);
	vector<int> val(ncol, 0);
	REPSZ(i, tri) {
		int idx = -1;
		REPE(j, ncol) if (A[i][j] != 0) { idx = j; break; }
		if (idx == -1) continue;
		if (idx == ncol) return false;
		val[idx] = A[i][ncol];
	}
	REP(i, m) if (ans[i] == -1) ans[i] = val[e2col[i]];
	return true;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].scol), --e[i].a, --e[i].b;
	REP(i, m) if (e[i].scol != -1) --e[i].scol;
	if (!solve()) { printf("-1\n"); return; }
	REP(i, m) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}