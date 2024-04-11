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

const int MAXN = 300000;
const int MAXS = 4 * MAXN;

int n;
int val[MAXN];
int kill[MAXN];
int ans[MAXN];

int pos[MAXN];
int alive;

int slazy[MAXS];
int sval[MAXS];

void sapply(int x, int by) { slazy[x] += by; if (sval[x] != INT_MAX) sval[x] += by; }
void spush(int x) { if (slazy[x] != 0) sapply(2 * x + 1, slazy[x]), sapply(2 * x + 2, slazy[x]), slazy[x] = 0; }
void spull(int x) { sval[x] = min(sval[2 * x + 1], sval[2 * x + 2]); }
void sinit(int x, int l, int r) {
	slazy[x] = 0;
	if (l == r) {
		sval[x] = INT_MAX;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m); sinit(2 * x + 2, m + 1, r);
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
void sactivate(int x, int l, int r, int IDX) {
	if (l == r) {
		sval[x] = slazy[x];
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (IDX <= m) sactivate(2 * x + 1, l, m, IDX); else sactivate(2 * x + 2, m + 1, r, IDX);
		spull(x);
	}
}




void solve() {
	sinit(0, 0, n - 1);
	REP(i, n) pos[val[i]] = i;

	int alive = n;
	REP(i, n) {
		while (sval[0] >= 0) {
			assert(alive >= 0);
			int idx = pos[--alive];
			sactivate(0, 0, n - 1, idx);
			smod(0, 0, n - 1, 0, idx, -1);
		}
		ans[i] = alive;
		smod(0, 0, n - 1, 0, kill[i], +1);
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &val[i]), --val[i];
	REP(i, n) scanf("%d", &kill[i]), --kill[i];
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}