#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 1000;

int n;

bool local = false;
ll localval[MAXN];

ll query(int a, int b, int c) {
	if (!local) {
		printf("? %d %d %d\n", a + 1, b + 1, c + 1); fflush(stdout);
		ll ret; scanf("%lld", &ret); return ret;
	} else {
		ll mn = min(localval[a], min(localval[b], localval[c]));
		ll mx = max(localval[a], max(localval[b], localval[c]));
		return mn + mx;
	}
}

ll res[5][5][5];
int who[5];
ll ans[MAXN];

ll mat[10][6];

void gaussjord() {
	int nrow = 10, ncol = 6, r = 0, c = 0;
	while (r < nrow && c < ncol) {
		{ int rr = r; while (rr < nrow && mat[rr][c] == 0) ++rr; if (rr >= nrow) { ++c; continue; } REP(cc, ncol) swap(mat[r][cc], mat[rr][cc]); }
		{ ll dv = mat[r][c]; REP(cc, ncol) { assert(mat[r][cc] % dv == 0); mat[r][cc] /= dv; } }
		FOR(rr, r + 1, nrow) { ll times = mat[rr][c]; REP(cc, ncol) mat[rr][cc] -= mat[r][cc] * times; }
		++r, ++c;
	}
	for (--r; r >= 0; --r) {
		c = 0; while (c < ncol && mat[r][c] == 0) ++c; if (c >= ncol) continue; assert(mat[r][c] == 1);
		REP(rr,r) { ll times = mat[rr][c]; REP(cc, ncol) mat[rr][cc] -= mat[r][cc] * times; }
	}
	//REP(ri, nrow) { REP(ci, ncol) printf("%4lld", mat[ri][ci]); puts(""); } puts("");
	REP(i, 5) assert(mat[i][i] == 1);
	REP(i, 5) ans[i] = mat[i][5];
}

void solve() {
	REP(i, n) ans[i] = -1;
	vector<int> mxidx, mnidx; ll mxval = LLONG_MIN, mnval = LLONG_MAX;
	REP(i, 5) FOR(j, i + 1, 5) FOR(k, j + 1, 5) {
		ll cur = query(i, j, k);
		res[i][j][k] = res[i][k][j] = res[j][i][k] = res[j][k][i] = res[k][i][j] = res[k][j][i] = cur;
		if (cur > mxval) mxval = cur, mxidx.clear(); if (cur == mxval) mxidx.PB(i), mxidx.PB(j), mxidx.PB(k);
		if (cur < mnval) mnval = cur, mnidx.clear(); if (cur == mnval) mnidx.PB(i), mnidx.PB(j), mnidx.PB(k);
	}
	sort(mnidx.begin(), mnidx.end()); mnidx.erase(unique(mnidx.begin(), mnidx.end()), mnidx.end());
	sort(mxidx.begin(), mxidx.end()); mxidx.erase(unique(mxidx.begin(), mxidx.end()), mxidx.end());
	int mididx = -1; REP(i, 5) { bool inmn = false, inmx = false; REPSZ(j, mnidx) if (mnidx[j] == i) inmn = true; REPSZ(j, mxidx) if (mxidx[j] == i) inmx = true; if (inmn&&inmx) { mididx = i; break; } } assert(mididx != -1); who[2] = mididx;
	{ int n = 0; REPSZ(i, mnidx) if (mnidx[i] != mididx) mnidx[n++] = mnidx[i]; mnidx.resize(n); }
	{ int n = 0; REPSZ(i, mxidx) if (mxidx[i] != mididx) mxidx[n++] = mxidx[i]; mxidx.resize(n); }
	if (SZ(mnidx) == 3 && SZ(mxidx) == 4) { mnidx.resize(2); }
	if (SZ(mnidx) == 4 && SZ(mxidx) == 3) { mxidx.resize(2); }
	if (SZ(mnidx) == 4 && SZ(mxidx) == 4) { mnidx.resize(2); }
	if (SZ(mnidx) == 3 && SZ(mxidx) == 3) { vector<int> common; REP(i, 5) { bool inmn = false, inmx = false; REPSZ(j, mnidx) if (mnidx[j] == i) inmn = true; REPSZ(j, mxidx) if (mxidx[j] == i) inmx = true; if (inmn&&inmx) common.PB(i); } assert(SZ(common) == 2); mnidx.erase(find(mnidx.begin(),mnidx.end(),common[0])); mxidx.erase(find(mxidx.begin(),mxidx.end(),common[1])); }
	if (SZ(mnidx) == 2) { int n = 0; REPSZ(i, mxidx) if (mxidx[i] != mnidx[0] && mxidx[i] != mnidx[1]) mxidx[n++] = mxidx[i]; mxidx.resize(n); }
	if (SZ(mxidx) == 2) { int n = 0; REPSZ(i, mnidx) if (mnidx[i] != mxidx[0] && mnidx[i] != mxidx[1]) mnidx[n++] = mnidx[i]; mnidx.resize(n); }
	//printf("mididx: %d\n", mididx);
	//printf("mnidx:"); REPSZ(i, mnidx) printf(" %d", mnidx[i]); puts("");
	//printf("mxidx:"); REPSZ(i, mxidx) printf(" %d", mxidx[i]); puts("");
	assert(SZ(mnidx) == 2 && SZ(mxidx) == 2);
	{ int a = mnidx[0], b = mnidx[1]; if (res[a][mididx][mxidx[0]] <= res[b][mididx][mxidx[0]]) who[0] = a, who[1] = b; else who[0] = b, who[1] = a; }
	{ int a = mxidx[0], b = mxidx[1]; if (res[a][mididx][mnidx[0]] <= res[b][mididx][mnidx[0]]) who[3] = a, who[4] = b; else who[3] = b, who[4] = a; }
	//printf("who:"); REP(i, 5) printf(" %d", who[i]); puts("");
	REP(i, 4) assert(localval[who[i]] <= localval[who[i + 1]]);
	int nrow = 0, ncol = 6;
	REP(i, 5) FOR(j, i + 1, 5) FOR(k, j + 1, 5) {
		REP(z, ncol) mat[nrow][z] = 0;
		++mat[nrow][who[i]], ++mat[nrow][who[k]], mat[nrow][5] = res[who[i]][who[j]][who[k]], ++nrow;
	}
	gaussjord();
	REP(k, 4) if (ans[who[k]] == ans[who[k + 1]]) {
		int a = who[k], b = who[k + 1];
		FOR(i, 5, n) {
			ll cur = query(a, b, i);
			ans[i] = cur - ans[a];
		}
		return;
	}
	FOR(i, 5, n) {
		int a = who[0], b = who[1], c = who[2];
		ll ab = query(a, b, i), bc = query(b, c, i);
		if (ab < ans[a] + ans[b]) ans[i] = ab - ans[b]; else if (ab > ans[a] + ans[b]) ans[i] = ab - ans[a]; else if (bc < ans[b] + ans[c]) ans[i] = bc - ans[c]; else if (bc > ans[b] + ans[c]) ans[i] = bc - ans[b]; else ans[i] = ans[b];
	}
}

void run() {
	scanf("%d", &n);
	solve();
	printf("!"); REP(i, n) printf(" %lld", ans[i]); puts(""); fflush(stdout);
}

void testlocal(int rep) {
	local = true;
	solve();
	bool ok = true; REP(i, n) if (localval[i] != ans[i]) ok = false;
	if (ok) { printf("."); return; }
	printf("err: rep=%d\n", rep);
	printf("want:"); REP(i, n) printf(" %lld", localval[i]); puts("");
	printf("have:"); REP(i, n) printf(" %lld", ans[i]); puts("");
	exit(0);
}

void stress() {
	REP(rep, 10000) {
		n = 10; int ndiff = rand() % n + 1;
		set<int> vals; while (SZ(vals) < ndiff) vals.insert(rand() % 10);
		int at = 0; for (auto it = vals.begin(); it != vals.end(); ++it) localval[at++] = *it; while (at < n) localval[at++] = localval[rand() % ndiff];
		random_shuffle(localval, localval + n);
		//if (rep != 10) continue;
		testlocal(rep);
	}
}


int main() {
	run();
	//stress();
	return 0;
}