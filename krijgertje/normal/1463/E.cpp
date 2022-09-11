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
const int MAXCONS = MAXN - 1;

int n, ncons;
int par[MAXN];
int cons[MAXCONS][2];
int ans[MAXN];

int prv[MAXN], nxt[MAXN];
int chainidx[MAXN], chainoffset[MAXN];
vector<vector<int>> chains;
vector<int> waitcnt;
vector<int> ch[MAXN];

bool solve() {
	REP(i, n) ch[i].clear();
	REP(i, n) if (par[i] != -1) ch[par[i]].PB(i);
	REP(i, n) prv[i] = nxt[i] = -1;
	REP(i, ncons) {
		int a = cons[i][0], b = cons[i][1];
		if (nxt[a] != -1 || prv[b] != -1) return false;
		nxt[a] = b, prv[b] = a;
	}
	chains.clear();
	REP(i, n) chainidx[i] = -1, chainoffset[i] = -1;
	REP(i, n) if (prv[i] == -1) {
		vector<int> chain;
		int at = i;
		while (at != -1) {
			if (chainidx[at] != -1 || chainoffset[at] != -1) return false;
			chainidx[at] = SZ(chains), chainoffset[at] = SZ(chain);
			chain.PB(at);
			at = nxt[at];
		}
		chains.PB(chain);
	}
	REP(i, n) if (chainidx[i] == -1 || chainoffset[i] == -1) return false;
	//REPSZ(i, chains) { printf("chain%d:", i); REPSZ(j, chains[i]) printf(" %d", chains[i][j] + 1); puts(""); }
	waitcnt = vector<int>(SZ(chains), 0);
	REP(i, n) {
		int j = par[i];
		if (j == -1) continue;
		if (chainidx[i] == chainidx[j]) {
			if (chainoffset[i] < chainoffset[j]) return false;
		} else {
			++waitcnt[chainidx[i]];
		}
	}
	queue<int> q;
	REPSZ(i, chains) if (waitcnt[i] == 0) q.push(i);
	int nans = 0;
	while (!q.empty()) {
		int c = q.front(); q.pop();
		REPSZ(i, chains[c]) {
			int at = chains[c][i];
			ans[nans++] = at;
			REPSZ(j, ch[at]) {
				int to = ch[at][j];
				if (chainidx[to] == chainidx[at]) continue;
				if (--waitcnt[chainidx[to]] == 0) q.push(chainidx[to]);
			}
		}
	}
	return nans == n;
}

void run() {
	scanf("%d%d", &n, &ncons);
	REP(i, n) scanf("%d", &par[i]), --par[i];
	REP(i, ncons) REP(j, 2) scanf("%d", &cons[i][j]), --cons[i][j];
	if (!solve()) { printf("0\n"); return; }
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	run();
	return 0;
}