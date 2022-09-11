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
#include <array>
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
		int sz = 1; while (sz < na + nb - 1 || sz < na || sz < nb) sz *= 2;
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
typedef vector<int> Pol;
typedef array<array<Pol, 2>, 2> Mat;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int& a, int b) { inc(a, MOD - b); }

int n;
int a[MAXN];

int b[MAXN], nb;
Mat init[2];
Mat trans[2];
int fac[MAXN + 1];

Pol mlt(const Pol& a, const Pol& b) {
	Pol c = ntt.mult(a, b);
	//if (SZ(a) == 0 || SZ(b) == 0) return Pol();
	//Pol c(SZ(a) + SZ(b) - 1);
	//REPSZ(i, a) REPSZ(j, b) c[i + j] = (c[i + j] + (ll)a[i] * b[j]) % MOD;
	while (SZ(c) >= 1 && c.back() == 0) c.pop_back();
	return c;
}
void inc(Pol& a, const Pol& b) {
	while (SZ(a) < SZ(b)) a.PB(0);
	REPSZ(i, b) inc(a[i], b[i]);
	while (SZ(a) >= 1 && a.back() == 0) a.pop_back();
}
Mat mlt(const Mat& a, const Mat& b) {
	Mat ret;
	REP(i, 2) REP(j, 2) REP(k, 2) inc(ret[i][j], mlt(a[i][k], b[k][j]));
	return ret;
}
Mat rec(int l, int r) {
	if (l == r) return trans[b[l]];
	int m = l + (r - l) / 2;
	Mat lres = rec(l, m);
	Mat rres = rec(m + 1, r);
	return mlt(lres, rres);
}

int solve() {
	init[0][0][0] = { 0,2 };
	init[1][0][1] = { 0,1 };
	trans[0][0][0] = { 1,2 };
	trans[0][1][0] = { 2,2 };
	trans[1][0][0] = { 1 };
	trans[1][0][1] = { 0,1 };
	trans[1][1][0] = { 2 };
	trans[1][1][1] = { 0,1 };
	fac[0] = 1; FORE(i, 1, n) fac[i] = (ll)fac[i - 1] * i % MOD;

	nb = 0;
	int at = 0;
	while (at < n) {
		int to = at + a[at];
		if (to > n) return 0;
		FOR(i, at, to) if (a[i] != a[at]) return 0;
		b[nb++] = a[at] != 1 ? 0 : 1;
		at = to;
	}
	//printf("b: "); REP(i, nb) printf("%d", b[i]); puts("");

	if (nb == 1) return b[0] == 0 ? 2 : 1;

	Mat mat = mlt(init[b[0]], rec(1, nb - 1));
	Pol pol;
	inc(pol, mat[0][0]);
	inc(pol, mat[0][1]);
	//printf("pol:"); REPSZ(i, pol) printf(" %d", pol[i]); puts("");

	int ret = 0;
	REPSZ(i, pol) {
		int sgn = i % 2 == nb % 2 ? +1 : -1;
		int cur = (ll)fac[i] * pol[i] % MOD;
		if (sgn == +1) inc(ret, cur); else dec(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}