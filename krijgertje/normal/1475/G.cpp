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

const int MAXN = 200000;
const int MAXVAL = 200000;

int n;
int a[MAXN];

int cnt[MAXVAL + 1];
int dp[MAXVAL + 1];

int solve() {
	memset(cnt, 0, sizeof(cnt));
	REP(i, n) ++cnt[a[i]];
	int best = 0;
	FORE(i, 1, MAXVAL) dp[i] = cnt[i];
	FORE(i, 1, MAXVAL) {
		//if (cnt[i] != 0) printf("\t%d=%d\n", i, dp[i]);
		best = max(best, dp[i]);
		for (int j = i + i; j <= MAXVAL; j += i) dp[j] = max(dp[j], dp[i] + cnt[j]);
	}
	return n - best;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}