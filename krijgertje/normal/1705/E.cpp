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
const int MAXLGN = 17;
const int MAXQ = 200000;
const int MAXSVAL = 200000;
const int MAXTVAL = MAXSVAL + MAXLGN;
const int MAXS = 4 * MAXTVAL;

int n, nq;
int a[MAXN];
int qidx[MAXQ], qval[MAXQ];
int qans[MAXQ];

int cur[MAXN];

int scntzero[MAXS], scntone[MAXS];
int smxzero[MAXS], smxone[MAXS];
int lazyval[MAXS];

void sapply(int x, int val) {
	int cnt = scntzero[x] + scntone[x], mx = max(smxzero[x], smxone[x]);
	scntzero[x] = val == 0 ? cnt : 0;
	scntone[x] = val == 1 ? cnt : 0;
	smxzero[x] = val == 0 ? mx : INT_MIN;
	smxone[x] = val == 1 ? mx : INT_MIN;
	lazyval[x] = val;
}
void spush(int x) {
	if (lazyval[x] != -1) sapply(2 * x + 1, lazyval[x]), sapply(2 * x + 2, lazyval[x]), lazyval[x] = -1;
}
void spull(int x) {
	scntzero[x] = scntzero[2 * x + 1] + scntzero[2 * x + 2];
	scntone[x] = scntone[2 * x + 1] + scntone[2 * x + 2];
	smxzero[x] = max(smxzero[2 * x + 1], smxzero[2 * x + 2]);
	smxone[x] = max(smxone[2 * x + 1], smxone[2 * x + 2]);
}
void sinit(int x, int l, int r) {
	lazyval[x] = -1;
	if (l == r) {
		scntzero[x] = 1, scntone[x] = 0, smxzero[x] = l, smxone[x] = INT_MIN;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void smod(int x, int l, int r, int L, int R, int VAL) {
	if (L <= l && r <= R) {
		sapply(x, VAL);
	} else {
		int m = l + (r - l) / 2;
		spush(x);
		if (L <= m) smod(2 * x + 1, l, m, L, R, VAL);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, VAL);
		spull(x);
	}
}
int sget(int x, int l, int r, int L, int VAL) {
	if (VAL == 0 && scntzero[x] == 0) return INT_MAX;
	if (VAL == 1 && scntone[x] == 0) return INT_MAX;
	if (l == r) return l;
	int m = l + (r - l) / 2;
	spush(x);
	int ret = INT_MAX;
	if (ret == INT_MAX && L <= m) ret = sget(2 * x + 1, l, m, L, VAL);
	if (ret == INT_MAX) ret = sget(2 * x + 2, m + 1, r, L, VAL);
	return ret;
}

void addval(int v) {
	//printf("\tadding %d\n", v);
	int zero = sget(0, 1, MAXTVAL, v, 0);
	//printf("\t->zero at %d\n", zero);
	if (v < zero) smod(0, 1, MAXTVAL, v, zero - 1, 0);
	smod(0, 1, MAXTVAL, zero, zero, 1);
}
void remval(int v) {
	//printf("\tremoving %d\n", v);
	int one = sget(0, 1, MAXTVAL, v, 1);
	//printf("\t->one at %d\n", one);
	if (v < one) smod(0, 1, MAXTVAL, v, one - 1, 1);
	smod(0, 1, MAXTVAL, one, one, 0);
}
void debug() {
	int at = 1;
	printf("state:");
	while (at <= MAXTVAL) {
		at = sget(0, 1, MAXTVAL, at, 1);
		if (at == INT_MAX) break;
		printf(" %d", at);
		++at;
	}
	puts("");
}

void solve() {
	sinit(0, 1, MAXTVAL);
	REP(i, n) addval(a[i]);
	REP(i, n) cur[i] = a[i];
	REP(i, nq) {
		int idx = qidx[i];
		remval(cur[idx]);
		//debug();
		cur[idx] = qval[i];
		addval(cur[idx]);
		//debug();
		qans[i] = smxone[0];
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, nq) scanf("%d%d", &qidx[i], &qval[i]), --qidx[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}