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

int n;

int query(int c) {
	printf("+ %d\n", c); fflush(stdout);
	int ret; scanf("%d", &ret); return ret;
}

int solve() {
	int l = 1, r = n;
	int x = 0;
	while (r - l >= 2) {
		int m = l + (r - l) / 2;
		int c = n - m;
		int y = query(c);
		if (y == x) {
			r = m;
			l += c, r += c;
			assert(r <= n);
		} else {
			assert(y == x + 1);
			l = m;
			l += c, r += c;
			assert(l >= n);
			l -= n, r -= n, ++x;
		}
	}
	return x * n + l;
}

void run() {
	scanf("%d", &n);
	int ans = solve();
	printf("! %d\n", ans); fflush(stdout);
}

int main() {
	run();
	return 0;
}