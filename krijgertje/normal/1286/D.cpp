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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 100000;
const int MOD = 998244353;
const int MAXS = 4 * MAXN;

int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret*x%MOD; if ((n >>= 1) == 0) return ret; x = (ll)x*x%MOD; } }

int n;
int x[MAXN], v[MAXN], perc[MAXN];

struct E {
	int num, den, pos, mask;
	E() {} E(int num, int den, int pos, int mask) :num(num), den(den), pos(pos), mask(mask) {}
};
bool operator<(const E &a, const E &b) { return (ll)a.num*b.den < (ll)b.num*a.den; }

vector<E> e;

bool can[MAXN - 1][4];
int pl[MAXN], pr[MAXN];
int sval[MAXS][2][2];

void spull(int x, int opt) {
	//printf("pulling %d %d\n", x, opt);
	REP(a, 2) REP(d, 2) sval[x][a][d] = 0;
	REP(a, 2) REP(b, 2) REP(c, 2) REP(d, 2) if (can[opt][b + 2 * c]) sval[x][a][d] = (sval[x][a][d] + (ll)sval[2 * x + 1][a][b] * sval[2 * x + 2][c][d]) % MOD;
}
void sinit(int x, int l, int r) {
	if (l == r) {
		sval[x][0][0] = pl[l], sval[x][1][1] = pr[l], sval[x][0][1] = sval[x][1][0] = 0;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m); sinit(2 * x + 2, m + 1, r);
		spull(x, m);
	}
	//printf("[%d..%d]:", l, r); REP(a, 2) REP(b, 2) printf(" %d", sval[x][a][b]); puts("");
}
void supd(int x, int l, int r, int POS) {
	if (l < r) {
		int m = l + (r - l) / 2;
		if (POS < m) supd(2 * x + 1, l, m, POS);
		if (POS >= m + 1) supd(2 * x + 2, m + 1, r, POS);
		spull(x, m);
	}
}

int solve() {
	e.clear();
	REP(i, n - 1) {
		e.PB(E(x[i + 1] - x[i], v[i] + v[i + 1], i, 1));
		if (v[i] > v[i + 1]) e.PB(E(x[i + 1] - x[i], v[i] - v[i + 1], i, 3));
		if (v[i + 1] > v[i]) e.PB(E(x[i + 1] - x[i], v[i + 1] - v[i], i, 0));
	}
	sort(e.begin(), e.end());

	int inv100 = pw(100, MOD - 2);
	REP(i, n) pr[i] = (ll)perc[i] * inv100%MOD, pl[i] = (1 + MOD - pr[i]) % MOD;
	REP(i, n - 1) REP(j, 4) can[i][j] = true;
	sinit(0, 0, n - 1);

	int cprob = 1;
	int ret = 0;
	REPSZ(i, e) {
		//printf("processing forbidding %d at pos %d (t=%d/%d)\n", e[i].mask, e[i].pos, e[i].num, e[i].den);
		can[e[i].pos][e[i].mask] = false;
		supd(0, 0, n - 1, e[i].pos);
		int nprob = 0; REP(a, 2) REP(b, 2) nprob = (nprob + sval[0][a][b]) % MOD;
		int dprob = (cprob + MOD - nprob) % MOD;
		int t = (ll)e[i].num*pw(e[i].den, MOD - 2) % MOD;
		ret = (ret + (ll)dprob*t) % MOD;
		//printf("nprob=%d\n", nprob);
		cprob = nprob;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d%d", &x[i], &v[i], &perc[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}