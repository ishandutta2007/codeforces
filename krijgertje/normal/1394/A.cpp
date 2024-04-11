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

int n, nskip, mxsmall;
int a[MAXN];

ll sum[MAXN + 1];

ll solve() {
	sort(a, a + n);
	sum[0] = 0; REP(i, n) sum[i + 1] = sum[i] + a[i];
	int nlarge = 0; REP(i, n) if (a[i] > mxsmall) ++nlarge;
	int nsmall = n - nlarge;
	ll ret = 0;
	REPE(uselarge, nlarge) {
		int remlarge = nlarge - uselarge;
		ll need = uselarge == 0 ? 0 : (ll)(uselarge - 1) * nskip;
		if (need > remlarge + nsmall) continue;
		int extra = uselarge == 0 ? 0 : nskip;
		if (remlarge > need + extra) continue;
		int usesmall = n - uselarge - max((int)need, remlarge);
		ll cur = sum[n] - sum[n - uselarge] + sum[nsmall] - sum[nsmall - usesmall];
		ret = max(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d%d%d", &n, &nskip, &mxsmall);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}