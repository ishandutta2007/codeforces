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

const int MAXN = 5000;

int n;
int a[MAXN];
int b[MAXN];

ll pref[MAXN];
ll suff[MAXN];

ll solve() {
	REP(i, n) pref[i] = i == 0 ? 0 : pref[i - 1] + (ll)a[i - 1] * b[i - 1];
	for (int i = n - 1; i >= 0; --i) suff[i] = i + 1 >= n ? 0 : suff[i + 1] + (ll)a[i + 1] * b[i + 1];

	ll ret = LLONG_MIN;
	// one mid
	REP(mid, n) {
		ll sum = (ll)a[mid] * b[mid];
		int l = mid, r = mid;
		while(true) {
			ll cur = sum + pref[l] + suff[r];
			ret = max(ret, cur);
			--l, ++r;
			if (l < 0 || r >= n) break;
			sum += (ll)a[l] * b[r] + (ll)a[r] * b[l];
		}
	}
	// two mids
	REP(lmid, n - 1) {
		int rmid = lmid + 1;
		ll sum = (ll)a[lmid] * b[rmid] + (ll)a[rmid] * b[lmid];
		int l = lmid, r = rmid;
		while (true) {
			ll cur = sum + pref[l] + suff[r];
			ret = max(ret, cur);
			--l, ++r;
			if (l < 0 || r >= n) break;
			sum += (ll)a[l] * b[r] + (ll)a[r] * b[l];
		}
	}

	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, n) scanf("%d", &b[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}