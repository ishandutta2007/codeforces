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

const int MAXN = 5000;

int n;
int a[MAXN];

int rec(int lo, int hi,int sofar) {
	int mn = a[lo]; FORE(i, lo + 1, hi) mn = min(mn, a[i]); assert(mn >= sofar);
	int opt1 = hi - lo + 1;
	int opt2 = mn - sofar;
	for (int l = lo, r = l; l <= hi; l = r) {
		while (r <= hi && (a[r] == mn) == (a[l] == mn)) ++r;
		if (a[l] != mn) opt2 += rec(l, r - 1, mn);
	}
	return min(opt1, opt2);
}

int solve() {
	return rec(0, n - 1, 0);
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}