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

int n, m;
vector<int> out[MAXN];
vector<int> in[MAXN];
vector<int> ans;

int cat[MAXN];

void solve() {
	// cat 2: at least an incoming edge from cat 1
	// cat 1: at leat an incoming edge from cat 0
	// cat 0: other
	REP(i, n) {
		cat[i] = 0;
		REPSZ(ii, in[i]) {
			int j = in[i][ii];
			if (cat[j] == 2) continue;
			cat[i] = max(cat[i], cat[j] + 1);
		}
	}
	ans.clear(); REP(i, n) if (cat[i] == 2) ans.PB(i);
}

void run() {
	scanf("%d%d", &n, &m);
	REP(i, n) in[i].clear(), out[i].clear();
	REP(i, m) { int a, b; scanf("%d%d", &a, &b); --a, --b; out[a].PB(b); in[b].PB(a); }
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}