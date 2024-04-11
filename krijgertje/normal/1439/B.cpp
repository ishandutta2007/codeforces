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

const int MAXN = 100000;

int n, m, k;
vector<int> adj[MAXN];
int anskind;
vector<int> ans;

bool alive[MAXN];
int deg[MAXN];
bool alive2[MAXN];
int deg2[MAXN];
queue<int> q;
queue<int> q2;
queue<int> q3;

bool solve() {
	ll needclique = (ll)k * (k - 1) / 2;
	if (m < needclique) return false;

	REP(i, n) alive[i] = alive2[i] = true;
	REP(i, n) deg[i] = deg2[i] = SZ(adj[i]);
	q = queue<int>();
	q2 = queue<int>();
	q3 = queue<int>();
	REP(i, n) if (deg[i] < k - 1) q.push(i);
	REP(i, n) if (deg2[i] < k) q2.push(i);
	REP(i, n) if (deg[i] == k - 1) q3.push(i);
	int cnt2 = n;

	vector<vector<int>> cand;
	while (true) {
		while (!q.empty()) {
			int at = q.front(); q.pop();
			alive[at] = false;
			REPSZ(i, adj[at]) {
				int to = adj[at][i];
				if (!alive[to]) continue;
				--deg[at], --deg[to];
				if (deg[to] == k - 2) q.push(to);
				if (deg[to] == k - 1) q3.push(to);
			}
		}
		while (!q2.empty()) {
			int at = q2.front(); q2.pop();
			alive2[at] = false;
			--cnt2;
			REPSZ(i, adj[at]) {
				int to = adj[at][i];
				if (!alive2[to]) continue;
				--deg2[at], --deg2[to];
				if (deg2[to] == k - 1) q2.push(to);
			}
		}
		if (cnt2 > 0) {
			anskind = 1;
			ans.clear();
			REP(i, n) if (alive2[i]) ans.PB(i);
			return true;
		}

		//printf("deg:"); REP(i, n) printf(" %d", deg[i]); puts("");
		bool found = false;
		while (!q3.empty()) {
			int at = q3.front(); q3.pop();
			if (deg[at] != k - 1) continue;
			vector<int> cur;
			cur.PB(at);
			REPSZ(i, adj[at]) {
				int to = adj[at][i];
				if (!alive[to]) continue;
				cur.PB(to);
			}
			assert(SZ(cur) == k);
			cand.PB(cur);
			q.push(at);
			found = true;
			break;
		}
		if (!found) break;
	}
	
	vector<vector<int>> usages(n);
	vector<bool> ok(SZ(cand), true);
	REPSZ(i, cand) REPSZ(j, cand[i]) usages[cand[i][j]].PB(i);
	vector<int> mark(n, -1);
	REP(at, n) {
		REPSZ(i, adj[at]) { int to = adj[at][i]; mark[to] = at; }
		REPSZ(i, usages[at]) {
			int id = usages[at][i];
			REPSZ(j, cand[id]) { int to = cand[id][j]; if (to != at && mark[to] != at) ok[id] = false; }
		}
	}
	REPSZ(id, cand) if (ok[id]) { anskind = 2; ans = cand[id]; return true; }

	return false;
}

void run() {
	scanf("%d%d%d", &n, &m, &k);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b), adj[b].PB(a); }
	if (!solve()) {
		printf("-1\n");
	} else {
		printf("%d", anskind);
		if (anskind == 1) printf(" %d", SZ(ans));
		puts("");
		REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
	}
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}