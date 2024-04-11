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

const int MAXSZ = 500;
const int MAXCELEB = 100000;

int sz, nceleb;
int t[MAXCELEB], x[MAXCELEB], y[MAXCELEB];

int dp[MAXCELEB];
int mxdp[MAXCELEB];

int dist(int a, int b, int c, int d) {
	return abs(a - c) + abs(b - d);
}

int solve() {
	REP(i, nceleb) {
		dp[i] = INT_MIN;
		if (dist(x[i], y[i], 0, 0) <= t[i]) dp[i] = 1;
		for (int j = i - 1; j >= 0; --j) {
			int dt = t[i] - t[j];
			if (dist(x[i], y[i], 0, 0) <= dt && dist(x[i], y[i], 0, sz - 1) <= dt && dist(x[i], y[i], sz - 1, 0) <= dt && dist(x[i], y[i], sz - 1, sz - 1) <= dt) {
				if (mxdp[j] != INT_MIN) dp[i] = max(dp[i], mxdp[j] + 1);
				break;
			}
			if (dist(x[i], y[i], x[j], y[j]) <= dt && dp[j] != INT_MIN) dp[i] = max(dp[i], dp[j] + 1);
		}
		mxdp[i] = dp[i];
		if (i - 1 >= 0) mxdp[i] = max(mxdp[i], mxdp[i - 1]);
	}
	int ret = 0; REP(i, nceleb) ret = max(ret, dp[i]); return ret;
}

void run() {
	scanf("%d%d", &sz, &nceleb);
	REP(i, nceleb) scanf("%d%d%d", &t[i], &x[i], &y[i]), --x[i], --y[i];
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}