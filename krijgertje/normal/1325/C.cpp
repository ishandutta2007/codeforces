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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 100000;
const int MAXM = MAXN - 1;

int n;
int e[MAXM][2];
int ans[MAXM];

int deg[MAXN];

void solve() {
	REP(i, n) deg[i] = 0;
	REP(i, n - 1) REP(j, 2) ++deg[e[i][j]];
	int root = -1; REP(i, n) if (deg[i] >= 3) { root = i; break; }
	if (root == -1) {
		REP(i, n - 1) ans[i] = i;
	} else {
		REP(i, n - 1) ans[i] = -1;
		int at = 0;
		REP(i, n - 1) if (e[i][0] == root || e[i][1] == root) ans[i] = at++;
		REP(i, n - 1) if (ans[i] == -1) ans[i] = at++;
	}
}

void run() {
	scanf("%d", &n);
	REP(i, n - 1) REP(j, 2) scanf("%d", &e[i][j]), --e[i][j];
	solve();
	REP(i, n - 1) printf("%d\n", ans[i]);
}

int main() {
	run();
	return 0;
}