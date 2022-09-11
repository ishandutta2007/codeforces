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

const int MAXCAND = 2000;
const int MAXLEVEL = 2000;

int ncand, nlevel;
int level[MAXCAND];
int cost[MAXCAND];
int score[MAXCAND + MAXLEVEL];

int dp[MAXCAND][MAXCAND + 1]; // dp[i][j] = maximum value when choosing candidates out of [i..ncand) when the only relevant remaining candidates after fighting are j times a candidate of level level[i]
int dpfinish[MAXCAND];
int nxt[MAXLEVEL]; // nxt[i] = index of the next candidate with level i

void upd(int& a, int b) { a = max(a, b); }
int solve() {
	REP(i, nlevel) nxt[i] = -1;
	for (int i = ncand - 1; i >= 0; --i) {
		REPE(k, ncand) dp[i][k] = INT_MIN;
		upd(dp[i][0], 0);
		int groupsz = 1;
		for (int x = level[i]; x >= 0; --x) {
			if (ncand - i - 1 >= groupsz) {
				int j = nxt[x];
				if (j != -1) {
					REPE(k, ncand) if (dp[j][k] != INT_MIN) {
						int kk = k, cur = dp[j][k];
						FORE(y, x + 1, level[i]) kk /= 2, cur += kk * score[y];
						upd(dp[i][kk], cur);
					}
				}
			} else {
				FOR(j, i + 1, ncand) if (level[j] <= x) upd(dp[i][0], dpfinish[j]);
				break;
			}
			groupsz *= 2;
		}
		for (int k = ncand - 1; k >= 0; --k) if (dp[i][k] != INT_MIN) upd(dp[i][k + 1], dp[i][k] + score[level[i]] - cost[i]);
		dpfinish[i] = INT_MIN;
		REPE(k, ncand) if (dp[i][k] != INT_MIN) {
			int kk = k, cur = dp[i][k];
			for (int y = level[i] + 1; kk >= 2; ++y) { kk /= 2; assert(y < ncand + nlevel); cur += kk * score[y]; }
			upd(dpfinish[i], cur);
		}
		nxt[level[i]]=i;
	}
	int ret = 0; REP(i, ncand) upd(ret, dpfinish[i]); return ret;
}

void run() {
	scanf("%d%d", &ncand, &nlevel);
	REP(i, ncand) scanf("%d", &level[i]), --level[i];
	REP(i, ncand) scanf("%d", &cost[i]);
	REP(i, ncand + nlevel) scanf("%d", &score[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}