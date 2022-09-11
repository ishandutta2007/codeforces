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
const int MAXQ = 1000000;

int n, nq;
int a[MAXN];
int par[MAXN];
int qnode[MAXQ], qlim[MAXQ], qidx[MAXQ];
int qans[MAXQ];

vector<int> ch[MAXN];
int cnt[MAXN];
int pos[MAXN];
int ord[MAXN];
int first[MAXN + 1];
vector<int> q[MAXN];

void dfs(int at) {
	int v = a[at];
	int x = pos[v], y = first[cnt[v] + 1] - 1;
	swap(ord[x], ord[y]);
	swap(pos[ord[x]], pos[ord[y]]);
	++cnt[v];
	first[cnt[v]]--;
	//printf("%d:", at + 1); REP(i, n) printf(" %d=%d", ord[i] + 1, cnt[ord[i]]); puts("");
	for (int id : q[at]) {
		int z = first[qlim[id]];
		qans[id] = z + qidx[id] < n ? ord[z + qidx[id]] : -1;
	}
	for (int to : ch[at]) {
		dfs(to);
	}
	swap(ord[x], ord[y]);
	swap(pos[ord[x]], pos[ord[y]]);
	first[cnt[v]]++;
	--cnt[v];
}

void solve() {
	REP(i, n) if (par[i] != -1) ch[par[i]].PB(i);
	REP(i, n) cnt[i] = 0;
	REP(i, n) pos[i] = i, ord[i] = i;
	REPE(i, n) first[i] = i == 0 ? 0 : n;
	REP(i, nq) q[qnode[i]].PB(i);
	dfs(0);
	REP(i, n) ch[i].clear(), q[i].clear();
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n) scanf("%d", &a[i]), --a[i];
	par[0] = -1; FOR(i, 1, n) scanf("%d", &par[i]), --par[i];
	REP(i, nq) scanf("%d%d%d", &qnode[i], &qlim[i], &qidx[i]), --qnode[i], --qidx[i];
	solve();
	REP(i, nq) { if (i != 0) printf(" "); printf("%d", qans[i] == -1 ? -1 : qans[i] + 1); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}