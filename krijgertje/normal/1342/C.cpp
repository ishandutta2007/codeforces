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

const int MAXQ = 500;

int a, b, nq;
ll ql[MAXQ], qr[MAXQ], qans[MAXQ];

ll calc(ll lim) {
	ll ret = 0;
	int r = b / a, s = b % a;
	REP(q, a) {
		if ((q * s) % a != 0) continue;
		ll fst = (ll)q * b, step = (ll)a * b;
		if (fst > lim) continue;
		ll t = (lim - fst) / step;
		ll lst = fst + t * step;
		ret += b * t;
		ret += min((ll)b, lim - lst + 1);
	}
	return ret;
}

void solve() {
	if (a > b) swap(a, b);
	REP(i, nq) {
		ll l = ql[i], r = qr[i];
		//for (ll x = l; x <= r; ++x) printf("%lld: %lld vs %lld (%lld)\n", x, (x % a) % b, (x % b) % a, (x % a) % b - (x % b) % a);
		qans[i] = (r - l + 1) - (calc(r) - calc(l - 1));
	}
}

void run() {
	scanf("%d%d%d", &a, &b, &nq);
	REP(i, nq) scanf("%lld%lld", &ql[i], &qr[i]);
	solve();
	REP(i, nq) { if (i != 0) printf(" "); printf("%lld", qans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}