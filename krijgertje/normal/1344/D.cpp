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

const int MAXN = 100000;
const int MAXA = 1000000000;
const ll MAXDELTAVAL = MAXA;
const ll MINDELTAVAL = -((ll)3 * MAXA * MAXA - (ll)3 * MAXA + 1);

int n; ll want;
int a[MAXN];
int b[MAXN];

pair<int, int> o[MAXN];
int res[MAXN];

ll cost(ll x) { return -(3 * x * x - 3 * x + 1); }

ll calc(ll delta) {
	// -(3*x*x-3*x+1)>=delta

	ll lo = 0, hi = MAXA + 1;
	while (lo + 1 < hi) {
		ll mi = lo + (hi - lo) / 2;
		if (cost(mi) >= delta) lo = mi; else hi = mi;
	}
	ll x = lo;
	ll ret = 0;
	REP(i, n) {
		while (o[i].first + cost(x + 1) >= delta) ++x;
		res[o[i].second] = min(x, (ll)o[i].first);
		ret += res[o[i].second];
	}
	return ret;
}

void solve() {
	REP(i, n) o[i] = MP(a[i], i); sort(o, o + n);
	
	ll lo = MINDELTAVAL - 1, hi = MAXDELTAVAL + 1;
	while (lo + 1 < hi) {
		ll mi = lo + (hi - lo) / 2;
		ll have = calc(mi);
		if (have <= want) hi = mi; else lo = mi;
	}
	ll delta = hi;
	//printf("delta=%lld -> have=%lld/%lld (want=%lld)\n", delta, calc(delta), calc(delta - 1), want);

	ll sofar = calc(delta); assert(sofar <= want);
	REP(i, n) b[i] = res[i];
	if (sofar < want) {
		ll toomuch = calc(delta - 1); assert(toomuch > want);
		ll rem = want - sofar;
		REP(i, n) if (res[i] > b[i] && rem > 0) ++b[i], --rem;
		assert(rem == 0);
	}
}

void run() {
	scanf("%d%lld", &n, &want);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", b[i]); } puts("");
}

int main() {
	run();
	return 0;
}