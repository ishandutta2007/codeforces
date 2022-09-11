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

const int MOD = 998244353;
const int PRIMROOT = 3;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int& a, int b) { inc(a, MOD - b); }
int neg(int a) { return a == 0 ? 0 : MOD - a; }
int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret * x % MOD; if ((n >>= 1) == 0) return ret; x = (ll)x * x % MOD; } }
int calcinv(int x) { assert(x != 0); return pw(x, MOD - 2); }

struct NTT {
	void _init(int n, int& nlog, int& g, vector<int>& w) {
		assert((MOD - 1) % n == 0);
		g = pw(PRIMROOT, (MOD - 1) / n); nlog = 0; while ((1 << nlog) < n) ++nlog; if ((1 << nlog) != n) nlog = -1;
		w = vector<int>(n); w[0] = 1; FOR(i, 1, n) w[i] = (ll)w[i - 1] * g % MOD;
	}
	int fftn, fftnlog; int fftg; vector<int> fftw;
	void initfft(int n) { fftn = n, _init(fftn, fftnlog, fftg, fftw); assert(fftnlog != -1); }
	void fft(int* a, int n, bool inv) {
		if (n != fftn) initfft(n);
		for (int i = 1, j = n >> 1, k, l = j; i < n; j ^= k, ++i) { if (i < j) swap(a[i], a[j]); for (k = l; k & j; j ^= k, k >>= 1); }
		int* l, * r, * w;
		if (inv) reverse(fftw.begin() + 1, fftw.end());
		for (int hlen = 1, step = n >> 1; hlen < n; hlen <<= 1, step >>= 1) {
			for (int i = 0; i < n; i += (hlen << 1)) {
				l = a + i, r = l + hlen, w = fftw.data();
				REP(off, hlen) {
					int v = (ll)(*r) * (*w) % MOD;
					*r = (*l) - v; if (*r < 0) *r += MOD;
					*l = (*l) + v; if (*l >= MOD) *l -= MOD;
					++l, ++r, w += step;
				}
			}
		}
		if (inv) reverse(fftw.begin() + 1, fftw.end());
		if (inv) { int mlt = pw(n, MOD - 2); REP(i, n) a[i] = (ll)a[i] * mlt % MOD; }
	}
	void mult(const int* a, int na, const int* b, int nb, int* c, int nc) {
		int sz = 1, lgsz = 0; while (sz < na + nb - 1) sz *= 2, ++lgsz;
		if ((ll)na * nb < sz + (ll)3 * (lgsz + 1) * sz) { 
			REP(i, nc) c[i] = 0;
			REP(i, na) REP(j, nb) c[i + j] = (c[i + j] + (ll)a[i] * b[j]) % MOD;
		} else {
			vector<int> A(sz, 0), B(sz, 0);
			REP(i, na) A[i] = a[i]; REP(i, nb) B[i] = b[i];
			fft(A.data(), sz, false); fft(B.data(), sz, false); REP(i, sz) A[i] = (ll)A[i] * B[i] % MOD; fft(A.data(), sz, true);
			REP(i, nc) c[i] = i < sz ? A[i] : 0;
		}
	}
};

NTT ntt;

vector<int> mult(const vector<int>& a, const vector<int>& b) {
	if (SZ(a) == 0 || SZ(b) == 0) return vector<int>();
	vector<int> c(SZ(a) + SZ(b) - 1);
	ntt.mult(a.data(), SZ(a), b.data(), SZ(b), c.data(), SZ(c));
	return c;
}

vector<int> twice(const vector<int>& a) {
	vector<int> b = a;
	REPSZ(i, b) inc(b[i], b[i]);
	return b;
}

vector<int> sub(const vector<int>& a, const vector<int>& b) {
	vector<int> c = a;
	while (SZ(c) < SZ(b)) c.PB(0);
	REPSZ(i, b) dec(c[i], b[i]);
	while (SZ(c) > 0 && c.back() == 0) c.pop_back();
	return c;
}

vector<int> add(const vector<int>& a, const vector<int>& b) {
	vector<int> c = a;
	while (SZ(c) < SZ(b)) c.PB(0);
	REPSZ(i, b) inc(c[i], b[i]);
	while (SZ(c) > 0 && c.back() == 0) c.pop_back();
	return c;
}

vector<int> prefix(const vector<int>& a, int n) {
	vector<int> b(min(n, SZ(a)), 0);
	REPSZ(i, b) b[i] = a[i];
	while (SZ(b) > 0 && b.back() == 0) b.pop_back();
	return b;
}

vector<int> calcinv(const vector<int>& a, int n) {
	assert(SZ(a) >= 1 && a[0] != 0);
	vector<int> b{ calcinv(a[0]) };
	for (int k = 0; (1 << k) < n; ++k) b = prefix(sub(twice(b), mult(prefix(a, 2 << k), mult(b, b))), 2 << k);
	return prefix(b, n);
}

vector<int> divide(vector<int> a, vector<int> b) {
	if (SZ(a) < SZ(b)) return vector<int>();
	int k = SZ(a) - SZ(b) + 1;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	vector<int> c = prefix(mult(a, calcinv(b, k)), k);
	while (SZ(c) < k) c.PB(0);
	reverse(c.begin(), c.end());
	return c;
}

vector<int> remainder(const vector<int>& a, const vector<int>& b) {
	return sub(a, mult(divide(a, b), b));
}

int eval(const vector<int>& a, int b) {
	int ret = 0;
	for (int i = SZ(a) - 1; i >= 0; --i) ret = ((ll)ret * b + a[i]) % MOD;
	return ret;
}

vector<int> eval(const vector<int>& a, const vector<int>& b) {
	int n = SZ(b); if (n == 0) return vector<int>(); else if (n == 1) return { eval(a,b[0]) };
	int k = 0; while (n > (1 << k)) ++k;
	vector<vector<int>> tree(2 << k);
	REP(i, n) tree[(1 << k) + i] = { neg(b[i]), 1 };
	FOR(i, n, 1 << k) tree[(1 << k) + i] = { 1 };
	for (int i = (1 << k) - 1; i >= 2; --i) tree[i] = mult(tree[2 * i + 0], tree[2 * i + 1]);
	tree[1] = a;
	FOR(i, 2, (1 << k) + n) tree[i] = remainder(tree[i / 2], tree[i]);
	vector<int> c(n);
	REP(i, n) c[i] = eval(tree[(1 << k) + i], b[i]);
	return c;
}

vector<int> derivative(const vector<int>& a) {
	vector<int> b(max(0, SZ(a) - 1));
	REPSZ(i, b) b[i] = (ll)a[i + 1] * (i + 1) % MOD;
	return b;
}

vector<int> interpolate(const vector<int>& a, const vector<int>& b) {
	int n = SZ(a);
	int k = 0; while (n > (1 << k)) ++k;
	vector<vector<int>> tree(2 << k);
	REP(i, n) tree[(1 << k) + i] = { neg(a[i]), 1 };
	FOR(i, n, (1 << k)) tree[(1 << k) + i] = { 1 };
	for (int i = (1 << k) - 1; i >= 1; --i) tree[i] = mult(tree[2 * i + 0], tree[2 * i + 1]);
	vector<int> c = eval(derivative(tree[1]), a);
	REPSZ(i, c) c[i] = (ll)calcinv(c[i]) * b[i] % MOD;
	vector<vector<int>> tree2(2 << k);
	REP(i, n) tree2[(1 << k) + i] = { c[i] };
	FOR(i, n, (1 << k)) tree2[(1 << k) + i] = {};
	for (int i = (1 << k) - 1; i >= 1; --i) tree2[i] = add(mult(tree[2 * i + 1], tree2[2 * i + 0]), mult(tree[2 * i + 0], tree2[2 * i + 1]));
	return tree2[1];
}

const int MAXCLUB = 1000;

int nclub;
int a[MAXCLUB];

int solve() {
	if (nclub == 1) return 0;
	int n = 0;
	REP(i, nclub) n += a[i];

	int bsz = sqrt(n), nb = (n - 1 + bsz - 1) / bsz; // block b: [1+b*bsz..(b+1)*bsz]
	vector<int> bl(nb), br(nb);
	REP(b, nb) bl[b] = 1 + b * bsz, br[b] = min((b + 1) * bsz, n - 1);

	assert(2 * bsz <= n);
	vector<int>bp(bsz + 1);
	bp[0] = 1; REP(j, bsz) bp[0] = (ll)bp[0] * (2 * n - j) % MOD;
	REP(i, bsz) bp[i + 1] = (ll)bp[i] * (2 * n - (i + bsz)) % MOD * calcinv(2 * n - i) % MOD;
	vector<int>bq(bsz + 1);
	bq[0] = 1; REP(j, bsz) bq[0] = (ll)bq[0] * (n - j) % MOD;
	REP(i, bsz) bq[i + 1] = (ll)bq[i] * (n - (i + bsz)) % MOD * calcinv(n - i) % MOD;
	vector<int> locpref(bsz + 1); locpref[0] = 1; REP(j, bsz) locpref[j + 1] = (ll)locpref[j] * (2 * n - j) % MOD;
	vector<int> locsuff(bsz + 1); locsuff[bsz] = 1; for (int j = bsz - 1; j >= 0; --j) locsuff[j] = (ll)locsuff[j + 1] * (n - j) % MOD;
	vector<int>bpq(bsz + 1);
	bpq[0] = 0; REP(j, bsz) bpq[0] = (bpq[0] + (ll)locpref[j] * locsuff[j]) % MOD;
	REP(i, bsz) bpq[i + 1] = ((ll)bpq[i] + bp[i] - bq[i] + MOD) * (n - (i + bsz)) % MOD * calcinv(2 * n - i) % MOD;

	vector<int> have(bsz + 1); REPE(i, bsz) have[i] = i;
	vector<int> want(nb - 1); REPSZ(i, want) want[i] = bl[i];
	vector<int> bppol = interpolate(have, bp);
	vector<int> bpqpol = interpolate(have, bpq);
	vector<int> bqpol = interpolate(have, bq);
	bp = eval(bppol, want); bp.PB(0);
	bpq = eval(bpqpol, want); bpq.PB(0);
	bq = eval(bqpol, want); bq.PB(0);

	FORE(b, nb - 1, nb - 1) {
		bp[b] = 1; FORE(i, bl[b], br[b]) bp[b] = (ll)bp[b] * (2 * n - i) % MOD;
		bq[b] = 1; FORE(i, bl[b], br[b]) bq[b] = (ll)bq[b] * (n - i) % MOD;
		vector<int> locpref(br[b] - bl[b] + 2); locpref[0] = 1; FORE(j, bl[b], br[b]) locpref[j - bl[b] + 1] = (ll)locpref[j - bl[b]] * (2 * n - j) % MOD;
		vector<int> locsuff(br[b] - bl[b] + 2); locsuff[br[b] - bl[b] + 1] = 1; for (int j = br[b]; j >= bl[b]; --j) locsuff[j - bl[b]] = (ll)locsuff[j - bl[b] + 1] * (n - j) % MOD;
		bpq[b] = 0; FORE(i, bl[b], br[b]) bpq[b] = (bpq[b] + (ll)locpref[i - bl[b]] * locsuff[i - bl[b]]) % MOD;
	}

	//printf("bp:"); REPSZ(i, bp) printf(" %d", bp[i]); puts("");
	//printf("bpq:"); REPSZ(i, bpq) printf(" %d", bpq[i]); puts("");
	//printf("bq:"); REPSZ(i, bq) printf(" %d", bq[i]); puts("");

	vector<int> ppref(nb + 1); ppref[0] = 1; REP(i, nb) ppref[i + 1] = (ll)ppref[i] * bp[i] % MOD;
	vector<int> qsuff(nb + 1); qsuff[nb] = 1; for (int i = nb - 1; i >= 0; --i) qsuff[i] = (ll)qsuff[i + 1] * bq[i] % MOD;
	vector<int> pqpref(nb + 1); pqpref[0] = 0; REP(i, nb) pqpref[i + 1] = (pqpref[i] + (ll)ppref[i] * bpq[i] % MOD * qsuff[i + 1]) % MOD;

	auto calc = [&](int i) -> int {
		if (i == 0) return 0; else if (i == 1) return neg(2);
		int num = neg(2);
		int den = qsuff[0];
		int b = (i - 2) / bsz;
		int sum = pqpref[b];
		vector<int> locpref(br[b] - bl[b] + 2); locpref[0] = ppref[b]; FORE(j, bl[b], br[b]) locpref[j - bl[b] + 1] = (ll)locpref[j - bl[b]] * (2 * n - j) % MOD;
		vector<int> locsuff(br[b] - bl[b] + 2); locsuff[br[b] - bl[b] + 1] = qsuff[b + 1]; for (int j = br[b]; j >= bl[b]; --j) locsuff[j - bl[b]] = (ll)locsuff[j - bl[b] + 1] * (n - j) % MOD;
		FORE(j, bl[b], i) sum = (sum + (ll)locpref[j - bl[b]] * locsuff[j - bl[b]]) % MOD;
		return (ll)num * calcinv(den) % MOD * sum % MOD;
	};

	int ret = 0;
	REP(i, nclub) inc(ret, calc(a[i]));
	dec(ret, calc(n));
	return ret;
}

void run() {
	scanf("%d", &nclub);
	REP(i, nclub) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}