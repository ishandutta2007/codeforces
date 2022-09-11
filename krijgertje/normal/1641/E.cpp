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

const int MOD = 998244353;
const int PRIMROOT = 3;
void mlt(int& a, int b) { a = (ll)a * b % MOD; }
int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) mlt(ret, x); if ((n >>= 1) == 0) return ret; mlt(x, x); } }

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
		int sz = 1; while (sz < na + nb - 1) sz *= 2;
		vector<int> A(sz, 0), B(sz, 0);
		REP(i, na) A[i] = a[i]; REP(i, nb) B[i] = b[i];
		fft(A.data(), sz, false); fft(B.data(), sz, false); REP(i, sz) A[i] = (ll)A[i] * B[i] % MOD; fft(A.data(), sz, true);
		REP(i, nc) c[i] = i < sz ? A[i] : 0;
	}
	vector<int> mult(const vector<int>& a, const vector<int>& b) {
		vector<int> c(max(0, SZ(a) + SZ(b) - 1));
		mult(a.data(), SZ(a), b.data(), SZ(b), c.data(), SZ(c));
		return c;
	}
};

NTT ntt;

const int MAXN = 100000;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int calcinv(int x) { return pw(x, MOD - 2); }

int n, nmarked;
int a[MAXN];
int marked[MAXN];

bool ismarked[MAXN];
int before[MAXN + 1];
int onorafter[MAXN + 1];
int p2[MAXN + 1];


vector<int> calc(const vector<int> &l, const vector<int> &r, int lo, int hi) {
	vector<int> ret(2 * (hi - lo) + 1, 0);
	if (lo == hi) return ret;
	int mi = lo + (hi - lo) / 2;
	/*printf("%d..%d..%d -> offset %d cnt %d + offset %d cnt %d -> offset %d cnt %d\n", lo, mi, hi, lo, mi - lo + 1, mi + 1, hi - mi, mi - lo + 1, hi - lo);
	assert(lo >= 0 && lo <= SZ(l));
	assert(mi - lo + 1 >= 1 && lo + mi - lo + 1 <= SZ(l));
	assert(mi + 1 >= 0 && mi + 1 <= SZ(r));
	assert(hi - mi >= 0 && mi + 1 + hi - mi <= SZ(r));
	assert(mi - lo + 1 >= 0 && mi - lo + 1 <= SZ(ret));
	assert(hi - lo >= 0 && mi - lo + 1 + hi - lo <= SZ(ret));*/
	ntt.mult(l.data() + lo, mi - lo + 1, r.data() + mi + 1, hi - mi, ret.data() + mi - lo + 1, hi - lo);
	vector<int> lres = calc(l, r, lo, mi);
	vector<int> rres = calc(l, r, mi + 1, hi);
	REPSZ(i, lres) inc(ret[i], lres[i]);
	REPSZ(i, rres) inc(ret[2 * (mi - lo + 1) + i], rres[i]);
	return ret;
}

int solve() {
	//printf("marked:"); REP(i, nmarked) printf(" %d", marked[i]); puts("");
	REP(i, n) ismarked[i] = false;
	REP(i, nmarked) ismarked[marked[i]] = true;
	before[0] = 0; REP(i, n) before[i + 1] = before[i] + (ismarked[i] ? 1 : 0);
	onorafter[n] = 0; for (int i = n - 1; i >= 0; --i) onorafter[i] = onorafter[i + 1] + (ismarked[i] ? 1 : 0);
	p2[0] = 1; FORE(i, 1, n) p2[i] = (ll)p2[i - 1] * 2 % MOD;

	vector<int> l(2 * n - 1, 0), r(2 * n - 1, 1);
	REP(i, n) l[i] = !ismarked[i] ? 0 : p2[before[i]], r[i] = p2[onorafter[i]];
	vector<int> x1 = calc(l, r, 0, 2 * n - 2);
	//printf("l:"); REPSZ(i, l) printf(" %d", l[i]); puts("");
	REP(i, n) l[i] = (ll)l[i] * i % MOD;
	vector<int> x2 = calc(l, r, 0, 2 * n - 2);
	vector<int> x(n);
	REP(i, n) x[i] = ((ll)i * x1[2 * i] + MOD - x2[2 * i]) % MOD;
	//printf("l:"); REPSZ(i, l) printf(" %d", l[i]); puts("");
	//printf("r:"); REPSZ(i, r) printf(" %d", r[i]); puts("");
	//printf("x1:"); REPSZ(i, x1) printf(" %d", x1[i]); puts("");
	//printf("x2:"); REPSZ(i, x2) printf(" %d", x2[i]); puts("");
	//printf("x:"); REPSZ(i, x) printf(" %d", x[i]); puts("");

	REPSZ(i, l) l[i] = 0; REPSZ(i, r) r[i] = 1;
	REP(i, n) l[i] = !ismarked[n - i - 1] ? 0 : p2[onorafter[n - i]], r[i] = p2[before[n - i - 1]];
	vector<int> y1 = calc(l, r, 0, 2 * n - 2);
	//printf("l:"); REPSZ(i, l) printf(" %d", l[i]); puts("");
	REP(i, n) l[i] = (ll)l[i] * (n - i - 1) % MOD;
	vector<int> y2 = calc(l, r, 0, 2 * n - 2);
	vector<int> y(n);
	REP(i, n) y[n - i - 1] = (y2[2 * i] + MOD - (ll)(n - i - 1) * y1[2 * i] % MOD) % MOD;
	//printf("l:"); REPSZ(i, l) printf(" %d", l[i]); puts("");
	//printf("r:"); REPSZ(i, r) printf(" %d", r[i]); puts("");
	//printf("y1:"); REPSZ(i, y1) printf(" %d", y1[i]); puts("");
	//printf("y2:"); REPSZ(i, y2) printf(" %d", y2[i]); puts("");
	//printf("y:"); REPSZ(i, y) printf(" %d", y[i]); puts("");

	int num = 0;
	REP(i, n) num = (num + (ll)(x[i] + y[i]) * a[i]) % MOD;
	int den = (p2[nmarked] + MOD - 1) % MOD;
	return (ll)num * calcinv(den) % MOD;
}

void run() {
	scanf("%d%d", &n, &nmarked);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, nmarked) scanf("%d", &marked[i]), --marked[i];
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}