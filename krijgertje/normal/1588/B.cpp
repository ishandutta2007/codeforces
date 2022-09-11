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

int n;

ll query(int l, int r) {
	printf("? %d %d\n", l + 1, r + 1); fflush(stdout);
	ll ret; scanf("%lld", &ret); if (ret == -1) exit(0); return ret;
}

pair<pair<int, int>, pair<int, int>> solve() {
	int a, b, c, d;
	{
		int l = 0, r = n - 1;
		while (l + 1 < r) {
			int m = l + (r - l) / 2;
			if (query(0, m) == 0) l = m; else r = m;
		}
		a = l;
	}
	{
		ll diff = query(a, n - 1) - query(a + 1, n - 1);
		b = a + diff;
		c = b + 1;
	}
	{
		ll diff = query(c, n - 1) - query(c + 1, n - 1);
		d = c + diff;
	}
	return MP(MP(a, b), MP(c, d));
}

void run() {
	scanf("%d", &n);
	auto ans = solve();
	printf("! %d %d %d\n", ans.first.first + 1, ans.second.first + 1, ans.second.second + 1); fflush(stdout);

}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}