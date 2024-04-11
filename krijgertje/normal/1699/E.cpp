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

const int MAXN = 1000000;
const int MAXVAL = 5000000;

int n, mxval;
int a[MAXN];


int dp[MAXVAL + 1];
bool have[MAXVAL + 1];
int cnt[MAXVAL + 1];

int solve() {
	int mnval = a[0]; FOR(i, 1, n) mnval = min(mnval, a[i]);
	int mxval = a[0]; FOR(i, 1, n) mxval = max(mxval, a[i]);
	REPE(i, mxval) have[i] = false, cnt[i] = 0;
	REP(i, n) have[a[i]] = true;

	int ret = INT_MAX;
	int at = mxval;
	for (int i = mxval; i >= 1; --i) {
		dp[i] = i;
		if (have[i]) ++cnt[dp[i]];
		for (int j = i + i, k = 2; j <= mxval; j += i, ++k) {
			if (k >= i && dp[k] < dp[j]) {
				//printf("%d: dp[%d]=%d\n", i, j, dp[k]);
				if (have[j]) {
					--cnt[dp[j]];
					++cnt[dp[k]];
				}
				dp[j] = dp[k];
			}
		}
		//printf("%d:", i); FORE(j, 1, at) printf(" %d", cnt[j]); puts("");
		while (cnt[at] == 0) --at;
		if (i <= mnval) ret = min(ret, at - i);
	}
	//printf("mnval=%d\n", mnval);
	return ret;
}

void run() {
	scanf("%d%d", &n, &mxval);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}


int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}