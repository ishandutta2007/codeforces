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

int n, want;
int a[MAXN];
int b[MAXN - 1];

ll solve() {
	ll ret = LLONG_MAX;
	ll t = 0;
	ll have = 0;
	REP(i, n) {
		ll d = have >= want ? 0 : (want - have + a[i] - 1) / a[i];
		ret = min(ret, t + d);
		if (i == n - 1) break;
		ll dd = have >= b[i] ? 0 : (b[i] - have + a[i] - 1) / a[i];
		have += dd * a[i];
		t += dd + 1;
		assert(have >= b[i]);
		have -= b[i];
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &want);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, n - 1) scanf("%d", &b[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}