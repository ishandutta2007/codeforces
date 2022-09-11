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

struct P { int x, y; P(int x, int y) :x(x), y(y) {} P() {} };

int wantinternal;
vector<P> ans;

void solve() {
	ans.clear();
	REP(x, 2) REP(y, 2) ans.PB(P(x, y));
	int have = 0;
	int lastx = 1, lasty = 1;
	while (have < wantinternal) {
		ans.PB(P(lastx + 1, lasty));
		ans.PB(P(lastx, lasty + 1));
		ans.PB(P(lastx + 1, lasty + 1));
		++lastx, ++lasty, ++have;
	}
}

void run() {
	scanf("%d", &wantinternal);
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) printf("%d %d\n", ans[i].x, ans[i].y);
}

int main() {
	run();
	return 0;
}