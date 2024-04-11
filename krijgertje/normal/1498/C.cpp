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
const int MAXK = 1000;
const int MOD = 1000000007;

int n, kstart;

int dpfromlft[MAXN][MAXK + 1];
int dpfromrgt[MAXN][MAXK + 1];

int solve() {
	REP(i, n) dpfromlft[i][1] = dpfromrgt[i][1] = 1;
	for (int k = 2; k <= kstart; ++k) {
		for (int i = n - 1; i >= 0; --i) dpfromlft[i][k] = ((i + 1 < n ? dpfromlft[i + 1][k] : 1) + (i - 1 >= 0 ? dpfromrgt[i - 1][k - 1] : 1)) % MOD;
		REP(i, n) dpfromrgt[i][k] = ((i + 1 < n ? dpfromlft[i + 1][k - 1] : 1) + (i - 1 >= 0 ? dpfromrgt[i - 1][k] : 1)) % MOD;
	}
	return dpfromlft[0][kstart];
}

void run() {
	scanf("%d%d", &n, &kstart);
	printf("%d\n", solve());
}


int main() {
	int ncase; scanf("%d", &ncase); FORE(i, 1, ncase) run();
	return 0;
}