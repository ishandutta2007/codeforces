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

const int MAXN = 300000;
const int MAXM = 300000;
const int MAXCOMP = MAXN;

int n, m, nspecial;
bool isspecial[MAXN];
int vgain[MAXN];
int e[MAXM][2], ecost[MAXM];
ll ans[MAXN];

vector<int> adj[MAXN];
int comp[MAXN], ncomp;
int stck[MAXN], nstck;
int id[MAXN], mnid[MAXN], nid;

ll compgain[MAXCOMP];
vector<pair<int, int>> compadj[MAXCOMP];
int compcnt[MAXCOMP];

void tarjan(int at,int parid) {
	id[at] = mnid[at] = nid++; stck[nstck++] = at;
	REPSZ(i, adj[at]) {
		int eid = adj[at][i]; if (eid == parid) continue;
		int to = e[eid][0] ^ e[eid][1] ^ at;
		if (id[to] == -1) {
			tarjan(to, eid);
			mnid[at] = min(mnid[at], mnid[to]);
		} else if (comp[to] == -1) {
			mnid[at] = min(mnid[at], id[to]);
		}
	}
	if (mnid[at] == id[at]) {
		while (comp[at] == -1) comp[stck[--nstck]] = ncomp; ++ncomp;
	}
}

int subtreecnt[MAXCOMP];
ll subtreegain[MAXCOMP];
ll dpdown[MAXCOMP]; // max gain in subtree, assuming every special vertex in it needs to be able to get to the root of the subtree
ll dpup[MAXCOMP]; // max gain in complement of subtree, assuming every special vertex in it needs to be able to get to the root of the subtree
ll compans[MAXCOMP];

void dfsdown(int at, int par) {
	subtreecnt[at] = compcnt[at];
	subtreegain[at] = compgain[at];
	dpdown[at] = compgain[at];
	REPSZ(i, compadj[at]) {
		int to = compadj[at][i].first, cost = compadj[at][i].second; if (to == par) continue;
		dfsdown(to, at);
		subtreecnt[at] += subtreecnt[to];
		subtreegain[at] += subtreegain[to];
		if (subtreecnt[to] == 0) dpdown[at] += subtreegain[to]; else dpdown[at] += max(0LL, dpdown[to] - cost);
	}
}
void dfsup(int at, int par,int parcost) {
	if (par == -1) {
		dpup[at] = 0;
	} else {
		ll dppar = dpdown[par] + dpup[par] - (subtreecnt[at] == 0 ? subtreegain[at] : max(0LL, dpdown[at] - parcost));
		if (subtreecnt[at] == 0) dpup[at] = dppar; else dpup[at] = max(0LL, dppar - parcost);
	}
	REPSZ(i, compadj[at]) {
		int to = compadj[at][i].first, cost = compadj[at][i].second; if (to == par) continue;
		dfsup(to, at, cost);
	}
}

void solve() {
	REP(i, m) REP(j, 2) adj[e[i][j]].PB(i);
	nid = ncomp = nstck = 0;
	REP(i, n) comp[i] = id[i] = -1;
	tarjan(0, -1);
	REP(i, n) assert(comp[i] != -1);
	//printf("comp:"); REP(i, n) printf(" %d", comp[i]); puts("");

	REP(i, ncomp) compgain[i] = 0, compcnt[i] = 0;
	REP(i, n) { int c = comp[i]; compgain[c] += vgain[i]; compcnt[c] += isspecial[i] ? 1 : 0; }
	REP(i, m) { int a = comp[e[i][0]], b = comp[e[i][1]]; if (a == b) continue; compadj[a].PB(MP(b, ecost[i])), compadj[b].PB(MP(a, ecost[i])); }
	int comproot = -1; REP(i, ncomp) if (compcnt[i] > 0) { comproot = i; break; } assert(comproot != -1);

	dfsdown(comproot, -1);
	dfsup(comproot, -1, 0);
	REP(i, ncomp) compans[i] = dpdown[i] + dpup[i];
	REP(i, n) ans[i] = compans[comp[i]];
}

void run() {
	scanf("%d%d%d", &n, &m, &nspecial);
	REP(i, n) isspecial[i] = false;
	REP(i, nspecial) { int x; scanf("%d", &x); --x; isspecial[x] = true; }
	REP(i, n) scanf("%d", &vgain[i]);
	REP(i, m) scanf("%d", &ecost[i]);
	REP(i, m) REP(j, 2) scanf("%d", &e[i][j]), --e[i][j];
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%lld", ans[i]); } puts("");
}

int main() {
	run();
	return 0;
}