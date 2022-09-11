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

int l, r; ll want;
ll a, b, c;

void solve() {
	for (a = l; a <= r; ++a) {
		ll n = max(1LL, want / a);
		FORE(dn, -3, +3) {
			ll nn = n + dn; if (nn < 1) continue;
			ll diff = want - (n + dn) * a;
			b = max(0LL, diff);
			c = max(0LL, -diff);
			if (b < l) { int delta = l - b; b += delta; c += delta; }
			if (c < l) { int delta = l - c; b += delta; c += delta; }
			if (b <= r && c <= r) return;
		}

	}
	assert(false);
}

void run() {
	scanf("%d%d%lld", &l, &r, &want);
	solve();
	printf("%lld %lld %lld\n", a, b, c);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}