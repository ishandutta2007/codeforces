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

vector<int> query(int l, int r) {
	printf("? %d %d\n", l, r); fflush(stdout);
	vector<int> ret(r - l + 1); REPSZ(i, ret) { scanf("%d", &ret[i]); if (ret[i] == -1) exit(0); } return ret;
}

int solve() {
	int lo = 1, hi = n;
	while (lo < hi) {
		int mi = lo + (hi - lo) / 2;
		vector<int> lst = query(lo, mi);
		int cnt = 0; for (int x : lst) if (x >= lo && x <= mi) ++cnt;
		if (cnt % 2 == 1) hi = mi; else lo = mi + 1;
	}
	return lo;
}

void run() {
	scanf("%d", &n);
	if (n == -1) exit(0);
	int ans = solve();
	printf("! %d\n", ans); fflush(stdout);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}