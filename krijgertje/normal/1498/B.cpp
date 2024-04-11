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

int n, w;
int a[MAXN];

bool can(int h) {
	int at = 0;
	int cnt = 0;
	for (int bit = 0; (1 << bit) <= w; ++bit) {
		while (at < n && a[at] == (1 << bit)) ++cnt, ++at;
		//printf("h=%d bit=%d cnt=%d\n", h, bit, cnt);
		if (w & (1 << bit)) cnt = max(0, cnt - h);
		cnt = (cnt + 1) / 2;
	}
	return cnt == 0;
}

int solve() {
	sort(a, a + n);
	int lo = 0, hi = n;
	while (lo + 1 < hi) {
		int mi = lo + (hi - lo) / 2;
		if (can(mi)) hi = mi; else lo = mi;
	}
	return hi;
}

void run() {
	scanf("%d%d", &n, &w);
	REP(i, n) scanf("%d", &a[i]);
	printf("%d\n", solve());
}


int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}