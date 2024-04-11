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


const int MAXFFT = 1 << 18;

typedef struct C {
	long double x, y; C() { x = y = 0; } C(long double x, long double y) :x(x), y(y) {}
	const inline C operator+(const C &b) const { return C(x + b.x, y + b.y); }
	const inline C operator-(const C &b) const { return C(x - b.x, y - b.y); }
	const inline C operator*(const C &b) const { return C(x*b.x - y*b.y, x*b.y + y*b.x); }
	const inline void operator-=(const C &b) { x -= b.x; y -= b.y; }
	const inline void operator+=(const C &b) { x += b.x; y += b.y; }
} C;

C wpos[MAXFFT], wneg[MAXFFT]; // r=acos(-1)/MAXFFT punit=(cos(r),sin(r)),wpos[i]=punit^i,wneg[i]=punit^(-i)
void initFFT() {
	long double r = acosl(-1) / MAXFFT;
	C punit(cosl(r), sinl(r));
	wpos[0] = C(1, 0); FOR(i, 1, MAXFFT) wpos[i] = wpos[i - 1] * punit;
	wneg[0] = C(1, 0); FOR(i, 1, MAXFFT) wneg[i] = C(0, 0) - wpos[MAXFFT - i];
}
void FFT(C *x, int n, int type) {
	for (int i = 1, j = 0; i<n - 1; ++i) {
		for (int s = n; j ^= s >>= 1, ~j&s;);
		if (i<j) swap(x[i], x[j]);
	}
	for (int d = 0; (1 << d)<n; ++d) {
		int m = 1 << d, m2 = m * 2, step = MAXFFT / m;
		for (int i = 0; i<n; i += m2) {
			C *l = x + i, *r = x + i + m, *w = type == +1 ? wpos : wneg;
			for (int j = 0; j<m; ++j, ++l, ++r, w += step) {
				//printf("(%d,%d,%d) l=(%.2lf,%.2lf) r=(%.2lf,%.2lf) w=(%.2lf,%.2lf) \n", d, i, j, l->x, l->y, r->x, r->y, w->x, w->y);
				C s = *l, t = *r**w;
				*l = s + t, *r = s - t;
			}
		}
	}
}

const int MOD = 1009;

C A[MAXFFT], B[MAXFFT];
void fftmlt(int *a,int na,int *b,int nb,int *c,int nc) {
	int sz = 1; while (sz < na + nb - 1) sz *= 2;
	REP(i, sz) A[i] = C(i < na ? a[i] : 0, 0);
	//printf("A:");  REP(i, sz) printf(" [%.1lf,%.1lf]", A[i].x, A[i].y); puts("");
	FFT(A, sz, +1);
	//printf("A:");  REP(i, sz) printf(" [%.1lf,%.1lf]", A[i].x, A[i].y); puts("");
	REP(i, sz) B[i] = C(i < nb ? b[i] : 0, 0);
	//printf("B:");  REP(i, sz) printf(" [%.1lf,%.1lf]", B[i].x, B[i].y); puts("");
	FFT(B, sz, +1);
	//printf("B:");  REP(i, sz) printf(" [%.1lf,%.1lf]", B[i].x, B[i].y); puts("");
	REP(i, sz) A[i] = A[i] * B[i];
	//printf("A:");  REP(i, sz) printf(" [%.1lf,%.1lf]", A[i].x, A[i].y); puts("");
	FFT(A, sz, -1);
	//printf("A:");  REP(i, sz) printf(" [%.1lf,%.1lf]", A[i].x, A[i].y); puts("");
	REP(i, nc) c[i] = i < sz ? ((ll)floor(A[i].x / sz + 0.5)) % MOD : 0;
}

const int MAXN = 200000;

int n, ncol, want;
int a[MAXN];
int colcnt[MAXN];

int off[MAXN + 1];
int x[2 * MAXN];

int solve(int l, int r) {
	if (l == r) {
		REPE(i, colcnt[l]) x[off[l] + i] = 1;
		return colcnt[l] + 1;
	}
	int m = l + (r - l) / 2;
	int n1 = solve(l, m);
	int n2 = solve(m + 1, r);
	//printf("a:"); REP(i, n1) printf(" %d", x[off[l] + i]); puts("");
	//printf("b:"); REP(i, n2) printf(" %d", x[off[m + 1] + i]); puts("");
	fftmlt(x + off[l], n1, x + off[m + 1], n2, x + off[l], n1 + n2 - 1);
	//printf("c:"); REP(i, n1 + n2 - 1) printf(" %d", x[off[l] + i]); puts("");
	return n1 + n2 - 1;
}

void run() {
	scanf("%d%d%d", &n, &ncol, &want); REP(i, n) scanf("%d", &a[i]), --a[i];
	REP(i, ncol) colcnt[i] = 0; REP(i, n) ++colcnt[a[i]];

	off[0] = 0; REP(i, ncol) off[i + 1] = off[i] + colcnt[i] + 1;
	initFFT();
	solve(0, ncol - 1);
	printf("%d\n", x[off[0] + want]);
}

int main() {
	run();
	return 0;
}