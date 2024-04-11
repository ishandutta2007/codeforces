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
const int MAXQ = 500000;
const int MOD = 998244353;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int& a, int b) { if ((a -= b) < 0) a += MOD; }

int n, nbit, nq;
int ql[MAXQ], qr[MAXQ], qval[MAXQ];


int must[MAXN + 1];
int last[MAXN + 1];
int dp[MAXN + 1];

int solve() {
	int ret = 1;
	REP(bit, nbit) {
		REPE(i, n) must[i] = 0, last[i] = -1;
		REP(i, nq) {
			int l = ql[i], r = qr[i];
			if (qval[i] & (1 << bit)) {
				++must[l], --must[r + 1];
			} else {
				last[r + 1] = max(last[r + 1], l);
			}
		}
		REP(i, n) must[i + 1] += must[i];
		REP(i, n) last[i + 1] = max(last[i + 1], last[i]);
		int sum = 1;
		int l = -1;
		REPE(i, n) {
			if (must[i] != 0) { 
				dp[i] = 0; 
			} else {
				// dp[i] = dp[last[i]] + ... + dp[i-1]
				while (l < last[i]) dec(sum, l == -1 ? 1 : dp[l]), ++l;
				dp[i] = sum;
			}
			inc(sum, dp[i]);
		}
		//printf("bit%d\n", bit);
		//printf("must:"); REPE(i, n) printf(" %d", must[i]); puts("");
		//printf("last:"); REPE(i, n) printf(" %d", last[i]); puts("");
		//printf("dp:"); REPE(i, n) printf(" %d", dp[i]); puts("");
		int cur = dp[n];
		ret = (ll)ret * cur % MOD;
	}
	return ret;
}

void run() {
	scanf("%d%d%d", &n, &nbit, &nq);
	REP(i, nq) scanf("%d%d%d", &ql[i], &qr[i], &qval[i]), --ql[i], --qr[i];
	printf("%d\n", solve());
}


int main() {
	run();
	return 0;
}