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
const int MAXP = 100000;

int n, p;
int a[MAXN];
vector<int> ans;

int opt[MAXN];
int blocked[MAXP];

bool can(int x) {
	int at = 0, cnt = 0;
	REP(i, n) {
		while (at < n && x + i >= a[at]) ++at, ++cnt;
		if (cnt == 0) return false;
		opt[i] = cnt;
		--cnt;
	}
	return true;
}

void solve() {
	sort(a, a + n);
	int lo = a[0] - 1, hi = a[n - 1];
	while (lo + 1 < hi) {
		int mi = lo + (hi - lo) / 2;
		if (can(mi)) hi = mi; else lo = mi;
	}
	int xlo = hi;
	//printf("xlo=%d\n", xlo);
	assert(can(xlo));
	//printf("opt:"); REP(i, n) printf(" %d", opt[i]); puts("");
	REP(i, p) blocked[i] = -1;
	REP(i, n) { int val = (p - opt[i] % p) % p; blocked[val] = i; }
	//printf("blocked:"); REP(i, p) if (blocked[i] != -1) printf(" %d:%d", i, blocked[i]); puts("");
	int lim = (p - opt[n - 1] % p) % p;
	ans.clear();
	REP(i, lim) if (blocked[i] < i) ans.PB(xlo + i);
}

void run() {
	scanf("%d%d", &n, &p);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}