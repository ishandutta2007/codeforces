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

const int MAXA = 100000;
const int MAXB = 100000;

int na, nb;
int a[MAXA];
vector<int> b[MAXB];
vector<bool> ans[MAXB];

int bcnt[MAXB];
ll bsum[MAXB];

int ord[MAXB];
int pos[MAXB];
int validcnt[MAXA][3];

void solve() {
	REP(i, nb) {
		bcnt[i] = SZ(b[i]);
		bsum[i] = 0; for (int x : b[i]) bsum[i] += x;
	}
	sort(a, a + na);
	reverse(a, a + na);
	reverse(a, a + nb);

	REP(i, nb) ord[i] = i;
	sort(ord, ord + nb, [&](int i, int j) { return bsum[i] * bcnt[j] < bsum[j] * bcnt[i]; });
	REP(i, nb) pos[ord[i]] = i;

	FORE(delta, -1, +1) {
		for (int i = nb - 1; i >= 0; --i) {
			int j = i + delta;
			validcnt[i][1 + delta] = j < 0 || j >= nb || (ll)a[i] * bcnt[ord[j]] < bsum[ord[j]] ? 0 : 1 + (i + 1 < nb ? validcnt[i + 1][1 + delta] : 0);
		}
	}

	//printf("a:"); REP(i, nb) printf(" %d", a[i]); puts("");
	//printf("b:"); REP(i, nb) printf(" %.1lf", 1.0 * bsum[ord[i]] / bcnt[ord[i]]); puts("");
	REP(i, nb) {
		ans[i] = vector<bool>(SZ(b[i]));
		REPSZ(j, b[i]) {
			int mycnt = bcnt[i] - 1;
			ll mysum = bsum[i] - b[i][j];
			int lo = -1, hi = nb;
			while (lo + 1 < hi) {
				int mi = lo + (hi - lo) / 2;
				if (mysum * bcnt[ord[mi]] <= bsum[ord[mi]] * mycnt) hi = mi; else lo = mi;
			}
			int from = pos[i];
			int to = hi; if (to > from) --to;
			//printf("%d - %d: %d to %d with %.1lf\n", i, j, from, to, 1.0 * mysum / mycnt);
			int l = min(from, to);
			int r = max(from, to);
			bool ok = true;
			if (l != 0 && validcnt[0][1 + 0] < l) ok = false;
			if (r != nb - 1 && validcnt[r + 1][1 + 0] < nb - r - 1) ok = false;
			if (from < to && validcnt[l][1 + (+1)] < r - l) ok = false;
			if (to < from && validcnt[l + 1][1 + (-1)] < r - l) ok = false;
			if ((ll)a[to] * mycnt < mysum) ok = false;
			ans[i][j] = ok;
		}
	}
}

void run() {
	scanf("%d%d", &na, &nb);
	REP(i, na) scanf("%d", &a[i]);
	REP(i, nb) { int cnt; scanf("%d", &cnt); b[i] = vector<int>(cnt); REP(j, cnt) scanf("%d", &b[i][j]); }
	solve();
	REP(i, nb) REPSZ(j, ans[i]) printf("%d", ans[i][j] ? 1 : 0); puts("");
	REP(i, nb) b[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}