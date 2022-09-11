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

int n, want;
int give[MAXN], cost[MAXN];

int solve() {
	vector<ll> one, two;
	REP(i, n) if (cost[i] == 1) one.PB(give[i]); else if (cost[i] == 2) two.PB(give[i]); else assert(false);
	sort(one.begin(), one.end()); reverse(one.begin(), one.end());
	sort(two.begin(), two.end()); reverse(two.begin(), two.end());
	one.insert(one.begin(), 0); FORSZ(i, 1, one) one[i] += one[i - 1];
	two.insert(two.begin(), 0); FORSZ(i, 1, two) two[i] += two[i - 1];
	int ret = INT_MAX;
	int at = SZ(one);
	REPSZ(i, two) {
		while (at - 1 >= 0 && two[i] + one[at - 1] >= want) --at;
		if (at < SZ(one)) ret = min(ret, 2 * i + at);
	}
	return ret == INT_MAX ? -1 : ret;
}

void run() {
	scanf("%d%d", &n, &want);
	REP(i, n) scanf("%d", &give[i]);
	REP(i, n) scanf("%d", &cost[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}