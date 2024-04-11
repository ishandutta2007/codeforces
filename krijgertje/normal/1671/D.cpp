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

const int MAXN = 200000;

int n, upto;
int a[MAXN];

ll solve() {
	int lo = a[0];
	FOR(i, 1, n) lo = min(lo, a[i]);
	int hi = a[0];
	FOR(i, 1, n) hi = max(hi, a[i]);
	ll init = 0;
	REP(i, n - 1) init += abs(a[i + 1] - a[i]);
	ll ret = LLONG_MAX;
	FORE(mntimes, 1, 2) FORE(mxtimes, 1, 2) {
		ll cur = init;
		if (1 < lo) cur += mntimes == 1 ? min(a[0], a[n - 1]) - 1 : 2 * (lo - 1);
		if (upto > hi) cur += mxtimes == 1 ? upto - max(a[0], a[n - 1]) : 2 * (upto - hi);
		//printf("\t%d %d -> %lld [init=%lld lo=%d hi=%d]\n", mntimes, mxtimes, cur, init, lo, hi);
		ret = min(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &upto);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}