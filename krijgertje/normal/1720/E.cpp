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

const int MAXN = 500;

int n, want;
int a[MAXN][MAXN];

int cnt[MAXN * MAXN];

int lx[MAXN * MAXN], hx[MAXN * MAXN], ly[MAXN * MAXN], hy[MAXN * MAXN];
int remcnt[MAXN + 1][MAXN + 1];


int solve() {
	REP(i, n * n) cnt[i] = 0;
	REP(i, n) REP(j, n) ++cnt[a[i][j]];
	int have = 0;
	REP(i, n * n) if (cnt[i] >= 1) ++have;
	if (have <= want) return want - have;

	REP(i, n * n) lx[i] = INT_MAX, hx[i] = INT_MIN, ly[i] = INT_MAX, hy[i] = INT_MIN;
	REP(x, n) REP(y, n) { int v = a[x][y]; lx[v] = min(lx[v], x); hx[v] = max(hx[v], x); ly[v] = min(ly[v], y); hy[v] = max(hy[v], y); }
	FORE(sz, 1, n) {
		REPE(x, n) REPE(y, n) remcnt[x][y] = 0;
		REP(v, n * n) if (cnt[v] >= 1) {
			// x<=lx[v] hx[v]<=x+sz-1 -> hx[v]-sz+1<=x<=lx[v]
			int sx = max(0, hx[v] - sz + 1), tx = lx[v] + 1;
			int sy = max(0, hy[v] - sz + 1), ty = ly[v] + 1;
			if (sx < tx && sy < ty) ++remcnt[sx][sy], --remcnt[sx][ty], --remcnt[tx][sy], ++remcnt[tx][ty];
		}
		REPE(x, n) REP(y, n) remcnt[x][y + 1] += remcnt[x][y];
		REPE(y, n) REP(x, n) remcnt[x + 1][y] += remcnt[x][y];
		REPE(x, n - sz) REPE(y, n - sz) if (have - remcnt[x][y] >= want - 1 && have - remcnt[x][y] <= want) return 1;
	}
	return 2;
}

void run() {
	scanf("%d%d", &n, &want);
	REP(i, n) REP(j, n) scanf("%d", &a[i][j]), --a[i][j];
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}