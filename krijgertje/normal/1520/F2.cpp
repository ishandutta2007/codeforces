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

int n, nq;

int query(int l, int r) {
	printf("? %d %d\n", l + 1, r + 1); fflush(stdout);
	int ret; scanf("%d", &ret); return r - l + 1 - ret;
}

void solve() {
	int k = 1;
	while (k < n) k *= 2;
	vector<int> cnt(2 * k, -1);
	REP(i, nq) {
		int want;
		scanf("%d", &want);
		if (want == -1) exit(0);
		--want;
		int x = 1, l = 0, r = k;
		while (r - l > 1) {
			int m = l + (r - l) / 2;
			if (cnt[2 * x] == -1) cnt[2 * x] = query(l, min(n - 1, m - 1));
			if (want < cnt[2 * x]) x = 2 * x, r = m; else want -= cnt[2 * x], x = 2 * x + 1, l = m;
		}
		printf("! %d\n", l + 1); fflush(stdout);
		while (x >= 1) --cnt[x], x /= 2;
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	solve();
}

int main() {
	run();
	return 0;
}