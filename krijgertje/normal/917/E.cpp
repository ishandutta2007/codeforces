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

const int MAXN = 100000;
const int MAXALPH = 26;
const int MAXWORD = 100000;
const int MAXSUMWORDLEN = 100000;
const int MAXAHONODES = MAXSUMWORDLEN + 1;
const int MAXQ = 100000;
const int MAXSTNODES = 2 * MAXSUMWORDLEN + 1;
const int MAXBITNODES = MAXAHONODES >= MAXSUMWORDLEN ? MAXAHONODES : MAXSUMWORDLEN;

struct BIT {
	int bit[MAXBITNODES+1], n;
	void init(int _n) { n = _n; memset(bit, 0, sizeof(bit)); }
	void mod(int idx, int by) { ++idx; while (idx <= n) { bit[idx] += by; idx += idx&-idx; } }
	void modrange(int lidx, int ridx, int by) { mod(lidx, by); mod(ridx + 1, -by); }
	int get(int idx) { ++idx; int ret = 0; while (idx > 0) { ret += bit[idx]; idx -= idx&-idx; } return ret; }
	int getrange(int lidx, int ridx) { return get(ridx) - get(lidx - 1); }
};

struct AHO {
	int root, n;
	int dep[MAXAHONODES];
	int nxt[MAXAHONODES][MAXALPH];
	int suff[MAXAHONODES];
	int chead[MAXAHONODES], cnxt[MAXAHONODES];
	int lid[MAXAHONODES], rid[MAXAHONODES], nid;
	int leaf[MAXWORD];
	void init() { n = 0; memset(nxt, -1, sizeof(nxt)); root = n++; dep[root] = 0; }
	void add(char *s,int len, int id) {
		int at = root; REP(i, len) { int x = s[i] - 'a'; if (nxt[at][x] == -1) nxt[at][x] = n++, dep[nxt[at][x]] = dep[at] + 1; at = nxt[at][x]; }
		leaf[id] = at;
	}
	int q[MAXAHONODES], qhead, qtail;
	void dfsid(int at) { lid[at] = nid++; for (int to = chead[at]; to != -1; to = cnxt[to]) dfsid(to); rid[at] = nid - 1; }
	void calc() {
		suff[root] = root; REP(x, MAXALPH) if (nxt[root][x] == -1) nxt[root][x] = root;
		qhead = qtail = 0; q[qhead++] = root;
		while (qtail < qhead) {
			int at = q[qtail++];
			REP(x, MAXALPH) {
				if (nxt[at][x] != -1 && nxt[at][x] != root) {
					suff[nxt[at][x]] = at == root ? root : nxt[suff[at]][x];
					q[qhead++] = nxt[at][x];
				} else {
					nxt[at][x] = nxt[suff[at]][x];
				}
			}
		}
		REP(i, n) chead[i] = -1; REP(i, n) if (i != root) cnxt[i] = chead[suff[i]], chead[suff[i]] = i;
		nid = 0; dfsid(root);
	}
	void print(int at) {
		REP(x, MAXALPH) if (nxt[at][x]!=-1 && dep[nxt[at][x]] > dep[at]) {
			REP(i, dep[at]) printf(" "); printf("%c (%d suff=%d, id=%d..%d)\n", 'a' + x, nxt[at][x], suff[nxt[at][x]], lid[nxt[at][x]], rid[nxt[at][x]]);
			print(nxt[at][x]);
		}
	}
};

struct STNode {
	char *s; int len;
	int childs[MAXALPH];
	int suffix;
	vector<int> ids;
	STNode(char *s, int len, int id) :s(s), len(len) { memset(childs, -1, sizeof(childs)); suffix = -1; if (id != -1) ids.PB(id); }
};
struct STState { int at, x, len; STState(int at, int x, int len) :at(at), x(x), len(len) {} STState() {} };
struct ST {
	int root;
	vector<STNode> nodes;

	void init() { nodes.clear(); root = addnode(NULL, 0, -1); }
	int addnode(char *s, int len, int id) { nodes.PB(STNode(s, len, id)); return SZ(nodes) - 1; }
	int add(char *s, int n, int id) {
		//printf("adding %.*s\n", n, s);
		int atnode = root, atedge = 0, atlen = 0, pint = -1, pleaf = -1; // atedge+atlen==i
		REPE(i, n) {
			//printf("i=%d\n", i); print(root);
			while (true) {
				//printf("atnode=%d atedge=%d atlen=%d\n", atnode, atedge, atlen);
				int tonode = atedge == n ? -1 : nodes[atnode].childs[s[atedge] - 'a'];
				if (tonode != -1 && atlen >= nodes[tonode].len) {
					atedge += nodes[tonode].len;
					atlen -= nodes[tonode].len;
					atnode = tonode;
					continue;
				}
				if (tonode == -1) { // atlen should be 0, atedge should be i
					if (i != n) {
						int leaf = addnode(s + i, n - i, id);
						nodes[atnode].childs[nodes[leaf].s[0] - 'a'] = leaf;
						if (pleaf != -1) nodes[pleaf].suffix = leaf; pleaf = leaf;
					} else {
						nodes[atnode].ids.PB(id);
						if (pleaf != -1) nodes[pleaf].suffix = atnode; pleaf = -1;
					}
					if (pint != -1) nodes[pint].suffix = atnode; pint = -1;
				} else if (i == n || nodes[tonode].s[atlen] != s[i]) {
					int branch = addnode(nodes[tonode].s, atlen, -1);
					nodes[tonode].s += atlen, nodes[tonode].len -= atlen;
					nodes[atnode].childs[nodes[branch].s[0] - 'a'] = branch;
					nodes[branch].childs[nodes[tonode].s[0] - 'a'] = tonode;
					if (i != n) {
						int leaf = addnode(s + i, n - i, id);
						nodes[branch].childs[nodes[leaf].s[0] - 'a'] = leaf;
						if (pleaf != -1) nodes[pleaf].suffix = leaf; pleaf = leaf;
					} else {
						nodes[branch].ids.PB(id);
						if (pleaf != -1) nodes[pleaf].suffix = branch; pleaf = -1;
					}
					if (pint != -1) nodes[pint].suffix = branch; pint = branch;
				} else {
					if (pint != -1) assert(atlen == 0), nodes[pint].suffix = atnode; pint = -1;
					++atlen;
					break;
				}
				if (atnode == root) {
					atedge++;
					if (atlen == 0) { assert(pint == -1); break; } else --atlen;
				} else {
					atnode = nodes[atnode].suffix;
				}
			}
		}
		return root;
	}

	STState nxt(STState cur, int x) {
		if (cur.len == -1) return cur;
		STState ret;
		if (cur.len == 0) {
			if (nodes[cur.at].childs[x] == -1) return STState(cur.at, -1, -1); else ret = STState(cur.at, x, 1);
		} else {
			if (nodes[nodes[cur.at].childs[cur.x]].s[cur.len] != 'a' + x) return STState(cur.at, -1, -1); else ret = STState(cur.at, cur.x, cur.len + 1);
		}
		return nodes[nodes[ret.at].childs[ret.x]].len == ret.len ? STState(nodes[ret.at].childs[ret.x], -1, 0) : ret;
	}

	void print(int at, int depth = 0) {
		REP(i, depth) printf("  "); if (nodes[at].s != NULL) printf("'%.*s'", nodes[at].len, nodes[at].s);
		printf(" = %d", at); if (nodes[at].suffix != -1) printf(" [%d]", nodes[at].suffix);
		if (SZ(nodes[at].ids) != 0) { printf(" <"); REPSZ(i, nodes[at].ids) { if (i != 0) printf(","); printf("%d", nodes[at].ids[i]); } printf(">"); } puts("");
		REP(i, MAXALPH) if (nodes[at].childs[i] != -1) print(nodes[at].childs[i], depth + 1);
	}
};

BIT FWBIT, BWBIT;
AHO AHOFW, AHOBW;
ST STFW, STBW;

int n, nword, nq;
vector<pair<int, char> > adj[MAXN];
int woff[MAXWORD + 1], wlen[MAXWORD]; char wsfw[MAXSUMWORDLEN + 1], wsbw[MAXSUMWORDLEN + 1];

int qkind[MAXQ], qa[MAXQ], qb[MAXQ], qans[MAXQ], qstfw[MAXQ], qstbw[MAXQ], qstidx[MAXQ];
vector<int> rqa[MAXN], rqb[MAXN], rstfw[MAXSTNODES], rstbw[MAXSTNODES];

int sz[MAXN];
bool alive[MAXN];
int mark[MAXN];

void dfssz(int at, int par) {
	sz[at] = 1;
	REPSZ(i, adj[at]) {
		int to = adj[at][i].first; if (!alive[to] || to == par) continue;
		dfssz(to, at); sz[at] += sz[to];
	}
}

int centroid(int at) {
	dfssz(at, -1); int rootsz = sz[at], par = -1;
	while (true) {
		bool found = false;
		REPSZ(i, adj[at]) {
			int to = adj[at][i].first; if (!alive[to] || to == par) continue;
			if (2 * sz[to] > rootsz) { par = at; at = to; found = true; break; }
		}
		if (!found) return at;
	}
}

void dfsmark(int at, int par, int tok) {
	mark[at] = tok;
	REPSZ(i, adj[at]) {
		int to = adj[at][i].first; if (!alive[to] || to == par) continue;
		dfsmark(to, at, tok);
	}
}

bool debug = false;
void dfssolve(int at, int par, int ahofw, int ahobw, STState stfw, STState stbw) {
	if (debug) printf("dfspath(%d,%d,%d=%d,%d=%d|%d,%d,%d|%d,%d,%d)\n", at + 1, par + 1, ahofw, AHOFW.lid[ahofw], ahobw, AHOBW.lid[ahobw], stfw.at, stfw.x, stfw.len, stbw.at, stbw.x, stbw.len);
	FWBIT.mod(AHOFW.lid[ahofw], +1);
	BWBIT.mod(AHOBW.lid[ahobw], +1);
	REPSZ(i, rqa[at]) {
		int qi = rqa[at][i], node = AHOBW.leaf[qkind[qi]]; if (mark[qb[qi]] == -1 || mark[qb[qi]] == mark[qa[qi]]) continue;
		if (debug) printf("qa%d: %d->%d [ahobw%d=%d..%d]\n", qi, qa[qi] + 1, qb[qi] + 1, node, AHOBW.lid[node], AHOBW.rid[node]);
		qans[qi] += BWBIT.getrange(AHOBW.lid[node], AHOBW.rid[node]);
		qstbw[qi] = stbw.at;
	}
	REPSZ(i, rqb[at]) {
		int qi = rqb[at][i], node = AHOFW.leaf[qkind[qi]]; if (mark[qa[qi]] == -1 || mark[qa[qi]] == mark[qb[qi]]) continue;
		if (debug) printf("qb%d: %d->%d [ahofw%d=%d..%d]\n", qi, qa[qi] + 1, qb[qi] + 1, node, AHOFW.lid[node], AHOFW.rid[node]);
		qans[qi] += FWBIT.getrange(AHOFW.lid[node], AHOFW.rid[node]);
		qstfw[qi] = stfw.at;
	}
	REPSZ(i, adj[at]) {
		int to = adj[at][i].first, x = adj[at][i].second - 'a'; if (!alive[to] || to == par) continue;
		dfssolve(to, at, AHOFW.nxt[ahofw][x], AHOBW.nxt[ahobw][x], STFW.nxt(stfw, x), STBW.nxt(stbw, x));
	}
	FWBIT.mod(AHOFW.lid[ahofw], -1);
	BWBIT.mod(AHOBW.lid[ahobw], -1);
}

void decompose(int at) {
	at = centroid(at);
	//printf("centroid=%d\n", at + 1); debug = at + 1 == 2;

	mark[at] = at;
	REPSZ(i, adj[at]) {
		int to = adj[at][i].first; if (!alive[to]) continue;
		dfsmark(to, at, to);
	}
	dfssolve(at, -1, AHOFW.root, AHOBW.root, STState(STFW.root, -1, 0), STState(STBW.root, -1, 0));
	mark[at] = -1;
	REPSZ(i, adj[at]) {
		int to = adj[at][i].first; if (!alive[to]) continue;
		dfsmark(to, at, -1);
	}

	alive[at] = false;
	REPSZ(i, adj[at]) {
		int to = adj[at][i].first; if (!alive[to]) continue;
		decompose(to);
	}
}

BIT STBIT;
int wlast[MAXWORD], oldwlast[MAXSUMWORDLEN];
int bwlid[MAXSUMWORDLEN], bwrid[MAXSUMWORDLEN], bwnid[MAXWORD];

void preprocst(int at, int len) {
	REPSZ(i, STBW.nodes[at].ids) {
		int wi = STBW.nodes[at].ids[i]; if (len >= wlen[wi]) continue; int idx = woff[wi] + len;
		oldwlast[idx] = wlast[wi], wlast[wi] = idx;
		bwlid[idx] = woff[wi] + bwnid[wi]++;
		//printf("%d: (%d,%d)=%d\n", at, wi, len, idx);
	}
	REPSZ(i, rstbw[at]) {
		int qi = rstbw[at][i], wi = qkind[qi];
		qstidx[qi] = wlast[wi];
		//printf("qstidx%d=%d\n", qi, qstidx[qi]);
	}
	REP(x, MAXALPH) if (STBW.nodes[at].childs[x] != -1) preprocst(STBW.nodes[at].childs[x], len + STBW.nodes[STBW.nodes[at].childs[x]].len);
	REPSZ(i, STBW.nodes[at].ids) {
		int wi = STBW.nodes[at].ids[i]; if (len >= wlen[wi]) continue; int idx = woff[wi] + len;
		wlast[wi] = oldwlast[idx];
		bwrid[idx] = woff[wi] + bwnid[wi] - 1;
	}
}

void solvest(int at,int len) {
	REPSZ(i, STFW.nodes[at].ids) {
		int wi = STFW.nodes[at].ids[i]; if (len <= 0 || len >= wlen[wi]) continue; int idx = woff[wi] + wlen[wi] - len;
		//printf("%d: suffix of word %d of length %d\n", at, wi, len);
		STBIT.modrange(bwlid[idx], bwrid[idx], +1);
	}
	REPSZ(i, rstfw[at]) {
		int qi = rstfw[at][i], idx = qstidx[qi];
		qans[qi] += STBIT.get(bwlid[idx]);
	}
	REP(x, MAXALPH) if (STFW.nodes[at].childs[x] != -1) solvest(STFW.nodes[at].childs[x], len + STFW.nodes[STFW.nodes[at].childs[x]].len);
	REPSZ(i, STFW.nodes[at].ids) {
		int wi = STFW.nodes[at].ids[i]; if (len <= 0 || len >= wlen[wi]) continue; int idx = woff[wi] + wlen[wi] - len;
		STBIT.modrange(bwlid[idx], bwrid[idx], -1);
	}
}

void solve() {
	REP(i, nword) REP(j, wlen[i]) wsbw[woff[i] + wlen[i] - j - 1] = wsfw[woff[i] + j]; wsbw[woff[nword]] = '\0';
	REP(i, n) rqa[i].clear(), rqb[i].clear();
	REP(i, nq) rqa[qa[i]].PB(i), rqb[qb[i]].PB(i);

	AHOFW.init(); REP(i, nword) AHOFW.add(wsfw + woff[i], wlen[i], i); AHOFW.calc(); FWBIT.init(AHOFW.n);
	AHOBW.init(); REP(i, nword) AHOBW.add(wsbw + woff[i], wlen[i], i); AHOBW.calc(); BWBIT.init(AHOBW.n);
	//printf("wsfw: %s\nwsbw: %s\n", wsfw, wsbw); AHOFW.print(AHOFW.root); AHOBW.print(AHOBW.root);

	STFW.init(); REP(i, nword) STFW.add(wsfw + woff[i], wlen[i], i);
	STBW.init(); REP(i, nword) STBW.add(wsbw + woff[i], wlen[i], i);
	//printf("st\n"); STFW.print(STFW.root); STBW.print(STBW.root);

	REP(i, n) mark[i] = -1, alive[i] = true; REP(i, nq) qans[i] = 0, qstfw[i] = -1, qstbw[i] = -1, qstidx[i] = -1;
	decompose(0);

	//REP(i, nq) printf("q%d: fw=%d bw=%d\n", i, qstfw[i], qstbw[i]);
	REPSZ(i, STFW.nodes) rstfw[i].clear(); REPSZ(i, STBW.nodes) rstbw[i].clear();
	REP(i, nq) { if (qstfw[i] != -1) rstfw[qstfw[i]].PB(i); if (qstbw[i] != -1) rstbw[qstbw[i]].PB(i); }
	STBIT.init(woff[nword]);
	REP(i, nword) wlast[i] = -1, bwnid[i] = 0; REP(i, woff[nword]) oldwlast[i] = -1, bwlid[i] = bwrid[i] = -1;
	preprocst(STBW.root, 0);
	solvest(STFW.root, 0);
}

void input() {
	scanf("%d%d%d", &n, &nword, &nq);
	REP(i, n) adj[i].clear();
	REP(i, n - 1) { int a, b; char c; scanf("%d%d %c", &a, &b, &c); --a, --b; adj[a].PB(MP(b, c)); adj[b].PB(MP(a, c)); }
	woff[0] = 0; REP(i, nword) { scanf("%s", wsfw + woff[i]); wlen[i] = strlen(wsfw + woff[i]); woff[i + 1] = woff[i] + wlen[i]; }
	REP(i, nq) scanf("%d%d%d", &qa[i], &qb[i], &qkind[i]), --qa[i], --qb[i], --qkind[i];
}

void run() {
	input();
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int myrand() { return rand() % 1000 * 1000000 + rand() % 1000 * 1000 + rand() % 1000; }
void stresslarge() {
	n = MAXN, nword = min(MAXWORD, max(1, (int)sqrt(1.0*MAXSUMWORDLEN))), nq = MAXQ;
	REP(i, n) adj[i].clear();
	REP(i, n - 1) { int a = myrand() % (i + 1), b = i, x = rand() % 26; adj[a].PB(MP(b, 'a' + x)), adj[b].PB(MP(a, 'a' + x)); }
	woff[nword] = MAXSUMWORDLEN; REP(i, nword) woff[i] = myrand() % (woff[nword] - nword + 1); sort(woff, woff + nword); REP(i, nword) woff[i] += i; REP(i, nword) wlen[i] = woff[i + 1] - woff[i];
	REP(i, woff[nword]) wsfw[i] = 'a' + rand() % 26;
	REP(i, nq) qa[i] = myrand() % n, qb[i] = myrand() % n, qkind[i] = myrand() % nword;
	clock_t start = clock();
	solve();
	printf("Took %.9lf\n", double(clock() - start) / CLOCKS_PER_SEC);
}

int main() {
	run();
	//stresslarge();
	return 0;
}