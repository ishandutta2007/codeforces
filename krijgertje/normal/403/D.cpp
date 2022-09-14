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
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

const int MOD=1000000007;

int fac[1001];
int f[1001][1001];
int g[1001][1001];

void run() {
	int n,k; scanf("%d%d",&n,&k); n-=k;
	int ret=(ll)f[n][k]*fac[k]%MOD;
	printf("%d\n",ret);
}

void precalc() {
	fac[0]=1; FORE(i,1,1000) fac[i]=(ll)fac[i-1]*i%MOD;
	REPE(n,1000) f[n][0]=1;
	REPE(n,1000) FORE(k,1,1000) {
		g[n][k]=0; if(n-k>=0) g[n][k]=g[n-k][k]; if(n-k+1>=0) g[n][k]=(g[n][k]+f[n-k+1][k-1])%MOD;
		f[n][k]=g[n][k]%MOD; if(n>=1) f[n][k]=(f[n][k]+f[n-1][k])%MOD;
	}
}

int main() {
	precalc();
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}