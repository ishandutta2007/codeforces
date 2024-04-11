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

const int MAXN = 100000;

int n;
int a[MAXN];

int prefmx[MAXN], prefmn[MAXN];
int suffmx[MAXN], suffmn[MAXN];

int solve() {
	prefmx[0] = a[0]; FOR(i, 1, n) prefmx[i] = max(prefmx[i - 1], a[i]);
	prefmn[0] = a[0]; FOR(i, 1, n) prefmn[i] = min(prefmn[i - 1], a[i]);
	suffmx[n - 1] = a[n - 1]; for (int i = n - 2; i >= 0; --i) suffmx[i] = max(suffmx[i + 1], a[i]);
	suffmn[n - 1] = a[n - 1]; for (int i = n - 2; i >= 0; --i) suffmn[i] = min(suffmn[i + 1], a[i]);

	int mxidx = 0;
	REP(i, n) if (a[i] > a[mxidx]) mxidx = i;

	int ret = 0;
	REP(i, n - 1) ret = max(ret, (prefmx[i] - prefmn[i]) + (suffmx[i + 1] - suffmn[i + 1]));
	for (int i = mxidx, mnidx = i; i < n; ++i) {
		if (a[i] < a[mnidx]) mnidx = i;
		if (mxidx == 0 && i == n - 1) continue;
		int hi = max(mxidx == 0 ? INT_MIN : prefmx[mxidx - 1], i == n - 1 ? INT_MIN : suffmx[i + 1]);
		int lo = min(mxidx == 0 ? INT_MIN : prefmn[mxidx - 1], i == n - 1 ? INT_MIN : suffmn[i + 1]);
		ret = max(ret, (a[mxidx] - a[mnidx]) + (hi - lo));
	}
	for (int i = mxidx, mnidx = i; i >= 0; --i) {
		if (a[i] < a[mnidx]) mnidx = i;
		if (i == 0 && mxidx == n - 1) continue;
		int hi = max(i == 0 ? INT_MIN : prefmx[i - 1], mxidx == n - 1 ? INT_MIN : suffmx[mxidx + 1]);
		int lo = min(i == 0 ? INT_MIN : prefmn[i - 1], mxidx == n - 1 ? INT_MIN : suffmn[mxidx + 1]);
		ret = max(ret, (a[mxidx] - a[mnidx]) + (hi - lo));
	}
	if (mxidx != n - 1) for (int i = mxidx + 2, hi = a[mxidx + 1], lo = a[mxidx + 1]; i < n; ++i) {
		ret = max(ret, (a[mxidx] - suffmn[i]) + (hi - lo));
		if (a[i] < lo) lo = a[i];
		if (a[i] > hi) hi = a[i];
	}
	if (mxidx != 0) for (int i = mxidx - 2, hi = a[mxidx - 1], lo = a[mxidx - 1]; i >= 0; --i) {
		ret = max(ret, (a[mxidx] - prefmn[i]) + (hi - lo));
		if (a[i] < lo) lo = a[i];
		if (a[i] > hi) hi = a[i];
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}