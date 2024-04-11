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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 60;
const int MOD = 1000000007;
const int MAXCOL = MAXN / 4;
void inc(int& a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n;
int a[MAXN];

int choose[MAXN + 1][MAXN + 1];

vector<int> adj[MAXN];
int comp[MAXN], ncomp;
int q[MAXN], qhead, qtail;

int id[MAXN], nid;

int dp[1 << MAXCOL][MAXN + 1]; // dp[mask][cnt] = ways to prepend all rows when the last 'cnt' rows are already fixed and 'mask' is its OR

int calc(vector<int> rows, int ncol) {
	//printf("calc:"); REPSZ(i, rows) { printf(" "); REP(j, ncol) printf("%d", (rows[i] >> j) & 1); } puts("");
	REP(mask, 1 << ncol) REPE(cnt, SZ(rows)) dp[mask][cnt] = 0;
	REPSZ(i, rows) inc(dp[rows[i]][1], 1);
	REP(mask, 1 << ncol) REPE(cnt, SZ(rows)) {
		int ways = dp[mask][cnt]; if (ways == 0) continue;
		int lim = 0; REPSZ(i, rows) if ((mask & rows[i]) == rows[i]) ++lim;
		if (cnt < lim) inc(dp[mask][cnt + 1], (ll)ways * (lim - cnt) % MOD);
		REPSZ(i, rows) if ((mask & rows[i]) != rows[i] && (mask & rows[i]) != 0) inc(dp[mask | rows[i]][cnt + 1], ways);
	}
	int ret = dp[(1 << ncol) - 1][SZ(rows)];
	//printf("=%d\n", ret);
	return ret;
}

int solve() {
	REPE(i, n) { choose[i][0] = choose[i][i] = 1; FOR(j, 1, i) choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % MOD; }

	REP(i, n) adj[i].clear(); REP(i, n) REP(j, n) if (j != i && a[i] % a[j] == 0) { adj[i].PB(j); adj[j].PB(i); }
	ncomp = 0; REP(i, n) comp[i] = -1;
	REP(i, n) if (comp[i] == -1) { comp[i] = ncomp++; qhead = qtail = 0; q[qhead++] = i; while (qtail < qhead) { int at = q[qtail++]; REPSZ(i, adj[at]) { int to = adj[at][i]; if (comp[to] == -1) comp[to] = comp[at], q[qhead++] = to; } } }
	//printf("comp:"); REP(i, n) printf(" %d", comp[i]); puts("");

	int ret = 1; int sum = 0;
	REP(c, ncomp) {
		nid = 0; REP(i, n) id[i] = -1;
		REP(i, n) if (comp[i] == c) { bool issrc = true; REPSZ(_, adj[i]) { int j = adj[i][_]; assert(comp[j] == comp[i]); if (a[i] > a[j]) issrc = false; } if (issrc) id[i] = nid++; }
		assert(nid <= MAXN / 4);
		vector<int> rows;
		REP(i, n) if (comp[i] == c && id[i] == -1) { int mask = 0; REPSZ(_, adj[i]) { int j = adj[i][_]; if (id[j] != -1) mask |= 1 << id[j]; } rows.PB(mask); }
		if (SZ(rows) == 0) continue;
		int curways = calc(rows, nid), curcnt = SZ(rows) - 1;
		ret = (ll)ret * curways % MOD * choose[sum + curcnt][sum] % MOD; sum += curcnt;
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