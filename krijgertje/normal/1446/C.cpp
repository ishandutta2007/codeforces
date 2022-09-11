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

int n;
int a[MAXN];

int layer[MAXN];
int mxlayer;
vector<int> cnt;

int rec(int l, int r) {
	if (l == r) return 0;
	int diff = a[l] ^ a[r];
	int bit = 0; while ((2LL << bit) <= diff) ++bit;
	int m = l; while (((a[m] >> bit) & 1) == 0) ++m;
	int nl = m - l, nr = r - m + 1;
	//printf("l=%d r=%d diff=%d bit=%d m=%d nl=%d nr=%d\n", l, r, diff, bit, m, nl, nr);
	assert(nl >= 1 && nr >= 1);
	return min(nl - 1 + rec(m, r), rec(l, m - 1) + nr - 1);
}

int solve() {
	sort(a, a + n);
	//printf("a:"); REP(i, n) printf(" %d", a[i]); puts("");
	REP(i, n) if (a[i] == 0) layer[i] = 0; else { int bit = 0; while ((2LL << bit) <= a[i]) ++bit; layer[i] = bit + 1; }
	mxlayer = layer[0]; FOR(i, 1, n) mxlayer = max(mxlayer, layer[i]);
	cnt = vector<int>(mxlayer + 1, 0);
	REP(i, n) ++cnt[layer[i]];
	int ret = 0;
	REPE(i, mxlayer) ret += max(0, cnt[i] - 1);
	int at = 0;
	REPE(x, mxlayer) { // x is a layer with multiple remaining nodes
		int to = at; while (to < n && layer[to] == x) ++to;
		if (cnt[x] >= 2) {
			int part1 = 0, part2 = 0, part3 = 0;
			REP(i, x) part1 += cnt[i];
			part1 = max(0, part1 - 1);
			FORE(i, x + 1, mxlayer) part2 += max(0, cnt[i] - 1);
			part3 += rec(at, to - 1);
			ret = min(ret, part1 + part2 + part3);
		}
		at = to;
	}
	return ret;
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