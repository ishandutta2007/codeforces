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

const int MAXN = 200000;
const int MAXQ = 200000;
const int MAXS = 4 * MAXN;

int n, nq;
int a, b;
int vinit[MAXN];
int qkind[MAXQ], qidx[MAXQ], qv[MAXQ], ql[MAXQ], qr[MAXQ];
double qans[MAXQ];

const int ZERO = 0;
const int ONEOVERAB = 1;
const int ONEOVERA = 2;

struct SVal { ll sum[3][3]; };

SVal sval[MAXS];
SVal smake(int v) {
	SVal ret;
	REP(i, 3) REP(j, 3) ret.sum[i][j] = 0;
	ret.sum[ONEOVERAB][ONEOVERAB] = (ll)a * v;
	ret.sum[ONEOVERA][ONEOVERA] = (ll)(a + b) * v;
	return ret;
}
SVal smerge(const SVal& a, const SVal& b) {
	SVal ret;
	REP(i, 3) REP(j, 3) {
		ret.sum[i][j] = 0;
		REP(ii, 3) REP(jj, 3) {
			if (ii == ONEOVERAB && jj == ONEOVERA) continue;
			if (ii == ONEOVERA && jj == ONEOVERAB) continue;
			if (ii == ONEOVERA && jj == ONEOVERA) continue;
			ret.sum[i][j] = max(ret.sum[i][j], a.sum[i][ii] + b.sum[jj][j]);
		}
	}
	return ret;
}
void spull(int x) {
	sval[x] = smerge(sval[2 * x + 1], sval[2 * x + 2]);
}
void sinit(int x, int l, int r) {
	if (l == r) {
		sval[x] = smake(vinit[l]);
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void smod(int x, int l, int r, int IDX, int V) {
	if (l == r) {
		sval[x] = smake(V);
	} else {
		int m = l + (r - l) / 2;
		if (IDX <= m) smod(2 * x + 1, l, m, IDX, V); else smod(2 * x + 2, m + 1, r, IDX, V);
		spull(x);
	}
}
SVal sget(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return sval[x];
	} else {
		int m = l + (r - l) / 2;
		if (m + 1 > R) return sget(2 * x + 1, l, m, L, R);
		else if (L > m) return sget(2 * x + 2, m + 1, r, L, R);
		else return smerge(sget(2 * x + 1, l, m, L, R), sget(2 * x + 2, m + 1, r, L, R));
	}
}

void solve() {
	if (a < b) swap(a, b);
	sinit(0, 0, n - 1);
	REP(i, nq) {
		if (qkind[i] == 1) {
			smod(0, 0, n - 1, qidx[i], qv[i]);
		}
		if (qkind[i] == 2) {
			SVal res = sget(0, 0, n - 1, ql[i], qr[i]);
			ll best = 0;
			REP(j, 3) REP(k, 3) best = max(best, res.sum[j][k]);
			qans[i] = 1.0 * best / a / (a + b);
		}
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	scanf("%d%d", &a, &b);
	REP(i, n) scanf("%d", &vinit[i]);
	REP(i, nq) {
		scanf("%d", &qkind[i]);
		if (qkind[i] == 1) scanf("%d%d", &qidx[i], &qv[i]), --qidx[i];
		if (qkind[i] == 2) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	}
	solve();
	REP(i, nq) if (qkind[i] == 2) printf("%.15lf\n", qans[i]);

}

int main() {
	run();
	return 0;
}