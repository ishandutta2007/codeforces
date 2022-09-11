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

const int MAXN = 200000 - 1;
const int MAXS = 4 * MAXN;

int n;
int a[MAXN];

int ainv[MAXN];

int sval[MAXS];
int slazy[MAXS];

void sapply(int x, int by) { slazy[x] += by; if (sval[x] != INT_MIN) sval[x] += by; }
void spush(int x) { if (slazy[x] != 0) sapply(2 * x + 1, slazy[x]), sapply(2 * x + 2, slazy[x]), slazy[x] = 0; }
void spull(int x) { sval[x] = max(sval[2 * x + 1], sval[2 * x + 2]); }
void sinit(int x, int l, int r) {
	slazy[x] = 0;
	if (l == r) {
		sval[x] = INT_MIN;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void smod(int x, int l, int r,int L,int R,int BY) {
	if (L <= l && r <= R) {
		sapply(x, BY);
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (L <= m) smod(2 * x + 1, l, m, L, R, BY);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, BY);
		spull(x);
	}
}
void stoggle(int x, int l, int r, int IDX) {
	if (l == r) {
		sval[x] = l + (l % 2 == 0 ? 1 : 0) + slazy[x];
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (IDX <= m) stoggle(2 * x + 1, l, m, IDX); else stoggle(2 * x + 2, m + 1, r, IDX);
		spull(x);
	}
}
int sget(int x, int l, int r,int L, int R) {
	if (L <= l && r <= R) {
		return sval[x];
	} else {
		int m = l + (r - l) / 2; spush(x); int ret = INT_MIN;
		if (L <= m) ret = max(ret, sget(2 * x + 1, l, m, L, R));
		if (m + 1 <= R) ret = max(ret, sget(2 * x + 2, m + 1, r, L, R));
		spull(x); return ret;
	}
}



int solve() {
	int ret = 0;
	/*FORE(i, 1, n - 1) {
		vector<int> pos;
		REP(j, n) if (a[j] < i) pos.PB(j);
		int cur = 0;
		REPSZ(j, pos) if (pos[j] > j) cur = max(cur, pos[j] - 2 * j + (pos[j] % 2 == 0 ? 1 : 0) + i - 1);
		ret = max(ret, cur);
		printf("%d: %d\n", i, cur);
	}*/
	REP(i, n) ainv[a[i]] = i;
	int pref = 0;
	sinit(0, 0, n - 1);
	FORE(i, 1, n - 1) {
		int pos = ainv[i - 1];
		stoggle(0, 0, n - 1, pos);
		if (pos != n - 1) smod(0, 0, n - 1, pos + 1, n - 1, -2);
		while (pref < n && a[pref] < i) ++pref;
		int cur = 0;
		if (pref < n) {
			int mx = sget(0, 0, n - 1, pref, n - 1);
			if (mx != INT_MIN) cur = mx + i - 1;
		}
		ret = max(ret, cur);
		//printf("%d: %d\n", i, cur);
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}