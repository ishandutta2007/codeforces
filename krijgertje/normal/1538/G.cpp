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

int nred, nblue, a, b;

bool can(int want) {
	ll each = (ll)a * want;
	if (nred < each || nblue < each) return false;
	if (a == b) return true;
	return (nred - each) / (b - a) + (nblue - each) / (b - a) >= want;
}

int solve() {
	if (a > b) swap(a, b);
	int lo = 0, hi = nred + nblue + 1;
	while (lo + 1 < hi) {
		int mi = lo + (hi - lo) / 2;
		if (can(mi)) lo = mi; else hi = mi;
	}
	return lo;
}

void run() {
	scanf("%d%d%d%d", &nred, &nblue, &a, &b);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}