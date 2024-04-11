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
const int MAXBIT = 35;
const int MOD = 998244353;
const int LIM1 = 20;
const int LIM2 = MAXBIT - LIM1 - 1;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n, nbit;
ll a[MAXN];
int ans[MAXBIT + 1];

ll indep[MAXBIT]; int nindep;

ll val[MAXBIT];
int ways[MAXBIT + 1][1 << LIM2];

void solve() {
	REPE(i, nbit) ans[i] = 0;

	nindep = 0;
	int mlt = 1;
	REP(i, n) {
		ll x = a[i];
		REP(j, nindep) if ((x ^ indep[j]) < x) x ^= indep[j];
		if (x == 0) { mlt = (ll)2 * mlt % MOD; continue; }
		REP(j, nindep) if ((x ^ indep[j]) < indep[j]) indep[j] ^= x;
		indep[nindep++] = x;
	}
	//printf("indep:\n"); REP(i, nindep) { REP(j, nbit) printf("%d", (int)((indep[i] >> (nbit - j - 1)) & 1)); puts(""); }

	ll have = 0; int nfixed = nbit - nindep;
	REP(i, nindep) { int cur = 0; while ((2LL << cur) <= indep[i]) ++cur; assert((have & (1LL << cur)) == 0); have |= 1LL << cur; }
	REP(i, nindep) { ll cur = 0; int at = 0; REP(j, nbit) if ((have & (1LL << j)) == 0) cur |= ((indep[i] >> j) & 1) << (at++); assert(at == nfixed); val[i] = cur; }
	if (nindep <= LIM1) { // nindep<=LIM1
		REP(mask, 1 << nindep) {
			int cnt = 0; ll fixed = 0;
			REP(i, nindep) if (mask & (1 << i)) ++cnt, fixed ^= val[i];
			REP(i, nfixed) if (fixed & (1LL << i)) ++cnt;
			inc(ans[cnt], mlt);
		}
	} else { // nfixed<=LIM2
		REPE(k, nindep) REP(mask, 1 << nfixed) ways[k][mask] = 0;
		inc(ways[0][0], mlt);
		//REP(i, nindep) printf("%lld\n", val[i]);
		REP(i, nindep) for (int k = i; k >= 0; --k) { REP(mask, 1 << nfixed) inc(ways[k + 1][mask ^ val[i]], ways[k][mask]); }
		REPE(k, nindep) REP(mask, 1 << nfixed) { int cnt = k; REP(j, nfixed) if (mask & (1 << j)) ++cnt; inc(ans[cnt], ways[k][mask]); }
	}
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