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

const int MAXN = 600;
const int MAXM = 600;

const int GMAXN = MAXN + MAXM + 2;
const int GMAXM = MAXN + 3 * MAXM;
struct G {
	int n, m;
	int ghead[GMAXN], gnxt[2 * GMAXM], gto[2 * GMAXM], gcap[2 * GMAXM];

	int level[GMAXN];
	int q[GMAXN], qhead, qtail;
	int gcur[GMAXN];
	int path[GMAXN], npath;

	bool incut[2 * GMAXM];

	void init(int _n) { n = _n, m = 0; REP(i, n) ghead[i] = -1; }
	int addedge(int a, int b, int cap) {
		int ret = m;
		//printf("addedge(%d,%d,%d)\n", a, b, cap);
		gnxt[m] = ghead[a], ghead[a] = m, gto[m] = b, gcap[m] = cap; ++m;
		gnxt[m] = ghead[b], ghead[b] = m, gto[m] = a, gcap[m] = 0; ++m;
		return ret;
	}
	bool calclevel(int s, int t) {
		REP(i, n) level[i] = -1; qhead = qtail = 0;
		level[s] = 0, q[qhead++] = s;
		while (qtail < qhead) {
			int at = q[qtail++];
			for (int x = ghead[at]; x != -1; x = gnxt[x]) if (gcap[x] > 0) {
				int to = gto[x]; if (level[to] == -1) level[to] = level[at] + 1, q[qhead++] = to;
			}
		}
		//printf("level:"); REP(i, n) printf(" %d", level[i]); puts("");
		return level[t] != -1;
	}
	bool augment(int at, int t, int lim, int &flow) {
		if (at == t) { flow = lim; path[npath++] = at; return true; }
		for (; gcur[at] != -1; gcur[at] = gnxt[gcur[at]]) {
			int x = gcur[at], to = gto[x];
			if (gcap[x] <= 0 || level[to] != level[at] + 1) continue;
			if (augment(to, t, min(lim, gcap[x]), flow)) { gcap[x] -= flow; gcap[x ^ 1] += flow; path[npath++] = at; return true; }
		}
		return false;
	}
	int maxflow(int s, int t) {
		int ret = 0;
		while (calclevel(s, t)) {
			REP(i, n) gcur[i] = ghead[i];
			while (true) {
				int cur; npath = 0;
				if (!augment(s, t, INT_MAX, cur)) break;
				ret += cur;
				//reverse(path, path + npath); printf("found path"); REP(i, npath) printf(" %d", path[i]); printf(" of value %lf\n", cur);
			}
		}
		return ret;
	}
};


int n, m, mxdiff;
vector<int> adj[MAXN];
int ans[MAXM];

G g;
int sid, tid, nodeid[MAXN], edgeid[MAXM], nid;

bool solve() {
	nid = 0; sid = nid++; tid = nid++; REP(i, n) nodeid[i] = nid++; REP(i, m) edgeid[i] = nid++;
	g.init(nid);
	int want = 0;
	REP(i, n) { int deg = SZ(adj[i]); if (deg > 2 * mxdiff) return false; int need = max(0, deg - mxdiff); if (need > 0) g.addedge(sid, nodeid[i], 2 * need), want += 2 * need; }
	REP(i, n) REPSZ(j, adj[i]) { int k = adj[i][j]; g.addedge(nodeid[i], edgeid[k], 1); }
	REP(i, m) g.addedge(edgeid[i], tid, 1);
	int have = g.maxflow(sid, tid);
	//printf("have=%d want=%d\n", have, want);
	if (have != want) return false;
	REP(i, m) ans[i] = -1;
	vector<int> rmap(nid, -1); REP(i, m) rmap[edgeid[i]] = i;
	int ncomp = 0;
	REP(i, n) {
		int cid = nodeid[i];
		vector<int> lst;
		for (int x = g.ghead[cid]; x != -1; x = g.gnxt[x]) {
			if (g.gcap[x ^ 1] == 0 || rmap[g.gto[x]] == -1) continue;
			lst.PB(rmap[g.gto[x]]);
		}
		assert(SZ(lst) % 2 == 0);
		for (int j = 0; j < SZ(lst); j += 2) ans[lst[j]] = ans[lst[j + 1]] = ncomp++;
	}
	REP(i, m) if (ans[i] == -1) ans[i] = ncomp++;
	return true;
}

void run() {
	scanf("%d%d%d", &n, &m, &mxdiff);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(i); adj[b].PB(i); }
	if (!solve()) {
		REP(i, m) { if (i != 0) printf(" "); printf("0"); } puts("");
	} else {
		REP(i, m) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
	}
	REP(i, n) adj[i].clear();
}

int main() {
	int n; scanf("%d", &n); FORE(i, 1, n) run();
	return 0;
}