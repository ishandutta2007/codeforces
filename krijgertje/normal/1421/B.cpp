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
vector<string> g;
vector<pair<int, int>> ans;

void solve() {
	ans.clear();
	REP(a, 2) {
		int b = 1 - a; char x = '0' + a, y = '0' + b;
		vector<pair<int, int>> cur;
		if (g[0][1] != x) cur.PB(MP(0, 1));
		if (g[1][0] != x) cur.PB(MP(1, 0));
		if (g[n - 1][n - 2] != y) cur.PB(MP(n - 1, n - 2));
		if (g[n - 2][n - 1] != y) cur.PB(MP(n - 2, n - 1));
		if (SZ(cur) <= 2) { ans = cur; return; }
	}
	assert(false);
}

void run() {
	scanf("%d", &n);
	g = vector<string>(n); REP(x, n) cin >> g[x];
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}