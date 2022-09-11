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

const int MAXQ = 200000;
const int MAXY = 200000 + 200000;
const int MAXS = 4 * MAXY;

int sz, xspecial, nq;
int qx[MAXQ], qy[MAXQ], qans[MAXQ];

set<pair<int, int>> have;
multiset<int> exist;

int sval[MAXS];
int slazy[MAXS];

void sapply(int x, int by) { sval[x] += by; slazy[x] += by; }
void spush(int x) { if (slazy[x] != 0) sapply(2 * x + 1, slazy[x]), sapply(2 * x + 2, slazy[x]), slazy[x] = 0; }
void spull(int x) { sval[x] = max(sval[2 * x + 1], sval[2 * x + 2]); }

void sinit(int x, int l, int r) {
	slazy[x] = 0;
	if (l == r) {
		sval[x] = l;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m); sinit(2 * x + 2, m + 1, r);
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
int sget(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return sval[x];
	} else {
		int m = l + (r - l) / 2; spush(x); int ret = 0;
		if (L <= m) ret = max(ret, sget(2 * x + 1, l, m, L, R));
		if (m + 1 <= R) ret = max(ret, sget(2 * x + 2, m + 1, r, L, R));
		return ret;
	}
}

void solve() {
	sinit(0, 0, 2 * sz - 1);
	have.clear(); exist.clear();

	REP(i, nq) {
		pair<int, int> cur = MP(qx[i], qy[i]);
		int y = qy[i] + abs(qx[i] - xspecial);
		if (!have.count(cur)) {
			//printf("add %d\n", y);
			smod(0, 0, 2 * sz - 1, 0, y, +1);
			have.insert(cur); exist.insert(y);
		} else {
			//printf("remove %d\n", y);
			smod(0, 0, 2 * sz - 1, 0, y, -1);
			have.erase(cur); exist.erase(exist.find(y));
		}
		if (SZ(exist) == 0) {
			qans[i] = sz;
		} else {
			int mx = *prev(exist.end());
			qans[i] = max(sz, sget(0, 0, 2 * sz - 1, 0, mx));
			//printf("%d: mx=%d sget=%d\n", i, mx, sget(0, 0, 2 * sz - 1, 0, mx));
		}
		qans[i] -= sz;
	}
}

void run() {
	scanf("%d%d%d", &sz, &xspecial, &nq), --xspecial;
	REP(i, nq) scanf("%d%d", &qx[i], &qy[i]), --qx[i], --qy[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}