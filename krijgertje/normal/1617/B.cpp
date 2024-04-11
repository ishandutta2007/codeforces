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
int a, b, c;

void solve() {
	if (n % 2 == 0) {
		c = 1, b = 2, a = n - b - c;
	} else if ((n - 1) % 4 == 0) {
		c = 1, b = (n - 1) / 2 - 1, a = n - b - c;
	} else {
		c = 1, b = (n - 1) / 2 - 2, a = n - b - c;
	}
}

void run() {
	scanf("%d", &n);
	solve();
	printf("%d %d %d\n", a, b, c);
}

void stress() {
	for (n = 10; n <= 100; ++n) {
		solve();
		assert(a + b + c == n && a >= 1 && b >= 1 && c >= 1 && a != b && a != c && b != c && gcd(a, b) == c);
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}