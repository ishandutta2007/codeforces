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

const int MAXNUMBER = 2000000;
const int MAXJOKER = 2000000;
const int MOD = 998244353;
int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret * x % MOD; if ((n >>= 1) == 0) return ret; x = (ll)x * x % MOD; } }
int calcinv(int x) { return pw(x, MOD - 2); }

int nnumber, njoker;

int inv[MAXNUMBER + MAXJOKER + 2];
int fac[MAXNUMBER + MAXJOKER + 2];
int ifac[MAXNUMBER + MAXJOKER + 2];
int choose(int n, int k) { if (k<0 || k>n) return 0; return (ll)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD; }

int solve() {
	inv[1] = 1; FORE(i, 2, nnumber + njoker + 1) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, nnumber + njoker + 1) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, nnumber + njoker + 1) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	// f(x) = expected cost when x numbers remaining
	// f(0) = 0, f(x) = sum(i=0..x: sum(j=i..nnumber-x+i: choose(x,i)*choose(nnumber-x,j-i)*j!*njoker*(nnumber+njoker-j-1)!/(nnumber+njoker)!*(f(x-a)+j+1)))
	// split up [A] f(x-a) and [B] j+1 part
	// A: njoker*x!*(nnumber-x)!/(nnumber+njoker)!*sum(i=0..x: 1/i!/(x-i)!*f(x-i)*sum(j=i..nnumber-x+i: 1/(j-i)!/(nnumber-x-j+i)!*j!*(nnumber+njoker-j-1)!))
	// = njoker*x!*(nnumber-x)!/(nnumber+njoker)!*sum(i=0..x: (njoker+x-i-1)!/(x-i)!*f(x-i)*sum(j=i..nnumber-x+i: choose(j,i)*choose(nnumber+njoker-1-j,njoker+x-1-i)))
	// = njoker*x!*(nnumber-x)!/(nnumber+njoker)!*choose(nnumber+njoker,njoker+x)*sum(i=0..x: (njoker+x-i-1)!/(x-i)!*f(x-i))
	// (suppose we have nnumber+njoker items and need to choose njoker+x of them, first fix ith item (zero-based) at position j (zero-based), then need to choose i items out of j before and njoker+x-1-i items out of nnumber+njoker-1-j items)
	// = njoker*x!*(nnumber-x)!/(nnumber+njoker)!*choose(nnumber+njoker,njoker+x)*sum(k=0..x: (njoker+k-1)!/k!*f(k))
	// similarly B: njoker*x!*(nnumber-x)!/(nnumber+njoker)!*choose(nnumber+njoker+1,njoker+x+1)*((x+1)*sum(k=0..x: (njoker+k-1)!/k!)-sum(k=1..x: (njoker+k-1)!/(k-1)!))

	vector<int> f(nnumber + 1);
	vector<int> g(nnumber + 1); // g(x) = sum(k=0..x,(njoker+k-1)!/k!*f(k))
	vector<int> p(nnumber + 1); // p(x) = sum(k=0..x,(njoker+k-1)!/k!)
	vector<int> q(nnumber + 1); // q(x) = sum(k=1..x,(njoker+k-1)!/(k-1)!)
	f[0] = 0, g[0] = 0, p[0] = (ll)fac[njoker - 1] * ifac[0] % MOD, q[0] = 0;
	FORE(x, 1, nnumber) {
		int mlt = (ll)njoker * fac[x] % MOD * fac[nnumber - x] % MOD * ifac[nnumber + njoker] % MOD;
		int amlt = choose(nnumber + njoker, njoker + x), bmlt = choose(nnumber + njoker + 1, njoker + x + 1);
		int den = (1 + MOD - (ll)mlt * amlt % MOD * fac[njoker + x - 1] % MOD * ifac[x] % MOD) % MOD;
		p[x] = (p[x - 1] + (ll)fac[njoker + x - 1] * ifac[x]) % MOD;
		q[x] = (q[x - 1] + (ll)fac[njoker + x - 1] * ifac[x - 1]) % MOD;
		f[x] = ((ll)mlt * amlt % MOD * g[x - 1] + (ll)mlt * bmlt % MOD * ((ll)(x + 1) * p[x] % MOD + MOD - q[x])) % MOD * calcinv(den) % MOD;
		g[x] = (g[x - 1] + (ll)fac[njoker + x - 1] * ifac[x] % MOD * f[x]) % MOD;
	}
	//REPE(i, nnumber) printf("%d: f=%d g=%d p=%d q=%d\n", i, f[i], g[i], p[i], q[i]);
	return f[nnumber];
}

void run() {
	scanf("%d%d", &nnumber, &njoker);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}