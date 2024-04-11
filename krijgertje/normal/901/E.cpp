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

struct MODOPS {
	static ull mult(ull a, ull b, ull m) {
		return norm((ll)a*b - (ll)((long double)a*b / m)*m, m);
		ull oa = a, ob = b, test = norm((ll)a*b - (ll)((long double)a*b / m)*m, m), ret = 0;
		while (true) { if (b & 1) ret = (ret + a) % m; if ((b >>= 1) == 0) break; a = 2 * a%m; }
		if (ret != test) { printf("%llu * %llu mod %llu = %llu vs %llu (%llu %llf %llf %llu %llu)\n", oa, ob, m, ret, test, oa*ob, (long double)oa*ob, (long double)oa*ob / m, (ll)((long double)oa*ob / m), (ull)((long double)oa*ob / m)*m); exit(0); }
		return ret;
	}
	static ull add(ull a, ull b, ull m) { return a < m - b ? a + b : a - (m - b); }
	static ull sub(ull a, ull b, ull m) { return  m - a <= m - b ? a - b : a + (m - b); }
	static ull pw(ull x, ull n, ull m) { ull ret = 1 % m; while (true) { if (n & 1) ret = mult(ret, x, m); if ((n >>= 1) == 0) return ret; x = mult(x, x, m); } }
	static ull norm(ll x, ull m) { return x >= 0 ? x%m : (m - (-x) % m) % m; }
};

const static int miller_rabin_p[7] = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };
struct ALG {
	static ull gcd(ull a, ull b) { if (b == 0) return a; return gcd(b, a%b); }
	static bool miller_rabin(ull p, ull a) { if (p%a == 0) return true; int r = 0; ull s = a - 1; while ((s & 1) == 0) s >>= 1, ++r; ull x = MODOPS::pw(p, s, a); if (x == 1) return true; REP(j, r) { if (x == a - 1) return true; x = MODOPS::mult(x, x, a); }  return false; }
	static bool isprime(ull a) { if (a <= 1) return false; REP(i, 7) if (!miller_rabin(miller_rabin_p[i], a)) return false; return true; }
	static ull pollard_rho(ull a) { for (int c = 1;; ++c) { ull x = 2, y = 2; while (true) { x = MODOPS::mult(x, x, a), x = MODOPS::add(x, c, a); y = MODOPS::mult(y, y, a), y = MODOPS::add(y, c, a); y = MODOPS::mult(y, y, a), y = MODOPS::add(y, c, a); ull d = gcd(x < y ? y - x : x - y, a); if (d == a) break; else if (d > 1) return d; } } }
	static vector<pair<ll, int> > factorize(ull x) {
		vector<pair<ll, int> > ret;
		for (int i = 2; i*i < x&&i < 10000; ++i) if (x%i == 0) { int cnt = 0; while (x%i == 0) x /= i, ++cnt; ret.PB(MP(i, cnt)); if (x == 1) break; }
		if (x == 1) return ret; if (isprime(x)) { ret.PB(MP(x, 1)); return ret; }
		ll d = pollard_rho(x); ret = factorize(d); vector<pair<ll, int> > oth = factorize(x / d); REPSZ(i, oth) ret.PB(oth[i]); sort(ret.begin(), ret.end());
		int nret = 0; REPSZ(i, ret) if (i == 0 || ret[nret - 1].first == ret[i].first) ret[nret - 1].second += ret[i].second; else ret[nret++] = ret[i]; ret.resize(nret); return ret;
	}
	static ull proot(ull p) { vector<pair<ll, int> > fact = factorize(p - 1); FOR(g, 2, p) { bool ok = gcd(g, p) == 1; if (ok) REPSZ(i, fact) { if (MODOPS::pw(g, (p - 1) / fact[i].first, p) == 1) { ok = false; break; } } if (ok) return g; } return -1; }
};

struct NTT {
	ull p, pg;
	void init(ull _p, ull _pg) { p = _p, pg = _pg; }
	void _init(int n,int &nlog,ull &g,vector<ull> &w) {
		assert((p - 1) % n == 0);
		g = MODOPS::pw(pg, (p - 1) / n, p); nlog = 0; while ((1 << nlog) < n) ++nlog; if ((1 << nlog) != n) nlog = -1;
		w = vector<ull>(n); w[0] = 1; FOR(i, 1, n) w[i] = MODOPS::mult(w[i - 1], g, p);
	}
	int fftn, fftnlog; ull fftg; vector<ull> fftw;
	void initfft(int n) { fftn = n, _init(fftn, fftnlog, fftg, fftw); assert(fftnlog != -1); }
	void fft(ull *a, int n, bool inv) {
		if (n != fftn) initfft(n);
		for (int i = 1, j = n >> 1, k, l = j; i < n; j ^= k, ++i) { if (i < j) swap(a[i], a[j]); for (k = l; k&j; j ^= k, k >>= 1); }
		ull *l, *r, *w;
		if (inv) reverse(fftw.begin() + 1, fftw.end());
		for (int hlen = 1, step = n >> 1; hlen < n; hlen <<= 1, step >>= 1) {
			for (int i = 0; i < n; i += (hlen << 1)) {
				l = a + i, r = l + hlen, w = fftw.data();
				REP(off, hlen) {
					ull v = MODOPS::mult(*r, *w, p);
					*r = MODOPS::sub(*l, v, p);
					*l = MODOPS::add(*l, v, p);
					++l, ++r, w += step;
				}
			}
		}
		if (inv) reverse(fftw.begin() + 1, fftw.end());
		if (inv) { ull mlt = MODOPS::pw(n, p - 2, p); REP(i, n) a[i] = MODOPS::mult(a[i], mlt, p); }
	}
	int bsn, bsnn, bsnlog; ull bsg; vector<ull> bsw, bsa, bsb;
	void initbluestein(int n) {
		bsn = n; _init(bsn, bsnlog, bsg, bsw);
		bsnn = 1; while (bsnn < 2 * n) bsnn <<= 1;
		bsa = vector<ull>(bsnn),bsb=vector<ull>(bsnn);
		REP(i, bsnn) { int j = i - n, jj = ((j - (ll)j*j) / 2 % n + n) % n; bsa[i] = bsw[jj], bsb[i] = bsw[jj == 0 ? 0 : n - jj]; }
		fft(bsa.data(), bsnn, false); fft(bsb.data(), bsnn, false);
	}
	void bluestein(ull *a, int n, bool inv) {
		if (n != bsn) initbluestein(n);
		if (inv) reverse(bsw.begin() + 1, bsw.end());
		REP(i, n) a[i] = MODOPS::mult(a[i], bsw[(ll)i*(i + 1) / 2 % n], p); FOR(i, n, bsnn) a[i] = 0;
		fft(a, bsnn, false);
		if (!inv) REP(i, bsnn) a[i] = MODOPS::mult(a[i], bsa[i], p);
		if ( inv) REP(i, bsnn) a[i] = MODOPS::mult(a[i], bsb[i], p);
		fft(a, bsnn, true);
		REP(i, n) a[i] = MODOPS::mult(a[i + n], bsw[(ll)i*(i - 1) / 2 % n], p); FOR(i, n, bsnn) a[i] = 0;
		if (inv) reverse(bsw.begin() + 1, bsw.end());
		if (inv) { ull mlt = MODOPS::pw(n, p - 2, p); REP(i, n) a[i] = MODOPS::mult(a[i], mlt, p); }
	}
};

NTT ntt;

const int MAXN = 100000;
const int MAXNN = 1 << 18; //262144

int n;
int a[MAXN];
int aa[MAXN];
int b[MAXN];
int bb[MAXN];
int c[MAXN];
int cc[MAXN];

ull AA[MAXNN];
ull BB[MAXNN];

ull CC[MAXNN];

vector<ull> fftstupid(const vector<ull> &a, ull g, ull p, bool inv=false) {
	int n = SZ(a); ull x = 1; vector<ull> ret(n, 0);
	if (inv) g = MODOPS::pw(g, n - 1, p);
	REP(i, n) { ull y = 1; REP(j, n) { ret[i] = MODOPS::add(ret[i], MODOPS::mult(a[j], y, p), p); y = MODOPS::mult(y, x, p); } x = MODOPS::mult(x, g, p); }
	if (inv) { ull mlt = MODOPS::pw(n, p - 2, p); REPSZ(i, ret) ret[i] = MODOPS::mult(ret[i], mlt, p); }
	return ret;
}

void run() {
	scanf("%d", &n); REP(i, n) scanf("%d", &b[i]); REP(i, n) scanf("%d", &c[i]);
	FOR(i, 1, n) if ((c[i] - c[i - 1]) % 2 != 0) { printf("0\n"); return; }

	//n = 50000; REP(i, n) b[i] = i == 0 ? 1 : 0; REP(i, n) c[i] = 0; // 1
	int nn = 1; while (nn < 2 * n) nn <<= 1;
	ull g = ALG::gcd(n, nn), dv = nn / g*n; ull mn = (ull)1000 * 10000 * n;
	ull p = dv + 1; while (p < mn || !ALG::isprime(p)) p += dv;
	ntt.init(p, ALG::proot(p));
	//printf("dv=%llu mn=%llu -> p=%llu proot=%llu\n", dv, mn, p, ntt.pg); // return;


	// c[i]=sum(k=0..n-1,(b[k-i]-a[k])^2)=sum(k=0..n-1,b[k-i]^2+a[k]^2-2*b[k-i]*a[k])=sum(k=0..n-1,a[k]^2+b[k]^2)-2*sum(k=0..n-1,b[k-i]*a[k])
	// cc[i]=(c[i]-c[i-1])/2,aa[k]=a[k-1]-a[k],bb[k]=b[n-k]
	// -> c[i]=sum(k=0..n-1,b[k-i+1]*a[k])-sum(k=0..n-1,b[k-i]*a[k])=sum(k=0..n-1,b[k-i]*a[k-1])-sum(k=0..n-1,b[k-i]*a[k])=sum(k=0..n-1,b[k-i]*aa[k])=sum(k=0..n-1,bb[i-k]*aa[k]) -> cc=cycconv(bb,aa)
	REP(i, n) bb[i] = b[(n - i) % n], cc[i] = (c[i] - c[(i + n - 1) % n]) / 2;
	REP(i, n) BB[i] = MODOPS::norm(bb[i], p), CC[i] = MODOPS::norm(cc[i], p);
	ntt.bluestein(BB, n, false);
	ntt.bluestein(CC, n, false);
	REP(i, n) AA[i] = MODOPS::mult(MODOPS::pw(BB[i], p - 2, p), CC[i], p);
	ntt.bluestein(AA, n, true);

	bool ok = true;
	REP(i, n) if (AA[i] < 5000) aa[i] = AA[i]; else if (AA[i] > p - 5000) aa[i] = -(int)(p - AA[i]); else ok = false;
	if (!ok) { printf("0\n"); return; }
	//printf("aa:"); REP(i, n) printf(" %d", aa[i]); puts("");
	a[0] = 0; FOR(i, 1, n) a[i] = a[i - 1] - aa[i];
	//printf("a:"); REP(i, n) printf(" %d", a[i]); puts("");
	// c[0]=sum(k=0..n-1,(b[k]-a[k]-a0)^2)=sum(k=0..n-1,(b[k]-a[k])^2-2*(b[k]-a[k])*a0+a0^2)
	ll x = 0, y = 0, z = -c[0]; REP(i, n) { int diff = b[i] - a[i]; z += diff*diff, y -= 2 * diff, x++; } ll ww = y*y - 4 * x*z, w = (ll)sqrt(1.0*abs(ww));
	//printf("%lld*?^2+%lld*?+%lld=0\n", x, y, z);
	vector<int> a0; if (w*w == ww) REP(i, 2) { ll num = i == 0 ? -y - w : -y + w, den = 2 * x; if (num%den == 0 && (i == 0 || w != 0)) a0.PB(num / den); }
	printf("%d\n", SZ(a0)); sort(a0.begin(), a0.end()); REPSZ(i, a0) { REP(j, n) { if (j != 0) printf(" "); printf("%d", a[j] + a0[i]); } puts(""); }
}

int main() {
	run();
	return 0;
}