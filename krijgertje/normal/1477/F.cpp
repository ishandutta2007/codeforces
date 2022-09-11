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

const int MAXN = 50;
const int MAXTOTLEN = 2000;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
int neg(int x) { return x == 0 ? 0 : MOD - x; }
int calcinv(int x) { return pw(x, MOD - 2); }

int n, lim;
int len[MAXN];

// Qi = exp((Li/L)*x)+sum(k=1..floor(Li/K): (-1)^k*exp(((Li-k*K)/L)*x)*(((Li-k*K)/L)^k*x^k/k!+((Li-k*K)/L)^(k-1)*x^(k-1)/(k-1)!)) = sum(j=0..1: sum(k=0..floor(len[i]/lim): q[i][j][k]*x^(k-j)*exp(((len[i]-k*lim)/totlen)*x)))

int inv[MAXTOTLEN + 1];
int fac[MAXTOTLEN + 1];
int ifac[MAXTOTLEN + 1];

vector<vector<int>> twodimmult(const vector<vector<int>>& a, const vector<vector<int>>& b) {
	int n1 = SZ(a), n2 = SZ(b), m1 = 0, m2 = 0;
	REPSZ(i, a) m1 = max(m1, SZ(a[i]));
	REPSZ(i, b) m2 = max(m2, SZ(b[i]));
	if (n1 == 0 || n2 == 0 || m1 == 0 || m2 == 0) return vector<vector<int>>();
	int n = n1 + n2 - 1, m = m1 + m2 - 1;
	vector<int> A(n1 * m, 0), B(n2 * m, 0);
	REPSZ(i, a) REPSZ(j, a[i]) A[i * m + j] = a[i][j];
	REPSZ(i, b) REPSZ(j, b[i]) B[i * m + j] = b[i][j];
	vector<int> C(n * m);
	ntt.mult(A.data(), SZ(A), B.data(), SZ(B), C.data(), SZ(C));
	vector<vector<int>> ret(n, vector<int>(m));
	REP(i, n) REP(j, m) ret[i][j] = C[i * m + j];
	REP(i, n) while (SZ(ret[i]) > 0 && ret[i].back() == 0) ret[i].pop_back();
	while (SZ(ret) > 0 && SZ(ret.back()) == 0) ret.pop_back();
	//vector<vector<int>> chk(n, vector<int>(m)); REPSZ(i, a) REPSZ(ii, a[i]) REPSZ(j, b) REPSZ(jj, b[j]) chk[i + j][ii + jj] = (chk[i + j][ii + jj] + (ll)a[i][ii] * b[j][jj]) % MOD;
	//REP(i, n) while (SZ(chk[i]) > 0 && chk[i].back() == 0) chk[i].pop_back();
	//while (SZ(chk) > 0 && SZ(chk.back()) == 0) chk.pop_back();
	//assert(ret == chk);
	return ret;
}

vector<vector<int>> twodimmultdnc(const vector<vector<vector<int>>>& a, int l, int r) {
	if (l == r) return a[l];
	int m = l + (r - l) / 2;
	return twodimmult(twodimmultdnc(a, l, m), twodimmultdnc(a, m + 1, r));
}

int solve() {
	inv[1] = 1; FORE(i, 2, MAXTOTLEN) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, MAXTOTLEN) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, MAXTOTLEN) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	int totlen = 0; REP(i, n) totlen += len[i];
	vector<vector<vector<int>>> q(n, vector<vector<int>>(2));
	REP(i, n) {
		int kmx = len[i] / lim;
		q[i][0] = q[i][1] = vector<int>(kmx + 1, 0);
		inc(q[i][0][0], 1);
		FORE(k, 1, kmx) {
			if (k * lim == len[i]) continue;
			int a = (ll)(len[i] - k * lim) * inv[totlen] % MOD;
			int b = (ll)pw(a, k) * ifac[k] % MOD;
			int c = (ll)pw(a, k - 1) * ifac[k - 1] % MOD;
			if (k % 2 == 1) b = neg(b), c = neg(c);
			inc(q[i][0][k], b), inc(q[i][1][k], c);
		}
	}
	//REP(i, n) REPSZ(j, q[i]) { printf("q%d%d:", i, j); REPSZ(k, q[i][j]) printf(" %d", q[i][j][k]); puts(""); }
	vector<vector<int>> p = twodimmultdnc(q, 0, SZ(q) - 1);
	REPSZ(j, p) REPSZ(k, p[j]) p[j][k] = neg(p[j][k]);
	if (SZ(p) == 0) p.PB(vector<int>());
	if (SZ(p[0]) == 0) p[0].PB(0);
	inc(p[0][0], 1);
	//REPSZ(j, p) { printf("p%d:", j); REPSZ(k, p[j]) printf(" %d", p[j][k]); puts(""); }

	int ret = 0;
	REPSZ(j, p) REPSZ(k, p[j]) {
		int a = (ll)k * lim * inv[totlen] % MOD;
		if (k == 0 || k < j) { assert(p[j][k] == 0); continue; }
		// EGF: p[j][k]*x^(k-j)*exp((1-a)*x)) -> (k-j)!*x^(k-j)/(1-(1-a)*x)^(k-j+1) evaluated at x=1 -> (k-j)!/a^(k-j+1)
		ret = (ret + (ll)p[j][k] * fac[k - j] % MOD * calcinv(pw(a, k - j + 1))) % MOD;
	}

	return ret;
}

void run() {
	scanf("%d%d", &n, &lim);
	REP(i, n) scanf("%d", &len[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}