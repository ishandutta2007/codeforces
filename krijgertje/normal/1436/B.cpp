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

const int MAXN = 100;

int n;
int a[MAXN][MAXN];

bool isprime(int x) { for (int y = 2; y * y <= x; ++y) if (x % y == 0) return false; return true; }

void solve() {
	for (int x = 1;; ++x) {
		if (!isprime(x) && isprime(x + n - 1)) {
			REP(i, n) REP(j, n) a[i][j] = i == j ? x : 1;
			return;
		}
	}
}

void run() {
	scanf("%d", &n);
	solve();
	REP(i, n) { REP(j, n) { if (j != 0) printf(" "); printf("%d", a[i][j]); } puts(""); }
}

void stress() {
	for (n = 2; n <= MAXN; ++n) solve();
	printf("done\n");
}

int main() {
	//stress();
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}