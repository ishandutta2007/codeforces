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

const int MAXBIT = 16;
const int MAXN = 2 << MAXBIT;

int l, r, n;
int a[MAXN];

int mxbit, diffbit;

int calcwant(int r, int bit) {
	int period = 2 << bit;
	int half = 1 << bit;
	int full = (r + 1) / period, rem = (r + 1) % period;
	return full * half + max(0, rem - half);
}
int calcwant(int l, int r, int bit) {
	return calcwant(r, bit) - (l == 0 ? 0 : calcwant(l - 1, bit));
}



int trycalc(bool flipdiff) {
	int ret = 0;
	vector<int> b(a, a + n);
	for (int bit = mxbit; bit > diffbit; --bit) {
		int have = 0;
		REP(i, n) if (b[i] & (1 << bit)) ++have;
		int want = calcwant(l, r, bit);
		assert(want == 0 || want == n);
		assert(want != n - want);
		//printf("\tbit=%d: have=%d, want=%d\n", bit, have, want);
		if (have == want) continue;
		if (have != n - want) return -1;
		ret ^= 1 << bit;
		REP(i, n) b[i] ^= 1 << bit;
	}
	if (flipdiff) {
		ret ^= 1 << diffbit;
		REP(i, n) b[i] ^= 1 << diffbit;
	}
	int havediff = 0;
	REP(i, n) if (b[i] & (1 << diffbit)) ++havediff;
	int wantdiff = calcwant(l, r, diffbit);
	//printf("\tbit=%d: have=%d, want=%d\n", diffbit, havediff, wantdiff);
	if (havediff != wantdiff) return -1;
	int ml = l, mr = r;
	while (ml % (1 << diffbit) != 0) ++ml;
	while (mr % (1 << diffbit) != (1 << diffbit) - 1) --mr;
	//printf("l=%d ml=%d mr=%d r=%d\n", l, ml, mr, r);
	//printf("a:"); REP(i, n) printf(" %d", a[i]); puts("");
	//printf("b:"); REPSZ(i, b) printf(" %d", b[i]); puts("");
	vector<int> lo, mi, hi;
	REP(i, n) if (b[i] < ml) lo.PB(b[i]); else if (b[i] > mr) hi.PB(b[i]); else mi.PB(b[i]);
	sort(mi.begin(), mi.end());
	//printf("mi:"); REPSZ(i, mi) printf(" %d", mi[i]); puts("");
	if (SZ(mi) != mr - ml + 1) return -1;
	if (SZ(lo) != ml - l) return -1;
	if (SZ(hi) != r - mr) return -1;
	REPSZ(i, mi) if (mi[i] != ml + i) return -1;
	for (int bit = diffbit - 1; bit >= 0; --bit) {
		int havelo = 0;
		REPSZ(i, lo) if (lo[i] & (1 << bit)) ++havelo;
		int wantlo = l <= ml - 1 ? calcwant(l, ml - 1, bit) : 0;
		int havehi = 0;
		REPSZ(i, hi) if (hi[i] & (1 << bit)) ++havehi;
		int wanthi = mr + 1 <= r ? calcwant(mr + 1, r, bit) : 0;
		if (havelo == wantlo && havehi == wanthi) continue; // maybe we could flip, but doesn't matter?
		if (havelo != SZ(lo) - wantlo || havehi != SZ(hi) - wanthi) return -1;
		ret ^= 1 << bit;
		REPSZ(i, lo) lo[i] ^= 1 << bit;
		REPSZ(i, hi) hi[i] ^= 1 << bit;
	}
	sort(lo.begin(), lo.end());
	sort(hi.begin(), hi.end());
	REPSZ(i, lo) if (lo[i] != l + i) return -1;
	REPSZ(i, hi) if (hi[i] != mr + 1 + i) return -1;
	return ret;
}

int solve() {
	if (l == r) return a[0] ^ l;
	int mxval = r;
	REP(i, n) mxval = max(mxval, a[i]);
	mxbit = 0;
	while ((2 << mxbit) <= mxval) ++mxbit;
	diffbit = mxbit;
	while (((l >> diffbit) & 1) == ((r >> diffbit) & 1)) --diffbit;
	REP(flipdiff, 2) {
		int cur = trycalc(flipdiff == 1);
		if (cur != -1) return cur;
	}
	assert(false); return -1;
}

void run() {
	scanf("%d%d", &l, &r); n = r - l + 1;
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}