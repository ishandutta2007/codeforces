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

const int MAXN = 200000;
const int TOP = 0;
const int BOTTOM = 1;
const int DISCONNECTED = 2;
const int CONNECTED = 3;

int n;
char g[2][MAXN + 1];

int solve() {
	int lo = INT_MAX, hi = INT_MIN;
	REP(x, 2) REP(y, n) if (g[x][y] == '*') lo = min(lo, y), hi = max(hi, y);
	assert(lo != INT_MAX && hi != INT_MIN);
	
	vector<int> dp(4, INT_MAX);
	auto relax = [&](int& a, int b) { a = min(a, b); };
	relax(dp[TOP], g[1][lo] == '*' ? 2 : 1);
	relax(dp[BOTTOM], g[0][lo] == '*' ? 2 : 1);
	relax(dp[DISCONNECTED], 2);
	relax(dp[CONNECTED], 3);
	//printf("%s\n%s\n", g[0], g[1]);
	FORE(y, lo + 1, hi) {
		vector<int> ndp(4, INT_MAX);
		REP(state, 4) {
			int cur = dp[state];
			if (cur == INT_MAX) continue;
			//printf("y=%d: dp[%d]=%d\n", y, state, dp[state]);
			REP(inside, 2) {
				FOR(right, 1, 4) {
					int cost = inside + (right == 3 ? 2 : 1);
					int nstate = right == 1 ? TOP : right == 2 ? BOTTOM : inside == 1 || state == CONNECTED ? CONNECTED : DISCONNECTED;
					if ((state == TOP || state == DISCONNECTED) && inside == 0 && right == 2) continue;
					if ((state == BOTTOM || state == DISCONNECTED) && inside == 0 && right == 1) continue;
					if (g[0][y] == '*' && inside == 0 && right == 2 && state == BOTTOM) continue;
					if (g[1][y] == '*' && inside == 0 && right == 1 && state == TOP) continue;
					relax(ndp[nstate], cur + cost);
				}
			}
		}
		swap(dp, ndp);
	}
	return min(dp[TOP] - 1, dp[BOTTOM] - 1);
}

void run() {
	scanf("%d", &n);
	REP(x, 2) scanf("%s", g[x]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}