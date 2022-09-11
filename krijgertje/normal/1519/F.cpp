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

const int MAXCHEST = 6;
const int MAXCHESTGAIN = 4;
const int MAXKEY = 6;

int nchest, nkey;
int chestgain[MAXCHEST];
int keycost[MAXKEY];
int lockprice[MAXCHEST][MAXKEY];

int nstate;
vector<vector<int>> states;
map<vector<int>, int> statemp;
vector<vector<int>> trans;

vector<int> dp[MAXCHEST][MAXCHESTGAIN + 1][MAXKEY + 1]; // dp[c][rem][k][keystate]

int solve() {
	nstate = 0;
	states.clear();
	statemp.clear();
	trans.clear();
	auto getstateid = [&](const vector<int>& state) { if (statemp.count(state)) return statemp[state]; int ret = nstate++; states.PB(state); statemp[state] = ret; trans.PB(vector<int>(nkey, -1)); return ret; };
	vector<int> startstate(nkey);
	REP(i, nkey) startstate[i] = keycost[i];
	int startid = getstateid(startstate);
	REP(i, nstate) REP(j, nkey) if (states[i][j] > 0) { vector<int> to = states[i]; --to[j]; trans[i][j] = getstateid(to); }
	//printf("nstate=%d\n", nstate);
	//REP(i, nstate) { printf("state%d:", i); REP(j, nkey) printf(" %d", trans[i][j]); puts(""); }

	REP(c, nchest) REPE(rem, chestgain[c]) REPE(k, nkey) dp[c][rem][k] = vector<int>(nstate, INT_MAX);
	auto relax = [&](int& v, int by) { v = min(v, by); };
	relax(dp[0][chestgain[0]][0][startid], 0);
	int ret = INT_MAX;
	REP(c, nchest) for (int rem = chestgain[c]; rem >= 0; --rem) REPE(k, nkey) REP(state, nstate) {
		int cur = dp[c][rem][k][state];
		if (cur == INT_MAX) continue;
		//printf("dp[%d][%d][%d][%d]=%d\n", c, rem, k, state, cur);
		if (rem == 0 && c + 1 < nchest) relax(dp[c + 1][chestgain[c + 1]][0][state], cur);
		if (k < nkey) relax(dp[c][rem][k + 1][state], cur);
		int tostate = state;
		if (k < nkey) FORE(use, 1, min(rem, keycost[k])) {
			tostate = trans[tostate][k];
			if (tostate == -1) break;
			relax(dp[c][rem - use][k + 1][tostate], cur + lockprice[c][k]);
		}
		if (c == nchest - 1 && rem == 0) relax(ret, cur);
	}
	return ret == INT_MAX ? -1 : ret;
}

void run() {
	scanf("%d%d", &nchest, &nkey);
	REP(i, nchest) scanf("%d", &chestgain[i]);
	REP(i, nkey) scanf("%d", &keycost[i]);
	REP(i, nchest) REP(j, nkey) scanf("%d", &lockprice[i][j]);
	printf("%d\n", solve());
}

int main() {
	//int ncase; scanf("%d", &ncase); FORE(i, 1, ncase)
	run();
	return 0;
}