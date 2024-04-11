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

const int MAXN = 300000;
const int MAXQ = 300000;
const int MAXS = 4 * MAXN;

int n, nq;
int a[MAXN];
int ql[MAXQ], qr[MAXQ], qans[MAXQ];

int need[MAXN];
vector<int> qbyl[MAXN];

int sval[MAXS], sfirst[MAXS], slazy[MAXS];
void sapply(int x, int by) {
	if (sval[x] != INT_MAX) sval[x] += by;
	slazy[x] += by;
}
void spush(int x) {
	if (slazy[x] != 0) sapply(2 * x + 1, slazy[x]), sapply(2 * x + 2, slazy[x]), slazy[x] = 0;
}
void spull(int x) {
	sval[x] = min(sval[2 * x + 1], sval[2 * x + 2]);
	sfirst[x] = sval[2 * x + 1] == sval[x] ? sfirst[2 * x + 1] : sfirst[2 * x + 2];
}
void sinit(int x, int l, int r) {
	slazy[x] = 0;
	if (l == r) {
		sval[x] = need[l], sfirst[x] = l;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void smod(int x, int l, int r, int L, int R, int BY) {
	if (L <= l && r <= R) {
		sapply(x, BY);
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (L <= m) smod(2 * x + 1, l, m, L, R, BY);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, BY);
		spull(x);
	}
}
pair<int, int> sget(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return MP(sval[x], sfirst[x]);
	} else {
		int m = l + (r - l) / 2; spush(x); pair<int, int> ret = MP(INT_MAX, -1);
		if (L <= m) { pair<int, int> sub = sget(2 * x + 1, l, m, L, R); if (sub.first < ret.first) ret = sub; }
		if (m + 1 <= R) { pair<int, int> sub = sget(2 * x + 2, m + 1, r, L, R); if (sub.first < ret.first) ret = sub; }
		return ret;
	}
}
void skill(int x, int l, int r, int IDX) {
	if (l == r) {
		sval[x] = INT_MAX;
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (IDX <= m) skill(2 * x + 1, l, m, IDX);
		if (m + 1 <= IDX) skill(2 * x + 2, m + 1, r, IDX);
		spull(x);
	}
}

int bit[MAXN + 1];
void bmod(int idx, int by) { ++idx; while (idx <= n) { bit[idx] += by; idx += idx & -idx; } }
int bget(int idx) { int ret = 0; ++idx; while (idx > 0) { ret += bit[idx]; idx -= idx & -idx; } return ret; }

void solve() {
	REP(i, n) qbyl[i].clear();
	REP(i, nq) qbyl[ql[i]].PB(i);
	REP(i, n) {
		int x = a[i] - i;
		need[i] = x > 1 ? INT_MAX : 1 - x;
	}
	sinit(0, 0, n - 1);
	REPE(i, n) bit[i] = 0;
	for (int i = n - 1; i >= 0; --i) {
		while (true) {
			pair<int, int> res = sget(0, 0, n - 1, i, n - 1);
			if (res.first > 0) break;
			int idx = res.second;
			//printf("i=%d idx=%d\n", i, idx);
			bmod(idx, +1);
			skill(0, 0, n - 1, idx);
			if (idx != n - 1) smod(0, 0, n - 1, idx + 1, n - 1, -1);
		}
		REPSZ(j, qbyl[i]) {
			int id = qbyl[i][j];
			qans[id] = bget(n - qr[id] - 1);
		}
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]);
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}