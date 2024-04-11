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
const int GRAY = 0;
const int WHITE = 1;
const int BLACK = 2;


int n;
int col[MAXN];
vector<int> adj[MAXN];

bool alive[MAXN];
int deg[MAXN];
vector<int> leafbycol[3];

int calc(int fstcol) {
	REP(i, n) deg[i] = SZ(adj[i]), alive[i] = true;
	REP(i, 3) leafbycol[i].clear();
	REP(i, n) if (deg[i] <= 1) leafbycol[col[i]].PB(i);
	int nalive = n; int nxtcol = fstcol; int ret = 0;
	while (nalive > 0) {
		++ret;
		int curcol = nxtcol;
		nxtcol = 3 - nxtcol;
		while (true) {
			bool change = false;
			REP(i, 3) if (i != 3 - curcol) {
				while (SZ(leafbycol[i]) >= 1) {
					int at = leafbycol[i].back(); leafbycol[i].pop_back();
					change = true;
					alive[at] = false, --nalive;
					REPSZ(j, adj[at]) {
						int to = adj[at][j];
						if (--deg[to] == 1) leafbycol[col[to]].PB(to);
					}
				}
			}
			if (!change) break;
		}
	}
	return ret;
}

int solve() {
	return min(calc(WHITE), calc(BLACK));
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &col[i]);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%d\n", solve());
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}