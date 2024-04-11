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


ll n;
vector<ll> ans;

void solve() {
	vector<pair<ll, int>> fac;
	ll x = n;
	for (int i = 2; (ll)i * i <= x; ++i) if (x % i == 0) {
		int cnt = 0;
		while (x % i == 0) x /= i, ++cnt;
		fac.PB(MP(i, cnt));
	}
	if (x != 1) fac.PB(MP(x, 1));
	int anslen = 0;
	REPSZ(i, fac) anslen = max(anslen, fac[i].second);
	ans = vector<ll>(anslen, 1);
	REPSZ(i, fac) REP(k, fac[i].second) ans[anslen - k - 1] *= fac[i].first;
}

void run() {
	scanf("%lld", &n);
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%lld", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}