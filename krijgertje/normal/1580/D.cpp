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

const int MAXN = 4000;

int n, ntake;
int a[MAXN];

bool taken[MAXN];
ll cur[MAXN];

ll solve() {
	REP(i, n) taken[i] = false;
	REP(i, n) cur[i] = (ll)(ntake - 1) * a[i];
	ll ret = 0;
	REP(i, ntake) {
		//printf("cur:"); REP(j, n) if (taken[j]) printf(" XX"); else printf(" %lld", cur[j]); puts("");
		int best = -1;
		REP(j, n) if (!taken[j] && (best == -1 || cur[j] > cur[best])) best = j;
		ret += cur[best];
		taken[best] = true;
		{ int lo = a[best]; for (int j = best - 1; j >= 0; --j) { lo = min(lo, a[j]); cur[j] -= (ll)2 * lo; } }
		{ int lo = a[best]; for (int j = best + 1; j < n; ++j) { lo = min(lo, a[j]); cur[j] -= (ll)2 * lo; } }
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &ntake);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}