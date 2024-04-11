#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXDAY = 1000000;
const int MAXPLAN = 200000;
struct Plan { int l, r, cnt, price; };

int nday, need, nplan;
Plan plan[MAXPLAN];

vector<int> byl[MAXDAY + 1], byr[MAXDAY + 1];
set<pair<int, int>> used; int usedcnt; ll usedprice;
set<pair<int, int>> unused;

void update() {
	while (SZ(used) > 0 && SZ(unused) > 0 && prev(used.end())->first > unused.begin()->first) {
		int idx = unused.begin()->second;
		usedcnt += plan[idx].cnt, usedprice += (ll)plan[idx].cnt*plan[idx].price, used.insert(MP(plan[idx].price, idx)), unused.erase(unused.begin());
	}
	while (usedcnt > need) {
		int idx = prev(used.end())->second;
		usedcnt -= plan[idx].cnt, usedprice -= (ll)plan[idx].cnt*plan[idx].price, unused.insert(MP(plan[idx].price, idx)), used.erase(prev(used.end()));
	}
	while (SZ(unused) > 0 && usedcnt + plan[unused.begin()->second].cnt <= need) {
		int idx = unused.begin()->second;
		usedcnt += plan[idx].cnt, usedprice += (ll)plan[idx].cnt*plan[idx].price, used.insert(MP(plan[idx].price, idx)), unused.erase(unused.begin());
	}
}

ll solve() {
	usedcnt = usedprice = 0; used.clear(); unused.clear(); FORE(i, 1, nday) byl[i].clear(), byr[i].clear();
	REP(i, nplan) byl[plan[i].l].PB(i), byr[plan[i].r].PB(i);
	ll ret = 0;
	FORE(i, 1, nday) {
		REPSZ(j, byl[i]) {
			int idx = byl[i][j];
			unused.insert(MP(plan[idx].price, idx));
		}
		update();
		ll cur = usedprice;
		if (usedcnt < need && !unused.empty()) {
			assert(need - usedcnt < plan[unused.begin()->second].cnt);
			cur += (ll)(need - usedcnt) * unused.begin()->first;
		}
		//printf("%d: %lld [", i, cur); for (auto it = used.begin(); it != used.end(); ++it) printf("%d,", it->first); printf("-"); for (auto it = unused.begin(); it != unused.end(); ++it) printf(",%d", it->first); puts("]");
		ret += cur;
		REPSZ(j, byr[i]) {
			int idx = byr[i][j];
			if (used.erase(MP(plan[idx].price, idx))) usedcnt -= plan[idx].cnt, usedprice -= (ll)plan[idx].cnt*plan[idx].price;
			unused.erase(MP(plan[idx].price, idx));
		}
	}
	return ret;
}

void run() {
	scanf("%d%d%d", &nday, &need, &nplan);
	REP(i, nplan) scanf("%d%d%d%d", &plan[i].l, &plan[i].r, &plan[i].cnt, &plan[i].price);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}