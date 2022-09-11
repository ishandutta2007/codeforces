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

const int MAXN = 2000;
const int MAXLIM = 2000;

int n, lim; ll want;
char s[MAXN + 1];
char ans[MAXN * MAXLIM + 1];

int same[MAXN + 1];
ll dp[MAXN + 1];

ll safemlt(ll a, ll b) { if (a == 0) return 0; return  b > LLONG_MAX / a ? LLONG_MAX : a * b; }

void solve() {
	same[n] = 0;
	for (int i = n - 1; i >= 0; --i) same[i] = 1 + (s[i + 1] == s[i] ? same[i + 1] : 0);
	dp[n] = 1;
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == 'a') { dp[i] = dp[i + 1]; continue; }
		assert(s[i] == '*');
		dp[i] = safemlt(same[i] * lim + 1, dp[i + same[i]]);
	}
	//printf("dp:"); REPE(i, n) printf(" %lld", dp[i]); puts("");
	int nans = 0;
	ll rem = want;
	int at = 0;
	while (at < n) {
		if (s[at] == 'a') { ans[nans++] = 'a'; ++at; continue; }
		ll den = dp[at + same[at]];
		ll cnt = rem / den;
		assert(cnt >= 0 && cnt <= same[at] * lim);
		REP(i, cnt) ans[nans++] = 'b';
		rem %= den;
		at += same[at];
	}
	ans[nans] = '\0';
	assert(rem == 0);
}

void run() {
	scanf("%d%d%lld", &n, &lim, &want); --want;
	scanf("%s", s);
	solve();
	printf("%s\n", ans);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}