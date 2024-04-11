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

ll val;

pair<ll, ll> solve() {
	vector<ll> parts;
	ll x = val; for (int i = 2; (ll)i * i <= x; ++i) if (x % i == 0) { ll cur = 1; while (x % i == 0) x /= i, cur *= i; parts.PB(cur); }
	if (x != 1) parts.PB(x);
	ll best = LLONG_MAX; pair<ll, ll> ret = MP(LLONG_MAX, LLONG_MAX);
	REP(mask, 1 << SZ(parts)) {
		ll a = 1, b = 1; REPSZ(i, parts) if (mask & (1 << i)) a *= parts[i]; else b *= parts[i];
		ll cur = max(a, b); if (cur < best) best = cur, ret = MP(a, b);
	}
	return ret;
}

void run() {
	scanf("%lld", &val);
	pair<ll, ll> ans = solve();
	printf("%lld %lld\n", ans.first, ans.second);
}

int main() {
	run();
	return 0;
}