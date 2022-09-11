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

ll p; int q;

ll solve() {
	vector<pair<int, int>> qpr;
	{ int cur = q; for (int x = 2; (ll)x * x <= cur; ++x) if (cur % x == 0) { int cnt = 0; while (cur % x == 0) cur /= x, ++cnt; qpr.PB(MP(x, cnt)); } if (cur != 1) qpr.PB(MP(cur, 1)); }
	//printf("qpr:"); REPSZ(i, qpr) printf(" (%d,%d)", qpr[i].first, qpr[i].second); puts("");
	ll ret = 0;
	REPSZ(i, qpr) {
		int x = qpr[i].first; int qcnt = qpr[i].second;
		ll cur = p; int pcnt = 0; while (cur % x == 0) cur /= x, ++pcnt;
		int usecnt = min(pcnt, qcnt - 1);
		REP(j, usecnt) cur *= x;
		//printf("%d -> %lld (%d,%d)\n", x, cur, qcnt, pcnt);
		ret = max(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%lld%d", &p, &q);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}