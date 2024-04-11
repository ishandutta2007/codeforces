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

const int MAXN = 100000;

int n;
vector<int> adj[MAXN];

bool isleaf[MAXN];
int d[MAXN];
int q[MAXN], qhead, qtail;
int cntadjleaf[MAXN];

int solvemn() {
	REP(i, n) isleaf[i] = SZ(adj[i]) <= 1;
	int root = -1; REP(i, n) if (isleaf[i]) { root = i; break; } assert(root != -1);
	qhead = qtail = 0; REP(i, n) d[i] = INT_MAX;
	d[root] = 0, q[qhead++] = root;
	while (qtail < qhead) { int at = q[qtail++]; REPSZ(i, adj[at]) { int to = adj[at][i]; if (d[to] == INT_MAX) d[to] = d[at] + 1, q[qhead++] = to; } }
	REP(i, n) assert(d[i] != INT_MAX);
	REP(i, n) if (isleaf[i] && d[i] % 2 == 1) return 3;
	return 1;
}

int solvemx() {
	REP(i, n) isleaf[i] = SZ(adj[i]) <= 1;
	REP(i, n) cntadjleaf[i] = 0;
	REP(i, n) if (isleaf[i]) REPSZ(j, adj[i]) ++cntadjleaf[adj[i][j]];
	int ret = n - 1; REP(i, n) ret -= max(0, cntadjleaf[i] - 1); return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b), adj[b].PB(a); }
	printf("%d %d\n", solvemn(), solvemx());
}

int main() {
	run();
	return 0;
}