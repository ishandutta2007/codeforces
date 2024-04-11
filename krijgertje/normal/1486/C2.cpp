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

int n;

int query(int l, int r) {
	printf("? %d %d\n", l + 1, r + 1); fflush(stdout);
	int ret; scanf("%d", &ret); --ret; return ret;
}

int solve() {
	int x = query(0, n - 1);
	if (x != 0 && query(0, x) == x) {
		int l = 0, r = x;
		while (l + 1 < r) {
			int m = l + (r - l) / 2;
			if (query(m, x) != x) r = m; else l = m;
		}
		return l;
	} else {
		int l = x, r = n - 1;
		while (l + 1 < r) {
			int m = l + (r - l) / 2;
			if (query(x, m) != x) l = m; else r = m;
		}
		return r;
	}
}

void run() {
	scanf("%d", &n);
	int ans = solve();
	printf("! %d\n", ans + 1); fflush(stdout);
}

int main() {
	run();
	return 0;
}