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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXSPELL = 100000;
const int MAXX = 2 * MAXSPELL;
const int MAXLIM = 8;

int nspell, nchild, lim;
int l[MAXSPELL], r[MAXSPELL];

int x[MAXX], nx;
vector<int> who[MAXX];

int dp[1 << MAXLIM];
int ndp[1 << MAXLIM];
int bitcount[1 << MAXLIM];

int id[MAXSPELL];

void upd(int& a, int b) { a = max(a, b); }
int solve() {
	nx = 0; REP(i, nspell) x[nx++] = l[i], x[nx++] = r[i];
	sort(x, x + nx); nx = unique(x, x + nx) - x;
	REP(i, nspell) l[i] = lower_bound(x, x + nx, l[i]) - x, r[i] = lower_bound(x, x + nx, r[i]) - x;

	REP(i, nx) who[i].clear();
	REP(i, nspell) FOR(j, l[i], r[i]) who[j].PB(i);
	REP(i, nx) assert(SZ(who[i]) <= lim);

	bitcount[0] = 0; FOR(i, 1, 1 << lim) bitcount[i] = bitcount[i >> 1] + (i & 1);
	REP(mask, 1 << SZ(who[0])) dp[mask] = bitcount[mask] % 2 == 1 ? x[1] - x[0] : 0;
	REP(i, nspell) id[i] = -1;
	FOR(i, 1, nx - 1) {
		REP(mask, 1 << SZ(who[i])) ndp[mask] = INT_MIN;
		REPSZ(j, who[i]) id[who[i][j]] = j;
		REP(mask, 1 << SZ(who[i - 1])) if (dp[mask] != INT_MIN) {
			int nmask = 0;
			REPSZ(j, who[i - 1]) if ((mask & (1 << j)) != 0 && id[who[i - 1][j]] != -1) nmask |= 1 << id[who[i - 1][j]];
			upd(ndp[nmask], dp[mask]);
		}
		REPSZ(j, who[i - 1]) id[who[i - 1][j]] = -1;
		REPSZ(j, who[i]) if (id[who[i][j]] == j) REP(mask, 1 << SZ(who[i])) if ((mask & (1 << j)) == 0) upd(ndp[mask ^ (1 << j)], ndp[mask]);

		REP(mask, 1 << SZ(who[i])) if (bitcount[mask] % 2 == 1) ndp[mask] += x[i + 1] - x[i];
		REPSZ(j, who[i]) id[who[i][j]] = -1;
		REP(mask, 1 << SZ(who[i])) dp[mask] = ndp[mask];
	}
	int ret = INT_MIN; REP(mask, 1 << SZ(who[nx - 2])) upd(ret, dp[mask]); return ret;
}

void run() {
	scanf("%d%d%d", &nspell, &nchild, &lim);
	REP(i, nspell) scanf("%d%d", &l[i], &r[i]), --l[i];
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}