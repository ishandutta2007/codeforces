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

const int MAXH = 50;
const int MAXW = 20000;

int h, w, sz;
int g[MAXH + 1][MAXW];

int pref[MAXH + 1][MAXW + 1];
int dp[MAXH][MAXW];

pair<int, int> q[MAXW]; int qtail, qhead;

int solve() {
	REP(y, w) g[h][y] = 0;
	REPE(x, h) { pref[x][0] = 0; REP(y, w) pref[x][y + 1] = pref[x][y] + g[x][y]; }

	REPE(y, w - sz) dp[0][y] = pref[0][y + sz] - pref[0][y] + pref[1][y + sz] - pref[1][y];
	FOR(x, 1, h) {
		REPE(y, w - sz) dp[x][y] = 0;
		{ // py>=y+sz -> dp[px][py]+pref[x][y+sz]-pref[x][y]
			int mx = 0;
			for (int y = w - sz; y >= 0; --y) {
				if (y + sz <= w - sz) mx = max(mx, dp[x - 1][y + sz]);
				dp[x][y] = max(dp[x][y], mx + pref[x][y + sz] - pref[x][y]);
			}
		}
		{ // py<=y-sz -> dp[px][py]+pref[x][y+sz]-pref[x][y]
			int mx = 0;
			REPE(y, w - sz) {
				if (y - sz >= 0) mx = max(mx, dp[x - 1][y - sz]);
				dp[x][y] = max(dp[x][y], mx + pref[x][y + sz] - pref[x][y]);
			}
		}
		{ // y<=py<=y+sz -> dp[px][py]+pref[x][py]-pref[x][y]
			int py = 0; qhead = qtail = 0;
			REPE(y, w - sz) {
				while (py <= w - sz && py <= y + sz) { pair<int, int> cur = MP(py, dp[x - 1][py] + pref[x][py]); ++py; while (qtail < qhead && q[qhead - 1].second <= cur.second) --qhead; q[qhead++] = cur; }
				while (qtail < qhead && q[qtail].first < y) ++qtail;
				if (qtail < qhead) dp[x][y] = max(dp[x][y], q[qtail].second - pref[x][y]);
			}
		}
		{ // y-sz<=py<=y -> dp[px][py]+pref[x][y+sz]-pref[x][py+sz]
			int py = 0; qhead = qtail = 0;
			REPE(y, w - sz) {
				while (py <= w - sz && py <= y) { pair<int, int> cur = MP(py, dp[x - 1][py] - pref[x][py + sz]); ++py; while (qtail < qhead && q[qhead - 1].second <= cur.second) --qhead; q[qhead++] = cur; }
				while (qtail < qhead && q[qtail].first < y - sz) ++qtail;
				if (qtail < qhead) dp[x][y] = max(dp[x][y], q[qtail].second + pref[x][y + sz]);
			}
		}
		REPE(y, w - sz) dp[x][y] += pref[x + 1][y + sz] - pref[x + 1][y];
	}
	//REP(x, h) { printf("dp%d:", x); REPE(y, w - sz) printf(" %d", dp[x][y]); puts(""); }

	int ret = 0; REPE(y, w - sz) ret = max(ret, dp[h - 1][y]); return ret;
}

void run() {
	scanf("%d%d%d", &h, &w, &sz);
	REP(x, h) REP(y, w) scanf("%d", &g[x][y]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}