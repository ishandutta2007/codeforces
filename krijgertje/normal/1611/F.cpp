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

int n, start;
int a[MAXN];

ll sum[MAXN + 1];

pair<ll, int> stck[MAXN + 1]; int nstck;

pair<int, int> solve() {
	sum[0] = 0; REP(i, n) sum[i + 1] = sum[i] + a[i];
	//printf("sum:"); REPE(i, n) printf(" %lld", sum[i]); puts("");

	nstck = 0;
	pair<int, int> ret = MP(-1, -1);
	for (int i = n; i >= 0; --i) {
		while (nstck > 0 && sum[i] <= stck[nstck - 1].first) --nstck;
		stck[nstck++] = MP(sum[i], i);
		if (i == n) continue;
		int lo = -1, hi = nstck - 1;
		while (lo + 1 < hi) {
			int mi = lo + (hi - lo) / 2;
			if (stck[mi].first < sum[i] - start) lo = mi; else hi = mi;
		}
		int j = lo == -1 ? n - 1 : stck[lo].second - 2;
		//printf("%d..%d\n", i, j);
		if (i > j) continue;
		if (ret == MP(-1, -1) || j - i > ret.second - ret.first) ret = MP(i, j);
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &start);
	REP(i, n) scanf("%d", &a[i]);
	pair<int, int> ans = solve();
	if (ans == MP(-1, -1)) printf("-1\n"); else printf("%d %d\n", ans.first + 1, ans.second + 1);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}