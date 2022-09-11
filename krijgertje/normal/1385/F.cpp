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

const int MAXN = 200000;

int n, movesz;
vector<int> adj[MAXN];

bool alive[MAXN];
int leafadj[MAXN];
int deg[MAXN];
queue<int> q;

void kill(int at) {
	int to = -1; REPSZ(i, adj[at]) { int tmp = adj[at][i]; if (!alive[tmp]) continue; assert(to == -1); to = tmp; }
	--deg[at], alive[at] = false;
	if (to != -1) {
		++leafadj[to];
		if (leafadj[to] == movesz) q.push(to);
	}
}

int solve() {
	if (movesz == 1) return n - 1;
	REP(i, n) alive[i] = true, leafadj[i] = 0, deg[i] = SZ(adj[i]);
	q = queue<int>();
	REP(at, n) if (deg[at] == 1) kill(at);
	int ret = 0;
	while (!q.empty()) {
		int at = q.front(); q.pop();
		//printf("at=%d\n", at);
		assert(leafadj[at] >= movesz && alive[at]);
		while (leafadj[at] >= movesz) {
			leafadj[at] -= movesz;
			deg[at] -= movesz;
			++ret;
		}
		if (deg[at] == 1) kill(at);
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &movesz);
	REP(i, n) adj[i].clear();
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}