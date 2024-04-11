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
#include <functional>
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

const int MAXN = 20;
const int MOD = 1000000007;
const int INV2 = (MOD + 1) / 2;

int n;
char s[(1 << MAXN) + 1];
int a[1 << MAXN];

void run() {
	scanf("%d%s", &n, s);
	REP(i, 1 << n) a[i] = s[i] == '1';
	REP(i, n) for (int j = 0; j < (1 << n); j += (2 << i)) REP(k, 1 << i) { int u = a[j + k], v = a[j + (1 << i) + k]; a[j + k] = (u + v) % MOD, a[j + (1 << i) + k] = (u - v + MOD) % MOD; }
	REP(i, 1 << n) a[i] = (ll)a[i] * a[i] % MOD;
	REP(i, n) for (int j = 0; j < (1 << n); j += (2 << i)) REP(k, 1 << i) { int u = a[j + k], v = a[j + (1 << i) + k]; a[j + k] = (u + v) % MOD, a[j + (1 << i) + k] = (u - v + MOD) % MOD; }
	//REP(i, 1 << n) printf("%x: %d\n", i, a[i]);
	int ret = 0;
	REP(i, 1 << n) {
		int nfree = 0; REP(j, n) if (((i >> j) & 1) == 0) ++nfree;
		ret = (ret + (((ll)a[i]) << nfree)) % MOD;
	}
	ret = (ll)3 * ret%MOD;
	REP(i, n) ret = (ll)ret*INV2%MOD;
	printf("%d\n", ret);
}

int main() {
	run();
	return 0;
}