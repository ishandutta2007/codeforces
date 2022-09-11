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
int a[MAXN];
vector<int> ans;

void solve() {
	ans.clear();
	set<int> have;
	REP(i, n) have.insert(i);
	set<int> opt;
	REP(i, n) { int j = (i + 1) % n; if (gcd(a[i], a[j]) == 1) opt.insert(i); }
	int at = 0;
	while (SZ(have) >= 2 && SZ(opt) >= 1) {
		auto it = opt.lower_bound(at);
		if (it == opt.end()) it = opt.begin();

		int x = *it;
		auto itx = have.find(x); assert(itx != have.end());
		auto ity = next(itx) == have.end() ? have.begin() : next(itx);
		int y = *ity;
		auto itz = next(ity) == have.end() ? have.begin() : next(ity);
		int z = *itz;
		//printf("x=%d y=%d z=%d\n", x, y, z);
		assert(gcd(a[x], a[y]) == 1);

		ans.PB(y);
		have.erase(y);
		if (gcd(a[y], a[z]) == 1) opt.erase(y);
		if (gcd(a[x], a[z]) != 1) opt.erase(x);
		at = z;
	}
	if (SZ(have) == 1) {
		int x = *have.begin();
		if (a[x] == 1) ans.PB(x);
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	printf("%d", SZ(ans)); REPSZ(i, ans) printf(" %d", ans[i] + 1); puts("");

}


int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}