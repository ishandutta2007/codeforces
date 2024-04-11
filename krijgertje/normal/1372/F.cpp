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
int ans[MAXN];

pair<int, int> query(int l, int r) {
	printf("? %d %d\n", l + 1, r + 1); fflush(stdout);
	int val; scanf("%d", &val); if (val == -1) exit(0); int cnt; scanf("%d", &cnt); if (cnt == -1) exit(0); return MP(val, cnt);
}

int rec(int start, int end, int search, int cnt) {
	while (start < end) {
		int lim = min(start + cnt, end);
		pair<int, int> res = query(start, lim - 1);
		if (res.first != search) {
			start = rec(start, end, res.first, res.second);
		} else {
			int fst = lim - res.second;
			REP(i, cnt) ans[fst + i] = search;
			rec(start, lim - res.second, -1, n);
			return fst + cnt;
		}
	}
	return start;
}

void solve() {
	rec(0, n, -1, n);
}

void run() {
	scanf("%d", &n);
	solve();
	printf("!"); REP(i, n) printf(" %d", ans[i]); puts(""); fflush(stdout);
}

int main() {
	run();
	return 0;
}