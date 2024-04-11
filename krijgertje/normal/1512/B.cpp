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

int dim;
vector<string> g;
vector<string> ans;

void solve() {
	vector<int> xx;
	vector<int> yy;
	REP(x, dim) REP(y, dim) if (g[x][y] == '*') xx.PB(x), yy.PB(y);
	sort(xx.begin(), xx.end()); xx.erase(unique(xx.begin(), xx.end()), xx.end());
	sort(yy.begin(), yy.end()); yy.erase(unique(yy.begin(), yy.end()), yy.end());
	assert(SZ(xx) >= 1 && SZ(xx) <= 2);
	assert(SZ(yy) >= 1 && SZ(yy) <= 2);
	if (SZ(xx) == 1) xx.PB(xx[0] == 0 ? 1 : 0);
	if (SZ(yy) == 1) yy.PB(yy[0] == 0 ? 1 : 0);
	ans = vector<string>(dim, string(dim, '.'));
	for (int x : xx) for (int y : yy) ans[x][y] = '*';
}

void run() {
	scanf("%d", &dim);
	g = vector<string>(dim); REP(i, dim) cin >> g[i];
	solve();
	REPSZ(i, ans) cout << ans[i] << '\n';
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}