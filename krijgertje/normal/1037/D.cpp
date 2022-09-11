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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 200000;

int n;
vector<int> adj[MAXN];
int want[MAXN];

int par[MAXN];
vector<int> ch[MAXN];
void dfsinit(int at) {
	REPSZ(i, adj[at]) { int to = adj[at][i]; if (to == par[at]) continue; par[to] = at; dfsinit(to); }
}

bool solve() {
	par[0] = -1; dfsinit(0);
	REP(i, n) if (par[i] != -1) ch[par[i]].PB(i);

	int off = 1;
	if (want[0] != 0) return false;
	REP(i, n) {
		int at = want[i];
		int cnt = SZ(ch[at]);
		//printf("at=%d cnt=%d off=%d\n", at, cnt, off);
		REP(j, cnt) if (par[want[off + j]] != at) return false;
		off += cnt;
	}
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	REP(i, n) scanf("%d", &want[i]), --want[i];
	printf("%s\n", solve() ? "Yes" : "No");
}

int main() {
	run();
	return 0;
}