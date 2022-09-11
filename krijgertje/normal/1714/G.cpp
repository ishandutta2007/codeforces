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

const int MAXN = 200000;

int n;
int par[MAXN], a[MAXN], b[MAXN];
int ans[MAXN];

vector<vector<int>> ch;
ll bsum[MAXN]; int nb;

void dfs(int at, ll asum) {
	ans[at] = upper_bound(bsum, bsum + nb, asum) - bsum;
	for (int to : ch[at]) {
		bsum[nb] = (nb == 0 ? 0 : bsum[nb - 1]) + b[to];
		++nb;
		dfs(to, asum + a[to]);
		--nb;
	}
}

void solve() {
	ch = vector<vector<int>>(n);
	REP(i, n) if (par[i] != -1) ch[par[i]].PB(i);
	nb = 0;
	dfs(0, 0);
}

void run() {
	scanf("%d", &n);
	par[0] = -1, a[0] = b[0] = 0; FOR(i, 1, n) scanf("%d%d%d", &par[i], &a[i], &b[i]), --par[i];
	solve();
	FOR(i, 1, n) { if (i != 1) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}