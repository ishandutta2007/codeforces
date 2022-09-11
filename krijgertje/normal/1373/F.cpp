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

const int MAXN = 1000000;

int n;
int a[MAXN + 1];
int b[MAXN];

bool solve() {
	int lo = 0, hi = a[0];
	ll sum = 0;
	int lim = a[0];
	a[n] = a[0];
	REP(i, n) {
		// a[i] already gets min(lim,sum+x) with lim<=a[i]
		// b[i]->a[i]: a[i]-min(lim,sum+x), so b[i]>=a[i]-lim and b[i]>=a[i]-x-sum -> x>=a[i]-b[i]-sum
		// b[i]->a[i+1]: min(min(a[i+1],b[i]-a[i]+lim),b[i]-a[i]+sum+x)
		if (b[i] < a[i] - lim) return false;
		lo = max((ll)lo, a[i] - b[i] - sum);
		if (lo > hi) return false;
		lim = min(a[i + 1], b[i] - a[i] + lim);
		if (lim < 0) return false;
		sum += b[i] - a[i];
		//printf("%d: lo=%d hi=%d sum=%lld lim=%d\n", i, lo, hi, sum, lim);
	}
	//FORE(x, lo, hi) if (min((ll)lim, sum + x) >= x) return true;
	if (sum < 0) return false;
	if (lim - lo >= 0) return true;
	return false;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, n) scanf("%d", &b[i]);
	printf("%s\n", solve() ? "YES" : "NO");
}

bool solvestupid() {
	a[n] = a[0];
	REPE(sx, a[0]) {
		int x = sx; bool ok = true;
		REP(i, n) {
			int rem = a[i] - x; assert(rem >= 0);
			if (b[i] < rem) { ok = false; break; }
			x = min(a[i + 1], b[i] - rem);
		}
		if (!ok) continue;
		if (x < sx) continue;
		return true;
	}
	return false;
}

void stress() {
	REP(rep, 10000000) {
		n = rnd() % 10 + 1;
		REP(i, n) a[i] = rnd() % 10, b[i] = rnd() % 10;
		bool have = solve();
		bool want = solvestupid();
		if (have == want) { if (rep % 1000 == 999) printf("."); continue; }
		printf("err\n");
		printf("%d\n", n);
		REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i]); } puts("");
		REP(i, n) { if (i != 0) printf(" "); printf("%d", b[i]); } puts("");
		printf("have=%s want=%s\n", have ? "YES" : "NO", want ? "YES" : "NO");
	}
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}