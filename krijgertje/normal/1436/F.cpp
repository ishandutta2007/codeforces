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

const int MAXN = 100000;
const int MOD = 998244353;
const int MAXVAL = 100000;
const int INV2 = (MOD + 1) / 2;
int pw(int x, ll n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret * x % MOD; if ((n >>= 1) == 0) return ret; x = (ll)x * x % MOD; } }

int n;
int val[MAXN], freq[MAXN];

int calc1(ll n) { // sum(i*choose(n,i))
	if (n == 0) return 0;
	return (ll)pw(2, n - 1) * (n % MOD) % MOD;
}
int calc2(ll n) { // sum((i+1)*choose(n,i))
	return (calc1(n) + pw(2, n)) % MOD;
}

int calc(vector<int> ids) {
	if (SZ(ids) == 0) return 0;
	ll cnt = 0;
	int sum = 0;
	int sumsq = 0;
	REPSZ(i, ids) {
		int idx = ids[i]; 
		cnt += freq[idx];
		sum = (sum + (ll)freq[idx] * val[idx]) % MOD;
		sumsq = (sumsq + (ll)freq[idx] * val[idx] % MOD * val[idx]) % MOD;
	}
	int sumpair = ((ll)sum * sum + MOD - sumsq) % MOD;

	int sqmlt = calc1(cnt - 1);
	int pairmlt = cnt == 1 ? 0 : calc2(cnt - 2);
	return ((ll)sumsq * sqmlt + (ll)sumpair * pairmlt) % MOD;
}

int who[MAXVAL + 1];

int solve() {
	vector<int> all(n); REP(i, n) all[i] = i;

	vector<bool> isprime(MAXVAL + 1, true); isprime[0] = isprime[1] = false; FORSZ(i, 2, isprime) if (isprime[i]) for (int j = i + i; j < SZ(isprime); j += i) isprime[j] = false;
	vector<int> mu(MAXVAL + 1, +1); REPSZ(i, mu) if (isprime[i]) { for (int j = i; j < SZ(mu); j+=i) mu[j] = -mu[j]; if ((ll)i * i < SZ(mu)) for (int j = i * i; j < SZ(mu); j += i * i) mu[j] = 0; }

	REPE(i, MAXVAL) who[i] = -1;
	REP(i, n) { assert(who[val[i]] == -1); who[val[i]] = i; }

	int ret = 0;
	FORSZ(i, 1, mu) if (mu[i] != 0) {
		vector<int> lst; for (int j = i; j <= MAXVAL; j+=i) if (who[j] != -1) lst.PB(who[j]);
		int cur = calc(lst);
		//if (cur != 0) printf("%d = %d (%d)\n", i, cur, mu[i]);
		ret += mu[i] * cur;
		ret = (ret % MOD + MOD) % MOD;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &val[i], &freq[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}