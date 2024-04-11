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
const int MOD = 1000000007;

int n;
char s[MAXN + 1];

int prefcnt[MAXN + 1][4];
int p3[MAXN + 1];

int solve() {
	int nq = 0; REP(i, n) if (s[i] == '?') ++nq;
	p3[0] = 1; FORE(i, 1, n) p3[i] = (ll)p3[i - 1] * 3 % MOD;
	REP(j, 4) prefcnt[0][j] = 0;
	REP(i, n) REP(j, 4) prefcnt[i + 1][j] = prefcnt[i][j] + (s[i] == (j != 3 ? 'a' + j : '?') ? 1 : 0);
	int ret = 0;
	REP(mask, 1 << 3) REP(i, n) {
		int a = (mask & 1) ? 0 : 3, b = (mask & 2) ? 1 : 3, c = (mask & 4) ? 2 : 3;
		if (s[i] != (b != 3 ? 'a' + b : '?')) continue;
		int aways = prefcnt[i][a];
		int cways = prefcnt[n][c] - prefcnt[i + 1][c];
		int remq = nq - (a == 3 ? 1 : 0) - (b == 3 ? 1 : 0) - (c == 3 ? 1 : 0);
		ret = (ret + (ll)aways * cways % MOD * p3[remq]) % MOD;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	scanf("%s", s); assert(strlen(s) == n);
	printf("%d\n", solve());
}


int main() {
	run();
	return 0;
}