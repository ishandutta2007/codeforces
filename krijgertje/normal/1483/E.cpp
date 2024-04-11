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

const int DPLIM = 50;
const ll MLIM = 100000000000000LL;

// dp[i][j] = number of values we can differentiable in i moves, starting with a budget of j (assuming we have enough 'spare change') 
ll dp[DPLIM + 1][DPLIM + 1];
ll need[DPLIM + 1][DPLIM + 1];

void precalc() {
	REPE(j, DPLIM) dp[0][j] = 1;
	FORE(i, 1, DPLIM) REPE(j, DPLIM) dp[i][j] = j == 0 ? dp[i - 1][j + 1] : min(MLIM + 1, dp[i - 1][j - 1] + dp[i - 1][min(j + 1, DPLIM)]);
	//REPE(i, DPLIM) { printf("dp[%d]:", i); REP(j, 20) printf(" %lld", dp[i][j]); puts(""); }
	REPE(j, DPLIM) need[0][j] = 0;
	FORE(i, 1, DPLIM) REPE(j, DPLIM) need[i][j] = dp[i][j] + need[i - 1][min(j + 1, DPLIM)];
	//REPE(i, DPLIM) { printf("need[%d]:", i); REP(j, 20) printf(" %lf", 1.0 * need[i][j] / dp[i][j]); puts(""); }
}

ll have;
ll sure;
bool query(ll x) {
	assert(x <= sure || have >= x);
	printf("? %lld\n", x); fflush(stdout);
	char buff[100];
	scanf("%s", buff);
	assert(strcmp(buff, "Fired!") != 0);
	if (strcmp(buff, "Lucky!") == 0 || strcmp(buff, "1") == 0) { sure = max(sure, x); have += x; return true; }
	if (strcmp(buff, "Fraudster!") == 0 || strcmp(buff, "0") == 0) { have -= x; return false; }
	assert(false); return false;
}


ll solve() {
	ll lo = 0, hi = 1;
	sure = 0; have = 1;
	while (true) {
		if (lo >= hi) { assert(lo == MLIM); return MLIM; }
		if (!query(hi)) break;
		lo = hi, hi = min(2 * hi, MLIM);
	}
	while (lo + 1 < hi) {
		int budget = max(1, (int)min((ll)DPLIM, have / hi));
		ll need = hi - lo;
		int at = 0; while (dp[at][budget] < need) ++at;
		ll mi = min(lo + dp[at - 1][budget - 1], MLIM);
		while (have < mi) assert(query(lo));
		if (query(mi)) lo = mi; else hi = mi;
	}
	return lo;
}

void run() {
	ll ans = solve();
	printf("! %lld\n", ans); fflush(stdout);
}


int main() {
	precalc();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}