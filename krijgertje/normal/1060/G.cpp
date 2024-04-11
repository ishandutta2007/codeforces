#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
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

const int MAXN = 100000;
const int MAXQ = 100000;

int n, nq;
int x[MAXN];
int qx[MAXQ], qt[MAXQ]; ll qans[MAXQ];

pair<int, int> o[MAXQ];
priority_queue<pair<int, pair<int, int>>> pq;

struct TreapNode { int prio, sz, l, r, par; };
struct Treap {
	int n, root;
	vector<TreapNode> nodes;
	void init(int _n) { n = _n, root = -1; nodes = vector<TreapNode>(n); REP(i, n) nodes[i].prio = rand() % 1000 * 1000000 + rand() % 1000 * 1000 + rand() % 1000, nodes[i].sz = 1, nodes[i].l = nodes[i].r = nodes[i].par = -1; }
	int get(int offset) {
		int at = root; 
		while (true) {
			//printf("at=%d offset=%d sz=%d\n", at, offset,nodes[at].sz);
			assert(at != -1 && offset < nodes[at].sz); int l = nodes[at].l, r = nodes[at].r;
			if (l != -1) { if (offset < nodes[l].sz) { at = l; continue; } offset -= nodes[l].sz; } 
			if (offset == 0) return at; else --offset;
			if (r != -1) { if (offset < nodes[r].sz) { at = r; continue; } offset -= nodes[r].sz; }
			assert(false);
		}
	}
	int find(int at) {
		int ret = 0;
		if (nodes[at].l != -1) ret += nodes[nodes[at].l].sz;
		while (nodes[at].par != -1) {
			int to = nodes[at].par;
			if (at == nodes[to].r) ret += 1 + getsz(nodes[to].l);
			at = to;
		}
		return ret;
	}
	int getsz(int a) { return a == -1 ? 0 : nodes[a].sz; }
	void setpar(int a, int b) { if (a != -1) nodes[a].par = b; }
	void split(int res, int &l, int &r, int sz) {
		if (res == -1) { assert(sz == 0); l = r = -1; }
		else if (sz <= getsz(nodes[res].l)) split(nodes[res].l, l, nodes[res].l, sz), setpar(nodes[res].l, res), r = res;
		else split(nodes[res].r, nodes[res].r, r, sz - 1 - getsz(nodes[res].l)), setpar(nodes[res].r, res), l = res;
		if (l != -1) nodes[l].par = -1; if (r != -1) nodes[r].par = -1;
		if (res != -1) nodes[res].sz = 1 + getsz(nodes[res].l) + getsz(nodes[res].r);
	}
	void merge(int &res, int l, int r) {
		if (l == -1) res = r;
		else if (r == -1) res = l;
		else if (nodes[l].prio > nodes[r].prio) merge(nodes[l].r, nodes[l].r, r), setpar(nodes[l].r,l), res = l;
		else merge(nodes[r].l, l, nodes[r].l), setpar(nodes[r].l, r), res = r;
		if (res != -1) nodes[res].sz = 1 + getsz(nodes[res].l) + getsz(nodes[res].r);
		//if (res != -1) printf("merged -> %d (%d,%d)\n", nodes[res].sz,nodes[res].l,nodes[res].r);
	}
};

Treap treap;
void initpockets(int sz) { treap.init(sz); treap.root = 0; }
int getpocket(int offset) { return treap.get(offset); }
int getoffset(int pocket) { return treap.find(pocket); }
void insertpocket(int offset, int pocket) { int l, r; treap.split(treap.root, l, r, offset); treap.merge(l, l, pocket); treap.merge(treap.root, l, r); }

/*
vector<int> pockets;
void initpockets(int sz) { pockets = vector<int>(1, 0); }
int getpocket(int offset) { assert(0 <= offset && offset < SZ(pockets)); return pockets[offset]; }
int getoffset(int pocket) { REPSZ(i, pockets) if (pockets[i] == pocket) return i; assert(false); return -1; }
void insertpocket(int offset, int pocket) { pockets.insert(pockets.begin() + offset, pocket); }
*/


void solve() {
	REP(i, nq) o[i] = MP(qx[i], i); sort(o, o + nq);

	int at = 0;
	while (at < nq && o[at].first < x[0]) {
		int id = o[at++].second;
		qans[id] = qx[id];
	}
	int cround = 0, coffset = 0, cseen = 1;
	initpockets(n);
	pq = priority_queue<pair<int, pair<int, int>>>();

	REP(i, n) {
		int cx = x[i], nx = i == n - 1 ? INT_MAX : x[i + 1];
		//printf("processing [%d..%d), cround=%d coffset=%d cseen=%d pockets", cx, nx, cround, coffset, cseen); REP(j, cseen) printf("%c%d", j == 0 ? '=' : ',', getpocket(j)); puts("");
		// process [x[i]..x[i+1])
		// needed: some structure to indicate the relative order of the pockets we've seen (including a[i])
		// needed: how many 'rounds' have we done and the offset (within the relative order) of a[i]
		while (at < nq && (nx == INT_MAX || o[at].first < nx)) {
			int id = o[at++].second;
			int qoffset = (coffset + qx[id] - cx) % cseen;
			int qround = cround + (qx[id] - cx) / cseen + (qoffset < coffset ? 1 : 0) + qt[id];
			int qpocket = getpocket(qoffset);
			pq.push(MP(-qround, MP(id, qpocket)));
		}
		int dx = nx == INT_MAX ? INT_MAX : nx - cx;
		if (dx != INT_MAX && coffset + dx < cseen) {
			cx += dx, coffset += dx;
		} else {
			int rem = cseen - coffset;
			cx += rem, coffset = 0, ++cround; if (dx != INT_MAX) dx -= rem;
			int full = dx == INT_MAX ? INT_MAX : dx / cseen;
			while (!pq.empty() && (full == INT_MAX || -pq.top().first < cround + full)) {
				int qround = -pq.top().first, id = pq.top().second.first, qpocket = pq.top().second.second; pq.pop();
				int qoffset = getoffset(qpocket);
				qans[id] = cx + (ll)(qround - cround)*cseen + qoffset;
				//printf("\tanswering q%d (%d,%d): qround=%d qpocket=%d qoffset=%d -> %lld\n", id, qx[id], qt[id], qround, qpocket, qoffset, qans[id]);
			}
			if (full == INT_MAX) break;
			cround += full, cx += full*cseen, dx -= full*cseen, coffset += dx, cx += dx, dx = 0;
		}
		insertpocket(coffset, i + 1), ++cseen;
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &x[i]);
	REP(i, nq) scanf("%d%d", &qx[i], &qt[i]);
	solve();
	REP(i, nq) printf("%lld\n", qans[i]);
}

ll bfans[MAXQ];
void bf() {
	int sz = 0; REP(i, n) sz = max(sz, x[i] + 1); REP(i, nq) sz = max(sz, qx[i] + 1);
	vector<int> cur(sz); REP(i, sz) cur[i] = i; int nxt = sz; int t = 0; int rem = nq;
	//printf("x:"); REP(i, n) printf(" %d", x[i]); puts("");
	while (rem > 0) {
		//printf("t=%d rem=%d cur", t, rem); REP(i, sz) printf("%c%d", i == 0 ? '=' : ',', cur[i]); puts("");
		REP(i, nq) if (qt[i] == t) { bfans[i] = cur[qx[i]]; --rem; }
		int at = 0, idx = 0;
		REP(i, sz) {
			if (at < n && x[at] == i) { ++at; continue; }
			cur[idx++] = cur[i];
		}
		while (idx < sz) cur[idx++] = nxt++;
		++t;
	}
}

void stress() {
	REP(rep, 10000) {
		n = 100; nq = 50; int lim = 5 * n;
		REP(i, n) x[i] = rand() % (lim - n); sort(x, x + n); REP(i, n) x[i] += i;
		REP(i, nq) { qx[i] = rand() % lim; qt[i] = rand() % 5; }
		solve();
		bf();
		bool ok = true; REP(i, nq) if (bfans[i] != qans[i]) ok = false;
		if (ok) { printf("."); continue; }
		printf("err\n");
		printf("have:"); REP(i, nq) printf(" %lld", qans[i]); puts("");
		printf("want:"); REP(i, nq) printf(" %lld", bfans[i]); puts("");
		printf("%d %d\n", n, nq); REP(i, n) { if (i != 0) printf(" "); printf("%d", x[i]); } puts(""); REP(i, nq) printf("%d %d\n", qx[i], qt[i]);
		break;
	}
}

int main() {
	run();
	//stress();
	return 0;
}