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
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a%b); }

const int MAXN = 100000;

int n, MOD;
int a[MAXN];
int sum[MAXN + 1];

void run() {
	scanf("%d%d", &n, &MOD);
	REP(i, n) scanf("%d", &a[i]);
	
	sum[0] = 0; REP(i, n) sum[i + 1] = (sum[i] + a[i]) % MOD;
	int ans = 0;
	FOR(i, 1, n) {
		int cur = sum[i] + (sum[n] + MOD - sum[i]) % MOD;
		ans = max(ans, cur);
	}
	printf("%d\n", ans);
}

int main() {
	run();
	return 0;
}