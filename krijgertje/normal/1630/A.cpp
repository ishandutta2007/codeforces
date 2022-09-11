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

const int MAXN = 1 << 16;

int n, want;
vector<pair<int, int>> ans;

bool solve() {
	ans.clear();
	if (want == 0) {
	} else if (want == n - 1) {
		if (n == 4) return false;
		ans.PB(MP(n - 2, n - 1));
		ans.PB(MP(1, 3));
		ans.PB(MP(0, n - 1 - 3));
	} else {
		ans.PB(MP(want, n - 1));
		ans.PB(MP(0, n - 1 - want));
	}
	vector<bool> seen(n, false);
	auto mark = [&](int x) { assert(!seen[x]); seen[x] = true; };
	REPSZ(i, ans) mark(ans[i].first), mark(ans[i].second);
	REP(i, n) if (!seen[i]) { ans.PB(MP(i, n - i - 1)); mark(i); mark(n - i - 1); }
	return true;
}

void run() {
	scanf("%d%d", &n, &want);
	if (!solve()) { printf("-1\n"); return; }
	REPSZ(i, ans) printf("%d %d\n", ans[i].first, ans[i].second);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}