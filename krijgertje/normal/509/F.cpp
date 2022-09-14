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

int n;
int x[500];
const int MOD=1000000007;

ll dp[500][500];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]);
	FORE(len,1,n) REPE(i,n-len) {
		int j=i+len-1;
		dp[i][j]=0;
		//dp[i][j]+=p[#in [i+1..j] for which x[i]<x[*]]*dp[i+1][j]
		//FORE(k,i+1,j) if(x[k]>x[i]) dp[i][j]+=p[# in [i+1..k-1] for which x[i]<x[*]]*dp[i+1][k-1]*dp[k][j]
		ll mult=1;
		FORE(k,i+1,j) if(x[k]>x[i]) {
			ll cur=mult*(i+1<=k-1?dp[i+1][k-1]:1)%MOD*dp[k][j]%MOD;
			dp[i][j]+=cur;
			//printf("%d..%d (%d) -> %lld\n",i,j,k,cur);
			//mult=2*mult%MOD;
		}
		{
			ll cur=mult*(i+1<=j?dp[i+1][j]:1)%MOD;
			dp[i][j]+=cur;
			//printf("%d..%d (X) -> %lld\n",i,j,cur);
		}
		dp[i][j]%=MOD;
	}
	ll ret=n==1?1:dp[1][n-1];
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}