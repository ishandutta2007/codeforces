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

int x, y;
int cost[6];

ll solve() {
	if (x < 0) {
		x = -x, y = -y;
		REP(i, 3) swap(cost[i], cost[i + 3]);
	}
	while (true) {
		bool change = false;
		REP(i, 6) { int a = i, b = (i + 1) % 6, c = (i + 2) % 6; if (cost[a] + cost[c] < cost[b]) cost[b] = cost[a] + cost[c], change = true; }
		if (!change) break;
	}
	ll ret = 0;
	if (x > 0 && y > 0) {
		int z = min(x, y);
		ret += (ll)z * cost[0];
		x -= z, y -= z;
	}
	ret += (ll)x * cost[5];
	if (y < 0) ret += (ll)(-y) * cost[4];
	if (y > 0) ret += (ll)(+y) * cost[1];
	return ret;
}

void run() {
	scanf("%d%d", &x, &y);
	REP(i, 6) scanf("%d", &cost[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}