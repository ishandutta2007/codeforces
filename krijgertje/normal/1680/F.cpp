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
#include <chrono>
#include <random>
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
std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

const int MAXN = 1000000;

int n, m;
vector<int> adj[MAXN];
char ans[MAXN + 1];

vector<int> cyc;
int col[MAXN];
int par[MAXN];
int cycidx[MAXN];
int comp[MAXN], ncomp;

bool dfs1(int at) {
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		if (col[to] != -1) {
			if (col[to] == 1 - col[at]) continue;
			cyc = vector<int>();
			for (int x = at; x != par[to]; x = par[x]) cyc.PB(x);
			return false;
		}
		par[to] = at, col[to] = 1 - col[at];
		if (!dfs1(to)) return false;
	}
	return true;
}

bool solve() {
	REP(i, n) col[i] = -1;
	par[0] = -1, col[0] = 0;
	if (dfs1(0)) {
		REP(i, n) ans[i] = '0' + col[i]; ans[n] = '\0';
		return true;
	}
	//printf("cyc:"); REPSZ(i, cyc) printf(" %d", cyc[i] + 1); puts("");
	REP(i, n) cycidx[i] = -1;
	REPSZ(i, cyc) cycidx[cyc[i]] = i;

	ncomp = 0;
	REP(i, n) comp[i] = col[i] = -1;
	vector<int> blockcnt(SZ(cyc) + 1, 0);
	REP(i, n) if (comp[i] == -1) {
		comp[i] = ncomp++, col[i] = 0;
		queue<int> q;
		q.push(i);
		vector<int> who;
		while (!q.empty()) {
			int at = q.front(); q.pop();
			if (cycidx[at] != -1) who.PB(cycidx[at]);
			for (int to : adj[at]) {
				if (cycidx[at] != -1 && cycidx[to] != -1 && (abs(cycidx[at] - cycidx[to]) == 1 || min(cycidx[at], cycidx[to]) == 0 && max(cycidx[at], cycidx[to]) == SZ(cyc) - 1)) continue;
				if (comp[to] != -1) {
					assert(comp[to] == comp[at]);
					if (col[to] == col[at]) return false;
				} else {
					comp[to] = comp[at], col[to] = 1 - col[at];
					q.push(to);
				}
			}
		}
		sort(who.begin(), who.end());
		//printf("who%d:", comp[i]); for (int x : who) printf(" %d", x); puts("");
		FORSZ(j, 1, who) {
			int dist = who[j] - who[0];
			bool diff = col[cyc[who[j]]] != col[cyc[who[0]]];
			//printf("\tdist=%d diff=%d\n", dist, diff ? 1 : 0);
			if ((dist % 2 == 0) != diff) {
				//printf("\tblock [%d..%d)\n", who[0], who[j]);
				++blockcnt[who[0]], --blockcnt[who[j]];
			} else {
				//printf("\tblock [%d..%d)\n", who[j], who[0]);
				++blockcnt[0], --blockcnt[who[0]], ++blockcnt[who[j]], --blockcnt[SZ(cyc)];
			}
		}
	}
	FORE(i, 1, SZ(cyc)) blockcnt[i] += blockcnt[i - 1];
	//printf("blockcnt:"); REPSZ(i, cyc) printf(" %d", blockcnt[i]); puts("");
	int idx = -1;
	REPSZ(i, cyc) if (blockcnt[i] == 0) { idx = i; break; }
	if (idx == -1) return false;

	REP(i, n) ans[i] = '?'; ans[n] = '\0';
	REPSZ(i, cyc) {
		int at = (idx + 1 + i) % SZ(cyc);
		ans[cyc[at]] = '1' - i % 2;
	}
	vector<int> flip(ncomp, -1);
	REPSZ(i, cyc) {
		int c = comp[cyc[i]];
		if (flip[c] != -1) continue;
		flip[c] = col[cyc[i]] == ans[cyc[i]] - '0' ? 0 : 1;
	}
	REP(i, n) {
		if (cycidx[i] != -1) assert((col[i] ^ flip[comp[i]]) == ans[i] - '0');
		ans[i] = '0' + (col[i] ^ flip[comp[i]]);
	}
	return true;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	if (!solve()) {
		printf("NO\n");
	} else {
		printf("YES\n");
		printf("%s\n", ans);
	}
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}