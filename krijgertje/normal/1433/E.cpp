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

const int MAXN = 20;

int n;

ll choose[MAXN + 1][MAXN + 1];
ll fac[MAXN + 1];

ll solve() {
	REPE(i, n) { choose[i][0] = choose[i][i] = 1; FOR(j, 1, i) choose[i][j] = choose[i - 1][j - 1] + choose[i - 1][j]; }
	fac[0] = 1; FORE(i, 1, n) fac[i] = fac[i - 1] * i;
	ll a = choose[n - 1][n / 2];
	ll b = fac[n / 2 - 1];
	return a * b * b;
}

void run() {
	scanf("%d", &n);
	printf("%lld\n", solve());
}

int main() {
	run();
	return 0;
}