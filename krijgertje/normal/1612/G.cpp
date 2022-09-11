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

const int MAXCOL = 500000;
const int MOD = 1000000007;

int ncol;
int cnt[MAXCOL];
int anssum, answays;

int fac[MAXCOL + 1];

void solve() {
	fac[0] = 1; FORE(i, 1, ncol) fac[i] = (ll)fac[i - 1] * i % MOD;

	int maxcnt = 0;
	REP(i, ncol) maxcnt = max(maxcnt, cnt[i]);
	vector<int> a(2 * maxcnt + 1, 0);
	REP(i, ncol) {
		int x = cnt[i] - 1;
		++a[maxcnt - x];
		if (x + 2 <= maxcnt) --a[maxcnt + x + 2];
	}
	FORSZ(i, 2, a) a[i] += a[i - 2];
	answays = 1;
	REPSZ(i, a) answays = (ll)answays * fac[a[i]] % MOD;
	anssum = 0;
	int pos = 0;
	FORE(i, -maxcnt, +maxcnt) {
		int now = a[maxcnt + i];
		int mlt = (i + MOD) % MOD;
		ll sum = (ll)(pos + pos + now - 1) * now / 2;
		anssum = (anssum + sum % MOD * mlt) % MOD;
		pos = (pos + now) % MOD;
	}
}

void run() {
	scanf("%d", &ncol);
	REP(i, ncol) scanf("%d", &cnt[i]);
	solve();
	printf("%d %d\n", anssum, answays);
}

int main() {
	run();
	return 0;
}