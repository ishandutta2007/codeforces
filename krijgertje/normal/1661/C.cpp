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

const int MAXN = 300000;

int n;
int a[MAXN];

ll solve() {
	ll ret = LLONG_MAX;
	int mx = a[0]; FOR(i, 1, n) mx = max(mx, a[i]);
	REP(delta, 2) {
		int target = mx + delta;
		ll one = 0, two = 0;
		REP(i, n) {
			int diff = target - a[i];
			one += diff % 2, two += diff / 2;
		}
		if (one == 0 && two == 0) { ret = min(ret, 0LL); continue; }
		// one+2*x,two-x
		// 2*(one+2*x)-1,2*(two-x)
		ll x = 2 * one - 1, y = 2 * two;
		if (y >= x) {
			ll t = (y - x) / 6;
			x += 4 * t, y -= 2 * t;
		}
		while (true) {
			ret = min(ret, max(x, y));
			if (x > y) break;
			x += 4, y -= 2;
		}
	}
	return ret;
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