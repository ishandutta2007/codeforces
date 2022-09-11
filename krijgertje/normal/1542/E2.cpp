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

const int MAXN = 500;

int n, MOD;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int& a, int b) { inc(a, MOD - b); }

int solve() {
	vector<int> ways(1, 1 % MOD); int zero = 0;
	int ret = 0;
	REPE(suff, n) {
		//printf("%d:", suff); REPSZ(i, ways) printf(" %d", ways[i]); puts("");
		if (suff == n) break;

		vector<int> sum = ways;
		FORSZ(i, 1, sum) inc(sum[i], sum[i - 1]);
		int cur = 0;
		FORE(diff, 1, suff) if (1 + diff <= zero) cur = (cur + (ll)(suff + 1 - diff) * sum[zero - 1 - diff]) % MOD;
		//printf("%d -> %d\n", n - suff - 1, cur);
		ret = ((ll)ret * (suff + 1) + cur) % MOD;

		vector<int> nways(SZ(ways) + 2 * suff + 2); int nzero = zero + suff;
		// sum(i=0..suff: x^i)*sum(i=0..suff,x^(-i))
		// (x^(suff+1)-1)/(x-1)*(x^(-suff-1)-1)/(x^(-1)-1)
		// (x^(suff+1)-1)/(x-1)*(x-x^(-suff))/(x-1)
		// (x^(suff+2)+x^(-suff)-2x)/(x-1)^2
		FORE(i, -zero, +zero) {
			inc(nways[nzero + i + suff + 2], ways[zero + i]);
			inc(nways[nzero + i - suff], ways[zero + i]);
			dec(nways[nzero + i + 1], ways[zero + i]);
			dec(nways[nzero + i + 1], ways[zero + i]);
		}
		REP(rep, 2) {
			for (int i = SZ(nways) - 1; i >= 1; --i) inc(nways[i - 1], nways[i]);
			assert(nways[0] == 0); FORSZ(i, 1, nways) nways[i - 1] = nways[i]; nways.pop_back();
		}
		ways = nways, zero = nzero;
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &MOD);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}