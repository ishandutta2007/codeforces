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

const int MAXN = 100000;
const int MAXQ = 100000;
const int NBIT = 30;

int n, m;
vector<pair<int, int>> adj[MAXN];
int nq;
int qx[MAXQ], qy[MAXQ];
int qans[MAXQ];

int comp[NBIT][MAXN];
bool canzero[NBIT][MAXN];

int calc(int x, int y) {
	REP(bit, NBIT) if (comp[bit][x] == comp[bit][y]) return 0;
	FOR(bit, 1, NBIT) if (canzero[bit][comp[bit][x]]) return 1;
	return 2;
}

void solve() {
	REP(bit, NBIT) {
		int ncomp = 0;
		REP(i, n) comp[bit][i] = -1;
		REP(i, n) if (comp[bit][i] == -1) {
			int c = ncomp++;
			canzero[bit][c] = false;
			queue<int> q;
			comp[bit][i] = c, q.push(i);
			while (!q.empty()) {
				int at = q.front(); q.pop();
				for (const auto &e : adj[at]) {
					int to = e.first, w = e.second;
					if ((w & (1 << bit)) != 0 && comp[bit][to] == -1) {
						comp[bit][to] = c, q.push(to);
					}
					if ((w & 1) == 0) canzero[bit][c] = true;
				}
			}
		}
	}
	REP(i, nq) qans[i] = calc(qx[i],qy[i]);
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, m) { int a, b, c; scanf("%d%d%d", &a, &b, &c); --a, --b; adj[a].PB(MP(b, c)); adj[b].PB(MP(a, c)); }
	scanf("%d", &nq);
	REP(i, nq) scanf("%d%d", &qx[i], &qy[i]), --qx[i], --qy[i];
	solve();
	REP(i, nq) printf("%d\n", qans[i]);
}

int main() {
	run();
	return 0;
}