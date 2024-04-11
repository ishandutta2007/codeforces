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

const int MAXN = 400000;
const int MAXQ = 400000;

int n, nq;
vector<int> adj[MAXN];
int qx[MAXQ], qy[MAXQ]; string qs[MAXQ];
char buff[400000 + 1];
char ans[MAXN + 1];

int par[MAXN], dep[MAXN];
vector<int> qpath[MAXQ];
vector<pair<int, int>> who[MAXN];
bool done[MAXQ];

void dfsinit(int at) {
	dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1;
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
	}
}

bool solve() {
	REP(i, n) ans[i] = '?'; ans[n] = '\0';

	par[0] = -1;
	dfsinit(0);
	REP(i, nq) {
		qpath[i].clear();
		int x = qx[i], y = qy[i];
		vector<int> suff;
		while (x != y) {
			if (dep[x] >= dep[y]) {
				qpath[i].PB(x);
				x = par[x];
			} else {
				suff.PB(y);
				y = par[y];
			}
		}
		qpath[i].PB(x);
		qpath[i].insert(qpath[i].end(), suff.rbegin(), suff.rend());
		//printf("path%d:", i); for (int z : qpath[i]) printf(" %d", z + 1); puts("");
		assert(SZ(qpath[i]) == SZ(qs[i]));
	}

	REP(i, nq) {
		int len = SZ(qpath[i]);
		REPSZ(j, qpath[i]) {
			int v = qpath[i][j];
			char a = qs[i][j], b = qs[i][len - j - 1];
			if (a == b) {
				if (ans[v] != '?' && ans[v] != a) return false;
				ans[v] = a;
			} else {
				who[v].PB(MP(i, j));
			}
		}
	}

	REP(i, nq) done[i] = false;
	REP(i, nq) if (!done[i]) {
		REP(dir, 2) {
			bool ok = true;
			vector<int> assigned;
			vector<int> oriented;
			queue<int> q;
			q.push(i);
			done[i] = true;
			oriented.PB(i);
			while (!q.empty()) {
				int at = q.front(); q.pop();
				REPSZ(j, qpath[at]) {
					int v = qpath[at][j];
					char c = qs[at][j];
					if (ans[v] != '?' && ans[v] != c) { ok = false; break; }
					if (ans[v] != '?') continue;
					ans[v] = c;
					assigned.PB(v);
					for (auto z : who[v]) {
						int to = z.first, idx = z.second;
						if (qpath[to][idx] != v) idx = SZ(qs[to]) - idx - 1;
						assert(qpath[to][idx] == v);
						if (done[to]) continue;
						char a = qs[to][idx], b = qs[to][SZ(qs[to]) - idx - 1];
						assert(a != b);
						if (a == ans[v]) {
							//ok
						} else if (b == ans[v]) {
							reverse(qpath[to].begin(), qpath[to].end());
						} else {
							ok = false;
							break;
						}
						q.push(to);
						done[to] = true;
						oriented.PB(to);
					}
					if(!ok) break;
				}
				if (!ok) break;
			}
			if (ok) {
				break;
			}
			for (int v : assigned) ans[v] = '?';
			for (int at : oriented) done[at] = false;
			reverse(qpath[i].begin(), qpath[i].end());
		}
		if (!done[i]) return false;
	}

	REP(i, n) if (ans[i] == '?') ans[i] = 'a';

	return true;
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	REP(i, nq) { scanf("%d%d%s", &qx[i], &qy[i], buff); --qx[i], --qy[i]; qs[i] = buff; }
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%s\n", ans);
}

int main() {
	run();
	return 0;
}