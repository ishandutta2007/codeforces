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

const int N = 4;
const int MAXCNT = 150000;

int cnt[N];
int cost[N][MAXCNT];
vector<int> forbid[N][MAXCNT];

int dp[N][MAXCNT];

int solve() {
	REP(i, cnt[0]) dp[0][i] = cost[0][i];
	FOR(i, 1, N) {
		vector<pair<int, int>> ord(cnt[i - 1]);
		REP(j, cnt[i - 1]) ord[j] = MP(dp[i - 1][j], j);
		sort(ord.begin(), ord.end());
		vector<int> pos(cnt[i - 1]);
		REP(j, cnt[i - 1]) pos[ord[j].second] = j;
		REP(j, cnt[i]) {
			vector<int> lst = forbid[i][j];
			REPSZ(k, lst) lst[k] = pos[lst[k]];
			sort(lst.begin(), lst.end());
			int at = 0;
			while (at < SZ(lst) && lst[at] == at) ++at;
			if (at < cnt[i - 1] && ord[at].first != INT_MAX) dp[i][j] = ord[at].first + cost[i][j]; else dp[i][j] = INT_MAX;
			//printf("(%d,%d): %d -> %d\n", i, j, at < cnt[i - 1] && ord[at].first != INT_MAX ? ord[at].second : -1, dp[i][j]);
			//printf("\t"); REPSZ(k, lst) printf(" %d", lst[k]); puts("");
		}
	}
	int ret = INT_MAX; REP(j, cnt[N - 1]) ret = min(ret, dp[N - 1][j]); return ret == INT_MAX ? -1 : ret;
}

void run() {
	REP(i, N) scanf("%d", &cnt[i]);
	REP(i, N) REP(j, cnt[i]) scanf("%d", &cost[i][j]);
	FOR(i, 1, N) { int m; scanf("%d", &m); REP(j, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; forbid[i][b].PB(a); } }
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}