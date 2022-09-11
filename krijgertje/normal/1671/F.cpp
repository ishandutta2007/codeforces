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
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MOD = 998244353;
const int MAXINV = 11;
const int MAXDEC = 11;
const int MAXLEN = MAXINV + 1;
const int MAXCNT = MAXINV;
const int MAXSUM = 2 * MAXINV;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }

int prefixlen[1 << MAXLEN];
int bc[1 << MAXLEN];
int dp[1 << MAXLEN][MAXLEN][MAXINV + 1][MAXDEC + 1];

int one[MAXLEN + 1][MAXINV + 1][MAXDEC + 1];
int many[MAXCNT + 1][MAXSUM + 1][MAXINV + 1][MAXDEC + 1];

int inv[MAXCNT + 1];


void precalc() {
	inv[1] = 1; FORE(i, 2, MAXCNT) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;

	memset(prefixlen, -1, sizeof(prefixlen));
	REPE(len, MAXLEN) prefixlen[(1 << len) - 1] = len;
	bc[0] = 0; FOR(i, 1, 1 << MAXLEN) bc[i] = bc[i >> 1] + (i & 1);
	memset(dp, 0, sizeof(dp));
	REP(first, MAXLEN) inc(dp[1 << first][first][0][0], 1);
	FOR(mask, 1, 1 << MAXLEN) REP(last, MAXLEN) REPE(cinv, MAXINV) REPE(cdec, MAXDEC) {
		int ways = dp[mask][last][cinv][cdec];
		if (ways == 0) continue;
		if (prefixlen[mask] == -1) REP(cur, MAXLEN) if ((mask & (1 << cur)) == 0) {
			int ninv = cinv + bc[mask >> cur], ndec = cdec + (last > cur ? 1 : 0);
			if (ninv > MAXINV || ndec > MAXDEC) continue;
			inc(dp[mask | (1 << cur)][cur][ninv][ndec], ways);
		}
	}
	memset(one, 0, sizeof(one));
	FORE(len, 2, MAXLEN) REPE(cinv, MAXINV) REPE(cdec, MAXDEC) {
		int ways = 0;
		REP(last, MAXLEN) inc(ways, dp[(1 << len) - 1][last][cinv][cdec]);
		if (ways == 0) continue;
		//printf("len=%d cinv=%d cdec=%d: ways=%d\n", len, cinv, cdec, ways);
		one[len][cinv][cdec] = ways;
	}
	memset(many, 0, sizeof(many));
	inc(many[0][0][0][0], 1);
	REPE(cnt, MAXCNT) REPE(sum, MAXSUM) REPE(cinv, MAXINV) REPE(cdec, MAXDEC) {
		int ways = many[cnt][sum][cinv][cdec];
		if (ways == 0) continue;
		FORE(len, 2, MAXLEN) REPE(dinv, MAXINV) REPE(ddec, MAXDEC) {
			int times = one[len][dinv][ddec];
			if (times == 0) continue;
			int ncnt = cnt + 1, nsum = sum + len, ninv = cinv + dinv, ndec = cdec + ddec;
			if (ninv > MAXINV || ndec > MAXDEC) continue;
			//if (!(ncnt <= MAXCNT && nsum <= MAXSUM)) printf("%d %d %d %d | %d %d %d -> %d %d %d %d\n", cnt, sum, cinv, cdec, len, dinv, ddec, ncnt, nsum, ninv, ndec);
			assert(ncnt <= MAXCNT && nsum <= MAXSUM);
			inc(many[ncnt][nsum][ninv][ndec], (ll)ways * times % MOD);
		}
	}
}

int n, wantinv, wantdec;


int choose(int n, int k) {
	assert(k <= MAXCNT);
	int ret = 1;
	REP(i, k) ret = (ll)ret * (n - i) % MOD * inv[i + 1] % MOD;
	return ret;
}

int solve() {
	int ret = 0;
	REPE(cnt, MAXCNT) REPE(sum, MAXSUM) {
		if (sum > n) continue;
		int ways = many[cnt][sum][wantinv][wantdec];
		if (ways == 0) continue;
		ways = (ll)ways * choose(n - (sum - cnt), cnt) % MOD;
		//printf("\tcnt=%d sum=%d -> ways=%d\n", cnt, sum, ways);
		inc(ret, ways);
	}
	return ret;
}

void run() {
	scanf("%d%d%d", &n, &wantinv, &wantdec);
	printf("%d\n", solve());
}

void stress() {
	for (n = 1; n <= 10; ++n) {
		vector<int> p(n); REP(i, n) p[i] = i;
		vector<vector<int>> memwant(MAXINV + 1, vector<int>(MAXDEC + 1, 0));
		do {
			int cinv = 0, cdec = 0;
			REP(i, n) FOR(j, i + 1, n) if (p[j] < p[i]) ++cinv;
			REP(i, n - 1) if (p[i + 1] < p[i]) ++cdec;
			if (cinv <= MAXINV && cdec <= MAXDEC) inc(memwant[cinv][cdec], 1);

		} while (next_permutation(p.begin(), p.end()));
		for (wantinv = 0; wantinv <= MAXINV; ++wantinv) for (wantdec = 0; wantdec <= MAXDEC; ++wantdec) {
			int have = solve();
			int want = memwant[wantinv][wantdec];
			if (have != want) printf("%d %d %d: have=%d want=%d\n", n, wantinv, wantdec, have, want);
		}
	}
}

int main() {
	precalc();
	//stress();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}