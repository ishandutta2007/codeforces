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

const int MOD = 1000000007;

int bfirst, bstep, bcnt;
int cfirst, cstep, ccnt;

int solve() {
	if (cstep % bstep != 0) return 0;
	ll blast = bfirst + (ll)bstep * (bcnt - 1);
	ll clast = cfirst + (ll)cstep * (ccnt - 1);
	if (cfirst < bfirst || clast > blast) return 0;
	if ((cfirst - bfirst) % bstep != 0) return 0;
	if (cfirst - cstep < bfirst || clast + cstep > blast) return -1;

	// lcm(astep,bstep)=cstep -> astep*bstep/gcd(astep,bstep)=cstep -> astep/gcd(astep,bstep)=cstep/bstep -> (bstep/gcd(astep,bstep))^2 opt
	// if(cfirst - lcm < bfirst || clast + lcm > blast) -> oo

	int ret = 0;
	for (int g = 1; (ll)g * g <= bstep; ++g) {
		if (bstep % g == 0) {
			{
				int astep = cstep / bstep * g;
				if (gcd(astep, bstep) == g) {
					int opt = bstep / g;
					//printf("astep=%d -> %d*%d\n", astep, opt, opt);
					ret = (ret + (ll)opt * opt) % MOD;
				}
			}
			if (bstep / g != g) {
				int astep = cstep / bstep * (bstep / g);
				if (gcd(astep, bstep) == bstep / g) {
					int opt = bstep / (bstep / g);
					//printf("astep=%d -> %d*%d\n", astep, opt, opt);
					ret = (ret + (ll)opt * opt) % MOD;
				}
			}
		}
	}
	return ret;
}

void run() {
	scanf("%d%d%d", &bfirst, &bstep, &bcnt);
	scanf("%d%d%d", &cfirst, &cstep, &ccnt);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}