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

const int MAXN = 150000;
const int MOD = 998244353;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n, lim;
int a[MAXN];

int nonempty[MAXN + 1];

int rec(int la, int ra, int lb, int rb, int bit) {
	if (la == ra || lb == rb) return 0;
	if (bit == -1) return (ll)nonempty[ra - la] * nonempty[rb - lb] % MOD;
	int ma = la;
	while (ma < ra && (a[ma] & (1 << bit)) == 0) ++ma;
	int mb = lb;
	while (mb < rb && (a[mb] & (1 << bit)) == 0) ++mb;
	int ret = 0;
	if ((lim&(1 << bit)) == 0) {
		inc(ret, rec(la, ma, lb, mb, bit - 1));
		inc(ret, rec(ma, ra, mb, rb, bit - 1));
	} else {
		int x = rec(la, ma, mb, rb, bit - 1);
		int y = rec(ma, ra, lb, mb, bit - 1);
		inc(ret, x);
		inc(ret, y);
		inc(ret, (ll)nonempty[ma - la] * nonempty[mb - lb] % MOD);
		inc(ret, (ll)nonempty[ra - ma] * nonempty[rb - mb] % MOD);
		inc(ret, (ll)x*(nonempty[ra - ma] + nonempty[mb - lb]) % MOD);
		inc(ret, (ll)y*(nonempty[ma - la] + nonempty[rb - mb]) % MOD);
		inc(ret, (ll)x*y%MOD);
	}
	return ret;
}

int rec(int l, int r, int bit) {
	if (l == r) return 0;
	if (bit == -1) return nonempty[r - l];
	int m = l;
	while (m < r && (a[m] & (1 << bit)) == 0) ++m;
	int ret = 0;
	if ((lim&(1 << bit)) == 0) {
		inc(ret, rec(l, m, bit - 1));
		inc(ret, rec(m, r, bit - 1));
	} else {
		inc(ret, nonempty[m - l]);
		inc(ret, nonempty[r - m]);
		inc(ret, rec(l, m, m, r, bit - 1));
	}
	return ret;
}

int solve() {
	nonempty[0] = 0; FORE(i, 1, n) nonempty[i] = ((ll)2 * nonempty[i - 1] + 1) % MOD;
	sort(a, a + n);
	return rec(0, n, 29);
}

void run() {
	scanf("%d%d", &n, &lim);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}