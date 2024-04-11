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

const int MAXLEN = 200000;

int slen, tlen;
char s[MAXLEN + 1];
char t[MAXLEN + 1];

int pref[MAXLEN + 1];
int suff[MAXLEN + 1];

int solve() {
	pref[0] = 0;
	REP(i, tlen) { int x = pref[i]; while (x < slen && s[x] != t[i]) ++x; assert(x < slen); pref[i + 1] = x + 1; }
	suff[tlen] = slen;
	for (int i = tlen - 1; i >= 0; --i) { int x = suff[i + 1] - 1; while (x >= 0 && s[x] != t[i]) --x; assert(x >= 0); suff[i] = x; }
	int ret = 0;
	// pref[i+1] vs suff[i+1]
	REP(i, tlen - 1) {
		int cur = suff[i + 1] - (pref[i + 1] - 1);
		//printf("%d..%d\n", pref[i + 1] - 1, suff[i + 1]);
		assert(cur >= 1);
		ret = max(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d%d", &slen, &tlen);
	scanf("%s", s);
	scanf("%s", t);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}