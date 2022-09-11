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

const int MAXN = 200000;
const int MAXQ = 200000;
const int MAXS = 4 * MAXN;
struct SRes { int cnt, cost; SRes() {} SRes(int cnt, int cost) :cnt(cnt), cost(cost) {} };

int n, nq;
int scost[MAXN];
int qkind[MAXQ], qidx[MAXQ], qval[MAXQ], qans[MAXQ];

ll ssum[MAXS];
int smin[MAXS], smax[MAXS];
int slazy[MAXS];

void sapply(int x, int l, int r, int by) {
	//printf("sapply(%d,%d..%d,%d) [%d..%d]\n", x, l, r, by, smin[x], smax[x]);
	assert(smin[x] == smax[x] && slazy[x] <= by);
	ssum[x] += (ll)(r - l + 1) * (by - smin[x]);
	smin[x] = smax[x] = slazy[x] = by;
}
void spush(int x, int l, int m, int r) {
	if (slazy[x] != 0) sapply(2 * x + 1, l, m, slazy[x]), sapply(2 * x + 2, m + 1, r, slazy[x]), slazy[x] = 0;
}
void spull(int x) {
	//printf("pulling %d\n", x);
	smin[x] = min(smin[2 * x + 1], smin[2 * x + 2]);
	smax[x] = max(smax[2 * x + 1], smax[2 * x + 2]);
	ssum[x] = ssum[2 * x + 1] + ssum[2 * x + 2];
}
void sinit(int x, int l, int r) {
	slazy[x] = 0;
	if (l == r) {
		ssum[x] = smin[x] = smax[x] = scost[l];
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void smod(int x, int l, int r, int L, int R, int BY) {
	//printf("smod(%d,%d..%d,%d..%d,%d)\n", x, l, r, L, R, BY);
	if (smin[x] >= BY) return;
	if (L <= l && r <= R && smin[x] == smax[x]) {
		//printf("applying %d to %d..%d (was %d)\n", BY, l, r, smin[x]);
		sapply(x, l, r, BY);
	} else {
		int m = l + (r - l) / 2; spush(x, l, m, r);
		if (L <= m) smod(2 * x + 1, l, m, L, R, BY);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, BY);
		spull(x);
	}
}
SRes sget(int x, int l, int r, int L, int R, int have) {
	if (L > r || R < l || smin[x]>have) return SRes(0, 0);
	if (L <= l && r <= R && ssum[x] <= have) {
		//printf("have=%d -> %d..%d (sum=%lld)\n", have, l, r, ssum[x]);
		return SRes(r - l + 1, ssum[x]);
	} else {
		int m = l + (r - l) / 2; spush(x, l, m, r);
		SRes lres = sget(2 * x + 1, l, m, L, R, have);
		SRes rres = sget(2 * x + 2, m + 1, r, L, R, have - lres.cost);
		return SRes(lres.cnt + rres.cnt, lres.cost + rres.cost);
	}
}

void solve() {
	sinit(0, 0, n - 1);
	REP(i, nq) {
		if (qkind[i] == 1) {
			smod(0, 0, n - 1, 0, qidx[i], qval[i]);
		}
		if (qkind[i] == 2) {
			qans[i] = 0;
			int budget = qval[i];
			int at = qidx[i];
			SRes cur = sget(0, 0, n - 1, at, n - 1, budget);
			qans[i] = cur.cnt;
			/*while (true) {
				SRes cur = sget(0, 0, n - 1, at, n - 1, budget);
				if (cur.cnt == 0) break;
				qans[i] += cur.cnt;
				budget -= qans[i].cost;
			}*/
		}
	}

}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &scost[i]);
	REP(i, nq) scanf("%d%d%d", &qkind[i], &qidx[i], &qval[i]), --qidx[i];
	solve();
	REP(i, nq) if (qkind[i] == 2) printf("%d\n", qans[i]);
}

void stress() {
	REP(rep, 1000000) {
		n = rnd() % 5 + 1;
		nq = rnd() % 3 + 1;
		REP(i, n) scost[i] = rnd() % 100 + 1;
		sort(scost, scost + n);
		reverse(scost, scost + n);
		REP(i, nq) qkind[i] = rnd() % 2 + 1, qidx[i] = rnd() % n, qval[i] = rnd() % 100 + 1;
		printf("%d %d\n", n, nq); REP(i, n) { if (i != 0) printf(" "); printf("%d", scost[i]); } puts(""); REP(i, nq) printf("%d %d %d\n", qkind[i], qidx[i] + 1, qval[i]);
		solve();
		printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}