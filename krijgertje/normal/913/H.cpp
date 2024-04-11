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

const int MAXN = 30;
const int MAXFRACLEN = 6;
const int MAXLEN = 2 + 1 + MAXFRACLEN;
const int MOD = 998244353;

int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret*x%MOD; if ((n >>= 1) == 0) return ret; x = (ll)x*x%MOD; } }
int inv(int x) { return pw(x, MOD - 2); }

typedef struct Pol { 
	vector<int> coef;
	Pol() {} Pol(int cnst) { if (cnst != 0) coef.PB(cnst); }
	int eval(int x) { int ret = 0; for (int i = SZ(coef) - 1; i >= 0; --i) ret = ((ll)ret*x + coef[i]) % MOD; return ret; }
	void mod(int idx, int by) { while (idx >= SZ(coef)) coef.PB(0); coef[idx] = (coef[idx] + by) % MOD; }
	void inc(int cnst) { mod(0, cnst); }
	void sub(int cnst) { mod(0, MOD - cnst); }
	void inc(const Pol &a) { REPSZ(i, a.coef) mod(i, a.coef[i]); }
	void sub(const Pol &a) { REPSZ(i, a.coef) mod(i, MOD - a.coef[i]); }
	void mlt(int by) { REPSZ(i, coef) coef[i] = (ll)coef[i] * by%MOD; }
	Pol integrate() { Pol ret(0); REPSZ(i, coef) ret.mod(i + 1, (ll)coef[i] * inv(i + 1) % MOD); return ret; }
	Pol changevar(int by) { Pol ret(0), x(1); REPSZ(i, coef) { REPSZ(j, x.coef) ret.mod(j, (ll)coef[i] * x.coef[j] % MOD); Pol nx(0); REPSZ(j, x.coef) nx.mod(j + 1, x.coef[j]), nx.mod(j, (ll)by*x.coef[j] % MOD); x = nx; } return ret; }
} Pol;
typedef struct Seg { int lx, rx; Pol pol; Seg(int lx, int rx, Pol pol) :lx(lx), rx(rx), pol(pol) { } } Seg;

int n;
char s[MAXN][MAXLEN + 1];
int x[MAXN];
int one;

vector<Seg> segs;

int area() {
	int ret = 0;
	REPSZ(cseg, segs) {
		Pol a = segs[cseg].pol.integrate();
		int cur = 0;
		cur = (cur + a.eval(segs[cseg].rx)) % MOD;
		cur = (cur + MOD - a.eval(segs[cseg].lx)) % MOD;
		ret = (ret + cur) % MOD;
	}
	ret = (ll)ret*inv(one) % MOD;
	return ret;
}

void run() {
	scanf("%d", &n); REP(i, n) scanf("%s", s[i]);

	one = 1; REP(j, MAXFRACLEN) one *= 10;
	REP(i, n) {
		x[i] = 0; bool havesep = false; int p = MAXFRACLEN;
		for (int j = 0; s[i][j] != '\0'; ++j) if (s[i][j] == '.') havesep = true; else { x[i] = 10 * x[i] + s[i][j] - '0'; if (havesep) --p; } 
		REP(j, p) x[i] *= 10;
	}
	for (int i = n - 2; i >= 0; --i) x[i] = min(x[i], x[i + 1]);
	REP(i, n) x[i] = min(x[i], (i == 0 ? 0 : x[i - 1]) + one);
	//printf("x:"); REP(i, n) printf(" %d", x[i]); puts("");

	segs.clear();
	segs.PB(Seg(0, x[0], Pol(1)));
	FORE(i, 1, n) {
		//printf("%d [%d]:", i, area()); REPSZ(j, segs) { printf(" %d..%d[", segs[j].lx, segs[j].rx); REPSZ(k, segs[j].pol.coef) { if (k != 0) printf(","); printf("%d", segs[j].pol.coef[k]); } printf("]"); } puts("");
		if (i == n) break;
		int cx = 0, lseg = -1, rseg = 0; // seg[lseg].lx<=cx-one<seg[lseg].rx, seg[rseg].lx<=cx<seg[rseg].rx
		vector<Seg> nsegs;
		while (cx < x[i] && lseg < SZ(segs)) {
			int dx = min(min((lseg == -1 ? 0 : segs[lseg].rx) - (cx - one), rseg < SZ(segs) ? segs[rseg].rx - cx : INT_MAX), x[i] - cx);
			Pol pol(0);
			if (lseg == rseg) {
				Pol a = segs[lseg].pol.integrate();
				Pol b = a.changevar(MOD - one);
				pol.inc(a);
				pol.sub(b);
			} else {
				if (lseg >= 0) {
					Pol a = segs[lseg].pol.integrate();
					Pol b = a.changevar(MOD - one);
					pol.inc(a.eval(segs[lseg].rx));
					pol.sub(b);
				}
				if (rseg < SZ(segs)) {
					Pol a = segs[rseg].pol.integrate();
					pol.inc(a);
					pol.sub(a.eval(segs[rseg].lx));
				}
				FORE(cseg, lseg + 1, rseg - 1) {
					Pol a = segs[cseg].pol.integrate();
					pol.inc(a.eval(segs[cseg].rx));
					pol.sub(a.eval(segs[cseg].lx));
				}
			}
			pol.mlt(inv(one));
			nsegs.PB(Seg(cx, cx + dx, pol));
			cx += dx; if (cx - one == (lseg == -1 ? 0 : segs[lseg].rx)) ++lseg; if (rseg < SZ(segs) && cx == segs[rseg].rx) ++rseg;
		}
		segs = nsegs;
	}

	printf("%d\n", area());
}

int main() {
	run();
	return 0;
}