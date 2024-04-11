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

const int MAXN = 200;
const int MAXM = 2000;

int n, m;
int e[MAXM][3];
int ansmx, ans[MAXN];

vector<int> adj[MAXN];
int col[MAXN];
queue<int> q;

int d[MAXN][MAXN];

bool solve() {
	REP(i, n) adj[i].clear();
	REP(i, m) { int a = e[i][0], b = e[i][1]; adj[a].PB(b), adj[b].PB(a); }
	q = queue<int>();
	REP(i, n) col[i] = -1;
	col[0] = 0, q.push(0);
	while (!q.empty()) {
		int at = q.front(); q.pop();
		REPSZ(i, adj[at]) {
			int to = adj[at][i];
			if (col[to] == col[at]) return false;
			if (col[to] != -1) continue;
			col[to] = 1 - col[at], q.push(to);
		}
	}
	REP(i, n) assert(col[i] != -1);

	REP(i, n) REP(j, n) d[i][j] = i == j ? 0 : INT_MAX;
	REP(i, m) { int a = e[i][0], b = e[i][1]; if (e[i][2] == 0) d[a][b] = d[b][a] = 1; else d[a][b] = 1, d[b][a] = -1; }
	REP(k, n) {
		REP(i, n) REP(j, n) if (d[i][k] != INT_MAX && d[k][j] != INT_MAX) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		REP(i, n) if (d[i][i] < 0) return false;
	}
	int broot = -1, bdist = -1;
	REP(i, n) REP(j, n) if (d[i][j] > bdist) bdist = d[i][j], broot = i;
	REP(i, n) assert(d[broot][i] >= 0);
	ansmx = bdist; REP(i, n) ans[i] = d[broot][i]; return true;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) scanf("%d%d%d", &e[i][0], &e[i][1], &e[i][2]), --e[i][0], --e[i][1];
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%d\n", ansmx);
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}