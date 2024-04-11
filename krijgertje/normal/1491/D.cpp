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

ll a, b;

bool solve() {
	if (a > b) return false;
	ll x = a, y = b;
	vector<int> xdig;
	while (x != 0) xdig.PB(x & 1), x /= 2;
	vector<int> ydig;
	while (y != 0) ydig.PB(y & 1), y /= 2;
	int xsum = 0, ysum = 0;
	REPSZ(i, ydig) {
		xsum += i < SZ(xdig) ? xdig[i] : 0;
		ysum += ydig[i];
		if (ysum > xsum) return false;
	}
	return true;
}

void run() {
	scanf("%lld%lld", &a, &b);
	printf("%s\n", solve() ? "YES" : "NO");
}

void stress() {
	int n = 1000;
	FORE(s, 1, n) {
		vector<bool> reach(n + 1, false);
		queue<int> q;
		auto relax = [&](int a) { if (a > n) return; if (reach[a]) return; reach[a] = true, q.push(a); };
		relax(s);
		while (!q.empty()) {
			int at = q.front(); q.pop();
			FORE(i, 1, at) if ((at & i) == i) relax(at + i);
		}
		FORE(t, 1, n) {
			::a = s, ::b = t;
			bool have = solve();
			bool want = reach[t];
			if (have != want) printf("err: %d->%d have=%s want=%s\n", s, t, have ? "YES" : "NO", want ? "YES" : "NO");
		}
	}

}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	//stress();
	return 0;
}