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

const int MAXN = 200000;

int n;
int a[MAXN];
int b[MAXN];

int la[MAXN], lamin;
int ra[MAXN], ramin;
int lb[MAXN], lbmin;
int rb[MAXN], rbmin;

ll solve() {
	REP(i, n) la[i] = abs(a[0] - b[i]);
	REP(i, n) ra[i] = abs(a[n - 1] - b[i]);
	REP(i, n) lb[i] = abs(b[0] - a[i]);
	REP(i, n) rb[i] = abs(b[n - 1] - a[i]);
	lamin = INT_MAX; REP(i, n) lamin = min(lamin, la[i]);
	ramin = INT_MAX; REP(i, n) ramin = min(ramin, ra[i]);
	lbmin = INT_MAX; REP(i, n) lbmin = min(lbmin, lb[i]);
	rbmin = INT_MAX; REP(i, n) rbmin = min(rbmin, rb[i]);

	ll ret = LLONG_MAX;
	REP(l, 4) REP(r, 4) {
		ll cur = 0;
		REP(bit, 2) if (l & (1 << bit)) cur += la[bit == 0 ? 0 : n - 1];
		REP(bit, 2) if (r & (1 << bit)) cur += ra[bit == 0 ? 0 : n - 1];
		if (l == 0) cur += lamin;
		if (r == 0) cur += ramin;
		if (((l | r) & 1) == 0) cur += lbmin;
		if (((l | r) & 2) == 0) cur += rbmin;
		ret = min(ret, cur);
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
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}