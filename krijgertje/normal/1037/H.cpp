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

const int MAXSLEN = 100000;
const int MAXQ = 200000;
const int MAXQLEN = 200000;
const int ALPH = 26;

struct STNode {
	char *s; int len;
	int childs[ALPH];
	int suffix;
	STNode(char *s, int len) :s(s), len(len) { memset(childs, -1, sizeof(childs)); suffix = -1; }
};
struct STState { int at, x, len; STState(int at, int x, int len) :at(at), x(x), len(len) {} STState() {} };
struct ST {
	int root;
	vector<STNode> nodes;

	void init() { nodes.clear(); root = addnode(NULL, 0); }
	int addnode(char *s, int len) { nodes.PB(STNode(s, len)); return SZ(nodes) - 1; }
	int add(char *s, int n) {
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
						int leaf = addnode(s + i, n - i);
						nodes[atnode].childs[nodes[leaf].s[0] - 'a'] = leaf;
						if (pleaf != -1) nodes[pleaf].suffix = leaf; pleaf = leaf;
					} else {
						if (pleaf != -1) nodes[pleaf].suffix = atnode; pleaf = -1;
					}
					if (pint != -1) nodes[pint].suffix = atnode; pint = -1;
				} else if (i == n || nodes[tonode].s[atlen] != s[i]) {
					int branch = addnode(nodes[tonode].s, atlen);
					nodes[tonode].s += atlen, nodes[tonode].len -= atlen;
					nodes[atnode].childs[nodes[branch].s[0] - 'a'] = branch;
					nodes[branch].childs[nodes[tonode].s[0] - 'a'] = tonode;
					if (i != n) {
						int leaf = addnode(s + i, n - i);
						nodes[branch].childs[nodes[leaf].s[0] - 'a'] = leaf;
						if (pleaf != -1) nodes[pleaf].suffix = leaf; pleaf = leaf;
					} else {
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
		printf(" = %d", at); if (nodes[at].suffix != -1) printf(" [%d]", nodes[at].suffix); puts("");
		REP(i, ALPH) if (nodes[at].childs[i] != -1) print(nodes[at].childs[i], depth + 1);
	}
};

ST st;


struct Z { int id, len, x, l, r, cnt; Z() {} Z(int id, int len, int x, int l, int r) :id(id), len(len), x(x), l(l), r(r), cnt(0) {} };

char s[MAXSLEN + 1]; int slen;
int nq; char q[MAXQLEN + 1]; int qoff[MAXQ + 1], qlen[MAXQ], ql[MAXQ], qr[MAXQ]; pair<int, char> qans[MAXQ];

int n;
vector<vector<Z>> z;
vector<int> pos; // node->index in s
int ord[MAXSLEN], rev[MAXSLEN], nord; // inorder->index in s
vector<int> l, r;
vector<pair<int, int>> e[MAXSLEN];

void dfs(int at) {
	l[at] = nord;
	if (pos[at] != -1) ord[nord++] = pos[at];
	REP(x, ALPH) if (st.nodes[at].childs[x] != -1) dfs(st.nodes[at].childs[x]);
	r[at] = nord - 1;
}

int bit[MAXSLEN + 1];
int bget(int idx) { ++idx; int ret = 0; while (idx > 0) { ret += bit[idx]; idx -= idx&-idx; } return ret; }
void bmod(int idx, int by) { ++idx; while (idx <= slen) { bit[idx] += by; idx += idx&-idx; } }

void solve() {
	st.init();
	st.add(s, slen);
	n = SZ(st.nodes);
	z = vector<vector<Z>>(n);
	REP(i, nq) {
		STState at(st.root, -1, 0);
		REPE(j, qlen[i]) {
			int x = j == qlen[i] ? -1 : q[qoff[i] + j] - 'a';
			if (ql[i] <= qr[i] - j) FOR(y, x + 1, ALPH) {
				STState to = st.nxt(at, y);
				if (to.len != -1) { int v = to.len == 0 ? to.at : st.nodes[to.at].childs[to.x]; z[v].PB(Z(i, j, y, ql[i], qr[i] - j)); }
			}
			at = st.nxt(at, x); if (at.len == -1) break;
		}
	}
	{
		STState at(st.root, -1, 0);
		REP(i, slen) { int x = s[i] - 'a'; at = st.nxt(at, x); assert(at.len != -1); }
		assert(at.len == 0);
		pos = vector<int>(n, -1);
		int v = at.at; REP(i, slen) { assert(v != -1 && v != st.root); pos[v] = i; v = st.nodes[v].suffix; } assert(v == st.root);
	}
	{
		l = r = vector<int>(n); nord = 0;
		dfs(st.root);
		assert(nord == slen);
		REP(i, nord) rev[ord[i]] = i;
	}
	
	REPSZ(i, z) REPSZ(j, z[i]) { if (z[i][j].l != 0) e[z[i][j].l - 1].PB(MP(i, j)); e[z[i][j].r].PB(MP(i, j)); }
	REPE(i, slen) bit[i] = 0;
	REP(i, slen) {
		bmod(rev[i], +1);
		REPSZ(j, e[i]) {
			int v = e[i][j].first, idx = e[i][j].second;
			int val = bget(r[v]) - bget(l[v] - 1);
			if (i == z[v][idx].r) z[v][idx].cnt += val; else z[v][idx].cnt -= val;
		}
	}

	//st.print(st.root);
	//REPSZ(i, z) if (SZ(z[i]) > 0) { printf("z%d:", i); REPSZ(j, z[i]) printf(" [%d..%d](%d,%d%c)=%d", z[i][j].l, z[i][j].r, z[i][j].id, z[i][j].len, 'a' + z[i][j].x, z[i][j].cnt); puts(""); }
	//printf("pos:"); REP(i, n) printf(" %d", pos[i]); puts("");
	//printf("ord:"); REP(i, nord) printf(" %d", ord[i]); puts("");
	//printf("lr:"); REP(i, n) printf(" %d..%d", l[i], r[i]); puts("");

	REP(i, nq) qans[i] = MP(-1, '?');
	REPSZ(i, z) REPSZ(j, z[i]) if (z[i][j].cnt > 0) { int id = z[i][j].id, len = z[i][j].len; char c = 'a' + z[i][j].x; if (len > qans[id].first || len == qans[id].first&&c < qans[id].second) qans[id] = MP(len, c); }

}

void run() {
	scanf("%s", s); slen = strlen(s);
	scanf("%d", &nq); qoff[0] = 0; REP(i, nq) { scanf("%d%d%s", &ql[i], &qr[i], q + qoff[i]); --ql[i], --qr[i]; qlen[i] = strlen(q + qoff[i]); qoff[i + 1] = qoff[i] + qlen[i]; }
	solve();
	REP(i, nq) if (qans[i].first == -1) printf("-1\n"); else { REP(j, qans[i].first) printf("%c", q[qoff[i] + j]); printf("%c", qans[i].second); puts(""); }
}

int main() {
	run();
	return 0;
}