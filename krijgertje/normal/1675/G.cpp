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
#include <functional>
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

const int MAXN = 250;
const int MAXSUM = 250;

int n, sum;
int a[MAXN];

int solve() {
	vector<vector<int>> dp(sum + 1, vector<int>(sum + 1, INT_MAX)); // dp[cnt][last] = minimum moves so that the first stacks have cnt pancakes and last stack has at least last
	REPE(cnt, sum) dp[cnt][cnt] = abs(cnt - a[0]);
	REPE(cnt, sum) for (int last = sum - 1; last >= 0; --last) dp[cnt][last] = min(dp[cnt][last], dp[cnt][last + 1]);
	int bal = a[0];
	FOR(i, 1, n) {
		bal += a[i];
		int lim = sum / (i + 1);
		vector<vector<int>> ndp(sum + 1, vector<int>(lim + 1, INT_MAX));
		REPE(cnt, sum) REPE(last, lim) {
			int pcnt = cnt - last;
			if (pcnt < 0) continue;
			int cur = dp[pcnt][last];
			if (cur == INT_MAX) continue;
			cur += abs(cnt - bal);
			ndp[cnt][last] = cur;
		}
		swap(dp, ndp);
		REPE(cnt, sum) for (int last = lim - 1; last >= 0; --last) dp[cnt][last] = min(dp[cnt][last], dp[cnt][last + 1]);
	}
	return dp[sum][0];
}

void run() {
	scanf("%d%d", &n, &sum);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}