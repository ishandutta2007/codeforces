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

const int MAXN = 200000;

int n;
char s[MAXN + 1];

int bal[MAXN + 1];

int solve() {
	bal[0] = 0;
	REP(i, n) bal[i + 1] = bal[i] + (s[i] == '0' ? -1 : +1);
	int ret = 0;
	if (bal[n] < bal[0]) reverse(bal, bal + n + 1);
	int at = n;
	int mnbal = bal[0], mxbal = bal[0];
	FOR(i, 1, n) mnbal = min(mnbal, bal[i]), mxbal = max(mxbal, bal[i]);
	vector<int> first(mxbal - mnbal + 1, INT_MAX); REP(i, n) first[bal[i] - mnbal] = min(first[bal[i] - mnbal], i);
	while (true) {
		//printf("bal:"); REPE(i, n) printf(" %d", bal[i]); puts("");
		while (bal[at] > bal[0] && bal[at - 1] == bal[at] - 1) --at;
		if (bal[at] == bal[0]) { assert(at % 2 == 0); if (bal[at / 2] != bal[0] - (at / 2)) ++ret;  break; }
		int to = first[bal[at] - mnbal];
		assert(to < at&& bal[at] == bal[to]);
		FORE(i, to, at) bal[i] = bal[at] - min(abs(at - i), abs(to - i));
		++ret;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	scanf("%s", s);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}