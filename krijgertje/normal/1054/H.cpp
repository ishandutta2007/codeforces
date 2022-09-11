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

int pw(int x, int n, int mod) { int ret = 1 % mod; while (true) { if (n & 1) ret = (ll)ret*x%mod; if ((n >>= 1) == 0) return ret; x = (ll)x*x%mod; } }
vector<int> getprimes(int x) { vector<int> ret; for (int i = 2; i * i <= x; ++i) if (x % i == 0) { while (x % i == 0) x /= i; ret.PB(i); } if (x != 1) ret.PB(x); return ret; }

int findprimitiveroot(int p) {
	vector<int> pp = getprimes(p - 1);
	FOR(a, 1, p) { bool ok = true; REPSZ(i, pp) if (pw(a, (p - 1) / pp[i], p) == 1) { ok = false; break; } if (ok) return a; }
	assert(false); return -1;
}

struct complex { 
	double x, y; complex(double x = 0, double y = 0) :x(x), y(y) {} 
	const inline complex operator+(const complex &b) const { return complex(x + b.x, y + b.y); }
	const inline complex operator-(const complex &b) const { return complex(x - b.x, y - b.y); }
	const inline complex operator*(const complex &b) const { return complex(x*b.x - y*b.y, x*b.y + y*b.x); }
	const inline void operator-=(const complex &b) { x -= b.x; y -= b.y; }
	const inline void operator+=(const complex &b) { x += b.x; y += b.y; }
};

void fft(complex *x, int n, int type) {
	vector<complex> ww(n); ww[0] = complex(1, 0);
	for (int step = n >> 1; step > 0; step >>= 1) {
		double r = 2 * acos(-1) / (n / step); complex unit(cos(r), sin(r));
		for (int i = 0; i < n; i += 2 * step) ww[i + step] = ww[i] * unit;
	}
	if (type != +1) { for (int i = 1; i <= n - i; ++i) swap(ww[i], ww[n - i]); }
	//printf("ww:"); REP(i, n) printf(" (%.3lf,%.3lf)", ww[i].x, ww[i].y); puts("");
	for (int i = 1, j = 0; i < n - 1; ++i) {
		for (int s = n; j ^= s >>= 1, ~j&s;);
		if (i<j) swap(x[i], x[j]);
	}
	for (int d = 0; (1 << d) < n; ++d) {
		int m = 1 << d, m2 = m * 2, step = n / m / 2;
		for (int i = 0; i<n; i += m2) {
			complex *l = x + i, *r = x + i + m, *w = ww.data();
			for (int j = 0; j<m; ++j, ++l, ++r, w += step) {
				//printf("(%d,%d,%d) l=(%.2lf,%.2lf) r=(%.2lf,%.2lf) w=(%.2lf,%.2lf) \n", d, i, j, l->x, l->y, r->x, r->y, w->x, w->y);
				complex s = *l, t = *r**w;
				*l = s + t, *r = s - t;
			}
		}
	}
}

template<class T> struct MultiDimArray {
	vector<int> dim;
	vector<T> data;

	MultiDimArray(vector<int> _dim) { dim = _dim; int sz = 1; REPSZ(i, dim) sz *= dim[i]; data = vector<T>(sz); }
	int flatidx(const vector<int> &idx) const { int ret = 0; REPSZ(i, dim) ret = ret * dim[i] + idx[i]; return ret; }
	vector<int> idx(int flatidx) const { vector<int> ret(SZ(dim)); for (int i = SZ(dim) - 1; i >= 0; --i) { ret[i] = flatidx % dim[i]; flatidx /= dim[i]; } return ret; }
	pair<int, int> splitidx(int flatidx, int dimidx) const { pair<int, int> ret = MP(0, 0); int prod = 1; for (int i = SZ(dim) - 1; i >= 0; --i) { int cur = flatidx%dim[i]; if (i == dimidx) ret.second = cur; else ret.first += prod * cur, prod *= dim[i]; flatidx /= dim[i]; } return ret; }
	T& operator[](const vector<int> &idx) { return data[flatidx(idx)]; }
	T& operator[](const int &flatidx) { return data[flatidx]; }
	const T& operator[](const vector<int> &idx) const { return data[flatidx(idx)]; }
	const T& operator[](const int &flatidx) const { return data[flatidx]; }
};

// OPTIMIZED
void fft(MultiDimArray<complex> &A, int type) {
	REPSZ(fftdim, A.dim) {
		int times = 1, step = 1; REP(i, fftdim) times *= A.dim[i]; FORSZ(i, fftdim + 1, A.dim) step *= A.dim[i];
		vector<complex> tmp(A.dim[fftdim]);
		REP(i, times) REP(j, step) {
			int off = i * A.dim[fftdim] * step + j;
			REP(k, A.dim[fftdim]) tmp[k] = A[off + k*step];
			fft(tmp.data(), A.dim[fftdim], type);
			REP(k, A.dim[fftdim]) A[off + k*step] = tmp[k];
		}
	}
}
/* NON-OPTIMIZED
void fft(MultiDimArray<complex> &A, int type) {
	REPSZ(fftdim, A.dim) {
		vector<vector<complex>> tmp(SZ(A.data) / A.dim[fftdim], vector<complex>(A.dim[fftdim]));
		REPSZ(i, A.data) { pair<int, int> split = A.splitidx(i, fftdim); tmp[split.first][split.second] = A[i]; }
		REPSZ(i, tmp) fft(tmp[i].data(), A.dim[fftdim], type);
		REPSZ(i, A.data) { pair<int, int> split = A.splitidx(i, fftdim); A[i] = tmp[split.first][split.second]; }
	}
}*/

// OPTIMIZED
MultiDimArray<int> multiply(const MultiDimArray<int> &A, const MultiDimArray<int> &B, int mod) {
	assert(A.dim == B.dim); vector<int> dim = A.dim;
	vector<int> ndim(SZ(dim)); REPSZ(i, dim) { ndim[i] = 1; while (2 * (dim[i] - 1) >= ndim[i]) ndim[i] *= 2; }
	vector<int> idx(SZ(dim)); int k = 0;
	MultiDimArray<complex> AA(ndim), BB(ndim);
	REPSZ(i, A.data) {
		AA[k] = complex(A[i], 0), BB[k] = complex(B[i], 0);
		for (int x = i + 1, y = 1, j = SZ(dim) - 1; j >= 0; x /= dim[j], y *= ndim[j], --j) if (x % dim[j] == 0) k -= idx[j] * y, idx[j] = 0; else { k += y, ++idx[j]; break; }
	}
	fft(AA, +1);
	fft(BB, +1);
	REPSZ(i, AA.data) AA[i] = AA[i] * BB[i];
	fft(AA, -1);
	MultiDimArray<int> ret(dim);
	REPSZ(i, AA.data) {
		int cur = (ll)floor(AA[i].x / SZ(AA.data) + 0.5) % mod; if (cur < 0) cur += mod;
		ret[k] = (ret[k] + cur) % mod;
		for (int x = i + 1, y = 1, j = SZ(ndim) - 1; j >= 0; x /= ndim[j], y *= dim[j], --j) if (x % ndim[j] == 0) k -= idx[j] * y, idx[j] = 0; else { if (idx[j] + 1 < dim[j]) k += y, ++idx[j]; else k -= idx[j] * y, idx[j] = 0; break; }
	}
	return ret;
}

/* NON-OPTIMIZED
MultiDimArray<int> multiply(const MultiDimArray<int> &A, const MultiDimArray<int> &B, int mod) {
	assert(A.dim == B.dim); vector<int> dim = A.dim;
	vector<int> ndim(SZ(dim)); REPSZ(i, dim) { ndim[i] = 1; while (2 * dim[i] > ndim[i]) ndim[i] *= 2; }
	MultiDimArray<complex> AA(ndim); REPSZ(i, A.data) AA[A.idx(i)] = complex(A[i], 0);
	MultiDimArray<complex> BB(ndim); REPSZ(i, B.data) BB[B.idx(i)] = complex(B[i], 0);
	fft(AA, +1);
	fft(BB, +1);
	REPSZ(i, AA.data) AA[i] = AA[i] * BB[i];
	fft(AA, -1);
	MultiDimArray<int> ret(dim);
	REPSZ(i, AA.data) {
		vector<int> nidx = AA.idx(i), idx(SZ(dim)); REPSZ(i, nidx) idx[i] = nidx[i] % dim[i];
		int cur = ((ll)floor(AA[i].x / SZ(AA.data) + 0.5) % mod + mod) % mod;
		ret[idx] = (ret[idx] + cur) % mod;
	}
	return ret;
}
*/

// Convert sum(i,j: ai*bj*x^(ci*dj)) mod p to sum(k: sum(i,j st ci*dj=k mod p-1: ai*bj)*x^k)
// Only supports unique primes in factorization of p-1
struct ExponentialResidueConvolution {
	int p;
	vector<int> pp; // factorization of p-1
	vector<int> proot;
	vector<vector<int>> exp;
	vector<vector<int>> lg;
	vector<int> crt;

	ExponentialResidueConvolution(int _p) {
		p = _p;
		pp = getprimes(p - 1); { int chk = 1; REPSZ(i, pp) chk *= pp[i]; assert(chk == p - 1); }
		//printf("pp:"); REPSZ(i, pp) printf(" %d", pp[i]); puts("");
		proot = vector<int>(SZ(pp)); lg = exp = vector<vector<int>>(SZ(pp));
		REPSZ(i, pp) {
			lg[i] = vector<int>(pp[i], -1); exp[i] = vector<int>(pp[i] - 1);
			proot[i] = findprimitiveroot(pp[i]);
			for (int n = 0, x = 1; n < pp[i] - 1; ++n, x = (ll)x*proot[i] % pp[i]) exp[i][n] = x, lg[i][x] = n;
			//printf("%d (proot=%d):", pp[i], proot[i]); REPSZ(j, lg[i]) printf(" %d", lg[i][j]); puts("");
		}
		crt = vector<int>(p - 1, -1); REP(i, p - 1) { int crtidx = 0, prod = 1; REPSZ(idx, pp) { crtidx += i%pp[idx] * prod; prod *= pp[idx]; } assert(crt[crtidx] == -1); crt[crtidx] = i; }
	}

	MultiDimArray<int> build(vector<int> coef, vector<int> exp, int zeromask, vector<int> dim) {
		MultiDimArray<int> ret(dim);
		REPSZ(i, exp) {
			vector<int> idx; bool ok = true;
			REPSZ(j, pp) {
				int rem = exp[i] % pp[j]; if (rem == 0 && (zeromask & (1 << j)) == 0) { ok = false; break; }
				if ((zeromask&(1 << j)) == 0 && pp[j] != 2) idx.PB(lg[j][rem]);
			}
			if (!ok) continue; ret[idx] = (ret[idx] + coef[i]) % p;
		}
		return ret;
	}

	vector<int> solve(vector<int> a, vector<int> b, vector<int> c, vector<int> d) {
		MultiDimArray<int> invcrt(pp); REP(i, p - 1) { vector<int> idx; REPSZ(j, pp) idx.PB(i%pp[j]); invcrt[idx] = i; }
		vector<int> ret(p - 1, 0);
		REP(zeromask, 1 << SZ(pp)) {
			vector<int> dim; REPSZ(j, pp) if ((zeromask & (1 << j)) == 0 && pp[j] != 2) dim.PB(pp[j] - 1);
			MultiDimArray<int> A = build(a, c, zeromask, dim);
			MultiDimArray<int> B = build(b, d, zeromask, dim);
			MultiDimArray<int> C = multiply(A, B, p);
			REPSZ(flatidx, C.data) {
				vector<int> idx = C.idx(flatidx);
				for (int submask = 0; submask < (1 << SZ(pp)); submask = (submask + zeromask + 1)&~zeromask) {
					vector<int> crtidx; int at = 0, subcnt = 0;
					REPSZ(j, pp) {
						if (submask & (1 << j)) ++subcnt;
						if ((submask | zeromask) & (1 << j)) crtidx.PB(0); else if (pp[j] == 2) crtidx.PB(1); else crtidx.PB(exp[j][idx[at]]);
						if ((zeromask & (1 << j)) == 0 && pp[j] != 2) ++at;
					}
					int k = invcrt[crtidx]; if (subcnt % 2 == 0) ret[k] = (ret[k] + C[idx]) % p; else ret[k] = (ret[k] + p - C[idx]) % p;
					//if (C[idx] != 0) { printf("zeromask=%x submask=%x subcnt=%d C[idx]=%d k=%d idx:", zeromask, submask, subcnt, C[idx], k); REPSZ(i, idx) printf(" %d", idx[i]); printf(" crtidx:"); REPSZ(i, crtidx) printf(" %d", crtidx[i]); puts(""); }
				}
			}
		}
		return ret;
	}
};

const int MAXN = 100000;
const int MOD = 490019;

int na, nb, c;
int a[MAXN], b[MAXN];

ExponentialResidueConvolution erc(MOD);

int solve() {
	vector<int> a(na), c(na); REP(i, na) a[i] = ::a[i] % MOD, c[i] = (ll)i*i % (MOD - 1);
	vector<int> b(nb), d(nb); REP(i, nb) b[i] = ::b[i] % MOD, d[i] = (ll)i*i*i % (MOD - 1);
	vector<int> res = erc.solve(a, b, c, d);
	int ret = 0; REPSZ(i, res) ret = (ret + (ll)res[i] * pw(::c, i, MOD)) % MOD; return ret;
}

void run() {
	scanf("%d%d%d", &na, &nb, &c);
	REP(i, na) scanf("%d", &a[i]);
	REP(i, nb) scanf("%d", &b[i]);
	printf("%d\n", solve());
}

vector<int> bfsolve(vector<int> a, vector<int> b, vector<int> c, vector<int> d,int mod) {
	int na = SZ(a), nb = SZ(b);
	vector<int> ret(mod - 1, 0);
	REP(i, na) REP(j, nb) { int idx = (ll)c[i] * d[j] % (mod - 1); ret[idx] = (ret[idx] + (ll)a[i] * b[j]) % mod; }
	return ret;
}

void stress() {
	int mod = 2 * 3 * 5 + 1;
	//int mod = 2 * 17 * 19 + 1;
	//int mod = MOD;
	//int mod = 2 * 3 * 5 * 7 + 1;
	//int mod = 2 * 3 * 5 * 7 * 11 + 1;
	ExponentialResidueConvolution erc(mod);
	REP(rep, 10000) {
		int na = rand() % 100, nb = rand() % 100;
		//int na = 1, nb = 1;
		vector<int> a(na), c(na); REP(i, na) a[i] = rand() % mod, c[i] = rand() % (mod - 1);
		vector<int> b(nb), d(nb); REP(i, nb) b[i] = rand() % mod, d[i] = rand() % (mod - 1);
		vector<int> have = erc.solve(a, b, c, d);
		vector<int> want = bfsolve(a, b, c, d, mod);
		if (have == want) { printf("."); continue; }
		printf("err (%d)\n",rep);
		printf("a:"); REPSZ(i, a) printf(" %d", a[i]); puts("");
		printf("c:"); REPSZ(i, c) printf(" %d", c[i]); puts("");
		printf("b:"); REPSZ(i, b) printf(" %d", b[i]); puts("");
		printf("d:"); REPSZ(i, d) printf(" %d", d[i]); puts("");
		printf("have:"); REPSZ(i, have) printf(" %d", have[i]); puts("");
		printf("want:"); REPSZ(i, want) printf(" %d", want[i]); puts("");
		exit(0);
	}
}

void stress2() {
	int mod = MOD;
	ExponentialResidueConvolution erc(mod);
	REP(rep, 10) {
		int na = MAXN, nb = MAXN;
		vector<int> a(na), c(na); REP(i, na) a[i] = rand() % mod, c[i] = rand() % (mod - 1);
		vector<int> b(nb), d(nb); REP(i, nb) b[i] = rand() % mod, d[i] = rand() % (mod - 1);
		vector<int> have = erc.solve(a, b, c, d);
		printf(".");
	}

}

int main() {
	run();
	//stress();
	//stress2();
	return 0;
}