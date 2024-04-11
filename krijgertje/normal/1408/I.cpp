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

const int MAXBIT = 16;
const int MAXDEC = 16;
const int MOD = 998244353;
const int INV2 = (MOD + 1) / 2;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int& a, int b) { inc(a, MOD - b); }
int neg(int a) { return a == 0 ? 0 : MOD - a; }
int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret * x % MOD; if ((n >>= 1) == 0) return ret; x = (ll)x * x % MOD; } }

struct Res {
	int cnt;
	vector<vector<int>> ways;
	vector<vector<int>> trans;
};

int nval, ndec, nbit;
int val[1 << MAXBIT];
int ans[1 << MAXBIT];

bool have[1 << MAXBIT];
int inv[MAXDEC + 1];
int fac[MAXDEC + 1];
int ifac[MAXDEC + 1];

void wht(int* a, int nbits) {
	REP(bit, nbits) for (int off = 0; off < (1 << nbits); off += 2 << bit) REP(i, 1 << bit) { int x = a[off + i], y = a[off + (1 << bit) + i]; a[off + i] = a[off + (1 << bit) + i] = x; inc(a[off + i], y); dec(a[off + (1 << bit) + i], y); }
}

void verify(const Res& a, int k,char* reason) {
	assert(SZ(a.ways) == SZ(a.trans));
	REPSZ(i, a.trans) {
		assert(SZ(a.ways[i]) == SZ(a.trans[i]));
		vector<int> tmp = a.trans[i];
		wht(tmp.data(), k);
		int mlt = 1; REP(j, k) mlt = (ll)mlt * INV2 % MOD;
		REPSZ(j, tmp) tmp[j] = (ll)tmp[j] * mlt % MOD;
		bool ok = true; REPSZ(j, tmp) if (tmp[j] != a.ways[i][j]) ok = false;
		if (!ok) printf("err %s!\n", reason); else printf(".");
	}
}

Res extend(const Res& a, bool toggle) {
	int sz = SZ(a.trans[0]);
	Res ret;
	ret.cnt = a.cnt;
	//ret.ways = vector<vector<int>>(SZ(a.ways), vector<int>(2 * sz, 0));
	//REPSZ(i, a.ways) REP(j, sz) if (!toggle) ret.ways[i][j] = a.ways[i][j]; else ret.ways[i][j + sz] = a.ways[i][j];
	ret.trans = vector<vector<int>>(SZ(a.trans), vector<int>(2 * sz, 0));
	REPSZ(i, a.trans) REP(j, sz) ret.trans[i][j] = a.trans[i][j], ret.trans[i][j + sz] = (!toggle ? +a.trans[i][j] : neg(a.trans[i][j]));
	return ret;
}

const ll MODUNDOOVERFLOW = (1ULL << 63) / MOD * MOD;
//ll sum = 0; REP(i, n) { sum += (ll)a[i] * b[i]; if (sum < 0) sum -= MODUNDOOVERFLOW; } sum %= MOD;


Res merge(Res& a, Res& b, int k) {
	int lim = min(SZ(a.trans) + SZ(b.trans) - 2, ndec), sz = SZ(a.trans[0]);
	assert(sz == (1 << (k - 1)));
	Res ret;
	ret.cnt = a.cnt + b.cnt;

	/*REPSZ(i, a.ways) wht(a.ways[i].data(), k);
	REPSZ(j, b.ways) wht(b.ways[j].data(), k);
	ret.ways = vector<vector<int>>(lim + 1, vector<int>(sz, 0));
	REPSZ(i, a.ways) REPSZ(j, b.ways) if (i + j <= lim) REP(z, sz) ret.ways[i + j][z] = (ret.ways[i + j][z] + (ll)a.ways[i][z] * b.ways[j][z]) % MOD;
	int mlt = 1; REP(i, k) mlt = (ll)mlt * INV2 % MOD;
	REPSZ(i, ret.ways) REPSZ(j, ret.ways[i]) ret.ways[i][j] = (ll)ret.ways[i][j] * mlt % MOD;
	REPSZ(i, ret.ways) wht(ret.ways[i].data(), k);*/


	ret.trans = vector<vector<int>>(lim + 1, vector<int>(sz, 0));
	vector<vector<ll>> tmp(lim + 1, vector<ll>(sz, 0));
	REPSZ(i, a.trans) REPSZ(j, b.trans) if (i + j <= lim) REP(z, sz) {
		tmp[i + j][z] += (ll)a.trans[i][z] * b.trans[j][z];
		if (tmp[i + j][z] < 0) tmp[i + j][z] -= MODUNDOOVERFLOW;
	}
	REPE(i, lim) REP(z, sz) ret.trans[i][z] = tmp[i][z] % MOD;
	//REPSZ(i, a.trans) REPSZ(j, b.trans) if (i + j <= lim) REP(z, sz) ret.trans[i + j][z] = (ret.trans[i + j][z] + (ll)a.trans[i][z] * b.trans[j][z]) % MOD;

	return ret;
}

Res rec(int k, int offset) { // numbers [offset..min(offset+(1<<k)-1,offset+ndec-1)] unprocessed
	if (k == 0) {
		Res ret;
		ret.cnt = 0;
		//ret.ways = vector<vector<int>>(1, vector<int>(1, 1));
		ret.trans = vector<vector<int>>(1, vector<int>(1, 1));
		//verify(ret, k, "base");
		return ret;
	} else {
		Res a = rec(k - 1, offset);
		Res b = rec(k - 1, offset + (1 << (k - 1)));
		//printf("k=%d offset=%d [%d..%d]\n", k, offset, offset, offset + (1 << k) - 1);
		if (k != 1) a = extend(a, false);
		//verify(a, k, "a");
		if (k != 1) b = extend(b, b.cnt % 2 == 1);
		//verify(b, k, "b");
		//REPSZ(i, a.ways) { printf("\ta%d:", i); REPSZ(j, a.ways[i]) printf(" %d", a.ways[i][j]); puts(""); }
		//REPSZ(i, b.ways) { printf("\tb%d:", i); REPSZ(j, b.ways[i]) printf(" %d", b.ways[i][j]); puts(""); }
		Res ret = merge(a, b, k);
		//verify(ret, k, "abmerge");
		int lo = max(offset + (1 << (k - 1)), offset + ndec), hi = min(offset + (1 << k) - 1, offset + (1 << (k - 1)) + ndec - 1);
		FORE(v, lo, hi) if(have[v]) {
			//printf("\t-> processing %d\n", v);
			Res c;
			c.cnt = 1;
			//c.ways = vector<vector<int>>(ndec + 1, vector<int>(1 << k, 0));
			//REPE(i, ndec) inc(c.ways[i][(v - i) & ((1 << k) - 1)], ifac[i]);
			c.trans = vector<vector<int>>(ndec + 1, vector<int>(1 << (k - 1), 0));
			vector<int> bc(1 << (k - 1), 0); FOR(i, 1, 1 << (k - 1)) bc[i] = bc[i >> 1] + (i & 1);
			REPE(i, ndec) { int x = ((v - i) & ((1 << k) - 1)) >> 1, y = ifac[i]; REP(j, 1 << (k - 1)) c.trans[i][j] = bc[j & x] % 2 == 0 ? y : neg(y); };
			//verify(c, k,"c");
			ret = merge(ret, c, k);
			//verify(ret, k,"cmerge");
		}
		//REPSZ(i, ret.ways) { printf("\tways%d:", i); REPSZ(j, ret.ways[i]) printf(" %d", ret.ways[i][j]); puts(""); }
		return ret;
	}
}

void solve() {
	inv[1] = 1; FORE(i, 2, ndec) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, ndec) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, ndec) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	REP(i, 1 << nbit) have[i] = false;
	REP(i, nval) { assert(!have[val[i]]); have[val[i]] = true; }

	auto res = rec(nbit, 0);
	//printf("cnt=%d\n", res.cnt);
	assert(res.cnt == nval);
	assert(SZ(res.trans) == ndec + 1);
	assert(SZ(res.trans[ndec]) == 1 << (nbit - 1));
	vector<int> tmp = res.trans[ndec];
	wht(tmp.data(), nbit - 1);
	int tot = 1; REP(i, ndec) tot = (ll)tot * nval % MOD;
	int den = pw(tot, MOD - 2);
	int mlt = (ll)fac[ndec] * den % MOD;
	REP(i, nbit - 1) mlt = (ll)mlt * INV2 % MOD;
	REP(i, 1 << nbit) ans[i] = 0;
	int par = 0; REP(i, nval) if (val[i] & 1) par ^= 1;
	if (ndec & 1) par ^= 1;
	REP(i, 1 << (nbit - 1)) ans[(i << 1) ^ par] = (ll)tmp[i] * mlt % MOD;
}

void run() {
	scanf("%d%d%d", &nval, &ndec, &nbit);
	REP(i, nval) scanf("%d", &val[i]);
	solve();
	REP(i, 1 << nbit) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

void stresstime() {
	REP(rep, 1) {
		nbit = MAXBIT, ndec = MAXDEC, nval = (1 << nbit) - ndec;
		REP(i, nval) val[i] = ndec + i;
		solve();
		printf(".");
	}
}

int main() {
	run();
	//stresstime();
	return 0;
}