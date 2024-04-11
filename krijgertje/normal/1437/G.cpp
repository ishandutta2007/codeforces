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

const int MAXN = 300000;
const int MAXQ = 300000;
const int MAXS = 4 * MAXQ;

int n, nq;
string name[MAXN];
int qkind[MAXQ]; int qidx[MAXQ], qval[MAXQ]; string qpattern[MAXQ]; int qans[MAXQ];

const int ALPH = 26;
struct Aho {
	struct Node { int suff, nxt[ALPH]; Node() { suff = -1; memset(nxt, -1, sizeof(nxt)); } };

	int root;
	vector<Node> nodes;

	int makenode() { int ret = SZ(nodes); nodes.PB(Node()); return ret; }
	int convert(char c) { return c - 'a'; }
	void init() { nodes.clear(); root = makenode(); }
	int add(const string& s) {
		int at = root; 
		REPSZ(i, s) { 
			int x = convert(s[i]);
			int to = nodes[at].nxt[x]; 
			if (to == -1) to = makenode(), nodes[at].nxt[x] = to;
			at = to; 
		}
		return at;
	}
	void build() {
		nodes[root].suff = root;
		queue<int> q;
		q.push(root);
		while (!q.empty()) {
			int at = q.front(); q.pop();
			REP(x, 26) {
				int to = nodes[at].nxt[x];
				if (to == -1) continue;
				int suff = nodes[at].suff;
				while (suff != root && nodes[suff].nxt[x] == -1) suff = nodes[suff].suff;
				if (at != root && nodes[suff].nxt[x] != -1) suff = nodes[suff].nxt[x];
				nodes[to].suff = suff;
				q.push(to);
			}
		}
	}

};

Aho aho;
int nodeforname[MAXN];
int val[MAXN];

vector<vector<int>> queries;
vector<vector<int>> ch;
vector<multiset<int>> opt;
vector<vector<pair<int, int>>> changes;

int sval[MAXS];
vector<pair<int, int>> history;
void sinit(int x, int l, int r) {
	sval[x] = -1;
	if (l != r) {
		int m = l + (r - l) / 2;
		sinit(2 * x + 1, l, m);
		sinit(2 * x + 2, m + 1, r);
	}
}
int sget(int x, int l, int r, int IDX) {
	if (l == r) {
		return sval[x];
	} else {
		int m = l + (r - l) / 2, ret = sval[x];
		if (IDX <= m) ret = max(ret, sget(2 * x + 1, l, m, IDX));
		else ret = max(ret, sget(2 * x + 2, m + 1, r, IDX));
		return ret;
	}
}
void smod(int x, int l, int r, int L, int R, int VAL) {
	if (L <= l && r <= R) {
		history.PB(MP(x, sval[x]));
		sval[x] = max(sval[x], VAL);
	} else {
		int m = l + (r - l) / 2;
		if (L <= m) smod(2 * x + 1, l, m, L, R, VAL);
		if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, VAL);
	}
}

void dfs(int at) {
	int state = SZ(history);
	REPSZ(i, changes[at]) {
		int l = changes[at][i].first, r = i + 1 < SZ(changes[at]) ? changes[at][i + 1].first - 1 : nq - 1, v = changes[at][i].second;
		if (l <= r) smod(0, 0, nq - 1, l, r, v);
	}
	REPSZ(i, queries[at]) {
		int t = queries[at][i];
		int cur = sget(0, 0, nq - 1, t);
		qans[t] = max(qans[t], cur);
	}
	REPSZ(i, ch[at]) {
		int to = ch[at][i];
		dfs(to);
	}
	while (state < SZ(history)) {
		int x = history.back().first, v = history.back().second; history.pop_back();
		sval[x] = v;
	}
}

void solve() {
	aho.init();
	REP(i, n) nodeforname[i] = aho.add(name[i]);
	aho.build();

	queries = vector<vector<int>>(SZ(aho.nodes));
	ch = vector<vector<int>>(SZ(aho.nodes));
	REPSZ(at, aho.nodes) if (at != aho.root) ch[aho.nodes[at].suff].PB(at);
	opt = vector<multiset<int>>(SZ(aho.nodes));
	changes = vector<vector<pair<int, int>>>(SZ(aho.nodes));
	REP(i, n) val[i] = 0;
	REP(i, n) { int at = nodeforname[i]; opt[at].insert(val[i]); }
	REPSZ(at, aho.nodes) if (SZ(opt[at]) != 0) { changes[at].PB(MP(0, *prev(opt[at].end()))); }

	REP(i, nq) if (qkind[i] == 1) {
		int idx = qidx[i], nval = qval[i];
		int at = nodeforname[idx];
		int before = *prev(opt[at].end());
		auto it = opt[at].find(val[idx]);
		assert(it != opt[at].end());
		opt[at].erase(it);
		val[idx] = nval;
		opt[at].insert(val[idx]);
		int after = *prev(opt[at].end());
		if (after != before) changes[at].PB(MP(i, after));
	}
	REP(i, nq) if (qkind[i] == 2) {
		string s = qpattern[i];
		int at = aho.root;
		REPSZ(j, s) {
			int x = aho.convert(s[j]);
			while (at != aho.root && aho.nodes[at].nxt[x] == -1) at = aho.nodes[at].suff;
			if (aho.nodes[at].nxt[x] != -1) at = aho.nodes[at].nxt[x];
			if (at != aho.root) queries[at].PB(i);
		}
		qans[i] = -1;
	}
	//REPSZ(at, aho.nodes) { printf("%d: suff=%d", at, aho.nodes[at].suff); REP(x, ALPH) if (aho.nodes[at].nxt[x] != -1) printf(" %c->%d", 'a' + x, aho.nodes[at].nxt[x]); REPSZ(i, queries[at]) printf(" q%d", queries[at][i]); REPSZ(i, changes[at]) printf(" %d:%d", changes[at][i].first, changes[at][i].second); puts(""); }

	sinit(0, 0, nq - 1);
	history.clear();
	dfs(aho.root);
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) cin >> name[i];
	REP(i, nq) { scanf("%d", &qkind[i]); if (qkind[i] == 1) scanf("%d%d", &qidx[i], &qval[i]), --qidx[i]; if (qkind[i] == 2) cin >> qpattern[i]; }
	solve();
	REP(i, nq) if (qkind[i] == 2) printf("%d\n", qans[i]);
}

int qansstupid[MAXQ];

void solvestupid() {
	REP(i, n) val[i] = 0;
	REP(i, nq) {
		if (qkind[i] == 1) {
			int idx = qidx[i], v = qval[i];
			val[idx] = v;
		}
		if (qkind[i] == 2) {
			qansstupid[i] = -1;
			string s = qpattern[i];
			REP(j, n) {
				if (SZ(s) < SZ(name[j])) continue;
				REPE(k, SZ(s) - SZ(name[j])) if (s.substr(k, SZ(name[j])) == name[j]) qansstupid[i] = max(qansstupid[i], val[j]);
			}
		}
	}
}

void stress() {
	REP(rep, 100000) {
		n = rnd() % 2 + 1;
		nq = rnd() % 2 + 1;
		REP(i, n) { int len = rnd() % 5 + 1; string s(len, '?'); REP(i, len) s[i] = 'a' + rnd() % 4; name[i] = s; }
		REP(i, nq) {
			qkind[i] = rnd() % 2 + 1;
			if (qkind[i] == 1) qidx[i] = rnd() % n, qval[i] = rnd() % 10 + 1;
			if (qkind[i] == 2) { int len = rnd() % 10 + 1; string s(len, '?'); REP(i, len) s[i] = 'a' + rnd() % 4; qpattern[i] = s; }
		}
		solve();
		solvestupid();
		bool ok = true; REP(i, nq) if (qkind[i] == 2 && qans[i] != qansstupid[i]) ok = false;
		if (ok) { printf("."); continue; }
		printf("err\n");
		printf("have:"); REP(i, nq) if (qkind[i] == 2) printf(" %d", qans[i]); puts("");
		printf("want:"); REP(i, nq) if (qkind[i] == 2) printf(" %d", qansstupid[i]); puts("");
		printf("%d %d\n", n, nq); REP(i, n) printf("%s\n", name[i].c_str()); REP(i, nq) { printf("%d", qkind[i]); if (qkind[i] == 1) printf(" %d %d\n", qidx[i] + 1, qval[i]); else printf(" %s\n", qpattern[i].c_str()); }
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}