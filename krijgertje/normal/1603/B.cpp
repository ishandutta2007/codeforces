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

int x, y;

ll solve() {
	if (x <= y) {
		int a = y / x, b = 1;
		ll num = y + (ll)a * x, den = b + 1;
		return num / den;
	} else {
		return x + y;
	}
}

void run() {
	scanf("%d%d", &x, &y);
	printf("%lld\n", solve());
}

void research() {
	int lim = 1000000000;
	REP(rep, 100000) {
		int x, y;
		while (true) {
			x = rnd() % lim + 1;
			y = rnd() % lim + 1;
			if (x % 2 != 0 || y % 2 != 0) continue;
			break;
		}
		ll n;
		if (x <= y) {
			int a = y / x, b = 1;
			ll num = y + (ll)a * x, den = b + 1;
			assert(num % den == 0);
			n = num / den;
		} else {
			n = x + y;
		}
		assert(n >= 1 && n <= 1000000000000000000LL);
		assert(n % x == y % n);
		printf(".");
	}
}

int main() {
	//research();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}