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
const int MAXPAL = 100000;

int n, wantpal;
char g[MAXN][MAXN + 1];
int ans[MAXPAL + 1];

bool solve() {
	if (wantpal % 2 == 1) { REP(z, wantpal + 1) ans[z] = z % 2; return true; }
	REP(i, n) REP(j, n) if (j != i && g[i][j] == g[j][i]) { REP(z, wantpal + 1) ans[z] = z % 2 == 0 ? i : j; return true; }
	REP(i, n) {
		int j = (i + 1) % n; 
		REP(k, n) if (k != i && k != j && g[i][k] != g[i][j]) {
			int at = 0;
			if (wantpal % 4 == 2) ans[at++] = j;
			ans[at++] = i;
			REP(z, wantpal / 4) ans[at++] = j, ans[at++] = i;
			REP(z, wantpal / 4) ans[at++] = k, ans[at++] = i;
			if (wantpal % 4 == 2) ans[at++] = k ;
			assert(at == wantpal + 1);
			return true;
		}
	}
	assert(wantpal % 2 == 0 && n == 2);
	return false;
}

void run() {
	scanf("%d%d", &n, &wantpal);
	REP(x, n) scanf("%s", g[x]);
	if (!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REP(i, wantpal + 1) { if (i != 0) printf(" "); printf("%d", ans[i] + 1); } puts("");
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}