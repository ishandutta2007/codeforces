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

const int MAXN = 1000;

int n, k;
int ans[MAXN][MAXN];

int solve() {
	int sz = 1;
	REP(i, n) REP(j, n) ans[i][j] = -1;
	for (int col = 0;; ++col) {
		if (sz >= n) return col;
		for (int offset = 0; offset < n; offset += k * sz) {
			int cnt = min(k * sz, n - offset);
			REP(a, cnt) FOR(b, a + 1, cnt) if (a / sz != b / sz) {
				assert(ans[offset + a][offset + b] == -1);
				ans[offset + a][offset + b] = col;
			}
		}
		sz = min(n, sz * k);
	}
}

void run() {
	scanf("%d%d", &n, &k);
	printf("%d\n", solve());
	REP(i, n) FOR(j, i + 1, n) { if (i != 0 || j != 1) printf(" "); printf("%d", ans[i][j] + 1); } puts("");
}

int main() {
	run();
	return 0;
}