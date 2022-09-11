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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN = 200;

int n, maxdeg, MOD;

int C[MAXN + 1][MAXN + 1];
int mono[MAXN + 1][MAXN + 1]; // mono[i][j] is # rooted trees with increasing paths with i nodes and the root having degree j
int monosum[MAXN + 1]; // monosum[i] is # rooted trees with increasing paths with i nodes and the root having degree 0..maxdeg-1

void run() {
	scanf("%d%d%d", &n, &maxdeg, &MOD);
	REPE(i, n) { C[i][0] = C[i][i] = 1; FOR(j, 1, i) C[i][j] = ((ll)C[i - 1][j - 1] + C[i - 1][j]) % MOD; }

	memset(mono, 0, sizeof(mono));
	mono[1][0] = 1; if (maxdeg != 0) monosum[1] = 1;
	FORE(i, 2, n) {
		FORE(j, 1, maxdeg) FORE(ii, 1, i - 1) {
			int ways = C[i - 2][ii - 1];
			ways = (ll)ways*monosum[ii] % MOD;
			ways = (ll)ways*mono[i - ii][j - 1] % MOD;
			mono[i][j] = ((ll)mono[i][j] + ways) % MOD;
		}
		monosum[i] = 0; REPE(j, maxdeg - 1) monosum[i] = ((ll)monosum[i] + mono[i][j]) % MOD;
	}

	int duo = 0;
	REPE(j, n) duo = ((ll)duo + mono[n][j]) % MOD;
	FORE(i, 3, n) FORE(j, 2, maxdeg) REPE(jj, maxdeg - j) {
		int ways = (ll)mono[i][j] * mono[n - i + 1][jj] % MOD;
		duo = ((ll)duo + ways) % MOD;
	}
	int paths = (ll)n*(n - 1) % MOD;
	int ret = (ll)2 * duo*paths%MOD;
	printf("%d\n", ret);
}


int main() {
	run();
	return 0;
}