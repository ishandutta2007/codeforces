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

const int MAXN = 100000;

int n, wantimbal;
int par[MAXN];

int nxtnode;

int calcmn(int n) {
	++n;
	while (n % 2 == 0) n /= 2;
	return n == 1 ? 0 : 1;
}
int calcmx(int n) {
	if (n == 1) return 0;
	return (n - 3) / 2;
}

bool forbidden(int n, int imbal) {
	if (calcmn(n) == 0 && imbal == 1) return true;
	//if (imbal == (n - 5) / 2) return true;
	if (n == 7 && imbal == 1 || n == 9 && imbal == 2) return true;
	return false;
}

void rec(int target, int cnt, int at) {
	//printf("rec(%d,%d,%d)\n", target, cnt, at);
	assert(cnt >= 1 && cnt % 2 == 1);
	if (cnt == 1) { assert(target == 0); return; }
	for (int l = 1; l < cnt; l += 2) {
		int r = cnt - l - 1; assert(r >= 1 && r % 2 == 1);
		int extra = max(l, r) >= 2 * min(l, r) ? 1 : 0;
		if (extra > target) continue;
		int lmn = calcmn(l), lmx = calcmx(l), rmn = calcmn(r), rmx = calcmx(r);
		if (extra + lmn + rmn > target) continue;
		if (extra + lmx + rmx < target) continue;
		int ltarget = min(target - extra - rmn, lmx); int rtarget = target - extra - ltarget;
		if (l == 7 && ltarget == 1) { if (rtarget < rmx) --ltarget, ++rtarget; else if (rtarget > rmn) ++ltarget, --rtarget; else continue; }
		if (r == 7 && rtarget == 1) { if (ltarget < lmx) --rtarget, ++ltarget; else if (ltarget > lmn) ++rtarget, --ltarget; else continue; }
		if (l == 7 && ltarget == 1 || r == 7 && rtarget == 1) continue;
		if (forbidden(l, ltarget) || forbidden(r, rtarget)) continue;
		assert(ltarget >= lmn && ltarget <= lmx && rtarget >= rmn && rtarget <= rmx && target == ltarget + rtarget + extra);
		int lnode = nxtnode++;
		int rnode = nxtnode++;
		par[lnode] = at;
		par[rnode] = at;
		rec(ltarget, l, lnode);
		rec(rtarget, r, rnode);
		return;
	}
	assert(false);
}

bool solve() {
	if (n % 2 == 0) return false;
	par[0] = -1, nxtnode = 1;
	if (wantimbal<calcmn(n) || wantimbal>calcmx(n) || forbidden(n, wantimbal)) return false;
	rec(wantimbal, n, 0);
	return true;
}

void run() {
	scanf("%d%d", &n, &wantimbal);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, n) { if (i != 0) printf(" "); printf("%d", par[i] + 1); } puts("");
}

void research() {
	int n = 101;
	vector<int> mn(n + 1, INT_MAX); vector<pair<int, int>> howmn(n + 1, pair<int, int>(-1, -1));
	vector<int> mx(n + 1, INT_MIN); vector<pair<int, int>> howmx(n + 1, pair<int, int>(-1, -1));
	mn[1] = mx[1] = 0;
	for (int i = 3; i <= n; i += 2) {
		for (int l = 1; l < i; l += 2) {
			int r = i - l - 1; assert(r >= 1 && r % 2 == 1);
			int extra = max(l, r) >= 2 * min(l, r) ? 1 : 0;
			int curmn = mn[l] + mn[r] + extra; if (curmn < mn[i]) mn[i] = curmn, howmn[i] = MP(l, r);
			int curmx = mx[l] + mx[r] + extra; if (curmx > mx[i]) mx[i] = curmx, howmx[i] = MP(l, r);
		}
	}
	REPE(i, n) if (i % 2 == 1) assert(mn[i] == calcmn(i) && mx[i] == calcmx(i));
	REPE(i, n) if (i % 2 == 1) printf("%d: %d..%d [%d/%d] [%d/%d]\n", i, mn[i], mx[i], howmn[i].first, howmn[i].second, howmx[i].first, howmx[i].second);
}

void verify() {
	vector<int> sz(n, 1); vector<vector<int>> chsz(n);
	assert(par[0] == -1);
	for (int i = n - 1; i >= 1; --i) { assert(par[i] < i); sz[par[i]] += sz[i]; chsz[par[i]].PB(sz[i]); }
	REP(i, n) assert(SZ(chsz[i]) == 0 || SZ(chsz[i]) == 2);
	int have = 0; REP(i, n) if (SZ(chsz[i]) == 2) { int a = chsz[i][0], b = chsz[i][1]; if (max(a, b) >= 2 * min(a, b)) ++have; } assert(have == wantimbal);
}

void stress() {
	for (n = 1; n <= 1001; n += 2) {
		int mn = calcmn(n), mx = calcmx(n);
		for (wantimbal = mn; wantimbal <= mx; ++wantimbal) {
			//if (n == 7 && wantimbal == 1) continue;
			//if (n == 9 && wantimbal == 2) continue;
			if (forbidden(n, wantimbal)) continue;
			printf("n=%d wantimbal=%d\n", n, wantimbal);
			bool have = solve();
			assert(have);
			verify();
		}
	}
}

int main() {
	//research();
	run();
	//stress();
	return 0;
}