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


ll sval, lval, hval, nday, x, y;

ll safemlt(ll a, ll b) { assert(a >= 0 && b >= 0); if (a == 0 || b == 0) return 0; return a > LLONG_MAX / b ? LLONG_MAX : a * b; }
ll safeadd(ll a, ll b) { assert(a >= 0 && b >= 0); return a > LLONG_MAX - b ? LLONG_MAX : a + b; }


ll g(ll mod, ll step, ll l, ll r) {
	//printf("mod=%lld l=%lld r=%lld step=%lld\n", mod, l, r, step);
	if (l == 0) return 1;
	if (step == 0) throw 0;
	if (2 * step > mod) return g(mod, mod - step, mod - r, mod - l);
	ll x = (l + step - 1) / step;
	if (x * step <= r) return x;
	ll y = g(step, -mod % step, l % step, r % step); // l<=x*step-y*mod<=r
	return (r + y * mod) / step;
}

bool solve() {
	ll lim = hval - lval;
	ll cur = hval - sval;
	if (cur >= y) cur -= y;
	if (cur + x > lim) return false;
	if (y <= x) {
		ll have = lim - cur;
		ll need = safeadd(safemlt(nday - 1, x - y), x);
		return have >= need;
	} else {
		ll diff = y - x;
		if (diff == 0) return true;
		ll initdays = cur / diff;
		if (initdays >= nday) return true;
		ll remdays = nday - initdays;
		cur %= diff;
		if (lim - x >= y - 1) return true;
		if (cur > lim - x) return false;
		// cur+i*x mod y <= lim-x
		// i*x mod y 
		//printf("TODO %lld+i*%lld mod %lld <= %lld for i=%lld..%lld\n", cur, x, y, lim - x, 0LL, remdays - 1);

		ll mod = y, step = x, lo = (lim - x) - cur + 1, hi = (y - 1) - cur;

		try {
			ll fst = g(mod, step, lo, hi);
			//printf("fst=%lld\n", fst);
			return fst > remdays - 1;
		} catch (int e) {
			//printf("caught\n");
			return true;
		}
	}
}

void run() {
	scanf("%lld%lld%lld%lld%lld%lld", &sval, &lval, &hval, &nday, &x, &y);
	printf("%s\n", solve() ? "Yes" : "No");
}

int main() {
	run();
	return 0;
}