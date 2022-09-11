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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 50000;
const int MOD = 998244353;
const int PRIMROOT = 3;
const int MAXSZ = 1 << 15;

int n;
int f[4][MAXN + 1]; // f[p][x]=g[p][x]+sum(q,sum(i<x, f[q][i]*c[p][q][x-i]))
int g[4][MAXN + 1];
int c[4][4][MAXN + 1];

int A[2 * MAXSZ];
int B[2 * MAXSZ];
int At[2 * MAXSZ];
int Bt[2 * MAXSZ];
int rootpow[2 * MAXSZ];

int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret*x%MOD; if ((n >>= 1) == 0) return ret; x = (ll)x*x%MOD; } }
void fft(int *to, int *from, int step, int n) {
	if (n == 1) { to[0] = from[0]; return; }
	int h = n / 2;
	fft(to, from, step + 1, h);
	fft(to + h, from + (1 << step), step + 1, h);
	REP(i, h) {
		int e = to[i], o = (ll)to[i + h] * rootpow[i << step] % MOD;
		to[i] = (e + o) % MOD;
		to[i + h] = (e + MOD - o) % MOD;
	}
}
void addprod(int *a, int na, int *b, int nb, int *c, int nc) {
	int SZ = 1; while ((SZ < na || SZ < nb) && SZ < nc) SZ *= 2;
	if (SZ <= 16) { REP(i, na) REP(j, nb) if (i + j < nc) c[i + j] = (c[i + j] + (ll)a[i] * b[j]) % MOD; return; }
	REP(i, 2 * SZ) A[i] = i < na &&i < SZ ? a[i] : 0, B[i] = i < nb&&i < SZ ? b[i] : 0;
	int root = pw(PRIMROOT, (MOD - 1) / (2 * SZ));
	rootpow[0] = 1; FOR(i, 1, 2 * SZ) rootpow[i] = (ll)rootpow[i - 1] * root%MOD;
	fft(At, A, 0, 2 * SZ);
	fft(Bt, B, 0, 2 * SZ);
	REP(i, 2 * SZ) At[i] = (ll)At[i] * Bt[i] % MOD;
	reverse(rootpow + 1, rootpow + 2 * SZ);
	fft(A, At, 0, 2 * SZ);
	reverse(rootpow + 1, rootpow + 2 * SZ);
	int mlt = pw(2 * SZ, MOD - 2);
	REP(i, 2 * SZ) if (i < nc) c[i] = (c[i] + (ll)A[i] * mlt) % MOD;
}

void calc() {
	//REP(p, 4) REP(q, 4) { bool allzero = true; REPE(x, n) if (c[p][q][x] != 0) allzero = false; if (allzero) printf("%d %d\n", p, q); }
	REPE(x, n) REP(p, 4) f[p][x] = g[p][x];
	REPE(x, n) REP(p, 4) {
		//REP(q, 4) REP(i, x) f[p][x] = (f[p][x] + (ll)c[p][q][x - i] * f[q][i]) % MOD;
		REP(q, 4) if ((p + q) % 2 == 0) for (int len = 1; (x + 1) % len == 0; len *= 2) {
			//printf("addprod(c[%d][%d]+%d,%d,f[%d]+%d,%d,f[%d]+%d,%d)\n", p, q, len, min(len, n - len + 1), q, x + 1 - len, len, p, x + 1, n - x);
			addprod(c[p][q] + len, min(len, n - len + 1), f[q] + x + 1 - len, len, f[p] + x + 1, n - x);
		}
		//printf("f[%d][%d][%d]=%d\n", x, p / 2, p % 2, f[p][x]);
	}
}

int h[MAXN + 1];

void run() {
	scanf("%d", &n);
	clock_t START = clock();

	h[0] = 1; FORE(i, 1, n) { h[i] = 0; if (i >= 2) h[i] = (h[i] + h[i - 2]) % MOD; if (i >= 4) h[i] = (h[i] + h[i - 4]) % MOD; }
	REP(y, 2) REP(z, 2) {
		REPE(x, n) g[2 * y + z][x] = (ll)(y + x + z)*(y + x + z) % MOD*h[x] % MOD;
		FORE(i, 1, n) c[2 * y + z][2 * 0 + z][i] = (ll)(y + i - 1)*(y + i - 1) % MOD*h[i - 1] % MOD;
		FORE(i, 3, n) c[2 * y + z][2 * 1 + z][i] = (ll)(y + i - 2)*(y + i - 2) % MOD*h[i - 3] % MOD;
	}
	calc();
	int ret = (f[2 * 0 + 0][n - 1] + f[2 * 1 + 1][n - 3] + (ll)(n - 1)*(n - 1) % MOD*(n - 1) % MOD*h[n - 1] + (ll)(n - 1)*(n - 1) % MOD*(n - 1) % MOD*h[n - 3]) % MOD;
	//printf("%d %d %d^3*%d %d^3*%d -> %d\n", f[n - 1][0][0], f[n - 3][1][1], n - 1, h[n - 1], n - 1, h[n - 3], ret);
	REP(y, 2) REP(z, 2) REPE(i, n - 2 - 2 * y - 2 * z) {
		ret = (ret + (ll)(y + i + z)*(y + i + z) % MOD*(y + i + z) % MOD*h[i] % MOD*f[2 * y + z][n - i - 2 - 2 * y - 2 * z]) % MOD;
		//printf("+=%d^3*%d*%d (%d,%d,%d) -> f[%d][%d][%d]\n", y + i + z, h[i], f[n - i - 2 - 2 * y - 2 * z][y][z], i, y, z, n - i - 2 - 2 * y - 2 * z, y, z);
	}
	printf("%d\n", ret);
	fprintf(stderr, "%lf seconds.\n", 1.0*(clock() - START) / CLOCKS_PER_SEC);
}

int main() {
	run();
	return 0;
}