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
const int MAXS = 4 * MAXN;

int n;
int a[MAXN];

int last[MAXN + 2];
bool have[MAXN + 3];

int sval[MAXS];
void spull(int x) { sval[x] = min(sval[2 * x + 1], sval[2 * x + 2]); }
void sinit(int x, int l, int r) {
	if (l == r) {
		sval[x] = -1;
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
int sget(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return sval[x];
	} else {
		int m = l + (r - l) / 2, ret = INT_MAX;
		if (L <= m) ret = min(ret, sget(2 * x + 1, l, m, L, R));
		if (m + 1 <= R) ret = min(ret, sget(2 * x + 2, m + 1, r, L, R));
		return ret;
	}
}
void sset(int x, int l, int r, int IDX, int VAL) {
	if (l == r) {
		sval[x] = VAL;
	} else {
		int m = l + (r - l) / 2;
		if (IDX <= m) sset(2 * x + 1, l, m, IDX, VAL); else sset(2 * x + 2, m + 1, r, IDX, VAL);
		spull(x);
	}
}


int solve() {
	REPE(i, n + 2) have[i] = false;

	REP(i, n) if (a[i] != 1) have[1] = true;

	REPE(i, n + 1) last[i] = -1;
	sinit(0, 1, n);
	REP(i, n) {
		if (a[i] != 1) {
			int prv = last[a[i]];
			int cur = sget(0, 1, n, 1, a[i] - 1);
			if (cur > prv) have[a[i]] = true;
		}
		sset(0, 1, n, a[i], i);
		last[a[i]] = i;
	}
	FORE(i, 2, n + 1) {
		int prv = last[i];
		int cur = sget(0, 1, n, 1, i - 1);
		if (cur > prv) have[i] = true;
	}
	
	int ret = 1; while (have[ret]) ++ret; return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}