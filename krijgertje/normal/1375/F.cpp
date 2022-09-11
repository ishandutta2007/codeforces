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

ll a, b, c;

void solve() {
	printf("First\n"); fflush(stdout);
	ll mn = min(a, min(b, c));
	ll mx = max(a, max(b, c));
	ll v1 = mx - mn;
	printf("%lld\n", v1); fflush(stdout);
	int who1; scanf("%d", &who1);
	if (who1 == 0) return;
	if (who1 == 1) a += v1; else if (who1 == 2) b += v1; else if (who1 == 3) c += v1; else assert(false);
	assert(a != b && a != c && b != c);
	mn = min(a, min(b, c));
	mx = max(a, max(b, c));
	if (who1 == 1) assert(a == mx); else if (who1 == 2) assert(b == mx); else if (who1 == 3) assert(c == mx);
	ll md = a + b + c - mn - mx;
	ll x = md - mn, y = mx - md;
	ll v2 = x + 2 * y;
	printf("%lld\n", v2); fflush(stdout);
	int who2; scanf("%d", &who2);
	if (who2 == 0) return;
	assert(who2 != who1);
	if (who2 == 1) a += v2; else if (who2 == 2) b += v2; else if (who2 == 3) c += v2; else assert(false);
	assert(a != b && a != c && b != c);
	if (who1 == 1) assert(a == mx); else if (who1 == 2) assert(b == mx); else if (who1 == 3) assert(c == mx);
	mn = min(a, min(b, c));
	mx = max(a, max(b, c));
	md = a + b + c - mn - mx;
	x = md - mn, y = mx - md;
	assert(x == y);
	ll v3 = x;
	printf("%lld\n", v3); fflush(stdout);
	int who3; scanf("%d", &who3);
	assert(who3 == 0);
}

void run() {
	scanf("%lld%lld%lld", &a, &b, &c);
	solve();
}

int main() {
	run();
	return 0;
}