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

const int MOD = 1000000007;
const int MAXN = 1000;

int n, val, pos;


int fac[MAXN + 1];
int choose[MAXN + 1][MAXN + 1];


int solve() {
	fac[0] = 1; FORE(i, 1, n) fac[i] = (ll)fac[i - 1] * i % MOD;
	REPE(i, n) { choose[i][0] = choose[i][i] = 1; FOR(j, 1, i) choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % MOD; }

	int lo = 0, hi = n;
	int needsmaller = 0, needgreater = 0;
	while (lo < hi) {
		int mi = (lo + hi) / 2;
		if (mi == pos) {
			lo = mi + 1;
		} else if (mi < pos) {
			++needsmaller, lo = mi + 1;
		} else {
			++needgreater, hi = mi;
		}
	}
	//printf("needsmaller=%d needgreater=%d\n", needsmaller, needgreater);
	int havesmaller = val - 1;
	int havegreater = n - val;
	if (needsmaller > havesmaller || needgreater > havegreater) return 0;
	return (ll)choose[havesmaller][needsmaller] * choose[havegreater][needgreater] % MOD * fac[needsmaller] % MOD * fac[needgreater] % MOD * fac[n - needsmaller - needgreater - 1] % MOD;
}

void run() {
	scanf("%d%d%d", &n, &val, &pos);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}