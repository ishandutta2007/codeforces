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

int n, m;
int monster[MAXN];
int gain[MAXN];
vector<int> adj[MAXN];

bool visited[MAXN];
int prv[MAXN];
ll visitpower[MAXN];

bool can(int startpower) {
	//printf("testing %d\n", startpower);
	REP(i, n) visited[i] = false;
	visited[0] = true;
	ll curpower = startpower;
	while (true) {
		REP(i, n) prv[i] = -2;
		bool change = false;
		queue<int> q;
		REP(i, n) if (visited[i]) prv[i] = -1, visitpower[i] = curpower, q.push(i);
		while (!q.empty() && !change) {
			int at = q.front(); q.pop();
			for (int to : adj[at]) {
				if (visited[at] && visited[to]) continue;
				if (!visited[to] && visitpower[at] <= monster[to]) continue;
				if (to == prv[at]) continue;
				if (prv[to] == -2) {
					assert(!visited[to]);
					prv[to] = at, visitpower[to] = visitpower[at] + gain[to], q.push(to);
				} else {
					vector<int> path;
					for (int x = at; x != -1; x = prv[x]) path.PB(x);
					reverse(path.begin(), path.end());
					for (int x = to; x != -1; x = prv[x]) path.PB(x);
					//printf("\tpath:"); REPSZ(i, path) printf(" %d", path[i] + 1); puts("");
					if (visitpower[at] < visitpower[to]) reverse(path.begin(), path.end());
					assert(SZ(path) >= 3 && visited[path[0]] && visited[path[SZ(path) - 1]]);
					bool any = false;
					FOR(i, 1, SZ(path) - 1) {
						assert(curpower > monster[path[i]]);
						if (!visited[path[i]]) {
							curpower += gain[path[i]];
							visited[path[i]] = true;
							any = true;
						}
					}
					assert(any);
					change = true;
					break;
				}
			}
		}
		if (!change) break;
	}
	REP(i, n) if (!visited[i]) return false;
	return true;
}

int solve() {
	int mxmonster = 0;
	FOR(i, 1, n) mxmonster = max(mxmonster, monster[i]);
	int lo = 0, hi = mxmonster + 1;
	while (lo + 1 < hi) {
		int mi = lo + (hi - lo) / 2;
		if (can(mi)) hi = mi; else lo = mi;
	}
	return hi;
}

void run() {
	scanf("%d%d", &n, &m);
	FOR(i, 1, n) scanf("%d", &monster[i]);
	FOR(i, 1, n) scanf("%d", &gain[i]);
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n", solve());
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}