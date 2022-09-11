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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXH = 300;
const int MAXW = 300;
const int MAXN = MAXH * MAXW;
const int MAXQ = 2000000;
const int MAXV = 2000000;
const int DX[] = { -1,0,+1,0 }, DY[] = { 0,+1,0,-1 };
struct E { int t, z; E() {} E(int t, int z) :t(t), z(z) {} };

int h, w, nq;
int qx[MAXQ], qy[MAXQ], qv[MAXQ], qans[MAXQ];

int g[MAXH][MAXW];

vector<E> added[MAXV + 1];
vector<E> removed[MAXV + 1];

int n;
int id[MAXH][MAXW];
vector<int> adj[MAXN];

bool alive[MAXN];
int ufpar[MAXN], ufsz[MAXN];
int delta[MAXQ + 1];

int uffind(int x) { if (ufpar[x] == x) return x; return ufpar[x] = uffind(ufpar[x]); }
bool ufunite(int x, int y) { x = uffind(x), y = uffind(y); if (x == y) return false; if (ufsz[x] < ufsz[y]) swap(x, y); ufpar[y] = x, ufsz[x] += ufsz[y]; return true; }

void solve() {
	n = h * w;
	REP(x, h) REP(y, w) id[x][y] = x * w + y;
	REP(i, n) adj[i].clear();
	REP(x, h) REP(y, w) REP(k, 4) { int nx = x + DX[k], ny = y + DY[k]; if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue; adj[id[x][y]].PB(id[nx][ny]); }

	REP(x, h) REP(y, w) g[x][y] = 0;
	REP(x, h) REP(y, w) added[g[x][y]].PB(E(-1, id[x][y]));
	REP(i, nq) {
		int x = qx[i], y = qy[i], v = qv[i];
		if (g[x][y] == v) continue;
		removed[g[x][y]].PB(E(i, id[x][y]));
		g[x][y] = v;
		added[g[x][y]].PB(E(i, id[x][y]));
	}
	REP(x, h) REP(y, w) removed[g[x][y]].PB(E(nq, id[x][y]));

	REP(i, n) alive[i] = false;
	REPE(i, nq) delta[i] = 0;
	REPE(v, MAXV) {
		int ncomp = 0;
		REPSZ(i, added[v]) {
			int ocomp = ncomp, t = added[v][i].t, at = added[v][i].z;
			assert(!alive[at]); alive[at] = true, ufpar[at] = at, ufsz[at] = 1, ++ncomp;
			REPSZ(j, adj[at]) { int to = adj[at][j]; if (!alive[to]) continue; if (ufunite(at, to)) --ncomp; }
			delta[max(t, 0)] += ncomp - ocomp;
		}
		REPSZ(i, added[v]) alive[added[v][i].z] = false;
		ncomp = 0;
		for (int i = SZ(removed[v]) - 1; i >= 0; --i) {
			int ocomp = ncomp, t = removed[v][i].t, at = removed[v][i].z;
			assert(!alive[at]); alive[at] = true, ufpar[at] = at, ufsz[at] = 1, ++ncomp;
			REPSZ(j, adj[at]) { int to = adj[at][j]; if (!alive[to]) continue; if (ufunite(at, to)) --ncomp; }
			delta[max(t, 0)] -= ncomp - ocomp;
		}
		REPSZ(i, removed[v]) alive[removed[v][i].z] = false;
	}
	qans[0] = delta[0]; FOR(i, 1, nq) qans[i] = qans[i - 1] + delta[i];
}

void run() {
	scanf("%d%d%d", &h, &w, &nq);
	REP(i, nq) scanf("%d%d%d", &qx[i], &qy[i], &qv[i]), --qx[i], --qy[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}