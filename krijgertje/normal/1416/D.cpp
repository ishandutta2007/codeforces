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
const int MAXM = 300000;
const int MAXQ = 500000;
const int MAXLG = 19;
const int MAXS = 4 * MAXN;
struct E { int a, b; };

int n, m, nq;
int val[MAXN];
E e[MAXM];
int qkind[MAXQ], qv[MAXQ], qidx[MAXQ], qans[MAXQ];


int trem[MAXM];
pair<int, int> edgeorder[MAXM];
bool intree[MAXM];

struct UF {
	int n; vector<int> par, sz;
	void init(int _n) { n = _n; par = sz = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1; }
	int find(int x) { return par[x] == x ? x : par[x] = find(par[x]); }
	bool unite(int x, int y) { x = find(x), y = find(y); if (x == y) return false; if (sz[x] < sz[y]) swap(x, y); par[y] = x, sz[x] += sz[y]; return true; }
};

UF uf;
int root[MAXN];

int par[MAXM + MAXN];
vector<int> ch[MAXM + MAXN];

pair<int,int> up[MAXM + MAXN][MAXLG + 1];

int lid[MAXM + MAXN], rid[MAXM + MAXN], nid; // [lid,rid)
int who[MAXN];

void dfsid(int at) {
	lid[at] = nid;
	if (at >= m) who[nid] = at - m, ++nid;
	REPSZ(i, ch[at]) dfsid(ch[at][i]);
	rid[at] = nid;
}

void printtree(int at, int dep) {
	REP(i, dep) printf("  "); printf("%d\n", at);
	REPSZ(i, ch[at]) printtree(ch[at][i], dep + 1);
}

int jump(int at, int t) {
	for (int k = MAXLG; k >= 0; --k) if (t < up[at][k].second) at = up[at][k].first;
	return at;
}

pair<int, int> sval[MAXS];

void spull(int x) {
	pair<int, int> a = sval[2 * x + 1], b = sval[2 * x + 2];
	sval[x] = a; if (b.first > a.first || b.first == a.first && b.second < a.second) sval[x] = b;
}
void sinit(int x, int l, int r) {
	if (l == r) {
		sval[x] = MP(val[who[l]], l);
	} else {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
		spull(x);
	}
}
void smod(int x, int l, int r, int IDX, int VAL) {
	if (l == r) {
		sval[x] = MP(VAL, l);
	} else {
		int m = l + (r - l) / 2;
		if (IDX <= m) smod(2 * x + 1, l, m, IDX, VAL);
		if (m + 1 <= IDX) smod(2 * x + 2, m + 1, r, IDX, VAL);
		spull(x);
	}
}
pair<int, int> sget(int x, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		return sval[x];
	} else {
		int m = l + (r - l) / 2; pair<int, int> ret = MP(INT_MIN, -1);
		if (L <= m) { pair<int, int> cur = sget(2 * x + 1, l, m, L, R); if (cur.first > ret.first || cur.first == ret.first && cur.second < ret.second) ret = cur; }
		if (m + 1 <= R) { pair<int, int> cur = sget(2 * x + 2, m + 1, r, L, R); if (cur.first > ret.first || cur.first == ret.first && cur.second < ret.second) ret = cur; }
		return ret;
	}
}


void solve() {
	REP(i, m) trem[i] = nq;
	REP(i, nq) if (qkind[i] == 2) trem[qidx[i]] = i;
	REP(i, m) edgeorder[i] = MP(-trem[i], i);
	sort(edgeorder, edgeorder + m);
	uf.init(n);
	REP(i, m) {
		int id = edgeorder[i].second;
		intree[id] = uf.unite(e[id].a, e[id].b);
	}
	uf.init(n);
	REP(i, m + n) par[i] = -1, ch[i].clear();
	REP(i, n) root[i] = m + i;
	REP(i, m) {
		int id = edgeorder[i].second;
		if (!intree[id]) continue;
		int x = uf.find(e[id].a), y = uf.find(e[id].b);
		assert(x != y);
		ch[id].PB(root[x]); ch[id].PB(root[y]); par[root[x]] = par[root[y]] = id;
		assert(uf.unite(x, y));
		root[uf.find(x)] = id;
	}
	//REP(i, m) if (par[i] == -1 && SZ(ch[i]) >= 1) printtree(i, 0);

	REP(i, m + n) up[i][0] = par[i] == -1 ? MP(i, nq) : MP(par[i], trem[par[i]]);
	REP(k, MAXLG) REP(i, m + n) up[i][k + 1] = MP(up[up[i][k].first][k].first, min(up[i][k].second, up[up[i][k].first][k].second));
	//REP(i, n) { printf("%d:", i + 1); REP(t, nq) printf(" %d", jump(m + i, t)); puts(""); }

	nid = 0; REP(i, m + n) if (par[i] == -1) dfsid(i);
	//REP(i, m + n) if (i >= m || SZ(ch[i]) >= 1) printf("%d: %d..%d\n", i, lid[i], rid[i]);
	assert(nid == n);

	sinit(0, 0, n - 1);
	REP(i, nq) if (qkind[i] == 1) {
		int at = jump(m + qv[i], i);
		//printf("%d: %d\n", i, at);
		assert(lid[at] < rid[at]);
		pair<int, int> cur = sget(0, 0, n - 1, lid[at], rid[at] - 1);
		qans[i] = cur.first;
		smod(0, 0, n - 1, cur.second, 0);
	}
}

void run() {
	scanf("%d%d%d", &n, &m, &nq);
	REP(i, n) scanf("%d", &val[i]);
	REP(i, m) scanf("%d%d", &e[i].a, &e[i].b), --e[i].a, --e[i].b;
	REP(i, nq) {
		scanf("%d", &qkind[i]);
		if (qkind[i] == 1) scanf("%d", &qv[i]), --qv[i];
		if (qkind[i] == 2) scanf("%d", &qidx[i]), --qidx[i];
	}
	solve();
	REP(i, nq) if (qkind[i] == 1) printf("%d\n", qans[i]);
}

int qansstupid[MAXQ];

void solvestupid() {
	vector<bool> dead(m, false);
	vector<int> curval(n); REP(i, n) curval[i] = val[i];
	REP(i, nq) {
		if (qkind[i] == 2) { dead[qidx[i]] = true; continue; }
		int v = qv[i];
		vector<bool> seen(n, false);
		queue<int> q;
		seen[v] = true, q.push(v);
		while (!q.empty()) {
			int at = q.front(); q.pop();
			REP(j, m) if (!dead[j] && (e[j].a == at || e[j].b == at)) {
				int to = e[j].a + e[j].b - at;
				if (!seen[to]) seen[to] = true, q.push(to);
			}
		}
		int best = v; REP(j, n) if (seen[j] && curval[j] > curval[best]) best = j;
		qansstupid[i] = curval[best]; curval[best] = 0;
	}
}

void stress() {
	int mxn = 5, mxm = 4, mxq = 2;
	REP(rep, 100000) {
		n = rnd() % mxn + 1, m = n == 1 ? 0 : rnd() % min(n * (n - 1) / 2, mxm) + 1, nq = rnd() % mxq + 1;
		REP(i, n) val[i] = i + 1;
		REP(i, n) { int idx = rnd() % (i + 1); swap(val[i], val[idx]); }
		set<pair<int, int>> have;
		REP(i, m) while (true) { int a = rnd() % n, b = rnd() % n; if (a == b || have.count(MP(a, b)) || have.count(MP(b, a))) continue; e[i].a = a, e[i].b = b; have.insert(MP(a, b)); break; }
		set<int> removed;
		REP(i, nq) {
			if (SZ(removed) < m && rnd() % 2 == 0) {
				qkind[i] = 2;
				while (true) { int idx = rnd() % m; if (removed.count(idx)) continue; qidx[i] = idx; removed.insert(idx); break; }
			} else {
				qkind[i] = 1;
				qv[i] = rnd() % n;
			}
		}
		solve();
		solvestupid();
		bool ok = true;
		REP(i, nq) if (qkind[i] == 1 && qans[i] != qansstupid[i]) ok = false;
		if (ok) { if (rep % 100 == 99) printf("."); continue; }
		printf("err\n");
		printf("%d %d %d\n", n, m, nq);
		REP(i, n) { if (i != 0) printf(" "); printf("%d", val[i]); } puts("");
		REP(i, m) printf("%d %d\n", e[i].a + 1, e[i].b + 1);
		REP(i, nq) printf("%d %d\n", qkind[i], qkind[i] == 1 ? qv[i] + 1 : qidx[i] + 1);
		printf("have:"); REP(i, nq) if (qkind[i] == 1) printf(" %d", qans[i]); puts("");
		printf("want:"); REP(i, nq) if (qkind[i] == 1) printf(" %d", qansstupid[i]); puts("");
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}