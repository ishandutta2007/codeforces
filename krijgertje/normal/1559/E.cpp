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

const int MAXN = 50;
const int MAXSUM = 100000;
const int MOD = 998244353;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int& a, int b) { inc(a, MOD - b); }

int n, mxsum;
int al[MAXN], ar[MAXN];

int pmn[MAXSUM + 1];
int mu[MAXSUM + 1];


int bl[MAXN], br[MAXN];
int bk[MAXN];

int inv[MAXSUM + 1];
int fac[MAXSUM + 1];
int ifac[MAXSUM + 1];
int choose(int n, int k) { if (k<0 || k>n) return 0; return (ll)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD; }

int calc(int g) {
	REP(i, n) bl[i] = (al[i] + g - 1) / g, br[i] = ar[i] / g;
	REP(i, n) if (bl[i] > br[i]) return 0;

	int blim = mxsum / g;
	REP(i, n) blim -= bl[i], bk[i] = br[i] - bl[i] + 1;
	if (blim < 0) return 0;

	vector<int> ways(blim + 1, 0);
	inc(ways[0], 1);
	REP(i, n) for (int j = blim; j >= bk[i]; --j) dec(ways[j], ways[j - bk[i]]);

	int ret = 0;
	REPE(i, blim) if (ways[i] != 0) {
		int rem = blim - i;
		ret = (ret + (ll)ways[i] * choose(rem + n, n)) % MOD;
	}
	return ret;
}

int solve() {
	FORE(i, 1, mxsum) inv[i] = i == 1 ? 1 : (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	FORE(i, 0, mxsum) fac[i] = i == 0 ? 1 : (ll)i * fac[i - 1] % MOD;
	FORE(i, 0, mxsum) ifac[i] = i == 0 ? 1 : (ll)inv[i] * ifac[i - 1] % MOD;

	REPE(i, mxsum) pmn[i] = -1;
	FORE(i, 2, mxsum) if (pmn[i] == -1) for (int j = i; j <= mxsum; j += i) if (pmn[j] == -1) pmn[j] = i;
	mu[1] = 1; FORE(i, 2, mxsum) { int j = i / pmn[i]; mu[i] = pmn[j] == pmn[i] ? 0 : -mu[j]; }
	//printf("mu:"); FORE(i, 1, mxsum) if (mu[i] != 0) printf(" %d:%d", i, mu[i]); puts("");

	int ret = 0;
	FORE(i, 1, mxsum) if (mu[i] != 0) ret = (ret + (ll)(MOD + mu[i]) * calc(i)) % MOD;
	return ret;
}

void run() {
	scanf("%d%d", &n, &mxsum);
	REP(i, n) scanf("%d%d", &al[i], &ar[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}