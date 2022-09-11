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

int n, mxcomp;
int val[MAXN];
vector<int> adj[MAXN];
int totalsum;

pair<int,int> dfs(int at, int par) {
	int sum = val[at], res = 0;
	for (int to : adj[at]) {
		if (to == par) continue;
		pair<int, int> sub = dfs(to, at);
		sum ^= sub.first;
		if (sub.second == 2) res = 2;
		if (res != 2 && sub.second == 1) ++res;
	}
	if (res == 0 && sum == totalsum) res = 1;
	if (res == 1 && sum == 0) res = 2;
	return MP(sum, res);
}

bool solve() {
	totalsum = 0;
	REP(i, n) totalsum ^= val[i];
	if (mxcomp >= 2 && totalsum == 0 && n >= 2) return true;
	return mxcomp >= 3 && dfs(0, -1).second == 2;
}

void run() {
	scanf("%d%d", &n, &mxcomp);
	REP(i, n) scanf("%d", &val[i]);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b); adj[b].PB(a); }
	printf("%s\n", solve() ? "YES" : "NO");
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}