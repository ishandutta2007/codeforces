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
const int MOD = 998244353;
const int PRIMROOT = 3;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
void mlt(int& a, int b) { a = (ll)a * b % MOD; }
int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) mlt(ret, x); if ((n >>= 1) == 0) return ret; mlt(x, x); } }

int n, k;

int pmn[MAXN + 1];
int mu[MAXN + 1];

int inv[MAXN + 1];
int fac[MAXN + 1];
int ifac[MAXN + 1];


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

// Counts number of partitions of n into i nonempty groups
vector<int> stirlingkind2(int n) {
	vector<int> a(n + 1), b(n + 1);
	REPE(i, n) a[i] = (ll)(i % 2 == 0 ? 1 : MOD - 1) * ifac[i] % MOD;
	REPE(i, n) b[i] = (ll)ifac[i] * pw(i, n) % MOD;
	return ntt.mult(a, b);
}


int solve() {
	if (n == 1 || k == 1) return 1;

	inv[1] = 1; FORE(i, 2, MAXN) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, MAXN) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, MAXN) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;


	REPE(i, MAXN) pmn[i] = -1, mu[i] = 0;
	FORE(i, 2, MAXN) if (pmn[i] == -1) for (int j = i; j <= MAXN; j += i) if (pmn[j] == -1) pmn[j] = i;
	mu[1] = 1; FORE(i, 2, MAXN) { int j = i / pmn[i]; mu[i] = pmn[j] == pmn[i] ? 0 : -mu[j]; }
	//printf("pmn:"); REPE(i, n) printf(" %d", pmn[i]); puts("");
	//printf("mu:"); REPE(i, n) printf(" %d", mu[i]); puts("");

	vector<int> mem(n + 1, -1);
	auto calc = [&](int x) { 
		if (mem[x] != -1) return mem[x]; 
		int ret = 0; vector<int> a = stirlingkind2(x); REPE(i, min(x, k)) inc(ret, a[i]); inc(ret, MOD - 1);
		return mem[x] = ret;
	};


	int ret = 0;
	inc(ret, calc(n));
	FORE(bsz, 2, n) {
		int cur = (ll)(MOD + mu[bsz]) * calc((n + bsz - 1) / bsz) % MOD;
		inc(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &k);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}