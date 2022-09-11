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

int n, eateach;
int a[MAXN], b[MAXN];
int aeat[MAXN], beat[MAXN];

ll solve() {
	ll amxeat = 0, bmxeat = 0;
	REP(i, n) amxeat += min(a[i], eateach), bmxeat += min(b[i], eateach);
	ll asum = 0, bsum = 0;
	REP(i, n) asum += a[i], bsum += b[i];
	ll sum = asum + bsum, eattotal = (ll)eateach * n, rem = sum - eattotal;
	ll targetkeep1 = rem / 2, targetkeep2 = rem - targetkeep1;
	ll amnrem = asum - amxeat, bmnrem = bsum - bmxeat;
	if (amnrem >= targetkeep2) {
		REP(i, n) aeat[i] = min(a[i], eateach), beat[i] = eateach - aeat[i];
		ll arem = amnrem, brem = bsum - (eattotal - amxeat);
		return abs(arem - brem);
	} else if (bmnrem >= targetkeep2) {
		REP(i, n) beat[i] = min(b[i], eateach), aeat[i] = eateach - beat[i];
		ll brem = bmnrem, arem = asum - (eattotal - bmxeat);
		return abs(arem - brem);
	} else {
		assert(amnrem <= targetkeep1 && bmnrem <= targetkeep1);
		ll aleft = asum - targetkeep1, bleft = bsum - targetkeep2;
		REP(i, n) {
			aeat[i] = min(aleft, (ll)min(a[i], eateach));
			beat[i] = min(bleft, (ll)min(b[i], eateach));
			aleft -= aeat[i];
			bleft -= beat[i];
		}
		assert(aleft == 0 && bleft == 0);
		int at = 0;
		//printf("before\n"); REP(i, n) printf("%d %d\n", aeat[i], beat[i]);
		REP(i, n) while (aeat[i] + beat[i] > eateach) {
			while (at < n && aeat[at] + beat[at] >= eateach) ++at;
			assert(at < n);
			int acur = min({ aeat[i] + beat[i] - eateach, aeat[i], a[at] - aeat[at], eateach - aeat[at] - beat[at] });
			aeat[i] -= acur, aeat[at] += acur;
			int bcur = min({ aeat[i] + beat[i] - eateach, beat[i], b[at] - beat[at], eateach - aeat[at] - beat[at] });
			beat[i] -= bcur, beat[at] += bcur;
			assert(aeat[i] + beat[i] == eateach || aeat[at] + beat[at] == eateach);
		}
		//printf("after\n"); REP(i, n) printf("%d %d\n", aeat[i], beat[i]);
		REP(i, n) assert(aeat[i] <= a[i] && beat[i] <= b[i] && aeat[i] + beat[i] == eateach);
		return abs(targetkeep1 - targetkeep2);
	}
}

void run() {
	scanf("%d%d", &n, &eateach);
	REP(i, n) scanf("%d%d", &a[i], &b[i]);
	printf("%lld\n", solve());
	REP(i, n) printf("%d %d\n", aeat[i], beat[i]);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}