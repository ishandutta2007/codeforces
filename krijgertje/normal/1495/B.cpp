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
int a[MAXN];

int lcnt[MAXN], rcnt[MAXN];

bool solve() {

	int x = -1, xlen = -1, xcnt = 0, xlft = 0, xrgt = 0;
	FOR(i, 1, n) if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
		int l = i - 1; while (l - 1 >= 0 && a[l] > a[l - 1]) --l;
		int r = i + 1; while (r + 1 < n && a[r] > a[r + 1]) ++r;
		int lcnt = i - l, rcnt = r - i, len = max(lcnt, rcnt);
		if (len > xlen) xlen = len, xcnt = 1, x = i, xlft = lcnt, xrgt = rcnt; else if (len == xlen) ++xcnt;
	}
	if (xcnt != 1) return false;

	REP(i, n) lcnt[i] = i - 1 >= 0 && a[i - 1] > a[i] ? lcnt[i - 1] + 1 : 0;
	for (int i = n - 1; i >= 0; --i) rcnt[i] = i + 1 < n && a[i + 1] > a[i] ? rcnt[i + 1] + 1 : 0;

	REP(y, n) if (y != x) {
		if (x - xlft <= y && y < x) {
			bool hewinslft = (x - y) % 2 == 0 && xlft > lcnt[y];
			bool hewinsrgt = xrgt > max(lcnt[y], rcnt[y]);
			if (!hewinslft && !hewinsrgt) return false;
		} else if (x < y && y <= x + xrgt) {
			bool hewinsrgt = (y - x) % 2 == 0 && xrgt > rcnt[y];
			bool hewinslft = xlft > max(lcnt[y], rcnt[y]);
			if (!hewinslft && !hewinsrgt) return false;
		} else {
			int me = max(lcnt[y], rcnt[y]), he = xlen;
			if (me >= he) return false;
		}
	}
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve() ? 1 : 0);
}

int main() {
	run();
	return 0;
}