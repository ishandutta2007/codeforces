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

const int MAXN = 200000;
const int NBIT = 30;

int n;
int a[MAXN];

ll asum[MAXN + 1];
int nxt[MAXN + 1][NBIT];

bool ok(int l, int r) {
	bool ret = a[l] > a[r] && r - l + 1 >= 3 && (a[l] ^ a[r]) == (asum[r] - asum[l + 1]);
	//if (ret) printf("%d..%d\n", l, r);
	return ret;
}

ll solve() {
	ll ret = 0;
	REP(rep, 2) {
		asum[0] = 0; REP(i, n) asum[i + 1] = asum[i] + a[i];
		REP(k, NBIT) nxt[n][k] = n;
		for (int i = n - 1; i >= 0; --i) {
			REP(k, NBIT) nxt[i][k] = ((a[i] >> k) & 1) != 0 ? i : nxt[i + 1][k];
		}
		REP(i, n) {
			if (asum[n] - asum[i + 1] < a[i]) continue;
			int lo = i + 1, hi = n;
			while (lo + 1 < hi) {
				int mi = lo + (hi - lo) / 2;
				if (asum[mi] - asum[i + 1] < a[i]) lo = mi; else hi = mi;
			}
			int j = hi;
			set<int> opt;
			opt.insert(j - 1);
			if (j < n) opt.insert(j), ++j;
			REP(bit, NBIT) if (nxt[j][bit] != n) opt.insert(nxt[j][bit]);
			//printf("%d:", i); for (const int& x : opt) printf(" %d", x); puts("");
			for (const int& x : opt) if (ok(i, x)) ++ret;
		}
		reverse(a, a + n);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%lld\n", solve());
}

int solvestupid() {
	int ret = 0;
	REP(i, n) {
		ll sum = 0;
		FOR(j, i + 1, n) {
			if (j != i + 1 && (a[i] ^ a[j]) == sum) ++ret;
			sum += a[j];
		}
	}
	return ret;
}

void stress() {
	REP(rep, 100000) {
		n = rnd() % 100 + 1;
		int lim = rnd() % 128 + 1;
		REP(i, n) a[i] = rnd() % lim + 1;
		int have = solve();
		int want = solvestupid();
		if (have == want) { if (rep % 100 == 99) printf("."); continue; }
		printf("err have=%d want=%d\n", have, want);
		printf("%d\n", n); REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i]); } puts("");
	}
}

int main() {
	run();
	//stress();
	return 0;
}