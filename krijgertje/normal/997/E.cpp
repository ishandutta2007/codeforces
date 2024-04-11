#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 120000;
const int MAXQ = 120000;
const int MAXB = MAXN;
const int MAXS = 4 * MAXN;

int n;
int a[MAXN];
int nq;
int ql[MAXQ], qr[MAXQ];
ll qans[MAXQ];

// do a sqrt-decomposition to get all segments with r<floor(r/k)*k
// use segment tree for the (less than k) remaining r's
// -> n*(n/k)+n*k+n*log(n)+q*k*log(n) -> k=sqrt(n*n/(n+q*log(n)))

int bsz, nb;
int bhist[MAXB];
int bmx[MAXB], bmxcnt[MAXB];
int bval[MAXN], blazy[MAXB];

void bpush(int b) {
	for (int i = b*bsz; i < (b + 1)*bsz && i < n; ++i) bval[i] += blazy[b];
	blazy[b] = 0;
}
void bpull(int b) {
	bmx[b] = INT_MIN, bmxcnt[b] = 0;
	for (int i = b*bsz; i < (b + 1)*bsz && i < n; ++i) if (bval[i] > bmx[b]) bmx[b] = bval[i], bmxcnt[b] = 1; else if (bval[i] == bmx[b]) ++bmxcnt[b];
}
void bmod(int l, int r, int by) {
	if (l%bsz != 0) {
		int b = l / bsz;
		bpush(b);
		while (l <= r && l%bsz != 0) bval[l] += by, ++l;
		bpull(b);
		if (l > r) return;
	}
	if (r%bsz != bsz - 1) {
		int b = r / bsz;
		bpush(b);
		while (l <= r && r%bsz != bsz - 1) bval[r] += by, --r;
		bpull(b);
		if (l > r) return;
	}
	FORE(b, l / bsz, r / bsz) blazy[b] += by;
}
void brec(int l, int r) {
	if (l%bsz != 0) {
		int b = l / bsz;
		bpush(b);
		while (l <= r && l%bsz != 0) bhist[b] += bval[l] == 0 ? 1 : 0, ++l;
		bpull(b);
		if (l > r) return;
	}
	if (r%bsz != bsz - 1) {
		int b = r / bsz;
		bpush(b);
		while (l <= r && r%bsz != bsz - 1) bhist[b] += bval[r] == 0 ? 1 : 0, --r;
		bpull(b);
		if (l > r) return;
	}
	FORE(b, l / bsz, r / bsz) if (bmx[b] + blazy[b] == 0) bhist[b] += bmxcnt[b];
}

int smx[MAXS], scnt[MAXS], slazy[MAXS];

void sapply(int x, int by) {
	smx[x] += by, slazy[x] += by;
}
void spush(int x) {
	if (slazy[x] != 0) sapply(2 * x + 1, slazy[x]), sapply(2 * x + 2, slazy[x]), slazy[x] = 0;
}
void spull(int x) {
	smx[x] = max(smx[2 * x + 1], smx[2 * x + 2]);
	scnt[x] = (smx[2 * x + 1] == smx[x] ? scnt[2 * x + 1] : 0) + (smx[2 * x + 2] == smx[x] ? scnt[2 * x + 2] : 0);
}
void sinit(int x, int l, int r) {
	slazy[x] = 0;
	if (l == r) {
		smx[x] = 0, scnt[x] = 1;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void smod(int x, int l, int r, int L, int R, int BY) {
	//printf("smod(%d,%d..%d,%d..%d,by %d)\n", x, l, r, L, R, BY);
	if (L <= l&&r <= R) {
		sapply(x, BY);
	} else {
		spush(x);
		int m = l + (r - l) / 2;
		if (L <= m) smod(2 * x + 1, l, m, L, R, BY);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, BY);
		spull(x);
	}
}
int sget(int x, int l, int r, int L, int R) {
	//printf("sget(%d,%d..%d,%d..%d) mx=%d cnt=%d lazy=%d\n", x, l, r, L, R, smx[x], scnt[x], slazy[x]);
	if (L <= l&&r <= R) {
		return smx[x] == 0 ? scnt[x] : 0;
	} else {
		spush(x);
		int m = l + (r - l) / 2;
		int ret = 0;
		if (L <= m) ret += sget(2 * x + 1, l, m, L, R);
		if (m + 1 <= R) ret += sget(2 * x + 2, m + 1, r, L, R);
		spull(x);
		return ret;
	}
}


int mn[MAXN], nmn;
int mx[MAXN], nmx;
vector<int> qlft[MAXN];
vector<int> qrgt[MAXN];

void solve() {
	REP(i, n) qlft[i].clear(), qrgt[i].clear();
	bsz = (int)ceil(sqrt(1.0*n*n / (n + nq*log(n) / log(2))));
	nb = (n + bsz - 1) / bsz;
	REP(i, nq) qlft[ql[i]].PB(i);
	REP(i, nq) FORE(r, (qr[i] + 1) / bsz * bsz, qr[i]) qrgt[r].PB(i);
	REP(i, nq) qans[i] = 0;
	//printf("bsz=%d\n", bsz);

	// keep r-l-max+min
	nmn = nmx = 0;
	REP(i, n) bval[i] = 0; REP(b, nb) blazy[b] = bhist[b] = 0, bpull(b);
	for (int i = n - 1; i >= 0; --i) {
		while (nmn > 0 && a[mn[nmn - 1]] > a[i]) bmod(mn[nmn - 1], nmn == 1 ? n - 1 : mn[nmn - 2] - 1, a[i] - a[mn[nmn - 1]]), --nmn;
		while (nmx > 0 && a[mx[nmx - 1]] < a[i]) bmod(mx[nmx - 1], nmx == 1 ? n - 1 : mx[nmx - 2] - 1, a[mx[nmx - 1]] - a[i]), --nmx;
		if (i != n - 1) bmod(i + 1, n - 1, 1);
		mn[nmn++] = i, mx[nmx++] = i;
		brec(i, n - 1);
		//printf("after%d:",i); REP(b, nb) printf(" %d*%d", bmxcnt[b], bmx[b]); puts("");
		REPSZ(j, qlft[i]) { int id = qlft[i][j]; REP(b, (qr[id] + 1) / bsz) qans[id] += bhist[b]/*, printf("b%d:%d\n", b, bhist[b])*/; }
	}
	//printf("between:"); REP(i, nq) printf(" %lld", qans[i]); puts("");

	nmn = nmx = 0;
	sinit(0, 0, n - 1);
	REP(i, n) {
		while (nmn > 0 && a[mn[nmn - 1]] > a[i]) smod(0, 0, n - 1, nmn == 1 ? 0 : mn[nmn - 2] + 1, mn[nmn - 1], a[i] - a[mn[nmn - 1]]), --nmn;
		while (nmx > 0 && a[mx[nmx - 1]] < a[i]) smod(0, 0, n - 1, nmx == 1 ? 0 : mx[nmx - 2] + 1, mx[nmx - 1], a[mx[nmx - 1]] - a[i]), --nmx;
		if (i != 0) smod(0, 0, n - 1, 0, i - 1, 1);
		mn[nmn++] = i, mx[nmx++] = i;
		REPSZ(j, qrgt[i]) { int id = qrgt[i][j]; int cur = sget(0, 0, n - 1, ql[id], i); qans[id] += cur; /*printf("%d: %d=%d\n", i, id,cur);*/ }
	}
}

void run() {
	scanf("%d", &n); REP(i, n) scanf("%d", &a[i]), --a[i];
	scanf("%d", &nq); REP(i, nq) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	REP(i, nq) printf("%lld\n", qans[i]);
}

ll bfans[MAXQ];
void bfsolve() {
	REP(i, nq) bfans[i] = 0;
	REP(l, n) FOR(r, l, n) {
		int mn = a[l], mx = a[l]; FORE(i, l, r) mn = min(mn, a[i]), mx = max(mx, a[i]);
		if (r - l != mx - mn) continue;
		REP(i, nq) if (ql[i] <= l && r <= qr[i]) ++bfans[i];
	}
}

void stress() {
	REP(rep, 10000) {
		n = 100; REP(i, n) a[i] = i; random_shuffle(a, a + n);
		nq = 100; REP(i, nq) { ql[i] = rand() % n, qr[i] = rand() % n; if (ql[i] > qr[i]) swap(ql[i], qr[i]); }
		solve();
		bfsolve();
		bool ok = true; REP(i, nq) if (qans[i] != bfans[i]) ok = false;
		if (ok) { printf("."); continue; }
		printf("err\n");
		printf("%d\n", n); REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i] + 1); } puts("");
		printf("%d\n", nq); REP(i, nq) printf("%d %d\n", ql[i] + 1, qr[i] + 1);
		printf("have:"); REP(i, nq) printf(" %lld", qans[i]); puts("");
		printf("want:"); REP(i, nq) printf(" %lld", bfans[i]); puts("");
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}