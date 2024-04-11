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

int n;
int val[MAXN];
vector<int> adj[MAXN];
ll ans[MAXN];

void solve() {
	ll sum = 0; REP(i, n) sum += val[i];
	vector<int> opt; REP(i, n) REP(j, SZ(adj[i]) - 1) opt.PB(val[i]);
	sort(opt.begin(), opt.end());
	reverse(opt.begin(), opt.end());
	assert(SZ(opt) == n - 2);
	ans[1] = sum;
	REPSZ(i, opt) ans[2 + i] = ans[1 + i] + opt[i];
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &val[i]);
	REP(i, n - 1) { int a, b; scanf("%d%d", &a, &b); --a, --b; adj[a].PB(b), adj[b].PB(a); }
	solve();
	FORE(k, 1, n - 1) { if (k != 1) printf(" "); printf("%lld", ans[k]); } puts("");
	REP(i, n) adj[i].clear();
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}