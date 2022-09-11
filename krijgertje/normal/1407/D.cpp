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

const int MAXN = 300000;

int n;
int a[MAXN];

int dp[MAXN];
pair<int, int> lower[MAXN]; int nlower;
pair<int, int> upper[MAXN]; int nupper;


int solve() {
	nlower = nupper = 0;
	dp[0] = 0; lower[nlower++] = MP(a[0], 0); upper[nupper++] = MP(a[0], 0);
	FOR(i, 1, n) {
		dp[i] = INT_MAX;
		while (nlower > 0 && lower[nlower - 1].first > a[i]) {
			dp[i] = min(dp[i], lower[nlower - 1].second + 1);
			--nlower;
		}
		if (nlower > 0) {
			dp[i] = min(dp[i], lower[nlower - 1].second + 1);
			if (lower[nlower - 1].first == a[i]) --nlower;
		}
		while (nupper > 0 && upper[nupper - 1].first < a[i]) {
			dp[i] = min(dp[i], upper[nupper - 1].second + 1);
			--nupper;
		}
		if (nupper > 0) {
			dp[i] = min(dp[i], upper[nupper - 1].second + 1);
			if (upper[nupper - 1].first == a[i]) --nupper;
		}
		lower[nlower++] = MP(a[i], dp[i]);
		upper[nupper++] = MP(a[i], dp[i]);
	}
	return dp[n - 1];
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}