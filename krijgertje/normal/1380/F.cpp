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

const int MAXLEN = 500000;
const int MAXQ = 500000;
const int MAXS = 4 * MAXLEN;
const int MOD = 998244353;

int len, nq;
char init[MAXLEN + 1];
int qidx[MAXQ], qval[MAXQ], qans[MAXQ];


char cur[MAXLEN + 1];
int sval[MAXS][2][2];
int ways[100];

void smake(int x,int idx) {
	REP(a, 2) REP(b, 2) if (a == 1 && b == 1) sval[x][a][b] = 0; else if (a == 1 || b == 1) sval[x][a][b] = 1; else sval[x][a][b] = ways[cur[idx] - '0'];
	//printf("making [%d]: ", idx); REP(a, 2) REP(b, 2) printf(" %d", sval[x][a][b]); puts("");
}
void spull(int x,int l,int m,int r) {
	REP(a, 2) REP(b, 2) {
		int res = 0;
		REP(c, 2) {
			int lval = sval[2 * x + 1][a][c];
			int rval = sval[2 * x + 2][c][b];
			int mval = c == 0 ? 1 : cur[m] == '0' ? 0 : ways[10 * (cur[m] - '0') + (cur[m + 1] - '0')];
			res = (res + (ll)lval * rval % MOD * mval) % MOD;
			//printf("\t(%d,%d,%d): %d*%d*%d\n", a, b, c, lval, mval, rval);
		}
		sval[x][a][b] = res;
	}
	//printf("pulling [%d..%d]: ", l, r); REP(a, 2) REP(b, 2) printf(" %d", sval[x][a][b]); puts("");
}

void sinit(int x, int l, int r) {
	if (l == r) {
		smake(x, l);
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x, l, m, r);
	}
}

void supd(int x, int l, int r,int IDX) {
	if (l == r) {
		smake(x, IDX);
	} else {
		int m = l + (r - l) / 2;
		if (IDX <= m) supd(2 * x + 1, l, m, IDX); else supd(2 * x + 2, m + 1, r, IDX);
		spull(x, l, m, r);
	}
}

void solve() {
	REP(i, 100) ways[i] = 0;
	REP(a, 10) REP(b, 10) ++ways[a + b];
	REPE(i, len) cur[i] = init[i];
	sinit(0, 0, len - 1);
	REP(i, nq) {
		int idx = qidx[i], val = qval[i];
		cur[idx] = '0' + val;
		supd(0, 0, len - 1, idx);
		qans[i] = sval[0][0][0];
	}
}

void run() {
	scanf("%d%d", &len, &nq);
	scanf("%s", init); assert(strlen(init) == len);
	REP(i, nq) scanf("%d%d", &qidx[i], &qval[i]), --qidx[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}