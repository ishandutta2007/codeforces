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

int solve() {
	int lo1 = INT_MAX, lo2 = INT_MAX;
	REP(i, n) if (a[i] < lo1) lo2 = lo1, lo1 = a[i]; else if (a[i] < lo2) lo2 = a[i];
	int ret = (lo1 + 1) / 2 + (lo2 + 1) / 2;
	REP(i, n - 1) {
		int x = a[i], y = a[i + 1];
		if (x < y) swap(x, y);
		int diff = x - y;
		int cur = 0;
		int t = min(diff, y);
		x -= 2 * t, y -= t, cur += t;
		assert(x >= 0 && y >= 0);
		assert(y == 0 || x == y);
		if (y == 0) {
			cur += (x + 1) / 2;
		} else {
			t = x / 3;
			x -= 3 * t, y -= 3 * t, cur += 2 * t;
			cur += x;
		}
		ret = min(ret, cur);
	}
	REP(i, n - 2) {
		int x = a[i], y = a[i + 2];
		if (x < y) swap(x, y);
		int cur = 0;
		int t = y;
		x -= t, y -= t, cur += t;
		if (x >= 0) cur += (x + 1) / 2;
		ret = min(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}