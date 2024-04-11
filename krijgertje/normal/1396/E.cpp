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

int n; ll want;
vector<int> adj[MAXN];
int match[MAXN];

int sz[MAXN];
void dfssz(int at,int par) {
	sz[at] = 1;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par) continue;
		dfssz(to, at);
		sz[at] += sz[to];
	}
}
int dfscentroid(int at, int par, int rootsz) {
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par) continue;
		if (2 * sz[to] >= rootsz) return dfscentroid(to, at, rootsz);
	}
	return at;
}
int centroid(int at) {
	dfssz(at, -1);
	return dfscentroid(at, -1, sz[at]);
}

struct SubTree {
	int sz;
	vector<vector<int>> nodesbydep;
	SubTree() :sz(0) {}
};

int par[MAXN], dep[MAXN];
vector<SubTree> subtrees;

void dfsinit(int at, int id) {
	++subtrees[id].sz;
	while (dep[at] >= SZ(subtrees[id].nodesbydep)) subtrees[id].nodesbydep.PB(vector<int>());
	subtrees[id].nodesbydep[dep[at]].PB(at);
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		par[to] = at; dep[to] = dep[at] + 1; dfsinit(to, id);
	}
}

bool solve() {
	int cent = centroid(0);

	subtrees.clear();
	par[cent] = -1;
	REPSZ(i, adj[cent]) {
		int to = adj[cent][i];
		subtrees.PB(SubTree());
		par[to] = cent; dep[to] = 0; dfsinit(to, i);
	}
	//printf("cent=%d\n", cent + 1);
	//printf("subtrees:"); REPSZ(i, subtrees) printf(" %d=%d", subtrees[i].nodesbydep[0][0] + 1, subtrees[i].sz); puts("");

	ll have = 0;
	REPSZ(i, subtrees) REPSZ(j, subtrees[i].nodesbydep) have += (ll)(j + 1)*SZ(subtrees[i].nodesbydep[j]);
	//printf("have=%lld want=%lld\n", have, want);
	if (want > have) return false;
	if (want % 2 != have % 2) return false;
	ll steps = (have - want) / 2;

	priority_queue<pair<int, int>> pq;
	REPSZ(i, subtrees) pq.push(MP(subtrees[i].sz, i));
	REP(i, n) match[i] = -1;
	while (steps > 0) {
		int id = pq.top().second; pq.pop();
		if (subtrees[id].sz == 1) return false;
		int d = SZ(subtrees[id].nodesbydep) - 1;
		assert(d >= 1);
		if (d <= steps) {
			int a = subtrees[id].nodesbydep[d].back(); subtrees[id].nodesbydep[d].pop_back();
			while (!subtrees[id].nodesbydep[d].empty() && match[subtrees[id].nodesbydep[d].back()] != -1) subtrees[id].nodesbydep[d].pop_back();
			assert(match[a] == -1);
			int b;
			if (!subtrees[id].nodesbydep[d].empty() && par[a] == par[subtrees[id].nodesbydep[d].back()]) {
				b = subtrees[id].nodesbydep[d].back(); subtrees[id].nodesbydep[d].pop_back();
			} else {
				b = par[a];
			}
			//printf("a=%d b=%d\n", a + 1, b + 1);
			steps -= d, match[a] = b, match[b] = a, subtrees[id].sz -= 2; if (subtrees[id].sz >= 1) pq.push(MP(subtrees[id].sz, id));
			while (d > 0) {
				if (subtrees[id].nodesbydep[d].empty()) subtrees[id].nodesbydep.pop_back(), --d;
				else if (match[subtrees[id].nodesbydep[d].back()] != -1) subtrees[id].nodesbydep[d].pop_back();
				else break;
			}
		} else {
			while (d > steps) --d;
			while (!subtrees[id].nodesbydep[d].empty() && match[subtrees[id].nodesbydep[d].back()] != -1) subtrees[id].nodesbydep[d].pop_back();
			assert(!subtrees[id].nodesbydep[d].empty());
			int a = subtrees[id].nodesbydep[d].back();
			assert(dep[a] >= 1 && match[a] == -1);
			int b = par[a];
			assert(match[b] == -1);
			for (int i = SZ(subtrees[id].nodesbydep[dep[a]]) - 1; i >= 0; --i) if (subtrees[id].nodesbydep[dep[a]][i] == a) subtrees[id].nodesbydep[dep[a]].erase(subtrees[id].nodesbydep[dep[a]].begin() + i);
			for (int i = SZ(subtrees[id].nodesbydep[dep[b]]) - 1; i >= 0; --i) if (subtrees[id].nodesbydep[dep[b]][i] == b) subtrees[id].nodesbydep[dep[b]].erase(subtrees[id].nodesbydep[dep[b]].begin() + i);
			//printf("a=%d b=%d\n", a + 1, b + 1);
			steps -= d, match[a] = b, match[b] = a;
		}
	}

	vector<int> lst;
	lst.PB(cent); REPSZ(i, subtrees) REPSZ(j, subtrees[i].nodesbydep) REPSZ(k, subtrees[i].nodesbydep[j]) { int at = subtrees[i].nodesbydep[j][k]; if (match[at] == -1) lst.PB(at); }
	assert(SZ(lst) % 2 == 0);
	REP(i, SZ(lst) / 2) { int a = lst[i], b = lst[i + SZ(lst) / 2]; match[a] = b, match[b] = a; }

	return true;
}

void run() {
	scanf("%d%lld", &n, &want);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b), adj[b].PB(a); }
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, n) if (i < match[i]) printf("%d %d\n", i + 1, match[i] + 1);
}

void stress() {
	REP(rep, 100000) {
		do { n = rnd() % 100 + 1; } while (n % 2 != 0); want = rnd() % n*n + 1;
		REP(i, n) adj[i].clear();
		vector<pair<int, int>> e;
		FOR(i, 1, n) { int a = rnd() % i, b = i; adj[a].PB(b), adj[b].PB(a); e.PB(MP(a, b)); }
		//puts("");  printf("%d %lld\n", n, want); REPSZ(i, e) printf("%d %d\n", e[i].first + 1, e[i].second + 1);
		solve();
	}
}

int main() {
	run();
	//stress();
	return 0;
}