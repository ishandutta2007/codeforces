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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXSLEN = 100000;
const int MAXQLEN = 100000;
const int BSZ = 200;
const int MAXB = (MAXSLEN + BSZ - 1) / BSZ;

char s[MAXSLEN + 1]; int slen;
char q[MAXQLEN + 1]; int qlen;

int nb;
int bl[MAXB], br[MAXB];

typedef struct Node {
	int start, end;
	int childs[27];
	int suffix;
	int nleafs;
	Node(int start, int end) :start(start), end(end) { memset(childs, -1, sizeof(childs)); suffix = -1; }
} Node;

struct SuffTree {
	int n; char s[BSZ + 2];
	vector<Node> nodes; int root;
	int addnode(int start, int end) {
		nodes.push_back(Node(start, end));
		return SZ(nodes) - 1;
	}

	void build(char *_s, int _n) {
		n = _n; REP(i, n) s[i] = _s[i]; s[n++] = '{'; s[n] = '\0';
		nodes.clear(); root = addnode(0, 0);
		int atnode = root, atedge = 0, atlen = 0, rem = 0, prev = -1;
		for (int i = 0; i < n; ++i) {
			++rem; prev = -1;
			while (rem > 0) {
				int tonode = nodes[atnode].childs[s[atedge] - 'a'];
				int tostart = tonode == -1 ? -1 : nodes[tonode].start;
				if (tonode != -1 && nodes[tonode].start + atlen >= nodes[tonode].end) {
					atedge += nodes[tonode].end - nodes[tonode].start;
					atlen -= nodes[tonode].end - nodes[tonode].start;
					atnode = tonode;
					continue;
				}
				if (tonode == -1) { //atlen should be 0
					int leaf = addnode(i, n);
					nodes[atnode].childs[s[atedge] - 'a'] = leaf;
					if (prev != -1) nodes[prev].suffix = atnode; prev = atnode;
				}
				else if (s[tostart + atlen] == s[i]) {
					++atlen;
					if (prev != -1) nodes[prev].suffix = atnode; prev = atnode;
					break;
				}
				else {
					int branch = addnode(tostart, tostart + atlen);
					nodes[tonode].start += atlen;
					int leaf = addnode(i, n);
					nodes[atnode].childs[s[atedge] - 'a'] = branch;
					nodes[branch].childs[s[tostart + atlen] - 'a'] = tonode;
					nodes[branch].childs[s[i] - 'a'] = leaf;
					if (prev != -1) nodes[prev].suffix = branch; prev = branch;
				}
				--rem;
				if (atnode == root) {
					if (atlen > 0) --atlen;
					atedge++;
				}
				else {
					atnode = nodes[atnode].suffix;
				}
			}
		}
	}

	void dfs(int at) {
		nodes[at].nleafs = nodes[at].end == n ? 1 : 0;
		REP(i, 27) { int to = nodes[at].childs[i]; if (to == -1) continue; dfs(to); nodes[at].nleafs += nodes[to].nleafs; }
	}

	void print(int node, int depth) {
		for (int i = 0; i<depth; ++i) printf("  ");
		printf("'"); for (int i = nodes[node].start; i<nodes[node].end; ++i) printf("%c", s[i]); printf("'");
		if (nodes[node].end != n) printf(" -> %d", node); if (nodes[node].suffix != -1) printf(" [%d]", nodes[node].suffix); printf(" <%d>", nodes[node].nleafs); puts("");
		for (int i = 0; i<27; ++i) if (nodes[node].childs[i] != -1) print(nodes[node].childs[i], depth + 1);
	}

	int solve() {
		int at = root, pos = 0;
		REP(i, qlen) {
			if (pos == nodes[at].end - nodes[at].start) {
				int to = nodes[at].childs[q[i]-'a']; if (to == -1) return 0; at = to, pos = 1;
			} else {
				if (q[i] != s[nodes[at].start + pos]) return 0; ++pos;
			}
		}
		return nodes[at].nleafs;
	}
};

SuffTree st[MAXB];
void buildblock(int b) {
	st[b].build(s + bl[b], br[b] - bl[b]);
	st[b].dfs(st[b].root);
	//st[b].print(st[b].root, 0);
}

int solveblock(int b) {
	return st[b].solve();
}

int kmp[MAXQLEN + 1]; // kmp[i] = maximum proper suffix of q[0..i) that is also a prefix of q

void buildkmp() {
	kmp[0] = kmp[1] = 0;
	FORE(i, 2, qlen) {
		kmp[i] = kmp[i - 1];
		while (kmp[i] != 0 && q[i - 1] != q[kmp[i]]) kmp[i] = kmp[kmp[i]];
		if (q[i - 1] == q[kmp[i]]) ++kmp[i];
	}
}

int solvekmp(int ql, int qr) {
	int at = 0, ret = 0;
	FORE(i, ql, qr) {
		while (at != 0 && s[i] != q[at]) at = kmp[at];
		if (s[i] == q[at]) ++at;
		if (at == qlen) ++ret, at = kmp[at];
	}
	return ret;
}

int solvesmall(int ql, int qr) {
	buildkmp();
	if (ql / BSZ == qr / BSZ || ql / BSZ == qr / BSZ - 1) return solvekmp(ql, qr);
	int ret = 0;
	if (ql%BSZ != 0) { int nql = ql + BSZ - ql%BSZ; ret += solvekmp(ql, nql + qlen - 2); ql = nql; }
	if (qr%BSZ != BSZ - 1) { int nqr = qr - qr%BSZ - 1; ret += solvekmp(nqr - qlen + 2, qr); qr = nqr; }
	int qlb = ql / BSZ, qrb = qr / BSZ;
	FORE(b, qlb, qrb) {
		ret += solveblock(b);
		if (b + 1 <= qrb&&qlen >= 2) ret += solvekmp((b + 1)*BSZ - qlen + 1, (b + 1)*BSZ + qlen - 2);
	}
	return ret;
}

int solvelarge(int ql, int qr) {
	buildkmp();
	return solvekmp(ql, qr);
}

void run() {
	scanf("%s", s); slen = strlen(s);
	//slen = MAXSLEN; REP(i, slen) s[i] = 'a' + i % 25; s[slen] = '\0';
	nb = (slen + BSZ - 1) / BSZ;
	REP(i, nb) bl[i] = i*BSZ, br[i] = min(slen, (i + 1)*BSZ);
	REP(i, nb) buildblock(i);

	int nq; scanf("%d", &nq);
	REP(i, nq) {
		int kind; scanf("%d", &kind);
		if (kind == 1) {
			int idx; char c; scanf("%d %c", &idx, &c); --idx;
			s[idx] = c; buildblock(idx / BSZ);
		}
		if (kind == 2) {
			int l, r; scanf("%d%d%s", &l, &r, q); --l, --r; qlen = strlen(q);
			int ans = qlen <= BSZ ? solvesmall(l, r) : solvelarge(l, r);
			printf("%d\n", ans);
		}
	}
}


int main() {
	run();
	return 0;
}