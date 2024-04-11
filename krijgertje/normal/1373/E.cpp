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

int wantsum, cnt;

ll ans;

void upd(ll res) { if (ans == -1 || res < ans) ans = res; }

ll calc(int want) {
	ll mlt = 1, ret = 0;
	while (want >= 10) want -= 9, ret += mlt * 9, mlt *= 10;
	return ret + want * mlt;
}

void rec(int a, int b, int want,ll sofar,ll mlt) {
	//printf("rec(%d,%d,%d,%lld,%lld)\n", a, b, want, sofar, mlt);
	if (b == want) upd(sofar);
	REP(d, 10) {
		int have = 0;
		if (d + 1 < 10) {
			have += a * d + b * (d + 1);
			int rem = want - have;
			if (rem >= 0 && rem % (a + b) == 0) upd(sofar + mlt * d + 10 * mlt * calc(rem / (a + b)));
		} else {
			have += a * d + b * (d + 1 - 10);
			int rem = want - have;
			if (rem >= 0) rec(a, b, rem, sofar + mlt * d, 10 * mlt);
		}
	}
}

ll solve() {
	ans = -1;
	REP(d, 10) {
		int have = 0, a = 0, b = 0;
		REP(i, cnt) {
			int x = d + i;
			if (x < 10) ++a; else ++b, x -= 10;
			have += x;
		}
		if (have > wantsum) continue;
		rec(a, b, wantsum - have, d, 10);
	}
	return ans;
}

void run() {
	scanf("%d%d", &wantsum, &cnt); ++cnt;
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}