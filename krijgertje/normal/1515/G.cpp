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



const int MAXN = 200000;
const int MAXQ = 200000;
const int MAXCOMP = 200000;

int n, m;
vector<pair<int, int>> out[MAXN];
int nq;
int qv[MAXQ], qs[MAXQ], qmod[MAXQ];
bool qans[MAXQ];


int id[MAXN], mnid[MAXN], nid;
int comp[MAXN], ncomp;
int stck[MAXN], nstck;
void tarjan(int at) {
	id[at] = mnid[at] = nid++, stck[nstck++] = at;
	REPSZ(i, out[at]) {
		int to = out[at][i].first;
		if (comp[to] != -1) continue;
		if (id[to] == -1) {
			tarjan(to);
			mnid[at] = min(mnid[at], mnid[to]);
		} else {
			mnid[at] = min(mnid[at], id[to]);
		}
	}
	if (mnid[at] >= id[at]) { while (comp[at] == -1) comp[stck[--nstck]] = ncomp; ++ncomp; }
}

int comproot[MAXCOMP];
int par[MAXN];
ll dep[MAXN];
ll compgcd[MAXCOMP];

void dfsinit(int at) {
	REPSZ(i, out[at]) {
		int to = out[at][i].first, w = out[at][i].second;
		if (comp[to] != comp[at]) continue;
		if (par[to] != -2) continue;
		par[to] = at;
		dep[to] = dep[at] + w;
		dfsinit(to);
	}
}

void solve() {
	nid = ncomp = nstck = 0;
	REP(i, n) id[i] = mnid[i] = comp[i] = -1;
	REP(i, n) if (comp[i] == -1) tarjan(i);
	//printf("comp:"); REP(i, n) printf(" %d", comp[i]); puts("");

	REP(i, ncomp) comproot[i] = -1;
	REP(i, n) if (comproot[comp[i]] == -1) comproot[comp[i]] = i;
	REP(i, n) par[i] = -2;
	REP(i, ncomp) {
		par[comproot[i]] = -1;
		dep[comproot[i]] = 0;
		dfsinit(comproot[i]);
	}
	REP(i, ncomp) compgcd[i] = 0;
	REP(at, n) REPSZ(i, out[at]) {
		int to = out[at][i].first, w = out[at][i].second;
		if (comp[to] != comp[at]) continue;
		if (par[to] == at) continue;
		ll cur = dep[to] - dep[at] - w;
		compgcd[comp[at]] = gcd(compgcd[comp[at]], abs(cur));
	}
	//printf("compgcd:"); REP(i, ncomp) printf(" %lld", compgcd[i]); puts("");

	REP(i, nq) {
		int at = qv[i], s = qs[i], mod = qmod[i];
		ll g = gcd(compgcd[comp[at]], mod);
		qans[i] = s % g == 0;
	}
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b, c; scanf("%d%d%d", &a, &b, &c); --a, --b; out[a].PB(MP(b, c)); }
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d%d", &qv[i], &qs[i], &qmod[i]), --qv[i];
	solve();
	REP(i, nq) printf("%s\n", qans[i] ? "YES" : "NO");
}

int main() {
	run();
	return 0;
}