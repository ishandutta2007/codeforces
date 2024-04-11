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
#include <chrono>
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
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }

// Calculates sum of prime powers <= lim where lim=n/x for some x
template<class T> struct PrimePowerSum {
	ll n; int sqrtn;
	vector<int> pmin, primes;
	void init(ll _n) { 
		n = _n; sqrtn = (int)sqrt(1.0*n);
		pmin = vector<int>(sqrtn + 1, -1), primes.clear();
		FORE(i, 2, sqrtn) { if (pmin[i] == -1) pmin[i] = i, primes.PB(i); REPSZ(j, primes) if (primes[j] <= pmin[i] && (ll)i*primes[j] <= sqrtn) pmin[i*primes[j]] = primes[j]; else break; }
	}
	vector<vector<T>> res;
	void calc(int mxdeg) {
		res = vector<vector<T>>(2 * sqrtn, vector<T>(mxdeg + 1));
		REP(i, 2 * sqrtn) {
			T lim = i < sqrtn ? i + 1 : n / (2 * sqrtn - i), sum = lim % 2 == 0 ? (lim / 2)*(lim + 1) : (lim + 1) / 2 * lim;
			REPE(k, mxdeg) {
				if (k == 0) res[i][k] = lim - 1;
				else if (k == 1) res[i][k] = sum - 1;
				else if (k == 2) { T a = lim, b = lim + 1, c = 2 * lim + 1; if (a % 2 == 0) a /= 2; else if (b % 2 == 0) b /= 2; else c /= 2; if (a % 3 == 0) a /= 3; else if (b % 3 == 0) b /= 3; else c /= 3; res[i][k] = a*b*c - 1; }
				else if (k == 3) res[i][k] = sum*sum - 1;
				else assert(false); // not implemented
			}
		}
		REPSZ(j, primes) {
			T p = primes[j];
			for (int i = 2 * sqrtn - 1; i >= 0; --i) {
				ll lim = i < sqrtn ? i + 1 : n / (2 * sqrtn - i); if ((ll)primes[j] * primes[j] > lim) break;
				ll nlim = lim / primes[j]; int ni = nlim <= sqrtn ? nlim - 1 : 2 * sqrtn - n / nlim;
				T mlt = 1; REPE(k, mxdeg) { res[i][k] -= (res[ni][k] - res[primes[j] - 2][k])*mlt; mlt *= p; }
			}
		}
		//REP(i, 2 * sqrtn) { int lim = i < sqrtn ? i + 1 : n / (2 * sqrtn - i); printf("%d: lim=%d ->", i, lim); REPE(k, mxdeg) printf(" %u", res[i][k]); puts(""); }
	}
};

// floor(n/p)=x -> n/(x+1)<p<=n/x
// sum(p,n/p*f(p)) = sum(x,x*sum(p|n/p=x,f(p)) = sum(x,x*(g(n/x)-g(n/(x+1)))) with g(x)=sum(p<=x,f(p))
// x=1,2,...,sqrt(n)-1,sqrt(n),n/sqrt(n),n/(sqrt(n)-1),...,n/1

ll n; unsigned int A, B, C, D;

void run() {
	scanf("%lld%u%u%u%u", &n, &A, &B, &C, &D);

	PrimePowerSum<unsigned int> ppsum;
	ppsum.init(n);
	ppsum.calc(3);

	unsigned int ret = 0;
	FOR(i, 1, 2 * ppsum.sqrtn) {
		int lim = i < ppsum.sqrtn ? i + 1 : n / (2 * ppsum.sqrtn - i); unsigned int x = n / lim;
		ret += D*x*(ppsum.res[i][0] - ppsum.res[i - 1][0]);
		ret += C*x*(ppsum.res[i][1] - ppsum.res[i - 1][1]);
		ret += B*x*(ppsum.res[i][2] - ppsum.res[i - 1][2]);
		ret += A*x*(ppsum.res[i][3] - ppsum.res[i - 1][3]);
	}
	REPSZ(j, ppsum.primes) {
		unsigned int p = ppsum.primes[j], val = ((A*p + B)*p + C)*p + D;
		unsigned int cnt = 0; for (int i = n / p / p; i > 0; i /= p) cnt += i;
		ret += val*cnt;
	}
	printf("%u\n", ret);
}

int main() {
	chrono::high_resolution_clock::time_point TBEGIN = chrono::high_resolution_clock::now();
	run();
	fprintf(stderr, "Took: %.3lf seconds\n", chrono::duration_cast<chrono::duration<double>>(chrono::high_resolution_clock::now() - TBEGIN).count());
	return 0;
}