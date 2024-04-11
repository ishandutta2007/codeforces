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

vector<int> a[3];

int amn[3];
ll asum[3];
ll totsum;

ll solve() {
	totsum = 0;
	REP(i, 3) { asum[i] = 0; amn[i] = INT_MAX; REPSZ(j, a[i]) asum[i] += a[i][j], amn[i] = min(amn[i], a[i][j]); totsum += asum[i]; }
	ll ret = LLONG_MIN;
	REP(i, 3) ret = max(ret, totsum - 2 * asum[i]);
	REP(i, 3) ret = max(ret, totsum - 2 * ((ll)amn[0] + amn[1] + amn[2] - amn[i]));
	return ret;
}

void run() {
	REP(i, 3) { int cnt; scanf("%d", &cnt); a[i] = vector<int>(cnt); }
	REP(i, 3) REPSZ(j, a[i]) scanf("%d", &a[i][j]);
	printf("%lld\n", solve());
}

int main() {
	//int ncase; scanf("%d", &ncase); FORE(i, 1, ncase)
	run();
	return 0;
}