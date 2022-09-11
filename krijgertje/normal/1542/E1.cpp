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

		vector<int> nways(SZ(ways) + 2 * suff); int nzero = zero + suff;
		FORE(i, -nzero, +nzero) FORE(j, -zero, +zero) if (abs(i - j) <= suff + 1) nways[nzero + i] = (nways[nzero + i] + (ll)ways[zero + j] * (suff + 1 - abs(i - j))) % MOD;
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