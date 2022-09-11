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

const int MAXDIM = 50;

int h, w;
int ans[MAXDIM][MAXDIM];

void solve() {
	REP(x, h) REP(y, w) ans[x][y] = (x / 2 + y / 2) % 2 == 0 ? 0 : 1;
	REP(x, h) REP(y, w) if ((x + y) % 2 == 1) ans[x][y] ^= 1;
}

void run() {
	scanf("%d%d", &h, &w);
	solve();
	REP(x, h) { REP(y, w) { if (y != 0) printf(" "); printf("%d", ans[x][y]); } puts(""); }
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}