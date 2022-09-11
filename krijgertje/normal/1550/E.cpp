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
const int MAXALPH = 17;

int n, alph;
char s[MAXN + 1];

int before[MAXN];
int aftereq[MAXN];

int len;
int nxtopt[MAXN][MAXALPH];
int qnxtopt[MAXN];


bool can(int at, int havemask, int remcnt, int freecnt) {
	if (freecnt >= remcnt) return true;
	if (at >= n) return false;
	int pos = n;
	REP(k, alph) if ((havemask & (1 << k)) == 0) pos = min(pos, nxtopt[at][k]);
	pos = min(pos, qnxtopt[at]);
	if (pos == n) return false;
	if (s[pos] == '?') {
		assert(pos == at || pos >= 0 && s[pos - 1] != '?');
		assert(aftereq[pos] >= len);
		return can(pos + len, havemask, remcnt, freecnt + 1);
	} else {
		int l = min(before[pos], pos - at);
		assert(l < len);
		if (aftereq[pos] < len - l) return can(pos + 1, havemask, remcnt, freecnt);
		int k = s[pos] - 'a';
		assert((havemask & (1 << k)) == 0);
		if (can(pos + len - l, havemask | (1 << k), remcnt - 1, freecnt)) return true;
		int last = pos + len - l - 1;
		if (s[last] == '?') {
			int nxt = last + aftereq[last];
			if (nxt < n) {
				assert(s[nxt] != '?' && s[nxt - 1] == '?');
				int gap = before[nxt];
				int from = nxt - gap;
				if (gap >= len) {
					if (can(from + len, havemask, remcnt, freecnt + 1)) return true;
				} else {
					int kk = s[nxt] - 'a';
					if ((havemask & (1 << kk)) == 0 && aftereq[nxt] >= len - gap) {
						if (can(nxt + len - gap, havemask | (1 << kk), remcnt - 1, freecnt)) return true;
					}
				}
			}
		}
	}
	return false;
}

int solve() {
	REP(i, n) before[i] = i - 1 >= 0 && s[i - 1] == '?' ? 1 + before[i - 1] : 0;
	for (int i = n - 1; i >= 0; --i) aftereq[i] = i + 1 >= n ? 1 : s[i + 1] == s[i] ? 1 + aftereq[i + 1] : s[i + 1] == '?' ? 1 + aftereq[i + 1] + (i + 1 + aftereq[i + 1] < n && s[i + 1 + aftereq[i + 1]] == s[i] ? aftereq[i + 1 + aftereq[i + 1]] : 0) : 1;
	//printf("before:"); REP(i, n) printf(" %d", before[i]); puts("");
	//printf("aftereq:"); REP(i, n) printf(" %d", aftereq[i]); puts("");

	int lo = 0, hi = n + 1;
	while (lo + 1 < hi) {
		int mi = lo + (hi - lo) / 2;
		len = mi;
		for (int i = n - 1; i >= 0; --i) REP(k, alph) if (s[i] == 'a' + k && before[i] + aftereq[i] >= len) nxtopt[i][k] = i; else nxtopt[i][k] = i + 1 < n ? nxtopt[i + 1][k] : n;
		for (int i = n - 1; i >= 0; --i) if (s[i] == '?' && aftereq[i] >= len) qnxtopt[i] = i; else qnxtopt[i] = i + 1 < n ? qnxtopt[i + 1] : n;
		if (can(0, 0, alph, 0)) lo = mi; else hi = mi;
	}
	return lo;
}

void run() {
	scanf("%d%d", &n, &alph);
	scanf("%s", s);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}