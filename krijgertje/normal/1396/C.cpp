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

const int MAXN = 1000000;

int n, tpistol, tlaser, tawp, tportal;
int nmonster[MAXN];

ll tdone[MAXN];
ll trevisit[MAXN];

ll dp[MAXN]; // dp[i] = min time to go to level i, clearing all levels before
ll dponce[MAXN]; // dponce[i] = min time to go to level i, needing to return, but already counted time to clear and walk back to all levels before
ll dptwice[MAXN]; // dptwice[i] = min time to go to level i, needint to return and go back to level i, but already counted time to clear and walk back to all levels before


ll solve() {
	REP(i, n) tdone[i] = (ll)nmonster[i] * tpistol + tawp;
	REP(i, n) trevisit[i] = min(tdone[i], min((ll)tlaser, (ll)(nmonster[i] + 1) * tpistol) + tpistol);

	dp[0] = 0; dponce[0] = tportal; dptwice[0] = tportal + tportal;
	FOR(i, 1, n) {
		dp[i] = min(dp[i - 1] + tdone[i - 1] + tportal, dptwice[i - 1] + trevisit[i - 1] + tportal);
		dponce[i] = min(dp[i - 1], dponce[i - 1]) + trevisit[i - 1] + tportal + tportal;
		dptwice[i] = min(dp[i - 1], dptwice[i - 1]) + trevisit[i - 1] + tportal + tportal + tportal;
	}
	//REP(i, n) printf("%d: %lld / %lld || %lld / %lld / %lld\n", i, tdone[i], trevisit[i], dp[i], dponce[i], dptwice[i]);
	ll ret = min(min(dp[n - 1], dponce[n - 1]) + tdone[n - 1], dptwice[n - 1] + trevisit[n - 1]);
	return ret;
}

void run() {
	scanf("%d%d%d%d%d", &n, &tpistol, &tlaser, &tawp, &tportal);
	REP(i, n) scanf("%d", &nmonster[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}