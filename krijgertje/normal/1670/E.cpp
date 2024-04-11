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
#include <functional>
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

const int MAXPW = 17;
const int MAXN = 1 << MAXPW;

int pw, n;
vector<pair<int, int>> adj[MAXN];
int ansroot;
int ansnode[MAXN];
int ansedge[MAXN - 1];

void dfs(int at, int par, int& nxt, bool zero) {
	for (const auto& z : adj[at]) {
		int to = z.first, eid = z.second;
		if (to == par) continue;
		int x = nxt++;
		if (!zero) {
			ansedge[eid] = x ^ n, ansnode[to] = x;
		} else {
			ansedge[eid] = x, ansnode[to] = x ^ n;
		}
		dfs(to, at, nxt, !zero);
	}
}

void solve() {
	REP(i, n) ansnode[i] = -1;
	REP(i, n - 1) ansedge[i] = -1;
	ansroot = 0;
	ansnode[ansroot] = n;
	int nxt = 1;
	dfs(ansroot, -1, nxt, false);

}

void run() {
	scanf("%d", &pw); n = 1 << pw;
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(MP(b, i)); adj[b].PB(MP(a, i)); }
	solve();
	printf("%d\n", ansroot + 1);
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ansnode[i]); } puts("");
	REP(i, n - 1) { if (i != 0) printf(" "); printf("%d", ansedge[i]); } puts("");
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}