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

const int MAXSEG = 200000;
const int MAXX = 2 * MAXSEG;
const int MAXNODE = 4 * MAXX;
struct Seg { int l, r, col; };
bool operator<(const Seg& a, const Seg& b) { return a.l < b.l; }

int nseg;
Seg seg[MAXSEG];

struct STree {
	int lazy[MAXNODE];
	int val[MAXNODE];
	void apply(int x, int by) { lazy[x] += by; val[x] += by; }
	void push(int x) { if (lazy[x] != 0) apply(2 * x + 1, lazy[x]), apply(2 * x + 2, lazy[x]), lazy[x] = 0; }
	void pull(int x) { val[x] = max(val[2 * x + 1], val[2 * x + 2]); }
	void init(int x, int l, int r) {
		lazy[x] = 0;
		if (l == r) {
			val[x] = 0;
		} else {
			int m = l + (r - l) / 2;
			init(2 * x + 1, l, m);
			init(2 * x + 2, m + 1, r);
			pull(x);
		}
	}
	void inc(int x, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			apply(x, 1);
		} else {
			int m = l + (r - l) / 2; push(x);
			if (L <= m) inc(2 * x + 1, l, m, L, R);
			if (m + 1 <= R) inc(2 * x + 2, m + 1, r, L, R);
			pull(x);
		}
	}
	void upd(int x, int l, int r, int IDX, int VAL) {
		if (l == r) {
			val[x] = max(val[x], VAL);
		} else {
			int m = l + (r - l) / 2; push(x);
			if (IDX <= m) upd(2 * x + 1, l, m, IDX, VAL); else upd(2 * x + 2, m + 1, r, IDX, VAL);
			pull(x);
		}
	}
	int get(int x, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			return val[x];
		} else {
			int m = l + (r - l) / 2; push(x); int ret = 0;
			if (L <= m) ret = max(ret, get(2 * x + 1, l, m, L, R));
			if (m + 1 <= R) ret = max(ret, get(2 * x + 2, m + 1, r, L, R));
			return ret;
		}
	}
};

int x[MAXX], nx;
STree tree[2];

int solve() {
	sort(seg, seg + nseg);
	nx = 0; REP(i, nseg) x[nx++] = seg[i].l, x[nx++] = seg[i].r; sort(x, x + nx); nx = unique(x, x + nx) - x; REP(i, nseg) seg[i].l = lower_bound(x, x + nx, seg[i].l) - x, seg[i].r = lower_bound(x, x + nx, seg[i].r) - x;
	REP(col, 2) tree[col].init(0, 0, nx - 1);
	REP(i, nseg) {
		int l = seg[i].l, r = seg[i].r, col = seg[i].col;
		if (r + 1 < nx) tree[col].inc(0, 0, nx - 1, r + 1, nx);
		int v1 = tree[col].get(0, 0, nx - 1, 0, r);
		int v2 = l - 1 >= 0 ? tree[1 - col].get(0, 0, nx - 1, 0, l - 1) : 0;
		//printf("%d %d %d (v1=%d v2=%d)\n", l, r, col, v1, v2);
		tree[col].upd(0, 0, nx - 1, r, max(v1, v2) + 1);
	}
	int ret = 0;
	REP(col, 2) ret = max(ret, tree[col].get(0, 0, nx - 1, 0, nx - 1));
	return ret;
}

void run() {
	scanf("%d", &nseg);
	REP(i, nseg) scanf("%d%d%d", &seg[i].l, &seg[i].r, &seg[i].col), --seg[i].col;
	printf("%d\n", solve());
}

Seg oseg[MAXSEG];

int solvestupid() {
	int ret = 0;
	REP(mask, 1 << nseg) {
		bool ok = true;
		int cur = 0; REP(i, nseg) if (mask & (1 << i)) ++cur;
		if (cur <= ret) continue;
		REP(i, nseg) if (mask & (1 << i)) FOR(j, i + 1, nseg) if (mask & (1 << j)) if (oseg[i].col != oseg[j].col && oseg[i].l <= oseg[j].r && oseg[j].l <= oseg[i].r) ok = false;
		if (ok) ret = cur;
	}
	return ret;
}


void stress() {
	REP(rep, 10000) {
		nseg = rnd() % 10 + 1;
		int rng = rnd() % 100 + 1;
		REP(i, nseg) { seg[i].l = rnd() % rng, seg[i].r = rnd() % rng, seg[i].col = rnd() % 2; if (seg[i].l > seg[i].r) swap(seg[i].l, seg[i].r); oseg[i] = seg[i]; }
		int have = solve();
		int want = solvestupid();
		if (have == want) { printf("."); continue; }
		printf("err have=%d want=%d\n", have, want);
		printf("%d\n", nseg);
		REP(i, nseg) printf("%d %d %d\n", oseg[i].l, oseg[i].r, oseg[i].col + 1);
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}