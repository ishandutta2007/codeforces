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


const int MAXN = 200000;
const int MAXQ = 200000;
const int MAXX = 200000;
const int MAXQVAL = 1000000;

int n, x, y;
int a[MAXN + 1];
int nq;
int q[MAXQ], qans[MAXQ];

int A[MAXX + 1];
int B[MAXX + 1];
int C[2 * MAXX + 1];

int best[MAXQVAL + 1];


void mult(int* a, int na, int* b, int nb, int* c, int nc) {
	//REP(i, nc) c[i] = 0;
	//REP(i, na) REP(j, nb) if (i + j < nc) c[i + j] += a[i] * b[j];
	ntt.mult(a, na, b, nb, c, nc);
}

void solve() {
	REPE(i, x) A[i] = B[i] = 0;
	REPE(i, n) A[a[i]] = B[x - a[i]] = 1;
	mult(A, x + 1, B, x + 1, C, 2 * x + 1);
	//printf("A:"); REPE(i, x) if (A[i] != 0) printf(" %d", i); puts("");
	//printf("B:"); REPE(i, x) if (B[i] != 0) printf(" %d", i); puts("");
	//printf("C:"); REPE(i, 2 * x) if (C[i] != 0) printf(" %d", i); puts("");

	REPE(i, MAXQVAL) best[i] = -1;
	FORE(i, x + 1, 2 * x) if (C[i] != 0) {
		int z = 2 * (i - x) + 2 * y;
		if (z <= MAXQVAL) best[z] = z;
	}
	for (int i = MAXQVAL; i >= 0; --i) if (best[i] != -1) for (int j = i + i; j <= MAXQVAL; j += i) if (best[j] == -1) best[j] = best[i];
	REP(i, nq) qans[i] = best[q[i]];
}

void run() {
	scanf("%d%d%d", &n, &x, &y);
	REPE(i, n) scanf("%d", &a[i]);
	scanf("%d", &nq);
	REP(i, nq) scanf("%d", &q[i]);
	solve();
	REP(i, nq) { if (i != 0) printf(" "); printf("%d", qans[i]); } puts("");
}

int main() {
	run();
	return 0;
}