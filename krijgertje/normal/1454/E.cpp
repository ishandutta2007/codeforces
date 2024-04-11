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

int n;
vector<int> adj[MAXN];

int par[MAXN];
int cyc[MAXN], ncyc;

bool dfscyc(int at) {
	REPSZ(i, adj[at]) {
		int to = adj[at][i];
		if (to == par[at]) continue;
		if (par[to] == -2) {
			par[to] = at;
			if (dfscyc(to)) return true;
		} else {
			ncyc = 0;
			for (int x = at; x != to; x = par[x]) cyc[ncyc++] = x;
			cyc[ncyc++] = to;
			return true;
		}
	}
	return false;
}

int dfscnt(int at, int par) {
	//printf("dfscnt(%d,%d)\n", at + 1, par + 1);
	//static int tmp = 0; if (++tmp > 100) exit(0);
	int ret = 1;
	REPSZ(i, adj[at]) {
		int to = adj[at][i];
		if (to == par) continue;
		ret += dfscnt(to, at);
	}
	return ret;
}

ll solve() {
	REP(i, n) par[i] = -2;
	par[0] = -1;
	assert(dfscyc(0));
	//printf("cyc:"); REP(i, ncyc) printf(" %d", cyc[i] + 1); puts("");

	ll ret = (ll)n * (n - 1);
	REP(i, ncyc) {
		int at = cyc[i];
		int cnt = 1;
		REPSZ(j, adj[at]) {
			int to = adj[at][j];
			if (to == cyc[(i + 1) % ncyc] || to == cyc[(i + ncyc - 1) % ncyc]) continue;
			cnt += dfscnt(to, at);
		}
		ret -= (ll)cnt * (cnt - 1) / 2;
	}
	return ret;
}

void run() {
	scanf("%d", &n);
	REP(i, n) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%lld\n", solve());
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}