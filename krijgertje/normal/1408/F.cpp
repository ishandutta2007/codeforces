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

int n;
vector<pair<int, int>> ans;

void solve() {
	ans.clear();
	auto merge = [&](const vector<int>& a, const vector<int>& b) {	
		vector<int> c;
		REPSZ(i, a) ans.PB(MP(a[i], b[i])), c.PB(a[i]), c.PB(b[i]);
		return c;
	};
	vector<vector<int>> groups;
	REP(i, n) {
		vector<int> cur(1, i);
		groups.PB(cur);
		while(true) {
			int ng = SZ(groups);
			if (ng >= 2 && SZ(groups[ng - 2]) == SZ(groups[ng - 1])) {
				vector<int> a = groups.back(); groups.pop_back();
				vector<int> b = groups.back(); groups.pop_back();
				groups.PB(merge(a, b));
			} else {
				break;
			}
		}
	}
	assert(SZ(groups) >= 1);
	vector<int> biggroup = groups[0];
	groups.erase(groups.begin());
	while (true) {
		int ng = SZ(groups);
		if (ng <= 1) break;
		if (SZ(groups[ng - 2]) == SZ(groups[ng - 1])) {
			vector<int> a = groups.back(); groups.pop_back();
			vector<int> b = groups.back(); groups.pop_back();
			groups.PB(merge(a, b));
		} else {
			vector<int> a = groups.back(); groups.pop_back();
			assert(SZ(biggroup) >= SZ(a));
			vector<int> b; REPSZ(i, a) { int x = biggroup.back(); biggroup.pop_back(); b.PB(x); }
			groups.PB(merge(a, b));
		}
	}

}

void run() {
	scanf("%d", &n);
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}

int main() {
	run();
	return 0;
}