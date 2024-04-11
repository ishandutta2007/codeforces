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

const int MAXN = 4000;
const int MOD = 998244353;
const int MAXLEN = 75 / 2;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }

struct G {
	int n;
	vector<int> adj[MAXN];

	int tot[MAXLEN + 1];

	bool alive[MAXN];
	int sz[MAXN];

	int lst[MAXN], nlst;
	int id[MAXN], par[MAXN];
	int d1[MAXN][2 * MAXLEN + 1];
	int d2[MAXN][2 * MAXLEN + 1];

	void dfslst(int at) {
		id[at] = nlst; lst[nlst++] = at;
		REPSZ(i, adj[at]) {
			int to = adj[at][i]; if (to == par[at] || !alive[to]) continue;
			par[to] = at; dfslst(to);
		}
	}
	
	void process(int cent) {
		nlst = 0; par[cent] = -1; dfslst(cent);
		REP(i, n) d1[i][0] = d2[i][0] = lst[i] == cent ? 1 : 0;
		FORE(k, 1, 2*MAXLEN) {
			REP(i, nlst) {
				d1[i][k] = d2[i][k] = 0; int at = lst[i];
				REPSZ(j, adj[at]) {
					int to = adj[at][j]; if (!alive[to]) continue;
					if (at != cent) inc(d1[i][k], d1[id[to]][k - 1]);
					inc(d2[i][k], d2[id[to]][k - 1]);
				}
			}
		}
		REP(i, nlst) REPE(k1, 2 * MAXLEN) REPE(k2, 2 * MAXLEN - k1) if ((k1 + k2) % 2 == 0) { int k = (k1 + k2) / 2; tot[k] = (tot[k] + (ll)d1[i][k1] * d2[i][k2])%MOD; }
	}

	void dfssz(int at, int par) {
		sz[at] = 1;
		REPSZ(i, adj[at]) {
			int to = adj[at][i]; if (to == par || !alive[to]) continue;
			dfssz(to, at); sz[at] += sz[to];
		}
	}

	int dfscentroid(int at, int par, int rootsz) {
		REPSZ(i, adj[at]) {
			int to = adj[at][i]; if (to == par || !alive[to]) continue;
			if (2 * sz[to] > rootsz) return dfscentroid(to, at, rootsz);
		}
		return at;
	}

	int centroid(int root) {
		dfssz(root,-1);
		return dfscentroid(root, -1, sz[root]);
	}

	void decompose(int root) {
		int cent = centroid(root);
		process(cent);
		alive[cent] = false;
		REPSZ(i, adj[cent]) {
			int to = adj[cent][i]; if (!alive[to]) continue;
			decompose(to);
		}
	}

	void calc() {
		REP(i, n) alive[i] = true;
		decompose(0);
	}
	

};

G a, b;
int len;
int C[2 * MAXLEN + 1][2 * MAXLEN + 1];

void run() {
	REPE(i, 2 * MAXLEN) { C[i][0] = C[i][i] = 1; FOR(j, 1, i) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD; }

	scanf("%d%d%d", &a.n, &b.n, &len);
	REP(i, a.n - 1) { int u, v; scanf("%d%d", &u, &v); --u, --v; a.adj[u].PB(v), a.adj[v].PB(u); }
	REP(i, b.n - 1) { int u, v; scanf("%d%d", &u, &v); --u, --v; b.adj[u].PB(v), b.adj[v].PB(u); }

	if (len % 2 != 0) { printf("0\n"); return; } else len /= 2;

	a.calc();
	b.calc();
	//printf("a:"); REPE(k, len) printf(" %d", a.tot[k]); puts("");
	//printf("b:"); REPE(k, len) printf(" %d", b.tot[k]); puts("");

	int ret = 0;
	REPE(k, len) ret = (ret + (ll)a.tot[k] * b.tot[len - k] % MOD * C[2 * len][2 * k]) % MOD;
	printf("%d\n", ret);
}

int main() {
	run();
	return 0;
}