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

const int MAXH = 100;
const int MAXW = 100;

int h, w;
char g[MAXH][MAXW + 1];

bool solve() {
	REP(x, h) REP(y, w) if (g[x][y] != '*') {
		int want = g[x][y] == '.' ? 0 : g[x][y] - '0';
		int have = 0; FORE(dx, -1, +1) FORE(dy, -1, +1) { int nx = x + dx, ny = y + dy; if (0 <= nx&&nx < h && 0 <= ny&&ny < w&&g[nx][ny] == '*') ++have; }
		if (want != have) return false;
	}
	return true;
}

void run() {
	scanf("%d%d", &h, &w);
	REP(x, h) scanf("%s", g[x]);
	printf("%s\n", solve() ? "YES" : "NO");
}

int main() {
	run();
	return 0;
}