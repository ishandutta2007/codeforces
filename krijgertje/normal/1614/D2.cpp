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

const int MAXN = 100000;
//const int MAXVAL = 10;
const int MAXVAL = 20000000;
//const int MAXVAL = 5000000;

int n;
int a[MAXN];

int cnt[MAXVAL + 1];
ll dp[MAXVAL + 1];

int pmn[MAXVAL + 1];
vector<int> primes;

ll solve() {
	REPE(i, MAXVAL) pmn[i] = -1; primes.clear();

	FORE(i, 2, MAXVAL) {
		if (pmn[i] == -1) pmn[i] = i, primes.PB(i);
		REPSZ(j, primes) { int k = i * primes[j]; if (k > MAXVAL) break; pmn[k] = primes[j]; if (primes[j] == pmn[i]) break; }
	}

	memset(cnt, 0, sizeof(cnt));
	REP(i, n) ++cnt[a[i]];
	for (int p : primes) for (int i = MAXVAL / p; i >= 1; --i) cnt[i] += cnt[i * p];

	dp[1] = cnt[1];
	FORE(i, 1, MAXVAL) REPSZ(j, primes) {
		int k = i * primes[j];
		if (k > MAXVAL) break;
		dp[k] = max(dp[k], dp[i] + (ll)cnt[k] * (k - i));
	}

	ll ret = 0;
	FORE(i, 1, MAXVAL) ret = max(ret, dp[i]);
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}