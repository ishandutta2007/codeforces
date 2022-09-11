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

const int MAXN = 100000;

int n, nchange;
int gain[MAXN];
int cost[MAXN];

ll suffgain[MAXN];

ll solve() {
	suffgain[n - 1] = gain[n - 1]; for (int i = n - 2; i >= 0; --i) suffgain[i] = suffgain[i + 1] + gain[i];
	ll sumgain = suffgain[0];
	if (nchange == 0) {
		ll ret = 0;
		REP(i, n) ret = max(ret, suffgain[i] - cost[i]);
		return ret;
	} else if (nchange >= 2) {
		ll ret = 0;
		int mncost = cost[0]; REP(i, n - 1) mncost = min(mncost, cost[i]);
		ret = max(ret, sumgain - mncost);
		ret = max(ret, (ll)gain[n - 1] - cost[n - 1]);
		return ret;
	} else {
		ll ret = 0;
		int mncostidx = -1; REP(i, n) if (mncostidx == -1 || cost[i] < cost[mncostidx]) mncostidx = i;
		int mncostidx2 = -1; REP(i, n) if (i != mncostidx && (mncostidx2 == -1 || cost[i] < cost[mncostidx2])) mncostidx2 = i;
		ret = max(ret, sumgain - cost[mncostidx] - cost[mncostidx2]);
		FOR(i, 1, n) ret = max(ret, suffgain[i] - cost[i]);
		int mngain = gain[1]; FOR(i, 1, n - 1) mngain = min(mngain, gain[i]);
		ret = max(ret, sumgain - mngain - cost[0]);
		int mncost = cost[0]; REP(i, n - 1) mncost = min(mncost, cost[i]);
		ret = max(ret, sumgain - gain[n - 1] - mncost);
		return ret;
	}
}

void run() {
	scanf("%d%d", &n, &nchange);
	REP(i, n) scanf("%d", &gain[i]);
	REP(i, n) scanf("%d", &cost[i]);
	printf("%lld\n", solve());
}


int main() {
	run();
	return 0;
}