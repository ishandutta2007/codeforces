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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

int dsummax(int n) {
	return n*(n - 1) / 2;
}

int dsummin(int n) {
	int ret = 0;
	int rem = n;
	for (int d = 0; rem > 0; ++d) {
		int cur = min(rem, 1 << d);
		rem -= cur;
		ret += cur*d;
	}
	return ret;
}

const int MAXN = 5000;

int n, want;
int par[MAXN];

void go(int n, int want, int p, int &nxt) {
	if (n == 0) { assert(want == 0); return; }
	int at = nxt++; par[at] = p;
	if (n == 1) { assert(want == 0); return; }
	FORE(l, 1, n - 1) {
		int r = n - 1 - l;
		int rem = want - (n - 1);
		int lmin = dsummin(l), lmax = dsummax(l);
		int rmin = dsummin(r), rmax = dsummax(r);
		if (lmin + rmin > rem || lmax + rmax < rem) continue;
		if (lmin + rmax >= rem) { go(l, lmin, at, nxt); go(r, rem - lmin, at, nxt); return; }
		else { go(l, rem - rmax, at, nxt); go(r, rmax, at, nxt); return; }
	}
	printf("fail: %d %d\n", n, want);
	assert(false);
}

bool solve() {
	if (want<dsummin(n) || want>dsummax(n)) return false;
	int at = 0;
	go(n, want, -1, at);
	assert(at == n);
	return true;
}

void run() {
	scanf("%d%d", &n, &want);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	FOR(i, 1, n) { if (i != 1) printf(" "); printf("%d", par[i] + 1); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}