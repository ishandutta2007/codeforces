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

const int MAXN = 1000000;

int h, w, n;
string g[MAXN];

int dp[MAXN][1 << 3]; // dp[i][mask] = min cost to modify columns [0..i] such that last column has value mask and all 2*2 squares formed sofar are valid

int solve() {
	if (h >= 4 && w >= 4) return -1;
	if (h >= 4) {
		vector<string> ng(w,string(h,'?'));
		REP(x, h) REP(y, w) ng[y][x] = g[x][y];
		swap(h, w);
		REP(x, h) g[x] = ng[x];
	}
	REP(mask, 1 << h) {
		int cost = 0; REP(x, h) { int have = g[x][0] - '0', want = (mask >> x) & 1; if (have != want) ++cost; }
		dp[0][mask] = cost;
	}
	FOR(y, 1, w) {
		REP(mask, 1 << h) {
			dp[y][mask] = INT_MAX;
			REP(pmask, 1 << h) {
				if (dp[y - 1][pmask] == INT_MAX) continue;
				int cost = 0; REP(x, h) { int have = g[x][y] - '0', want = (mask >> x) & 1; if (have != want) ++cost; }
				bool ok = true;
				REP(x, h - 1) {
					int a = (pmask >> x) & 1, b = (pmask >> (x + 1)) & 1, c = (mask >> x) & 1, d = (mask >> (x + 1)) & 1, sum = a + b + c + d;
					if (sum % 2 == 0) ok = false;
				}
				if (!ok) continue;
				dp[y][mask] = min(dp[y][mask], dp[y - 1][pmask] + cost);
			}
		}
	}
	int ret = INT_MAX; REP(mask, 1 << h) ret = min(ret, dp[w - 1][mask]); return ret;
}

void run() {
	scanf("%d%d", &h, &w); n = h * w;
	REP(x, h) cin >> g[x];
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}