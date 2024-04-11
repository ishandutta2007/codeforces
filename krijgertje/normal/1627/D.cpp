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
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXN = 1000000;
const int MAXVAL = 1000000;

int n;
int a[MAXN];

bool have[MAXVAL + 1];

int solve() {
	memset(have, false, sizeof(have));
	REP(i, n) have[a[i]] = true;
	int ret = 0;
	for (int i = MAXVAL; i >= 1; --i) if (!have[i]) {
		int g = 0;
		for (int t = 2; t * i <= MAXVAL; ++t) if (have[t * i]) g = gcd(g, t);
		if (g == 1) have[i] = true, ++ret;
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