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

const int MAXN = 250;

int n;
int a[2 * MAXN][2 * MAXN];

ll solve() {
	ll ret = 0;
	REP(i, n) REP(j, n) ret += a[n + i][n + j];
	int best = INT_MAX;
	REP(i, 2 * n) REP(j, 2 * n) {
		bool s = false, t = false;
		FORE(di, -1, +1) FORE(dj, -1, +1) if (di * di + dj * dj == 1) {
			int ni = i + di, nj = j + dj;
			if (ni < 0) ni += 2 * n; else if (ni >= 2 * n) ni -= 2 * n;
			if (nj < 0) nj += 2 * n; else if (nj >= 2 * n) nj -= 2 * n;
			if (0 <= ni && ni < n && 0 <= nj && nj < n) s = true;
			if (n <= ni && ni < 2 * n && n <= nj && nj < 2 * n) t = true;
		}
		if (s && t) best = min(best, a[i][j]);
	}
	//printf("best=%d\n", best);
	ret += best;
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, 2 * n) REP(j, 2 * n) scanf("%d", &a[i][j]);
	printf("%lld\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}