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

const int MAXCOIN = 10;

int ncoin, have;
int coinexp[MAXCOIN];

int lim[MAXCOIN - 1];

ll solve() {
	REP(i, ncoin - 1) {
		lim[i] = 1;
		REP(j, coinexp[i + 1] - coinexp[i]) lim[i] *= 10;
		--lim[i];
	}
	int rem = have + 1;
	ll ret = 0;
	ll mlt = 1;
	for (int i = 0; rem > 0; ++i) {
		int cur = rem;
		if (i < ncoin - 1) cur = min(cur, lim[i]);
		rem -= cur;
		ret += mlt * cur;
		mlt *= lim[i] + 1;
	}
	return ret;
}

void run() {
	scanf("%d%d", &ncoin, &have);
	REP(i, ncoin) scanf("%d", &coinexp[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}