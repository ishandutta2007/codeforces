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

const int MAXN = 100000;

int n;
int l[MAXN], r[MAXN], cost[MAXN];
int ans[MAXN];

void solve() {
	int bestl = l[0], bestlcost = cost[0], bestr = r[0], bestrcost = cost[0], bestbothcost = cost[0];
	ans[0] = cost[0];
	FOR(i, 1, n) {
		if (l[i] < bestl) bestl = l[i], bestlcost = cost[i], bestbothcost = INT_MAX; else if (l[i] == bestl) bestlcost = min(bestlcost, cost[i]);
		if (r[i] > bestr) bestr = r[i], bestrcost = cost[i], bestbothcost = INT_MAX; else if (r[i] == bestr) bestrcost = min(bestrcost, cost[i]);
		if (l[i] == bestl && r[i] == bestr) bestbothcost = min(bestbothcost, cost[i]);
		ans[i] = min(bestbothcost, bestlcost + bestrcost);
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d%d", &l[i], &r[i], &cost[i]);
	solve();
	REP(i, n) printf("%d\n", ans[i]);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}