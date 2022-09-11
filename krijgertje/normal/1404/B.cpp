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

int n, sme, she, dme, dhe;
vector<int> adj[MAXN];

int d[MAXN];
int q[MAXN], qhead, qtail;

int calcdist(int s) {
	qhead = qtail = 0; REP(i, n) d[i] = INT_MAX;
	d[s] = 0, q[qhead++] = s;
	while (qtail < qhead) {
		int at = q[qtail++];
		REPSZ(i, adj[at]) { int to = adj[at][i]; if (d[to] == INT_MAX) d[to] = d[at] + 1, q[qhead++] = to; }
	}
	assert(qhead == n); return q[n - 1];
}

bool solve() {
	int x = calcdist(sme);
	if (d[she] <= dme) return true;
	if (dhe <= 2 * dme) return true;
	int y = calcdist(x);
	if (d[y] <= 2 * dme) return true;
	return false;
}

void run() {
	scanf("%d%d%d%d%d", &n, &sme, &she, &dme, &dhe); --sme, --she;
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%s\n", solve() ? "Alice" : "Bob");
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}