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

const int MAXN = 200000;

int n;
vector<int> adj[MAXN];
int ans[3];

int mx[MAXN][3], mxvia[MAXN][3],mxleaf[MAXN][3];

void upd(int at, int d, int via, int leaf) {
	REP(i, 3) {
		if (d > mx[at][i]) {
			int idx = i + 1; while (idx < 3 && mxvia[at][idx] != via) ++idx;
			for (int j = idx - 1; j >= i; --j) if (j + 1 < 3) mx[at][j + 1] = mx[at][j], mxvia[at][j + 1] = mxvia[at][j + 1], mxleaf[at][j + 1] = mxleaf[at][j];
			mx[at][i] = d, mxvia[at][i] = via, mxleaf[at][i] = leaf;
		}
		if (mxvia[at][i] == via) break;
	}
}

void dfsdn(int at, int par) {
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par) continue;
		dfsdn(to, at);
		upd(at, mx[to][0] + 1, to, mxleaf[to][0]);
	}
}

void dfsup(int at, int par) {
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par) continue;
		int j = mxvia[at][0] != to ? 0 : 1;
		upd(to, mx[at][j] + 1, at, mxleaf[at][j]);
		dfsup(to, at);
	}
}

int solve() {
	REP(i, n) REP(j, 3) mx[i][j] = 0, mxvia[i][j] = -1, mxleaf[i][j] = i;
	dfsdn(0, -1);
	dfsup(0, -1);
	int ret = 0;
	REP(i, n) {
		int cur = mx[i][0] + mx[i][1] + mx[i][2];
		if (cur > ret) { 
			ret = cur; set<int> seen; 
			REP(j, 3) { int z = mxleaf[i][j]; if (!seen.count(z)) seen.insert(z); } 
			REP(j, n) if (SZ(seen) < 3 && !seen.count(j)) seen.insert(j);
			assert(SZ(seen) == 3);
			int at = 0; for (auto x : seen) ans[at++] = x;
		}
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n", solve());
	REP(i, 3) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}