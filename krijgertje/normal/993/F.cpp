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

const char opname[4][5] = { "and","nand","or","nor" };
const int inputmapping[3][4] = { {0,1,0,1},{0,1,0,2},{0,1,2,3} };

int parseop(char *s) { REP(i, 4) if (strcmp(opname[i], s) == 0) return i; assert(false); return -1; }
int op(int id, int x, int y) {
	if (id == 0) return x == 1 && y == 1 ? 1 : 0;
	if (id == 1) return x == 1 && y == 1 ? 0 : 1;
	if (id == 2) return x == 1 || y == 1 ? 1 : 0;
	if (id == 3) return x == 1 || y == 1 ? 0 : 1;
	assert(false); return -1;
}

void gen() {
	REP(x, 4) REP(y, 4) FOR(z, y, 4) {
		REP(i, 3) {
			int masklen = i + 2;
			vector<int> res(1 << masklen, 0);
			REP(mask, 1 << masklen) {
				REP(love, 2) {
					int w1 = (mask >> inputmapping[i][0]) & 1, w2 = (mask >> inputmapping[i][1]) & 1, w3 = (mask >> inputmapping[i][2]) & 1, w4 = (mask >> inputmapping[i][3]) & 1;
					int resy = op(y^love, w1, w2), resz = op(z^love, w3, w4), resx = op(x^love, resy, resz);
					res[mask] |= resx << love;
				}
			}
			bool ok = true; REPSZ(j, res) if (res[j] == 3) ok = false; if (!ok) continue;
			printf("%s(%s(%c,%c),%s(%c,%c)): ", opname[x], opname[y], 'a' + inputmapping[i][0], 'a' + inputmapping[i][1], opname[z], 'a' + inputmapping[i][2], 'a' + inputmapping[i][3]);
			REPSZ(j, res) printf("%d", res[j]); puts("");
		}
	}
}

const int MAXA = 50;
const int MAXB = 50;
const int MAXC = 50;
struct Z { int kind; /* -1 = invalid, 0 = original always 0, 1 = complement always 0*/ vector<pair<int, int> > condzero; /* when is other 0 */ };

int na, nb, nc;
int bkind[MAXB], b[MAXB][2];
int ckind[MAXC], c[MAXC][2];
char opbuff[5], inbuff[(MAXB >= MAXC ? MAXB : MAXC) + 1];

Z classify(int id) {
	int x = ckind[id], y = bkind[c[id][0]], z = bkind[c[id][1]], w1 = b[c[id][0]][0], w2 = b[c[id][0]][1], w3 = b[c[id][1]][0], w4 = b[c[id][1]][1];
	map<int, int> mp; vector<int> in(4); vector<int> a; int nin = 0;
	if (mp.count(w1)) in[0] = mp[w1]; else mp[w1] = in[0] = nin++, a.PB(w1);
	if (mp.count(w2)) in[1] = mp[w2]; else mp[w2] = in[1] = nin++, a.PB(w2);
	if (mp.count(w3)) in[2] = mp[w3]; else mp[w3] = in[2] = nin++, a.PB(w3);
	if (mp.count(w4)) in[3] = mp[w4]; else mp[w4] = in[3] = nin++, a.PB(w4);
	int orgmask = 0, lovemask = 0, allmask = 0;
	REP(mask, 1 << nin) {
		REP(love, 2) {
			int v1 = (mask >> in[0]) & 1, v2 = (mask >> in[1]) & 1, v3 = (mask >> in[2]) & 1, v4 = (mask >> in[3]) & 1;
			int vy = op(y^love, v1, v2), vz = op(z^love, v3, v4), vx = op(x^love, vy, vz);
			allmask |= vx << mask; if (love == 0) orgmask |= vx << mask; else lovemask |= vx << mask;
		}
	}
	Z ret;
	if ((orgmask&lovemask) != 0) { ret.kind = -1; return ret; }
	assert(orgmask == 0 || lovemask == 0 && allmask != 0); ret.kind = orgmask == 0 ? 0 : 1;
	int donemask = 0;
	REP(i, nin) REP(ii, 2) FOR(j, i + 1, nin) REP(jj, 2) {
		bool ok = true; REP(k, 1 << nin) if (!(((k >> i) & 1) == ii || ((k >> j) & 1) == jj) && ((allmask >> k) & 1) == 0) ok = false; if (!ok) continue;
		ret.condzero.PB(MP((ii == 0 ? -1 : +1)*(a[i] + 1), (jj == 0 ? -1 : +1)*(a[j] + 1)));
		REP(k, 1 << nin) if (!(((k >> i) & 1) == ii || ((k >> j) & 1) == jj) && ((allmask >> k) & 1) == 1) donemask |= 1 << k;
	}
	assert(donemask == allmask);
	//printf("\torg=%x love=%x (nin=%d)\n", orgmask, lovemask, nin);
	return ret;
}

struct G {
	int n;
	vector<int> adj[2 * MAXA];
	int comp[2 * MAXA], ncomp;
	int stck[2 * MAXA], nstck;
	int id[2 * MAXA], lid[2 * MAXA], nid;

	void init(int _n) { n = _n; REP(i, n) adj[i].clear(); }
	void tarjan(int at) {
		id[at] = lid[at] = nid++; stck[nstck++] = at;
		REPSZ(i, adj[at]) {
			int to = adj[at][i];
			if (id[to] == -1) {
				tarjan(to);
				lid[at] = min(lid[at], lid[to]);
			} else if (comp[to] == -1) {
				lid[at] = min(lid[at], id[to]);
			}
		}
		if (lid[at] >= id[at]) {
			while (comp[at] == -1) comp[stck[--nstck]] = ncomp; ++ncomp;
		}
	}
	void calccomp() {
		nid = ncomp = nstck = 0; REP(i, n) comp[i] = id[i] = -1;
		REP(i, n) if (id[i] == -1) tarjan(i);
	}
};

G g;

bool satisfiable(vector<pair<int, int> > cond) {
	g.init(2 * na);
	REPSZ(i, cond) {
		int x = cond[i].first, y = cond[i].second;
		int xid = 2 * (abs(x) - 1) + (x > 0 ? 1 : 0), yid = 2 * (abs(y) - 1) + (y > 0 ? 1 : 0);
		g.adj[xid ^ 1].PB(yid); g.adj[yid ^ 1].PB(xid);
	}
	g.calccomp();
	REP(i, na) if (g.comp[2 * i + 0] == g.comp[2 * i + 1]) return false;
	return true;
}

void run() {
	scanf("%d%d%d", &na, &nb, &nc);
	REP(i, nb) { scanf("%s", opbuff); bkind[i] = parseop(opbuff); scanf("%s", inbuff); assert(strlen(inbuff) == na); int cnt = 0; REP(j, na) if (inbuff[j] == 'x') b[i][cnt++] = j; assert(cnt == 2); }
	REP(i, nc) { scanf("%s", opbuff); ckind[i] = parseop(opbuff); scanf("%s", inbuff); assert(strlen(inbuff) == nb); int cnt = 0; REP(j, nb) if (inbuff[j] == 'x') c[i][cnt++] = j; assert(cnt == 2); }

	vector<pair<int, int> > cond0, cond1; int cnt0 = 0, cnt1 = 0;
	REP(i, nc) {
		Z res = classify(i);
		//printf("%d: %d", i, res.kind); REPSZ(j, res.condzero) printf(" (%d or %d)", res.condzero[j].first, res.condzero[j].second); puts("");
		if (res.kind == 0) { ++cnt0; REPSZ(j, res.condzero) cond0.PB(res.condzero[j]); }
		if (res.kind == 1) { ++cnt1; REPSZ(j, res.condzero) cond1.PB(res.condzero[j]); }
	}

	bool ok0 = !satisfiable(cond0), ok1 = !satisfiable(cond1);
	if (!ok0 && !ok1) { printf("-1\n"); return; }
	int keep = max(ok0 ? cnt0 : 0, ok1 ? cnt1 : 0), ret = nc - keep;
	printf("%d\n", ret);
}

int main() {
	run();
	return 0;
}