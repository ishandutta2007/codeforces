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
const int MAXM = 500000;

int n, m;
int e[MAXM][3];

vector<pair<int, int>> adj[MAXN];
int col[MAXN];

int solve() {
	REP(i, n) adj[i].clear();
	REP(i, m) { int a = e[i][0], b = e[i][1], c = e[i][2]; adj[a].PB(MP(b, c)); adj[b].PB(MP(a, c)); }
	
	int ret = 0;
	REP(i, n) col[i] = -1;
	REP(i, n) if (col[i] == -1) {
		queue<int> q;
		vector<int> cnt(2, 0);
		col[i] = 0;
		q.push(i);
		while (!q.empty()) {
			int at = q.front(); q.pop();
			++cnt[col[at]];
			for (auto z : adj[at]) {
				int to = z.first, ncol = col[at] ^ z.second;
				if (col[to] != -1 && col[to] != ncol) return -1;
				if (col[to] == -1) col[to] = ncol, q.push(to);
			}
		}
		ret += max(cnt[0], cnt[1]);
	}
	return ret;
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { REP(j, 2) scanf("%d", &e[i][j]), --e[i][j]; char s[100]; scanf("%s", s); e[i][2] = strcmp(s, "crewmate") == 0 ? 0 : 1; }
	printf("%d\n", solve());
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}