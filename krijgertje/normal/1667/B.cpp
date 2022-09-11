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

const int MAXN = 500000;

int n;
int a[MAXN];

ll asum[MAXN + 1];
int dp[MAXN + 1];

int solve() {
	asum[0] = 0;
	REP(i, n) asum[i + 1] = asum[i] + a[i];
	dp[0] = 0;
	map<ll, int> opt;
	opt.insert(MP(asum[0], dp[0] - 0));
	FORE(i, 1, n) {
		dp[i] = dp[i - 1] + (a[i - 1] < 0 ? -1 : a[i - 1] > 0 ? +1 : 0);
		auto it = opt.lower_bound(asum[i]);
		if (it != opt.begin()) {
			dp[i] = max(dp[i], prev(it)->second + i);
		}
		while (it != opt.end() && it->second <= dp[i] - i) opt.erase(it++);
		opt.insert(it, MP(asum[i], dp[i] - i));
	}
	return dp[n];
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int solvestupid() {
	asum[0] = 0;
	REP(i, n) asum[i + 1] = asum[i] + a[i];
	dp[0] = 0;
	auto calc = [&](ll x) { return x < 0 ? -1 : x>0 ? +1 : 0; };
	FORE(i, 1, n) {
		dp[i] = INT_MIN;
		REP(j, i) dp[i] = max(dp[i], dp[j] + calc(asum[i] - asum[j]) * (i - j));
	}
	return dp[n];
}

void stress() {
	int mxn = 10, mxabsval = 10;
	REP(rep, 1000000) {
		n = rnd() % mxn + 1;
		REP(i, n) a[i] = rnd() % (2 * mxabsval + 1) - mxabsval;
		int have = solve();
		int want = solvestupid();
		if (have == want) { if (rep % 1000 == 0) printf("."); continue; }
		printf("rep=%d have=%d want=%d\n", rep, have, want);
		printf("%d\n", n); REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i]); } puts("");
		break;
	}
}

int main() {
	//stress();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}