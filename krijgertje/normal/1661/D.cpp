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

const int MAXN = 300000;

int n, k;
ll b[MAXN];

ll dx[MAXN], dc[MAXN];

ll solve() {
	ll ret = 0;
	REP(i, n) dx[i] = dc[i] = 0;
	for(int i=n-1;i>=0;--i) {
		if (i + 1 < n) dx[i] += dx[i + 1], dc[i] += dc[i + 1];
		ll a = dx[i] * i + dc[i];
		//printf("%d: a=%lld b=%lld\n", i, a, b[i]);
		if (a >= b[i]) continue;
		int idx = max(0, i - k + 1);
		int each = i - idx + 1;
		ll t = (b[i] - a + each - 1) / each;
		//printf("->%lld times at %d (%d each)\n", t, idx, each);
		dx[i] += t, dc[i] -= t * (idx - 1);
		if (idx - 1 >= 0) dx[idx - 1] -= t, dc[idx - 1] += t * (idx - 1);
		ret += t;
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &k);
	REP(i, n) scanf("%lld", &b[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}