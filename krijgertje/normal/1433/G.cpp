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

const int MAXN = 1000;
const int MAXM = 1000;
const int MAXROUTE = 1000;

int n, m, nroute;
int e[MAXM][3];
int route[MAXROUTE][2];

int d[MAXN][MAXN];
vector<int> adj[MAXN];

int solve() {
	REP(i, m) REP(j, 2) adj[e[i][j]].PB(i);
	REP(s, n) {
		REP(i, n) d[s][i] = INT_MAX;
		d[s][s] = 0;
		priority_queue<pair<int, int>> pq;
		pq.push(MP(-d[s][s], s));
		while (!pq.empty()) {
			int cost = -pq.top().first, at = pq.top().second; pq.pop();
			if (d[s][at] != cost) continue;
			REPSZ(i, adj[at]) {
				int id = adj[at][i];
				int to = e[id][0] ^ e[id][1] ^ at;
				int ncost = cost + e[id][2];
				if (ncost < d[s][to]) d[s][to] = ncost, pq.push(MP(-d[s][to], to));
			}
		}
	}
	int ret = 0;
	REP(i, nroute) ret += d[route[i][0]][route[i][1]];
	REP(i, m) {
		int cur = 0;
		REP(j, nroute) {
			int now = d[route[j][0]][route[j][1]];
			now = min(now, d[route[j][0]][e[i][0]] + 0 + d[e[i][1]][route[j][1]]);
			now = min(now, d[route[j][0]][e[i][1]] + 0 + d[e[i][0]][route[j][1]]);
			cur += now;
		}
		ret = min(ret, cur);
	}
	return ret;
}

void run() {
	scanf("%d%d%d", &n, &m, &nroute);
	REP(i, m) scanf("%d%d%d", &e[i][0], &e[i][1], &e[i][2]), --e[i][0], --e[i][1];
	REP(i, nroute) REP(j, 2) scanf("%d", &route[i][j]), --route[i][j];
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}