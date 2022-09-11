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

int n, k;

int sub(int a, int b) {
	int ret = 0, carry = 0, mlt = 1;
	while (a > 0 || b > 0 || carry != 0) {
		int cur = a % k - b % k;
		if (cur >= 0) { assert(cur < k); carry = 0; } else { cur += k; assert(cur >= 0); carry = -1; }
		ret += mlt * cur;
		a /= k, b /= k, mlt *= k;
	}
	return ret;
}
int add(int a, int b) { return sub(a, sub(0, b)); }

void solve() {
	int sum = 0; bool neg = false;
	REP(xstart, n) {
		int guess = !neg ? add(sum, xstart) : sub(sum, xstart);
		printf("%d\n", guess); fflush(stdout);
		int res; scanf("%d", &res); if (res == -1) exit(0); if (res == 1) return;
		sum = sub(guess, sum), neg = !neg;
	}
}

void run() {
	scanf("%d%d", &n, &k);
	solve();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}