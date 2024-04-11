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

ll n;

int solve() {
	vector<ll> fac;
	fac.PB(1);
	while (true) {
		ll nxt = fac.back() * SZ(fac);
		if (nxt > n) break;
		fac.PB(nxt);
	}
	int ret = INT_MAX;
	REP(mask, 1 << SZ(fac)) {
		ll rem = n;
		int cur = 0;
		REPSZ(i, fac) if (mask & (1 << i)) rem -= fac[i], ++cur;
		if (rem < 0) continue;
		for (int bit = 0; (1LL << bit) <= rem; ++bit) if (rem & (1LL << bit)) ++cur;
		ret = min(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%lld", &n);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}