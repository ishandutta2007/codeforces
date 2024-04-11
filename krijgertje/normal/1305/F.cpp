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
#include <random>
#include <chrono>
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
typedef long long ll;  
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 200000;

int n;
ll a[MAXN];

std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());

ll calc(ll g) {
	ll ret = 0;
	REP(i, n) {
		if (a[i] < g) { ret += g - a[i]; continue; }
		ll rem = a[i] % g; ret += min(rem, g - rem);
	}
	return ret;
}

ll solve() {
	ll ret = calc(2);
	REP(rep, 20) {
		int idx = rnd() % n;
		FORE(delta, -1, +1) {
			ll v = a[idx] + delta; if (v < 2) continue;
			for (int p = 2; (ll)p * p <= v; ++p) if (v % p == 0) {
				while (v % p == 0) v /= p;
				ret = min(ret, calc(p));
			}
			if (v != 1) ret = min(ret, calc(v));
		}
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%lld", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}