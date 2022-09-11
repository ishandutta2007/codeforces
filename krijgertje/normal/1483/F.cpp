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

const int MAXN = 1000000;
const int MAXLEN = 1000000;
const int ALPH = 26;

int n;
string s[MAXN];

struct Aho {
	struct Node { int suff, nxt[ALPH], id, suffid; Node() { suff = -1; memset(nxt, -1, sizeof(nxt)); id = suffid = -1; } };

	int root;
	vector<Node> nodes;

	int makenode() { int ret = SZ(nodes); nodes.PB(Node()); return ret; }
	int convert(char c) { return c - 'a'; }
	void init() { nodes.clear(); root = makenode(); }
	int add(const string& s, int id) {
		int at = root;
		REPSZ(i, s) {
			int x = convert(s[i]);
			int to = nodes[at].nxt[x];
			if (to == -1) to = makenode(), nodes[at].nxt[x] = to;
			at = to;
		}
		assert(nodes[at].id == -1);
		nodes[at].id = id;
		return at;
	}
	void build() {
		nodes[root].suff = root;
		queue<int> q;
		q.push(root);
		while (!q.empty()) {
			int at = q.front(); q.pop();
			REP(x, ALPH) {
				int to = nodes[at].nxt[x];
				if (to == -1) continue;
				int suff = nodes[at].suff;
				while (suff != root && nodes[suff].nxt[x] == -1) suff = nodes[suff].suff;
				if (at != root && nodes[suff].nxt[x] != -1) suff = nodes[suff].nxt[x];
				nodes[to].suff = suff;
				nodes[to].suffid = nodes[to].id != -1 ? nodes[to].id : nodes[suff].suffid;
				q.push(to);
			}
		}
	}
	int nxt(int at, char c) {
		int x = convert(c);
		while (at != root && nodes[at].nxt[x] == -1) at = nodes[at].suff;
		return nodes[at].nxt[x] != -1 ? nodes[at].nxt[x] : at;
	}
};

struct BIT {
	int n; vector<int> val;
	void init(int _n) { n = _n; val = vector<int>(n + 1, 0); }
	void mod(int idx, int by) { ++idx; while (idx <= n) { val[idx] += by; idx += idx & -idx; } }
	int get(int idx) { ++idx; int ret = 0; while (idx > 0) { ret += val[idx]; idx -= idx & -idx; } return ret; }
	int get(int lidx, int ridx) { return get(ridx) - get(lidx - 1); }
};

Aho aho;
BIT bit;

int cntblocked[MAXN];
int lastid[MAXN];

vector<int> par;
vector<vector<int>> ch;
vector<int> lidx, ridx; int nidx;

void dfsinit(int at) {
	lidx[at] = nidx++;
	for (int to : ch[at]) dfsinit(to);
	ridx[at] = nidx - 1;
}

int solve() {
	aho.init();
	REP(i, n) lastid[i] = aho.add(s[i], i);
	aho.build();

	par = vector<int>(SZ(aho.nodes));
	REPSZ(i, par) par[i] = i == aho.root ? -1 : aho.nodes[i].suff;
	//printf("par:"); REPSZ(i, par) printf(" %d", par[i]); puts("");
	ch = vector<vector<int>>(SZ(aho.nodes));
	REPSZ(i, par) if (par[i] != -1) ch[par[i]].PB(i);
	lidx = ridx = vector<int>(SZ(aho.nodes));
	nidx = 0; dfsinit(aho.root);
	

	int ret = 0;
	bit.init(nidx);
	REP(i, n) cntblocked[i] = 0;
	REP(i, n) {
		int at = aho.root;
		vector<int> who(SZ(s[i]));
		REPSZ(j, s[i]) {
			at = aho.nxt(at, s[i][j]);
			if (j == SZ(s[i]) - 1) at = aho.nodes[at].suff;
			who[j] = aho.nodes[at].suffid;
		}
		//printf("who%d:", i); REPSZ(j, who) printf(" %d", who[j]); puts("");
		vector<int> blocked;
		vector<int> opt;
		int from = SZ(s[i]);
		for (int j = SZ(s[i]) - 1; j >= 0; --j) {
			if (who[j] == -1) continue;
			int l = j - SZ(s[who[j]]) + 1;
			if (l >= from) {
				blocked.PB(who[j]);
			} else {
				opt.PB(who[j]);
				from = l;
			}
		}
		//printf("opt:"); REPSZ(j, opt) printf(" %d", opt[j]); puts("");
		for (int x : blocked) ++cntblocked[x], bit.mod(lidx[par[lastid[x]]], +1);
		for (int x : opt) bit.mod(lidx[par[lastid[x]]], +1);
		for (int x : opt) {
			if (cntblocked[x] == 0 && bit.get(lidx[lastid[x]], ridx[lastid[x]]) == 0) ++ret; // , printf("%d is in %d\n", x, i);
			++cntblocked[x];
		}
		for (int x : opt) --cntblocked[x];
		for (int x : opt) bit.mod(lidx[par[lastid[x]]], -1);
		for (int x : blocked) --cntblocked[x], bit.mod(lidx[par[lastid[x]]], -1);
	}
	return ret;
}

char buff[MAXLEN + 1];
void run() {
	scanf("%d", &n);
	REP(i, n) { scanf("%s", buff); s[i] = buff; }
	printf("%d\n", solve());
}

int solvestupid() {
	vector<vector<bool>> contains(n, vector<bool>(n, false));
	REP(i, n) REP(j, n) REPE(k, SZ(s[i]) - SZ(s[j])) if (s[i].substr(k, SZ(s[j])) == s[j]) contains[i][j] = true;
	int ret = 0;
	REP(i, n) REP(j, n) if (i != j && contains[i][j]) { bool ok = true; REP(k, n) if (k != i && k != j && contains[i][k] && contains[k][j]) ok = false; if (ok) ++ret; }
	return ret;
}

void stress() {
	int mxn = 20; int mxalph = 4; int mxlen = 10;
	//int mxn = 4; int mxalph = 2; int mxlen = 4;
	REP(rep, 100000) {
		int alph = rnd() % mxalph + 1;
		while (true) { n = rnd() % mxn + 1; if (alph == 1 && n > mxlen) continue; break; }
		set<string> seen;
		REP(i, n) while (true) { int len = rnd() % mxlen + 1; string cur(len, '?'); REP(j, len) cur[j] = 'a' + rnd() % alph; if (seen.count(cur)) continue; seen.insert(cur); s[i] = cur; break; }
		int have = solve();
		int want = solvestupid();
		if (have == want) { if (rep % 1000 == 999) printf("."); continue; }
		printf("err have=%d want=%d\n", have, want);
		printf("%d\n", n); REP(i, n) printf("%s\n", s[i].c_str());
		break;
	}
}


int main() {
	run();
	//stress();
	return 0;
}