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
const int MOD = 998244353;

int n;
int from[MAXN], to[MAXN], init[MAXN];

int cost[MAXN];
int sumcost[MAXN + 1];

int solve() {
	sumcost[0] = 0;
	REP(i, n) {
		cost[i] = (from[i] - to[i]) % MOD;
		int idx = lower_bound(from, from + n, to[i]) - from;
		cost[i] = ((ll)cost[i] + sumcost[i] - sumcost[idx] + MOD) % MOD;
		sumcost[i + 1] = (sumcost[i] + cost[i]) % MOD;
		//printf("%d: cost=%d (idx=%d)\n", i, cost[i], idx);
	}
	int ret = (from[n - 1] + 1) % MOD;
	REP(i, n) if (init[i]) ret = (ret + cost[i]) % MOD;
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d%d", &from[i], &to[i], &init[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}