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

int k; ll ban;

ll calcup(int x) { return (ll)x * (x + 1) / 2; }
ll calcdn(int x) { return calcup(k - 1) - calcup(k - 1 - x); }

int solve() {
	ll totup = calcup(k);
	ll totdn = calcdn(k - 1);
	if (totup >= ban) {
		int lo = 0, hi = k;
		while (lo + 1 < hi) {
			int mi = lo + (hi - lo) / 2;
			if (calcup(mi) >= ban) hi = mi; else lo = mi;
		}
		return hi;
	} else if (totup + totdn >= ban) {
		int lo = 0, hi = k - 1;
		while (lo + 1 < hi) {
			int mi = lo + (hi - lo) / 2;
			if (totup + calcdn(mi) >= ban) hi = mi; else lo = mi;
		}
		return k + hi;
	} else {
		return 2 * k - 1;
	}
}

void run() {
	scanf("%d%lld", &k, &ban);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}