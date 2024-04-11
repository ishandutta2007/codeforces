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

const int MAXN = 300000;
const int MOD = 998244353;
int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret * x % MOD; if ((n >>= 1) == 0) return ret; x = (ll)x * x % MOD; } }

int n;
int a[MAXN];
int ans[MAXN + 1];

int asum[MAXN + 1];

void solve() {
	sort(a, a + n); reverse(a, a + n);
	asum[0] = 0; REP(i, n) { asum[i + 1] = asum[i] + a[i]; if (asum[i + 1] >= MOD) asum[i + 1] -= MOD; }
	FORE(k, 1, n) {
		int nmlt = (n + k - 1) / k;
		int cur = 0;
		REP(i, nmlt) {
			int l = i * k, r = min((i + 1) * k, n);
			int sum = asum[r] - asum[l]; if (sum < 0) sum += MOD;
			//printf("k=%d: i=%d -> %d..%d -> sum=%d\n", k, i, l, r, sum);
			cur = (cur + (ll)sum * i) % MOD;
		}
		ans[k] = cur;
	}
	int mlt = pw(n, MOD - 2);
	FORE(k, 1, n) ans[k] = (ll)ans[k] * mlt % MOD;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	FORE(k, 1, n) { if (k != 1) printf(" "); printf("%d", ans[k]); } puts("");
}

int main() {
	run();
	return 0;
}