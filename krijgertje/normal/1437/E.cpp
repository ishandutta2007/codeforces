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

const int MAXN = 500000;

int n, nfix;
int a[MAXN];
int fix[MAXN];

int b[MAXN + 2];

int lis[MAXN + 2], nlis;

int calc(int l, int r) {
	//printf("calc:"); FORE(i, l, r) printf(" %d", b[i]); puts("");
	nlis = 0;
	lis[nlis++] = b[l];
	int len = r - l + 1;
	FORE(i, l + 1, r) if (b[i] >= b[l]) {
		int lo = 0, hi = nlis;
		while (lo + 1 < hi) {
			int mi = lo + (hi - lo) / 2;
			if (b[i] >= lis[mi]) lo = mi; else hi = mi;
		}
		int idx = lo;
		lis[idx + 1] = b[i];
		if (idx == nlis - 1) ++nlis;
		if (i == r) return len - (idx + 2);
	}
	assert(false); return -1;
}

int solve() {
	b[0] = INT_MIN; REP(i, n) b[i + 1] = a[i] - i; b[n + 1] = INT_MAX;
	FOR(i, 1, nfix) { int x = fix[i - 1] + 1, y = fix[i] + 1; if (b[x] > b[y]) return -1; }
	int ret = 0;
	REPE(i, nfix) {
		int l = i == 0 ? 0 : fix[i - 1] + 1;
		int r = i == nfix ? n + 1 : fix[i] + 1;
		ret += calc(l, r);
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &nfix);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, nfix) scanf("%d", &fix[i]), --fix[i];
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}