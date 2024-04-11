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

const int MAXN = 500000;

int n, m;
set<pair<int, int>> checked;
int ansp[MAXN];
int ansq[MAXN];

vector<int> adj[MAXN];
int deg[MAXN];
bool done[MAXN];

void maketree() {
	set<int> todo;
	REP(i, n) todo.insert(i);
	while (SZ(todo) >= 1) {
		int s = *todo.begin(); todo.erase(todo.begin());
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int at = q.front(); q.pop();
			auto it = todo.begin();
			while (it != todo.end()) {
				int to = *it;
				if (!checked.count(MP(at, to))) {
					adj[at].PB(to), adj[to].PB(at);
					//printf("%d-%d\n", at + 1, to + 1);
					q.push(to);
					todo.erase(it++);
				} else {
					++it;
				}
			}
		}
	}
}

void buildans() {
	REP(i, n) ansp[i] = ansq[i] = -1;
	REP(i, n) done[i] = false, deg[i] = SZ(adj[i]);
	queue<int> q;
	REP(i, n) if (deg[i] <= 1) q.push(i);
	int nxt = 0;
	auto markdone = [&](int at) {
		assert(!done[at]);
		done[at] = true;
		REPSZ(i, adj[at]) { int to = adj[at][i]; if (done[to]) continue; if (--deg[to] == 1) q.push(to); }
	};
	while (!q.empty()) {
		int at = q.front(); q.pop();
		if (done[at]) continue;
		int cent = -1; REPSZ(i, adj[at]) { int to = adj[at][i]; if (done[to]) continue; assert(cent == -1); cent = to; }
		if (cent == -1) {
			markdone(at);
			ansp[at] = ansq[at] = nxt++;
		} else {
			vector<int> lst;
			REPSZ(i, adj[cent]) { int to = adj[cent][i]; if (done[to] || deg[to] >= 2) continue; lst.PB(to); }
			markdone(cent); for (int to : lst) markdone(to);
			assert(SZ(lst) >= 1);
			ansp[cent] = nxt; REPSZ(i, lst) ansp[lst[i]] = nxt + i + 1;
			REPSZ(i, lst) ansq[lst[i]] = nxt + i; ansq[cent] = nxt + SZ(lst);
			nxt += SZ(lst) + 1;
		}
	}
}

void solve() {
	maketree();
	buildans();
	REP(i, n) adj[i].clear();
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; checked.insert(MP(a, b)); checked.insert(MP(b, a)); }
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ansp[i] + 1); } puts("");
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ansq[i] + 1); } puts("");
	checked.clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}