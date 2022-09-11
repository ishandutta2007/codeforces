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

const int MAXN = 200000;
const int MOD = 998244353;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

char s[MAXN + 1]; int n;

int dp[8][8];
int ndp[8][8];

int solve() {
	//n = MAXN; REP(i, n) s[i] = '0' + rnd() % 2; s[n] = '\0';
	memset(dp, 0, sizeof(dp));
	inc(dp[0][7], 1);
	REP(i, n) {
		memset(ndp, 0, sizeof(ndp));
		int dig = s[i] - '0';
		REP(biggermask, 8) REP(samemask, 8) {
			int cur = dp[biggermask][samemask];
			if (cur == 0) continue;
			REP(curmask, 8) {
				if (dig == 0 && (samemask & curmask) != 0) continue;
				int a = curmask & 1, b = (curmask >> 1) & 1, c = (curmask >> 2) & 1, x = a ^ b, y = b ^ c, z = c ^ a;
				int nbiggermask = biggermask | (x == 0 && y == 1 && z == 1 ? 1 : 0) | (y == 0 && z == 1 && x == 1 ? 2 : 0) | (z == 0 && x == 1 && y == 1 ? 4 : 0);
				int nsamemask = dig == 0 ? samemask : samemask & curmask;
				inc(ndp[nbiggermask][nsamemask], cur);
			}
		}
		REP(biggermask, 8) REP(samemask, 8) dp[biggermask][samemask] = ndp[biggermask][samemask];
	}
	int ret = 0;
	REP(samemask, 8) inc(ret, dp[7][samemask]);
	return ret;
}

void run() {
	scanf("%s", s); n = strlen(s);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}