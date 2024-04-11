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

const int MAXN = 250000;
const int MAXLG = 17;

int n;
int a[MAXN];

int nxtlower[MAXN];
int nxthigher[MAXN];
int stck[MAXN], nstck;

int mxidx[MAXN][MAXLG + 1];
int mnidx[MAXN][MAXLG + 1];

int solve() {
	nstck = 0;
	for (int i = n - 1; i >= 0; --i) {
		while (nstck > 0 && a[stck[nstck - 1]] >= a[i]) --nstck;
		nxtlower[i] = nstck == 0 ? n : stck[nstck - 1];
		stck[nstck++] = i;
	}
	nstck = 0;
	for (int i = n - 1; i >= 0; --i) {
		while (nstck > 0 && a[stck[nstck - 1]] <= a[i]) --nstck;
		nxthigher[i] = nstck == 0 ? n : stck[nstck - 1];
		stck[nstck++] = i;
	}
	REP(i, n) mxidx[i][0] = mnidx[i][0] = i;
	REP(k, MAXLG) REPE(i, n - (2 << k)) mxidx[i][k + 1] = a[mxidx[i][k]] > a[mxidx[i + (1 << k)][k]] ? mxidx[i][k] : mxidx[i + (1 << k)][k];
	REP(k, MAXLG) REPE(i, n - (2 << k)) mnidx[i][k + 1] = a[mnidx[i][k]] < a[mnidx[i + (1 << k)][k]] ? mnidx[i][k] : mnidx[i + (1 << k)][k];

	int ret = 0;
	int at = 0;
	while (at < n - 1) {
		int pos = at;
		int to = at;
		if (a[at] < a[at + 1]) {
			int lim = nxtlower[at];
			for (int k = MAXLG; k >= 0; --k) if (pos + (1 << k) <= lim) {  if (a[mxidx[pos][k]] > a[to]) to = mxidx[pos][k]; pos += 1 << k; }
		} else {
			int lim = nxthigher[at];
			for (int k = MAXLG; k >= 0; --k) if (pos + (1 << k) <= lim) { if (a[mnidx[pos][k]] < a[to]) to = mnidx[pos][k]; pos += 1 << k; }
		}
		at = to, ++ret;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}