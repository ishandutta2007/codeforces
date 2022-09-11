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

int n;
int a[MAXN + 1];
ll cap;

ll calc(int len, int cnt) {
	int parts = cnt + 1;
	int each = len / parts, rem = len % parts;
	return (ll)(parts - rem) * each * each + (ll)rem * (each + 1) * (each + 1);
}

pair<int, ll> calc(ll lim) { // given each teleport needs to save at least lim, calculate (nr added teleports, total cost)
	pair<int, ll> ret = MP(0, 0LL);
	REP(i, n) {
		int len = a[i + 1] - a[i];
		int lo = 0, hi = len;
		while (lo + 1 < hi) {
			int mi = lo + (hi - lo) / 2;
			ll cur = calc(len, mi - 1) - calc(len, mi);
			if (cur >= lim) lo = mi; else hi = mi;
		}
		ret.first += lo;
		ret.second += calc(len, lo);
	}
	return ret;
}

int solve() {
	ll init = 0;
	REP(i, n) init += (ll)(a[i + 1] - a[i]) * (a[i + 1] - a[i]);
	if (init <= cap) return 0;
	ll lo = 0, hi = (ll)a[n] * a[n] + 1;
	while (lo + 1 < hi) {
		ll mi = lo + (hi - lo) / 2;
		if (calc(mi).second < cap) lo = mi; else hi = mi;
	}
	pair<int, ll> res = calc(hi);
	int ret = res.first;
	ll rem = res.second - cap, each = hi - 1;
	assert(rem >= 0);
	if (rem > 0) {
		assert(each >= 1);
		ret += (rem + each - 1) / each;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	a[0] = 0; FORE(i, 1, n) scanf("%d", &a[i]);
	scanf("%lld", &cap);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}