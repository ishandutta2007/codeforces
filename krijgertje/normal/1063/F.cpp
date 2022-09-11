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

const int MAXN = 500000;

struct SegTree {
	int val[4 * MAXN];
	void init(int x, int l, int r) {
		val[x] = 0;
		if (l != r) {
			int m = l + (r - l) / 2;
			init(2 * x + 1, l, m);
			init(2 * x + 2, m + 1, r);
		}
	}
	int get(int x, int l, int r, int L, int R) {
		if (L <= l && r <= R) {
			return val[x];
		} else {
			int m = l + (r - l) / 2, ret = 0;
			if (L <= m) ret = max(ret, get(2 * x + 1, l, m, L, R));
			if (m + 1 <= R) ret = max(ret, get(2 * x + 2, m + 1, r, L, R));
			return ret;
		}
	}
	void upd(int x, int l, int r, int IDX, int VAL) {
		if (l == r) {
			val[x] = max(val[x], VAL);
		} else {
			int m = l + (r - l) / 2;
			if (IDX <= m) upd(2 * x + 1, l, m, IDX, VAL); else upd(2 * x + 2, m + 1, r, IDX, VAL);
			val[x] = max(val[2 * x + 1], val[2 * x + 2]);
		}
	}
};

const int MAXALPH = 26;

struct STNode {
	char *s; int len;
	int childs[MAXALPH];
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
		REP(i, MAXALPH) if (nodes[at].childs[i] != -1) print(nodes[at].childs[i], depth + 1);
	}
};

int n;
char s[MAXN + 1];

int dp[MAXN];
SegTree segtree;
ST sufftree;

int leafnode[MAXN];
vector<bool> isleaf; vector<int> sdep;
vector<int> lid, rid; int nid;
vector<int> dep; vector<vector<int>> up;

int finddeepestanc(int at, int mnsdep) {
	assert(sdep[at] >= mnsdep);
	for (int k = SZ(up[at]) - 1; k >= 0; --k) if (k < SZ(up[at]) && sdep[up[at][k]] >= mnsdep) at = up[at][k];
	return at;
}

bool findmatch(int pos, int len, int need) {
	//printf("\tfindmatch(%d,%d,%d)\n", pos, len, need);
	int x = finddeepestanc(leafnode[pos], len);
	return segtree.get(0, 0, n - 1, lid[x], rid[x]) >= need;
}

void dfs(int at, int par) {
	lid[at] = nid;
	int sz = 0; while ((1 << sz) <= dep[at]) ++sz; up[at] = vector<int>(sz, -1); REP(k, sz) up[at][k] = k == 0 ? par : up[up[at][k - 1]][k - 1];
	if (isleaf[at]) { leafnode[n - sdep[at]] = at; ++nid; }
	REP(x, MAXALPH) {
		int to = sufftree.nodes[at].childs[x]; if (to == -1) continue;
		sdep[to] = sdep[at] + sufftree.nodes[to].len; dep[to] = dep[at] + 1;
		dfs(to, at);
	}
	rid[at] = nid - 1;
}

int solve() {
	sufftree.init();
	sufftree.add(s, n);
	//sufftree.print(sufftree.root);
	{
		isleaf = vector<bool>(SZ(sufftree.nodes), false);
		STState state(sufftree.root, -1, 0); REP(i, n) state = sufftree.nxt(state, s[i] - 'a'); 
		//printf("%d %d %d\n", state.at, state.x, state.len);
		assert(state.len == 0);
		for (int at = state.at; at != sufftree.root; at = sufftree.nodes[at].suffix) isleaf[at] = true;
	}
	lid = rid = sdep = dep = vector<int>(SZ(sufftree.nodes), -1); up = vector<vector<int>>(SZ(sufftree.nodes));
	sdep[sufftree.root] = 0; dep[sufftree.root] = 0; dfs(sufftree.root, -1);
	//REPSZ(i, sufftree.nodes) { printf("%d: lid=%d rid=%d sdep=%d dep=%d, up=", i, lid[i], rid[i], sdep[i], dep[i]); REPSZ(k, up[i]) printf("%d ", up[i][k]); puts(""); }
	//printf("leafnode:"); REP(i, n) printf(" %d", leafnode[i]); puts("");

	segtree.init(0, 0, n - 1);
	int lim = n;
	for (int i = n - 1; i >= 0; --i) {
		dp[i] = i + 1 < n ? dp[i + 1] + 1 : 1;
		while (dp[i] >= 2) {
			//printf("\ttesting dp[%d]=%d\n", i, dp[i]);
			int nlim = i + dp[i];
			assert(nlim <= lim);
			while (nlim < lim) { int cur = --lim; segtree.upd(0, 0, n - 1, lid[leafnode[cur]], dp[cur]); }
			if (findmatch(i, dp[i] - 1, dp[i] - 1) || findmatch(i + 1, dp[i] - 1, dp[i] - 1)) break; else --dp[i];
		}
		//printf("dp[%d]=%d\n", i, dp[i]);
	}
	int ret = 0; REP(i, n) ret = max(ret, dp[i]); return ret;
}

void run() {
	scanf("%d", &n); scanf("%s", s);
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}