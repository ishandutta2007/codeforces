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

// sum(i/j/k,(x[i]&x[j])*(x[j]|x[k]))
// sum(abit,bbit,sum(i/j/k|x[i] has abit AND x[j] has abit AND x[j] has bbit,2^(a+b))) + sum(abit,bbit,sum(i/j/k|x[i] has abit AND x[j] has abit AND x[j] does not have bbit AND x[k] has bbit,2^(a+b)))
// sum(abit,sum(j|x[j] has abit,bitcnt[abit]*x[j]*2^a)) + sum(abit,sum(j|x[j] has abit,bitcnt[abit]*2^a*sum(bbit,x[j] does not have bbit,bitcnt[bbit]*2^b)))

const int MAXN = 500000;
const int MOD = 1000000007;
const int BITS = 60;

int n;
ll x[MAXN];

int bitcnt[BITS];
int xmod[MAXN];
int p2[2*BITS+1];
int pre[MAXN];

int solve() {
	REP(i, n) xmod[i] = x[i] % MOD;
	p2[0] = 1; FORE(i, 1, 2 * BITS) p2[i] = (ll)p2[i - 1] * 2 % MOD;

	REP(k, BITS) bitcnt[k] = 0;
	REP(i, n) REP(k, BITS) if (x[i] & (1LL << k)) ++bitcnt[k];
	REP(i, n) { pre[i] = 0; REP(b, BITS) if ((x[i] & (1LL << b)) == 0) pre[i] = (pre[i] + (ll)bitcnt[b] * p2[b]) % MOD; }

	int ret = 0;
	
	//REP(a, BITS) REP(b, BITS) REP(i, n) REP(j, n) REP(k, n) if ((x[i] & (1LL << a)) != 0 && (x[j] & (1LL << a)) != 0 && (x[j] & (1LL << b)) != 0) ret = (ret + p2[a + b]) % MOD;
	//REP(a, BITS) REP(b, BITS) REP(i, n) REP(j, n) REP(k, n) if ((x[i] & (1LL << a)) != 0 && (x[j] & (1LL << a)) != 0 && (x[j] & (1LL << b)) == 0 && (x[k] & (1LL << b)) != 0) ret = (ret + p2[a + b]) % MOD;
	
	REP(a, BITS) REP(j, n) if (x[j] & (1LL << a)) {
		ret = (ret + (ll)bitcnt[a] * xmod[j] % MOD * p2[a] % MOD *n) % MOD;
		ret = (ret + (ll)bitcnt[a] * p2[a] % MOD * pre[j]) % MOD;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%lld", &x[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}