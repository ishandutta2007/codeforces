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

const int MAXN = 200000;
const int MAXQ = 200000;
const int MOD = 998244353;
const int INV2 = (MOD + 1) / 2;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n, nq;
string s;
int qidx[MAXQ]; char qc[MAXQ]; int qans[MAXQ];

int inv[MAXN + 1];
int fac[MAXN + 1];
int ifac[MAXN + 1];
int ip2[MAXN + 1];

int choose(int n, int k) { if (k<0 || k>n) return 0; return (ll)fac[n] * ifac[k] % MOD*ifac[n - k] % MOD; }

// i*choose(x,i) = i * fac[x]*ifac[i]*ifac[x-i] = x * fac[x-1]*ifac[i-1]*ifac[x-i] = x * choose(x-1,i-1) when i>=1 and x>=1, but also fine for i=0
// choose(x,i) = choose(x-1,i-1)+choose(x-1,i) when i>=1 and i<=x-1, but also fine for all x>=1

int calc(int evenq, int oddq, int evenw, int oddw) {
	assert(evenq + oddq >= 1);
	int half = n / 2;
	int num = 0;
	// bal = even white - odd white
	int lo = evenw - oddq - oddw; if (lo % 2 != 0) ++lo;
	int hi = evenq + evenw - oddw; if (hi % 2 != 0) --hi;
	// i=offset+bal
	int offset = oddq - evenw + oddw;

	if (evenq + oddq == 1) {
		for (int i = offset + lo; i <= offset + hi; i += 2) {
			num = (num + (ll)abs(i - offset)*choose(evenq + oddq, i)) % MOD;
		}
	} else {
		int amlt = evenq + oddq, an = evenq + oddq - 2, alo = offset + max(2, lo) - 2, ahi = offset + hi - 1; if ((alo & 1) == (ahi & 1)) --ahi; alo = max(alo, 0);
		int bmlt = MOD - offset, bn = evenq + oddq - 1, blo = offset + max(2, lo) - 1, bhi = offset + hi; if ((blo & 1) == (bhi & 1)) --bhi; blo = max(blo, 0);
		int cmlt = MOD - evenq - oddq, cn = evenq + oddq - 2, clo = offset + lo - 2, chi = offset + min(-2, hi) - 1; if ((clo & 1) == (chi & 1)) ++clo; clo = max(clo, 0);
		int dmlt = MOD + offset, dn = evenq + oddq - 1, dlo = offset + lo - 1, dhi = offset + min(-2, hi); if ((dlo & 1) == (dhi & 1)) ++dlo; dlo = max(dlo, 0);

		FORE(i, alo, ahi) num = (num + (ll)amlt*choose(an, i)) % MOD;
		FORE(i, blo, bhi) num = (num + (ll)bmlt*choose(bn, i)) % MOD;
		FORE(i, clo, chi) num = (num + (ll)cmlt*choose(cn, i)) % MOD;
		FORE(i, dlo, dhi) num = (num + (ll)dmlt*choose(dn, i)) % MOD;

		//for (int i = offset + max(2, lo); i <= offset + hi; i += 2) {
			//num = (num + (ll)(evenq + oddq)*choose(evenq + oddq - 2, i - 2)) % MOD;
			//num = (num + (ll)(evenq + oddq)*choose(evenq + oddq - 2, i - 1)) % MOD;
			//num = (num + (ll)(MOD - offset)*choose(evenq + oddq - 1, i - 1)) % MOD;
			//num = (num + (ll)(MOD - offset)*choose(evenq + oddq - 1, i)) % MOD;
		//}
		//for (int i = offset + min(-2, hi); i >= offset + lo; i -= 2) {
			//num = (num + (ll)(MOD - evenq - oddq)*choose(evenq + oddq - 2, i - 2)) % MOD;
			//num = (num + (ll)(MOD - evenq - oddq)*choose(evenq + oddq - 2, i - 1)) % MOD;
			//num = (num + (ll)(MOD + offset)*choose(evenq + oddq - 1, i - 1)) % MOD;
			//num = (num + (ll)(MOD + offset)*choose(evenq + oddq - 1, i)) % MOD;
		//}
	}
	return (ll)num*ip2[evenq + oddq] % MOD;
}

void solve() {
	inv[1] = 1; FORE(i, 2, n) inv[i] = (ll)(MOD - MOD / i)*inv[MOD%i] % MOD;
	fac[0] = 1; FORE(i, 1, n) fac[i] = (ll)fac[i - 1] * i%MOD;
	ifac[0] = 1; FORE(i, 1, n) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;
	ip2[0] = 1; FORE(i, 1, n) ip2[i] = (ll)ip2[i - 1] * INV2%MOD;

	int evenq = 0, oddq = 0, evenw = 0, oddw = 0;
	REP(i, n) if (s[i] == '?') (i % 2 == 0 ? evenq : oddq)++; else if (s[i] == 'w') (i % 2 == 0 ? evenw : oddw)++;

	qans[0] = calc(evenq, oddq, evenw, oddw);
	REP(i, nq) {
		int idx = qidx[i]; char c = qc[i];
		if (s[idx] == '?') (idx % 2 == 0 ? evenq : oddq)--; else if (s[idx] == 'w') (idx % 2 == 0 ? evenw : oddw)--;
		s[idx] = c;
		if (s[idx] == '?') (idx % 2 == 0 ? evenq : oddq)++; else if (s[idx] == 'w') (idx % 2 == 0 ? evenw : oddw)++;
		qans[i + 1] = calc(evenq, oddq, evenw, oddw);
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	cin >> s;
	REP(i, nq) scanf("%d %c", &qidx[i], &qc[i]), --qidx[i];
	solve();
	REPE(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}