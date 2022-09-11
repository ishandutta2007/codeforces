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

const int MAXDOM = 300000;
const int MAXNODE = 2 * MAXDOM;

int ndom;
int dom[MAXDOM][2];
int h, w;
vector<vector<int>> ans;
vector<string> sol[2];

int nnode;
vector<int> adj[MAXNODE];
vector<int> loops[MAXNODE];
int par[MAXNODE], parid[MAXNODE], dep[MAXNODE], sz[MAXNODE]; // sz is tree edges + back edges

vector<vector<int>> groups;

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	sz[at] = SZ(loops[at]);
	for (int id : adj[at]) {
		int to = dom[id][0] ^ dom[id][1] ^ at;
		if (id == parid[at]) continue;
		if (par[to] != -2) { if (dep[to] < dep[at]) ++sz[at]; continue; }
		par[to] = at, parid[to] = id;
		dfsinit(to);
		sz[at] += sz[to] + 1;
	}
}
bool dfsbuild(int at) {
	int x = -1;
	auto upd = [&](int y) {
		if (x == -1) {
			x = y;
		} else {
			groups.PB({ x,y });
			x = -1;
		}
	};

	for (int id : loops[at]) upd(id);
	for (int id : adj[at]) {
		int to = dom[id][0] ^ dom[id][1] ^ at;
		if (id == parid[at]) continue;
		if (id == parid[to]) {
			if (dfsbuild(to)) upd(id);
		} else if (dep[to] < dep[at]) {
			upd(id);
		}
	}
	if (parid[at] != -1) upd(parid[at]);
	if (x != -1) {
		if (parid[at] != -1) {
			assert(x == parid[at]);
		} else {
			groups.back().PB(x);
			x = -1;
		}
	}
	return x != -1;
}


bool solve() {
	nnode = 2 * ndom;
	REP(i, nnode) adj[i].clear(), loops[i].clear();
	REP(i, ndom) { int a = dom[i][0], b = dom[i][1]; if (a != b) adj[a].PB(i), adj[b].PB(i); else loops[a].PB(i); }
	REP(i, nnode) par[i] = parid[i] = -2;
	groups.clear();
	REP(i, nnode) if (par[i] == -2) {
		par[i] = parid[i] = -1;
		dfsinit(i);
		//printf("%d: sz=%d\n", i + 1, sz[i]);
		if (sz[i] == 0) continue;
		if (sz[i] == 1) return false;
		dfsbuild(i);

	}
	//printf("groups:"); REPSZ(i, groups) { printf(" ["); REPSZ(j, groups[i]) { int id = groups[i][j]; if (j != 0) printf(","); printf("%d-%d", dom[id][0] + 1, dom[id][1] + 1); } printf("]"); } puts("");

	h = 2, w = ndom;
	ans = vector<vector<int>>(h, vector<int>(w, -1));
	sol[0] = vector<string>(h, string(w, '?'));
	sol[1] = vector<string>(h, string(w, '?'));
	int at = 0;
	REPSZ(i, groups) {
		vector<int> cur = groups[i];
		int len = SZ(cur);
		assert(len == 2 || len == 3);
		if (len == 2) {
			bool found = false;
			REP(aidx, len) {
				int bidx = 1 - aidx;
				int a = cur[aidx], b = cur[bidx];
				REP(aflip, 2) REP(bflip, 2) {
					if (found) continue;
					ans[0][at] = dom[a][aflip], ans[0][at + 1] = dom[a][aflip ^ 1];
					ans[1][at] = dom[b][bflip], ans[1][at + 1] = dom[b][bflip ^ 1];
					auto append = [&](vector<pair<int, int>>& have, int x, int y) { if (x > y) swap(x, y); have.PB(MP(x, y)); };
					vector<pair<int, int>> have1, have2, need;
					append(need, dom[a][0], dom[a][1]); append(need, dom[b][0], dom[b][1]);
					append(have1, ans[0][at], ans[0][at + 1]); append(have1, ans[1][at], ans[1][at + 1]);
					append(have2, ans[0][at], ans[1][at]); append(have2, ans[0][at + 1], ans[1][at + 1]);
					sort(have1.begin(), have1.end()); sort(have2.begin(), have2.end()); sort(need.begin(), need.end());
					if (have1 != have2 || have1 != need) continue;
					found = true;
					sol[0][0][at] = 'L', sol[0][0][at + 1] = 'R', sol[0][1][at] = 'L', sol[0][1][at + 1] = 'R';
					sol[1][0][at] = 'U', sol[1][1][at] = 'D', sol[1][0][at + 1] = 'U', sol[1][1][at + 1] = 'D';
				}
			}
			assert(found);
		} else {
			bool found = false;
			REP(aidx, len) REP(bidx, len) if (aidx != bidx) {
				int cidx = 3 - aidx - bidx;
				int a = cur[aidx], b = cur[bidx], c = cur[cidx];
				REP(aflip, 2) REP(bflip, 2) REP(cflip, 2) {
					if (found) continue;
					ans[0][at] = dom[a][aflip], ans[0][at + 1] = dom[a][aflip ^ 1];
					ans[1][at] = dom[b][bflip], ans[1][at + 1] = dom[b][bflip ^ 1];
					ans[0][at + 2] = dom[c][cflip], ans[1][at + 2] = dom[c][cflip ^ 1];
					auto append = [&](vector<pair<int,int>> &have, int x, int y) { if (x > y) swap(x, y); have.PB(MP(x, y)); };
					vector<pair<int, int>> have1, have2, need;
					append(need, dom[a][0], dom[a][1]); append(need, dom[b][0], dom[b][1]); append(need, dom[c][0], dom[c][1]);
					append(have1, ans[0][at], ans[0][at + 1]); append(have1, ans[1][at], ans[1][at + 1]); append(have1, ans[0][at + 2], ans[1][at + 2]);
					append(have2, ans[0][at], ans[1][at]); append(have2, ans[0][at + 1], ans[0][at + 2]); append(have2, ans[1][at + 1], ans[1][at + 2]);
					sort(have1.begin(), have1.end()); sort(have2.begin(), have2.end()); sort(need.begin(), need.end());
					if (have1 != have2 || have1 != need) continue;
					//printf("have1:"); for (auto z : have1) printf(" (%d,%d)", z.first, z.second); puts("");
					found = true;
					sol[0][0][at] = 'L', sol[0][0][at + 1] = 'R', sol[0][1][at] = 'L', sol[0][1][at + 1] = 'R', sol[0][0][at + 2] = 'U', sol[0][1][at + 2] = 'D';
					sol[1][0][at] = 'U', sol[1][1][at] = 'D', sol[1][0][at + 1] = 'L', sol[1][0][at + 2] = 'R', sol[1][1][at + 1] = 'L', sol[1][1][at + 2] = 'R';
				}
			}
			assert(found);
		}
		at += len;
	}
	assert(at == w);
	return true;
}

void run() {
	scanf("%d", &ndom);
	REP(i, ndom) REP(j, 2) scanf("%d", &dom[i][j]), --dom[i][j];
	if (!solve()) { printf("-1\n"); return; }
	printf("%d %d\n", h, w);
	REPSZ(i, ans) { REPSZ(j, ans[i]) { if (j != 0) printf(" "); printf("%d", ans[i][j] + 1); } puts(""); }
	REP(k, 2) REPSZ(i, sol[k]) printf("%s\n", sol[k][i].c_str());
}

int main() {
	run();
	return 0;
}