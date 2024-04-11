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
const int MAXM = 500000;
const int MAXCOL = 500000;
const int MAXID = 2 * MAXN;

int n, m, ncol;
int col[MAXN];
int e[MAXM][2];

vector<int> insideadj[MAXN];
vector<int> bycol[MAXCOL];

int nid;
int id[MAXN];
bool done[MAXN];
bool colbipartite[MAXCOL];

bool use[MAXID];
vector<int> uselst;
vector<int> outsideadj[MAXID];
bool seen[MAXID];
int side[MAXID];

ll solve() {
	REP(i, m) {
		int a = e[i][0], b = e[i][1];
		if (col[a] != col[b]) continue;
		insideadj[a].PB(b), insideadj[b].PB(a);
	}
	REP(i, n) bycol[col[i]].PB(i);

	nid = 0;
	REP(i, n) done[i] = false;
	REP(c, ncol) {
		bool ok = true;
		REPSZ(_, bycol[c]) {
			int s = bycol[c][_];
			if (done[s]) continue;
			queue<int> q;
			q.push(s);
			id[s] = nid;
			done[s] = true;
			nid += 2;
			while (!q.empty()) {
				int at = q.front(); q.pop();
				REPSZ(i, insideadj[at]) {
					int to = insideadj[at][i];
					assert(col[to] == c);
					if (done[to]) {
						if (id[to] == id[at]) ok = false;
					} else {
						id[to] = id[at] ^ 1;
						done[to] = true;
						q.push(to);
					}
				}
			}
		}
		colbipartite[c] = ok;
	}
	assert(nid <= 2 * n);

	int cntcolbipartite = 0;
	REP(c, ncol) if (colbipartite[c]) ++cntcolbipartite;
	ll ret = (ll)cntcolbipartite * (cntcolbipartite - 1) / 2;

	map<pair<int, int>, vector<int>> bicoledges;
	REP(i, m) {
		int a = e[i][0], b = e[i][1];
		if (col[a] == col[b]) continue;
		if (!colbipartite[col[a]] || !colbipartite[col[b]]) continue;
		int x = col[a], y = col[b];
		if (x > y) swap(x, y);
		bicoledges[MP(x, y)].PB(i);
	}

	REP(i, nid) use[i] = false;
	for (auto it = bicoledges.begin(); it != bicoledges.end(); ++it) {
		int c1 = it->first.first, c2 = it->first.second;
		vector<int> edges = it->second;
		//printf("processing (%d,%d) (cnt=%d)\n", c1 + 1, c2 + 1, SZ(edges));
		uselst.clear();
		REPSZ(i, edges) {
			int idx = edges[i];
			REP(j, 2) {
				int a = id[e[idx][j]];
				if (!use[a]) use[a] = true, uselst.PB(a);
			}
		}
		REPSZ(i, edges) {
			int idx = edges[i];
			int a = id[e[idx][0]], b = id[e[idx][1]];
			outsideadj[a].PB(b), outsideadj[b].PB(a);
		}
		REPSZ(i, uselst) {
			int a = uselst[i], b = a ^ 1;
			if (!use[b]) continue;
			if (b != a + 1) continue;
			outsideadj[a].PB(b), outsideadj[b].PB(a);
		}
		REPSZ(i, uselst) {
			int a = uselst[i];
			seen[a] = false;
			side[a] = -1;
		}
		bool ok = true;
		REPSZ(_, uselst) {
			int s = uselst[_];
			if (seen[s]) continue;
			queue<int> q;
			q.push(s);
			side[s] = 0;
			seen[s] = true;
			while (!q.empty()) {
				int at = q.front(); q.pop();
				REPSZ(i, outsideadj[at]) {
					int to = outsideadj[at][i];
					if (seen[to]) {
						if (side[to] == side[at]) ok = false;
					} else {
						side[to] = 1 - side[at];
						seen[to] = true;
						q.push(to);
					}
				}
			}
		}
		if (!ok) --ret;

		REPSZ(i, uselst) use[uselst[i]] = false, outsideadj[uselst[i]].clear();
	}

	return ret;
}

void run() {
	scanf("%d%d%d", &n, &m, &ncol);
	REP(i, n) scanf("%d", &col[i]), --col[i];
	REP(i, m) REP(j, 2) scanf("%d", &e[i][j]), --e[i][j];
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}