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

const int MAXN = 16;

int n;
vector<int> adj[1 << MAXN];
int perm[1 << MAXN];
int col[1 << MAXN];

int state[1 << MAXN];

bool solve() {
	REP(i, 1 << n) state[i] = 0;
	auto mark = [&](int at) { state[at] = -1; for (int to : adj[at]) { if (state[to] == -1) continue; ++state[to]; } };
	mark(0);
	perm[0] = 0;
	REP(i, n) {
		REP(j, 1 << i) {
			int x = -1; for (int to : adj[perm[j]]) if (state[to] >= (j == 0 ? 1 : 2)) { x = to; break; } assert(x != -1);
			mark(x);
			perm[(1 << i) + j] = x;
		}
	}
	int k = 0; while ((2 << k) <= n) ++k;
	if ((1 << k) != n) return false;
	REP(i, 1 << n) { int c = 0; REP(j, n) if (i & (1 << j)) c ^= j; col[perm[i]] = c; }
	return true;
}

void run() {
	scanf("%d", &n);
	REP(i, n * (1 << (n - 1))) { int a, b; scanf("%d%d", &a, &b); adj[a].PB(b); adj[b].PB(a); }
	bool res = solve();
	REP(i, 1 << n) { if (i != 0) printf(" "); printf("%d", perm[i]); } puts("");
	if (!res) {
		printf("-1\n");
	} else {
		REP(i, 1 << n) { if (i != 0) printf(" "); printf("%d", col[i]); } puts("");
	}
	REP(i, 1 << n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}