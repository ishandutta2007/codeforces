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

const int MAXN = 300000;

int n, m;
vector<int> adj[MAXN];
vector<int> ans;

bool intree[MAXN];
int q[MAXN], qhead, qtail;

bool solve() {
	REP(i, n) intree[i] = false;
	qhead = qtail = 0;
	ans.clear();

	int root = 0;
	intree[root] = true, ans.PB(root);
	REPSZ(i, adj[root]) {
		int to = adj[root][i];
		if (intree[to]) continue;
		intree[to] = true, q[qhead++] = to;
	}
	while (qtail < qhead) {
		int at = q[qtail++];
		REPSZ(i, adj[at]) {
			int to = adj[at][i];
			if (intree[to]) continue;
			intree[to] = true, ans.PB(to);
			REPSZ(j, adj[to]) {
				int oth = adj[to][j];
				if (intree[oth]) continue;
				intree[oth] = true, q[qhead++] = oth;
			}
		}
	}
	REP(at, n) if (!intree[at]) return false;
	return true;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b), adj[b].PB(a); }
	if (!solve()) {
		printf("NO\n"); 
	} else {
		printf("YES\n");
		printf("%d\n", SZ(ans));
		REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
	}
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}