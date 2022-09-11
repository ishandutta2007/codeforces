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
#include <array>
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

const int MAXSAFE = 10000;
const int MAXGREEN = 1000;
const int MAXRED = 1000;

int len, nsafe;
int x[MAXSAFE];
int tgreen, tred;

int dp[MAXSAFE][MAXGREEN + 1];

queue<array<int, 3>> q[MAXGREEN + MAXRED];

void upd(int i, int j, int v) {
	//printf("upd(%d,%d,%d)\n", i, j, v);
	if (v >= dp[i][j]) return;
	dp[i][j] = v;
	int qidx = v % (tgreen + tred);
	q[qidx].push({ i,j,v });
}

int solve() {
	REP(i, nsafe) REPE(j, tgreen) dp[i][j] = INT_MAX;
	REP(j, tgreen + tred) q[j] = queue<array<int, 3>>();
	upd(0, tgreen, 0);

	while (true) {
		bool any = false;
		REP(qidx, tgreen + tred) {
			while (!q[qidx].empty()) {
				array<int, 3> cur = q[qidx].front(); q[qidx].pop(); 
				int i = cur[0], j = cur[1], v = cur[2]; if (dp[i][j] != v) continue;
				any = true;
				if (i + 1 < nsafe && x[i + 1] - x[i] <= j) {
					upd(i + 1, j - (x[i + 1] - x[i]), dp[i][j] + (x[i + 1] - x[i]));
				}
				if (i - 1 >= 0 && x[i] - x[i - 1] <= j) {
					upd(i - 1, j - (x[i] - x[i - 1]), dp[i][j] + (x[i] - x[i - 1]));
				}
				if (j == 0) upd(i, tgreen, dp[i][j] + tred);
			}
		}
		if (!any) break;
	}
	int ret = INT_MAX; REPE(j, tgreen) ret = min(ret, dp[nsafe - 1][j]); return ret == INT_MAX ? -1 : ret;
}

void run() {
	scanf("%d%d", &len, &nsafe);
	REP(i, nsafe) scanf("%d", &x[i]); sort(x, x + nsafe); assert(x[0] == 0 && x[nsafe - 1] == len);
	scanf("%d%d", &tgreen, &tred);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}