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
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXN = 200000;
const int MAXBIT = 53;
const int MOD = 998244353;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int &a, int b) { if ((a -= b) < 0) a += MOD; }

int n, nbit;
ll a[MAXN];
int ans[MAXBIT + 1];

struct xorbase {
	ull v[64];
	xorbase() { memset(v, 0, sizeof(v)); }
	void add(ull x) { for (int i = 63; i >= 0; --i) if ((x >> i) & 1) { if (v[i] != 0) x ^= v[i]; else { v[i] = x; break; } } }
	void reduce() { REP(i, 64) if (v[i] != 0) FOR(j, i + 1, 64) if ((v[j] >> i) & 1) v[j] ^= v[i]; }
};

vector<int> calcxorbasebitcounts(const vector<ull> &v, int nbit) {
	int nv=SZ(v);
	vector<int> ret(nbit + 1, 0);
	vector<ull> prefix(nv + 1, 0); REP(i, nv) prefix[i + 1] = prefix[i] ^ v[i];
	ull cur = 0;
	FORE(mask, 1, 1 << nv) {
		//printf("cur=%llu (mask=%d ctz=%d popcount=%d)\n", cur, mask, __builtin_ctz(mask), __builtin_popcountll(cur));
		++ret[__builtin_popcountll(cur)];
		cur ^= prefix[__builtin_ctz(mask) + 1];
	}
	return ret;
}

int C[MAXBIT + 1][MAXBIT + 1];

void solve() {
	REPE(i, nbit) { C[i][0] = C[i][i] = 1; FOR(j, 1, i) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD; }
	xorbase base;
	REP(i, n) base.add(a[i]);
	base.reduce();
	vector<ull> v;
	REP(i, 64) if (base.v[i] != 0) v.PB(base.v[i]);
	int k = SZ(v);
	int mlt = 1; REP(i, n - k) mlt = (ll)mlt * 2 % MOD;
	//REPSZ(i, v) { printf("v%d:", i); REP(j, nbit) printf("%d", (int)((v[i] >> j) & 1)); puts(""); }
	if (2 * k <= nbit) {
		vector<int> cnt = calcxorbasebitcounts(v, nbit);
		REPE(i, nbit) ans[i] = cnt[i];
	} else {
		v.clear();
		REP(i, nbit) if (base.v[i] == 0) { ull cur = 1ULL << i; REP(j, 64) if ((base.v[j] >> i) & 1) cur |= 1ULL << j; v.PB(cur); }
		//REPSZ(i, v) { printf("v%d:", i); REP(j, nbit) printf("%d", (int)((v[i] >> j) & 1)); puts(""); }
		assert(SZ(v) == nbit - k);
		vector<int> cnt = calcxorbasebitcounts(v, nbit);
		REPE(j, nbit) REPE(i, nbit) {
			int cur = 0; FORE(k, max(0, i + j - nbit), min(i, j)) { int now = (ll)C[j][k] * C[nbit - j][i - k] % MOD; if (k % 2 == 0) inc(cur, now); else dec(cur, now); }
			//if (cnt[j] != 0) printf("(%d,%d)->%d\n", i, j, cur <= MOD / 2 ? cur : cur - MOD);
			ans[i] = (ans[i] + (ll)cur*cnt[j]) % MOD;
		}
		REP(i, nbit - k) mlt = (ll)mlt*(MOD + 1) / 2 % MOD;
	}
	REPE(i, nbit) ans[i] = (ll)ans[i] * mlt%MOD;
}

void run() {
	scanf("%d%d", &n, &nbit);
	REP(i, n) scanf("%lld", &a[i]);
	solve();
	REPE(i, nbit) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}