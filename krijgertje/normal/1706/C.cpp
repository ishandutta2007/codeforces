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

int n;
int a[MAXN];

ll l[MAXN];
ll r[MAXN];

ll solve() {
	auto calc = [&](int idx) -> ll { return max(0LL, (ll)max(a[idx - 1], a[idx + 1]) + 1 - a[idx]); };


	l[0] = 0, l[1] = calc(1), l[n - 1] = LLONG_MAX; FOR(i, 2, n - 1) l[i] = l[i - 2] + calc(i);
	r[n - 1] = 0, r[n - 2] = calc(n - 2), r[0] = LLONG_MAX; for (int i = n - 3; i >= 1; --i) r[i] = r[i + 2] + calc(i);
	//printf("l:"); REP(i, n) printf(" %lld", l[i]); puts("");
	//printf("r:"); REP(i, n) printf(" %lld", r[i]); puts("");
	if (n % 2 == 1) {
		return l[n - 2];
	} else {
		ll ret = min(l[n - 3], r[2]);
		FORE(i, 1, n - 3) if (i % 2 == 0) ret = min(ret, l[i - 1] + r[i + 2]);
		return ret;
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}