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

const int MAXFRIEND = 300000;
const int MAXPRESENT = 300000;

int nfriend, npresent;
int want[MAXFRIEND];
int cost[MAXPRESENT];

ll sumwant[MAXFRIEND + 1];
ll sumcost[MAXPRESENT + 1];

ll solve() {
	sort(want, want + nfriend);
	int mndirect = 0;
	REP(i, nfriend) mndirect = max(mndirect, i - want[i]);

	sumwant[0] = 0; REP(i, nfriend) sumwant[i + 1] = sumwant[i] + cost[want[i]];
	sumcost[0] = 0; REP(i, npresent) sumcost[i + 1] = sumcost[i] + cost[i];

	ll ret = LLONG_MAX;
	FORE(i, mndirect, nfriend) {
		ll cur = 0;
		cur += sumcost[nfriend - i];
		cur += sumwant[i];
		ret = min(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d%d", &nfriend, &npresent);
	REP(i, nfriend) scanf("%d", &want[i]), --want[i];
	REP(i, npresent) scanf("%d", &cost[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}