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

struct UF {
	int n; vector<int> par, sz, val;
	void init(int _n) { n = _n; par = sz = val = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1, val[i] = i; }
	int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return;
		int v = val[x];
		if (sz[x] < sz[y]) swap(x, y);
		par[y] = x, sz[x] += sz[y], val[x] = v;
	}
	int get(int x) { return val[find(x)]; }
};

const int MAXLEN = 5000;

int alen, blen;
char a[MAXLEN + 1];
char b[MAXLEN + 1];

int match[MAXLEN][MAXLEN]; // match[i][j] = length of match of a[i..] with b[j..]
int rmatch[MAXLEN][MAXLEN]; // rmatch[i][j] = length of match of a[..i] with b[..j]
int pref[MAXLEN]; // pref[i] = max matching characters of a subsequence of a[0..i] with b[0..]
int suff[MAXLEN]; // suff[i] = max matching characters of a subsequence of a[i..alen-1] with b[..blen-1]

int solve() {
	for (int i = alen - 1; i >= 0; --i) for (int j = blen - 1; j >= 0; --j) {
		match[i][j] = a[i] != b[j] ? 0 : 1 + (i + 1 < alen && j + 1 < blen ? match[i + 1][j + 1] : 0);
	}
	REP(i, alen) REP(j, blen) {
		rmatch[i][j] = a[i] != b[j] ? 0 : 1 + (i - 1 >= 0 && j - 1 >= 0 ? rmatch[i - 1][j - 1] : 0);
	}
	REP(i, alen) {
		if (i == 0) pref[i] = a[i] == b[0] ? 1 : 0;
		else pref[i] = pref[i - 1] + (pref[i - 1] != blen && a[i] == b[pref[i - 1]] ? 1 : 0);
	}
	for (int i = alen - 1; i >= 0; --i) {
		if (i == alen - 1) suff[i] = a[i] == b[blen - 1] ? 1 : 0;
		else suff[i] = suff[i + 1] + (suff[i + 1] != blen && a[i] == b[blen - suff[i + 1] - 1] ? 1 : 0);
	}
	int ret = INT_MAX;
	// do nothing
	if (alen == blen && match[0][0] == blen) ret = min(ret, 0);
	// only remove characters from suffix
	REP(i, alen) { // leftmost to remove
		if (match[0][0] < i) continue;
		int need = blen - i;
		if (suff[i] < need) continue;
		ret = min(ret, alen - i);
	}
	// only remove characters from prefix
	REP(i, alen) { // rightmost to remove
		if (rmatch[alen - 1][blen - 1] < alen - i - 1) continue;
		int need = blen - (alen - i - 1);
		if (pref[i] < need) continue;
		ret = min(ret, 1 + i + 1 + i + 1 - need);
	}
	// remove characters both from prefix and suffix
	REP(i, alen - 1) {
		vector<bool> dead(blen + 1, false);
		vector<vector<int>> die(blen + 1);
		REP(k, blen) die[match[i + 1][k]].PB(k);
		UF uf;
		uf.init(blen + 1);
		FOR(j, i + 1, alen) {
			// leftmost and rightmost to remove
			int mid = j - i - 1;
			if (mid - 1 >= 0 && mid - 1 <= blen) for (int k : die[mid - 1]) {
				dead[k] = true;
				if (k - 1 >= 0 && dead[k - 1]) uf.unite(k - 1, k);
				if (k + 1 <= blen && dead[k + 1]) uf.unite(k, k + 1);
			}
			if (mid > blen) continue;
			int lmx = min(pref[i], blen - mid);
			int rmx = min(suff[j], blen - mid);
			// find max k st: 0<=k<=lmx, match[i+1][k]>=mid, blen-mid-k<=rmx -> alen-j+1+i+1+i+1-k			(-> k>=blen-mid-rmx)
			int lo = max(0, blen - mid - rmx), hi = lmx;
			if (lo > hi) continue;
			int k = !dead[hi] ? hi : uf.get(hi) - 1;
			if (k >= lo) {
				//printf("i=%d j=%d -> %d..%d -> k=%d (%d)\n", i, j, lo, hi, k, alen - j + 1 + i + 1 + i + 1 - k);
				ret = min(ret, alen - j + 1 + i + 1 + i + 1 - k);
			}
		}
	}
	return ret == INT_MAX ? -1 : ret;
}

void run() {
	scanf("%d%d", &alen, &blen);
	scanf("%s", a);
	scanf("%s", b);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}