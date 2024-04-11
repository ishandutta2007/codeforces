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

const int MAXN = 100;

int n, k;
int have[MAXN][2];

int sol[2 * MAXN];

int prv[MAXN];

int solve() {
	REP(i, 2 * n) sol[i] = -1;
	REP(i, k) REP(j, 2) sol[have[i][j]] = i;
	int at = k;
	REP(i, 2 * n) if (sol[i] == -1) { sol[i] = at; ++at; if (at >= n) at = k; }
	//printf("sol:"); REP(i, 2 * n) printf(" %d", sol[i]); puts("");
	int ret = 0;
	REP(i, n) prv[i] = -1;
	REP(i, 2 * n) {
		int x = sol[i];
		if (prv[x] == -1) {
			prv[x] = i;
		} else {
			int j = prv[x];
			FORE(k, j + 1, i - 1) { int y = sol[k]; if (prv[y] >= 0) ++ret /*, printf("[%d,%d,%d]: (%d,%d) <%d>\n", i, k, j, x, y, prv[y])*/; }
			prv[x] = -2;
		}
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &k);
	REP(i, k) REP(j, 2) scanf("%d", &have[i][j]), --have[i][j];
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}