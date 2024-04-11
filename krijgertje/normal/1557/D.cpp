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

const int MAXROW = 300000;
const int MAXSEG = 300000;
const int MAXCOL = 2 * MAXSEG;
const int MAXS = 4 * MAXCOL;

int nrow, nseg;
int segrow[MAXSEG], segl[MAXSEG], segr[MAXSEG];
vector<int> ans;

vector<int> byrow[MAXROW];
vector<int> allcol;

int norml[MAXSEG], normr[MAXSEG];

int dp[MAXROW], act[MAXROW];
bool keep[MAXROW];

pair<int, int> sval[MAXS];
pair<int, int> slazy[MAXS];

void sapply(int x, pair<int, int> BY) {
	sval[x] = max(sval[x], BY);
	slazy[x] = max(slazy[x], BY);
}
void spush(int x) {
	if (slazy[x].first != 0) sapply(2 * x + 1, slazy[x]), sapply(2 * x + 2, slazy[x]), slazy[x] = MP(0, -1);
}
void spull(int x) {
	sval[x] = max(sval[2 * x + 1], sval[2 * x + 2]);
}
void sinit(int x, int l, int r) {
	slazy[x] = MP(0, -1);
	if (l == r) {
		sval[x] = MP(0, -1);
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void smod(int x, int l, int r, int L, int R, pair<int, int> BY) {
	if (L <= l && r <= R) {
		sapply(x, BY);
	} else {
		int m = l + (r - l) / 2; spush(x);
		if (L <= m) smod(2 * x + 1, l, m, L, R, BY);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, BY);
		spull(x);
	}
}
pair<int, int> sget(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return sval[x];
	} else {
		int m = l + (r - l) / 2; spush(x); pair<int, int> ret = MP(0, -1);
		if (L <= m) ret = max(ret, sget(2 * x + 1, l, m, L, R));
		if (m + 1 <= R) ret = max(ret, sget(2 * x + 2, m + 1, r, L, R));
		return ret;
	}
}


void solve() {
	REP(i, nrow) byrow[i].clear();
	REP(i, nseg) byrow[segrow[i]].PB(i);
	allcol.clear();
	REP(i, nseg) allcol.PB(segl[i]), allcol.PB(segr[i] + 1);
	sort(allcol.begin(), allcol.end());
	allcol.erase(unique(allcol.begin(), allcol.end()), allcol.end());
	REP(i, nseg) norml[i] = lower_bound(allcol.begin(), allcol.end(), segl[i]) - allcol.begin();
	REP(i, nseg) normr[i] = lower_bound(allcol.begin(), allcol.end(), segr[i] + 1) - allcol.begin() - 1;

	sinit(0, 0, SZ(allcol) - 2);
	REP(i, nrow) {
		dp[i] = 1, act[i] = -1;
		for (int idx : byrow[i]) {
			pair<int, int> cur = sget(0, 0, SZ(allcol) - 2, norml[idx], normr[idx]);
			//printf("row %d %d..%d -> (%d,%d)\n", i + 1, segl[idx], segr[idx], cur.first + 1, cur.second + 1);
			if (cur.first + 1 > dp[i]) dp[i] = cur.first + 1, act[i] = cur.second;
		}
		for (int idx : byrow[i]) {
			smod(0, 0, SZ(allcol) - 2, norml[idx], normr[idx], MP(dp[i], i));
		}
	}

	int best = 0;
	FOR(i, 1, nrow) if (dp[i] > dp[best]) best = i;
	REP(i, nrow) keep[i] = false;
	for (int i = best; i != -1; i = act[i]) keep[i] = true;
	ans.clear();
	REP(i, nrow) if (!keep[i]) ans.PB(i);
	assert(SZ(ans) == nrow - dp[best]);
}

void run() {
	scanf("%d%d", &nrow, &nseg);
	REP(i, nseg) scanf("%d%d%d", &segrow[i], &segl[i], &segr[i]), --segrow[i];
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}