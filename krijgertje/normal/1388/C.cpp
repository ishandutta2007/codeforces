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

int n, totsumperson;
int cntperson[MAXN];
int happiness[MAXN];
vector<int> adj[MAXN];

int sumperson[MAXN];
int sumhappy[MAXN];
int sumunhappy[MAXN];

bool rec(int at, int par) {
	sumperson[at] = cntperson[at], sumhappy[at] = 0, sumunhappy[at] = 0;
	REPSZ(i, adj[at]) {
		int to = adj[at][i]; if (to == par) continue;
		if (!rec(to, at)) return false;
		sumperson[at] += sumperson[to], sumhappy[at] += sumhappy[to], sumunhappy[at] += sumunhappy[to];
	}
	//sumhappy[at] + x - sumunhappy[at] - (cntperson[at] - x) = happiness[at];
	ll x = happiness[at] - sumhappy[at] + cntperson[at] + sumunhappy[at];
	//printf("%d: 2x=%lld\n", at + 1, x);
	if (x % 2 != 0) return false; else x /= 2;
	if (x < 0 || x > cntperson[at] + sumunhappy[at]) return false;
	sumhappy[at] += x, sumunhappy[at] += cntperson[at] - x;
	return true;
}

bool solve() {
	return rec(0, -1);
}

void run() {
	scanf("%d%d", &n, &totsumperson);
	REP(i, n) scanf("%d", &cntperson[i]);
	REP(i, n) scanf("%d", &happiness[i]);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b), adj[b].PB(a); }
	bool ans = solve();
	REP(i, n) adj[i].clear();
	printf("%s\n", ans ? "YES" : "NO");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}