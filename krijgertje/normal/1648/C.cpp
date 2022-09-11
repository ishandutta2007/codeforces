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

const int MAXN = 200000;
const int MOD = 998244353;

int na, nb;
int a[MAXN];
int b[MAXN];

int inv[MAXN + 1];
int fac[MAXN + 1];
int ifac[MAXN + 1];

struct BIT {
	int n; vector<int> val;
	void init(int _n) { n = _n; val = vector<int>(n + 1, 0); }
	int get(int idx) { int ret = 0; ++idx; while (idx > 0) { ret += val[idx]; idx -= idx & -idx; } return ret; }
	void mod(int idx, int by) { ++idx; while (idx <= n) { val[idx] += by; idx += idx & -idx; } }
};


int solve() {
	inv[1] = 1; FORE(i, 2, na) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, na) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, na) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;
	int mxval = a[0];
	REP(i, na) mxval = max(mxval, a[i]);
	REP(i, nb) mxval = max(mxval, b[i]);
	vector<int> cnt(mxval + 1, 0);
	BIT bit;

	bit.init(mxval + 1);
	int den = 1;
	REP(i, na) {
		++cnt[a[i]];
		bit.mod(a[i], +1);
		den = (ll)den * fac[cnt[a[i]] - 1] % MOD * ifac[cnt[a[i]]] % MOD;
	}

	int ret = 0;
	REP(i, na) {
		if (i >= nb) return ret;
		int rem = na - i - 1;
		int smaller = bit.get(b[i] - 1);
		//printf("i=%d b[i]=%d smaller=%d -> %lld\n", i, b[i], smaller, (ll)smaller * fac[rem] % MOD * den % MOD);
		ret = (ret + (ll)smaller * fac[rem] % MOD * den) % MOD;
		if (cnt[b[i]] == 0) return ret;
		--cnt[b[i]];
		bit.mod(b[i], -1);
		den = (ll)den * fac[cnt[b[i]] + 1] % MOD * ifac[cnt[b[i]]] % MOD;
	}
	if (nb > na) ret = (ret + 1) % MOD;
	return ret;
}

void run() {
	scanf("%d%d", &na, &nb);
	REP(i, na) scanf("%d", &a[i]);
	REP(i, nb) scanf("%d", &b[i]);
	printf("%d\n", solve());

}

int main() {
	run();
	return 0;
}