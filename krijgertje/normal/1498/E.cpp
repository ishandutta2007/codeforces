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

const int MAXN = 500;

int n;
int indeg[MAXN];

pair<int, int> ord[MAXN];

pair<int, int> solve() {
	REP(i, n) ord[i] = MP(n - indeg[i] - 1, i);
	REP(i, n) ord[i].first = -ord[i].first;
	sort(ord, ord + n);
	REP(i, n) ord[i].first = -ord[i].first;
	vector<vector<int>> comps;
	int at = 0;
	while (at < n) {
		int outsum = 0;
		int to = at;
		outsum += ord[to++].first;
		while (true) {
			int want = (n - to) * (to - at) + (to - at) * (to - at - 1) / 2;
			assert(outsum <= want);
			if (outsum == want) break;
			assert(to < n);
			outsum += ord[to++].first;
		}
		vector<int> comp; FOR(i, at, to) comp.PB(ord[i].second); comps.PB(comp);
		at = to;
	}
	pair<int, int> ret = MP(-1, -1); int retdiff = INT_MIN;
	for (auto c : comps) {
		if (SZ(c) <= 1) continue;
		vector<pair<int, int>> cur;
		for (int at : c) cur.PB(MP(indeg[at], at));
		sort(cur.begin(), cur.end());
		int curdiff = abs(cur[0].first - cur[SZ(cur) - 1].first);
		if (curdiff > retdiff) retdiff = curdiff, ret = MP(cur[0].second, cur[SZ(cur) - 1].second);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &indeg[i]);
	pair<int, int> ans = solve();
	if (ans == MP(-1, -1)) printf("! 0 0\n"); else printf("! %d %d\n", ans.first + 1, ans.second + 1); fflush(stdout);
}

int main() {
	run();
	return 0;
}