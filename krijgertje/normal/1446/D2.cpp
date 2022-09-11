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

int n;
int a[MAXN];

int cnt[MAXN], freq[MAXN + 1], mxcnt;

int solve() {
	int ret = 0;
	int magic = sqrt(n);
	//printf("magic=%d\n", magic);
	
	FORE(lim, 1, magic) {
		REP(i, n) cnt[i] = 0;
		REPE(i, n) freq[i] = 0;
		freq[0] = n, mxcnt = 0;
		int l = 0, r = 0; // [l..r)
		int cur = 0;
		while (true) {
			//printf("[%d..%d) mxcnt=%d freq[%d]=%d\n", l, r, mxcnt, mxcnt, freq[mxcnt]);
			if (mxcnt > lim) {
				--freq[cnt[a[l]]];
				--cnt[a[l]];
				++freq[cnt[a[l]]];
				++l;
				if (freq[mxcnt] == 0) --mxcnt;
			} else {
				if (freq[mxcnt] >= 2) cur = max(cur, r - l);
				if (r >= n) break;
				--freq[cnt[a[r]]];
				++cnt[a[r]];
				++freq[cnt[a[r]]];
				++r;
				if (mxcnt < n && freq[mxcnt + 1]>0) ++mxcnt;
			}
		}
		//printf("%d: %d\n", lim, cur);
		ret = max(ret, cur);
	}

	REP(i, n) cnt[i] = 0;
	REP(i, n) ++cnt[a[i]];
	int x = 0; REP(i, n) if (cnt[i] > cnt[x]) x = i;
	REP(y, n) if (y != x && cnt[y] > magic) {
		vector<int> bal(n + 1);
		bal[0] = 0; REP(i, n) bal[i + 1] = bal[i] + (a[i] == x ? -1 : a[i] == y ? +1 : 0);
		int lo = 0; REPE(i, n) lo = min(lo, bal[i]);
		int hi = 0; REPE(i, n) hi = max(hi, bal[i]);
		vector<int> fst(hi - lo + 1, INT_MAX), lst(hi - lo + 1, INT_MIN);
		REPE(i, n) fst[bal[i] - lo] = min(fst[bal[i] - lo], i), lst[bal[i] - lo] = max(lst[bal[i] - lo], i);
		int cur = 0;
		REPSZ(i, fst) if (fst[i] <= lst[i]) cur = max(cur, lst[i] - fst[i]);
		//printf("(%d,%d): %d\n", x + 1, y + 1, cur);
		ret = max(ret, cur);
	}

	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	printf("%d\n", solve());
}

int solvestupid() {
	int ret = 0;
	REP(l, n) {
		vector<int> cnt(n, 0);
		vector<int> freq(n + 1, 0);
		freq[0] = n;
		int mxcnt = 0;
		FOR(r, l, n) {
			--freq[cnt[a[r]]];
			++cnt[a[r]];
			++freq[cnt[a[r]]];
			if (mxcnt + 1 <= n && freq[mxcnt + 1] > 0) ++mxcnt;
			if (freq[mxcnt] >= 2) ret = max(ret, r - l + 1);
		}
	}
	return ret;
}

void stress() {
	REP(rep, 100000) {
		n = rnd() % 1000 + 1;
		int mxval = rnd() % min(n, 100);
		REP(i, n) a[i] = rnd() % (mxval + 1);
		int have = solve();
		int want = solvestupid();
		if (have == want) { printf("."); continue; }
		printf("err have=%d want=%d\n", have, want);
	}
}

int main() {
	run();
	//stress();
	return 0;
}