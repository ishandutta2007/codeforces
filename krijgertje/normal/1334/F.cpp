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

const int MAXN = 500000 + 1;
const int MAXS = 4 * MAXN;

int na;
int a[MAXN];
int cost[MAXN];
int nb;
int b[MAXN];

vector<int> apos[MAXN];
ll dp[MAXN];


ll slazy[MAXS], sactive[MAXS];

void sapply(int x, ll by) { slazy[x] += by; if (sactive[x] != LLONG_MAX) sactive[x] += by; }
void spush(int x) { if (slazy[x] != 0) sapply(2 * x + 1, slazy[x]), sapply(2 * x + 2, slazy[x]), slazy[x] = 0; }
void spull(int x) { sactive[x] = min(sactive[2 * x + 1], sactive[2 * x + 2]); }
void sinit(int x, int l, int r) {
	slazy[x] = 0;
	if (l == r) {
		sactive[x] = LLONG_MAX;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m); sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
ll sget(int x, int l, int r, int IDX) {
	//if (x == 0) printf("sget(%d)", IDX);
	if (l == r) {
		return slazy[x];
	} else {
		int m = l + (r - l) / 2; spush(x);
		ll ret = IDX <= m ? sget(2 * x + 1, l, m, IDX) : sget(2 * x + 2, m + 1, r, IDX);
		//if (x == 0) printf("=%lld\n", ret);
		return ret;
	}
}
ll sgetactive(int x, int l, int r, int L, int R) {
	//if (x == 0) printf("sgetactive(%d..%d)\n", L, R);
	if (L <= l && r <= R) {
		return sactive[x];
	} else {
		int m = l + (r - l) / 2; spush(x); ll ret = LLONG_MAX;
		if (L <= m) ret = min(ret, sgetactive(2 * x + 1, l, m, L, R));
		if (m + 1 <= R) ret = min(ret, sgetactive(2 * x + 2, m + 1, r, L, R));
		return ret;
	}
}
void sactivate(int x, int l, int r, int IDX, ll VAL) {
	//if (x == 0) printf("sactivate(%d with %lld)\n", IDX, VAL);
	if (l == r) {
		sactive[x] = slazy[x] + VAL;
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (IDX <= m) sactivate(2 * x + 1, l, m, IDX, VAL); else sactivate(2 * x + 2, m + 1, r, IDX, VAL);
		spull(x);
	}
}
void sdeactivate(int x, int l, int r, int IDX) {
	//if (x == 0) printf("sdeactivate(%d)\n", IDX);
	if (l == r) {
		sactive[x] = LLONG_MAX;
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (IDX <= m) sdeactivate(2 * x + 1, l, m, IDX); else sdeactivate(2 * x + 2, m + 1, r, IDX);
		spull(x);
	}
}
void smod(int x, int l, int r, int L, int R, ll BY) {
	//if (x == 0) printf("smod(%d..%d,%lld)\n", L, R, BY);
	if (L <= l && r <= R) {
		sapply(x, BY);
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (L <= m) smod(2 * x + 1, l, m, L, R, BY);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, BY);
		spull(x);
	}
}


ll solve() {
	a[na] = na, cost[na] = 0, b[nb++] = na, ++na;
	REP(i, na) apos[i].clear();
	REP(i, na) apos[a[i]].PB(i);
	sinit(0, 0, na - 1);
	REP(i, na - 1) smod(0, 0, na - 1, i + 1, na - 1, -cost[i]);
	int at = 0;
	REP(i, nb) {
		int v = b[i];
		//printf("processing %d\n", v + 1);
		if (i == 0) {
			REPSZ(i, apos[v]) { int idx = apos[v][i]; ll cur = -sget(0, 0, na - 1, idx); dp[idx] = cur; }
		} else {
			int pv = b[i - 1];
			REPSZ(i, apos[pv]) { int idx = apos[pv][i]; if (dp[idx] != LLONG_MAX) sactivate(0, 0, na - 1, idx, dp[idx] - (cost[idx] < 0 ? cost[idx] : 0)); }
			REPSZ(i, apos[v]) { int idx = apos[v][i]; ll cur = sgetactive(0, 0, na - 1, 0, idx); if (cur != LLONG_MAX) cur -= sget(0, 0, na - 1, idx); dp[idx] = cur; }
			REPSZ(i, apos[pv]) { int idx = apos[pv][i]; if (dp[idx] != LLONG_MAX) sdeactivate(0, 0, na - 1, idx); }
		}
		//REPSZ(i, apos[v]) { int idx = apos[v][i]; printf("dp[%d]=%lld\n", idx, dp[idx]); }
		while (at <= v) { REPSZ(i, apos[at]) { int idx = apos[at][i]; if (cost[idx] >= 0 && idx != na - 1) smod(0, 0, na - 1, idx + 1, na - 1, +cost[idx]); } ++at; }
	}
	ll ret = LLONG_MAX; REPSZ(i, apos[b[nb - 1]]) { int idx = apos[b[nb - 1]][i]; ret = min(ret, dp[idx]); } return ret;
}


void run() {
	scanf("%d", &na);
	REP(i, na) scanf("%d", &a[i]), --a[i];
	REP(i, na) scanf("%d", &cost[i]);
	scanf("%d", &nb);
	REP(i, nb) scanf("%d", &b[i]), --b[i];
	ll ans = solve();
	if (ans == LLONG_MAX) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%lld\n", ans);
}

int main() {
	run();
	return 0;
}