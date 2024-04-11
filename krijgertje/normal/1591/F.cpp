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
const int MAXS = 4 * MAXN;
const int MOD = 998244353;
int neg(int x) { return x == 0 ? 0 : MOD - x; }
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }

struct Z { int lim, sum, prod, sumprod; };


int n;
int a[MAXN];

int solve() {
	vector<Z> stck;
	vector<int> dp(n + 1);
	dp[0] = 1;
	REP(i, n) {
		Z z; z.lim = a[i]; z.sum = i % 2 == 0 ? dp[i] : neg(dp[i]);
		while (SZ(stck) >= 1 && stck[SZ(stck) - 1].lim >= a[i]) {
			inc(z.sum, stck[SZ(stck) - 1].sum);
			stck.pop_back();
		}
		z.prod = z.sumprod = (ll)z.sum * z.lim % MOD;
		if (SZ(stck) >= 1) inc(z.sumprod, stck[SZ(stck) - 1].sumprod);
		dp[i + 1] = i % 2 == 0 ? z.sumprod : neg(z.sumprod);
		//printf("dp[%d]=%d\n", i + 1, dp[i + 1]);
		stck.PB(z);
	}
	return dp[n];
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}