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
const int MAXQ = 100000;
const int NBIT = 20;

struct Node {
	int prefix, bit;
	int lazyset, lazyclear, lazyflip;
	int cntleaf, bothmask;
	int ch[2];
	Node() { lazyset = lazyclear = lazyflip = 0; ch[0] = ch[1] = -1; }
};

int n, nq;
int a[MAXN];
int qkind[MAXQ], ql[MAXQ], qr[MAXQ], qval[MAXQ];
int qans[MAXQ];

vector<Node> nodes;
queue<int> pool;

void print(int x,int v=-1) {
	REP(i, NBIT - 1 - nodes[x].bit) printf(" ");
	printf("%d:", x); if (v != -1) printf("%d", v); printf("[pref=%d cntleaf=%d", nodes[x].prefix, nodes[x].cntleaf);
	if (nodes[x].lazyset != 0) printf(" lazyset=%x", nodes[x].lazyset); 
	if (nodes[x].lazyclear != 0) printf(" lazyclear=%x", nodes[x].lazyclear);
	if (nodes[x].lazyflip != 0) printf(" lazyflip=%x", nodes[x].lazyflip);
	printf("]\n");
	REP(v, 2) if (nodes[x].ch[v] != -1) assert(nodes[nodes[x].ch[v]].bit == nodes[x].bit - 1), print(nodes[x].ch[v], v);
}

void update(int x) {
	nodes[x].cntleaf = (nodes[x].bit == -1 ? 1 : 0) + (nodes[x].ch[0] != -1 ? nodes[nodes[x].ch[0]].cntleaf : 0) + (nodes[x].ch[1] != -1 ? nodes[nodes[x].ch[1]].cntleaf : 0);
	nodes[x].bothmask = (nodes[x].ch[0] != -1 && nodes[x].ch[1] != -1 ? (1 << nodes[x].bit) : 0) | (nodes[x].ch[0] != -1 ? nodes[nodes[x].ch[0]].bothmask : 0) | (nodes[x].ch[1] != -1 ? nodes[nodes[x].ch[1]].bothmask : 0);
}
int createnode() {
	if (!pool.empty()) { int ret = pool.front(); pool.pop(); nodes[ret] = Node(); return ret; }
	int ret = SZ(nodes); nodes.PB(Node()); return ret;
}
int createnode(int prefix, int bit) {
	int ret = createnode();
	nodes[ret].prefix = prefix, nodes[ret].bit = bit;
	update(ret);
	return ret;
}
void releasenode(int x) {
	pool.push(x);
}
void applyset(int x, int val) {
	nodes[x].prefix |= val & ~((1 << (nodes[x].bit + 1)) - 1);
	assert((nodes[x].bothmask & val) == 0);
	if (nodes[x].bit == -1) return;
	if (val & (1 << nodes[x].bit)) {
		if (nodes[x].ch[0] != -1) { assert(nodes[x].ch[1] == -1); swap(nodes[x].ch[0], nodes[x].ch[1]); }
	}
	nodes[x].lazyset |= val;
	nodes[x].lazyclear &= ~val;
	nodes[x].lazyflip &= ~val;
}
void applyclear(int x, int val) {
	nodes[x].prefix &= ~(val & ~((1 << (nodes[x].bit + 1)) - 1));
	assert((nodes[x].bothmask & val) == 0);
	if (nodes[x].bit == -1) return;
	if (val & (1 << nodes[x].bit)) {
		if (nodes[x].ch[1] != -1) { assert(nodes[x].ch[0] == -1); swap(nodes[x].ch[0], nodes[x].ch[1]); }
	}
	nodes[x].lazyclear |= val;
	nodes[x].lazyset &= ~val;
	nodes[x].lazyflip &= ~val;
}
void applyflip(int x, int val) {
	nodes[x].prefix ^= val & ~((1 << (nodes[x].bit + 1)) - 1);
	if (nodes[x].bit == -1) return;
	if (val & (1 << nodes[x].bit)) {
		swap(nodes[x].ch[0], nodes[x].ch[1]);
	}
	nodes[x].lazyflip ^= val;
}
void push(int x) {
	if (nodes[x].lazyset != 0) { REP(v, 2) if (nodes[x].ch[v] != -1) applyset(nodes[x].ch[v], nodes[x].lazyset); nodes[x].lazyset = 0; }
	if (nodes[x].lazyclear != 0) { REP(v, 2) if (nodes[x].ch[v] != -1) applyclear(nodes[x].ch[v], nodes[x].lazyclear); nodes[x].lazyclear = 0; }
	if (nodes[x].lazyflip != 0) { REP(v, 2) if (nodes[x].ch[v] != -1) applyflip(nodes[x].ch[v], nodes[x].lazyflip); nodes[x].lazyflip = 0; }
}
void merge(int x, int y) {
	//printf("merge(%d,%d)\n", nodes[x].bit, nodes[y].bit);
	//print(x);
	//print(y);
	push(x); push(y);
	assert(nodes[x].bit == nodes[y].bit && nodes[x].prefix == nodes[y].prefix);
	REP(v, 2) {
		int xx = nodes[x].ch[v], yy = nodes[y].ch[v];
		if (yy == -1) continue;
		if (xx == -1) { nodes[x].ch[v] = yy; continue; }
		merge(xx, yy);
	}
	update(x);
	releasenode(y);
}
void insert(int x, int y) {
	//printf("insert(%d,%d)\n", nodes[x].bit, nodes[y].bit);
	assert(nodes[x].bit >= nodes[y].bit);
	push(x); push(y);
	if (nodes[x].bit == nodes[y].bit) {
		merge(x, y);
	} else {
		int v = (nodes[y].prefix >> nodes[x].bit) & 1;
		if (nodes[x].ch[v] == -1) {
			int z = createnode(nodes[x].prefix | (v << nodes[x].bit), nodes[x].bit - 1);
			nodes[x].ch[v] = z;
		}
		assert(nodes[nodes[x].ch[v]].bit == nodes[x].bit - 1);
		insert(nodes[x].ch[v], y);
		update(x);
	}
}
bool extract(int x, int l, int r, int L, int R, vector<int>& lst) { // [l,r) and [L,R)
	push(x);
	if (L <= l && r <= R) {
		lst.PB(x);
		return true;
	} else {
		int m = l + (r - l) / 2;
		if (nodes[x].ch[0] != -1 && L < m) {
			bool rem = extract(nodes[x].ch[0], l, m, L, R, lst);
			if (rem) nodes[x].ch[0] = -1;
		}
		if (nodes[x].ch[1] != -1 && m < R) {
			bool rem = extract(nodes[x].ch[1], m, r, L, R, lst);
			if (rem) nodes[x].ch[1] = -1;
		}
		if (nodes[x].ch[0] == -1 && nodes[x].ch[1] == -1) {
			releasenode(x);
			return true;
		}
		update(x);
		return false;
	}
}
void resolveclear(int x, int val) {
	nodes[x].prefix &= ~(val & ~((1 << (nodes[x].bit + 1)) - 1));
	if (nodes[x].bit == -1) return;
	if ((nodes[x].bothmask & val) == 0) { applyclear(x, val); return; }
	push(x);
	if (val & (1 << nodes[x].bit)) {
		if (nodes[x].ch[1] != -1) {
			applyclear(nodes[x].ch[1], 1 << nodes[x].bit);
			if (nodes[x].ch[0] == -1) swap(nodes[x].ch[0], nodes[x].ch[1]);
			else { merge(nodes[x].ch[0], nodes[x].ch[1]); nodes[x].ch[1] = -1; }
		}
	}
	REP(v, 2) if (nodes[x].ch[v] != -1) resolveclear(nodes[x].ch[v], val);
	update(x);
}
void resolveset(int x, int val) {
	nodes[x].prefix |= val & ~((1 << (nodes[x].bit + 1)) - 1);
	if (nodes[x].bit == -1) return;
	if ((nodes[x].bothmask & val) == 0) { applyset(x, val); return; }
	push(x);
	if (val & (1 << nodes[x].bit)) {
		if (nodes[x].ch[0] != -1) {
			applyset(nodes[x].ch[0], 1 << nodes[x].bit);
			if (nodes[x].ch[1] == -1) swap(nodes[x].ch[0], nodes[x].ch[1]);
			else { merge(nodes[x].ch[1], nodes[x].ch[0]); nodes[x].ch[0] = -1; }
		}
	}
	REP(v, 2) if (nodes[x].ch[v] != -1) resolveset(nodes[x].ch[v], val);
	update(x);
}
void resolveflip(int x, int val) {
	applyflip(x, val);
}

void solve() {
	sort(a, a + n);
	n = unique(a, a + n) - a;

	nodes.clear();
	pool = queue<int>();
	int root = createnode(0, NBIT - 1);
	REP(i, n) insert(root, createnode(a[i], -1));

	REP(i, nq) {
		//printf("q%d\n", i);
		//print(root);
		vector<int> lst;
		bool newroot = extract(root, 0, (1 << NBIT), ql[i], qr[i] + 1, lst);
		//printf("SZ(lst)=%d\n", SZ(lst));
		//for (int x : lst) print(x);
		//if (!newroot) printf("root\n"), print(root), printf("done\n");
		if (qkind[i] == 1) {
			for (int x : lst) {
				resolveclear(x, (1 << NBIT) - 1 - qval[i]);
			}
		}
		if (qkind[i] == 2) {
			for (int x : lst) {
				resolveset(x, qval[i]);
			}
		}
		if (qkind[i] == 3) {
			for (int x : lst) {
				resolveflip(x, qval[i]);
			}
		}
		//if (qkind[i] != 4) for (int x : lst) print(x);
		if (qkind[i] == 4) {
			qans[i] = 0;
			for (int x : lst) qans[i] += nodes[x].cntleaf;
		}
		if (newroot) root = createnode(0, NBIT - 1);
		for (int x : lst) insert(root, x);
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &a[i]);
	REP(i, nq) {
		scanf("%d%d%d", &qkind[i], &ql[i], &qr[i]);
		if (qkind[i] != 4) scanf("%d", &qval[i]);
	}
	solve();
	REP(i, nq) if (qkind[i] == 4) printf("%d\n", qans[i]);
}

int qansstupid[MAXQ];

void solvestupid() {
	set<int> cur;
	REP(i, n) cur.insert(a[i]);
	REP(i, nq) {
		int l = ql[i], r = qr[i];
		auto it = cur.lower_bound(l);
		qansstupid[i] = 0;
		vector<int> rem;
		while (it != cur.end() && *it <= r) {
			++qansstupid[i];
			rem.PB(*it);
			cur.erase(it++);
		}
		for (int x : rem) {
			if (qkind[i] == 1) x = x&qval[i];
			if (qkind[i] == 2) x = x | qval[i];
			if (qkind[i] == 3) x = x^qval[i];
			cur.insert(x);
		}
	}
}

void stress() {
	int mxbit = 20, mxn = 1000, mxq = 1000;
	//int mxbit = 4, mxn = 10, mxq = 5;
	REP(rep, 10000) {
		int nbit = rnd() % mxbit + 1;
		n = rnd() % min(mxn, 1 << nbit) + 1;
		set<int> seen;
		REP(i, n) while (true) { int x = rnd() % (1 << nbit); if (seen.count(x)) continue; seen.insert(x); a[i] = x; break; }
		nq = rnd() % mxq + 1;
		REP(i, nq) {
			qkind[i] = rnd() % 4 + 1;
			ql[i] = rnd() % (1 << nbit), qr[i] = rnd() % (1 << nbit); if (ql[i] > qr[i]) swap(ql[i], qr[i]);
			if (qkind[i] != 4) qval[i] = rnd() % (1 << nbit);
		}
		//printf("%d %d\n", n, nq); REP(i, n) { if (i != 0) printf(" "); printf("%d", a[i]); } puts(""); REP(i, nq) { printf("%d %d %d", qkind[i], ql[i], qr[i]); if (qkind[i] != 4) printf(" %d", qval[i]); puts(""); }
		solve();
		solvestupid();
		bool ok = true; REP(i, nq) if (qkind[i] == 4 && qans[i] != qansstupid[i]) ok = false;
		if (ok) { printf("."); continue; }
		printf("err\n");
	}
}

int main() {
	run();
	//stress();
	return 0;
}