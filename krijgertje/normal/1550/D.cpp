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

const int MAXN = 200000;
const int MOD = 1000000007;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n, l, r;

int inv[MAXN + 1];
int fac[MAXN + 1];
int ifac[MAXN + 1];
int choose(int n, int k) { if (k<0 || k>n) return 0; return (ll)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD; }

int solve() {
	inv[1] = 1; FORE(i, 2, n) inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = 1; FORE(i, 1, n) fac[i] = (ll)fac[i - 1] * i % MOD;
	ifac[0] = 1; FORE(i, 1, n) ifac[i] = (ll)ifac[i - 1] * inv[i] % MOD;

	int ret = 0;

	//r-x<n ->x>r-n, n-(l+x)+1<n -> x>-l+1
	int lx = min(r - n + 1, -l + 2);
	int times = lx - 1;
	{
		int numpos = n;
		int numneg = n;
		//printf("x=%d numpos=%d numneg=%d\n", x, numpos, numneg);
		int haveboth = numpos + numneg - n, havea = numpos - haveboth, haveb = numneg - haveboth;
		REP(par, 2) {
			if (par == 1 && n % 2 == 0) continue;
			int wanta = (n + par) / 2, wantb = n - wanta;
			if (havea + haveboth < wanta || haveb + haveboth < wantb) continue;
			ret = (ret + (ll)times * choose(haveboth, wanta - havea)) % MOD;
		}
	}
	for (int x = lx;; ++x) {
		int numpos = min(n, r - x);
		int numneg = min(n, n - (l + x) + 1);
		if (numpos + numneg < n) break;
		//printf("x=%d numpos=%d numneg=%d\n", x, numpos, numneg);
		int haveboth = numpos + numneg - n, havea = numpos - haveboth, haveb = numneg - haveboth;
		REP(par, 2) {
			if (par == 1 && n % 2 == 0) continue;
			int wanta = (n + par) / 2, wantb = n - wanta;
			if (havea + haveboth < wanta || haveb + haveboth < wantb) continue;
			inc(ret, choose(haveboth, wanta - havea));
		}
	}
	return ret;
}

void run() {
	scanf("%d%d%d", &n, &l, &r);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}