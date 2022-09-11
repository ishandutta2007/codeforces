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

const int MAXN = 50;
const int MAXBITS = 50;

int n, nbits;
ll l[MAXN], r[MAXN];
ll cost[MAXBITS];

// dp[k][i][ii][j][jj] = minimum cost for setting values in [i..j] for bits [k..nbits) assuming a[i]=bound[i][ii] if ii!=2*bits, a[j]=bound[j][jj] if jj!=2*nbits and for not yet fixed i<=q<=j, ceil(bound[q][0]/2^k)<=a[q]/2^k<=floor((bound[q][1]+1)/2^k)-1
//ll bound[MAXN][2*MAXBITS];
//ll dp[MAXBITS + 1][MAXN][2 * MAXBITS + 1][MAXN][2 * MAXBITS + 1];

int nfix[MAXN][MAXBITS + 1];
ll fix[MAXN][MAXBITS + 1][4];
int nxtfix[MAXN][MAXBITS][5];

ll range[MAXN][MAXBITS + 1][2];


ll dp[MAXBITS + 1][MAXN][5][MAXN][5];


void upd(ll& a, ll b) { a = min(a, b); }
ll solve() {
	REP(i, n) REPE(k, nbits) {
		nfix[i][k] = 0;
		ll lo = l[i] >> k, hi = r[i] >> k;
		fix[i][k][nfix[i][k]++] = lo;
		if (lo + 1 < hi && (lo << k) < l[i]) fix[i][k][nfix[i][k]++] = lo + 1;
		if (lo<hi - 1 && (hi << k) + (1LL << k) - 1>r[i]) fix[i][k][nfix[i][k]++] = hi - 1;
		if (lo < hi) fix[i][k][nfix[i][k]++] = hi;
		nfix[i][k] = unique(fix[i][k], fix[i][k] + nfix[i][k]) - fix[i][k];
		//printf("(%d,%d):", i, k); REP(j, nfix[i][k]) printf(" %lld", fix[i][k][j]); puts("");
	}
	REP(i, n) REP(k, nbits) REPE(j, nfix[i][k]) {
		if (j == nfix[i][k]) { nxtfix[i][k][j] = nfix[i][k + 1]; continue; }
		ll want = fix[i][k][j] / 2;
		nxtfix[i][k][j] = 0;
		while (nxtfix[i][k][j] < nfix[i][k + 1] && fix[i][k + 1][nxtfix[i][k][j]] != want) ++nxtfix[i][k][j];
		assert(nxtfix[i][k][j] < nfix[i][k + 1]);
	}
	REP(i, n) REPE(k, nbits) {
		range[i][k][0] = ((l[i] + (1LL << k) - 1) >> k);
		range[i][k][1] = (((r[i] + 1) >> k) - 1);
		//if (range[i][k][0] <= range[i][k][1]) printf("(%d,%d): %lld..%lld\n", i, k, range[i][k][0], range[i][k][1]);
	}

	REP(i, n) REPE(ii, nfix[i][nbits]) FOR(j, i, n) REPE(jj, nfix[j][nbits]) {
		dp[nbits][i][ii][j][jj] = LLONG_MAX;
		bool ok = i < j || ii == jj;
		FORE(q, ii == nfix[i][nbits] ? i : i + 1, jj == nfix[j][nbits] ? j : j - 1) if (range[q][nbits][0] > range[q][nbits][1]) ok = false;
		if (!ok) continue;
		//printf("ok (%d,%d,%d,%d) [%d,%d]\n", i, ii, j, jj, nfix[i][nbits], nfix[j][nbits]);
		if (ii != nfix[i][nbits]) assert(fix[i][nbits][ii] == 0);
		if (jj != nfix[j][nbits]) assert(fix[j][nbits][jj] == 0);
		FORE(q, ii == nfix[i][nbits] ? i : i + 1, jj == nfix[j][nbits] ? j : j - 1) assert(range[q][nbits][0] == 0 && range[q][nbits][1] == 0);
		upd(dp[nbits][i][ii][j][jj], 0);
	}
	for (int k = nbits - 1; k >= 0; --k) {
		FORE(len, 1, n) REPE(i, n - len) REPE(ii, nfix[i][k]) {
			int j = i + len - 1;
			REPE(jj, nfix[j][k]) {
				dp[k][i][ii][j][jj] = LLONG_MAX;
				do {
					ll cur = dp[k + 1][i][nxtfix[i][k][ii]][j][nxtfix[j][k][jj]];
					if (cur == LLONG_MAX) continue;
					if (ii != nfix[i][k] && jj != nfix[j][k] && (fix[i][k][ii] & 1) != (fix[j][k][jj] & 1)) cur += cost[k];
					//if (i != j) printf("\t%lld [%d,%d,%d,%d,%d->%lld]\n", cur, k + 1, i, nxtfix[i][k][ii], j, nxtfix[j][k][jj], dp[k + 1][i][nxtfix[i][k][ii]][j][nxtfix[j][k][jj]]);
					upd(dp[k][i][ii][j][jj], cur);
				} while (false);
				FORE(q, ii == nfix[i][k] ? i : i + 1, jj == nfix[j][k] ? j : j - 1) REP(qq, nfix[q][k]) {
					if (fix[q][k][qq]<range[q][k][0] || fix[q][k][qq]>range[q][k][1]) continue;
					ll a = q == i ? 0 : dp[k][i][ii][q][qq];
					ll b = q == j ? 0 : dp[k][q][qq][j][jj];
					if (a == LLONG_MAX || b == LLONG_MAX) continue;
					//if (i != j) printf("\t%lld+%lld (q=%d qq=%d)\n", a, b, q, qq);
					upd(dp[k][i][ii][j][jj], a + b);
				}
				//if (i != j && dp[k][i][ii][j][jj] != LLONG_MAX) printf("dp[%d][%d=%lld][%d=%lld]=%lld\n", k, i, ii == nfix[i][k] ? -1 : fix[i][k][ii], j, jj == nfix[j][k] ? -1 : fix[j][k][jj], dp[k][i][ii][j][jj]);
			}
		}
	}
	return dp[0][0][nfix[0][0]][n - 1][nfix[n - 1][0]];




	return -1;
	/*REP(i, n) bound[i][0] = l[i], bound[i][1] = r[i];

	FORE(len, 1, n) REPE(i, n - len) REP(ii, 3) REP(jj, 3) {
		int j = i + len - 1;
		bool ok = i < j || ii == jj;
		FORE(q, ii == 2 ? i : i + 1, jj == 2 ? j : j - 1) if (bound[q][0] != 0 || bound[q][1] != (1LL << nbits) - 1) ok = false;
		//if (ii == 2 && i != 0 || jj == 2 && j != n - 1) ok = false;
		dp[nbits][i][ii][j][jj] = ok ? 0 : LLONG_MAX;
	}

	for (int k = nbits - 1; k >= 0; --k) {
		FORE(len, 1, n) REPE(i, n - len) REP(ii, 3) REP(jj, 3) {
			int j = i + len - 1;
			dp[k][i][ii][j][jj] = LLONG_MAX;
			// no internal at bound
			do {
				ll cur = dp[k + 1][i][ii][j][jj];
				if (cur == LLONG_MAX) break;
				if (ii != 2 && jj != 2 && ((bound[i][ii] >> k) & 1) != ((bound[j][jj] >> k) & 1)) cur += cost[k];
				upd(dp[k][i][ii][j][jj], cur);
			} while (false);
			// some internal at bound, iterator over first of them
			FORE(q, ii == 2 ? i : i + 1, jj == 2 ? j : j - 1) REP(qq, 2) {
				ll lo = ((bound[q][0] + (1LL << k) - 1) >> k) << k;
				ll hi = (((bound[q][1] + 1) >> k) - 1) << k;
				if (bound[q][qq]<lo || bound[q][qq]>hi) continue;
				ll a = q == i ? 0 : dp[k][i][ii][q][qq];
				ll b = q == j ? 0 : dp[k][q][qq][j][jj];
				if (a == LLONG_MAX || b == LLONG_MAX) continue;
				upd(dp[k][i][ii][j][jj], a + b);
			}
			if (dp[k][i][ii][j][jj] != LLONG_MAX) printf("dp[%d][%d=%lld][%d=%lld]=%lld\n", k, i, ii == 2 ? -1 : bound[i][ii], j, jj == 2 ? -1 : bound[j][jj], dp[k][i][ii][j][jj]);
		}
	}

	return dp[0][0][2][n - 1][2];*/
}

void run() {
	scanf("%d%d", &n, &nbits);
	REP(i, n) scanf("%lld%lld", &l[i], &r[i]);
	REP(i, nbits) scanf("%lld", &cost[i]);
	printf("%lld\n", solve());
}

ll solvestupid() {
	vector<ll> dp(1 << nbits, LLONG_MAX);
	FORE(j, l[0], r[0]) dp[j] = 0;
	FOR(i, 1, n) {
		vector<ll> ndp(1 << nbits, LLONG_MAX);
		FORE(j, l[i], r[i]) FORE(jj, l[i - 1], r[i - 1]) {
			ll cur = dp[jj];
			if (cur == LLONG_MAX) continue;
			REP(k, nbits) if (((j ^ jj) >> k) & 1) cur += cost[k];
			upd(ndp[j], cur);
		}
		swap(dp, ndp);
	}
	ll ret = LLONG_MAX;
	FORE(j, l[n - 1], r[n - 1]) upd(ret, dp[j]);
	return ret;
}

void stress() {
	REP(rep, 1000) {
		n = rnd() % MAXN + 1;
		nbits = rnd() % 8 + 1;
		REP(i, n) { l[i] = rnd() % (1LL << nbits), r[i] = rnd() % (1LL << nbits); if (l[i] > r[i]) swap(l[i], r[i]); }
		REP(i, nbits) cost[i] = rnd() % 10 + 1;
		ll have = solve();
		ll want = solvestupid();
		if (have == want) { printf("."); continue; }
		printf("err have=%lld want=%lld\n", have, want);
		printf("%d %d\n", n, nbits); REP(i, n) printf("%lld %lld\n", l[i], r[i]); REP(i, nbits) { if (i != 0) printf(" "); printf("%lld", cost[i]); } puts("");
	}
}

int main() {
	run();
	//stress();
	return 0;
}