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

const int MXBIT = 29;

ll query(int a, int b) {
	printf("? %d %d\n", a, b); fflush(stdout);
	//ll x = 23127812; return gcd(x + a, x + b);
	ll ret; scanf("%lld", &ret); return ret;
}

int solve() {
	int x = 0;
	REPE(bit, MXBIT) {
		int z = 1 << bit;
		int a = z, b = 3 * z;
		int rem = x & (z - 1);
		a -= rem, b -= rem;
		ll res = query(a, b);
		if (res % (2 * z) == 0) x += z;
	}
	return x;
}

void run() {
	int x = solve();
	printf("! %d\n", x); fflush(stdout);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}