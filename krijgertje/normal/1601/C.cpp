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

const int MAXN = 1000000;
const int MAXS = 4 * (MAXN + 1);

int na, nb;
int a[MAXN];
int b[MAXN];

int v[2 * MAXN], nv;

int sval[MAXS];
int slazy[MAXS];

void sapply(int x, int by) { sval[x] += by; slazy[x] += by; }
void spush(int x) { if (slazy[x] != 0) sapply(2 * x + 1, slazy[x]), sapply(2 * x + 2, slazy[x]), slazy[x] = 0; }
void spull(int x) { sval[x] = min(sval[2 * x + 1], sval[2 * x + 2]); }
void sinit(int x, int l, int r) {
	slazy[x] = 0;
	if (l == r) {
		sval[x] = 0;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m); sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void smod(int x, int l, int r, int L, int R, int BY) {
	//if (x == 0) printf("smod(%d..%d with %d)\n", L, R, BY);
	if (L <= l && r <= R) {
		sapply(x, BY);
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (L <= m) smod(2 * x + 1, l, m, L, R, BY);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, BY);
		spull(x);
	}
}
int sget(int x, int l, int r, int IDX) {
	if (l == r) {
		return sval[x];
	} else {
		int m = l + (r - l) / 2; spush(x);
		int ret = IDX <= m ? sget(2 * x + 1, l, m, IDX) : sget(2 * x + 2, m + 1, r, IDX);
		spull(x);
		return ret;
	}
}



ll solve() {
	nv = 0; REP(i, na) v[nv++] = a[i]; REP(i, nb) v[nv++] = b[i];
	sort(v, v + nv); nv = unique(v, v + nv) - v;
	REP(i, na) a[i] = lower_bound(v, v + nv, a[i]) - v; REP(i, nb) b[i] = lower_bound(v, v + nv, b[i]) - v;

	sort(b, b + nb);
	vector<vector<int>> pos(nv);
	REP(i, na) pos[a[i]].PB(i);
	sinit(0, 0, na);
	REP(i, na) smod(0, 0, na, i + 1, na, +1);

	int at = 0;
	ll acost = 0;
	ll bcost = 0;
	REP(i, nv) {
		if (i - 1 >= 0) for (int idx : pos[i - 1]) smod(0, 0, na, 0, idx, +1);
		for (int idx : pos[i]) smod(0, 0, na, idx + 1, na, -1);
		for (int idx : pos[i]) acost += sget(0, 0, na, idx);
		while (at < nb && b[at] == i) bcost += sval[0], ++at;
	}
	assert(acost % 2 == 0); acost /= 2;
	return acost + bcost;
}

void run() {
	scanf("%d%d", &na, &nb);
	REP(i, na) scanf("%d", &a[i]);
	REP(i, nb) scanf("%d", &b[i]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}