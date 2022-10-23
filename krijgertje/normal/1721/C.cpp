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

const int MAXN = 200000;

int n;
int a[MAXN];
int b[MAXN];
int lo[MAXN];
int hi[MAXN];

void solve() {
	int ai = 0, bi = 0, at = 0;
	while (ai < n) {
		while (bi < n && a[ai] > b[bi]) ++bi;
		if (ai == bi) while (at < ai) hi[at] = b[bi - 1] - a[at], ++at;
		assert(bi < n);
		lo[ai] = b[bi] - a[ai];
		++ai;
	}
	while (at < ai) hi[at] = b[n - 1] - a[at], ++at;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, n) scanf("%d", &b[i]);
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", lo[i]); } puts("");
	REP(i, n) { if (i != 0) printf(" "); printf("%d", hi[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}