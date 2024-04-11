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

const int MAXLEN = 1000;
const int MOD = 998244353;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

char x[MAXLEN + 1]; int xlen;
char y[MAXLEN + 1]; int ylen;

int dp[MAXLEN + 1][MAXLEN + 1][2];
bool done[MAXLEN + 1][MAXLEN + 1][2];

int solve() {
	REPE(i, xlen) REPE(j, ylen) REP(k, 2) dp[i][j][k] = 0;
	REPE(i, xlen) REPE(j, ylen) REP(k, 2) done[i][j][k] = false;
	REP(i, xlen) REP(j, ylen) REP(k, 2) inc(dp[i][j][k], 1);

	REPE(_i, xlen) REPE(_j, ylen) REP(k, 2) {
		int i = _i == xlen ? xlen : xlen - _i - 1, j = _j == ylen ? ylen : ylen - _j - 1;
		if (k == 0 && i == xlen || k == 1 && j == ylen) continue;
		char last = k == 0 ? x[i] : y[j];
		if (i != xlen && i + 1 < xlen && x[i + 1] != last) inc(dp[i][j][k], dp[i + 1][j][0]), assert(done[i + 1][j][0]);
		if (j != ylen && j + 1 < ylen && y[j + 1] != last) inc(dp[i][j][k], dp[i][j + 1][1]), assert(done[i][j + 1][1]);
		if (i == xlen) REP(ii, xlen) if (x[ii] != last) inc(dp[i][j][k], dp[ii][j][0]), assert(done[ii][j][0]);
		if (j == ylen) REP(jj, ylen) if (y[jj] != last) inc(dp[i][j][k], dp[i][jj][1]), assert(done[i][jj][1]);
		done[i][j][k] = true;
		//printf("dp[%d][%d][%d]=%d\n", i, j, k, dp[i][j][k]);
	}

	int ret = 0;
	REP(i, xlen) inc(ret, dp[i][ylen][0]);
	REP(j, ylen) inc(ret, dp[xlen][j][1]);
	return ret;
}

int solvestupid() {
	int ret = 0;
	REP(lx, xlen) FOR(rx, lx, xlen) REP(ly, ylen) FOR(ry, ly, ylen) {
		int xcnt = (rx - lx + 1), ycnt = (ry - ly + 1);
		REP(mask, 1 << (xcnt + ycnt)) {
			char last = '?';
			int ones = 0; REP(i, xcnt + ycnt) if (mask & (1 << i)) ++ones; if (ones != ycnt) continue;
			int atx = lx, aty = ly; bool ok = true;
			REP(i, xcnt + ycnt) {
				if (mask & (1 << i)) { char c = y[aty++]; if (c == last) ok = false; last = c; }
				else { char c = x[atx++]; if (c == last) ok = false; last = c; }
			}
			if (ok) ++ret;
		}
	}
	return ret;
}

void run() {
	scanf("%s", x); xlen = strlen(x);
	scanf("%s", y); ylen = strlen(y);
	printf("%d\n", solve());
	//printf("%d\n", solvestupid());
}


int main() {
	run();
	return 0;
}