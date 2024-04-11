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

const int MAXN = 10000000;
const int MAXK = 17;
const int MOD = 998244353;

int n, k;
int a[MAXN];

int solve() {
	/*vector<int> cur(a, a + n);
	auto rec = [&](auto self, int idx,int sofar) -> int {
		if (idx > k) return sofar;
		int ret = 0;
		REP(i, n) {
			int old = cur[i];
			cur[i] -= cur[i] % idx;
			ret = (ret + self(self, idx + 1, (sofar + old) % MOD)) % MOD;
			cur[i] = old;
		}
		return ret;
	};
	printf("stupid = %d\n", rec(rec, 1, 0));*/


	int period = 1;
	FORE(i, 2, k - 1) period = period / gcd(period, i) * i;
	//printf("k=%d period=%d\n", k, period);
	//printf("a:"); REP(i, n) printf(" %d", a[i]); puts("");

	vector<int> val(period, 0);
	int vmlt = 1;
	for (int i = k; i >= 1; --i) {
		for (int j = period - 1; j >= 0; --j) {
			val[j] = ((ll)(n - 1) * val[j] + (ll)j * vmlt + val[j - j % i]) % MOD;
		}
		vmlt = (ll)vmlt * n % MOD;
	}
	//printf("val:"); REP(i, period) printf(" %d", val[i]); puts("");

	int mlt = (ll)k * period % MOD;
	REP(i, k - 1) mlt = (ll)mlt * n % MOD;


	int ret = 0;
	REP(i, n) {
		int p = a[i] / period, q = a[i] % period;
		ret = (ret + (ll)mlt * p + val[q]) % MOD;
	}
	return ret;



	/*
	REP(mask, 1 << k) {
		REP(rep, 1000) {
			int sx = rnd() % period;
			int sy = sx + period;
			int cx = sx, cy = sy;
			ll xsum = 0, ysum = 0;
			int cnt = 0;
			REP(i, k) if (mask & (1 << k)) {
				xsum += cx;
				cx -= cx % (i + 1);
				ysum += cy;
				cy -= cy % (i + 1);
			}
			assert(ysum == xsum + cnt * period);
		}
	}
	*/
}

void run() {
	int x, y, M;
	scanf("%d%d%d%d%d%d", &n, &a[0], &x, &y, &k, &M);
	FOR(i, 1, n) a[i] = ((ll)a[i - 1] * x + y) % M;
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}