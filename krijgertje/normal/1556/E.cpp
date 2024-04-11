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
const int MAXQ = 100000;
const int MAXLG = 17;

int n, nq;
int a[MAXN];
int b[MAXN];
int ql[MAXQ], qr[MAXQ];
ll qans[MAXQ];

int c[MAXN];
ll csum[MAXN + 1];


ll mx[MAXN + 1][MAXLG + 1];
ll mn[MAXN + 1][MAXLG + 1];

void solve() {
	REP(i, n) c[i] = b[i] - a[i];
	csum[0] = 0; REP(i, n) csum[i + 1] = csum[i] + c[i];
	//printf("csum:"); REPE(i, n) printf(" %lld", csum[i]); puts("");

	REPE(i, n) mx[i][0] = mn[i][0] = csum[i];
	REP(k, MAXLG) REPE(i, n) if (i + (2 << k) - 1 <= n) mx[i][k + 1] = max(mx[i][k], mx[i + (1 << k)][k]), mn[i][k + 1] = min(mn[i][k], mn[i + (1 << k)][k]);

	REP(i, nq) {
		int l = ql[i], r = qr[i] + 1;
		if (csum[l] != csum[r]) { qans[i] = -1; continue; }
		int k = 0; while (l + (2 << k) - 1 <= r) ++k;
		ll cmn = min(mn[l][k], mn[r - (1 << k) + 1][k]);
		ll cmx = max(mx[l][k], mx[r - (1 << k) + 1][k]);
		if (cmn < csum[l]) { qans[i] = -1; continue; }
		qans[i] = cmx - csum[l];
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, n) scanf("%d", &b[i]);
	REP(i, nq) scanf("%d%d", &ql[i], &qr[i]), --ql[i], --qr[i];
	solve();
	REP(i, nq) printf("%lld\n", qans[i]);
}

int main() {
	run();
	return 0;
}