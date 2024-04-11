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

const int MAXN = 400000;
const int MAXCOMP = 400000;

int n, m;
vector<int> out[MAXN];
int ans[MAXN];

int id[MAXN], mnid[MAXN], nid;
int comp[MAXN], ncomp;
int stck[MAXN], nstck;

void tarjan(int at) {
	id[at] = mnid[at] = nid++;
	stck[nstck++] = at;
	for (int to : out[at]) {
		if (comp[to] != -1) continue;
		if (id[to] == -1) {
			tarjan(to);
			mnid[at] = min(mnid[at], mnid[to]);
		} else {
			mnid[at] = min(mnid[at], id[to]);
		}
	}
	if (mnid[at] == id[at]) {
		while (comp[at] == -1) comp[stck[--nstck]] = ncomp;
		++ncomp;
	}
}

bool compcyc[MAXCOMP];
vector<int> compout[MAXCOMP];
int compreachcnt[MAXCOMP];
bool compreachinf[MAXCOMP];

void solve() {
	nid = ncomp = nstck = 0;
	REP(i, n) id[i] = comp[i] = -1;
	REP(i, n) if (id[i] == -1) tarjan(i);
	//printf("comp:"); REP(i, ncomp) printf(" %d", comp[i]); puts("");

	REP(i, ncomp) compcyc[i] = false;
	REP(at, n) for (int to : out[at]) if (comp[to] == comp[at]) compcyc[comp[at]] = true; else compout[comp[at]].PB(comp[to]);
	REP(i, ncomp) { sort(compout[i].begin(), compout[i].end()); compout[i].erase(unique(compout[i].begin(), compout[i].end()), compout[i].end()); }

	REP(i, ncomp) compreachcnt[i] = 0;
	queue<int> q;
	++compreachcnt[comp[0]], q.push(comp[0]);
	while (!q.empty()) {
		int at = q.front(); q.pop();
		for (int to : compout[at]) if (++compreachcnt[to] == 1) q.push(to);
	}

	REP(i, ncomp) if (compreachcnt[i] >= 2) compreachcnt[i] = 2, q.push(i);
	while (!q.empty()) {
		int at = q.front(); q.pop();
		for (int to : compout[at]) if (compreachcnt[to] < 2) compreachcnt[to] = 2, q.push(to);
	}

	REP(i, ncomp) compreachinf[i] = false;
	REP(i, ncomp) if (compreachcnt[i] >= 1 && compcyc[i]) compreachinf[i] = true, q.push(i);
	while (!q.empty()) {
		int at = q.front(); q.pop();
		for (int to : compout[at]) if (!compreachinf[to]) compreachinf[to] = true, q.push(to);
	}

	REP(i, n) ans[i] = compreachinf[comp[i]] ? -1 : compreachcnt[comp[i]];
	REP(i, ncomp) compout[i].clear();
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; out[a].PB(b); }
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
	REP(i, n) out[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}