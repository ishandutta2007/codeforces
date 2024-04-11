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

int n, t;

int solve() {
	if (n % 2 == 0) return t % n;
	int full = t / n;
	int rem = t % n;
	full %= (n - 1) / 2;
	int a = n - 1, b = 2 * full;
	while (true) {
		if (b < a) {
			int meet = (a - b) / 2;
			if (rem < meet) return b + rem;
			rem -= meet;
			a -= meet;
			b += meet + 1;
		} else {
			int loop = min(n - b, a + 1);
			if (rem < loop) return b + rem;
			a -= loop;
			b += loop;
			rem -= loop;
			if (a < 0) a += n;
			if (b >= n) b -= n;
			if (b == a) if (b == n - 1) b = 0; else ++b;
		}
	}
}

void run() {
	scanf("%d%d", &n, &t); --t;
	printf("%d\n", solve() + 1);
}

int solvestupid() {
	int a = n - 1, b = 0;
	REP(i, t) {
		if (a == 0) a = n - 1; else --a;
		if (b == n - 1) b = 0; else ++b;
		if (b == a) if (b == n - 1) b = 0; else ++b;
	}
	return b;
}

void stress() {
	for (n = 2; n <= 20; ++n) for (t = 0; t <= 100; ++t) {
		int have = solve();
		int want = solvestupid();
		if (have == want) { printf("."); continue; }
		printf("n=%d t=%d: have=%d want=%d\n", n, t + 1, have, want);
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}