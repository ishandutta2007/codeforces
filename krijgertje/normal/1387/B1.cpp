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
int ans[MAXN];

bool alive[MAXN];
int deg[MAXN];
int q[MAXN], qhead, qtail;

int solve() {
	REP(i, n) ans[i] = i;
	REP(i, n) deg[i] = SZ(adj[i]);
	REP(i, n) alive[i] = true;
	REP(i, n) if (deg[i] <= 1) q[qhead++] = i;
	int ret = 0;
	while (qtail < qhead) {
		int at = q[qtail++]; alive[at] = false;
		int found = -1;
		REPSZ(i, adj[at]) {
			int to = adj[at][i]; if (!alive[to]) continue;
			if (--deg[to] == 1) q[qhead++] = to;
			assert(found == -1); found = to;
		}
		if (ans[at] != at) continue;
		if (found != -1) {
			++ret; swap(ans[at], ans[found]);
		} else {
			int any = adj[at][0];
			++ret; swap(ans[at], ans[any]);
		}
	}
	return 2 * ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n", solve());
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}