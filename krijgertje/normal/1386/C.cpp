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
const int MAXM = 200000;
const int MAXQ = 200000;

int n, m, nq;
int e[MAXM][2];
int ql[MAXQ], qr[MAXQ]; bool qoddcyc[MAXQ];
vector<int> qbyl[MAXM];

int par[MAXN], sz[MAXN], diff[MAXN];
vector<int> changes;

pair<int, int> uffind(int x) { if (par[x] == x) return MP(x, 0); pair<int, int> ret = uffind(par[x]); ret.second ^= diff[x]; return ret; }

bool addedge(int id) {
	int x = e[id][0], y = e[id][1];
	int xdiff, ydiff; tie(x, xdiff) = uffind(x); tie(y, ydiff) = uffind(y);
	if (x == y) return xdiff != ydiff;
	if (sz[x] < sz[y]) swap(x, y), swap(xdiff, ydiff);
	par[y] = x, sz[x] += sz[y], diff[y] = xdiff ^ ydiff ^ 1, changes.PB(y);
	return true;
}
int savepoint() {
	return SZ(changes);
}
void restore(int t) {
	while (SZ(changes) > t) {
		int y = changes.back(); changes.pop_back(); int x = par[y];
		assert(x != y && par[x] == x);
		par[y] = y, sz[x] -= sz[y], diff[y] = 0;
	}
}

// answer queries for llo <= ql < lhi
// assuming edges < llo and >= rhi have already been added, not resulting in an odd cyc
// assuming edges < rlo could never be added any way
void rec(int llo, int lhi, int rlo, int rhi) {
	if (llo == lhi) return;
	int lmi = llo + (lhi - llo) / 2;
	int t1 = savepoint();
	bool ok = true;
	FOR(i, llo, lmi) if (!addedge(i)) { ok = false; break; }
	if (!ok) {
		FOR(i, lmi, lhi) REPSZ(j, qbyl[i]) { int id = qbyl[i][j]; qoddcyc[id] = true; }
		restore(t1);
		rec(llo, lmi, rlo, rhi);
		return;
	}
	int t2 = savepoint();
	int	rmi = rhi;
	while (rmi > lmi && rmi > rlo) if (addedge(rmi - 1)) --rmi; else break;
	REPSZ(j, qbyl[lmi]) { int id = qbyl[lmi][j]; qoddcyc[id] = qr[id] < rmi; }
	restore(t2);
	if (!addedge(lmi)) {
		FOR(i, lmi + 1, lhi) REPSZ(j, qbyl[i]) { int id = qbyl[i][j]; qoddcyc[id] = true; }
	} else {
		rec(lmi + 1, lhi, rmi, rhi);
	}
	restore(t1);
	FOR(i, rmi, rhi) assert(addedge(i));
	rec(llo, lmi, rlo, rmi);
	restore(t1);
}

void solve() {
	REP(i, m) qbyl[i].clear();
	REP(i, nq) qbyl[ql[i]].PB(i);
	REP(i, n) par[i] = i, sz[i] = 1, diff[i] = 0;
	changes.clear();
	rec(0, m, 0, m);

}

void run() {
	scanf("%d%d%d", &n, &m, &nq);
	REP(i, m) REP(j, 2) scanf("%d", &e[i][j]), --e[i][j];
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]), --ql[i];
	solve();
	REP(i, nq) printf("%s\n", qoddcyc[i] ? "YES" : "NO");
}

int main() {
	run();
	return 0;
}