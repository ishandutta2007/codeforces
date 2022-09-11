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

const int MAXLEN = 3000;
const int MOD = 998244353;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

char s[MAXLEN + 1]; int slen;
char t[MAXLEN + 1]; int tlen;

int dp[MAXLEN][MAXLEN];

bool ok(char c, int pos) {
	return pos >= tlen || t[pos] == c;
}

int solve() {
	REP(i, slen) REP(j, slen) dp[i][j] = 0;
	REP(i, slen) if (ok(s[0], i)) dp[i][i] = 2;
	FORE(len, 1, slen - 1) REPE(i, slen - len) {
		int j = i + len - 1; if (dp[i][j] == 0) continue;
		char c = s[len];
		if (i - 1 >= 0 && ok(c, i - 1)) inc(dp[i - 1][j], dp[i][j]);
		if (j + 1 < slen && ok(c, j + 1)) inc(dp[i][j + 1], dp[i][j]);
	}
	int ret = 0; FOR(j, tlen - 1, slen) inc(ret, dp[0][j]); return ret;
}

void run() {
	scanf("%s", s); slen = strlen(s);
	scanf("%s", t); tlen = strlen(t);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}