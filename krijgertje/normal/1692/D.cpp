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

const int MOD = 24 * 60;

int hh, mm, step;
bool seen[MOD];

int solve() {
	REP(i, MOD) seen[i] = false;
	int at = hh * 60 + mm;
	while (!seen[at]) { seen[at] = true; at = (at + step) % MOD; }

	int ret = 0;
	REP(i, MOD) if (seen[i]) {
		int a = i / 60 / 10, b = i / 60 % 10, c = i % 60 / 10, d = i % 60 % 10;
		if (a == d && b == c) ++ret;
	}
	return ret;
}

void run() {
	scanf("%d:%d%d", &hh, &mm, &step);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}