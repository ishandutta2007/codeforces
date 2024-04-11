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

const int MAXN = 2000;
const int MOD = 1000000007;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n;
char s[MAXN + 1];
char t[MAXN + 1];

int a[MAXN];
int b[MAXN];

int pref[MAXN + 1][2 * MAXN + 1];
int suff[MAXN + 1][2 * MAXN + 1];

int solve() {
	REP(i, n) a[i] = s[i] == '?' ? -1 : s[i] - '0';
	REP(i, n) b[i] = t[i] == '?' ? -1 : t[i] - '0';
	REP(i, n) if (i % 2 == 1 && a[i] != -1) a[i] = 1 - a[i];
	REP(i, n) if (i % 2 == 1 && b[i] != -1) b[i] = 1 - b[i];
	//printf("a:"); REP(i, n) printf(" %d", a[i]); puts("");
	//printf("b:"); REP(i, n) printf(" %d", b[i]); puts("");

	REPE(i, n) FORE(bal, -n, +n) pref[i][n + bal] = 0;
	inc(pref[0][n + 0], 1);
	REP(i, n) FORE(bal, -n, +n) {
		int cur = pref[i][n + bal];
		if (cur == 0) continue;
		REP(x, 2) REP(y, 2) {
			if (a[i] != -1 && a[i] != x) continue;
			if (b[i] != -1 && b[i] != y) continue;
			int nbal = bal + x - y;
			inc(pref[i + 1][n + nbal], cur);
		}
	}

	REPE(i, n) FORE(bal, -n, +n) suff[i][n + bal] = 0;
	inc(suff[n][n + 0], 1);
	for (int i = n - 1; i >= 0; --i) FORE(bal, -n, +n) {
		int cur = suff[i + 1][n + bal];
		if (cur == 0) continue;
		REP(x, 2) REP(y, 2) {
			if (a[i] != -1 && a[i] != x) continue;
			if (b[i] != -1 && b[i] != y) continue;
			int nbal = bal - (x - y);
			inc(suff[i][n + nbal], cur);
		}
	}

	int ret = 0;
	REP(i, n) REP(x, 2) REP(y, 2) {
		if (a[i] != -1 && a[i] != x) continue;
		if (b[i] != -1 && b[i] != y) continue;
		if (x == y) continue;
		FORE(bal, -n, +n) {
			int ways = pref[i][n + bal];
			if (ways == 0) continue;
			int nbal = bal + x - y;
			ways = (ll)ways * suff[i + 1][n + nbal] % MOD;
			int sgn = abs(nbal) > abs(bal) ? MOD - 1 : +1;
			//printf("i=%d x=%d y=%d bal=%d->%d ways=%d sgn=%d\n", i, x, y, bal, nbal, ways, sgn);
			ret = (ret + (ll)sgn * ways % MOD * i) % MOD;
		}
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	scanf("%s", s);
	scanf("%s", t);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}