#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 200000;

int n;
int a[MAXN], b[MAXN];

int l[MAXN], r[MAXN];
int ans[MAXN];
ll brem;

bool solve() {
	for (int i = n - 1; i >= 0; --i) {
		l[i] = a[i], r[i] = a[i] + b[i];
		if (i + 1 < n) {
			l[i] = max(l[i], l[i + 1] - 1);
			r[i] = min(r[i], r[i + 1] + 1);
			if (l[i] > r[i]) return false;
		}
	}
	REP(i, n) {
		ans[i] = r[i];
		if (i - 1 >= 0) ans[i] = min(ans[i], ans[i - 1] + 1);
	}
	brem = 0; REP(i, n) brem += ans[i] - a[i];
	return true;
}


void run() {
	scanf("%d", &n); REP(i, n) scanf("%d%d", &a[i], &b[i]);

	if (!solve()) { printf("%d\n", -1); return; }
	printf("%lld\n", brem); REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}