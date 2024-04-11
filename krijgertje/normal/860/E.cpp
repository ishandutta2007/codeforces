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
#include <functional>
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

typedef struct Tree {
	int n,root;
	vector<int> par;
	vector<vector<int> > ch;
	void init(int _n) { n = _n; root = -1; par = vector<int>(n, -1); ch = vector<vector<int> >(n); }
	void setroot(int _root) { root = _root; }
	void setpar(int a, int b) { par[a] = b; ch[b].PB(a); }

	vector<int> d, pre; int npre;
	vector<vector<int> > dlst;
	void calcdfs(int at) {
		d[at] = par[at] == -1 ? 0 : d[par[at]] + 1; while (d[at] >= SZ(dlst)) dlst.PB(vector<int>()); dlst[d[at]].PB(at); pre[at] = npre++;
		REPSZ(i, ch[at]) calcdfs(ch[at][i]);
	}
	void calc() { d = pre = vector<int>(n); npre = 0; dlst.clear(); calcdfs(root); }
} Tree;

typedef struct DSU {
	vector<int> par;
	void init(int n) { par = vector<int>(n); REP(i, n) par[i] = -1; }
	int find(int x) { if (par[x] < 0) return x; return par[x] = find(par[x]); }
	void unite(int a, int b) { a = find(a), b = find(b); if (a == b) return; if (-par[a] < -par[b]); swap(a, b); par[a] += par[b]; par[b] = a; }
} DSU;

typedef struct OLCA {
	Tree *t;
	DSU dsu;
	vector<int> q;
	vector<int> lca;
	vector<int> anc;
	void init(Tree *_t) { t = _t; dsu.init(t->n); q = lca = anc = vector<int>(t->n, -1); }
	void add(int a, int b) { assert(q[b] == -1); q[b] = a; }
	void dfscalc(int at) {
		anc[at] = at;
		REPSZ(i, t->ch[at]) { int to = t->ch[at][i]; dfscalc(to); dsu.unite(at, to); anc[dsu.find(at)] = at; }
		if (q[at] != -1) lca[at] = anc[dsu.find(q[at])];
	}
	void calc() { dfscalc(t->root);	}
} OLCA;

typedef struct STree {
	int n, root;
	vector<int> par;
	vector<vector<int> > ch;
	void init(int _n) { n = _n; root = -1; par = vector<int>(n, -1); leafcnt = vector<int>(n, 0); ch = vector<vector<int> >(n); }
	void setroot(int _root) { root = _root; }
	void setpar(int a, int b) { par[a] = b; ch[b].PB(a); }
	
	void dfsclear(int at) { REPSZ(i, ch[at]) dfsclear(ch[at][i]); ch[at].clear(); par[at] = -1; leafcnt[at] = 0; }
	void clear() { if (root != -1) dfsclear(root); root = -1; }
	void build(int rt,const vector<int> &lst, const vector<int> &d, const vector<int> &lca) {
		clear();
		vector<int> stck; stck.PB(rt);
		REPSZ(j, lst) {
			int at = lst[j];
			if (j != 0) {
				int up = lca[at], prv = -1;
				while (SZ(stck) > 0 && d[up] < d[stck.back()]) {
					if (prv != -1) setpar(prv, stck.back()); prv = stck.back(); stck.pop_back();
				}
				if (SZ(stck) == 0 || d[up] > d[stck.back()]) stck.PB(up);
				if (prv != -1) setpar(prv, stck.back());
			}
			if (SZ(stck) == 0 || d[at] > d[stck.back()]) stck.PB(at);
		}
		{
			int prv = -1;
			while (SZ(stck) > 0) {
				if (prv != -1) setpar(prv, stck.back()); prv = stck.back(); stck.pop_back();
			}
			setroot(prv);
		}
	}

	vector<int> leafcnt;
	void dfscalc(int at) { if (SZ(ch[at]) == 0) ++leafcnt[at]; REPSZ(i, ch[at]) { int to = ch[at][i]; dfscalc(to); leafcnt[at] += leafcnt[to]; } }
	void calc() { dfscalc(root); }
} STree;

Tree t;
OLCA olca;
STree st;

void dfs(int at, ll sum, vector<ll> &ans) {
	if (SZ(st.ch[at]) == 0) ans[at] += sum + (t.par[at] == -1 ? 0 : ans[t.par[at]]);
	REPSZ(i, st.ch[at]) { int to = st.ch[at][i]; dfs(to, sum + st.leafcnt[at] + (ll)(t.d[to] - t.d[at] - 1)*st.leafcnt[to], ans); }
}

void run() {
	int n; scanf("%d", &n); t.init(n);
	REP(i, n) { int p; scanf("%d", &p); --p; if (p == -1) t.setroot(i); else t.setpar(i, p); }
	t.calc();
	olca.init(&t);
	REPSZ(i, t.dlst) FORSZ(j, 1, t.dlst[i]) olca.add(t.dlst[i][j - 1], t.dlst[i][j]);
	olca.calc();
	vector<ll> ans(n, 0);
	st.init(n);
	REPSZ(i, t.dlst) {
		//printf("d=%d:", i); REPSZ(j, t.dlst[i]) { int at = t.dlst[i][j]; if (j != 0) printf(" [%d=%d]", olca.lca[at] + 1, t.d[olca.lca[at]]); printf(" %d", at + 1); } puts("");
		st.build(t.root, t.dlst[i], t.d, olca.lca);
		st.calc();
		dfs(st.root, 0, ans);
	}
	REP(i, n) { if (i != 0) printf(" "); printf("%lld", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}