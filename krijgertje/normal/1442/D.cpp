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

const int MAXSEQ = 3000;
const int MAXOP = 3000;

int nseq, nop;
vector<int> a[MAXSEQ];

vector<ll> sum[MAXSEQ];

ll rec(int l, int r, const vector<ll>& dp) {
	if (l == r) {
		int idx = l;
		ll ret = 0;
		REPE(i, min(SZ(a[idx]), nop)) ret = max(ret, sum[idx][i] + dp[nop - i]);
		return ret;
	} else {
		ll ret = 0;
		int m = l + (r - l) / 2;
		vector<ll> ldp = dp;
		FORE(idx, m + 1, r) { int sz = SZ(a[idx]); ll w = sum[idx][sz]; for (int i = nop; i >= sz; --i) ldp[i] = max(ldp[i], ldp[i - sz] + w); }
		ret = max(ret, rec(l, m, ldp));
		vector<ll> rdp = dp;
		FORE(idx, l, m) { int sz = SZ(a[idx]); ll w = sum[idx][sz]; for (int i = nop; i >= sz; --i) rdp[i] = max(rdp[i], rdp[i - sz] + w); }
		ret = max(ret, rec(m+1, r, rdp));
		return ret;
	}
}

ll solve() {
	REP(i, nseq) {
		int lim = SZ(a[i]);
		sum[i] = vector<ll>(lim + 1);
		sum[i][0] = 0; REP(j, lim) sum[i][j + 1] = sum[i][j] + a[i][j];
		//printf("sum%d:", i); REPSZ(j, sum[i]) printf(" %lld", sum[i][j]); puts("");
	}

	vector<ll> dp(nop + 1, 0);
	return rec(0, nseq - 1, dp);
}

void run() {
	scanf("%d%d", &nseq, &nop);
	REP(i, nseq) { int len; scanf("%d", &len); a[i] = vector<int>(len); REP(j, len) scanf("%d", &a[i][j]); }
	printf("%lld\n", solve());
}

int main() {
	//int ncase; scanf("%d", &ncase); FORE(i, 1, ncase)
	run();
	return 0;
}