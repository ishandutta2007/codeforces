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

const int MAXN = 1000;

int n;
vector<int> adj[MAXN];

int deg[MAXN];
int q[MAXN], qhead, qtail;

int query(int a, int b) {
	printf("? %d %d\n", a + 1, b + 1); fflush(stdout);
	int ret; scanf("%d", &ret); if (ret == -1) exit(0); --ret; return ret;
}

int solve() {
	REP(i, n) deg[i] = SZ(adj[i]);
	qhead = qtail = 0;
	REP(i, n) if (deg[i] <= 1) q[qhead++] = i;
	while (qhead - qtail >= 2) {
		int a = q[qtail++];
		int b = q[qtail++];
		int c = query(a, b);
		if (c == a || c == b) return c;
		REPSZ(i, adj[a]) { int to = adj[a][i]; if (--deg[to] == 1) q[qhead++] = to; }
		REPSZ(i, adj[b]) { int to = adj[b][i]; if (--deg[to] == 1) q[qhead++] = to; }
	}
	assert(qhead - qtail == 1);
	return q[qtail];
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	int ans=solve();
	printf("! %d\n", ans + 1); fflush(stdout);
}

int main() {
	run();
	return 0;
}