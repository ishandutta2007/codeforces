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

const int MAXN = 300000;

int n;
vector<int> adj[MAXN];
bool win[MAXN];

int par[MAXN];
int sum[MAXN];

bool ground[MAXN];

void dfsinit(int at) {
	sum[at] = 0;
	for (int to : adj[at]) {
		if (to == par[at]) continue;
		par[to] = at;
		dfsinit(to);
		sum[at] ^= 1 + sum[to];
	}
}

void solve() {
	par[0] = -1;
	dfsinit(0);

	REP(i, n) ground[i] = false;
	int totalsum = sum[0];
	ground[0] = true;
	win[0] = totalsum != 0;
	FOR(i, 1, n) {
		int at = i;
		//printf("grounding %d\n", i + 1);
		while (!ground[at]) {
			//printf("\tat=%d -> xor %d ^ %d ^ 1\n", at + 1, sum[at], 1 + sum[at]);
			totalsum ^= sum[at] ^ (1 + sum[at]) ^ 1;
			ground[at] = true;
			at = par[at];
		}
		//printf("-> %d\n", totalsum);
		win[i] = totalsum != 0;
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	solve();
	REP(i, n) printf("%c", win[i] ? '1' : '2');
}

int main() {
	run();
	return 0;
}