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
const int MAXSUMLEN = 1000000;
const int MOD = 1000000007;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int &a, int b) { inc(a, MOD - b); }

int n;
char s[MAXSUMLEN + 1];
int offset[MAXN + 1], len[MAXN];


int dpnorem[MAXN];
int dprem[MAXSUMLEN];

char a[MAXSUMLEN + 1]; int alen;
char b[MAXSUMLEN + 1]; int blen;

int dpa[MAXSUMLEN];
int dpb[MAXSUMLEN];
int prefixcmp[MAXSUMLEN + 1]; // prefixcmp[i] = result of comparing a[0..i) with b[0..i)
int suffixcmp[MAXSUMLEN + 1][3]; // suffixcmp[i][shift+1] = result of comparing a[i..) with b[i+shift..)
int prefsubdp[MAXSUMLEN + 1][3]; // prefsubdp[i][cmp+1] = when comparing a[0..i) and b[0..i+1) removing exactly one of them, sum over those dprem where cmp is result of comparison
int suffsubdp[MAXSUMLEN + 1][3]; // suffsubdp[i][cmp+1] = when comparing a[i+1..) and b[i..) removing exactly one of them, sum over those dprem where cmp is result of comparison 


int combinecmp(int a, int b) { return a != 0 ? a : b; }
int cmpchar(int aidx, int bidx) { char ca = 0 <= aidx&&aidx < alen ? a[aidx] : '\0', cb = 0 <= bidx&&bidx < blen ? b[bidx] : '\0'; return ca < cb ? -1 : ca > cb ? +1 : 0; }

int solve() {
	dpnorem[n - 1] = 1;
	REP(j, len[n - 1]) dprem[offset[n - 1] + j] = 1;
	for (int i = n - 2; i >= 0; --i) {
		alen = len[i]; REP(j, alen) a[j] = s[offset[i] + j]; a[alen] = '\0';
		blen = len[i + 1]; REP(k, blen) b[k] = s[offset[i + 1] + k]; b[blen] = '\0';
		REP(k, blen) dpb[k] = dprem[offset[i + 1] + k];

		int mxlen = max(alen, blen);
		prefixcmp[0] = 0; REP(j, mxlen) prefixcmp[j + 1] = combinecmp(prefixcmp[j], cmpchar(j, j));
		FORE(shift, -1, +1) { suffixcmp[mxlen][shift + 1] = 0; for (int j = mxlen - 1; j >= 0; --j) suffixcmp[j][shift + 1] = combinecmp(cmpchar(j, j + shift), suffixcmp[j + 1][shift + 1]); }

		REP(j, mxlen) {
			FORE(cmp, -1, +1) prefsubdp[j][cmp + 1] = 0;
			if (j - 1 >= 0) FORE(prefcmp, -1, +1) {
				int cmp = combinecmp(prefcmp, cmpchar(j - 1, j));
				inc(prefsubdp[j][cmp + 1], prefsubdp[j - 1][prefcmp + 1]);
			}
			if (j < blen) { // remove b[j]
				int cmp = prefixcmp[j];
				inc(prefsubdp[j][cmp + 1], dpb[j]);
			}
		}
		for (int j = mxlen - 1; j >= 0; --j) {
			FORE(cmp, -1, +1) suffsubdp[j][cmp + 1] = 0;
			if (j + 1 < mxlen) FORE(suffcmp, -1, +1) {
				int cmp = combinecmp(cmpchar(j + 1, j), suffcmp);
				inc(suffsubdp[j][cmp + 1], suffsubdp[j + 1][suffcmp + 1]);
			}
			if (j < blen) { // remove b[j]
				int cmp = suffixcmp[j + 1][0 + 1];
				inc(suffsubdp[j][cmp + 1], dpb[j]);
			}
		}

		dpnorem[i] = 0;
		if (suffixcmp[0][0 + 1] <= 0) inc(dpnorem[i], dpnorem[i + 1]);
		REP(k, blen) {
			int cmp = combinecmp(prefixcmp[k], suffixcmp[k][+1 + 1]);
			if (cmp <= 0) inc(dpnorem[i], dpb[k]);
		}

		REP(j, alen) {
			dpa[j] = 0;
			FORE(prefcmp, -1, +1) {
				int cmp = combinecmp(prefcmp, suffixcmp[j + 1][0 + 1]);
				if (cmp <= 0) inc(dpa[j], prefsubdp[j][prefcmp + 1]);
			}
			FORE(suffcmp, -1, +1) {
				int cmp = combinecmp(prefixcmp[j], suffcmp);
				if (cmp <= 0) inc(dpa[j], suffsubdp[j][suffcmp + 1]);
			}
			if (j < blen) { // double-counted
				int cmp = combinecmp(prefixcmp[j], suffixcmp[j + 1][0 + 1]);
				if (cmp <= 0) dec(dpa[j], dpb[j]);
			}
			{
				int cmp = combinecmp(prefixcmp[j], suffixcmp[j + 1][-1 + 1]);
				if (cmp <= 0) inc(dpa[j], dpnorem[i + 1]);
			}
		}

		REP(j, alen)  dprem[offset[i] + j] = dpa[j];
	}
	int ret = 0; inc(ret, dpnorem[0]); REP(j, len[0]) inc(ret, dprem[offset[0] + j]); return ret;
}

void run() {
	scanf("%d", &n);
	offset[0] = 0; REP(i, n) { scanf("%s", s + offset[i]); len[i] = strlen(s + offset[i]); offset[i + 1] = offset[i] + len[i]; }
	printf("%d\n", solve());
}


int main() {
	run();
	return 0;
}