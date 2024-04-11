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


const int MAXN = 10000;
const int MAXM = 10000;
const int MAXSPECIAL = 10;
const int MAXQ = 200000;
const int MAXW = 25;

const int MAXGN = MAXN;
const int MAXGM = MAXM;

void myassert(bool cond) { assert(cond); }

typedef struct MF {
	int n, m;
	int ghead[MAXGN], gnxt[2 * MAXGM], gto[2 * MAXGM]; ll gcap[2 * MAXGM];
	void init(int _n) { n = _n, m = 0; REP(i, n) ghead[i] = -1; }
	void addedge(int a, int b, ll c) { gnxt[2 * m + 0] = ghead[a], ghead[a] = 2 * m + 0, gto[2 * m + 0] = b, gcap[2 * m + 0] = c; gnxt[2 * m + 1] = ghead[b], ghead[b] = 2 * m + 1, gto[2 * m + 1] = a, gcap[2 * m + 1] = 0; ++m; /*printf("%d->%d\n",a,b);*/ }
	int d[MAXGN];
	int q[MAXGN], qhead, qtail;
	int cur[MAXGN];
	ll dinic(int s, int t) {
		ll ret = 0; int niter = 0;
		while (true) {
			REP(i, n) d[i] = INT_MAX; qhead = qtail = 0; d[s] = 0, q[qhead++] = s;
			while (qtail < qhead && d[t] == INT_MAX) { int at = q[qtail++]; for (int x = ghead[at]; x != -1; x = gnxt[x]) { int to = gto[x]; if (gcap[x] == 0 || d[to] != INT_MAX) continue; d[to] = d[at] + 1; q[qhead++] = to; } }
			if (d[t] == INT_MAX) return ret;
			REP(i, n) cur[i] = ghead[i];
			ret += dfs(s, t, LLONG_MAX); ++niter;
		}
	}
	ll dfs(int at, int t, ll rem) {
		ll ret = 0; if (at == t) return rem;
		if (d[at] >= d[t]) return 0;
		for (; cur[at] != -1; cur[at] = gnxt[cur[at]]) {
			int to = gto[cur[at]]; ll cap = gcap[cur[at]]; if (d[to] != d[at] + 1 || cap == 0) continue;
			ll now = dfs(to, t, min(cap, rem));
			rem -= now; ret += now; if (gcap[cur[at]] != LLONG_MAX) gcap[cur[at]] -= now; if (gcap[cur[at] ^ 1] != LLONG_MAX) gcap[cur[at] ^ 1] += now; if (rem == 0) return ret;
		}
		return ret;
	}
	vector<int> findpath(int s, int t) {
		vector<int> ret;
		int at = s;
		while (at != t) {
			bool found = false;
			for (int x = ghead[at]; x != -1; x = gnxt[x]) {
				if (x % 2 != 0 || gcap[x ^ 1] == 0) continue;
				++gcap[x], --gcap[x ^ 1], found = true; at = gto[x]; ret.PB(x); break;
			}
			myassert(found);
		}
		return ret;
	}
	vector<int> findreversepath(int s, int t) {
		vector<int> ret;
		int at = t;
		while (at != s) {
			bool found = false;
			for (int x = ghead[at]; x != -1; x = gnxt[x]) {
				if (x % 2 != 1 || gcap[x] == 0) continue;
				--gcap[x], ++gcap[x ^ 1], found = true, at = gto[x], ret.PB(x ^ 1); break;
			}
			myassert(found);
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
} MF;



int n, m, nspecial, nq;
MF g;
int qval[MAXQ][MAXSPECIAL], qans[MAXQ];

int s, t;
int flowwith[1 << MAXSPECIAL];
int qsum[1 << MAXSPECIAL];

int bitcount[1 << MAXSPECIAL];
int currentflow;
bool active[MAXSPECIAL];

int calc(int mask) {
	int lo = 0, hi = INT_MAX;
	REP(done, 1 << nspecial) if(flowwith[done]!=-1) {
		if ((done&mask) == mask) {
			lo = max(lo, flowwith[done] - bitcount[done^mask] * MAXW);
			hi = min(hi, flowwith[done]);
		}
		if ((done&mask) == done) {
			lo = max(lo, flowwith[done]);
			hi = min(hi, flowwith[done] + bitcount[done^mask] * MAXW);
		}
	}
	if (lo == hi) return lo;

	REP(i, nspecial) if (mask&(1 << i)) {
		if (!active[i]) {
			assert(g.gcap[2 * i + 0] == 0 && g.gcap[2 * i + 1] == 0);
			g.gcap[2 * i + 0] = MAXW;
			active[i] = true;
		}
	} else {
		if (active[i]) {
			while (g.gcap[2 * i + 1] > 0) {
				int a = g.gto[2 * i + 1], b = g.gto[2 * i + 0];
				g.findreversepath(s, a); g.findpath(b, t); assert(g.gcap[2 * i + 1] > 0); --g.gcap[2 * i + 1]; ++g.gcap[2 * i + 0]; --currentflow;
			}
			assert(g.gcap[2 * i + 0] == MAXW);
			g.gcap[2 * i + 0] = 0;
			active[i] = false;
		}
	}
	currentflow += g.dinic(s, t);
	//printf("%x = %d\n", mask, currentflow);
	return currentflow;
}

void rec(int l, int r) {
	if (r - l <= 1) return;
	//printf("rec [%d..%d)\n", l, r);
	int m = l + (r - l) / 2;
	REP(mask, 1 << nspecial) if (bitcount[mask] == m) flowwith[mask] = calc(mask);
	rec(l, m);
	rec(m, r);
}


void solve() {
	s = 0, t = n - 1;
	int initflow = g.dinic(s, t);
	bitcount[0] = 0; FOR(mask, 1, 1 << nspecial) bitcount[mask] = bitcount[mask >> 1] + (mask & 1);
	currentflow = initflow;
	REP(i, nspecial) active[i] = false;
	REP(i, 1 << nspecial) flowwith[i] = -1;
	flowwith[0] = calc(0);
	flowwith[(1 << nspecial) - 1] = calc((1 << nspecial) - 1);
	rec(0, nspecial);

	REP(i, nq) {
		qsum[0] = 0; REP(bit, nspecial) REP(mask, 1 << bit) qsum[mask | (1 << bit)] = qsum[mask] + qval[i][bit];
		int cur = INT_MAX;
		REP(mask, 1 << nspecial) cur = min(cur, flowwith[(1 << nspecial) - mask - 1] + qsum[mask]);
		qans[i] = cur;
	}
}

void run() {
	scanf("%d%d%d%d", &n, &m, &nspecial, &nq);
	g.init(n);
	REP(i, m) { int a, b, c; scanf("%d%d%d", &a, &b, &c); --a, --b; g.addedge(a, b, c); }
	REP(i, nq) REP(j, nspecial) scanf("%d", &qval[i][j]);
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}