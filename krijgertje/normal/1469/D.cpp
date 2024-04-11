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

int n;
vector<pair<int, int>> ans;

void solve() {
	vector<int> mx;
	vector<int> use;
	mx.PB(n);
	while (mx.back() > 2) {
		int cur = mx.back();
		int dv = max(2, (int)sqrt(1.0 * cur));
		int nxt = (cur + dv - 1) / dv;
		assert(nxt >= dv);
		mx.PB(nxt);
		use.PB(dv);
	}
	//printf("mx:"); REPSZ(i, mx) printf(" %d", mx[i]); puts("");

	ans.clear();
	int at = n - 1;
	REPSZ(i, mx) {
		while (at > use[i]) ans.PB(MP(at, n)), --at;
		ans.PB(MP(n, at));
	}
}

void run() {
	scanf("%d", &n);
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%d %d\n", ans[i].first, ans[i].second);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}