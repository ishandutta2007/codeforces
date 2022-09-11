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
typedef long long ll;  
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXLEN = 400;

char s[MAXLEN + 1]; int slen;
char t[MAXLEN + 1]; int tlen;

int dp[2][MAXLEN + 1][MAXLEN + 1]; // dp[i][j][k] = from s[i..slen), how far can be advance j, assuming k advances to the end of t

void upd(int& a, int b) { a = max(a, b); }
bool solve() {
	int at = 0;
	REPE(j, tlen) FORE(k, j, tlen) dp[at][j][k] = k == tlen ? j : -1;
	for (int i = slen - 1; i >= 0; --i) {
		at = 1 - at;
		REPE(j, tlen) FORE(k, j, tlen) {
			dp[at][j][k] = dp[1 - at][j][k];
			if (j + 1 <= k && s[i] == t[j]) upd(dp[at][j][k], dp[1 - at][j + 1][k]);
			if (k < tlen && s[i] == t[k]) upd(dp[at][j][k], dp[1 - at][j][k + 1]);
			//if (dp[at][j][k] != -1) printf("(%d,%d,%d) = %d\n", i, j, k, dp[at][j][k]);
		}
	}
	REPE(k, tlen) if (dp[at][0][k] >= k) return true;
	return false;
}

void run() {
	scanf("%s", s); slen = strlen(s);
	scanf("%s", t); tlen = strlen(t);
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}