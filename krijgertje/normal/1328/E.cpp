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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 200000;
const int MAXQ = 200000;

int n, nq;
vector<int> adj[MAXN];
vector<int> q[MAXQ];
bool qans[MAXQ];

int par[MAXN], dep[MAXN];
int lid[MAXN], rid[MAXN], nid;

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	lid[at] = nid++;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par[at]) continue;
		par[to] = at; dfsinit(to);
	}
	rid[at] = nid - 1;
}

void solve() {
	par[0] = -1; nid = 0; dfsinit(0);
	REP(i, nq) {
		vector<pair<int, int>> cur;
		REPSZ(j, q[i]) {
			int at = q[i][j];
			int onpath = par[at] == -1 ? at : par[at];
			cur.PB(MP(dep[onpath], onpath));
		}
		sort(cur.begin(), cur.end());
		bool ok = true;
		FORSZ(j, 1, cur) {
			int a = cur[j - 1].second, b = cur[j].second;
			if (!(lid[a] <= lid[b] && rid[b] <= rid[a])) ok = false;
		}
		qans[i] = ok;
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b), adj[b].PB(a); }
	REP(i, nq) { int cnt; scanf("%d", &cnt); q[i] = vector<int>(cnt); REP(j, cnt) scanf("%d", &q[i][j]), --q[i][j]; }
	solve();
	REP(i, nq) printf("%s\n", qans[i] ? "YES" : "NO");
}

int main() {
	run();
	return 0;
}