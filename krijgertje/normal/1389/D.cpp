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

int n, want;
int l1, r1, l2, r2;

ll solve() {
	if (l1 > l2) swap(l1, l2), swap(r1, r2);
	int init = 0, zero = 0, one = 0;
	if (r1 <= l2) {
		zero += l2 - r1;
		one += r2 - l1;
	} else if (r2 <= r1) {
		init += r2 - l2;
		one += r1 - l1 - init;
	} else {
		init += r1 - l2;
		one += r2 - l1 - init;
	}
	ll ret = LLONG_MAX;
	FORE(use, 1, n) {
		ll cost = (ll)zero * use;
		ll have = (ll)init * n;
		ll rem = max(0LL, want - have);
		ll onelim = min(rem, (ll)use * one);
		cost += onelim;
		have += onelim;
		rem -= onelim;
		ll half = 2 * rem;
		cost += half;
		have += half / 2;
		rem -= half / 2;
		ret = min(ret, cost);
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &want);
	scanf("%d%d", &l1, &r1);
	scanf("%d%d", &l2, &r2);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}