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

const int MAXN = 5000;

int alen, blen;
char a[MAXN + 1];
char b[MAXN + 1];

int dp[MAXN+1][MAXN+1];

int solve() {
	int ret = 0;
	for (int i = alen ; i >= 0; --i) for (int j = blen; j >= 0; --j) {
		dp[i][j] = 0;
		if (i == alen || j == blen) continue;
		if (a[i] == b[j]) {
			dp[i][j] = max(dp[i][j], 2 + dp[i + 1][j + 1]);
		} else {
			dp[i][j] = max(dp[i][j], max(dp[i + 1][j], dp[i][j + 1]) - 1);
		}
		ret = max(ret, dp[i][j]);
	}
	return ret;
}

void run() {
	scanf("%d%d", &alen, &blen);
	scanf("%s", a); assert(strlen(a) == alen);
	scanf("%s", b); assert(strlen(b) == blen);
	printf("%d\n", solve());
}

int main() {
	//int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) 
	run();
	return 0;
}