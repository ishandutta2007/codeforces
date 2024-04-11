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

const int MAXN = 25;

int n;
ll a[MAXN][MAXN];

ll lo[MAXN][MAXN - 1], hi[MAXN][MAXN - 1];

void solve() {
	REP(i, n) REP(j, n) a[i][j] = j == n - 1 ? 0 : -1;
	REP(j, n - 1) a[0][j] = 0, lo[0][j] = hi[0][j] = 0;
	FOR(i, 1, n) {
		for (int j = n - 2; j >= 0; --j) {
			ll nxt = j == n - 2 ? hi[i - 1][0] + 1 : hi[i][j + 1] + 1;
			a[i][j] = nxt; FOR(k, j + 1, n) a[i][j] -= a[i][k]; REP(k, i) a[i][j] -= a[k][j];
			lo[i][j] = a[i][j]; FOR(k, j + 1, n) lo[i][j] += a[i][k]; REP(k, i) lo[i][j] += a[k][j];
			hi[i][j] = a[i][j]; FOR(k, j + 1, n) hi[i][j] += a[i][k]; FORE(k, 1, j) hi[i][j] += a[i - 1][k]; REP(k, i) hi[i][j] += a[k][0];
		}
	}
	REP(i, n) { REP(j, n) { if (j != 0) printf(" "); printf("%lld", a[i][j]); } puts(""); } fflush(stdout);
	//puts(""); REP(i, n) { REP(j, n - 1) { if (j != 0) printf(" "); printf("%lld..%lld", lo[i][j], hi[i][j]); } puts(""); } fflush(stdout);

	int nq;
	scanf("%d", &nq);
	REP(i, nq) {
		ll sum; scanf("%lld", &sum);
		ll rem = sum;
		pair<int, int> at = MP(n - 1, n - 1);
		vector<pair<int, int>> path(1, at);
		while (rem != 0) {
			pair<int, int> to = MP(-1, -1);
			REP(x, n) REP(y, n - 1) if (lo[x][y] <= rem && rem <= hi[x][y]) {
				assert(to == MP(-1, -1));
				to = MP(x, y);
			}
			assert(to != MP(-1, -1));
			FOR(y, to.second, n) rem -= a[to.first][y];
			FOR(y, to.second + 1, n) rem += a[to.first - 1][y];
			//printf("to=(%d,%d) (nrem=%lld)\n", to.first + 1, to.second + 1, rem);
			assert(at.first >= to.first);
			while (at.first > to.first) --at.first, path.PB(at);
			assert(at.second >= to.second);
			while (at.second > to.second) --at.second, path.PB(at);
		}
		while (at.first > 0) --at.first, path.PB(at);
		while (at.second > 0) --at.second, path.PB(at);
		reverse(path.begin(), path.end());
		REPSZ(j, path) printf("%d %d\n", path[j].first + 1, path[j].second + 1); fflush(stdout);
	}
}

void run() {
	scanf("%d", &n);
	solve();
}

int main() {
	run();
	return 0;
}