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

int n;

int query(int x) {
	printf("? %d\n", x + 1); fflush(stdout);
	int ret; scanf("%d", &ret); return ret;
}

int solve() {
	int l = -1, lval = INT_MAX, r = n, rval = INT_MAX;
	int m = l + (r - l) / 2, mval = query(m);
	while (true) {
		int a = m == l + 1 ? -1 : l + (m - l) / 2;
		int b = r == m + 1 ? -1 : m + (r - m) / 2;
		if (a == -1 && b == -1) return m;
		int aval = a == -1 ? lval : query(a);
		int bval = b == -1 ? rval : query(b);
		if (aval < mval) { r = m, rval = mval, m = a, mval = aval; continue; }
		if (bval < mval) { l = m, lval = mval, m = b, mval = bval; continue; }
		if (a != -1) l = a, lval = aval;
		if (b != -1) r = b, rval = bval;
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