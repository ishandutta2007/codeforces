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

const int MAXN = 500000;

int n, nreset;
int a[MAXN];

ll sum[MAXN + 1];
ll prodsum[MAXN + 1];

ll solve() {
	sort(a, a + n);

	sum[n] = 0; prodsum[n] = 0;
	for (int i = n - 1; i >= 0; --i) sum[i] = sum[i + 1] + a[i], prodsum[i] = prodsum[i + 1] + (ll)i * a[i];

	ll ret = LLONG_MIN;
	ll sofar = 0;
	int ngroup = nreset + 1;
	REP(i, n) {
		int w = (i + ngroup - 1) / ngroup;
		ll cur = sofar;
		cur += prodsum[i] + (ll)(w - i) * sum[i];
		ret = max(ret, cur);
		sofar += (ll)a[i] * (i / ngroup);
	}
	ret = max(ret, sofar);
	return ret;
}

void run() {
	scanf("%d%d", &n, &nreset);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}