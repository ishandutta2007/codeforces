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

const int MAXN = 200000;
const int MOD = 1000000007;
void inc(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }

int n, m;
int s, t;
vector<int> adj[MAXN];

int d[MAXN];
int ways[MAXN][2];

int solve() {
	{
		REP(i, n) d[i] = INT_MAX;
		queue<int> q;
		auto relax = [&](int to, int val) { if (d[to] == INT_MAX) d[to] = val, q.push(to); };
		relax(s, 0);
		while (!q.empty()) {
			int at = q.front(); q.pop();
			for (int to : adj[at]) relax(to, d[at] + 1);
		}
	}
	REP(i, n) REP(j, 2) ways[i][j] = 0;
	inc(ways[s][0], 1);
	vector<pair<int, int>> states;
	REP(i, n) REP(j, 2) states.PB(MP(i, j));
	sort(states.begin(), states.end(), [&](pair<int, int> a, pair<int, int> b) { return d[a.first] + a.second < d[b.first] + b.second; });
	for (auto state : states) {
		int at = state.first, extra = state.second;
		//printf("\t%d %d: dist=%d ways=%d\n", at + 1, extra, d[at] + extra, ways[at][extra]);
		for (int to : adj[at]) {
			int nextra = d[at] + extra + 1 - d[to];
			assert(nextra >= 0);
			if (nextra >= 2) continue;
			inc(ways[to][nextra], ways[at][extra]);
		}
	}
	int ret = 0;
	REP(j, 2) inc(ret, ways[t][j]);
	return ret;
}

void run() {
	scanf("%d%d", &n, &m);
	scanf("%d%d", &s, &t), --s, --t;
	REP(i, m) { int a, b; scanf("%d%d", &a, &b), --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n", solve());
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}