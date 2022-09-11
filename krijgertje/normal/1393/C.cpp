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

int b[MAXN], nb;
int bmx, bmxcnt;

bool can(int dist) {
	int lim = 1 + (n - 1) / (dist + 1);
	int limcnt = n - (lim - 1) * (dist + 1);
	if (bmx > lim) return false;
	if (bmx == lim && bmxcnt > limcnt) return false;
	return true;
}

int solve() {
	sort(a, a + n);
	nb = 0; for (int l = 0, r = l; l < n; l = r) { while (r < n && a[r] == a[l]) ++r; b[nb++] = r - l; }
	sort(b, b + nb);
	bmx = b[nb - 1]; bmxcnt = 0; REP(i, nb) if (b[i] == bmx) ++bmxcnt;
	int lo = 0, hi = n;
	while (lo + 1 < hi) {
		int mi = lo + (hi - lo) / 2;
		if (can(mi)) lo = mi; else hi = mi;
	}
	return lo;
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}