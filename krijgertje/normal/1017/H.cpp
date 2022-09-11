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

const int MAXN = 100000;
const int MAXZ = 447;
const int MAXTYPE = 100000;
const int MAXQ = 100000;
const int MAXK = 100;
const int MAXKVAL = 100000;
const int MOD = 998244353;
struct Q { int b, l, r, k, id; };
bool operator<(const Q &u, const Q &v) { if (u.b != v.b) return u.b < v.b; return u.b % 2 == 0 ? u.r<v.r : u.r>v.r; }
int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret*x%MOD; if ((n >>= 1) == 0) return ret; x = (ll)x*x%MOD; } }

int n, ntype, nq;
int type[MAXN];
Q q[MAXQ];
int ans[MAXQ];

int inv[MAXKVAL + MAXN + 1];
int fac[MAXKVAL + MAXN + 1];
int ifac[MAXKVAL + MAXN + 1];
int tmp[MAXN >= MAXTYPE ? MAXN : MAXTYPE], ntmp;

int zval[MAXZ], nz;
int tz[MAXTYPE];
int tcnt[MAXTYPE];
int freq[MAXZ][MAXN + 1];
bool incur[MAXZ][MAXN + 1];
pair<int, int> cur[3 * MAXN]; int ncur;

int kval[MAXK], nk;
int kfalling[MAXK][MAXN + 1];

void mod(int idx, int by) {
	//printf("mod(%d,%d)\n", idx, by);
	--freq[tz[type[idx]]][tcnt[type[idx]]];
	tcnt[type[idx]] += by;
	++freq[tz[type[idx]]][tcnt[type[idx]]];
	if (tcnt[type[idx]] != 0 && !incur[tz[type[idx]]][tcnt[type[idx]]]) cur[ncur++] = MP(tz[type[idx]], tcnt[type[idx]]), incur[tz[type[idx]]][tcnt[type[idx]]] = true;
}
int calc(int k) {
	int nncur = 0; REP(i, ncur) if (freq[cur[i].first][cur[i].second] == 0) incur[cur[i].first][cur[i].second] = false; else cur[nncur++] = cur[i]; ncur = nncur;
	int ret = 1;
	REP(i, ncur) {
		int have = zval[cur[i].first], need = cur[i].second, exp = freq[cur[i].first][cur[i].second];
		//printf("\thave=%d need=%d exp=%d\n", have, need, exp);
		// ret*=((k+have)*(k+have-1)*...*(k+have-need+1))^exp
		ret = (ll)ret*pw((ll)fac[k + have] * ifac[k + have - need] % MOD, exp) % MOD;
	}
	return ret;
}

void solve() {
	inv[1] = 1; FORE(i, 2, MAXKVAL + MAXN) inv[i] = (ll)(MOD - MOD / i)*inv[MOD%i] % MOD;
	fac[0] = 1; FORE(i, 1, MAXKVAL + MAXN) fac[i] = (ll)fac[i - 1] * i%MOD;
	ifac[0] = 1; FORE(i, 1, MAXKVAL + MAXN) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	REP(i, ntype) tcnt[i] = 0; REP(i, n) ++tcnt[type[i]];
	ntmp = 0; REP(i, ntype) if (tcnt[i] != 0) tmp[ntmp++] = tcnt[i]; sort(tmp, tmp + ntmp); ntmp = unique(tmp, tmp + ntmp) - tmp;
	assert(ntmp <= MAXZ); nz = ntmp; REP(i, nz) zval[i] = tmp[i];
	REP(i, ntype) tz[i] = tcnt[i] == 0 ? -1 : lower_bound(zval, zval + nz, tcnt[i]) - zval;

	ntmp = 0; REP(i, nq) tmp[ntmp++] = q[i].k; sort(tmp, tmp + ntmp); ntmp = unique(tmp, tmp + ntmp) - tmp;
	assert(ntmp <= MAXK); nk = ntmp; REP(i, nk) kval[i] = tmp[i];
	REP(i, nk) { kfalling[i][0] = 1; REP(j, n) kfalling[i][j + 1] = (ll)kfalling[i][j] * ((ll)kval[i] * ntype%MOD + j + 1) % MOD; }

	int bsz = sqrt(1.0*n); REP(i, nq) q[i].b = q[i].l / bsz;
	sort(q, q + nq);
	int l = 0, r = 0;
	ncur = 0; REP(i, ntype) tcnt[i] = 0; REP(i, nz) REPE(j, n) freq[i][j] = 0, incur[i][j] = false; REP(i, ntype) if (tz[i] != -1) ++freq[tz[i]][tcnt[i]];
	REP(i, nq) {
		while (l > q[i].l) mod(--l, +1);
		while (r < q[i].r) mod(r++, +1);
		while (l < q[i].l) mod(l++, -1);
		while (r > q[i].r) mod(--r, -1);
		int k = q[i].k, kid = lower_bound(kval, kval + nk, k) - kval;
		int a = calc(k);
		int b = (ll)kfalling[kid][n - (r - l)];
		//printf("%d: a=%d b=%d\n", q[i].id, a, b);
		ans[q[i].id] = (ll)a*b%MOD;
	}
}

void run() {
	scanf("%d%d%d", &n, &ntype, &nq);
	REP(i, n) scanf("%d", &type[i]),--type[i];
	REP(i, nq) scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].k), --q[i].l, q[i].id = i;
	solve();
	REP(i, nq) printf("%d\n", ans[i]);
}

void stress() {
	n = MAXN; ntype = MAXTYPE; nq = MAXQ;
	REP(i, n) type[i] = rand() % ntype;
	REP(i, nq) { q[i].l = rand() % n, q[i].r = rand() % n, q[i].k = rand() % MAXK, q[i].id = i; if (q[i].l > q[i].r) swap(q[i].l, q[i].r); ++q[i].r; }
	solve();
	printf(".");
}

int main() {
	run();
	//stress();
	return 0;
}