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

const int MAXN = 100000;

int n;
char a[MAXN + 1];
char b[MAXN + 1];

char c[MAXN + 1];

int solve() {
	REP(i, n) c[i] = a[i] != b[i] ? '2' : a[i];
	c[n] = '\0';
	int ret = 0;
	bool leftfree = false;
	REP(i, n) {
		if (c[i] == '2') { ret += 2; leftfree = false; continue; }
		if (c[i] == '0') {
			++ret;
			if (leftfree && c[i - 1] == '1') ++ret, leftfree = false; else leftfree = true;
		} else {
			if (leftfree && c[i - 1] == '0') ++ret, leftfree = false; else leftfree = true;
		}
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	scanf("%s", a);
	scanf("%s", b);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}