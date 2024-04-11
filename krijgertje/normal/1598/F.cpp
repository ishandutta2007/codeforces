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

const int MAXN = 20;
struct Seq { int sum, lo; vector<int> cnt; };

int n;
string s[MAXN];
Seq seq[MAXN];

int dp[1 << MAXN];

int solve() {
	REP(i, n) {
		seq[i].sum = 0;
		seq[i].lo = 0;
		vector<int> lst = { 0 };
		for (char c : s[i]) {
			if (c == '(') {
				seq[i].sum++;
			} else {
				seq[i].sum--;
				if (seq[i].sum < seq[i].lo) seq[i].lo = seq[i].sum;
			}
			lst.PB(seq[i].sum);
		}
		int hi = 0;
		for (int x : lst) hi = max(hi, x);
		seq[i].cnt = vector<int>(hi - seq[i].lo + 1, 0);
		int lo = 0;
		FORSZ(j, 1, lst) {
			lo = min(lo, lst[j]);
			if (lst[j] == lo) ++seq[i].cnt[lst[j] - seq[i].lo];
		}
	}
	REP(mask, 1 << n) dp[mask] = INT_MIN;
	dp[0] = 0;
	int ret = 0;
	REP(mask, 1 << n) if (dp[mask] != INT_MIN) {
		ret = max(ret, dp[mask]);
		int sum = 0;
		REP(i, n) if (mask & (1 << i)) sum += seq[i].sum;
		REP(i, n) if ((mask & (1 << i)) == 0) {
			if (-(sum + seq[i].lo) > 0 && -(sum + seq[i].lo) < SZ(seq[i].cnt)) {
				ret = max(ret, dp[mask] + seq[i].cnt[-(sum + seq[i].lo)]);
			}
			if (sum + seq[i].lo >= 0) {
				int nval = dp[mask];
				if (sum + seq[i].lo == 0) nval += seq[i].cnt[0];
				int nmask = mask | (1 << i);
				dp[nmask] = max(dp[nmask], nval);
			}
		}
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) cin >> s[i];
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}