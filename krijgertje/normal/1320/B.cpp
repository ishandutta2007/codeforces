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

int n, m;
vector<int> in[MAXN];
int np;
int p[MAXN];

int q[MAXN], qhead, qtail;
int d[MAXN]; bool multiple[MAXN];

pair<int, int> solve() {
	qhead = qtail = 0; REP(i, n) d[i] = INT_MAX, multiple[i] = false;
	int t = p[np - 1]; d[t] = 0, q[qhead++] = t;
	while (qtail < qhead) { int at = q[qtail++]; REPSZ(i, in[at]) { int to = in[at][i]; if (d[to] == INT_MAX) d[to] = d[at] + 1, q[qhead++] = to; else if (d[to] == d[at] + 1) multiple[to] = true; } }
	REP(i, n) assert(d[i] != INT_MAX);
	//printf("d:"); REP(i, n) printf(" %d", d[i]); puts("");
	int mn = 0, mx = 0;
	REP(i, np - 1) {
		int a = p[i], b = p[i + 1];
		if (d[b] + 1 > d[a]) ++mn;
		if (d[b] + 1 > d[a] || multiple[a]) ++mx;
	}
	return MP(mn,mx);
}


void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; in[b].PB(a); }
	scanf("%d", &np);
	REP(i, np) scanf("%d", &p[i]), --p[i];
	pair<int, int> ans = solve();
	printf("%d %d\n", ans.first, ans.second);
}

int main() {
	run();
	return 0;
}