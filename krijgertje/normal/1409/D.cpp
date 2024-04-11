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

ll x; int lim;

ll solve() {
	vector<int> d; for (ll y = x; y > 0; y /= 10) d.PB(y % 10); d.PB(0); reverse(d.begin(), d.end());
	int have = 0; REPSZ(i, d) have += d[i];
	ll ret = 0, curcost = 1;
	for (int i = SZ(d) - 1; i >= 0; --i, curcost *= 10) if (have > lim) {
		if (d[i] == 0) continue;
		ret += (10 - d[i]) * curcost;
		have -= d[i], d[i] = 0; for (int j = i - 1;; --j) { assert(j >= 0); ++have, ++d[j]; if (d[j] < 10) break; have -= d[j], d[j] = 0; }
	}
	return ret;
}

void run() {
	scanf("%lld%d", &x, &lim);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}