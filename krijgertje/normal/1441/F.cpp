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
const int MAXM = 3 * MAXN;
struct P { int x, y; P() {} P(int x, int y) :x(x), y(y) {} };
P operator-(const P& a, const P& b) { return P(a.x - b.x, a.y - b.y); }
ll operator^(const P& a, const P& b) { return (ll)a.x * b.y - (ll)a.y * b.x; }

int n, m;
P p[MAXN];
int eto[2 * MAXM];
vector<int> adj[MAXN];

int idx[2 * MAXM], nxt[2 * MAXM], prv[2 * MAXM];
int comp[2 * MAXM];

queue<int> q;
bool alive[MAXM];

int marknode[MAXN], markedge[2 * MAXM], curmark;
vector<int> matches;

void removeedge(int cur) {
	if (!alive[cur]) return;
	int aid = 2 * cur + 0, bid = 2 * cur + 1;
	//printf("removing %d-%d\n", eto[bid], eto[aid]);
	if (comp[aid] != comp[bid]) {
		int aat = nxt[aid], bat = nxt[bid];
		while (aat != aid && bat != bid) {
			aat = nxt[aat];
			swap(aid, bid), swap(aat, bat);
		}
		assert(bat == bid);
		//printf("\t\tapath:"); for (int id = nxt[aid]; id != aid; id = nxt[id]) printf(" (%d->%d)", eto[id ^ 1], eto[id]); puts("");
		//printf("\t\tbpath:"); for (int id = nxt[bid]; id != bid; id = nxt[id]) printf(" (%d->%d)", eto[id ^ 1], eto[id]); puts("");
		while (comp[bat] != comp[aid]) {
			//printf("\trecoloring %d->%d with %d\n", eto[bat ^ 1], eto[bat], comp[aid]);
			comp[bat] = comp[aid];
			if (comp[bat] == comp[bat ^ 1]) q.push(bat >> 1);
			bat = nxt[bat];
		}
	}
	alive[cur] = false;
	prv[nxt[aid]] = prv[bid], nxt[prv[aid]] = nxt[bid];
	prv[nxt[bid]] = prv[aid], nxt[prv[bid]] = nxt[aid];
	nxt[aid] = prv[aid] = nxt[bid] = prv[bid] = comp[aid] = comp[bid] = -1;
}


void trymatchedge(int cur) {
	if (!alive[cur]) return;
	int aid = 2 * cur + 0, bid = 2 * cur + 1;
	if (comp[aid] != comp[bid]) return;
	//printf("try matching %d-%d\n", eto[bid], eto[aid]);
	int asz = 0, bsz = 0;
	queue<int> aq, bq;
	++curmark;
	aq.push(aid), markedge[aid] = curmark;
	bq.push(bid), markedge[bid] = curmark;
	while (!aq.empty()) {
		int id = aq.front(); aq.pop();
		int to = eto[id];
		if (marknode[to] != curmark) marknode[to] = curmark, ++asz;
		if (markedge[id ^ 1] != curmark) markedge[id ^ 1] = curmark, aq.push(id ^ 1);
		if (markedge[nxt[id]] != curmark) markedge[nxt[id]] = curmark, aq.push(nxt[id]);
		swap(aid, bid), swap(asz, bsz), swap(aq, bq);
	}
	//printf("->side of %d has size %d\n", eto[aid], asz);
	if (asz % 2 == 0) return;
	//printf("!!! found matching edge %d-%d\n", eto[bid], eto[aid]);
	matches.PB(cur);
	for (const int& id : adj[eto[aid]]) removeedge(id >> 1);
	for (const int& id : adj[eto[bid]]) removeedge(id >> 1);
}

bool solve() {
	REP(i, n) {
		sort(adj[i].begin(), adj[i].end(), [&](const int& a, const int& b) {
			P da = p[eto[a]] - p[i], db = p[eto[b]] - p[i];
			bool apos = da.y > 0 || da.y == 0 && da.x > 0, bpos = db.y > 0 || db.y == 0 && db.x > 0;
			if (apos != bpos) return apos;
			ll res = da ^ db; if (res != 0) return res > 0;
			assert(a == b); return false;
		});
		//printf("(%d,%d):", p[i].x, p[i].y); for (int& id : adj[i]) { int j = eto[id]; printf(" %d:(%d,%d)", id, p[j].x, p[j].y); } puts("");
	}

	REP(i, n) REPSZ(j, adj[i]) idx[adj[i][j]] = j;
	REP(i, 2 * m) nxt[i] = -1;
	REP(i, 2 * m) if (nxt[i] == -1) {
		int id = i;
		while (nxt[id] == -1) {
			comp[id] = i;
			int to = eto[id], toidx = idx[id ^ 1]; assert(to >= 0 && to < n&& toidx >= 0 && toidx < SZ(adj[to]) && adj[to][toidx] == (id ^ 1));
			int nxtidx = (toidx + 1) % SZ(adj[to]);
			nxt[id] = adj[to][nxtidx];
			id = nxt[id];
		}
	}
	REP(i, 2 * m) prv[nxt[i]] = i;
	//printf("comp:"); REP(i, 2 * m) printf(" %d", comp[i]); puts("");
	//REP(i, n) { printf("%d:", i); for (int& id : adj[i]) printf(" %d=%d", eto[id], comp[id]); puts(""); }


	q = queue<int>();
	REP(i, m) alive[i] = true;
	REP(i, m) if (comp[2 * i + 0] == comp[2 * i + 1]) q.push(i);
	curmark = -1; REP(i, n) marknode[i] = curmark; REP(i, 2 * m) markedge[i] = curmark;
	matches.clear();
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		trymatchedge(cur);
		removeedge(cur);
		//printf("new state:\n");	REP(i, n) { printf("%d:", i); for (int& id : adj[i]) if (alive[id >> 1]) printf(" %d=%d", eto[id], comp[id]); puts(""); }

	}

	return 2 * SZ(matches) == n;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, n) scanf("%d%d", &p[i].x, &p[i].y);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; eto[2 * i + 0] = b, adj[a].PB(2 * i + 0), eto[2 * i + 1] = a, adj[b].PB(2 * i + 1); }
	printf("%d\n", solve() ? 1 : 0);
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}