#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
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
typedef long long ll;
typedef unsigned long long ull;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 10;

int n;
char a[MAXN][MAXN + 1];
char b[MAXN][MAXN + 1];
char c[MAXN][MAXN + 1];

bool same() { REP(x, n) REP(y, n) if (a[x][y] != b[x][y]) return false; return true; }
void dorotate() { REP(x, n) REP(y, n) c[x][y] = a[x][y]; REP(x, n) REP(y, n) a[y][n - x - 1] = c[x][y]; }
void doflip() { REP(x, n) REP(y, n) c[x][y] = a[x][y]; REP(x, n) REP(y, n) a[x][n - y - 1] = c[x][y]; }

bool solve() {
	REP(flip, 2) {
		REP(rot, 4) {
			if (same()) return true;
			dorotate();
		}
		doflip();
	}
	return false;
}

void run() {
	scanf("%d", &n); REP(i, n) scanf("%s", a[i]); REP(i, n) scanf("%s", b[i]);
	printf("%s\n", solve() ? "Yes" : "No");
}

int main() {
	run();
	return 0;
}