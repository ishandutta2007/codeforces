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

int n, nmove, mxleft;
int a[MAXN];

ll solve() {
	ll ret = LLONG_MIN;
	ll sum = a[0], mx = LLONG_MIN;
	FOR(i, 1, n) {
		sum += a[i];
		mx = max(mx, (ll)a[i - 1] + a[i]);
		int rem = nmove - i;
		if (rem < 0) continue;
		ll cur = sum;
		int remleft = mxleft;
		if (rem % 2 == 1) if (remleft == 0) continue; else cur += a[i - 1], --rem, --remleft;
		if (rem / 2 > remleft) continue;
		cur += (rem / 2) * mx;
		//printf("%d: %lld\n", i, cur);
		ret = max(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d%d%d", &n, &nmove, &mxleft);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}