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

const int MAXN = 1000;
const int MAXV = 3 * MAXN;

int n;
int c[MAXN];

ll x[MAXN + 1];
ll v[MAXV + 1]; int nv;

int cnt[MAXV];

ll solve() {
	x[0] = 0;
	REP(i, n) x[i + 1] = x[i] + (i % 2 == 0 ? +c[i] : -c[i]);
	nv = 0; REPE(i, n) FORE(delta, -1, +1) v[nv++] = x[i] + delta; sort(v, v + nv); nv = unique(v, v + nv) - v; REPE(i, n) x[i] = lower_bound(v, v + nv, x[i]) - v;

	ll ret = 0;
	REP(i, nv - 1) cnt[i] = 0;
	REP(i, n) {
		if (i % 2 == 0) {
			int a = x[i], b = x[i + 1];
			FOR(j, a, b) ++cnt[j];
		} else {
			int a = x[i + 1], b = x[i];
			FOR(j, a, b) ret += (ll)(v[j + 1] - v[j]) * cnt[j];
			FORE(j, a + 1, b) cnt[j] = 0;
		}
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &c[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}