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

const int MAXN = 199999;

int n;
int ans[MAXN + 1];

int inv[MAXN + 1];
int fac[MAXN + 1];
int ifac[MAXN + 1];

void solve() {
	inv[1] = 1; FORE(i, 2, n) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, n) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, n) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	int big = (n + 1) / 2;
	vector<int> c(n + 2);
	FORE(ij, 1 + big, n + 1) c[ij] = ifac[n - ij + 1];
	vector<int> d(n + 1);
	FORE(j, big, n - 1) d[n - j] = fac[n - j - 1];
	vector<int> e = ntt.mult(c, d);
	//printf("e:"); REPSZ(i, e) printf(" %d", e[i]); puts("");

	vector<int> a(n + 1);
	a[1] = fac[n - 1];
	FORE(i, 2, n) a[i] = (ll)fac[n - i] * e[n + i] % MOD;
	//printf("a:"); REPSZ(i, a) printf(" %d", a[i]); puts("");

	/*vector<int> aa(n + 1);
	aa[1] = fac[n - 1];
	FORE(i, 2, n) FORE(j, big, n - i + 1) aa[i] = (aa[i] + (ll)fac[n - i] * ifac[j - 1] % MOD * ifac[n - i - j + 1] % MOD * fac[j - 1] % MOD * fac[n - j - 1]) % MOD; // , printf("\t%d %d: %d %d %d\n", i, j, (int)((ll)fac[n - i] * ifac[j - 1] % MOD * ifac[n - i - j + 1] % MOD), fac[j - 1], fac[n - j - 1]);
	printf("aa:"); REPSZ(i, a) printf(" %d", aa[i]); puts("");*/

	int sum = 0;
	for (int i = n; i >= 1; --i) {
		ans[i] = ((ll)(i == 1 ? 1 : i - 1) * a[i] + MOD - sum) % MOD;
		sum = (sum + a[i]) % MOD;
	}
}

void run() {
	scanf("%d", &n);
	solve();
	FORE(i, 1, n) { if (i != 1) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}