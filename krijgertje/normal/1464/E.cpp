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

const int MOD = 998244353;
const int MAXN = 100000;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int& a, int b) { inc(a, MOD - b); }
int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret * x % MOD; if ((n >>= 1) == 0) return ret; x = (ll)x * x % MOD; } }

int n, m;
vector<int> out[MAXN];
vector<int> in[MAXN];

int g[MAXN];
int deg[MAXN];
queue<int> q;

int inv[MAXN + 2];
int mark[MAXN + 1];


void gaussjord(vector<vector<int>>& A) {
	int R = SZ(A), C = SZ(A[0]);
	int r = 0, c = 0;
	while (r < R && c < C) {
		{ int rr = r; while (rr < R && A[rr][c] == 0) ++rr; if (rr >= R) { ++c; continue; } REP(cc, C) swap(A[r][cc], A[rr][cc]); }
		{ int mlt = pw(A[r][c], MOD - 2); REP(cc, C) A[r][cc] = (ll)A[r][cc] * mlt % MOD; }
		FOR(rr, r + 1, R) { int times = A[rr][c]; REP(cc, C) dec(A[rr][cc], (ll)times * A[r][cc] % MOD); }
		++r, ++c;
	}
	while (--r >= 0) {
		c = 0; while (c < C && A[r][c] == 0) ++c; assert(c < C&& A[r][c] == 1);
		REP(rr, r) { int times = A[rr][c]; REP(cc, C) dec(A[rr][cc], (ll)times * A[r][cc] % MOD); }
	}
}


int solve() {
	inv[1] = 1; FORE(i, 2, n + 1) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;

	REP(i, n) g[i] = -1, deg[i] = SZ(out[i]);
	q = queue<int>();
	REP(i, n) if (deg[i] == 0) q.push(i);
	REPE(i, n) mark[i] = -1;
	while (!q.empty()) {
		int at = q.front(); q.pop();
		REPSZ(i, out[at]) { int to = out[at][i]; mark[g[to]] = at; }
		g[at] = 0;
		while (mark[g[at]] == at) ++g[at];
		REPSZ(i, in[at]) { int to = in[at][i]; if (--deg[to] == 0) q.push(to); }
	}
	//printf("g:"); REP(i, n) printf(" %d", g[i]); puts("");

	int gmx = 0; REP(i, n) gmx = max(gmx, g[i]);
	int lim = 1; while (gmx >= lim) lim *= 2;

	vector<int> cnt(gmx + 1);
	REP(i, n) ++cnt[g[i]];

	vector<vector<int>> A(lim, vector<int>(lim + 1, 0));
	REP(at, lim) {
		inc(A[at][at], 1);
		REPE(i, gmx) {
			int to = at ^ i;
			dec(A[at][to], (ll)cnt[i] * inv[n + 1] % MOD);
		}
		if (at != 0) inc(A[at][lim], inv[n + 1]);
	}
	gaussjord(A);
	//REP(i, lim) { printf("A%d:", i); REPE(j, lim) printf(" %d", A[i][j]); puts(""); }
	return A[0][lim];
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; out[a].PB(b); in[b].PB(a); }
	printf("%d\n", solve());

}

int main() {
	run();
	return 0;
}