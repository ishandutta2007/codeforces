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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 200000;
const int MAXQ = 200000;

int n, nq;
int a[MAXN];
int ql[MAXQ], qr[MAXQ]; vector<int> qans[MAXQ];

set<int> nonextremal;
int both[MAXN], nboth;
int upper[MAXN], diffupper[MAXN], nupper;
int lower[MAXN], difflower[MAXN], nlower;

void addupper(int idx) { upper[nupper] = idx, diffupper[nupper] = nupper == 0 ? -1 : a[upper[nupper - 1]] == a[idx] ? diffupper[nupper - 1] : upper[nupper - 1], ++nupper; }
void addlower(int idx) { lower[nlower] = idx, difflower[nlower] = nlower == 0 ? -1 : a[lower[nlower - 1]] == a[idx] ? difflower[nlower - 1] : lower[nlower - 1], ++nlower; }
void removeupper() { int idx = upper[--nupper]; nonextremal.insert(idx); }
void removelower() { int idx = lower[--nlower]; nonextremal.insert(idx); }
int findabove(int idx) { int lo = -1, hi = nupper; while (lo + 1 < hi) { int mi = lo + (hi - lo) / 2; if (upper[mi] <= idx) hi = mi; else lo = mi; } assert(hi < nupper); return upper[hi]; }
int findbelow(int idx) { int lo = -1, hi = nlower; while (lo + 1 < hi) { int mi = lo + (hi - lo) / 2; if (lower[mi] <= idx) hi = mi; else lo = mi; } assert(hi < nlower); return lower[hi]; }

bool havesol4[MAXN];
int sol4[MAXN][4];
int mnsol4[MAXN];

bool havesol3[MAXN];
int sol3[MAXN][3];
int mnsol3[MAXN];


void solve() {
	//printf("a:"); REP(i, n) printf(" %d", a[i]); puts("");
	nboth = 0, nupper = 0, nlower = 0; nonextremal.clear();
	for (int i = n - 1; i >= 0; --i) {
		if (nboth == 0 || a[i] != a[both[nboth - 1]]) {
			if (nboth > 0 && a[i] < a[both[nboth - 1]]) {
				REP(j, nboth) addupper(both[j]);
				nboth = 0;
			}
			if (nboth > 0 && a[i] > a[both[nboth - 1]]) {
				REP(j, nboth) addlower(both[j]);
				nboth = 0;
			}
			while (nupper > 0 && a[i] > a[upper[nupper - 1]]) removeupper();
			while (nlower > 0 && a[i] < a[lower[nlower - 1]]) removelower();
		}
		both[nboth++] = i;
		int fstabove = nupper == 0 ? -1 : a[upper[nupper - 1]] == a[i] ? diffupper[nupper - 1] : upper[nupper - 1];
		int fstbelow = nlower == 0 ? -1 : a[lower[nlower - 1]] == a[i] ? difflower[nlower - 1] : lower[nlower - 1];
		int fstaboveoreq = nupper == 0 ? -1 : upper[nupper - 1];
		int fstbeloworeq = nlower == 0 ? -1 : lower[nlower - 1];
		havesol3[i] = false;
		havesol4[i] = false;
		if (fstabove != -1 && fstbelow != -1) {
			int mid = min(fstabove, fstbelow), lst = max(fstabove, fstbelow);
			if (!havesol3[i] || lst < sol3[i][2]) havesol3[i] = true, sol3[i][0] = i, sol3[i][1] = mid, sol3[i][2] = lst;
		}
		if (fstabove != -1) {
			auto it = nonextremal.lower_bound(fstabove + 1);
			if (it != nonextremal.end()) {
				int lst = *it, mid = findabove(lst); assert(a[i] < a[mid] && a[lst] < a[mid]);
				if (!havesol3[i] || lst < sol3[i][2]) havesol3[i] = true, sol3[i][0] = i, sol3[i][1] = mid, sol3[i][2] = lst;
			}
			if (fstbeloworeq != -1 && fstbeloworeq > fstabove) {
				int mid = fstabove, lst = fstbeloworeq;
				if (!havesol3[i] || lst < sol3[i][2]) havesol3[i] = true, sol3[i][0] = i, sol3[i][1] = mid, sol3[i][2] = lst;
			}
		}
		if (fstbelow != -1) {
			auto it = nonextremal.lower_bound(fstbelow + 1);
			if (it != nonextremal.end()) {
				int lst = *it, mid = findbelow(lst); assert(a[i] > a[mid] && a[lst] > a[mid]);
				if (!havesol3[i] || lst < sol3[i][2]) havesol3[i] = true, sol3[i][0] = i, sol3[i][1] = mid, sol3[i][2] = lst;
			}
			if (fstaboveoreq != -1 && fstaboveoreq > fstbelow) {
				int mid = fstbelow, lst = fstaboveoreq;
				if (!havesol3[i] || lst < sol3[i][2]) havesol3[i] = true, sol3[i][0] = i, sol3[i][1] = mid, sol3[i][2] = lst;
			}
		}
		if (fstabove != -1 && fstbelow != -1) {
			int lim = max(fstabove, fstbelow) + 1;
			auto it = nonextremal.lower_bound(lim);
			if (it != nonextremal.end()) {
				int fst = i, lst = *it;
				int above = findabove(lst);
				int below = findbelow(lst);
				//printf("found4 (%d,%d/%d,%d) (%d/%d)\n", fst, above, below, lst, fstabove, fstbelow);
				havesol4[i] = true; sol4[i][0] = fst; sol4[i][1] = min(above, below); sol4[i][2] = max(above, below); sol4[i][3] = lst;
				assert(a[fst]<a[above] && a[fst]>a[below] && a[lst]<a[above] && a[lst]>a[below] && fst<above && fst<below && lst>above && lst>below);
			}
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		mnsol4[i] = i + 1 < n ? mnsol4[i + 1] : -1;
		if (havesol4[i] && (mnsol4[i] == -1 || sol4[i][3] <= sol4[mnsol4[i]][3])) mnsol4[i] = i;
		mnsol3[i] = i + 1 < n ? mnsol3[i + 1] : -1;
		if (havesol3[i] && (mnsol3[i] == -1 || sol3[i][2] <= sol3[mnsol3[i]][2])) mnsol3[i] = i;
	}

	REP(i, nq) {
		int l = ql[i], r = qr[i];
		if (mnsol4[l] != -1 && sol4[mnsol4[l]][3] <= r) { qans[i] = vector<int>(4); REP(j, 4) qans[i][j] = sol4[mnsol4[l]][j]; continue; }
		if (mnsol3[l] != -1 && sol3[mnsol3[l]][2] <= r) { qans[i] = vector<int>(3); REP(j, 3) qans[i][j] = sol3[mnsol3[l]][j]; continue; }
		qans[i] = vector<int>(0);
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	REP(i, nq) { printf("%d\n", SZ(qans[i])); REPSZ(j, qans[i]) { if (j != 0) printf(" "); printf("%d", qans[i][j] + 1); } puts(""); }
}

vector<int> stupidans[MAXQ];

void solvestupid() {
	REP(i, nq) {
		int l = ql[i], r = qr[i];
		stupidans[i] = vector<int>(0);
		if (SZ(stupidans[i]) == 0) FORE(w, l, r) if (SZ(stupidans[i]) == 0) FORE(x, w + 1, r) if (SZ(stupidans[i]) == 0) FORE(y, x + 1, r) if (SZ(stupidans[i]) == 0) FORE(z, y + 1, r) if (SZ(stupidans[i]) == 0) {
			if (a[w]<max(a[x], a[y]) && a[w]>min(a[x], a[y]) && a[z]<max(a[x], a[y]) && a[z]>min(a[x], a[y])) {
				stupidans[i] = vector<int>(4); stupidans[i][0] = w, stupidans[i][1] = x, stupidans[i][2] = y, stupidans[i][3] = z;
			}
		}
		if (SZ(stupidans[i]) == 0) FORE(x, l, r) if (SZ(stupidans[i]) == 0) FORE(y, x + 1, r) if (SZ(stupidans[i]) == 0) FORE(z, y + 1, r) if (SZ(stupidans[i]) == 0) {
			if (a[x]<a[y] && a[z]<a[y] || a[x]>a[y] && a[z]>a[y]) {
				stupidans[i] = vector<int>(3); stupidans[i][0] = x, stupidans[i][1] = y, stupidans[i][2] = z;
			}
		}
	}
}

void stress() {
	REP(rep, 1000000) {
		n = rnd() % 10 + 1; int lim = rnd() % 10 + 1;
		REP(i, n) a[i] = rnd() % lim + 1;
		nq = 1; ql[0] = 0, qr[0] = n - 1;
		solve();
		solvestupid();
		bool ok = true; REP(i, nq) if (SZ(qans[i]) != SZ(stupidans[i])) ok = false;
		if (ok) { if (rep % 100 == 99) printf("."); continue; }
		printf("err\n");
		REP(i, nq) { printf("["); REPSZ(j, qans[i]) { if (j != 0) printf(","); printf("%d", qans[i][j] + 1); } printf("] vs ["); REPSZ(j, stupidans[i]) { if (j != 0) printf(","); printf("%d", stupidans[i][j] + 1); } printf("]\n"); }
		printf("%d %d\n", n, nq);
		REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i]); }
		REP(i, nq) printf("%d %d\n", ql[i] + 1, qr[i] + 1);
	}
}

int main() {
	//stress();
	run();
	return 0;
}