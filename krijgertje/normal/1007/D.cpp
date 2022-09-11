// Implicit Kosaraju with multiple small topdown segtrees with prefix optimization
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


struct ImplicitKosaraju {
	int n;
	int(*unmarkedadj)(int, bool);
	void(*mark)(int, bool);
	void(*reset)();
	void init(int _n) { n = _n; }

	vector<bool> been;
	vector<int> top; int ntop;
	vector<int> comp; int ncomp;
	vector<vector<int>> compnodes;

	void dfs1(int at) {
		been[at] = true; mark(at, true);
		while (true) {
			int to = unmarkedadj(at, true);
			//printf("reverse: %d<=%d\n",at,to);
			if (to == -1) break;
			dfs1(to);
		}
		top[ntop++] = at;
	}
	void dfs2(int at, int c) {
		comp[at] = c; compnodes[c].PB(at); mark(at, false);
		while (true) {
			int to = unmarkedadj(at, false);
			//printf("forward: %d=>%d\n",at,to);
			if (to == -1) break;
			dfs2(to, c);
		}
	}

	void calc() {
		ntop = ncomp = 0; been = vector<bool>(n, false), top = vector<int>(n), comp = vector<int>(n, -1), compnodes.clear();
		reset();
		REP(i, n) if (!been[i]) dfs1(i);
		reset();
		for (int i = ntop - 1; i >= 0; --i) if (comp[top[i]] == -1) { compnodes.PB(vector<int>()); dfs2(top[i], ncomp++); }
	}
};

struct HLD {
	int n;
	vector<vector<int>> adj;
	void init(int _n) { n = _n; adj = vector<vector<int>>(n); }

	vector<int> par;
	vector<int> dep;
	vector<int> sz;
	vector<int> heavy;
	vector<int> psize; int np;
	vector<int> hroot;
	vector<int> hpath;
	vector<int> hpos;

	void dfsinit(int at) {
		if (par[at] != -1) dep[at] = dep[par[at]] + 1;
		REPSZ(i, adj[at]) {
			int to = adj[at][i]; if (to == par[at]) continue;
			par[to] = at; dfsinit(to);
			sz[at] += sz[to]; if (heavy[at] == -1 || sz[to] > sz[heavy[at]]) heavy[at] = to;
		}
	}

	void calc() {
		par = vector<int>(n, -1), dep = vector<int>(n, 0), sz = vector<int>(n, 1), heavy = vector<int>(n, -1);
		dfsinit(0);
		hroot = hpath = hpos = vector<int>(n, -1), np = 0, psize = vector<int>();
		REP(i, n) if (par[i] == -1 || heavy[par[i]] != i) { int p = np++; psize.PB(0); for (int at = i; at != -1; at = heavy[at]) hroot[at] = i, hpath[at] = p, hpos[at] = psize[p]++; }
		//REP(i, n) printf("%d: par=%d dep=%d sz=%d heavy=%d hroot=%d hpath=%d hpos=%d (out of %d)\n", i + 1, par[i] + 1, dep[i], sz[i], heavy[i] + 1, hroot[i] + 1, hpath[i], hpos[i], psize[hpath[i]]);
	}

	vector<pair<int, pair<int, int> > > query(int a, int b) { // unordered
		vector<pair<int, pair<int, int> > > ret;
		while (hpath[a] != hpath[b]) {
			if (dep[hroot[a]] < dep[hroot[b]]) swap(a, b);
			ret.PB(MP(hpath[a], MP(0, hpos[a])));
			a = par[hroot[a]];
		}
		if (dep[a] < dep[b]) swap(a, b);
		if (a != b) ret.PB(MP(hpath[a], MP(hpos[b] + 1, hpos[a])));
		return ret;
	}
};

struct HLDIntersect { // init->add*->precalc->(rem|query)*
	bool(*isactive)(int);

	int n,me;
	vector<vector<int>> allbyl;
	vector<vector<int>> prefbyr;
	vector<int> scnt;
	vector<int> sidx;
	vector<vector<int>> slst;

	void init(int _n) {
		n=_n; //allbyl=prefbyr=vector<vector<int>>(n); 
		int m=1; while(m<n) m*=2; scnt=sidx=vector<int>(2*m-1,0),slst=vector<vector<int>>(2*m-1);
	}

	void smod(int x,int l,int r,int L,int R,int ID,int BY) {
		scnt[x]+=BY;
		if(L<=l&&r<=R) {
			if(BY==+1) slst[x].PB(ID); // BY==-1 handled by id becoming inactive
		} else {
			int m=l+(r-l)/2;
			if(L<=m) smod(2*x+1,l,m,L,R,ID,BY);
			if(m+1<=R) smod(2*x+2,m+1,r,L,R,ID,BY);
		}
	}
	int sget(int x,int l,int r,int L,int R,int SKIP) {
		if(scnt[x]==0) return -1;
		while(sidx[x]<SZ(slst[x])) {
			if(slst[x][sidx[x]]!=SKIP) {
				if(isactive(slst[x][sidx[x]])) return slst[x][sidx[x]];
			} else {
				if(sidx[x]+1>=SZ(slst[x])) break;
				assert(slst[x][sidx[x]+1]!=SKIP);
				if(isactive(slst[x][sidx[x]+1])) return slst[x][sidx[x]+1];
				slst[x][sidx[x]+1]=slst[x][sidx[x]];
			}
			++sidx[x];
		}
		int ret=-1;
		if(l!=r) {
			int m=l+(r-l)/2;
			if(L<=m&&ret==-1) ret=sget(2*x+1,l,m,L,R,SKIP);
			if(m+1<=R&&ret==-1) ret=sget(2*x+2,m+1,r,L,R,SKIP);
		}
		return ret;
	}

	void add(int l,int r,int id) {
		smod(0,0,n-1,l,r,id,+1); return;
		//printf("\t%d: add %d on %d..%d\n",me,id,l,r);
		allbyl[l].PB(id);
		if(l==0) prefbyr[r].PB(id); else smod(0,0,n-1,l,r,id,+1);
	}
	vector<pair<int,int>> a; int aidx; // (l,id) of all (increasing l)
	vector<pair<int,int>> b; int bidx; // (r,id) of prefixes (decreasing r)
	void precalc() {
		//a.clear(); aidx=0; REP(i,n) REPSZ(j,allbyl[i]) a.PB(MP(i,allbyl[i][j]));
		//b.clear(); bidx=0; for(int i=n-1;i>=0;--i) REPSZ(j,prefbyr[i]) b.PB(MP(i,prefbyr[i][j]));
	}

	void rem(int l,int r,int id) {
		smod(0,0,n-1,l,r,id,-1); return;
		if(l!=0) smod(0,0,n-1,l,r,id,-1);
	}
	int query(int l,int r,int skip) {
		return sget(0,0,n-1,l,r,skip);
		//printf("\t%d: query %d..%d (skipping %d)\n",me,l,r,skip);
		if(l==0) {
			while(aidx<SZ(a)&&a[aidx].first<=r) {
				if(a[aidx].second!=skip) {
					if(isactive(a[aidx].second)) return a[aidx].second;
				} else {
					if(aidx+1>=SZ(a)||a[aidx+1].first>r) break;
					assert(a[aidx+1].second!=skip);
					if(isactive(a[aidx+1].second)) return a[aidx+1].second;
					a[aidx+1]=a[aidx];
				}
				++aidx;
			}
			return -1;
		} else {
			while(bidx<SZ(b)&&b[bidx].first>=l) {
				if(b[bidx].second!=skip) {
					if(isactive(b[bidx].second)) return b[bidx].second;
				} else {
					if(bidx+1>=SZ(b)||b[bidx+1].first<l) break;
					assert(b[bidx+1].second!=skip);
					if(isactive(b[bidx+1].second)) return b[bidx+1].second;
					b[bidx+1]=b[bidx];
				}
				++bidx;
			}
			return sget(0,0,n-1,l,r,skip);
		}
	}
};

const int MAXN = 100000;
const int MAXQ = 10000;

int n;
vector<int> adj[MAXN];
int nq;
int q[MAXQ][4];
int ans[MAXQ];

HLD hld;
vector<pair<int, pair<int, int>>> segs[2 * MAXQ];
vector<bool> active;
vector<HLDIntersect> paths;
ImplicitKosaraju impkos;

bool isactive(int id) { return active[id]; }
void reset() {
	active = vector<bool>(2 * nq, true);
	paths = vector<HLDIntersect>(hld.np);
	REPSZ(i, paths) paths[i].init(hld.psize[i]), paths[i].isactive = isactive, paths[i].me=i;
	REP(at, 2 * nq) REPSZ(i, segs[at]) paths[segs[at][i].first].add(segs[at][i].second.first, segs[at][i].second.second, at);
	REPSZ(i, paths) paths[i].precalc();
}
int unmarkedadj(int at, bool rev) {
	//printf("\tunmargkedadj(%d,%s)\n",at,rev?"yes":"no");
	if (rev) at ^= 1; 
	REPSZ(i, segs[at]) {
		int cur = paths[segs[at][i].first].query(segs[at][i].second.first, segs[at][i].second.second, at);
		if (cur == -1) continue;
		//printf("\t\tfound %d (%d,%d..%d,%d)\n",cur,segs[at][i].first,segs[at][i].second.first, segs[at][i].second.second,at);
		if (!rev) cur ^= 1; return cur;
	}
	return -1;
}
void mark(int at, bool rev) {
	if (!rev) at ^= 1;
	REPSZ(i, segs[at]) paths[segs[at][i].first].rem(segs[at][i].second.first, segs[at][i].second.second, at);
	active[at] = false; 
}

bool solve() {
	hld.init(n);
	REP(i, n) REPSZ(j, adj[i]) hld.adj[i].PB(adj[i][j]);
	hld.calc();
	REP(i, nq) REP(j, 2) {
		int a = q[i][2 * j + 0], b = q[i][2 * j + 1];
		segs[2 * i + j] = hld.query(a, b);
		//printf("%d-%d:", a + 1, b + 1); REPSZ(k, segs[2 * i + j]) printf(" %d:%d..%d", segs[2 * i + j][k].first, segs[2 * i + j][k].second.first, segs[2 * i + j][k].second.second); puts("");
	}

	impkos.init(2 * nq); impkos.unmarkedadj = unmarkedadj, impkos.mark = mark, impkos.reset = reset;
	impkos.calc();

	REP(i, nq) if (impkos.comp[2 * i + 0] == impkos.comp[2 * i + 1]) return false;
	REP(i, nq) ans[i] = -1;
	REP(i, impkos.ncomp) REPSZ(j, impkos.compnodes[i]) { int at = impkos.compnodes[i][j]; if (ans[at >> 1] == -1) ans[at >> 1] = at % 2 == 0 ? 1 : 2; }
	return true;
}

void run() {
	scanf("%d", &n); REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	scanf("%d", &nq); REP(i, nq) REP(j, 4) scanf("%d", &q[i][j]), --q[i][j];

	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, nq) printf("%d\n", ans[i]);
}

struct UF {
	vector<int> par, sz;
	UF(int n) { par = sz = vector<int>(n); REP(i, n) par[i] = i, sz[i] = 1; }
	int find(int x) { if (par[x] == x) return x; return par[x] = find(par[x]); }
	bool unite(int a, int b) { a = find(a), b = find(b); if (a == b) return false; if (sz[a] < sz[b]) swap(a, b); par[b] = a, sz[a] += sz[b]; return true; }
};
set<pair<int, int> > seen;
bool verifypath(int a, int b, int prev) {
	if (a == b) return true;
	REPSZ(i, adj[a]) {
		int c = adj[a][i]; if (c == prev) continue;
		if (!verifypath(c, b, a)) continue;
		pair<int, int> e = MP(a, c); if (e.first > e.second) swap(e.first, e.second);
		assert(!seen.count(e)); seen.insert(e);
		return true;
	}
	return false;
}
void verify() {
	seen.clear();
	REP(i, nq) {
		int a = q[i][2 * (ans[i] - 1) + 0], b = q[i][2 * (ans[i] - 1) + 1];
		assert(verifypath(a, b, -1));
	}
}
int myrand() { return rand() % 1000 * 1000 + rand() % 1000; }
void stress() {
	REP(rep, 10000) {
		n = 20; REP(i, n) adj[i].clear();
		UF uf(n); REP(i, n - 1) while (true) { int a = myrand() % n, b = myrand() % n; if (!uf.unite(a, b)) continue; adj[a].PB(b); adj[b].PB(a); break; }
		//REP(i, n - 1) { int a = i, b = i + 1; adj[a].PB(b); adj[b].PB(a); }
		nq = 5; REP(i, nq) REP(j, 4) q[i][j] = rand() % n;
		//printf("%d\n", n); REP(i, n) REPSZ(j, adj[i]) { int k = adj[i][j]; if (i < k) printf("%d %d\n", i + 1, k + 1); }
		//printf("%d\n", nq); REP(i, nq) printf("%d %d %d %d\n", q[i][0] + 1, q[i][1] + 1, q[i][2] + 1, q[i][3] + 1);
		bool have = solve();
		printf("%c", have ? 'V' : 'x');
		if((rep+1)%40==0) puts("");
		if (have) verify();
	}
}

int main() {
	run();
	//stress();
	return 0;
}