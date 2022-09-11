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

int n, lim;
int a[MAXN];

int v[MAXN], nv;

int b[MAXN + 1];

bool can(int need) {
	b[0] = 0;
	REP(i, n) b[i + 1] = b[i] + (a[i] >= need ? 1 : -1);
	//printf("%d:", need); REPE(i, n) printf(" %d", b[i]); puts("");
	int mx = INT_MIN;
	for (int i = n - 1; i >= 0; --i) {
		if (i + lim <= n) mx = max(mx, b[i + lim]);
		if (mx >= b[i] + 1) return true;
	}
	return false;
}

int solve() {
	nv = 0; REP(i, n) v[nv++] = a[i]; sort(v, v + nv); nv = unique(v, v + nv) - v;
	int l = 0, r = nv;
	while (l + 1 < r) {
		int m = l + (r - l) / 2;
		if (can(v[m])) l = m; else r = m;
	}
	return v[l];
}

void run() {
	scanf("%d%d", &n, &lim);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}