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

const int MAXN = 100000;
const int MAXS = 4 * MAXN;

int n, init;
int a[MAXN];

char ans[MAXN + 1];

int nalive;
bool alive[MAXN];

int smn[MAXS], smnidx[MAXS];
int slazy[MAXS];
void sapply(int x, int by) {
	if (smn[x] != INT_MAX) smn[x] += by;
	slazy[x] += by;
}
void spush(int x) {
	if (slazy[x] != 0) sapply(2 * x + 1, slazy[x]), sapply(2 * x + 2, slazy[x]), slazy[x] = 0;
}
void spull(int x) {
	smn[x] = min(smn[2 * x + 1], smn[2 * x + 2]);
	smnidx[x] = smn[2 * x + 1] == smn[x] ? smnidx[2 * x + 1] : smnidx[2 * x + 2];
}
void sinit(int x, int l, int r) {
	slazy[x] = 0;
	if (l == r) {
		if (a[l] <= init) {
			smn[x] = init - a[l];
		} else {
			smn[x] = INT_MAX;
		}
		smnidx[x] = l;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void sdec(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		sapply(x, -1);
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (L <= m) sdec(2 * x + 1, l, m, L, R);
		if (m + 1 <= R) sdec(2 * x + 2, m + 1, r, L, R);
		spull(x);
	}
}
void skill(int x, int l, int r, int IDX) {
	if (l == r) {
		smn[x] = INT_MAX;
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (IDX <= m) skill(2 * x + 1, l, m, IDX); else skill(2 * x + 2, m + 1, r, IDX);
		spull(x);
	}
}


void solve() {
	sinit(0, 0, n - 1);
	REP(i, n) alive[i] = a[i] <= init;
	nalive = 0;
	REP(i, n) if (alive[i]) ++nalive;
	int best = nalive, bestfirst = n;
	set<int> pos;
	int at = n - 1;
	for (int i = n - 1; i >= 0; --i) {
		if (a[i] <= init) { assert(alive[i]); continue; }
		assert(!alive[i]);
		alive[i] = true, ++nalive;
		pos.insert(i);
		if (i + 1 <= n - 1) sdec(0, 0, n - 1, i + 1, n - 1);
		while (smn[0] < 0) {
			int idx = smnidx[0];
			assert(idx < n);
			//printf("idx=%d\n", idx);
			skill(0, 0, n - 1, idx);
			pos.insert(idx);
			if (idx + 1 <= n - 1) sdec(0, 0, n - 1, idx + 1, n - 1);
		}
		while (SZ(pos) > init) pos.erase(prev(pos.end()));
		if (SZ(pos) == init) {
			int last = *prev(pos.end());
			while (at > last) {
				if (alive[at]) alive[at] = false, --nalive;
				--at;
			}
		}
		if (nalive > best) best = nalive, bestfirst = i;
	}
	{
		int cur = init;
		REP(i, n) {
			if (cur > 0 && (cur >= a[i] || i >= bestfirst)) {
				ans[i] = '1';
				if (a[i] > cur) --cur;
			} else {
				ans[i] = '0';
			}
		}
		ans[n] = '\0';
	}
}

void run() {
	scanf("%d%d", &n, &init);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	printf("%s\n", ans);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}