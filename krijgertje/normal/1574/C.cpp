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

const int MAXN = 200000;
const int MAXQ = 200000;

int n;
ll a[MAXN];
int nq;
ll qx[MAXQ], qy[MAXQ];
ll qans[MAXQ];

void solve() {
	sort(a, a + n);
	ll asum = 0; REP(i, n) asum += a[i];
	REP(i, nq) {
		int pos = lower_bound(a, a + n, qx[i]) - a;
		ll best = LLONG_MAX;
		if (pos < n) {
			best = min(best, max(0LL, qy[i] - (asum - a[pos])));
		}
		if (pos - 1 >= 0) {
			best = min(best, (qx[i] - a[pos - 1]) + max(0LL, qy[i] - (asum - a[pos - 1])));
		}
		qans[i] = best;
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%lld", &a[i]);
	scanf("%d", &nq);
	REP(i, nq) scanf("%lld%lld", &qx[i], &qy[i]);
	solve();
	REP(i, nq) printf("%lld\n", qans[i]);
}

int main() {
	run();
	return 0;
}