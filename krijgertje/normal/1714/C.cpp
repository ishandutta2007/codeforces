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

int wantsum;

int solve() {
	for (int len = 1;; ++len) {
		vector<int> d(len);
		REP(i, len) d[i] = 10 - len + i;
		int havesum = 0;
		REP(i, len) havesum += d[i];
		if (havesum < wantsum) continue;
		REP(i, len) {
			int x = min(havesum - wantsum, d[i] - (i + 1));
			d[i] -= x;
			havesum -= x;
		}
		assert(havesum == wantsum);
		int ret = 0;
		REP(i, len) ret = 10 * ret + d[i];
		return ret;
	}
}

void run() {
	scanf("%d", &wantsum);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}