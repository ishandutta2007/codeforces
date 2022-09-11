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

const int MAXN = 500000;

int n;
int a[MAXN];

vector<int> pos[MAXN];
int dp[MAXN + 1];
int ptr[MAXN];

int solve() {
	REP(i, n) ptr[i] = 0, pos[i].clear();
	REP(i, n) pos[a[i]].PB(i);
	dp[0] = 0;
	int mxkeep = 0;
	REP(i, n) {
		dp[i+1] = dp[i];
		int val = a[i];
		if (i == pos[val].back()) dp[i + 1] = max(dp[i + 1], dp[pos[val][0]] + SZ(pos[val]));
		assert(pos[val][ptr[val]] == i);
		mxkeep = max(mxkeep, dp[i] + (SZ(pos[val]) - ptr[val]));
		++ptr[val];
	}
	mxkeep = max(mxkeep, dp[n]);
	return n - mxkeep;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}