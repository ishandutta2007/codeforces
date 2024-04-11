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

const int MAXN = 100000;

int n;
int col[MAXN];
int ans[MAXN];

int mx[MAXN][2];

void solve() {
	REP(i, n) REP(j, 2) mx[i][j] = 0;
	REP(i, n) {
		int c = col[i];
		int x = i % 2;
		int a = mx[c][0], b = mx[c][1];
		if(x==0) mx[c][0] = max(a, b + 1);
		if(x==1) mx[c][1] = max(b, a + 1);
	}
	REP(i, n) ans[i] = max(mx[i][0], mx[i][1]);
}

void run() {
	scanf("%d", &n);
	REP(i, n) scanf("%d", &col[i]), --col[i];
	solve();
	REP(i, n) { if (i != 0) printf(" "); printf("%d", ans[i]); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}