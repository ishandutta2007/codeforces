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

int n; ll lim;
int a[MAXN];

ll asum[MAXN + 1];

ll solve() {
	sort(a, a + n);
	asum[0] = 0; REP(i, n) asum[i + 1] = asum[i] + a[i];
	ll ret = LLONG_MAX;
	FORE(i, 1, n) {
		ll rem = asum[n - i + 1] - asum[1];
		ll x = lim >= rem ? (lim - rem) / i : (lim - rem - (i - 1)) / i; // i*x<=lim-rem
		ll cur = i - 1;
		if (x < a[0]) cur += a[0] - x;
		ret = min(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d%lld", &n, &lim);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}