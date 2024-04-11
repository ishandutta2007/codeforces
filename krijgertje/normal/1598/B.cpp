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

const int MAXN = 1000;

int n;
int a[MAXN][5];

bool solve() {
	REP(i, 5) FOR(j, i + 1, 5) {
		int ni = 0, nj = 0, nboth = 0;
		REP(k, n) {
			int x = a[k][i], y = a[k][j];
			if (x == 1 && y == 1) ++nboth; else if (x == 1) ++ni; else if (y == 1) ++nj;
		}
		if (ni + nj + nboth >= n && ni + nboth >= n / 2 && nj + nboth >= n / 2) return true;
	}
	return false;
}

void run() {
	scanf("%d", &n);
	REP(i, n) REP(j, 5) scanf("%d", &a[i][j]);
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}