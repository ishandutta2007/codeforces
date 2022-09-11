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

const int MAXN = 3000;

int n, lim;
int a[MAXN];

ll bal[MAXN + 1];


ll solve() {
	bal[0] = 0; REP(i, n) bal[i + 1] = bal[i] + a[i];
	//printf("bal:"); REPE(i, n) printf(" %lld", bal[i]); puts("");
	int have = 0; REP(i, n) if (a[i] == 0) ++have;
	ll sum = bal[n];
	ll whole = abs(sum) / lim;
	int part = abs(sum) % lim;
	bool havepart = part != 0;
	if (whole > have) return -1;
	int need = whole + (havepart ? 1 : 0);
	if (need > have) return -1;
	int rem = have - need;
	int up = rem / 2, dn = rem / 2;
	if (rem % 2 == 1) if (havepart) ++whole, part = part - lim; else havepart = true;
	if (sum < 0) up += whole; else dn += whole, part = -part;
	//printf("up=%d dn=%d havepart=%s part=%d (rem=%d)\n", up, dn, havepart ? "yes" : "no", part, rem);
	int npos = up + dn + 1;
	auto relax = [&](vector<vector<vector<ll>>>& dp, int pos, bool usedpart, int mask, ll val) { dp[pos][usedpart ? 1 : 0][mask] = max(dp[pos][usedpart ? 1 : 0][mask], val); };
	vector<vector<vector<ll>>> dp(npos, vector<vector<ll>>(2, vector<ll>(4, LLONG_MIN)));
	relax(dp, dn, false, 0, 0);
	REPE(i, n) {
		vector<vector<vector<ll>>> ndp(npos, vector<vector<ll>>(2, vector<ll>(4, LLONG_MIN)));
		REP(pos, npos) REP(usedpart, 2) REP(mask, 4) {
			ll cur = dp[pos][usedpart][mask];
			if (cur == LLONG_MIN) continue;
			//printf("dp[%d][%d][%d][%d]\n", i, pos, usedpart, mask);
			ll val = bal[i] + (ll)(pos - dn) * lim + (usedpart == 1 ? part : 0);
			if ((mask & 1) == 0) relax(dp, pos, usedpart, mask | 1, cur + val);
			if ((mask & 2) == 0) relax(dp, pos, usedpart, mask | 2, cur - val);
			if (i < n) {
				if (a[i] != 0) {
					relax(ndp, pos, usedpart, mask, cur);
				} else {
					if (pos - 1 >= 0) relax(ndp, pos - 1, usedpart, mask, cur);
					if (pos + 1 < npos) relax(ndp, pos + 1, usedpart, mask, cur);
					if (usedpart == 0 && havepart) relax(ndp, pos, 1, mask, cur);
				}
			}
		}
		if (i != n) swap(dp, ndp);
	}
	ll ret = dp[up][havepart ? 1 : 0][3];
	assert(ret != LLONG_MIN);
	return ret + 1;
}

void run() {
	scanf("%d%d", &n, &lim);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}