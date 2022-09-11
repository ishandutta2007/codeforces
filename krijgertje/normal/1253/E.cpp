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

const int MAXP = 80;
const int MAXX = 100000;
struct P { int x, r; };
bool operator<(const P& a, const P& b) { return a.x < b.x; }

int np, nx;
P p[MAXP];

int dp[MAXX][MAXP+1]; // dp[x][i] = minimum cost to cover [0..x], with only possibly usefull increased antenna is i (which covers x)
void upd(int& a, int b) { a = min(a, b); }

int solve() {
	sort(p, p + np);
	REP(x, nx) REP(i, np) dp[x][i] = INT_MAX;

	REP(x, nx) {
		int any; if (x == 0) { any = 0; } else { any = INT_MAX; REP(i, np) upd(any, dp[x - 1][i]); } if (any == INT_MAX) continue;
		REP(i, np) {
			int dx = abs(x - p[i].x), xx = min(nx - 1, p[i].x + dx);
			int cost = max(0, dx - p[i].r);
			upd(dp[xx][i], any + cost);
			if (x - 1 >= 0 && dp[x - 1][i] != INT_MAX) {
				int pdx = abs(x - 1 - p[i].x), pcost = max(0, pdx - p[i].r), dcost = cost < pcost ? 0 : cost - pcost;
				upd(dp[xx][i], dp[x - 1][i] + dcost);
			}
		}
	}
	int ret = INT_MAX; REP(i, np) upd(ret, dp[nx - 1][i]); return ret;
}

void run() {
	scanf("%d%d", &np, &nx);
	REP(i, np) scanf("%d%d", &p[i].x, &p[i].r), --p[i].x;
	printf("%d\n", solve());
}

int main() {
	run();
	return 0;
}