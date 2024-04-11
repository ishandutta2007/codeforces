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

const int MAXN = 21;
const int MOD = 31607;
const int DEN = 10000;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }
void dec(int& a, int b) { inc(a, MOD - b); }

int n;
int a[MAXN][MAXN];

int inv[MOD];

int pcell[MAXN][MAXN];
int pcol[MAXN];
int prow[MAXN];

int bcnt[1 << (MAXN + 2)];
int pmask[1 << (MAXN + 2)];
int pcond[1 << (MAXN + 2)];

int bal[1 << (MAXN + 2)];


int solve() {
	inv[1] = 1; FOR(i, 2, MOD) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
	REP(i, n) REP(j, n) pcell[i][j] = a[i][j] * inv[DEN] % MOD;
	REP(j, n) { pcol[j] = 1; REP(i, n) pcol[j] = pcol[j] * pcell[i][j] % MOD; }
	REP(i, n) { prow[i] = 1; REP(j, n) prow[i] = prow[i] * pcell[i][j] % MOD; }

	bcnt[0] = 0; FOR(mask, 1, 1 << (n + 2)) bcnt[mask] = bcnt[mask >> 1] + (mask & 1);
	REP(mask, 1 << (n + 2)) {
		pmask[mask] = 1;
		REP(j, n) if (mask & (1 << j)) pmask[mask] = pmask[mask] * pcol[j] % MOD;
		if (mask & (1 << (n + 0))) REP(i, n) if ((mask & (1 << i)) == 0) pmask[mask] = pmask[mask] * pcell[i][i] % MOD;
		if (mask & (1 << (n + 1))) REP(i, n) if ((mask & (1 << (n - i - 1))) == 0 && (n - i - 1 != i || (mask & (1 << (n + 0))) == 0)) pmask[mask] = pmask[mask] * pcell[i][n - i - 1] % MOD;
	}
	REP(mask, 1 << (n + 2)) bal[mask] = pmask[mask];
	//REP(mask, 1 << (n + 2)) printf("pmask[%x]=%d\n", mask, 16 * pmask[mask] % MOD);
	REP(i, n) {
		pcond[0] = prow[i];
		REP(bit, n + 2) {
			REP(mask, 1 << bit) {
				int cur = pcond[mask];
				if (bit == n + 0) {
					if ((mask & (1 << i)) == 0) cur = cur * inv[pcell[i][i]] % MOD;
				} else if (bit == n + 1) {
					if ((mask & (1 << (n - i - 1))) == 0 && (n - i - 1 != i || (mask & (1 << (n + 0))) == 0)) cur = cur * inv[pcell[i][n - i - 1]] % MOD;
				} else {
					cur = cur * inv[pcell[i][bit]] % MOD;
				}
				pcond[mask | (1 << bit)] = cur;
			}
		}
		//printf("row %d:\n", i); REP(mask, 1 << (n + 2)) printf("pcond[%x]=%d\n", mask, 16 * pcond[mask] % MOD);
		REP(mask, 1 << (n + 2)) {
			int p = pcond[mask];
			bal[mask] = bal[mask] * (MOD + 1 - p) % MOD;
		}
	}
	int plose = 0;
	REP(mask,1<<(n+2)) {
		int cnt = bcnt[mask];
		//printf("bal[%x]=%d (cnt=%d)\n", mask, 16 * bal[mask] % MOD, cnt);
		if (cnt % 2 == 0) inc(plose, bal[mask]); else dec(plose, bal[mask]);
	}
	return (MOD + 1 - plose) % MOD;
}

void run() {
	scanf("%d", &n);
	REP(i, n) REP(j, n) scanf("%d", &a[i][j]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}