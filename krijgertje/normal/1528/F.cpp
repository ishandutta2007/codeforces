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

const int MAXK = 100000;
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


int n, k;

int inv[MAXK + 1];
int fac[MAXK + 1];
int ifac[MAXK + 1];

// for a: n times, choose one out of n+1 options, but take only 1/(n+1) of the final answer
// for b: still fine to compute answer for all options first, and only at the end take 1/(n+1) of the final answer
// for b: choose which i (1<=i<=k) indices from a are used at least once for b, use 2nd kind stirling + factorials for the usage pattern, those values together have one of n+1 options (cancels), remaining elements have n+1 options
int solve() {
	inv[1] = 1; FORE(i, 2, k) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, k) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, k) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	// stirling_k[i] = 1/i!*sum(j=0..i: (-1)^j*choose(i,j)*(i-j)^k)
	// stirling_k[i] = sum(j=0..i: (-1)^j*ifac[j]*ifac[i-j]*(i-j)^k) = [coeff of x^i] (sum(j=0..i: (-1)^j*ifac[j]*x^j)*(sum(j=0..i,ifac[j]*j^k*x^j))

	vector<int> a(k + 1), b(k + 1);
	REPE(i, k) a[i] = (ll)(i % 2 == 0 ? 1 : MOD - 1) * ifac[i] % MOD;
	REPE(i, k) b[i] = (ll)ifac[i] * pw(i, k) % MOD;
	vector<int> stirling = ntt.mult(a, b);

	int lim = min(n, k);
	int ret = 0;
	int binom = 1;
	FORE(i, 1, lim) {
		binom = (ll)binom * (n - i + 1) % MOD * inv[i] % MOD;
		ret = (ret + (ll)binom * stirling[i] % MOD * fac[i] % MOD * pw(n + 1, n - i)) % MOD;
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &k);
	printf("%d\n", solve());
}

void research() {
	const int mxn = 10;
	vector<vector<ll>> C(mxn + 1, vector<ll>(mxn + 1));
	REPE(i, mxn) { C[i][0] = C[i][i] = 1; FOR(j, 1, i) C[i][j] = C[i - 1][j - 1] + C[i - 1][j]; }

	vector<vector<ll>> dp(mxn + 1, vector<ll>(mxn + 1, 0));
	REPE(j, mxn) dp[0][j] = 1;
	FORE(i, 1, mxn) REPE(j, mxn-i) {
		REPE(k, i) {
			int ni = i - k, nj = j + k - 1;
			if (nj < 0) continue;
			assert(nj <= mxn - ni);
			dp[i][j] += C[i][k] * dp[ni][nj];
		}
	}
	REPE(i, mxn) printf("%d: %lld\n", i, dp[i][0]); // seems to be equal to (i+1)^(i-1)
}

int main() {
	//research();
	run();
	return 0;
}