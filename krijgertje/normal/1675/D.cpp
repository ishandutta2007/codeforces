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
int par[MAXN];
vector<vector<int>> ans;

bool isleaf[MAXN];
bool done[MAXN];

void solve() {
	ans.clear();
	REP(i, n) isleaf[i] = true;
	REP(i, n) if (par[i] != i) isleaf[par[i]] = false;
	REP(i, n) done[i] = false;
	REP(i, n) if (isleaf[i]) {
		vector<int> path;
		for (int at = i; !done[at]; at = par[at]) done[at] = true, path.PB(at);
		reverse(path.begin(), path.end());
		ans.PB(path);
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &par[i]), --par[i];
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { printf("%d\n", SZ(ans[i])); REPSZ(j, ans[i]) { if (j != 0) printf(" "); printf("%d", ans[i][j] + 1); } puts(""); }
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}