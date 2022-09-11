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

int n;
int a[MAXN];

int cntbefore[MAXN], cntafter[MAXN];

void calcbeforeandafter() {
	REP(i, n) cntbefore[i] = i - 1 >= 0 && a[i - 1] > a[i] ? 1 + cntbefore[i - 1] : 0;
	for (int i = n - 1; i >= 0; --i) cntafter[i] = i + 1 < n && a[i + 1] > a[i] ? 1 + cntafter[i + 1] : 0;
}

int stck[MAXN], nstck;
int prvgreater[MAXN];
int prvsmaller[MAXN];
int nxtgreater[MAXN];
int nxtsmaller[MAXN];
int dpup[MAXN];
int dpdn[MAXN];
int dpgreater[MAXN];
int dpsmaller[MAXN];
int dpaway[MAXN];

int suffix;

int sval[4 * MAXN];
void sinit(int x, int l, int r) {
	if (l == r) {
		sval[x] = n;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		sval[x] = min(sval[2 * x + 1], sval[2 * x + 2]);
	}
}
void smod(int x, int l, int r, int IDX, int VAL) {
	if (l == r) {
		sval[x] = min(sval[x], VAL);
	} else {
		int m = l + (r - l) / 2;
		if (IDX <= m) smod(2 * x + 1, l, m, IDX, VAL); else smod(2 * x + 2, m + 1, r, IDX, VAL);
		sval[x] = min(sval[2 * x + 1], sval[2 * x + 2]);
	}
}
int sget(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return sval[x];
	} else {
		int m = l + (r - l) / 2; int ret = n;
		if (L <= m) ret = min(ret, sget(2 * x + 1, l, m, L, R));
		if (m + 1 <= R) ret = min(ret, sget(2 * x + 2, m + 1, r, L, R));
		return ret;
	}
}

int calcfirstinrange(int l, int r) {
	return l <= r ? sget(0, 0, n - 1, l, r) : n;
}

//  a[i] > a[j], a[i] is part of increasing sequence, a[j] part of decreasing sequence, calculate how far we can get to right (return first element that is impossible) ignoring elements between i and j
int calcaway(int i, int j) {
	int k = max(i, j);
	assert(suffix == k);
	int ret = n;
	int up = calcfirstinrange(a[i], n - 1);
	if (up != n) ret = min(ret, dpgreater[up]);
	int dn = calcfirstinrange(0, a[j]);
	if (dn != n) ret = min(ret, dpsmaller[dn]);
	int forbid = calcfirstinrange(dn == n ? 0 : a[dn] + 1, up == n ? n - 1 : a[up] - 1);
	ret = min(ret, forbid);
	//printf("\tcalcaway(%d,%d)=%d\n", i, j, ret);
	return ret;
}
// j==i+1, a[i] < a[j], a[i] is part of increasing sequence, a[j] part of decreasing sequence, calculate how far we can get to right (return first element that is impossible)
int calctowards1(int i, int j) {
	return dpdn[j];
}
// j==i+1, a[i] > a[j], a[i] is part of decreasing sequence, a[j] part of increasing sequence, calculate how far we can get to right (return first element that is impossible)
int calctowards2(int i, int j) {
	return dpup[j];
}

ll solve() {
	ll ret = 0;
	// ". . . min . . ."
	calcbeforeandafter();
	REP(i, n) ret += (ll)(cntbefore[i] + 1) * (cntafter[i] + 1);
	// containing "min . . . . lower" and containing "lower . . . . min"
	REP(rep, 2) {
		calcbeforeandafter();
		nstck = 0;
		REP(i, n) {
			while (nstck > 0 && a[stck[nstck - 1]] <= a[i]) --nstck;
			prvgreater[i] = nstck == 0 ? -1 : stck[nstck - 1];
			stck[nstck++] = i;
		}
		nstck = 0;
		REP(i, n) {
			while (nstck > 0 && a[stck[nstck - 1]] >= a[i]) --nstck;
			prvsmaller[i] = nstck == 0 ? -1 : stck[nstck - 1];
			stck[nstck++] = i;
		}
		nstck = 0;
		for (int i = n - 1; i >= 0; --i) {
			while (nstck > 0 && a[stck[nstck - 1]] <= a[i]) --nstck;
			nxtgreater[i] = nstck == 0 ? -1 : stck[nstck - 1];
			stck[nstck++] = i;
		}
		nstck = 0;
		for (int i = n - 1; i >= 0; --i) {
			while (nstck > 0 && a[stck[nstck - 1]] >= a[i]) --nstck;
			nxtsmaller[i] = nstck == 0 ? -1 : stck[nstck - 1];
			stck[nstck++] = i;
		}
		suffix = n;
		sinit(0, 0, n - 1);
		for (int j = n - 1; j >= 0; --j) {
			if (prvgreater[j] != -1) {
				int i = prvgreater[j];
				dpup[j] = j + 1 >= n ? j + 1 : a[j + 1] < a[j] ? calcaway(j, j + 1) : a[j + 1] > a[i] ? calcaway(j + 1, i) : max(dpup[j + 1], dpdn[j + 1]);
			}
			if (prvsmaller[j] != -1) {
				int i = prvsmaller[j];
				dpdn[j] = j + 1 >= n ? j + 1 : a[j + 1] > a[j] ? calcaway(j + 1, j) : a[j + 1] < a[i] ? calcaway(i, j + 1) : max(dpup[j + 1], dpdn[j + 1]);
			}
			if (nxtgreater[j] == -1) {
				dpgreater[j] = n;
			} else {
				int k = nxtgreater[j];
				dpgreater[j] = min(dpgreater[k], calcfirstinrange(a[j] + 1, a[k] - 1));
			}
			if (nxtsmaller[j] == -1) {
				dpsmaller[j] = n;
			} else {
				int k = nxtsmaller[j];
				dpsmaller[j] = min(dpsmaller[k], calcfirstinrange(a[k] + 1, a[j] - 1));
			}
			if (j + 1 < n && a[j] > a[j + 1]) dpaway[j] = calcaway(j, j + 1);
			--suffix;
			smod(0, 0, n - 1, a[j], j);
		}
		//printf("dpdn:"); REP(i, n) printf(" %d", dpdn[i]); puts("");
		//printf("dpup:"); REP(i, n) printf(" %d", dpup[i]); puts("");
		REP(i, n) {
			int j = i + cntafter[i] + 1;
			if (j >= n) continue;
			if (a[j] <= a[i]) continue;
			if (j == i + 1) continue;
			int without = max(dpaway[j - 1], calctowards1(j - 2, j - 1));
			if (nxtsmaller[i] != -1) without = min(without, nxtsmaller[i]);
			if (without >= j) {
				ret += without - j;
				//printf("rep=%d: %d to [%d..%d] (%d and %d)\n", rep, i, j, without - 1, dpaway[j - 1], calctowards1(j - 2, j - 1));
			}
			if (i - 1 >= 0 && a[i - 1] > a[i]) {
				int with = calctowards2(i - 1, i);
				if (nxtsmaller[i] != -1) with = min(with, nxtsmaller[i]);
				if (with >= j) {
					ret += (ll)cntbefore[i] * (with - j);
					//printf("rep=%d: %d to [%d..%d] %d times\n", rep, i, j, with - 1, cntbefore[i]);
				}
			}
		}
		reverse(a, a + n);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}