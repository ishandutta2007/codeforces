#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
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

const int MAXK = 10;
struct Op { char kind; int a, b, c; Op(int a, int b, int c) :kind('+'), a(a), b(b), c(c) {} Op(int a, int c) :kind('^'), a(a), b(-1), c(c) {} Op(int c) :kind('f'), c(c) {} };

int k, MOD;

int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret*x%MOD; if ((n >>= 1) == 0) return ret; x = (ll)x*x%MOD; } }

vector<Op> sol;

int nid;
int xid, yid, oneid, zeroid, mlttmpid;
int x_yid, xxid, yyid, xx_2xy_yyid, sqrtmpid1, sqrtmpid2;
int dectmpid, retid;

void mlt2(int aid) { sol.PB(Op(aid, aid, aid)); }
void inc(int aid, int bid) { sol.PB(Op(aid, bid, aid)); }
void set(int aid, int bid) { sol.PB(Op(bid, zeroid, aid)); }
void makezero() { // mlttmpid=1, zeroid=1
	assert(MOD % 2 == 1);
	for (int i = 1; (1 << i) <= MOD; ++i) { mlt2(mlttmpid); if (MOD&(1 << i)) inc(zeroid, mlttmpid); }
}

void mltconst(int aid, int b, int cid) {
	set(mlttmpid, aid); set(cid, zeroid);
	for (int i = 0; (1 << i) <= b; ++i) { if (i != 0) mlt2(mlttmpid); if (b&(1 << i)) inc(cid, mlttmpid); }
}
void dec(int aid, int bid) {
	mltconst(bid, MOD - 1, dectmpid);
	inc(aid, dectmpid);
}

int C[MAXK + 1][MAXK + 1];
int A[MAXK + 1][2 * (MAXK + 1)];

void gaussjord(int nrow, int ncol) {
	int r = 0, c = 0;
	while (r < nrow && c < ncol) {
		{ int rr = r; while (rr < nrow && A[rr][c] == 0) ++rr; if (rr >= nrow) { ++c; continue; } REP(cc, ncol) swap(A[r][c], A[rr][c]); }
		{ int mlt = pw(A[r][c], MOD - 2); REP(cc, ncol) A[r][cc] = (ll)A[r][cc] * mlt%MOD; }
		FOR(rr, r + 1, nrow) { int t = A[rr][c]; REP(cc, ncol) A[rr][cc] = (A[rr][cc] + MOD - (ll)t*A[r][cc] % MOD) % MOD; }
		++r, ++c;
	}
	while (--r >= 0) {
		c = 0; while (c < ncol&&A[r][c] == 0) ++c; assert(c < ncol);
		REP(rr,r) { int t = A[rr][c]; REP(cc, ncol) A[rr][cc] = (A[rr][cc] + MOD - (ll)t*A[r][cc] % MOD) % MOD; }
	}
}

void sqr(int aid, int cid) {
	set(cid, zeroid); set(sqrtmpid1, aid);
	REP(i, k + 1) {
		if (i != 0) inc(sqrtmpid1, oneid);
		sol.PB(Op(sqrtmpid1, sqrtmpid2));
		mltconst(sqrtmpid2, A[k - 2][k + 1 + i],sqrtmpid2);
		inc(cid, sqrtmpid2);
	}
}

void solve() {
	REP(i, k + 1) { C[i][0] = C[i][i] = 1; FOR(j, 1, i) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD; }
	REP(i, k + 1) { REP(j, k + 1) A[i][j] = (ll)C[k][j] * pw(i, j) % MOD; REP(j, k + 1) A[i][k + 1 + j] = i == j ? 1 : 0; }
	gaussjord(k + 1, 2 * (k + 1));
	//REP(i, k + 1) { printf("A%d:", i); REP(j, 2 * (k + 1)) printf(" %d", A[i][j]); puts(""); }

	nid = 0; sol.clear();
	xid = nid++; yid = nid++; x_yid = nid++; oneid = nid++; zeroid = nid++; mlttmpid = nid++;
	xxid = nid++; yyid = nid++; xx_2xy_yyid = nid++; sqrtmpid1 = nid++; sqrtmpid2 = nid++;
	dectmpid = nid++; retid = nid++;
	
	makezero();
	sol.PB(Op(xid, yid, x_yid));
	sqr(xid, xxid);
	sqr(yid, yyid);
	sqr(x_yid, xx_2xy_yyid);
	set(retid, xx_2xy_yyid);
	dec(retid, xxid);
	dec(retid, yyid);
	mltconst(retid, pw(2, MOD - 2), retid);
	sol.PB(Op(retid));
}

int simulate(int x, int y) {
	vector<int> state(nid, 1); state[xid] = x; state[yid] = y;
	REPSZ(i, sol) {
		if (sol[i].kind == '+') { int a = sol[i].a, b = sol[i].b, c = sol[i].c; state[c] = (state[a] + state[b]) % MOD; }
		if (sol[i].kind == '^') { int a = sol[i].a, c = sol[i].c; state[c] = pw(state[a], k); }
		if (sol[i].kind == 'f') { assert(i == SZ(sol) - 1); int c = sol[i].c; return state[c]; }
	}
	assert(false); return -1;
}

void verifysingle(int x,int y) {
	int have = simulate(x, y), want = (ll)x*y%MOD;
	if (have == want) { printf("."); return; }
	printf("err: %d*%d=%d but got %d\n", x, y, want, have); exit(0);
}

void verify() {
	int cnt = 0;
	REP(x, MOD) REP(y, MOD) {
		verifysingle(x, y);
		if (++cnt >= 10000) return;
	}
}

void run() {
	scanf("%d%d", &k, &MOD);
	solve();
	REPSZ(i, sol) {
		if (sol[i].kind == '+') printf("+ %d %d %d\n", sol[i].a + 1, sol[i].b + 1, sol[i].c + 1);
		if (sol[i].kind == '^') printf("^ %d %d\n", sol[i].a + 1, sol[i].c + 1);
		if (sol[i].kind == 'f') printf("f %d\n", sol[i].c + 1);
	}
	//fprintf(stderr, "%d lines\n", SZ(sol));
	//verify();
}

void stress() {
	for (MOD = 3;; ++MOD) {
		bool isp = MOD >= 2; for (int i = 2; i*i <= MOD; ++i) if (MOD%i == 0) { isp = false; break; } if (!isp) continue;
		for (k = 2; k <= MAXK; ++k) if (k < MOD) {
			printf("processing %d %d\n", k, MOD);
			solve();
			REP(i, k + 1) REP(j, k + 1) assert(A[i][j] == (i == j ? 1 : 0));
			verify();
		}
	}
}

void test() {
	int x, y; scanf("%d%d%d%d", &k, &MOD, &x, &y);
	solve();
	verifysingle(x, y);
}


int main() {
	run();
	//stress();
	//test();
	return 0;
}