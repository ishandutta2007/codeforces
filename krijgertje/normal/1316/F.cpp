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
typedef long long ll;  
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MOD = 1000000007;
const int MAXN = 300000;
const int MAXQ = 300000;
const int MAXZ = MAXN + MAXQ;
const int MAXS = 4 * MAXZ;
const int INV2 = (MOD + 1) / 2;
struct SVal {
	int cnt;
	int prefsum;
	int suffsum;
	int prodsum;
};

int n;
int ival[MAXN];
int nq;
int qidx[MAXQ], qval[MAXN];
int ans[MAXQ + 1];

pair<int, int> z[MAXZ]; int nz;
int iz[MAXN], qz[MAXQ], cz[MAXN];

SVal sval[MAXS];
int halfpw[MAXZ + 1];

void spull(int x) {
	sval[x].cnt = sval[2 * x + 1].cnt + sval[2 * x + 2].cnt;
	sval[x].prefsum = (sval[2 * x + 1].prefsum + (ll)halfpw[sval[2 * x + 1].cnt] * sval[2 * x + 2].prefsum) % MOD;
	sval[x].suffsum = (sval[2 * x + 2].suffsum + (ll)halfpw[sval[2 * x + 2].cnt] * sval[2 * x + 1].suffsum) % MOD;
	sval[x].prodsum = (sval[2 * x + 1].prodsum + sval[2 * x + 2].prodsum + (ll)sval[2 * x + 1].suffsum*sval[2 * x + 2].prefsum) % MOD;
}
void sinit(int x, int l, int r) {
	if (l == r) {
		sval[x].prefsum = sval[x].suffsum = sval[x].prodsum = 0, sval[x].cnt = 0;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m); sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void sset(int x, int l, int r, int IDX, int VAL) {
	if (l == r) {
		sval[x].prefsum = sval[x].suffsum = VAL; sval[x].cnt = VAL == 0 ? 0 : 1;
	} else {
		int m = l + (r - l) / 2;
		if (IDX <= m) sset(2 * x + 1, l, m, IDX, VAL); else sset(2 * x + 2, m + 1, r, IDX, VAL);
		spull(x);
	}
	//printf("setting %d to %d: after [%d,%d] -> (cnt=%d,prefsum=%d,suffsum=%d,prodsum=%d)\n", IDX, VAL, l, r, sval[x].cnt, sval[x].prefsum, sval[x].suffsum, sval[x].prodsum);
}


void solve() {
	nz = 0;
	REP(i, n) z[nz++] = MP(ival[i], i); REP(i, nq) z[nz++] = MP(qval[i], n + i); sort(z, z + nz);
	REP(i, nz) if (z[i].second < n) iz[z[i].second] = i; else qz[z[i].second - n] = i;
	halfpw[0] = 1; FORE(i, 1, nz) halfpw[i] = (ll)halfpw[i - 1] * INV2%MOD;
	REP(i, n) cz[i] = iz[i];

	sinit(0, 0, nz - 1);
	REP(i, n) sset(0, 0, nz - 1, cz[i], ival[i]);

	ans[0] = sval[0].prodsum;
	REP(i, nq) {
		int idx = qidx[i], val = qval[i];
		sset(0, 0, nz - 1, cz[idx], 0);
		cz[idx] = qz[i];
		sset(0, 0, nz - 1, cz[idx], val);
		ans[i + 1] = sval[0].prodsum;
	}

	REPE(i, nq) ans[i] = (ll)ans[i] * INV2%MOD*INV2%MOD;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &ival[i]);
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d", &qidx[i], &qval[i]), --qidx[i];
	solve();
	REPE(i, nq) printf("%d\n", ans[i]);
}

int main() {
	run();
	return 0;
}