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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 100000;
const int MAXQ = 100000;

int n, nq;
int qx[MAXQ], qy[MAXQ]; bool qans[MAXQ];

bool isblocked[2][MAXN];

void solve() {
	REP(x, 2) REP(y, n) isblocked[x][y] = false;
	int cntbad = 0;
	REP(i, nq) {
		int x = qx[i], y = qy[i];
		FORE(dy, -1, +1) {
			int nx = 1 - x, ny = y + dy; if (ny < 0 || ny >= n) continue;
			if (isblocked[x][y] && isblocked[nx][ny]) --cntbad;
		}
		isblocked[x][y] = !isblocked[x][y];
		FORE(dy, -1, +1) {
			int nx = 1 - x, ny = y + dy; if (ny < 0 || ny >= n) continue;
			if (isblocked[x][y] && isblocked[nx][ny]) ++cntbad;
		}
		qans[i] = cntbad == 0;
	}
}

void run() {
	scanf("%d%d", &n, &nq);
	REP(i, nq) scanf("%d%d", &qx[i], &qy[i]), --qx[i], --qy[i];
	solve();
	REP(i, nq) printf("%s\n", qans[i] ? "Yes" : "No");
}

int main() {
	run();
	return 0;
}