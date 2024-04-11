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
const int MAXM = 200000;
const int MAXCOL = 200000;

int n, m;
vector<int> adj[MAXN];

int col[MAXN], ncol;
int q[MAXN], qhead, qtail;
int last[MAXCOL];


int solve() {
	ncol = 0; REP(i, n) col[i] = -1;
	REP(i, n) if (col[i] == -1) {
		qhead = qtail = 0; col[i] = ncol++; q[qhead++] = i;
		while (qtail < qhead) { int at = q[qtail++]; REPSZ(j, adj[at]) { int to = adj[at][j]; if (col[to] == -1) col[to] = col[at], q[qhead++] = to; assert(col[to] == col[at]); } }
	}
	REP(i, ncol) last[i] = -1; REP(i, n) last[col[i]] = max(last[col[i]], i);
	int nparts = 0, upto = -1;
	REP(i, n) {
		if (upto < i) ++nparts;
		upto = max(upto, last[col[i]]);
	}
	return ncol - nparts;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}