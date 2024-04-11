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

const int MAXN = 300000;

int n;
int a[MAXN];

int b[MAXN];

int solve() {
	int bsum = 0;
	REP(i, n) b[i] = 0;
	FOR(i, 1, n - 1) {
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) b[i] = 1;
		if (a[i] < a[i - 1] && a[i] < a[i + 1]) b[i] = 1;
		bsum += b[i];
	}
	int ret = bsum;
	REP(i, n) {
		int cur = bsum;
		FORE(di, -1, +1) if (i + di >= 0 && i + di < n) cur -= b[i + di];
		if (i - 2 >= 0 && i + 2 < n && a[i - 1] < a[i + 1] && a[i - 2] > a[i - 1] && a[i + 2] < a[i + 1]) ++cur;
		if (i - 2 >= 0 && i + 2 < n && a[i - 1] > a[i + 1] && a[i - 2] < a[i - 1] && a[i + 2] > a[i + 1]) ++cur;
		ret = min(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int solvestupid() {
	int lo = INT_MAX, hi = INT_MIN;
	REP(i, n) lo = min(lo, a[i]), hi = max(hi, a[i]);
	int ret = INT_MAX;
	REP(i, n) {
		FORE(x, lo, hi) {
			REP(j, n) b[j] = j == i ? x : a[j];
			int cur = 0;
			FOR(j, 1, n - 1) {
				if (b[j] > b[j - 1] && b[j] > b[j + 1]) ++cur;
				if (b[j] < b[j - 1] && b[j] < b[j + 1]) ++cur;
			}
			ret = min(ret, cur);
		}
	}
	return ret;
}

void stress() {
	int mxn = 10, mxlim = 10;
	REP(rep, 10000) {
		n = rnd() % mxn + 1; int lim = rnd() % mxlim + 1;
		REP(i, n) a[i] = rnd() % lim + 1;
		int have = solve();
		int want = solvestupid();
		if (have == want) { printf("."); continue; }
		printf("err have=%d want=%d\n", have, want);
		printf("%d\n", n); REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i]); } puts("");
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}