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
const int MAXVAL = 200000;

int n, mxval;
int val[MAXN];
int lim[MAXVAL + 1];
vector<vector<int>> ans;

int have[MAXVAL + 1];
int o[MAXN], no;

void solve() {
	FORE(i, 1, mxval) have[i] = 0;
	REP(i, n) ++have[val[i]];
	no = 0; for (int i = mxval; i >= 1; --i) REP(j, have[i]) o[no++] = i;
	for (int i = mxval - 1; i >= 0; --i) have[i] += have[i + 1];

	int nans = 0; FORE(i, 1, mxval) nans = max(nans, (have[i] + lim[i] - 1) / lim[i]);
	ans = vector<vector<int>>(nans);
	REP(i, n) ans[i % nans].PB(o[i]);
}

void run() {
	scanf("%d%d", &n, &mxval);
	REP(i, n) scanf("%d", &val[i]);
	FORE(i, 1, mxval) scanf("%d", &lim[i]);
	solve();
	printf("%d\n", SZ(ans));
	REPSZ(i, ans) { printf("%d", SZ(ans[i])); REPSZ(j, ans[i]) printf(" %d", ans[i][j]); puts(""); }
}

int main() {
	run();
	return 0;
}