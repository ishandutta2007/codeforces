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

const int MAXN = 100000;

int n;
int cost[MAXN];

ll solve() {
	ll ret = LLONG_MAX;
	ll evencost = cost[0], oddcost = cost[1];
	int evenbest = cost[0], oddbest = cost[1];
	int evenrem = n - 1, oddrem = n - 1;
	FORE(k, 2, n) {
		ll cur = evencost + oddcost + (ll)evenrem * evenbest + (ll)oddrem * oddbest;
		//printf("k=%d: evencost=%lld oddcost=%lld evenrem=%d evenbest=%d oddrem=%d oddbest=%d -> %lld\n", k, evencost, oddcost, evenrem, evenbest, oddrem, oddbest, cur);
		ret = min(ret, cur);
		if (k == n) break;
		if (k % 2 == 0) evencost += cost[k], evenbest = min(evenbest, cost[k]), --evenrem;
		if (k % 2 == 1) oddcost += cost[k], oddbest = min(oddbest, cost[k]), --oddrem;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &cost[i]);
	printf("%lld\n", solve());
}


int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}