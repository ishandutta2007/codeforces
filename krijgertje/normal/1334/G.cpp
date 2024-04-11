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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

struct complex {
	double x, y; complex(double x = 0, double y = 0) :x(x), y(y) {}
	const inline complex operator+(const complex& b) const { return complex(x + b.x, y + b.y); }
	const inline complex operator-(const complex& b) const { return complex(x - b.x, y - b.y); }
	const inline complex operator*(const complex& b) const { return complex(x * b.x - y * b.y, x * b.y + y * b.x); }
	const inline void operator-=(const complex& b) { x -= b.x; y -= b.y; }
	const inline void operator+=(const complex& b) { x += b.x; y += b.y; }
};
void fft(complex* x, int n, int type) {
	vector<complex> ww(n); ww[0] = complex(1, 0);
	for (int step = n >> 1; step > 0; step >>= 1) {
		double r = 2 * acos(-1) / (n / step); complex unit(cos(r), sin(r));
		for (int i = 0; i < n; i += 2 * step) ww[i + step] = ww[i] * unit;
	}
	if (type != +1) { for (int i = 1; i <= n - i; ++i) swap(ww[i], ww[n - i]); }
	for (int i = 1, j = 0; i < n - 1; ++i) {
		for (int s = n; j ^= s >>= 1, ~j & s;);
		if (i < j) swap(x[i], x[j]);
	}
	for (int d = 0; (1 << d) < n; ++d) {
		int m = 1 << d, m2 = m * 2, step = n / m / 2;
		for (int i = 0; i < n; i += m2) {
			complex* l = x + i, * r = x + i + m, * w = ww.data();
			for (int j = 0; j < m; ++j, ++l, ++r, w += step) {
				complex s = *l, t = *r * *w;
				*l = s + t, * r = s - t;
			}
		}
	}
}

const int ALPH = 26;
const int MAXLEN = 200000;
const int LOGMAXLEN = 18; // 2^LOGMAXLEN>=MAXLEN

int perm[ALPH];
char s[MAXLEN + 1]; int slen;
char t[MAXLEN + 1]; int tlen;
bool ans[MAXLEN];

int col[ALPH], colidx[ALPH], ncol;
int colsz[ALPH];

char ss[MAXLEN + 1];
char tt[MAXLEN + 1];
int kmp[MAXLEN + 1];

complex sval[ALPH], tval[ALPH];
double colexpect[ALPH];
complex sc[2 << LOGMAXLEN];
complex tc[2 << LOGMAXLEN];
complex resc[2 << LOGMAXLEN];


void calckmp() {
	kmp[0] = kmp[1] = 0;
	FORE(i, 2, slen) { int at = kmp[i - 1]; while (at != 0 && ss[i - 1] != ss[at]) at = kmp[at]; if (ss[i - 1] == ss[at]) ++at; kmp[i] = at; }
}

void fftmult(complex* a, complex* b, complex* c, int n) {
	fft(a, n, +1);
	fft(b, n, +1);
	REP(i, n) c[i] = a[i] * b[i];
	fft(c, n, -1);
	REP(i, n) c[i].x /= n, c[i].y /= n;
}


void solve() {
	REPE(i, tlen - slen) ans[i] = true;

	ncol = 0; REP(i, ALPH) col[i] = -1, colidx[i] = -1;
	REP(s, ALPH) if (col[s] == -1) {
		int c = ncol++; colsz[c] = 0;
		for (int at = s; col[at] == -1; at = perm[at]) col[at] = c, colidx[at] = colsz[c]++;
	}
	//printf("col:"); REP(i, ALPH) printf(" %d.%d", col[i], colidx[i]); puts("");

	REP(i, slen) ss[i] = 'a' + col[s[i] - 'a']; ss[slen] = '\0';
	REP(i, tlen) tt[i] = 'a' + col[t[i] - 'a']; tt[tlen] = '\0';
	//printf("%s\n%s\n", ss, tt);
	calckmp();
	//printf("kmp:"); REPE(i, slen) printf(" %d", kmp[i]); puts("");
	int at = 0;
	REP(i, tlen) { while (at != 0 && tt[i] != ss[at]) at = kmp[at]; if (tt[i] == ss[at]) ++at; if (i + 1 >= slen && at != slen) ans[i + 1 - slen] = false; }

	REP(i, ALPH) {
		double sang = 2 * acos(-1) * colidx[i] / colsz[col[i]]; sval[i] = complex(cos(sang), sin(sang));
		double tang = (acos(-1) - 2 * acos(-1) * colidx[i]) / colsz[col[i]]; tval[i] = complex(cos(tang), sin(tang));
	}
	REP(i, ncol) {
		double ang = acos(-1) / colsz[i]; colexpect[i] = cos(ang);
	}
	REP(i, slen) sc[i] = sval[s[i] - 'a'];
	REP(i, tlen) tc[i] = tval[t[i] - 'a'];
	reverse(sc, sc + slen);
	int lg = 0; while ((1 << lg) < tlen) ++lg;
	FOR(i, slen, 2 << lg) sc[i] = complex();
	FOR(i, tlen, 2 << lg) tc[i] = complex();
	fftmult(sc, tc, resc, 2 << lg);
	//printf("lg=%d\n", lg);

	double expect = 0; REP(i, slen) expect += colexpect[col[s[i] - 'a']];
	//printf("expect=%lf\n", expect);
	//REPE(off, tlen - slen) { complex sum; REP(i, slen) sum += sc[slen - i - 1] * tc[off + i]; printf("%d: want %lf %s have %lf\n", off, sum.x, sum.x >= expect ? "!!!" : "-", resc[slen - 1 + off].x); }
	REPE(off, tlen - slen) if (resc[slen - 1 + off].x < expect - 1e-6) ans[off] = false;


}

void run() {
	REP(i, ALPH) scanf("%d", &perm[i]), --perm[i];
	scanf("%s", s); slen = strlen(s);
	scanf("%s", t); tlen = strlen(t);
	solve();
	REPE(i, tlen - slen) printf("%d", ans[i] ? 1 : 0); puts("");
}

int main() {
	run();
	return 0;
}