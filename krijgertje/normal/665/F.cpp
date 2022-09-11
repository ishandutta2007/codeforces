#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

// Calculates number of primes <= lim where lim=n/x for some x
struct PrimeCnt {
	ll n; int sqrtn;
	vector<int> pmin, primes;
	void init(ll _n) {
		n = _n; sqrtn = (int)sqrt(1.0*n);
		pmin = vector<int>(sqrtn + 1, -1), primes.clear();
		FORE(i, 2, sqrtn) { if (pmin[i] == -1) pmin[i] = i, primes.PB(i); REPSZ(j, primes) if (primes[j] <= pmin[i] && (ll)i*primes[j] <= sqrtn) pmin[i*primes[j]] = primes[j]; else break; }
	}
	ll getlim(int idx) { return idx < sqrtn ? idx + 1 : n / (2 * sqrtn - idx); }
	int getidx(ll lim) { return lim <= sqrtn ? lim - 1 : 2 * sqrtn - n / lim; }
	vector<ll> res;
	void calc() {
		res = vector<ll>(2 * sqrtn);
		REP(i, 2 * sqrtn) res[i] = getlim(i) - 1;
		REPSZ(j, primes) {
			for (int i = 2 * sqrtn - 1; i >= 0; --i) {
				ll lim = getlim(i); if ((ll)primes[j] * primes[j] > lim) break;
				ll nlim = lim / primes[j]; int ni = getidx(nlim);
				res[i] -= res[ni] - res[primes[j] - 2];
			}
		}
		//REP(i, 2 * sqrtn) { ll lim = getlim(i); printf("%d: lim=%lld -> %lld\n", i, lim, res[i]); }
	}
};

PrimeCnt pcnt;


ull solve(ll n) {
	pcnt.init(n);
	pcnt.calc();
	ull ret = 0;
	REPSZ(i, pcnt.primes) {
		int p = pcnt.primes[i];
		ret += pcnt.res[pcnt.getidx(n / p)] - pcnt.res[pcnt.getidx(p)];
		if ((ll)p*p <= n / p) ++ret;
	}
	return ret;
}

void run() {
	ll n; scanf("%lld", &n);
	printf("%llu\n", solve(n));
}

int main() {
	run();
	return 0;
}