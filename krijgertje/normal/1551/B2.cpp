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

int n, ncol;
int a[MAXN];
int ans[MAXN];

void solve() {
	map<int, vector<int>> pos;
	REP(i, n) pos[a[i]].PB(i);
	vector<int> lst;
	for (const auto& z : pos) REP(i, min(ncol, SZ(z.second))) lst.PB(z.second[i]);
	int k = SZ(lst) / ncol;
	REP(i, n) ans[i] = 0;
	REP(i, ncol) REP(j, k) ans[lst[j * ncol + i]] = i + 1;
}

void run() {
	scanf("%d%d", &n, &ncol);
	REP(i, n) scanf("%d", &a[i]);
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}