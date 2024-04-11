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

int n;
int a[MAXN];
int ans[MAXN];

int b[MAXN], nb;
vector<int> palsuffixes[MAXN];
int shortestpal[MAXN];
vector<int> shortestpalends[MAXN];


void solve() {
	nb = 0;
	int sofar = 0;
	REP(i, n) {
		int x = a[i];
		if (nb - 1 >= 0) {
			REPSZ(j, palsuffixes[nb - 1]) {
				int plen = palsuffixes[nb - 1][j];
				if (nb - plen - 1 >= 0 && b[nb - plen - 1] == x) palsuffixes[nb].PB(plen + 2);
			}
			if (b[nb - 1] == x) palsuffixes[nb].PB(2);
		}
		b[nb++] = x;
		//printf("%d:", x); REPSZ(j, palsuffixes[nb - 1]) printf(" %d", palsuffixes[nb - 1][j]); puts("");
		shortestpal[nb - 1] = -1;
		REPSZ(j, palsuffixes[nb - 1]) {
			int len = palsuffixes[nb - 1][j];
			if (shortestpal[nb - len] == -1) shortestpal[nb - len] = len, shortestpalends[nb - 1].PB(nb - len);
		}
		if (SZ(palsuffixes[nb - 1]) >= 1) {
			int mnlen = palsuffixes[nb - 1].back();
			int pidx = nb - mnlen / 2 - 1; bool found = false; REPSZ(j, palsuffixes[pidx]) if (palsuffixes[pidx][j] == mnlen) found = true;
			if (found) {
				//printf("found XYX sequence of length %d -> removing last %d\n", mnlen / 2 * 3, mnlen);
				sofar += 2;
				REP(j, mnlen) {
					--nb;
					palsuffixes[nb].clear();
					REPSZ(k, shortestpalends[nb]) { int idx = shortestpalends[nb][k]; assert(shortestpal[idx] == nb - idx + 1); shortestpal[idx] = -1; }
					shortestpalends[nb].clear();
				}
			}
		}
		ans[i] = sofar;
		int prefrem = 0;
		{ int at = 0; while (shortestpal[at] != -1) ++ans[i], prefrem += shortestpal[at] / 2, at += shortestpal[at] / 2; }
		{ int at = nb - 1; while (SZ(palsuffixes[at]) >= 1) { int len = palsuffixes[at].back(); if (at + 1 - prefrem < len) break; ++ans[i], at -= len / 2; } }
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}