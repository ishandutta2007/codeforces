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

const int MAXN = 2500;
const int MAXA = 100000;
const int MOD = 1000000007;
int pw(int x, int n) { int ret = 1; while (true) { if (n & 1) ret = (ll)ret*x%MOD; if ((n >>= 1) == 0) return ret; x = (ll)x*x%MOD; } }

int n;
int a[MAXN];
int sum;

int E[MAXA + 1];

// E[n]=(S-1)*(S-n)*sum(i=0..n-1,1/(S-i))



void run() {
	scanf("%d", &n); REP(i, n) scanf("%d", &a[i]); sum = 0; REP(i, n) sum += a[i];

	int lim = min(sum, MAXA);
	E[0] = 0; REP(i, lim) E[i + 1] = (E[i] + pw(sum - i, MOD - 2)) % MOD;
	REPE(i, lim) E[i] = (ll)E[i] * (sum - 1) % MOD*(sum - i) % MOD;
	int ret = 0; REP(i, n) ret = (ret + E[a[i]]) % MOD; printf("%d\n", ret);
}

int main() {
	run();
	return 0;
}