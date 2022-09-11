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

int n, k;
vector<int> adj[MAXN];

int deg[MAXN];
int val[MAXN];

int solve() {
	REP(i, n) deg[i] = SZ(adj[i]);
	queue<int> q;
	REP(i, n) if (deg[i] <= 1) q.push(i);
	REP(i, n) val[i] = -1;
	for (int v = 1; !q.empty();++v) {
		queue<int> nq;
		while (!q.empty()) {
			int at = q.front(); q.pop();
			val[at] = v;
			for (int to : adj[at]) {
				if (--deg[to] == 1) nq.push(to);
			}
		}
		q = nq;
	}
	int ret = 0;
	REP(i, n) if (val[i] > k) ++ret;
	return ret;
}

void run() {
	scanf("%d%d", &n, &k);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n", solve());
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}