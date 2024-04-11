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

const int MAXN = 250000;
struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };
bool operator<(const P& a, const P& b) { if (a.x != b.x) return a.x < b.x; return a.y < b.y; }

int ninit;
P pinit[MAXN];

set<P> infected;

vector<P> getadj(const P& a) {
	vector<P> ret(3);
	ret[0] = P(a.x + 1, a.y);
	ret[1] = P(a.x - 1, a.y);
	ret[2] = a.x & 1 ? P(a.x - 1, a.y + 1) : P(a.x + 1, a.y - 1);
	return ret;
}

int ntree;
vector<P> ptree;
map<P, int> pmap;
vector<vector<int>> adj;
vector<int> col;

vector<int> par;

bool dfscycle(int at) {
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		if (par[to] != -2) return true;
		par[to] = at;
		if (dfscycle(to)) return true;
	}
	return false;
}

bool hascycle() {
	par = vector<int>(ntree, -2);
	REP(i, ntree) if (par[i] == -2) { par[i] = -1; if (dfscycle(i)) return true; }
	return false;
}

void determineinfected() {
	infected.clear();
	queue<P> q;
	REP(i, ninit) infected.insert(pinit[i]), q.push(pinit[i]);
	while (!q.empty()) {
		P a = q.front(); q.pop();
		for (const P& b : getadj(a)) {
			if (infected.count(b)) continue;
			int cntadjinfected = 0;
			for (const P& c : getadj(b)) cntadjinfected += infected.count(c);
			if (cntadjinfected >= 2) infected.insert(b), q.push(b);
		}
	}
}

void buildgraph() {
	ptree = vector<P>(SZ(infected));
	ntree = 0;
	pmap.clear();
	for (const P& a : infected) pmap[a] = ntree, ptree[ntree] = a, ++ntree;
	adj = vector<vector<int>>(ntree);
	col = vector<int>(ntree, 0);
	REP(i, ntree) for (const P& b : getadj(ptree[i])) if (pmap.count(b)) adj[i].PB(pmap[b]);
	REP(i, ninit) if (pmap.count(pinit[i])) col[pmap[pinit[i]]] = 1;
}

int calcsteps() {
	set<int> cheap;
	set<int> expansive;
	vector<bool> alive(ntree, true);
	vector<int> cntadjalive(ntree, 0);
	vector<int> cntadjblack(ntree, 0);
	REP(at, ntree) cntadjalive[at] = SZ(adj[at]);
	REP(at, ntree) for (int to : adj[at]) cntadjblack[at] += col[to];

	auto upd = [&](int at) {
		cheap.erase(at);
		expansive.erase(at);
		if (!alive[at]) return;
		if (col[at] == 0) {
			if (cntadjblack[at] == 2) cheap.insert(at);
			if (cntadjblack[at] == 3) expansive.insert(at);
		} else {
			if (cntadjblack[at] == 1 && cntadjalive[at] == 1) cheap.insert(at);
			if (cntadjblack[at] == 0 && cntadjalive[at] == 0) expansive.insert(at);
		}
	};
	REP(at, ntree) upd(at);

	int ret = 0;
	while (true) {
		if (!cheap.empty()) {
			int at = *cheap.begin();
			//printf("atcheap=(%d,%d)\n", ptree[at].x, ptree[at].y);
			if (col[at] == 0) {
				assert(cntadjblack[at] == 2);
				col[at] = 1, ++ret;
				for (int& to : adj[at]) ++cntadjblack[to];
				upd(at); for (int& to : adj[at]) upd(to);
			} else {
				assert(cntadjblack[at] == 1 && cntadjalive[at] == 1);
				int oth = -1; for (int& to : adj[at]) if (alive[to]) { assert(oth == -1); oth = to; } assert(oth != -1 && col[oth] == 1);
				if (cntadjalive[oth] == 2 && cntadjblack[oth] == 1) {
					int w = -1; for (int& to : adj[oth]) if (alive[to] && to != at) { assert(w == -1); w = to; } assert(w != -1 && col[w] == 0);
					if (cntadjblack[w] == 3) {
						col[oth] = 0, ++ret;
						col[w] = 1, ++ret;
						col[oth] = 1, ++ret;
						for (int& to : adj[w]) ++cntadjblack[to];
						upd(at); upd(w); for (int& to : adj[w]) upd(to);
						continue;
					}
				}
				col[at] = 0, alive[at] = false, ++ret;
				for (int& to : adj[at]) --cntadjblack[to], --cntadjalive[to];
				upd(at); for (int& to : adj[at]) upd(to);
			}
		} else if(!expansive.empty()) {
			int at = *expansive.begin();
			//printf("atexpansive=(%d,%d)\n", ptree[at].x, ptree[at].y);
			if (col[at] == 0) {
				assert(cntadjblack[at] == 3 && cntadjalive[at] == 3);
				bool done = false;
				for (int& oth : adj[at]) {
					if (cntadjblack[oth] != 1) continue;
					done = true;
					col[oth] = 0, ++ret;
					col[at] = 1, ++ret;
					col[oth] = 1, ++ret;
					for (int& to : adj[at]) ++cntadjblack[to];
					upd(at); for (int& to : adj[at]) upd(to);
					break;
				}
				if (done) continue;
				col[at] = 1, ++ret;
				for (int& to : adj[at]) ++cntadjblack[to];
				upd(at); for (int& to : adj[at]) upd(to);
			} else {
				assert(cntadjblack[at] == 0 && cntadjalive[at] == 0);
				col[at] = 0, alive[at] = false, ++ret;
				for (int& to : adj[at]) --cntadjblack[to], --cntadjalive[to];
				upd(at); for (int& to : adj[at]) upd(to);
			}
		} else {
			break;
		}
	}
	REP(at, ntree) assert(!alive[at] && col[at] == 0);
	return ret;
}

int solve() {
	determineinfected();
	buildgraph();
	if (hascycle()) return -1;
	return calcsteps();
}


void run() {
	scanf("%d", &ninit);
	REP(i, ninit) scanf("%d%d", &pinit[i].x, &pinit[i].y);
	int ans = solve();
	if (ans == -1) printf("SICK\n"); else printf("RECOVERED\n%d\n", ans);
}

void stress() {
	std::mt19937 rnd(123);
	REP(rep, 1000000) {
		ninit = rnd() % 20 + 1;
		int minsz = 1; while (minsz * minsz < ninit) ++minsz;
		int sz = minsz + rnd() % (minsz + 1);
		set<P> seen;
		REP(i, ninit) while (true) { P p; p.x = rnd() % sz, p.y = rnd() % sz; if (seen.count(p)) continue; seen.insert(p); pinit[i] = p; break; }
		//if (rep != 31075) continue;
		//printf("%d\n", ninit); REP(i, ninit) printf("%d %d\n", pinit[i].x, pinit[i].y);
		solve();
		if (rep % 1000 == 999) printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}