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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXH = 500;
const int MAXW = 500;

int diff;
int h, w;
int g[MAXH][MAXW];

void solve() {
	if (diff == 0) {
		h = w = 1;
		g[0][0] = 0;
	} else {
		int bit = 0; while ((1 << bit) <= diff) ++bit;
		h = 3, w = 2;
		g[0][0] = g[1][1] = (1 << bit) + diff;
		g[0][1] = g[2][1] = diff;
		g[1][0] = (1 << bit);
		g[2][0] = 0;
	}
}

void run() {
	scanf("%d", &diff);
	solve();
	printf("%d %d\n", h, w);
	REP(x, h) { REP(y, w) { if (y != 0) printf(" "); printf("%d", g[x][y]); } puts(""); }
}

int main() {
	run();
	return 0;
}