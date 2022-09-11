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

const int MAXDIM = 1000;

int h, w;
int a[MAXDIM][MAXDIM];

int mn[MAXDIM][MAXDIM];
int mx[MAXDIM][MAXDIM];

bool solve() {
	REP(x, h) REP(y, w) mn[x][y] = INT_MAX, mx[x][y] = INT_MIN;
	mn[0][0] = mx[0][0] = a[0][0];
	REP(x, h) REP(y, w) {
		if (x - 1 >= 0) mn[x][y] = min(mn[x][y], mn[x - 1][y] + a[x][y]);
		if (x - 1 >= 0) mx[x][y] = max(mx[x][y], mx[x - 1][y] + a[x][y]);
		if (y - 1 >= 0) mn[x][y] = min(mn[x][y], mn[x][y - 1] + a[x][y]);
		if (y - 1 >= 0) mx[x][y] = max(mx[x][y], mx[x][y - 1] + a[x][y]);
	}
	//printf("%d..%d\n", mn[h - 1][w - 1], mx[h - 1][w - 1]);
	return mn[h - 1][w - 1] % 2 == 0 && mn[h - 1][w - 1] <= 0 && mx[h - 1][w - 1] >= 0;
}

void run() {
	scanf("%d%d", &h, &w);
	REP(x, h) REP(y, w) scanf("%d", &a[x][y]);
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}