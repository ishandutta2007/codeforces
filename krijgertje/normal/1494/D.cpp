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

const int MAXN = 500;

int n;
int a[MAXN][MAXN];
int nemp;
vector<int> sal;
vector<int> par;

void solve() {
	vector<pair<int, pair<int, int>>> e;
	REP(i, n) FOR(j, i + 1, n) e.PB(MP(a[i][j], MP(i, j)));
	sort(e.begin(), e.end());
	nemp = n;
	sal = vector<int>(n); REP(i, n) sal[i] = a[i][i];
	par = vector<int>(n, -1);
	vector<vector<bool>> done(n, vector<bool>(n, false));
	REPSZ(i, e) {
		int v = e[i].first, x = e[i].second.first, y = e[i].second.second;
		while (par[x] != -1 && sal[par[x]] != v) x = par[x];
		while (par[y] != -1 && sal[par[y]] != v) y = par[y];
		if (par[x] != -1 && par[y] != -1) {
			assert(par[x] == par[y]);
			continue;
		}
		if (par[y] != -1) swap(x, y);
		if (par[x] != -1) {
			par[y] = par[x];
			continue;
		}
		int id = nemp;
		++nemp; sal.PB(v); par.PB(-1);
		par[x] = par[y] = id;
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n) REP(j, n) scanf("%d", &a[i][j]);
	solve();
	printf("%d\n", nemp);
	REP(i, nemp) { if (i != 0) printf(" "); printf("%d", sal[i]); } puts("");
	REP(i, nemp) if (par[i] == -1) printf("%d\n", i + 1);
	REP(i, nemp) if (par[i] != -1) printf("%d %d\n", i + 1, par[i] + 1);
}

int main() {
	run();
	return 0;
}