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

const int MAXN = 40000;
const int MOD = 1000000007;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

int dp[MAXN + 1];

void precalc() {
	int cnt = 0;
	dp[0] = 1; FORE(i, 1, MAXN) dp[i] = 0;
	FORE(len, 1, 5) {
		int alen = (len + 1) / 2, blen = len - alen;
		int lo = 1, hi = 9, mlt = 1; REP(i, alen - 1) lo = 10 * lo, hi = 10 * hi + 9; REP(i, blen) mlt *= 10;	
		FORE(a, lo, hi) {
			int mymlt = mlt;
			int cur = a * mymlt;
			int x = a;
			if (len % 2 == 1) x /= 10;
			REP(i, blen) mymlt /= 10, cur += (x % 10) * mymlt, x /= 10;
			if (cur > MAXN) break;
			//printf("cur=%d alen=%d blen=%d lo=%d hi=%d\n", cur, alen, blen, lo, hi);
			FORE(i, cur, MAXN) inc(dp[i], dp[i - cur]);
			++cnt;
		}
	}
	//printf("cnt=%d\n", cnt);
}

int n;

void run() {
	scanf("%d", &n);
	printf("%d\n", dp[n]);
}

int main() {
	precalc();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}