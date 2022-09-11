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
typedef long long ll;  
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 100000;

int n;
int a[MAXN];


pair<int, int> solve() {
	int ret = 0;
	int mx = INT_MIN, mn = INT_MAX;
	REP(i, n - 1) {
		int x = a[i], y = a[i + 1];
		if (x == -1 && y == -1) continue;
		if (x != -1 && y != -1) { ret = max(ret, abs(x - y)); continue; }
		if (x == -1) swap(x, y);
		mx = max(mx, x); mn = min(mn, x);
	}
	if (mx == INT_MIN || mn == INT_MAX) { assert(ret == 0); return MP(0, 0); }
	int diff = mx - mn;
	int k = mn + (mx - mn) / 2;
	ret = max(ret, max(abs(mn - k), abs(mx - k)));
	return MP(ret, k);
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	pair<int, int> ans = solve();
	printf("%d %d\n", ans.first, ans.second);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}