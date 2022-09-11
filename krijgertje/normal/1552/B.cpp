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

const int MAXN = 50000;

int n;
int rnk[MAXN][5];

int solve() {
	int best = 0;
	FOR(i, 1, n) {
		int cnt = 0;
		REP(j, 5) if (rnk[best][j] < rnk[i][j]) ++cnt;
		if (cnt < 3) best = i;
	}
	REP(i, n) if (i != best) {
		int cnt = 0;
		REP(j, 5) if (rnk[best][j] < rnk[i][j]) ++cnt;
		if (cnt < 3) return -1;
	}
	return best;
}

void run() {
	scanf("%d", &n);
	REP(i, n) REP(j, 5) scanf("%d", &rnk[i][j]);
	int ans = solve();
	printf("%d\n", ans == -1 ? -1 : ans + 1);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}