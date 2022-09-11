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
int beauty[MAXN], cost[MAXN];

pair<int, int> o[MAXN];

ll solve() {
	REP(i, n) o[i] = MP(beauty[i], cost[i]);
	sort(o, o + n);
	ll ret = 0;
	REP(i, n) ret += cost[i];
	int upto = o[0].first;
	REP(i, n) {
		int a = o[i].first, c = o[i].second;
		if (a > upto) ret += a - upto;
		upto = max(upto, a + c);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d%d", &beauty[i], &cost[i]);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}