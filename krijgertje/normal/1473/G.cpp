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
};

NTT ntt;

const int MAXN = 1000;
const int MAXNUM = 2 * 100000;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n;
int a[MAXN], b[MAXN];

int inv[MAXNUM + 1];
int fac[MAXNUM + 1];
int ifac[MAXNUM + 1];

int choose(int n, int k) { if (k<0 || k>n) return 0; return (ll)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD; }

int solve() {
	inv[1] = 1; FORE(i, 2, MAXNUM) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, MAXNUM) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, MAXNUM) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	vector<int> dp(1, 1);
	REP(i, n) {
		vector<int> ndp(SZ(dp) + a[i] - b[i], 0);
		vector<int> A(SZ(dp) + SZ(ndp) - 1); REPSZ(j, A) A[j] = choose(a[i] + b[i], b[i] + j - SZ(dp) + 1);
		vector<int> B = dp;
		vector<int> C(max(SZ(A) + SZ(B) - 1, 0), 0);
		ntt.mult(A.data(), SZ(A), B.data(), SZ(B), C.data(), SZ(C));
		//REPSZ(j, A) REPSZ(k, B) inc(C[j + k], (ll)A[j] * B[k] % MOD);

		//REPSZ(j, ndp) REPSZ(k, dp) inc(ndp[j], (ll)choose(a[i] + b[i], b[i] + j - k) * dp[k] % MOD);
		//printf("C:"); REPSZ(j, C) printf(" %d", C[j]); puts("");
		//printf("ndp:"); REPSZ(j, ndp) printf(" %d", ndp[j]); puts("");
		//REPSZ(j, ndp) assert(ndp[j] == C[SZ(dp) - 1 + j]);
		REPSZ(j, ndp) ndp[j] = C[SZ(dp) - 1 + j];
		dp = ndp;
	}

	int ret = 0;
	REPSZ(i, dp) inc(ret, dp[i]);
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &a[i], &b[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}