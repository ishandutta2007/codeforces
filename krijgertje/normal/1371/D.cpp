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

const int MAXN = 300;

int n, want;
char ans[MAXN][MAXN];

int solve() {
	int full = want / n, rem = want % n;
	REP(x, n) REP(y, n) ans[x][y] = '0';
	REP(diag, n) {
		REP(i, n) {
			int x = i, y = (i + diag) % n;
			if (diag < full || diag == full && i < rem) ans[x][y] = '1';
		}
	}
	return rem == 0 ? 0 : 2;
}

void run() {
	scanf("%d%d", &n, &want);
	printf("%d\n", solve());
	REP(i, n) printf("%.*s\n", n, ans[i]);
}

int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}