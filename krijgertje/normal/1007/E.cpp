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

const int MAXSTAT = 200 + 1; // 1 for dummy station
const int MAXT = 200;

int nstat, tend; ll cap;
ll init[MAXSTAT], delta[MAXSTAT], lim[MAXSTAT];

ll suminit[MAXSTAT + 1], sumdelta[MAXSTAT + 1];

// dp[i][j][x][y] = minimum trains to survive the first i stations for j-x/2 hours (every train being completely full)
// when x==1, there needs to be a train that picked up passengers from the last station in the last hour
// when y==1, include initial number of passengers
ll dp[MAXSTAT + 1][MAXT + 1][2][2];
void upd(ll &a, const ll b) { if (b < a) a = b; }

ll solve() {
	init[nstat] = delta[nstat] = cap, lim[nstat] = (tend + 1)*cap, ++nstat; // add dummy station
	suminit[0] = 0; REP(i, nstat) suminit[i + 1] = suminit[i] + init[i];
	sumdelta[0] = 0; REP(i, nstat) sumdelta[i + 1] = sumdelta[i] + delta[i];

	REPE(i, nstat) REPE(j, tend) REP(x, 2) REP(y, 2) dp[i][j][x][y] = LLONG_MAX;
	REPE(j, tend) REP(y, 2) dp[0][j][0][y] = 0;
	REPE(i, nstat) REP(y, 2) dp[i][0][0][y] = 0;
	FORE(i, 1, nstat) FORE(j, 1, tend) REP(y, 2) {
		// x=1
		if (y*init[i - 1] + (j - 1)*delta[i - 1] <= lim[i - 1] && dp[i - 1][j - 1][0][y] != LLONG_MAX) { // first train for station i-1
			ll have = y*init[i - 1] + (j - 1)*delta[i - 1], cost = 0; assert(have <= lim[i - 1]);
			ll rembefore = y*suminit[i - 1] + (j - 1)*sumdelta[i - 1] - dp[i - 1][j - 1][0][y] * cap; assert(rembefore >= 0); cost += rembefore / cap + 1;
			ll now = cap*cost - rembefore; assert(now > 0 && now <= cap);
			if (now <= have) upd(dp[i][j][1][y], dp[i - 1][j - 1][0][y] + cost);
		}
		FORE(jj, 1, j - 1) if (dp[i][jj][1][y] != LLONG_MAX && dp[i - 1][j - jj][0][0] != LLONG_MAX) { // previous train for station i-1 at jj-1/2
			ll have = y*suminit[i] + (jj - 1)*sumdelta[i] - dp[i][jj][1][y] * cap; assert(have >= 0 && have <= lim[i - 1]);
			ll dhave = (j - jj)*delta[i - 1], cost1 = 0;
			if (have + dhave > lim[i - 1]) {
				cost1 = (have + dhave - lim[i - 1] + cap - 1) / cap;
				if (cost1*cap > have) continue;
				have -= cost1*cap;
			}
			have += dhave; assert(have <= lim[i - 1]);
			ll rembefore = (j - jj)*sumdelta[i - 1] - dp[i - 1][j - jj][0][0] * cap; assert(rembefore >= 0); ll cost2 = rembefore / cap + 1;
			ll now = cap*cost2 - rembefore; assert(now > 0 && now <= cap);
			if (now <= have) upd(dp[i][j][1][y], dp[i][jj][1][y] + dp[i - 1][j - jj][0][0] + cost1 + cost2);
		}
		// x=0
		if (y*init[i - 1] + j*delta[i - 1] <= lim[i - 1] && dp[i - 1][j][0][y] != LLONG_MAX) { // no trains for station i-1
																							   //if (i == 1 && j == 3 && y == 1) printf("A%lld\n", dp[i - 1][j][0][y]);
			upd(dp[i][j][0][y], dp[i - 1][j][0][y]);
		}
		FORE(jj, y == 0 ? 2 : 1, j) if (dp[i][jj][1][y] != LLONG_MAX && dp[i][j - jj + 1][0][0] != LLONG_MAX) { // previous trains for station i-1 at jj-1/2
			ll have = y*suminit[i] + (jj - 1)*sumdelta[i] - dp[i][jj][1][y] * cap, cost = 0; assert(have >= 0 && have <= lim[i - 1]);
			ll dhave = (j - jj + 1)*delta[i - 1];
			if (have + dhave > lim[i - 1]) {
				ll dcost = (have + dhave - lim[i - 1] + cap - 1) / cap;
				if (dcost*cap > have) continue;
				have -= dcost*cap, cost += dcost;
			}
			have += dhave; assert(have <= lim[i - 1]);
			//if (i == 1 && j == 3 && y == 1) printf("B%lld+%lld+%lld\n", dp[i][jj][1][y], dp[i][j - jj + 1][0][0], cost);
			upd(dp[i][j][0][y], dp[i][jj][1][y] + dp[i][j - jj + 1][0][0] + cost);
		}
	}
	//REPE(i, nstat) REPE(j, tend) { printf("%d,%d:", i, j); REP(x, 2) REP(y, 2) if (dp[i][j][x][y] == LLONG_MAX) printf(" X"); else printf(" %lld", dp[i][j][x][y]); puts(""); }
	return dp[nstat][tend][0][1];
}

void run() {
	scanf("%d%d%lld", &nstat, &tend, &cap);
	REP(i, nstat) scanf("%lld%lld%lld", &init[i], &delta[i], &lim[i]);
	//nstat = 200; tend = 200; cap = 1; REP(i, nstat) init[i] = delta[i] = lim[i] = 1000000000;

	ll ans = solve();
	printf("%lld\n", ans == LLONG_MAX ? -1 : ans);
}

int myrand() { return rand() % 1000 * 1000000 + rand() % 1000 * 1000 + rand() % 1001; }
void stress() {
	REP(rep, 1000) {
		nstat = 200, tend = 200, cap = myrand(); if (cap == 0) ++cap;
		REP(i, nstat) { init[i] = myrand(), delta[i] = myrand(), lim[i] = myrand(); if (init[i] > lim[i]) swap(init[i], lim[i]); if (delta[i] > lim[i]) swap(delta[i], lim[i]); }
		//printf("%d %d %lld\n", nstat, tend, cap);
		//REP(i, nstat) printf("%lld %lld %lld\n", init[i], delta[i], lim[i]);
		solve(); printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}