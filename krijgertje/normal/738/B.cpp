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

const int MAXH = 1000;
const int MAXW = 1000;

int h, w;
int a[MAXH][MAXW];

void run() {
	scanf("%d%d", &h, &w); REP(x, h) REP(y, w) scanf("%d", &a[x][y]);
	int ret = 0;
	REP(x, h) {
		int fst = INT_MAX, lst = INT_MIN; REP(y, w) if (a[x][y] == 1) fst = min(fst, y), lst = max(lst, y); if (fst > lst) continue;
		//printf("x%d: %d..%d\n", x, fst, lst);
		REP(y, w) if (a[x][y] == 0) ret += (y > fst ? 1 : 0) + (y < lst ? 1 : 0);
	}
	REP(y, w) {
		int fst = INT_MAX, lst = INT_MIN; REP(x, h) if (a[x][y] == 1) fst = min(fst, x), lst = max(lst, x); if (fst > lst) continue;
		//printf("y%d: %d..%d\n", y, fst, lst);
		REP(x, h) if (a[x][y] == 0) ret += (x > fst ? 1 : 0) + (x < lst ? 1 : 0);
	}
	printf("%d\n", ret);
}

int main() {
	run();
	return 0;
}